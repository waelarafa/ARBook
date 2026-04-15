/*version finale - technique RectTransformUtility utilisation de raycast*/
// AROverlayUI.cs
using UnityEngine;
using UnityEngine.UI;

public class AROverlayUI : MonoBehaviour
{
    public static AROverlayUI Instance { get; private set; }

    private GameObject  _canvasGO;
    private GameObject  _buttonGO;
    private RectTransform _buttonRect;

    // ─────────────────────────────────────────────────────────────
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        BuildButton();
        ShowCloseButton(false);
    }

    void OnDestroy()
    {
        if (Instance == this) Instance = null;
    }

    // ─────────────────────────────────────────────────────────────
    void BuildButton()
    {
        _canvasGO = new GameObject("CloseButtonCanvas");
        _canvasGO.transform.SetParent(transform);
        DontDestroyOnLoad(_canvasGO);

        Canvas canvas       = _canvasGO.AddComponent<Canvas>();
        canvas.renderMode   = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder = 999;

        CanvasScaler cs        = _canvasGO.AddComponent<CanvasScaler>();
        cs.uiScaleMode         = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        cs.referenceResolution = new Vector2(1080, 1920);
        cs.matchWidthOrHeight  = 0.5f;

        // Pas de GraphicRaycaster — on utilise RectTransformUtility à la place

        _buttonGO = new GameObject("FermerButton");
        _buttonGO.transform.SetParent(_canvasGO.transform, false);

        Image img = _buttonGO.AddComponent<Image>();
        img.color = new Color(0.85f, 0.1f, 0.1f, 1f);

        _buttonRect             = _buttonGO.GetComponent<RectTransform>();
        _buttonRect.anchorMin   = new Vector2(0.5f, 1f);
        _buttonRect.anchorMax   = new Vector2(0.5f, 1f);
        _buttonRect.pivot       = new Vector2(0.5f, 1f);
        _buttonRect.anchoredPosition = new Vector2(0f, -60f);
        _buttonRect.sizeDelta   = new Vector2(260f, 80f);

        GameObject textGO      = new GameObject("Texte");
        textGO.transform.SetParent(_buttonGO.transform, false);

        RectTransform trt  = textGO.AddComponent<RectTransform>();
        trt.anchorMin      = Vector2.zero;
        trt.anchorMax      = Vector2.one;
        trt.offsetMin      = Vector2.zero;
        trt.offsetMax      = Vector2.zero;

        Text txt           = textGO.AddComponent<Text>();
        txt.text           = "✕  Fermer";
        txt.font           = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        txt.fontSize       = 34;
        txt.fontStyle      = FontStyle.Bold;
        txt.color          = Color.white;
        txt.alignment      = TextAnchor.MiddleCenter;
        txt.raycastTarget  = false;

        Debug.Log("✅ Bouton Fermer créé (RectTransformUtility)");
    }

    // ─────────────────────────────────────────────────────────────
    public void ShowCloseButton(bool visible)
    {
        if (_buttonGO != null)
            _buttonGO.SetActive(visible);
        Debug.Log(visible ? "🔴 Bouton affiché" : "✅ Bouton caché");
    }

    // ─────────────────────────────────────────────────────────────
    // Appelé par TapDetector1 pour savoir si le tap est sur le bouton
    public bool IsTapOnCloseButton(Vector2 screenPosition)
    {
        if (_buttonGO == null || !_buttonGO.activeSelf) return false;
        return RectTransformUtility.RectangleContainsScreenPoint(
            _buttonRect, screenPosition, null);
    }

    // ─────────────────────────────────────────────────────────────
    public void OnFermerPressed()
    {
        Debug.Log("🔴 Fermer appuyé → destruction prefab");
        TapDetector1.DestroyCurrentPrefab(0f);
    }
}
/*version finale verifiee
// AROverlayUI.cs
// Attacher sur un GameObject vide dans la scène
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class AROverlayUI : MonoBehaviour
{
    public static AROverlayUI Instance { get; private set; }

    private GameObject _canvasGO;
    private GameObject _buttonGO;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        EnsureEventSystem();
        BuildButton();
        ShowCloseButton(false);
    }

    void OnDestroy()
    {
        if (Instance == this) Instance = null;
    }

    void EnsureEventSystem()
    {
        if (FindFirstObjectByType<EventSystem>() != null) return;
        GameObject es = new GameObject("EventSystem");
        es.AddComponent<EventSystem>();
        es.AddComponent<StandaloneInputModule>();
        DontDestroyOnLoad(es);
        Debug.Log("✅ EventSystem créé");
    }

    void BuildButton()
    {
        _canvasGO = new GameObject("CloseButtonCanvas");
        _canvasGO.transform.SetParent(transform);
        DontDestroyOnLoad(_canvasGO);

        Canvas canvas       = _canvasGO.AddComponent<Canvas>();
        canvas.renderMode   = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder = 999;

        CanvasScaler cs        = _canvasGO.AddComponent<CanvasScaler>();
        cs.uiScaleMode         = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        cs.referenceResolution = new Vector2(1080, 1920);
        cs.matchWidthOrHeight  = 0.5f;

        _canvasGO.AddComponent<GraphicRaycaster>();

        _buttonGO = new GameObject("FermerButton");
        _buttonGO.transform.SetParent(_canvasGO.transform, false);

        RectTransform rt    = _buttonGO.AddComponent<RectTransform>();
        rt.anchorMin        = new Vector2(0.5f, 1f);
        rt.anchorMax        = new Vector2(0.5f, 1f);
        rt.pivot            = new Vector2(0.5f, 1f);
        rt.anchoredPosition = new Vector2(0f, -60f);
        rt.sizeDelta        = new Vector2(260f, 80f);

        Image img = _buttonGO.AddComponent<Image>();
        img.color = new Color(0.85f, 0.1f, 0.1f, 1f);

        Button btn             = _buttonGO.AddComponent<Button>();
        ColorBlock c           = btn.colors;
        c.normalColor          = new Color(0.85f, 0.1f, 0.1f, 1f);
        c.highlightedColor     = new Color(1f,    0.2f, 0.2f, 1f);
        c.pressedColor         = new Color(0.5f,  0.0f, 0.0f, 1f);
        c.fadeDuration         = 0.05f;
        btn.colors             = c;
        btn.onClick.AddListener(OnFermerPressed);

        GameObject textGO      = new GameObject("Texte");
        textGO.transform.SetParent(_buttonGO.transform, false);

        RectTransform trt  = textGO.AddComponent<RectTransform>();
        trt.anchorMin      = Vector2.zero;
        trt.anchorMax      = Vector2.one;
        trt.offsetMin      = Vector2.zero;
        trt.offsetMax      = Vector2.zero;

        Text txt           = textGO.AddComponent<Text>();
        txt.text           = "✕  Fermer";
        txt.font           = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        txt.fontSize       = 34;
        txt.fontStyle      = FontStyle.Bold;
        txt.color          = Color.white;
        txt.alignment      = TextAnchor.MiddleCenter;
        txt.raycastTarget  = false;

        Debug.Log("✅ Bouton Fermer créé (order=999)");
    }

    public void ShowCloseButton(bool visible)
    {
        if (_buttonGO != null)
            _buttonGO.SetActive(visible);
        Debug.Log(visible ? "🔴 Bouton affiché" : "✅ Bouton caché");
    }

    void OnFermerPressed()
    {
        Debug.Log("🔴 OnFermerPressed appelé !");
        TapDetector1.DestroyCurrentPrefab(0f);
    }
}*/