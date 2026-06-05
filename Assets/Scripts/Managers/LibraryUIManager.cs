using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;

public class LibraryUIManager : MonoBehaviour
{
    public static LibraryUIManager Instance { get; private set; }

    [Header("── Settings ScrollView ──")]
    public Transform settingsContent;

    [Header("── Library ScrollView ──")]
    public Transform libraryContent;

    [Header("── Prefabs ──")]
    public GameObject bookItemActivatePrefab;
    public GameObject bookItemExplorePrefab;

    // ══════════════════════════════════════════════════════════
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        // ⚠️ PAS d'abonnement ici — BookLibraryManager.Awake()
        // n'est pas encore forcément exécuté
    }

    void Start()
    {
        if (BookLibraryManager.Instance != null)
        {
            BookLibraryManager.Instance.OnLibraryChanged -= RefreshAll;
            BookLibraryManager.Instance.OnLibraryChanged += RefreshAll;
            Debug.Log("[LibraryUIManager] ✅ Abonné à OnLibraryChanged");
        }
        else
        {
            Debug.LogError("[LibraryUIManager] ❌ BookLibraryManager.Instance est null !");
        }

        RefreshAll();
        StartCoroutine(StartSessionNextFrame()); // ← attendre une frame
    }

    IEnumerator StartSessionNextFrame()
    {
        yield return null;
        Debug.Log($"[DIAGNOSTIC] SessionTimerManager.Instance null? " +
                  $"{SessionTimerManager.Instance == null}");
        Debug.Log($"[DIAGNOSTIC] ParentalSettingsManager.Instance null? " +
                  $"{ParentalSettingsManager.Instance == null}");
        SessionTimerManager.Instance?.StartChildSession();
    }

    void OnDestroy()
    {
        if (BookLibraryManager.Instance != null)
            BookLibraryManager.Instance.OnLibraryChanged -= RefreshAll;
    }

    // ══════════════════════════════════════════════════════════
    // REFRESH
    // ══════════════════════════════════════════════════════════

    public void RefreshAll()
    {
        RefreshSettings();
        RefreshLibrary();
    }

    public void RefreshSettings()
    {
        if (settingsContent == null || bookItemActivatePrefab == null)
        {
            Debug.LogError("[LibraryUIManager] ❌ settingsContent ou prefab non assigné !");
            return;
        }

        ClearContent(settingsContent);

        var allBooks = BookLibraryManager.Instance.GetAllBooks();
        Debug.Log($"[LibraryUIManager] 📋 RefreshSettings → {allBooks.Count} livre(s)");

        foreach (var book in allBooks)
        {
            GameObject item = Instantiate(bookItemActivatePrefab, settingsContent);
            var ctrl = item.GetComponent<BookItemActivate>();
            if (ctrl != null)
                ctrl.Setup(book.bookId, book.title, book.isEnabled, OnToggleClicked);
            else
                Debug.LogError("[LibraryUIManager] ❌ BookItemActivate manquant sur le prefab !");
        }
    }

    public void RefreshLibrary()
    {
        if (libraryContent == null || bookItemExplorePrefab == null)
        {
            Debug.LogError("[LibraryUIManager] ❌ libraryContent ou prefab non assigné !");
            return;
        }

        ClearContent(libraryContent);

        var enabledBooks = BookLibraryManager.Instance.GetEnabledBooks();
        Debug.Log($"[LibraryUIManager] 📚 RefreshLibrary → {enabledBooks.Count} livre(s) activé(s)");

        foreach (var book in enabledBooks)
        {
            GameObject item = Instantiate(bookItemExplorePrefab, libraryContent);
            var ctrl = item.GetComponent<BookItemExplore>();
            if (ctrl != null)
                ctrl.Setup(book.bookId, book.title);
            else
                Debug.LogError("[LibraryUIManager] ❌ BookItemExplore manquant sur le prefab !");
        }
    }

    void OnToggleClicked(string bookId, bool newState)
    {
        Debug.Log($"[LibraryUIManager] 🔘 Toggle reçu : {bookId} → {newState}");
        BookLibraryManager.Instance.SetBookEnabled(bookId, newState);
        // OnLibraryChanged déclenche RefreshAll() automatiquement
    }

    void ClearContent(Transform content)
    {
        foreach (Transform child in content)
            Destroy(child.gameObject);
    }
}