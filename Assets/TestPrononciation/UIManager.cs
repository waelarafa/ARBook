using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{
    public static UIManager Instance { get; private set; }

    private Canvas mainCanvas;
    private Text headerText;
    private GameObject scrollContent;
    private Button btnPrev;
    private Button btnNext;
    private GameObject feedbackPanel;
    private Text feedbackText;

    private List<GameObject> currentCards = new List<GameObject>();

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject); // ✅ UIManager survit entre les scènes
    }

    void Start()
    {
        BuildUI();
    }

    // ─────────────────────────────────────────────
    // OPEN / CLOSE
    // ─────────────────────────────────────────────

    public void OpenGame()
    {
        // ✅ si canvas détruit, le recréer
        if (mainCanvas == null)
            BuildUI();

        mainCanvas.gameObject.SetActive(true);
        StartCoroutine(WaitAndDisplay());
    }

    public void CloseGame()
    {
        if (mainCanvas != null)
            mainCanvas.gameObject.SetActive(false);
    }

    IEnumerator WaitAndDisplay()
    {
        yield return new WaitUntil(() => PronunciationManager.Instance != null);
        yield return new WaitUntil(() => PronunciationManager.Instance.IsDataReady());

        var page = PronunciationManager.Instance.GetCurrentPage();
        UpdateHeader(page.nom);
        GenerateCards(page);
        UpdateNavButtons(
            PronunciationManager.Instance.GetCurrentPageIndex(),
            PronunciationManager.Instance.GetTotalPages()
        );
    }

    // ─────────────────────────────────────────────
    // CONSTRUCTION DU UI
    // ─────────────────────────────────────────────

    void BuildUI()
    {
        GameObject canvasObj = new GameObject("MainCanvas");
        canvasObj.transform.SetParent(this.transform); // ✅ attaché au UIManager
        
        mainCanvas = canvasObj.AddComponent<Canvas>();
        mainCanvas.renderMode = RenderMode.ScreenSpaceOverlay;
        mainCanvas.sortingOrder = 10;

        CanvasScaler scaler = canvasObj.AddComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1080, 1920);

        canvasObj.AddComponent<GraphicRaycaster>();

        if (FindObjectOfType<UnityEngine.EventSystems.EventSystem>() == null)
        {
            GameObject es = new GameObject("EventSystem");
            es.AddComponent<UnityEngine.EventSystems.EventSystem>();
            es.AddComponent<UnityEngine.EventSystems.StandaloneInputModule>();
        }

        BuildHeader(canvasObj);
        BuildScrollView(canvasObj);
        BuildNavigation(canvasObj);
        BuildFeedbackPanel(canvasObj);
        BuildCloseButton(canvasObj); // ✅ bouton fermer par code

        mainCanvas.gameObject.SetActive(false);
    }

    void BuildHeader(GameObject parent)
    {
        GameObject header = new GameObject("Header");
        header.transform.SetParent(parent.transform, false);

        Image bg = header.AddComponent<Image>();
        bg.color = new Color(0.2f, 0.6f, 1f, 1f);

        RectTransform rt = header.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0, 0.88f);
        rt.anchorMax = new Vector2(1, 1f);
        rt.offsetMin = Vector2.zero;
        rt.offsetMax = Vector2.zero;

        GameObject textObj = new GameObject("HeaderText");
        textObj.transform.SetParent(header.transform, false);

        headerText = textObj.AddComponent<Text>();
        headerText.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        headerText.fontSize = 52;
        headerText.fontStyle = FontStyle.Bold;
        headerText.color = Color.white;
        headerText.alignment = TextAnchor.MiddleCenter;

        RectTransform trt = textObj.GetComponent<RectTransform>();
        trt.anchorMin = Vector2.zero;
        trt.anchorMax = Vector2.one;
        trt.offsetMin = Vector2.zero;
        trt.offsetMax = Vector2.zero;
    }

    void BuildScrollView(GameObject parent)
    {
        GameObject scrollView = new GameObject("ScrollView");
        scrollView.transform.SetParent(parent.transform, false);

        Image scrollBg = scrollView.AddComponent<Image>();
        scrollBg.color = new Color(0.95f, 0.95f, 0.95f, 1f);

        ScrollRect scrollRect = scrollView.AddComponent<ScrollRect>();
        scrollRect.horizontal = false;
        scrollRect.vertical = true;

        RectTransform srt = scrollView.GetComponent<RectTransform>();
        srt.anchorMin = new Vector2(0, 0.12f);
        srt.anchorMax = new Vector2(1, 0.88f);
        srt.offsetMin = Vector2.zero;
        srt.offsetMax = Vector2.zero;

        GameObject viewport = new GameObject("Viewport");
        viewport.transform.SetParent(scrollView.transform, false);

        Image vpImage = viewport.AddComponent<Image>();
        vpImage.color = Color.white;
        viewport.AddComponent<Mask>().showMaskGraphic = false;

        RectTransform vrt = viewport.GetComponent<RectTransform>();
        vrt.anchorMin = Vector2.zero;
        vrt.anchorMax = Vector2.one;
        vrt.offsetMin = Vector2.zero;
        vrt.offsetMax = Vector2.zero;

        GameObject content = new GameObject("Content");
        content.transform.SetParent(viewport.transform, false);

        VerticalLayoutGroup vlg = content.AddComponent<VerticalLayoutGroup>();
        vlg.spacing = 20;
        vlg.padding = new RectOffset(30, 30, 30, 30);
        vlg.childForceExpandWidth = true;
        vlg.childForceExpandHeight = false;
        vlg.childAlignment = TextAnchor.UpperCenter;

        ContentSizeFitter csf = content.AddComponent<ContentSizeFitter>();
        csf.verticalFit = ContentSizeFitter.FitMode.PreferredSize;

        RectTransform crt = content.GetComponent<RectTransform>();
        crt.anchorMin = new Vector2(0, 1);
        crt.anchorMax = new Vector2(1, 1);
        crt.pivot = new Vector2(0.5f, 1);
        crt.offsetMin = Vector2.zero;
        crt.offsetMax = Vector2.zero;

        scrollRect.viewport = vrt;
        scrollRect.content = crt;

        scrollContent = content;
    }

    void BuildNavigation(GameObject parent)
    {
        GameObject navPanel = new GameObject("NavPanel");
        navPanel.transform.SetParent(parent.transform, false);

        Image navBg = navPanel.AddComponent<Image>();
        navBg.color = new Color(0.15f, 0.15f, 0.15f, 1f);

        RectTransform nrt = navPanel.GetComponent<RectTransform>();
        nrt.anchorMin = new Vector2(0, 0);
        nrt.anchorMax = new Vector2(1, 0.12f);
        nrt.offsetMin = Vector2.zero;
        nrt.offsetMax = Vector2.zero;

        HorizontalLayoutGroup hlg = navPanel.AddComponent<HorizontalLayoutGroup>();
        hlg.spacing = 40;
        hlg.padding = new RectOffset(60, 60, 20, 20);
        hlg.childForceExpandWidth = true;
        hlg.childForceExpandHeight = true;
        hlg.childAlignment = TextAnchor.MiddleCenter;

        btnPrev = CreateNavButton(navPanel, "◀ Précédent", new Color(0.3f, 0.3f, 0.8f));
        btnNext = CreateNavButton(navPanel, "Suivant ▶", new Color(0.3f, 0.3f, 0.8f));

        btnPrev.onClick.AddListener(() =>
        {
            PronunciationManager.Instance.GoToPage(
                PronunciationManager.Instance.GetCurrentPageIndex() - 1);
            RefreshPage();
        });

        btnNext.onClick.AddListener(() =>
        {
            PronunciationManager.Instance.GoToPage(
                PronunciationManager.Instance.GetCurrentPageIndex() + 1);
            RefreshPage();
        });
    }

    Button CreateNavButton(GameObject parent, string label, Color color)
    {
        GameObject btnObj = new GameObject(label);
        btnObj.transform.SetParent(parent.transform, false);

        Image img = btnObj.AddComponent<Image>();
        img.color = color;

        Button btn = btnObj.AddComponent<Button>();

        GameObject textObj = new GameObject("Text");
        textObj.transform.SetParent(btnObj.transform, false);

        Text txt = textObj.AddComponent<Text>();
        txt.text = label;
        txt.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        txt.fontSize = 42;
        txt.fontStyle = FontStyle.Bold;
        txt.color = Color.white;
        txt.alignment = TextAnchor.MiddleCenter;

        RectTransform trt = textObj.GetComponent<RectTransform>();
        trt.anchorMin = Vector2.zero;
        trt.anchorMax = Vector2.one;
        trt.offsetMin = Vector2.zero;
        trt.offsetMax = Vector2.zero;

        return btn;
    }

    void BuildFeedbackPanel(GameObject parent)
    {
        feedbackPanel = new GameObject("FeedbackPanel");
        feedbackPanel.transform.SetParent(parent.transform, false);

        Image bg = feedbackPanel.AddComponent<Image>();
        bg.color = new Color(0, 0.8f, 0, 0.85f);

        RectTransform rt = feedbackPanel.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.1f, 0.35f);
        rt.anchorMax = new Vector2(0.9f, 0.65f);
        rt.offsetMin = Vector2.zero;
        rt.offsetMax = Vector2.zero;

        GameObject textObj = new GameObject("FeedbackText");
        textObj.transform.SetParent(feedbackPanel.transform, false);

        feedbackText = textObj.AddComponent<Text>();
        feedbackText.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        feedbackText.fontSize = 72;
        feedbackText.fontStyle = FontStyle.Bold;
        feedbackText.color = Color.white;
        feedbackText.alignment = TextAnchor.MiddleCenter;

        RectTransform trt = textObj.GetComponent<RectTransform>();
        trt.anchorMin = Vector2.zero;
        trt.anchorMax = Vector2.one;
        trt.offsetMin = Vector2.zero;
        trt.offsetMax = Vector2.zero;

        feedbackPanel.SetActive(false);
    }

    void BuildCloseButton(GameObject parent)
    {
        GameObject btnObj = new GameObject("CloseButton");
        btnObj.transform.SetParent(parent.transform, false);

        Image img = btnObj.AddComponent<Image>();
        img.color = new Color(0.9f, 0.2f, 0.2f, 1f);

        Button btn = btnObj.AddComponent<Button>();

        RectTransform rt = btnObj.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.85f, 0.91f);
        rt.anchorMax = new Vector2(0.98f, 0.99f);
        rt.offsetMin = Vector2.zero;
        rt.offsetMax = Vector2.zero;

        GameObject textObj = new GameObject("Icon");
        textObj.transform.SetParent(btnObj.transform, false);

        Text txt = textObj.AddComponent<Text>();
        txt.text = "✕";
        txt.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        txt.fontSize = 48;
        txt.fontStyle = FontStyle.Bold;
        txt.color = Color.white;
        txt.alignment = TextAnchor.MiddleCenter;

        RectTransform trt = textObj.GetComponent<RectTransform>();
        trt.anchorMin = Vector2.zero;
        trt.anchorMax = Vector2.one;
        trt.offsetMin = Vector2.zero;
        trt.offsetMax = Vector2.zero;

        btn.onClick.AddListener(() => PronunciationManager.Instance.CloseGame());
    }

    // ─────────────────────────────────────────────
    // GÉNÉRATION DES CARTES
    // ─────────────────────────────────────────────

    public void GenerateCards(ARBook.Models.PageData page)
    {
        foreach (var card in currentCards)
            Destroy(card);
        currentCards.Clear();

        foreach (var item in page.items)
        {
            string nomCapture = item.nom;
            GameObject card = CreateWordCard(nomCapture);
            card.transform.SetParent(scrollContent.transform, false);
            currentCards.Add(card);
        }
    }

    GameObject CreateWordCard(string mot)
    {
        GameObject card = new GameObject("Card_" + mot);

        Image cardBg = card.AddComponent<Image>();
        cardBg.color = Color.white;

        HorizontalLayoutGroup hlg = card.AddComponent<HorizontalLayoutGroup>();
        hlg.spacing = 16;
        hlg.padding = new RectOffset(20, 20, 20, 20);
        hlg.childForceExpandWidth = false;
        hlg.childForceExpandHeight = true;
        hlg.childAlignment = TextAnchor.MiddleLeft;

        LayoutElement le = card.AddComponent<LayoutElement>();
        le.preferredHeight = 120;

        card.AddComponent<Shadow>().effectColor = new Color(0, 0, 0, 0.2f);

        GameObject textObj = new GameObject("WordText");
        textObj.transform.SetParent(card.transform, false);

        Text wordText = textObj.AddComponent<Text>();
        wordText.text = mot;
        wordText.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        wordText.fontSize = 56;
        wordText.fontStyle = FontStyle.Bold;
        wordText.color = new Color(0.2f, 0.2f, 0.2f);
        wordText.alignment = TextAnchor.MiddleLeft;

        LayoutElement tle = textObj.AddComponent<LayoutElement>();
        tle.flexibleWidth = 1;

        Button btnListen = CreateCardButton("🔊", new Color(0.2f, 0.7f, 1f));
        btnListen.transform.SetParent(card.transform, false);
        btnListen.onClick.AddListener(() =>
        {
            PronunciationManager.Instance.SelectWord(mot);
            PronunciationAudioManager.Instance.PlayWord(mot);
        });

        Button btnRepeat = CreateCardButton("🎤", new Color(1f, 0.5f, 0.2f));
        btnRepeat.transform.SetParent(card.transform, false);
        btnRepeat.onClick.AddListener(() =>
        {
            PronunciationManager.Instance.SelectWord(mot);
            Debug.Log($"[UIManager] 🎤 Répéter : {mot}");
            STT_HF_OpenAi.Instance.ToggleRecording();
        });

        return card;
    }

    Button CreateCardButton(string icon, Color color)
    {
        GameObject btnObj = new GameObject("Btn_" + icon);

        Image img = btnObj.AddComponent<Image>();
        img.color = color;

        Button btn = btnObj.AddComponent<Button>();

        LayoutElement le = btnObj.AddComponent<LayoutElement>();
        le.preferredWidth = 110;
        le.preferredHeight = 90;

        ColorBlock cb = btn.colors;
        cb.highlightedColor = Color.white;
        btn.colors = cb;

        GameObject textObj = new GameObject("Icon");
        textObj.transform.SetParent(btnObj.transform, false);

        Text txt = textObj.AddComponent<Text>();
        txt.text = icon;
        txt.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        txt.fontSize = 48;
        txt.alignment = TextAnchor.MiddleCenter;

        RectTransform trt = textObj.GetComponent<RectTransform>();
        trt.anchorMin = Vector2.zero;
        trt.anchorMax = Vector2.one;
        trt.offsetMin = Vector2.zero;
        trt.offsetMax = Vector2.zero;

        return btn;
    }

    // ─────────────────────────────────────────────
    // MÉTHODES PUBLIQUES
    // ─────────────────────────────────────────────

    public void UpdateHeader(string nom)
    {
        if (headerText != null)
            headerText.text = nom;
    }

    public void UpdateNavButtons(int index, int total)
    {
        if (btnPrev != null) btnPrev.interactable = index > 0;
        if (btnNext != null) btnNext.interactable = index < total - 1;
    }

    void RefreshPage()
    {
        var page = PronunciationManager.Instance.GetCurrentPage();
        UpdateHeader(page.nom);
        GenerateCards(page);
        UpdateNavButtons(
            PronunciationManager.Instance.GetCurrentPageIndex(),
            PronunciationManager.Instance.GetTotalPages()
        );
    }

    public void ShowSuccess()
    {
        feedbackPanel.GetComponent<Image>().color = new Color(0, 0.8f, 0, 0.85f);
        feedbackText.text = "⭐ Bravo !";
        feedbackPanel.SetActive(true);
        StartCoroutine(HideAfter(2f));
    }

    public void ShowFailure(string mot)
    {
        feedbackPanel.GetComponent<Image>().color = new Color(1f, 0.3f, 0.3f, 0.85f);
        feedbackText.text = "Essaie encore ! 💪";
        feedbackPanel.SetActive(true);
        PronunciationAudioManager.Instance.PlayWord(mot);
        StartCoroutine(HideAfter(2.5f));
    }

    IEnumerator HideAfter(float seconds)
    {
        yield return new WaitForSeconds(seconds);
        feedbackPanel.SetActive(false);
    }
}