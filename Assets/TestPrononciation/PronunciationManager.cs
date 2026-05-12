using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PronunciationManager : MonoBehaviour
{
    public static PronunciationManager Instance { get; private set; }

    private const string BOOK_ID = "book_001";

    private List<ARBook.Models.PageData> allPages = new List<ARBook.Models.PageData>(); // ✅ sauvegarde
    private List<ARBook.Models.PageData> pages = new List<ARBook.Models.PageData>();    // ✅ pages affichées
    private int currentPageIndex = 0;
    private string currentWord = "";
    private bool dataReady = false;

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
        yield return new WaitUntil(() => DataManager.Instance.GetBookEntry(BOOK_ID) != null);
        yield return StartCoroutine(DataManager.Instance.LoadBookFromUrl(BOOK_ID));

        BuildPages();
    }

    void BuildPages()
    {
        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(BOOK_ID);
        if (bookData == null)
        {
            Debug.LogError("[PronunciationManager] BookData introuvable !");
            return;
        }

        pages.Clear();
        allPages.Clear(); // ✅
        foreach (var page in bookData.pages)
        {
            pages.Add(page);
            allPages.Add(page); // ✅ copie sauvegarde
        }

        dataReady = true;
        Debug.Log($"[PronunciationManager] ✅ {pages.Count} pages chargées");

        foreach (var page in pages)
        {
            Debug.Log($"📄 Page : {page.nom}");
            foreach (var item in page.items)
                Debug.Log($"   → {item.nom}");
        }
    }

    // ✅ appelé par chaque bouton avec ses pages
    public void OpenWithPages(string[] pageNames)
    {
        List<ARBook.Models.PageData> filtered = new List<ARBook.Models.PageData>();

        foreach (var name in pageNames)
        {
            var page = allPages.Find(p => p.nom == name); // ✅ cherche dans allPages
            if (page != null)
                filtered.Add(page);
            else
                Debug.LogWarning($"[PronunciationManager] Page introuvable : {name}");
        }

        if (filtered.Count == 0)
        {
            Debug.LogError("[PronunciationManager] Aucune page trouvée !");
            return;
        }

        pages = filtered;
        currentPageIndex = 0;
        UIManager.Instance.OpenGame();
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

    public string GetCurrentWord() => currentWord;
    public int GetCurrentPageIndex() => currentPageIndex;
    public int GetTotalPages() => pages.Count;
    public bool IsDataReady() => dataReady;

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
}