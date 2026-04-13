using Newtonsoft.Json;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;
using UnityEngine;
using UnityEngine.AddressableAssets;
using UnityEngine.Networking;
using UnityEngine.ResourceManagement.AsyncOperations;

public class DataManager : MonoBehaviour
{
    // ───── Singleton ─────
    public static DataManager Instance { get; private set; }

    // ───── URL GitHub Pages ─────
    private const string BASE_URL = "https://sirine-mechmech.github.io/unity-addressables-test/ARbook/";

    // ───── Données en mémoire ─────
    private ARBook.Models.GeneralCatalog _catalog;
    private Dictionary<string, ARBook.Models.BookEntry> _bookEntries;
    private Dictionary<string, ARBook.Models.BookData> _loadedBooks;
    private Dictionary<string, GameObject> _prefabCache = new Dictionary<string, GameObject>();
    private Dictionary<string, Texture2D> _imageCache = new Dictionary<string, Texture2D>();

    // ───── Chargement asset unique (ancienne logique conservée) ─────
    private CancellationTokenSource _cts;

    // ───── Préchargement prédictif ─────
    private List<string> _orderedPageIds = new List<string>();
    private string _activeBookId = null;
    private string _currentPageId = null;
    private CancellationTokenSource _neighborCts;

    // ─────────────────────────────────────────────
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        _bookEntries = new Dictionary<string, ARBook.Models.BookEntry>();
        _loadedBooks = new Dictionary<string, ARBook.Models.BookData>();
    }

    void Start()
    {
        StartCoroutine(LoadCatalogFromUrl());
    }

    // ─────────────────────────────────────────────
    // CATALOGUE + LIVRE
    // ─────────────────────────────────────────────

    private IEnumerator LoadCatalogFromUrl()
    {
        string url = BASE_URL + "general_catalog.json";
        UnityWebRequest request = UnityWebRequest.Get(url);
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError("Erreur chargement catalogue : " + request.error);
            yield break;
        }

        _catalog = JsonConvert.DeserializeObject<ARBook.Models.GeneralCatalog>(request.downloadHandler.text);
        foreach (ARBook.Models.BookEntry entry in _catalog.books)
            _bookEntries[entry.id] = entry;

        Debug.Log($"Catalogue chargé : {_catalog.books.Count} livre(s)");
    }

    public IEnumerator LoadBookFromUrl(string bookId)
    {
        if (_loadedBooks.ContainsKey(bookId)) yield break;

        ARBook.Models.BookEntry entry = GetBookEntry(bookId);
        if (entry == null) yield break;

        string url = BASE_URL + entry.jsonFile;
        UnityWebRequest request = UnityWebRequest.Get(url);
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError($"Erreur chargement livre {bookId} : " + request.error);
            yield break;
        }

        ARBook.Models.BookData book = JsonConvert.DeserializeObject<ARBook.Models.BookData>(request.downloadHandler.text);
        _loadedBooks[bookId] = book;
        StartCoroutine(DownloadBookAssets(entry.addressable_group));
        Debug.Log($"Livre chargé : {book.title} avec {book.pages.Count} page(s)");
    }

    public IEnumerator DownloadBookAssets(string group)
    {
        Debug.Log($"📦 Téléchargement assets : {group}");
        AsyncOperationHandle handle = Addressables.DownloadDependenciesAsync(group);
        while (!handle.IsDone)
        {
            Debug.Log($"⏳ {handle.PercentComplete * 100:F0}%");
            yield return null;
        }
        if (handle.Status == AsyncOperationStatus.Succeeded)
            Debug.Log("✅ Assets téléchargés !");
        else
            Debug.LogError("❌ Erreur téléchargement assets");
        Addressables.Release(handle);
    }

    // ─────────────────────────────────────────────
    // PRÉCHARGEMENT PRÉDICTIF
    // Appelé par le tracker AR de ta binôme :
    //   DataManager.Instance.OnPageDetected("book_001", "page1");
    // ─────────────────────────────────────────────

    public void OnPageDetected(string bookId, string pageId)
    {
        StartCoroutine(PrepareAndLaunch(bookId, pageId));
    }

    private IEnumerator PrepareAndLaunch(string bookId, string pageId)
    {
        // Même page → ignorer complètement
        if (pageId == _currentPageId) yield break;

        // Attendre que le catalogue soit disponible (max 15s)
        float elapsed = 0f;
        while (GetBookEntry(bookId) == null && elapsed < 15f)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }

        if (GetBookEntry(bookId) == null)
        {
            Debug.LogError($"[DataManager] Catalogue non prêt pour : {bookId}");
            yield break;
        }

        // Charger le livre si pas encore fait
        if (!_loadedBooks.ContainsKey(bookId))
            yield return StartCoroutine(LoadBookFromUrl(bookId));

        // Construire la liste ordonnée si nouveau livre
        if (_activeBookId != bookId)
        {
            _orderedPageIds.Clear();
            ARBook.Models.BookData book = GetBookData(bookId);
            if (book == null) yield break;
            foreach (ARBook.Models.PageData page in book.pages)
                _orderedPageIds.Add(page.id);
            _activeBookId = bookId;
            Debug.Log($"[DataManager] {_orderedPageIds.Count} pages indexées.");
        }

        _currentPageId = pageId;

        // Lancer la partie async (await interdit dans IEnumerator)
        _ = RunPredictiveLoad(bookId, pageId);
    }

    private async Task RunPredictiveLoad(string bookId, string pageId)
    {
        // Annuler les voisins précédents
        _neighborCts?.Cancel();
        _neighborCts?.Dispose();
        _neighborCts = new CancellationTokenSource();
        CancellationToken neighborToken = _neighborCts.Token;

        Debug.Log($"[DataManager] 📖 Page courante : {pageId} — chargement prioritaire");

        // ── PRIORITAIRE : page courante (on attend que ce soit fini) ──
        await LoadPageItemsAsync(bookId, pageId, CancellationToken.None);
        Debug.Log($"[DataManager] ✅ Page courante prête : {pageId}");

        // ── BACKGROUND : pages voisines (fire & forget) ──
        int index = _orderedPageIds.IndexOf(pageId);

        if (index > 0)
        {
            string prevId = _orderedPageIds[index - 1];
            _ = LoadPageItemsAsync(bookId, prevId, neighborToken);
            Debug.Log($"[DataManager] 🔄 Background lancé : {prevId}");
        }

        if (index < _orderedPageIds.Count - 1)
        {
            string nextId = _orderedPageIds[index + 1];
            _ = LoadPageItemsAsync(bookId, nextId, neighborToken);
            Debug.Log($"[DataManager] 🔄 Background lancé : {nextId}");
        }
    }

    private async Task LoadPageItemsAsync(string bookId, string pageId, CancellationToken token)
    {
        ARBook.Models.PageData page = GetPageById(bookId, pageId);
        if (page == null) return;

        foreach (ARBook.Models.ItemData item in page.items)
        {
            if (token.IsCancellationRequested)
            {
                Debug.Log($"[DataManager] ⏹ Background annulé : {pageId}");
                return;
            }

            if (IsAssetReady(item.nom))
            {
                Debug.Log($"[DataManager] Cache hit : {item.nom}");
                continue;
            }

            // On ignore les exceptions ici pour ne pas casser le background
            try { await LoadPrefabAsync(item.nom, token); } catch { }
            try { await LoadImageAsync(item.nom, token); } catch { }
        }
    }

    // ─────────────────────────────────────────────
    // CHARGEMENT ASSET UNIQUE (ancienne logique)
    // ─────────────────────────────────────────────

    public async void LoadAssetsForImage(string imageId)
    {
        _cts?.Cancel();
        _cts = new CancellationTokenSource();
        CancellationToken token = _cts.Token;
        Debug.Log($"[DataManager] Début chargement assets pour : {imageId}");
        try
        {
            await LoadPrefabAsync(imageId, token);
            if (token.IsCancellationRequested) return;
            await LoadImageAsync(imageId, token);
            if (token.IsCancellationRequested) return;
            Debug.Log($"[DataManager] ✅ Assets prêts pour : {imageId}");
        }
        catch (OperationCanceledException)
        {
            Debug.Log($"[DataManager] ⏹ Chargement interrompu : {imageId}");
        }
    }

    private async Task LoadPrefabAsync(string assetName, CancellationToken token)
    {
        if (_prefabCache.ContainsKey(assetName))
        {
            Debug.Log($"[DataManager] Prefab déjà en cache : {assetName}");
            return;
        }

        var handle = Addressables.LoadAssetAsync<GameObject>(assetName);
        while (!handle.IsDone)
        {
            if (token.IsCancellationRequested)
            {
                Addressables.Release(handle);
                throw new OperationCanceledException();
            }
            await Task.Yield();
        }

        if (handle.Status == AsyncOperationStatus.Succeeded)
        {
            _prefabCache[assetName] = handle.Result;
            Debug.Log($"[DataManager] Prefab chargé : {assetName}");
        }
        else
        {
            Debug.LogWarning($"[DataManager] Prefab introuvable dans Addressables : {assetName}");
        }
    }

    private async Task LoadImageAsync(string assetName, CancellationToken token)
    {
        if (_imageCache.ContainsKey(assetName))
        {
            Debug.Log($"[DataManager] Image déjà en cache : {assetName}");
            return;
        }

        var handle = Addressables.LoadAssetAsync<Texture2D>(assetName + "_img");
        while (!handle.IsDone)
        {
            if (token.IsCancellationRequested)
            {
                Addressables.Release(handle);
                throw new OperationCanceledException();
            }
            await Task.Yield();
        }

        if (handle.Status == AsyncOperationStatus.Succeeded)
        {
            _imageCache[assetName] = handle.Result;
            Debug.Log($"[DataManager] Image chargée : {assetName}");
        }
        else
        {
            Debug.LogWarning($"[DataManager] Image introuvable dans Addressables : {assetName}");
        }
    }

    // ─────────────────────────────────────────────
    // GETTERS
    // ─────────────────────────────────────────────

    public ARBook.Models.BookEntry GetBookEntry(string bookId)
    {
        if (_bookEntries.TryGetValue(bookId, out ARBook.Models.BookEntry entry)) return entry;
        Debug.LogWarning($"BookEntry introuvable : {bookId}");
        return null;
    }

    public ARBook.Models.BookData GetBookData(string bookId)
    {
        if (_loadedBooks.TryGetValue(bookId, out ARBook.Models.BookData book)) return book;
        Debug.LogWarning($"Livre non chargé : {bookId}");
        return null;
    }

    public ARBook.Models.PageData GetPageById(string bookId, string pageId)
    {
        ARBook.Models.BookData book = GetBookData(bookId);
        if (book == null) return null;
        foreach (ARBook.Models.PageData page in book.pages)
            if (page.id == pageId) return page;
        Debug.LogWarning($"Page introuvable : {pageId} dans {bookId}");
        return null;
    }

    public GameObject GetPrefab(string animalName)
    {
        if (_prefabCache.TryGetValue(animalName, out GameObject prefab)) return prefab;
        Debug.LogWarning($"[DataManager] GetPrefab — prefab non chargé : {animalName}");
        return null;
    }

    public Texture2D GetImage(string animalName)
    {
        if (_imageCache.TryGetValue(animalName, out Texture2D texture)) return texture;
        Debug.LogWarning($"[DataManager] GetImage — image non chargée : {animalName}");
        return null;
    }

    public ARBook.Models.ItemData GetItemData(string bookId, string animalName)
    {
        ARBook.Models.BookData book = GetBookData(bookId);
        if (book == null) return null;
        foreach (ARBook.Models.PageData page in book.pages)
            foreach (ARBook.Models.ItemData item in page.items)
                if (item.nom == animalName) return item;
        Debug.LogWarning($"[DataManager] GetItemData — animal introuvable : {animalName}");
        return null;
    }

    public bool IsAssetReady(string animalName)
    {
        return _prefabCache.ContainsKey(animalName) && _imageCache.ContainsKey(animalName);
    }
}



/*using Newtonsoft.Json;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.AddressableAssets;
using UnityEngine.ResourceManagement.AsyncOperations;
public class DataManager : MonoBehaviour
{
    // ───── Singleton ─────
    public static DataManager Instance { get; private set; }

    // ───── URLs GitHub Pages ─────
    private const string BASE_URL = "https://sirine-mechmech.github.io/unity-addressables-test/ARbook/";

    // ───── Données en mémoire ─────
    private ARBook.Models.GeneralCatalog _catalog;
    private Dictionary<string, ARBook.Models.BookEntry> _bookEntries;
    private Dictionary<string, ARBook.Models.BookData> _loadedBooks;

    private Dictionary<string, GameObject> _prefabCache = new Dictionary<string, GameObject>();
    private Dictionary<string, Texture2D> _imageCache = new Dictionary<string, Texture2D>();

    // ───── Annulation chargement async ─────
    private System.Threading.CancellationTokenSource _cts;
    void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        DontDestroyOnLoad(gameObject);

        _bookEntries = new Dictionary<string, ARBook.Models.BookEntry>();
        _loadedBooks = new Dictionary<string, ARBook.Models.BookData>();

        
    }

    void Start()
    {
        
        StartCoroutine(LoadCatalogFromUrl());
    }

    private IEnumerator LoadCatalogFromUrl()
    {
        string url = BASE_URL + "general_catalog.json";
        UnityWebRequest request = UnityWebRequest.Get(url);
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError("Erreur chargement catalogue : " + request.error);
            yield break;
        }

        _catalog = JsonConvert.DeserializeObject<ARBook.Models.GeneralCatalog>(request.downloadHandler.text);

        foreach (ARBook.Models.BookEntry entry in _catalog.books)
        {
            _bookEntries[entry.id] = entry;
        }

        Debug.Log($"Catalogue chargé : {_catalog.books.Count} livre(s)");
        _catalog = JsonConvert.DeserializeObject<ARBook.Models.GeneralCatalog>(request.downloadHandler.text);

        
    }

    public IEnumerator LoadBookFromUrl(string bookId)
    {
        if (_loadedBooks.ContainsKey(bookId))
            yield break;

        ARBook.Models.BookEntry entry = GetBookEntry(bookId);
        if (entry == null) yield break;

        string url = BASE_URL + entry.jsonFile;
        UnityWebRequest request = UnityWebRequest.Get(url);
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError($"Erreur chargement livre {bookId} : " + request.error);
            yield break;
        }

        ARBook.Models.BookData book = JsonConvert.DeserializeObject<ARBook.Models.BookData>(request.downloadHandler.text);
        _loadedBooks[bookId] = book;
        StartCoroutine(DownloadBookAssets(entry.addressable_group));

        Debug.Log($"Livre chargé : {book.title} avec {book.pages.Count} page(s)");
    }

    public IEnumerator DownloadBookAssets(string group)
    {
        Debug.Log($"📦 Téléchargement assets : {group}");

        AsyncOperationHandle handle =
            Addressables.DownloadDependenciesAsync(group);

        while (!handle.IsDone)
        {
            Debug.Log($"⏳ Progression : {handle.PercentComplete * 100:F0}%");
            yield return null;
        }

        if (handle.Status == AsyncOperationStatus.Succeeded)
        {
            Debug.Log("✅ Assets téléchargés !");
        }
        else
        {
            Debug.LogError("❌ Erreur téléchargement assets");
        }

        Addressables.Release(handle);
    }

    // ───── Chargement async déclenché par détection d'image ─────

    public async void LoadAssetsForImage(string imageId)
    {
        // ── Annuler le chargement précédent s'il est encore en cours ──
        // Exemple : image A en cours de chargement → image B détectée
        // → on annule A et on démarre B
        _cts?.Cancel();
        _cts = new System.Threading.CancellationTokenSource();
        System.Threading.CancellationToken token = _cts.Token;

        Debug.Log($"[DataManager] Début chargement assets pour : {imageId}");

        try
        {
            // Charger le prefab en arrière-plan
            await LoadPrefabAsync(imageId, token);

            // Vérifier si on a été annulé pendant le chargement
            if (token.IsCancellationRequested)
            {
                Debug.Log($"[DataManager] Chargement annulé pour : {imageId}");
                return;
            }

            // Charger l'image/texture en arrière-plan
            await LoadImageAsync(imageId, token);

            if (token.IsCancellationRequested) return;

            Debug.Log($"[DataManager] ✅ Assets prêts pour : {imageId}");
        }
        catch (System.OperationCanceledException)
        {
            // Annulation propre — pas une erreur
            Debug.Log($"[DataManager] ⏹ Chargement interrompu proprement : {imageId}");
        }
    }

    private async System.Threading.Tasks.Task LoadPrefabAsync(
        string assetName,
        System.Threading.CancellationToken token)
    {
        // Si déjà en cache → pas besoin de recharger
        if (_prefabCache.ContainsKey(assetName))
        {
            Debug.Log($"[DataManager] Prefab déjà en cache : {assetName}");
            return;
        }

        var handle = UnityEngine.AddressableAssets.Addressables
            .LoadAssetAsync<GameObject>(assetName);

        // Attendre sans bloquer le main thread
        while (!handle.IsDone)
        {
            if (token.IsCancellationRequested)
            {
                UnityEngine.AddressableAssets.Addressables.Release(handle);
                throw new System.OperationCanceledException();
            }
            await System.Threading.Tasks.Task.Yield();
        }

        if (handle.Status == UnityEngine.ResourceManagement.AsyncOperations.AsyncOperationStatus.Succeeded)
        {
            _prefabCache[assetName] = handle.Result;
            Debug.Log($"[DataManager] Prefab chargé : {assetName}");
        }
        else
        {
            Debug.LogWarning($"[DataManager] Prefab introuvable dans Addressables : {assetName}");
        }
    }

    private async System.Threading.Tasks.Task LoadImageAsync(
        string assetName,
        System.Threading.CancellationToken token)
    {
        // Si déjà en cache → pas besoin de recharger
        if (_imageCache.ContainsKey(assetName))
        {
            Debug.Log($"[DataManager] Image déjà en cache : {assetName}");
            return;
        }

        var handle = UnityEngine.AddressableAssets.Addressables
            .LoadAssetAsync<Texture2D>(assetName + "_img");

        while (!handle.IsDone)
        {
            if (token.IsCancellationRequested)
            {
                UnityEngine.AddressableAssets.Addressables.Release(handle);
                throw new System.OperationCanceledException();
            }
            await System.Threading.Tasks.Task.Yield();
        }

        if (handle.Status == UnityEngine.ResourceManagement.AsyncOperations.AsyncOperationStatus.Succeeded)
        {
            _imageCache[assetName] = handle.Result;
            Debug.Log($"[DataManager] Image chargée : {assetName}");
        }
        else
        {
            Debug.LogWarning($"[DataManager] Image introuvable dans Addressables : {assetName}");
        }
    }

    public ARBook.Models.BookEntry GetBookEntry(string bookId)
    {
        if (_bookEntries.TryGetValue(bookId, out ARBook.Models.BookEntry entry))
            return entry;

        Debug.LogWarning($"BookEntry introuvable : {bookId}");
        return null;
    }

    public ARBook.Models.BookData GetBookData(string bookId)
    {
        if (_loadedBooks.TryGetValue(bookId, out ARBook.Models.BookData book))
            return book;

        Debug.LogWarning($"Livre non chargé : {bookId} — appelle LoadBookFromUrl() d'abord");
        return null;
    }

    public ARBook.Models.PageData GetPageById(string bookId, string pageId)
    {
        ARBook.Models.BookData book = GetBookData(bookId);
        if (book == null) return null;

        foreach (ARBook.Models.PageData page in book.pages)
        {
            if (page.id == pageId)
                return page;
        }

        Debug.LogWarning($"Page introuvable : {pageId} dans {bookId}");
        return null;
    }
    public GameObject GetPrefab(string animalName)
    {
        if (_prefabCache.TryGetValue(animalName, out GameObject prefab))
            return prefab;

        Debug.LogWarning($"[DataManager] GetPrefab — prefab non chargé : {animalName}");
        return null;
    }
    public Texture2D GetImage(string animalName)
    {
        if (_imageCache.TryGetValue(animalName, out Texture2D texture))
            return texture;

        Debug.LogWarning($"[DataManager] GetImage — image non chargée : {animalName}");
        return null;
    }
    public ARBook.Models.ItemData GetItemData(string bookId, string animalName)
    {
        ARBook.Models.BookData book = GetBookData(bookId);
        if (book == null) return null;

        foreach (ARBook.Models.PageData page in book.pages)
            foreach (ARBook.Models.ItemData item in page.items)
                if (item.nom == animalName)
                    return item;

        Debug.LogWarning($"[DataManager] GetItemData — animal introuvable : {animalName}");
        return null;
    }
    public bool IsAssetReady(string animalName)
    {
        return _prefabCache.ContainsKey(animalName) && _imageCache.ContainsKey(animalName);
    }

}*/



/*using Newtonsoft.Json;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.AddressableAssets;
using UnityEngine.ResourceManagement.AsyncOperations;
public class DataManager : MonoBehaviour
{
    // ───── Singleton ─────
    public static DataManager Instance { get; private set; }

    // ───── URLs GitHub Pages ─────
    private const string BASE_URL = "https://sirine-mechmech.github.io/unity-addressables-test/ARbook/";

    // ───── Données en mémoire ─────
    private ARBook.Models.GeneralCatalog _catalog;
    private Dictionary<string, ARBook.Models.BookEntry> _bookEntries;
    private Dictionary<string, ARBook.Models.BookData> _loadedBooks;

    void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    void Start()
    {
        _bookEntries = new Dictionary<string, ARBook.Models.BookEntry>();
        _loadedBooks = new Dictionary<string, ARBook.Models.BookData>();
        StartCoroutine(LoadCatalogFromUrl());
    }

    private IEnumerator LoadCatalogFromUrl()
    {
        string url = BASE_URL + "general_catalog.json";
        UnityWebRequest request = UnityWebRequest.Get(url);
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError("Erreur chargement catalogue : " + request.error);
            yield break;
        }

        _catalog = JsonConvert.DeserializeObject<ARBook.Models.GeneralCatalog>(request.downloadHandler.text);

        foreach (ARBook.Models.BookEntry entry in _catalog.books)
        {
            _bookEntries[entry.id] = entry;
        }

        Debug.Log($"Catalogue chargé : {_catalog.books.Count} livre(s)");
    }

    public IEnumerator LoadBookFromUrl(string bookId)
    {
        if (_loadedBooks.ContainsKey(bookId))
            yield break;

        ARBook.Models.BookEntry entry = GetBookEntry(bookId);
        if (entry == null) yield break;

        string url = BASE_URL + entry.jsonFile;
        UnityWebRequest request = UnityWebRequest.Get(url);
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError($"Erreur chargement livre {bookId} : " + request.error);
            yield break;
        }

        ARBook.Models.BookData book = JsonConvert.DeserializeObject<ARBook.Models.BookData>(request.downloadHandler.text);
        _loadedBooks[bookId] = book;
        StartCoroutine(DownloadBookAssets(entry.addressable_group));

        Debug.Log($"Livre chargé : {book.title} avec {book.pages.Count} page(s)");
    }

    public IEnumerator DownloadBookAssets(string group)
    {
        Debug.Log($"📦 Téléchargement assets : {group}");

        AsyncOperationHandle handle =
            Addressables.DownloadDependenciesAsync(group);

        while (!handle.IsDone)
        {
            Debug.Log($"⏳ Progression : {handle.PercentComplete * 100:F0}%");
            yield return null;
        }

        if (handle.Status == AsyncOperationStatus.Succeeded)
        {
            Debug.Log("✅ Assets téléchargés !");
        }
        else
        {
            Debug.LogError("❌ Erreur téléchargement assets");
        }

        Addressables.Release(handle);
    }

    public ARBook.Models.BookEntry GetBookEntry(string bookId)
    {
        if (_bookEntries.TryGetValue(bookId, out ARBook.Models.BookEntry entry))
            return entry;

        Debug.LogWarning($"BookEntry introuvable : {bookId}");
        return null;
    }

    public ARBook.Models.BookData GetBookData(string bookId)
    {
        if (_loadedBooks.TryGetValue(bookId, out ARBook.Models.BookData book))
            return book;

        Debug.LogWarning($"Livre non chargé : {bookId} — appelle LoadBookFromUrl() d'abord");
        return null;
    }

    public ARBook.Models.PageData GetPageById(string bookId, string pageId)
    {
        ARBook.Models.BookData book = GetBookData(bookId);
        if (book == null) return null;

        foreach (ARBook.Models.PageData page in book.pages)
        {
            if (page.id == pageId)
                return page;
        }

        Debug.LogWarning($"Page introuvable : {pageId} dans {bookId}");
        return null;
    }
}*/