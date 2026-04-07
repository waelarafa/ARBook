using Newtonsoft.Json;
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