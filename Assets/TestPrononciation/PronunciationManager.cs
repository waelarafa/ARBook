using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PronunciationManager : MonoBehaviour
{
    public static PronunciationManager Instance { get; private set; }

    private string bookId  => SessionManager.Instance.CurrentBookId;
    private string themeId => SessionManager.Instance.CurrentThemeId;

    private List<ARBook.Models.PageData> allPages = new List<ARBook.Models.PageData>();
    private List<ARBook.Models.PageData> pages    = new List<ARBook.Models.PageData>();
    private int    currentPageIndex = 0;
    private string currentWord      = "";
    private bool   dataReady        = false;

    private int _correctCount  = 0;
    private int _totalAttempts = 0;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

    void Start()
    {
        StartCoroutine(WaitAndLoad());
    }

    IEnumerator WaitAndLoad()
    {
        yield return new WaitUntil(() => DataManager.Instance != null);
        yield return new WaitUntil(() => SessionManager.Instance != null);

        string currentBookId = SessionManager.Instance.CurrentBookId;

        if (string.IsNullOrEmpty(currentBookId))
        {
            Debug.LogError("[PronunciationManager] ❌ CurrentBookId vide.");
            yield break;
        }

        if (!DataManager.Instance.IsBookLoaded(currentBookId))
        {
            Debug.LogError($"[PronunciationManager] ❌ '{currentBookId}' absent du cache.");
            yield break;
        }

        BuildPages(currentBookId);
    }

    void BuildPages(string bId)
    {
        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(bId);
        if (bookData == null)
        {
            Debug.LogError("[PronunciationManager] ❌ BookData introuvable.");
            return;
        }

        pages.Clear();
        allPages.Clear();
        foreach (var page in bookData.pages)
        {
            pages.Add(page);
            allPages.Add(page);
        }

        dataReady = true;
        Debug.Log($"[PronunciationManager] ✅ {allPages.Count} pages chargées.");
    }

    public void OpenWithTheme()
    {
        _correctCount  = 0;
        _totalAttempts = 0;

        string bId = bookId;
        string tId = themeId;

        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(bId);
        if (bookData == null)
        {
            Debug.LogError($"[PronunciationManager] ❌ BookData introuvable pour '{bId}'");
            return;
        }

        allPages.Clear();
        foreach (var page in bookData.pages)
            allPages.Add(page);

        dataReady = true;

        List<ARBook.Models.PageData> filtered = allPages.FindAll(p => p.themeId == tId);

        if (filtered.Count == 0)
        {
            Debug.LogError($"[PronunciationManager] ❌ Aucune page pour themeId='{tId}'");
            return;
        }

        pages = filtered;
        currentPageIndex = 0;

        Debug.Log($"[PronunciationManager] ✅ {pages.Count} page(s) pour '{tId}'");
        UIManager.Instance.OpenGame();
        AnalyticsManager.Instance?.LogActivityEntered(bId, tId, "pronunciation");
    }

    public void CloseGame()
    {
        UIManager.Instance.CloseGame();
    }

    public ARBook.Models.PageData GetCurrentPage()
    {
        if (pages.Count == 0) return null;
        return pages[currentPageIndex];
    }

    public void SelectWord(string mot)
    {
        currentWord = mot;
        Debug.Log($"[PronunciationManager] Mot sélectionné : {currentWord}");
    }

    public string GetCurrentWord()      => currentWord;
    public int    GetCurrentPageIndex() => currentPageIndex;
    public int    GetTotalPages()       => pages.Count;
    public bool   IsDataReady()         => dataReady;

    public void GoToPage(int index)
    {
        if (index < 0 || index >= pages.Count) return;
        currentPageIndex = index;
        Debug.Log($"[PronunciationManager] Page : {pages[currentPageIndex].nom}");
    }

    public void OnTranscriptionReceived(string texte)
    {
        if (string.IsNullOrEmpty(currentWord))
        {
            Debug.LogWarning("[PronunciationManager] Aucun mot sélectionné !");
            return;
        }

        string texteNormalise = texte.Replace(".", "")
            .Replace(",", "")
            .Replace("!", "")
            .Replace("?", "")
            .Replace(" ", "")
            .Trim()
            .ToLower();

        string motAttendu = currentWord.Trim().ToLower();

        bool correct = texteNormalise == motAttendu || texteNormalise.Contains(motAttendu);

        _totalAttempts++;
        if (correct) _correctCount++;

        Debug.Log($"[PronunciationManager] Score : {_correctCount}/{_totalAttempts}");

        if (correct)
            UIManager.Instance.ShowSuccess();
        else
            UIManager.Instance.ShowFailure(currentWord);

        CheckCompletion();
    }

    private void CheckCompletion()
{
    if (_correctCount >= 1)
        EndPronunciation();
}

    private void EndPronunciation()
    {
        string bId = bookId;
        string tId = themeId;

        AnalyticsManager.Instance?.LogQuizScore(bId, tId, _correctCount, _totalAttempts);
        AnalyticsManager.Instance?.LogActivityExited();
        StartCoroutine(NotifyNextFrame());
    }

    private IEnumerator NotifyNextFrame()
{
    yield return null;

    string tId = themeId;
    Debug.Log($"[Pronunciation] Cherche ActivityMapManager avec themeId='{tId}'");
    
    ActivityMapManager[] managers = FindObjectsByType<ActivityMapManager>(FindObjectsSortMode.None);
    Debug.Log($"[Pronunciation] {managers.Length} ActivityMapManager(s) trouvé(s)");
    
    foreach (var manager in managers)
    {
        Debug.Log($"[Pronunciation] Manager trouvé : themeId='{manager.themeId}'");
        if (manager.themeId == tId)
        {
            manager.OnActivityCompleted("pronunciation");
            Debug.Log($"[Pronunciation] ✅ OnActivityCompleted appelé !");
            break;
        }
    }
}
}
/*using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PronunciationManager : MonoBehaviour
{
    public static PronunciationManager Instance { get; private set; }

    [Header("Analytics")]
    public string bookId  = "";
    public string themeId = "";

    private List<ARBook.Models.PageData> allPages = new List<ARBook.Models.PageData>();
    private List<ARBook.Models.PageData> pages    = new List<ARBook.Models.PageData>();
    private int    currentPageIndex = 0;
    private string currentWord      = "";
    private bool   dataReady        = false;

    // ── Suivi du score ────────────────────────────────────────
    private int _correctCount  = 0;
    private int _totalAttempts = 0;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

    void Start()
    {
        StartCoroutine(WaitAndLoad());
    }

    IEnumerator WaitAndLoad()
    {
        yield return new WaitUntil(() => DataManager.Instance != null);

        bookId = DataManager.Instance.LastLoadedBookId;

        if (string.IsNullOrEmpty(bookId))
        {
            Debug.LogError("[PronunciationManager] ❌ LastLoadedBookId vide.");
            yield break;
        }

        if (!DataManager.Instance.IsBookLoaded(bookId))
        {
            Debug.LogError($"[PronunciationManager] ❌ '{bookId}' absent du cache.");
            yield break;
        }

        BuildPages(bookId);
    }

    void BuildPages(string bookId)
    {
        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(bookId);
        if (bookData == null)
        {
            Debug.LogError("[PronunciationManager] ❌ BookData introuvable.");
            return;
        }

        pages.Clear();
        allPages.Clear();
        foreach (var page in bookData.pages)
        {
            pages.Add(page);
            allPages.Add(page);
        }

        dataReady = true;
        Debug.Log($"[PronunciationManager] ✅ {allPages.Count} pages chargées.");
    }

    public void OpenWithTheme(string bookId, string themeId)
    {
        // Réinitialiser le score à chaque ouverture
        _correctCount  = 0;
        _totalAttempts = 0;

        this.bookId  = bookId;
        this.themeId = themeId;

        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(bookId);
        if (bookData == null)
        {
            Debug.LogError($"[PronunciationManager] ❌ BookData introuvable pour '{bookId}'");
            return;
        }

        allPages.Clear();
        foreach (var page in bookData.pages)
            allPages.Add(page);

        dataReady = true;

        List<ARBook.Models.PageData> filtered = allPages.FindAll(p => p.themeId == themeId);

        if (filtered.Count == 0)
        {
            Debug.LogError($"[PronunciationManager] ❌ Aucune page pour themeId='{themeId}'");
            return;
        }

        pages = filtered;
        currentPageIndex = 0;

       

        Debug.Log($"[PronunciationManager] ✅ {pages.Count} page(s) pour '{themeId}'");
        UIManager.Instance.OpenGame();
        AnalyticsManager.Instance?.LogActivityEntered(bookId, themeId, "pronunciation");
    }

    public void CloseGame()
    {
        //AnalyticsManager.Instance?.LogActivityExited();
        UIManager.Instance.CloseGame();
    }

    public ARBook.Models.PageData GetCurrentPage()
    {
        if (pages.Count == 0) return null;
        return pages[currentPageIndex];
    }

    public void SelectWord(string mot)
    {
        currentWord = mot;
        Debug.Log($"[PronunciationManager] Mot sélectionné : {currentWord}");
    }

    public string GetCurrentWord()      => currentWord;
    public int    GetCurrentPageIndex() => currentPageIndex;
    public int    GetTotalPages()       => pages.Count;
    public bool   IsDataReady()         => dataReady;

    public void GoToPage(int index)
    {
        if (index < 0 || index >= pages.Count) return;
        currentPageIndex = index;
        Debug.Log($"[PronunciationManager] Page : {pages[currentPageIndex].nom}");
    }

    public void OnTranscriptionReceived(string texte)
    {
        if (string.IsNullOrEmpty(currentWord))
        {
            Debug.LogWarning("[PronunciationManager] Aucun mot sélectionné !");
            return;
        }

        string texteNormalise = texte.Replace(".", "")
            .Replace(",", "")
            .Replace("!", "")
            .Replace("?", "")
            .Replace(" ", "")
            .Trim()
            .ToLower();

        string motAttendu = currentWord.Trim().ToLower();

        Debug.Log($"[PronunciationManager] Transcrit : '{texteNormalise}' | Attendu : '{motAttendu}'");

        bool correct = texteNormalise == motAttendu || texteNormalise.Contains(motAttendu);

        // ── Comptage ──────────────────────────────────────────
        _totalAttempts++;
        if (correct) _correctCount++;

        Debug.Log($"[PronunciationManager] Score : {_correctCount}/{_totalAttempts}");

        if (correct)
        {
            Debug.Log("✅ Correct !");
            UIManager.Instance.ShowSuccess();
        }
        else
        {
            Debug.Log("❌ Incorrect !");
            UIManager.Instance.ShowFailure(currentWord);
        }

        // ── Vérifier si l'activité est terminée ───────────────
        CheckCompletion();
    }

    private void CheckCompletion()
    {
        // Terminé quand tous les mots ont été tentés
        if (_totalAttempts < pages.Count) return;

        // Condition : 2/3 des mots corrects
        float ratio = (float)_correctCount / _totalAttempts;
        bool passed = ratio >= (1f / 6f);

        Debug.Log($"[PronunciationManager] Terminé — {_correctCount}/{_totalAttempts} ({ratio:P0}) — passed={passed}");

        if (passed)
            EndPronunciation();
    }

    private void EndPronunciation()
{
    AnalyticsManager.Instance?.LogQuizScore(bookId, themeId, _correctCount, _totalAttempts);
    
    AnalyticsManager.Instance?.LogActivityExited();
    StartCoroutine(NotifyNextFrame());
}

private IEnumerator NotifyNextFrame()
{
    yield return null; // attendre un seul frame
    
    ActivityMapManager[] managers = FindObjectsByType<ActivityMapManager>(FindObjectsSortMode.None);
    foreach (var manager in managers)
    {
        if (manager.themeId == themeId)
        {
            manager.OnActivityCompleted("pronunciation");
            break;
        }
    }
}
}
/*using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PronunciationManager : MonoBehaviour
{
    public static PronunciationManager Instance { get; private set; }

    private string _bookId = "";

    private List<ARBook.Models.PageData> allPages = new List<ARBook.Models.PageData>();
    private List<ARBook.Models.PageData> pages    = new List<ARBook.Models.PageData>();
    private int    currentPageIndex = 0;
    private string currentWord      = "";
    private bool   dataReady        = false;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

    void Start()
    {
        StartCoroutine(WaitAndLoad());
    }

    IEnumerator WaitAndLoad()
    {
        yield return new WaitUntil(() => DataManager.Instance != null);

        _bookId = DataManager.Instance.LastLoadedBookId;

        if (string.IsNullOrEmpty(_bookId))
        {
            Debug.LogError("[PronunciationManager] ❌ LastLoadedBookId vide.");
            yield break;
        }

        if (!DataManager.Instance.IsBookLoaded(_bookId))
        {
            Debug.LogError($"[PronunciationManager] ❌ '{_bookId}' absent du cache.");
            yield break;
        }

        BuildPages(_bookId);
    }

    void BuildPages(string bookId)
    {
        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(bookId);
        if (bookData == null)
        {
            Debug.LogError("[PronunciationManager] ❌ BookData introuvable.");
            return;
        }

        pages.Clear();
        allPages.Clear();
        foreach (var page in bookData.pages)
        {
            pages.Add(page);
            allPages.Add(page);
        }

        dataReady = true;
        Debug.Log($"[PronunciationManager] ✅ {allPages.Count} pages chargées.");
    }

    public void OpenWithTheme(string bookId, string themeId)
    {
        // Toujours recharger depuis DataManager avec le bookId donné
        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(bookId);
        if (bookData == null)
        {
            Debug.LogError($"[PronunciationManager] ❌ BookData introuvable pour '{bookId}'");
            return;
        }

        allPages.Clear();
        foreach (var page in bookData.pages)
            allPages.Add(page);

        dataReady = true; // ← forcer dataReady pour que WaitAndDisplay ne bloque pas

        Debug.Log($"[PronunciationManager] 📚 {allPages.Count} pages pour '{bookId}'");
        foreach (var p in allPages)
            Debug.Log($"   → nom='{p.nom}' themeId='{p.themeId}'");

        List<ARBook.Models.PageData> filtered = allPages.FindAll(p => p.themeId == themeId);

        if (filtered.Count == 0)
        {
            Debug.LogError($"[PronunciationManager] ❌ Aucune page pour themeId='{themeId}'");
            return;
        }

        pages = filtered;
        currentPageIndex = 0;

        Debug.Log($"[PronunciationManager] ✅ {pages.Count} page(s) pour '{themeId}'");
        UIManager.Instance.OpenGame();
    }

    public void CloseGame()
    {
        AnalyticsManager.Instance?.LogActivityExited();
        UIManager.Instance.CloseGame();
    }

    public ARBook.Models.PageData GetCurrentPage()
    {
        if (pages.Count == 0) return null;
        return pages[currentPageIndex];
    }

    public void SelectWord(string mot)
    {
        currentWord = mot;
        Debug.Log($"[PronunciationManager] Mot sélectionné : {currentWord}");
    }

    public string GetCurrentWord()      => currentWord;
    public int    GetCurrentPageIndex() => currentPageIndex;
    public int    GetTotalPages()       => pages.Count;
    public bool   IsDataReady()         => dataReady;

    public void GoToPage(int index)
    {
        if (index < 0 || index >= pages.Count) return;
        currentPageIndex = index;
        Debug.Log($"[PronunciationManager] Page : {pages[currentPageIndex].nom}");
    }

    public void OnTranscriptionReceived(string texte)
    {
        if (string.IsNullOrEmpty(currentWord))
        {
            Debug.LogWarning("[PronunciationManager] Aucun mot sélectionné !");
            return;
        }

        string texteNormalise = texte.Replace(".", "")
            .Replace(",", "")
            .Replace("!", "")
            .Replace("?", "")
            .Replace(" ", "")
            .Trim()
            .ToLower();

        string motAttendu = currentWord.Trim().ToLower();

        Debug.Log($"[PronunciationManager] Transcrit : '{texteNormalise}' | Attendu : '{motAttendu}'");

        if (texteNormalise == motAttendu || texteNormalise.Contains(motAttendu))
        {
            Debug.Log("✅ Correct !");
            UIManager.Instance.ShowSuccess();
        }
        else
        {
            Debug.Log("❌ Incorrect !");
            UIManager.Instance.ShowFailure(currentWord);
        }
    }
}*/