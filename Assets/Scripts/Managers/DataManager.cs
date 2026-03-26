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
}