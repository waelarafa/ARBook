using System;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// BookLibraryManager — Singleton qui gère la liste des livres scannés.
///
/// RESPONSABILITÉS :
///   - Stocker localement (PlayerPrefs + JSON) tous les livres scannés par le parent
///   - Permettre d'activer / désactiver un livre (visible dans Library ou non)
///   - Fournir la liste filtrée des livres activés (pour Panel_Library)
///   - Fournir la liste complète (pour Panel_Settings)
///
/// STOCKAGE :
///   PlayerPrefs key : "book_library_data"
///   Format          : JSON → BookLibraryData
/// </summary>
public class BookLibraryManager : MonoBehaviour
{
    public static BookLibraryManager Instance { get; private set; }

    // ── Clé PlayerPrefs ───────────────────────────────────────
    //private const string PREFS_KEY = "book_library_data";

    // ── Clé EasySave ──────────────────────────────────────────
    private const string ES3_KEY = "book_library";


    // ── Données en mémoire ────────────────────────────────────
    private BookLibraryData _data;

    // ── Événement : notifie quand la liste change ─────────────
    // Abonne-toi depuis Panel_Library ou Panel_Settings pour refresh l'UI
    public event Action OnLibraryChanged;

    // ══════════════════════════════════════════════════════════
    // MODÈLES DE DONNÉES
    // ══════════════════════════════════════════════════════════

    [Serializable]
    public class BookEntry
    {
        public string bookId;
        public string title;
        public bool isEnabled;   // true → visible dans Library enfant
        public long scannedAt;   // timestamp Unix ms
    }

    [Serializable]
    public class BookLibraryData
    {
        public List<BookEntry> books = new List<BookEntry>();
    }

    // ══════════════════════════════════════════════════════════
    // INIT
    // ══════════════════════════════════════════════════════════
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);

        Load();
    }

    // ══════════════════════════════════════════════════════════
    // PERSISTANCE
    // ══════════════════════════════════════════════════════════
    /// <summary>
    /// avec playerprefs 
    /// </summary>
    /*void Load()
    {
        string json = PlayerPrefs.GetString(PREFS_KEY, "{\"books\":[]}");
        _data = JsonUtility.FromJson<BookLibraryData>(json) ?? new BookLibraryData();
        Debug.Log($"[BookLibrary] 📚 {_data.books.Count} livre(s) chargé(s)");
    }

    void Save()
    {
        PlayerPrefs.SetString(PREFS_KEY, JsonUtility.ToJson(_data));
        PlayerPrefs.Save();
        Debug.Log($"[BookLibrary] 💾 Sauvegardé — {_data.books.Count} livre(s)");
    }

    //*/

    void Load()
    {
        if (ES3.KeyExists(ES3_KEY))
        {
            _data = new BookLibraryData();
            _data.books = ES3.Load<List<BookEntry>>(ES3_KEY);
        }
        else
        {
            _data = new BookLibraryData();
        }

        Debug.Log($"[BookLibrary] 📚 {_data.books.Count} livre(s) chargé(s) (ES3)");
    }

    void Save()
    {
        ES3.Save(ES3_KEY, _data.books);
        Debug.Log($"[BookLibrary] 💾 {_data.books.Count} livre(s) sauvegardé(s) (ES3)");
    }

    //══════════════════════════════════════════════════════════
    // API PUBLIQUE
    // ══════════════════════════════════════════════════════════

    /// <summary>
    /// Ajoute un livre scanné à la liste.
    /// S'il existe déjà (même bookId), met à jour le titre sans changer isEnabled.
    /// Retourne true si c'est un nouveau livre, false si déjà présent.
    /// </summary>
    public bool AddScannedBook(string bookId, string title)
    {
        var existing = _data.books.Find(b => b.bookId == bookId);

        if (existing != null)
        {
            // Mise à jour du titre si changé
            existing.title = title;
            Save();
            Debug.Log($"[BookLibrary] 🔄 Livre déjà présent, mis à jour : {bookId}");
            OnLibraryChanged?.Invoke();
            return false;
        }

        // Nouveau livre → désactivé par défaut (parent doit l'activer manuellement)
        _data.books.Add(new BookEntry
        {
            bookId = bookId,
            title = title,
            isEnabled = false,
            scannedAt = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });

        Save();
        Debug.Log($"[BookLibrary] ✅ Nouveau livre ajouté : {bookId} — \"{title}\"");
        OnLibraryChanged?.Invoke();
        return true;
    }

    /// <summary>
    /// Active ou désactive un livre (toggle dans Panel_Settings).
    /// </summary>
    public void SetBookEnabled(string bookId, bool enabled)
    {
        var book = _data.books.Find(b => b.bookId == bookId);
        if (book == null)
        {
            Debug.LogWarning($"[BookLibrary] ⚠️ bookId introuvable : {bookId}");
            return;
        }

        book.isEnabled = enabled;
        Save();
        Debug.Log($"[BookLibrary] 🔘 {bookId} → {(enabled ? "ACTIVÉ" : "DÉSACTIVÉ")}");
        OnLibraryChanged?.Invoke();
    }

    /// <summary>
    /// Retourne TOUS les livres scannés (pour Panel_Settings).
    /// </summary>
    public List<BookEntry> GetAllBooks() => new List<BookEntry>(_data.books);

    /// <summary>
    /// Retourne uniquement les livres ACTIVÉS (pour Panel_Library enfant).
    /// </summary>
    public List<BookEntry> GetEnabledBooks()
        => _data.books.FindAll(b => b.isEnabled);

    /// <summary>
    /// Vérifie si un livre est déjà dans la liste.
    /// </summary>
    public bool ContainsBook(string bookId)
        => _data.books.Exists(b => b.bookId == bookId);

    /// <summary>
    /// Supprime un livre de la liste (optionnel — pour une future fonctionnalité).
    /// </summary>
    public void RemoveBook(string bookId)
    {
        int removed = _data.books.RemoveAll(b => b.bookId == bookId);
        if (removed > 0)
        {
            Save();
            OnLibraryChanged?.Invoke();
            Debug.Log($"[BookLibrary] 🗑️ Livre supprimé : {bookId}");
        }
    }

    /// <summary>
    /// Vide complètement la bibliothèque (debug/reset).
    /// </summary>
    public void ClearAll()
    {
        _data.books.Clear();
        Save();
        OnLibraryChanged?.Invoke();
        Debug.Log("[BookLibrary] 🧹 Bibliothèque vidée");
    }
}