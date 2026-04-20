/*ajout de photo token*/
// AROverlayUI.cs
using UnityEngine;
using UnityEngine.UI;
using System.Collections.Generic;

public class AROverlayUI : MonoBehaviour
{
    public static AROverlayUI Instance { get; private set; }

    private ImageCubeDataLibrary.ImageDataEntry _currentData = null;

    private GameObject    _canvasGO;
    private GameObject    _buttonGO;
    private RectTransform _buttonRect;

    private GameObject    _btnArabe;
    private GameObject    _btnFrancais;
    private GameObject    _btnAnglais;
    private RectTransform _btnArabeRect;
    private RectTransform _btnFrancaisRect;
    private RectTransform _btnAnglaisRect;

    // ── NOUVEAU : bouton photo ─────────────────────────────────
    private GameObject    _btnPhoto;
    private RectTransform _btnPhotoRect;
    // ──────────────────────────────────────────────────────────

    private List<Canvas>  _hiddenCanvases = new List<Canvas>();

    // ─────────────────────────────────────────────────────────────
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);

        BuildUI();
        ShowCloseButton(false);
    }

    void OnDestroy()
    {
        if (Instance == this) Instance = null;
    }

    // ─────────────────────────────────────────────────────────────
    public void SetCurrentData(ImageCubeDataLibrary.ImageDataEntry data)
    {
        _currentData = data;
        Debug.Log("📦 AROverlayUI.SetCurrentData → " + (data != null ? data.imageName : "NULL"));
    }

    // ─────────────────────────────────────────────────────────────
    void BuildUI()
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

        // ── Bouton Fermer ──────────────────────────────────────────
        _buttonGO = new GameObject("FermerButton");
        _buttonGO.transform.SetParent(_canvasGO.transform, false);

        Image img = _buttonGO.AddComponent<Image>();
        img.color = new Color(0.85f, 0.1f, 0.1f, 1f);

        _buttonRect                  = _buttonGO.GetComponent<RectTransform>();
        _buttonRect.anchorMin        = new Vector2(0.5f, 1f);
        _buttonRect.anchorMax        = new Vector2(0.5f, 1f);
        _buttonRect.pivot            = new Vector2(0.5f, 1f);
        _buttonRect.anchoredPosition = new Vector2(0f, -60f);
        _buttonRect.sizeDelta        = new Vector2(260f, 80f);

        CreateLabel(_buttonGO, "✕  Fermer", 34);

        // ── Boutons de langue ──────────────────────────────────────
        _btnArabe    = CreateLanguageButton("BtnArabe",    "🇸🇦", "العربية",  new Color(0.00f, 0.55f, 0.25f, 1f), new Vector2(-200f, -170f));
        _btnFrancais = CreateLanguageButton("BtnFrancais", "🇫🇷", "Français", new Color(0.00f, 0.20f, 0.70f, 1f), new Vector2(   0f, -170f));
        _btnAnglais  = CreateLanguageButton("BtnAnglais",  "🇬🇧", "English",  new Color(0.75f, 0.10f, 0.15f, 1f), new Vector2( 200f, -170f));

        _btnArabeRect    = _btnArabe.GetComponent<RectTransform>();
        _btnFrancaisRect = _btnFrancais.GetComponent<RectTransform>();
        _btnAnglaisRect  = _btnAnglais.GetComponent<RectTransform>();

        // ── NOUVEAU : Bouton Photo ─────────────────────────────────
        _btnPhoto     = CreatePhotoButton();
        _btnPhotoRect = _btnPhoto.GetComponent<RectTransform>();
        // ──────────────────────────────────────────────────────────

        Debug.Log("✅ UI construite (bouton Fermer + 3 boutons de langue + bouton Photo)");
    }

    // ─────────────────────────────────────────────────────────────
    // NOUVEAU : création du bouton photo
    // ─────────────────────────────────────────────────────────────
    GameObject CreatePhotoButton()
    {
        GameObject btn = new GameObject("BtnPhoto");
        btn.transform.SetParent(_canvasGO.transform, false);

        Image img = btn.AddComponent<Image>();
        img.color = new Color(0.10f, 0.10f, 0.10f, 0.75f);

        RectTransform rt    = btn.GetComponent<RectTransform>();
        rt.anchorMin        = new Vector2(0.5f, 1f);
        rt.anchorMax        = new Vector2(0.5f, 1f);
        rt.pivot            = new Vector2(0.5f, 1f);
        rt.anchoredPosition = new Vector2(0f, -310f); // sous les boutons de langue
        rt.sizeDelta        = new Vector2(200f, 80f);

        CreateLabel(btn, "📷  Photo", 34);
        return btn;
    }

    // ─────────────────────────────────────────────────────────────
    GameObject CreateLanguageButton(string goName, string emoji, string label, Color couleur, Vector2 position)
    {
        GameObject btn = new GameObject(goName);
        btn.transform.SetParent(_canvasGO.transform, false);

        Image img = btn.AddComponent<Image>();
        img.color = couleur;

        RectTransform rt    = btn.GetComponent<RectTransform>();
        rt.anchorMin        = new Vector2(0.5f, 1f);
        rt.anchorMax        = new Vector2(0.5f, 1f);
        rt.pivot            = new Vector2(0.5f, 1f);
        rt.anchoredPosition = position;
        rt.sizeDelta        = new Vector2(160f, 110f);

        GameObject emojiGO      = new GameObject("Emoji");
        emojiGO.transform.SetParent(btn.transform, false);
        RectTransform ert       = emojiGO.AddComponent<RectTransform>();
        ert.anchorMin           = new Vector2(0f, 0.48f);
        ert.anchorMax           = new Vector2(1f, 1f);
        ert.offsetMin           = Vector2.zero;
        ert.offsetMax           = Vector2.zero;
        Text emojiTxt           = emojiGO.AddComponent<Text>();
        emojiTxt.text           = emoji;
        emojiTxt.font           = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        emojiTxt.fontSize       = 36;
        emojiTxt.alignment      = TextAnchor.MiddleCenter;
        emojiTxt.raycastTarget  = false;

        GameObject labelGO      = new GameObject("Label");
        labelGO.transform.SetParent(btn.transform, false);
        RectTransform lrt       = labelGO.AddComponent<RectTransform>();
        lrt.anchorMin           = new Vector2(0f, 0f);
        lrt.anchorMax           = new Vector2(1f, 0.48f);
        lrt.offsetMin           = Vector2.zero;
        lrt.offsetMax           = Vector2.zero;
        Text labelTxt           = labelGO.AddComponent<Text>();
        labelTxt.text           = label;
        labelTxt.font           = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        labelTxt.fontSize       = 20;
        labelTxt.fontStyle      = FontStyle.Bold;
        labelTxt.color          = Color.white;
        labelTxt.alignment      = TextAnchor.MiddleCenter;
        labelTxt.raycastTarget  = false;

        return btn;
    }

    // ─────────────────────────────────────────────────────────────
    void CreateLabel(GameObject parent, string texte, int fontSize)
    {
        GameObject textGO   = new GameObject("Texte");
        textGO.transform.SetParent(parent.transform, false);

        RectTransform trt   = textGO.AddComponent<RectTransform>();
        trt.anchorMin       = Vector2.zero;
        trt.anchorMax       = Vector2.one;
        trt.offsetMin       = Vector2.zero;
        trt.offsetMax       = Vector2.zero;

        Text txt            = textGO.AddComponent<Text>();
        txt.text            = texte;
        txt.font            = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        txt.fontSize        = fontSize;
        txt.fontStyle       = FontStyle.Bold;
        txt.color           = Color.white;
        txt.alignment       = TextAnchor.MiddleCenter;
        txt.raycastTarget   = false;
    }

    // ─────────────────────────────────────────────────────────────
    public void EnterPrefabMode()
    {
        _hiddenCanvases.Clear();
        foreach (Canvas c in FindObjectsOfType<Canvas>())
        {
            if (c.gameObject == _canvasGO) continue;
            if (c.enabled)
            {
                c.enabled = false;
                _hiddenCanvases.Add(c);
            }
        }

        ShowCloseButton(true);
        Debug.Log($"🔴 PrefabMode ON — {_hiddenCanvases.Count} canvas masqués");
    }

    public void ExitPrefabMode()
    {
        foreach (Canvas c in _hiddenCanvases)
            if (c != null) c.enabled = true;

        _hiddenCanvases.Clear();
        _currentData = null;

        ShowCloseButton(false);
        Debug.Log("✅ PrefabMode OFF — UI restaurée");
    }

    // ─────────────────────────────────────────────────────────────
    public void ShowCloseButton(bool visible)
    {
        if (_buttonGO    != null) _buttonGO.SetActive(visible);
        if (_btnArabe    != null) _btnArabe.SetActive(visible);
        if (_btnFrancais != null) _btnFrancais.SetActive(visible);
        if (_btnAnglais  != null) _btnAnglais.SetActive(visible);
        // NOUVEAU
        if (_btnPhoto    != null) _btnPhoto.SetActive(visible);
    }

    // ─────────────────────────────────────────────────────────────
    public bool IsTapOnCloseButton(Vector2 screenPosition)
    {
        if (_buttonGO == null || !_buttonGO.activeSelf) return false;
        return RectTransformUtility.RectangleContainsScreenPoint(
            _buttonRect, screenPosition, null);
    }

    // ─────────────────────────────────────────────────────────────
    // NOUVEAU : détection tap sur bouton photo
    // ─────────────────────────────────────────────────────────────
    public bool IsTapOnPhotoButton(Vector2 screenPosition)
    {
        if (_btnPhoto == null || !_btnPhoto.activeSelf) return false;

        if (RectTransformUtility.RectangleContainsScreenPoint(_btnPhotoRect, screenPosition, null))
        {
            Debug.Log("📷 Tap sur bouton Photo → lancement capture");
            ScreenshotManager.Instance?.TakeAndSaveScreenshot();
            return true;
        }
        return false;
    }

    // ─────────────────────────────────────────────────────────────
    public bool IsTapOnLanguageButton(Vector2 screenPosition)
    {
        if (_btnArabe == null || !_btnArabe.activeSelf) return false;

        if (RectTransformUtility.RectangleContainsScreenPoint(_btnArabeRect, screenPosition, null))
        {
            TTSLanguagePlayer.Instance?.PlayLangue(TTSLanguagePlayer.Langue.Arabe, _currentData);
            return true;
        }
        if (RectTransformUtility.RectangleContainsScreenPoint(_btnFrancaisRect, screenPosition, null))
        {
            TTSLanguagePlayer.Instance?.PlayLangue(TTSLanguagePlayer.Langue.Francais, _currentData);
            return true;
        }
        if (RectTransformUtility.RectangleContainsScreenPoint(_btnAnglaisRect, screenPosition, null))
        {
            TTSLanguagePlayer.Instance?.PlayLangue(TTSLanguagePlayer.Langue.Anglais, _currentData);
            return true;
        }

        return false;
    }

    // ─────────────────────────────────────────────────────────────
    public void OnFermerPressed()
    {
        Debug.Log("🔴 Fermer appuyé → destruction prefab");
        ExitPrefabMode();
        TapDetector1.DestroyCurrentPrefab(0f);
    }
}
/*ajouter api1 pour tts 
// AROverlayUI.cs
using UnityEngine;
using UnityEngine.UI;
using System.Collections.Generic;

public class AROverlayUI : MonoBehaviour
{
    public static AROverlayUI Instance { get; private set; }

    // Plus d'AudioClip publics ici — tout passe par TTSLanguagePlayer + ScriptableObject
    private ImageCubeDataLibrary.ImageDataEntry _currentData = null;

    private GameObject    _canvasGO;
    private GameObject    _buttonGO;
    private RectTransform _buttonRect;

    private GameObject    _btnArabe;
    private GameObject    _btnFrancais;
    private GameObject    _btnAnglais;
    private RectTransform _btnArabeRect;
    private RectTransform _btnFrancaisRect;
    private RectTransform _btnAnglaisRect;

    private List<Canvas>  _hiddenCanvases = new List<Canvas>();

    // ─────────────────────────────────────────────────────────────
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);

        BuildUI();
        ShowCloseButton(false);
    }

    void OnDestroy()
    {
        if (Instance == this) Instance = null;
    }

    // ─────────────────────────────────────────────────────────────
    /// <summary>
    /// Appelé par TapDetector1 juste avant EnterPrefabMode()
    /// pour que les boutons langue sachent quel texte lire.
    /// </summary>
    public void SetCurrentData(ImageCubeDataLibrary.ImageDataEntry data)
    {
        _currentData = data;
        Debug.Log("📦 AROverlayUI.SetCurrentData → " + (data != null ? data.imageName : "NULL"));
    }

    // ─────────────────────────────────────────────────────────────
    void BuildUI()
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

        // ── Bouton Fermer ──────────────────────────────────────────
        _buttonGO = new GameObject("FermerButton");
        _buttonGO.transform.SetParent(_canvasGO.transform, false);

        Image img = _buttonGO.AddComponent<Image>();
        img.color = new Color(0.85f, 0.1f, 0.1f, 1f);

        _buttonRect                  = _buttonGO.GetComponent<RectTransform>();
        _buttonRect.anchorMin        = new Vector2(0.5f, 1f);
        _buttonRect.anchorMax        = new Vector2(0.5f, 1f);
        _buttonRect.pivot            = new Vector2(0.5f, 1f);
        _buttonRect.anchoredPosition = new Vector2(0f, -60f);
        _buttonRect.sizeDelta        = new Vector2(260f, 80f);

        CreateLabel(_buttonGO, "✕  Fermer", 34);

        // ── Boutons de langue ──────────────────────────────────────
        _btnArabe    = CreateLanguageButton("BtnArabe",    "🇸🇦", "العربية",  new Color(0.00f, 0.55f, 0.25f, 1f), new Vector2(-200f, -170f));
        _btnFrancais = CreateLanguageButton("BtnFrancais", "🇫🇷", "Français", new Color(0.00f, 0.20f, 0.70f, 1f), new Vector2(   0f, -170f));
        _btnAnglais  = CreateLanguageButton("BtnAnglais",  "🇬🇧", "English",  new Color(0.75f, 0.10f, 0.15f, 1f), new Vector2( 200f, -170f));

        _btnArabeRect    = _btnArabe.GetComponent<RectTransform>();
        _btnFrancaisRect = _btnFrancais.GetComponent<RectTransform>();
        _btnAnglaisRect  = _btnAnglais.GetComponent<RectTransform>();

        Debug.Log("✅ UI construite (bouton Fermer + 3 boutons de langue)");
    }

    // ─────────────────────────────────────────────────────────────
    GameObject CreateLanguageButton(string goName, string emoji, string label, Color couleur, Vector2 position)
    {
        GameObject btn = new GameObject(goName);
        btn.transform.SetParent(_canvasGO.transform, false);

        Image img = btn.AddComponent<Image>();
        img.color = couleur;

        RectTransform rt    = btn.GetComponent<RectTransform>();
        rt.anchorMin        = new Vector2(0.5f, 1f);
        rt.anchorMax        = new Vector2(0.5f, 1f);
        rt.pivot            = new Vector2(0.5f, 1f);
        rt.anchoredPosition = position;
        rt.sizeDelta        = new Vector2(160f, 110f);

        // Emoji drapeau (haut)
        GameObject emojiGO      = new GameObject("Emoji");
        emojiGO.transform.SetParent(btn.transform, false);
        RectTransform ert       = emojiGO.AddComponent<RectTransform>();
        ert.anchorMin           = new Vector2(0f, 0.48f);
        ert.anchorMax           = new Vector2(1f, 1f);
        ert.offsetMin           = Vector2.zero;
        ert.offsetMax           = Vector2.zero;
        Text emojiTxt           = emojiGO.AddComponent<Text>();
        emojiTxt.text           = emoji;
        emojiTxt.font           = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        emojiTxt.fontSize       = 36;
        emojiTxt.alignment      = TextAnchor.MiddleCenter;
        emojiTxt.raycastTarget  = false;

        // Libellé langue (bas)
        GameObject labelGO      = new GameObject("Label");
        labelGO.transform.SetParent(btn.transform, false);
        RectTransform lrt       = labelGO.AddComponent<RectTransform>();
        lrt.anchorMin           = new Vector2(0f, 0f);
        lrt.anchorMax           = new Vector2(1f, 0.48f);
        lrt.offsetMin           = Vector2.zero;
        lrt.offsetMax           = Vector2.zero;
        Text labelTxt           = labelGO.AddComponent<Text>();
        labelTxt.text           = label;
        labelTxt.font           = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        labelTxt.fontSize       = 20;
        labelTxt.fontStyle      = FontStyle.Bold;
        labelTxt.color          = Color.white;
        labelTxt.alignment      = TextAnchor.MiddleCenter;
        labelTxt.raycastTarget  = false;

        return btn;
    }

    // ─────────────────────────────────────────────────────────────
    void CreateLabel(GameObject parent, string texte, int fontSize)
    {
        GameObject textGO   = new GameObject("Texte");
        textGO.transform.SetParent(parent.transform, false);

        RectTransform trt   = textGO.AddComponent<RectTransform>();
        trt.anchorMin       = Vector2.zero;
        trt.anchorMax       = Vector2.one;
        trt.offsetMin       = Vector2.zero;
        trt.offsetMax       = Vector2.zero;

        Text txt            = textGO.AddComponent<Text>();
        txt.text            = texte;
        txt.font            = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        txt.fontSize        = fontSize;
        txt.fontStyle       = FontStyle.Bold;
        txt.color           = Color.white;
        txt.alignment       = TextAnchor.MiddleCenter;
        txt.raycastTarget   = false;
    }

    // ─────────────────────────────────────────────────────────────
    public void EnterPrefabMode()
    {
        _hiddenCanvases.Clear();
        foreach (Canvas c in FindObjectsOfType<Canvas>())
        {
            if (c.gameObject == _canvasGO) continue;
            if (c.enabled)
            {
                c.enabled = false;
                _hiddenCanvases.Add(c);
            }
        }

        ShowCloseButton(true);
        Debug.Log($"🔴 PrefabMode ON — {_hiddenCanvases.Count} canvas masqués");
    }

    public void ExitPrefabMode()
    {
        foreach (Canvas c in _hiddenCanvases)
            if (c != null) c.enabled = true;

        _hiddenCanvases.Clear();
        _currentData = null;

        ShowCloseButton(false);
        Debug.Log("✅ PrefabMode OFF — UI restaurée");
    }

    // ─────────────────────────────────────────────────────────────
    public void ShowCloseButton(bool visible)
    {
        if (_buttonGO    != null) _buttonGO.SetActive(visible);
        if (_btnArabe    != null) _btnArabe.SetActive(visible);
        if (_btnFrancais != null) _btnFrancais.SetActive(visible);
        if (_btnAnglais  != null) _btnAnglais.SetActive(visible);
    }

    // ─────────────────────────────────────────────────────────────
    public bool IsTapOnCloseButton(Vector2 screenPosition)
    {
        if (_buttonGO == null || !_buttonGO.activeSelf) return false;
        return RectTransformUtility.RectangleContainsScreenPoint(
            _buttonRect, screenPosition, null);
    }

    // ─────────────────────────────────────────────────────────────
    public bool IsTapOnLanguageButton(Vector2 screenPosition)
    {
        if (_btnArabe == null || !_btnArabe.activeSelf) return false;

        if (RectTransformUtility.RectangleContainsScreenPoint(_btnArabeRect, screenPosition, null))
        {
            TTSLanguagePlayer.Instance?.PlayLangue(TTSLanguagePlayer.Langue.Arabe, _currentData);
            return true;
        }
        if (RectTransformUtility.RectangleContainsScreenPoint(_btnFrancaisRect, screenPosition, null))
        {
            TTSLanguagePlayer.Instance?.PlayLangue(TTSLanguagePlayer.Langue.Francais, _currentData);
            return true;
        }
        if (RectTransformUtility.RectangleContainsScreenPoint(_btnAnglaisRect, screenPosition, null))
        {
            TTSLanguagePlayer.Instance?.PlayLangue(TTSLanguagePlayer.Langue.Anglais, _currentData);
            return true;
        }

        return false;
    }

    // ─────────────────────────────────────────────────────────────
    public void OnFermerPressed()
    {
        Debug.Log("🔴 Fermer appuyé → destruction prefab");
        ExitPrefabMode();
        TapDetector1.DestroyCurrentPrefab(0f);
    }
}
/*ajout de la langue 
// AROverlayUI.cs
using UnityEngine;
using UnityEngine.UI;
using System.Collections.Generic;

public class AROverlayUI : MonoBehaviour
{
    public static AROverlayUI Instance { get; private set; }

    [Header("Sons des langues (assigner dans l'Inspector)")]
    public AudioClip sonArabe;
    public AudioClip sonFrancais;
    public AudioClip sonAnglais;

    private AudioSource _audioSource;

    private GameObject    _canvasGO;
    private GameObject    _buttonGO;
    private RectTransform _buttonRect;

    // Boutons de langue
    private GameObject    _btnArabe;
    private GameObject    _btnFrancais;
    private GameObject    _btnAnglais;
    private RectTransform _btnArabeRect;
    private RectTransform _btnFrancaisRect;
    private RectTransform _btnAnglaisRect;

    private List<Canvas>  _hiddenCanvases = new List<Canvas>();

    // ─────────────────────────────────────────────────────────────
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);

        // AudioSource pour jouer les sons
        _audioSource = gameObject.AddComponent<AudioSource>();
        _audioSource.playOnAwake = false;

        BuildUI();
        ShowCloseButton(false);
    }

    void OnDestroy()
    {
        if (Instance == this) Instance = null;
    }

    // ─────────────────────────────────────────────────────────────
    void BuildUI()
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

        // ── Bouton Fermer ──────────────────────────────────────────
        _buttonGO = new GameObject("FermerButton");
        _buttonGO.transform.SetParent(_canvasGO.transform, false);

        Image img = _buttonGO.AddComponent<Image>();
        img.color = new Color(0.85f, 0.1f, 0.1f, 1f);

        _buttonRect                   = _buttonGO.GetComponent<RectTransform>();
        _buttonRect.anchorMin         = new Vector2(0.5f, 1f);
        _buttonRect.anchorMax         = new Vector2(0.5f, 1f);
        _buttonRect.pivot             = new Vector2(0.5f, 1f);
        _buttonRect.anchoredPosition  = new Vector2(0f, -60f);
        _buttonRect.sizeDelta         = new Vector2(260f, 80f);

        CreateLabel(_buttonGO, "✕  Fermer", 34);

        // ── Boutons de langue (en dessous du bouton Fermer) ────────
        // Positions : centrés, espacés horizontalement
        // Fermer est à Y=-60, hauteur=80 → bas du Fermer = -140
        // On place les drapeaux à Y=-160 (avec un petit gap)

        _btnArabe    = CreateLanguageButton("BtnArabe",    "🇸🇦", "العربية", new Color(0.00f, 0.55f, 0.25f, 1f), new Vector2(-200f, -170f));
        _btnFrancais = CreateLanguageButton("BtnFrancais", "🇫🇷", "Français", new Color(0.00f, 0.20f, 0.70f, 1f), new Vector2(   0f, -170f));
        _btnAnglais  = CreateLanguageButton("BtnAnglais",  "🇬🇧", "English",  new Color(0.75f, 0.10f, 0.15f, 1f), new Vector2( 200f, -170f));

        _btnArabeRect    = _btnArabe.GetComponent<RectTransform>();
        _btnFrancaisRect = _btnFrancais.GetComponent<RectTransform>();
        _btnAnglaisRect  = _btnAnglais.GetComponent<RectTransform>();

        Debug.Log("✅ UI construite (bouton Fermer + 3 boutons de langue)");
    }

    // ─────────────────────────────────────────────────────────────
    /// <summary>Crée un bouton langue avec emoji drapeau + libellé.</summary>
    GameObject CreateLanguageButton(string goName, string emoji, string label, Color couleur, Vector2 position)
    {
        GameObject btn = new GameObject(goName);
        btn.transform.SetParent(_canvasGO.transform, false);

        Image img = btn.AddComponent<Image>();
        img.color = couleur;

        RectTransform rt   = btn.GetComponent<RectTransform>();
        rt.anchorMin       = new Vector2(0.5f, 1f);
        rt.anchorMax       = new Vector2(0.5f, 1f);
        rt.pivot           = new Vector2(0.5f, 1f);
        rt.anchoredPosition = position;
        rt.sizeDelta       = new Vector2(160f, 110f);

        // Emoji drapeau (haut)
        GameObject emojiGO = new GameObject("Emoji");
        emojiGO.transform.SetParent(btn.transform, false);
        RectTransform ert  = emojiGO.AddComponent<RectTransform>();
        ert.anchorMin      = new Vector2(0f, 0.48f);
        ert.anchorMax      = new Vector2(1f, 1f);
        ert.offsetMin      = Vector2.zero;
        ert.offsetMax      = Vector2.zero;
        Text emojiTxt      = emojiGO.AddComponent<Text>();
        emojiTxt.text      = emoji;
        emojiTxt.font      = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        emojiTxt.fontSize  = 36;
        emojiTxt.alignment = TextAnchor.MiddleCenter;
        emojiTxt.raycastTarget = false;

        // Libellé langue (bas)
        GameObject labelGO = new GameObject("Label");
        labelGO.transform.SetParent(btn.transform, false);
        RectTransform lrt  = labelGO.AddComponent<RectTransform>();
        lrt.anchorMin      = new Vector2(0f, 0f);
        lrt.anchorMax      = new Vector2(1f, 0.48f);
        lrt.offsetMin      = Vector2.zero;
        lrt.offsetMax      = Vector2.zero;
        Text labelTxt      = labelGO.AddComponent<Text>();
        labelTxt.text      = label;
        labelTxt.font      = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        labelTxt.fontSize  = 20;
        labelTxt.fontStyle = FontStyle.Bold;
        labelTxt.color     = Color.white;
        labelTxt.alignment = TextAnchor.MiddleCenter;
        labelTxt.raycastTarget = false;

        return btn;
    }

    // ─────────────────────────────────────────────────────────────
    void CreateLabel(GameObject parent, string texte, int fontSize)
    {
        GameObject textGO = new GameObject("Texte");
        textGO.transform.SetParent(parent.transform, false);

        RectTransform trt = textGO.AddComponent<RectTransform>();
        trt.anchorMin     = Vector2.zero;
        trt.anchorMax     = Vector2.one;
        trt.offsetMin     = Vector2.zero;
        trt.offsetMax     = Vector2.zero;

        Text txt          = textGO.AddComponent<Text>();
        txt.text          = texte;
        txt.font          = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        txt.fontSize      = fontSize;
        txt.fontStyle     = FontStyle.Bold;
        txt.color         = Color.white;
        txt.alignment     = TextAnchor.MiddleCenter;
        txt.raycastTarget = false;
    }

    // ─────────────────────────────────────────────────────────────
    public void EnterPrefabMode()
    {
        _hiddenCanvases.Clear();
        foreach (Canvas c in FindObjectsOfType<Canvas>())
        {
            if (c.gameObject == _canvasGO) continue;
            if (c.enabled)
            {
                c.enabled = false;
                _hiddenCanvases.Add(c);
            }
        }

        ShowCloseButton(true);
        Debug.Log($"🔴 PrefabMode ON — {_hiddenCanvases.Count} canvas masqués");
    }

    public void ExitPrefabMode()
    {
        foreach (Canvas c in _hiddenCanvases)
        {
            if (c != null) c.enabled = true;
        }
        _hiddenCanvases.Clear();

        ShowCloseButton(false);
        Debug.Log("✅ PrefabMode OFF — UI restaurée");
    }

    // ─────────────────────────────────────────────────────────────
    public void ShowCloseButton(bool visible)
    {
        if (_buttonGO    != null) _buttonGO.SetActive(visible);
        if (_btnArabe    != null) _btnArabe.SetActive(visible);
        if (_btnFrancais != null) _btnFrancais.SetActive(visible);
        if (_btnAnglais  != null) _btnAnglais.SetActive(visible);
    }

    // ─────────────────────────────────────────────────────────────
    public bool IsTapOnCloseButton(Vector2 screenPosition)
    {
        if (_buttonGO == null || !_buttonGO.activeSelf) return false;
        return RectTransformUtility.RectangleContainsScreenPoint(
            _buttonRect, screenPosition, null);
    }

    /// <summary>
    /// À appeler depuis TapDetector à chaque frame / à chaque tap.
    /// Retourne true si le tap était sur un bouton de langue (pour ne pas propager l'événement).
    /// </summary>
    public bool IsTapOnLanguageButton(Vector2 screenPosition)
    {
        if (_btnArabe == null || !_btnArabe.activeSelf) return false;

        if (RectTransformUtility.RectangleContainsScreenPoint(_btnArabeRect,    screenPosition, null))
        {
            PlaySon(sonArabe, "Arabe");
            return true;
        }
        if (RectTransformUtility.RectangleContainsScreenPoint(_btnFrancaisRect, screenPosition, null))
        {
            PlaySon(sonFrancais, "Français");
            return true;
        }
        if (RectTransformUtility.RectangleContainsScreenPoint(_btnAnglaisRect,  screenPosition, null))
        {
            PlaySon(sonAnglais, "Anglais");
            return true;
        }

        return false;
    }

    // ─────────────────────────────────────────────────────────────
    void PlaySon(AudioClip clip, string langue)
    {
        if (clip == null)
        {
            Debug.LogWarning($"⚠️ Son {langue} non assigné dans l'Inspector !");
            return;
        }
        _audioSource.Stop();
        _audioSource.clip = clip;
        _audioSource.Play();
        Debug.Log($"🔊 Son {langue} joué : {clip.name}");
    }

    // ─────────────────────────────────────────────────────────────
    public void OnFermerPressed()
    {
        Debug.Log("🔴 Fermer appuyé → destruction prefab");
        ExitPrefabMode();
        TapDetector1.DestroyCurrentPrefab(0f);
    }
}
/*essaye de eliminer tout ui quand on spawn
// AROverlayUI.cs
using UnityEngine;
using UnityEngine.UI;
using System.Collections.Generic;

public class AROverlayUI : MonoBehaviour
{
    public static AROverlayUI Instance { get; private set; }

    private GameObject    _canvasGO;
    private GameObject    _buttonGO;
    private RectTransform _buttonRect;
    private List<Canvas>  _hiddenCanvases = new List<Canvas>();

    // ─────────────────────────────────────────────────────────────
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        BuildUI();
        ShowCloseButton(false);
    }

    void OnDestroy()
    {
        if (Instance == this) Instance = null;
    }

    // ─────────────────────────────────────────────────────────────
    void BuildUI()
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

        // Pas de GraphicRaycaster — on utilise RectTransformUtility

        _buttonGO = new GameObject("FermerButton");
        _buttonGO.transform.SetParent(_canvasGO.transform, false);

        Image img = _buttonGO.AddComponent<Image>();
        img.color = new Color(0.85f, 0.1f, 0.1f, 1f);

        _buttonRect                   = _buttonGO.GetComponent<RectTransform>();
        _buttonRect.anchorMin         = new Vector2(0.5f, 1f);
        _buttonRect.anchorMax         = new Vector2(0.5f, 1f);
        _buttonRect.pivot             = new Vector2(0.5f, 1f);
        _buttonRect.anchoredPosition  = new Vector2(0f, -60f);
        _buttonRect.sizeDelta         = new Vector2(260f, 80f);

        GameObject textGO = new GameObject("Texte");
        textGO.transform.SetParent(_buttonGO.transform, false);

        RectTransform trt = textGO.AddComponent<RectTransform>();
        trt.anchorMin     = Vector2.zero;
        trt.anchorMax     = Vector2.one;
        trt.offsetMin     = Vector2.zero;
        trt.offsetMax     = Vector2.zero;

        Text txt          = textGO.AddComponent<Text>();
        txt.text          = "✕  Fermer";
        txt.font          = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        txt.fontSize      = 34;
        txt.fontStyle     = FontStyle.Bold;
        txt.color         = Color.white;
        txt.alignment     = TextAnchor.MiddleCenter;
        txt.raycastTarget = false;

        Debug.Log("✅ UI construite (bouton Fermer)");
    }

    // ─────────────────────────────────────────────────────────────
    public void EnterPrefabMode()
    {
        _hiddenCanvases.Clear();
        foreach (Canvas c in FindObjectsOfType<Canvas>())
        {
            if (c.gameObject == _canvasGO) continue;
            if (c.enabled)
            {
                c.enabled = false;
                _hiddenCanvases.Add(c);
            }
        }

        ShowCloseButton(true);
        Debug.Log($"🔴 PrefabMode ON — {_hiddenCanvases.Count} canvas masqués");
    }

    public void ExitPrefabMode()
    {
        foreach (Canvas c in _hiddenCanvases)
        {
            if (c != null) c.enabled = true;
        }
        _hiddenCanvases.Clear();

        ShowCloseButton(false);
        Debug.Log("✅ PrefabMode OFF — UI restaurée");
    }

    // ─────────────────────────────────────────────────────────────
    public void ShowCloseButton(bool visible)
    {
        if (_buttonGO != null)
            _buttonGO.SetActive(visible);
    }

    // ─────────────────────────────────────────────────────────────
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
        ExitPrefabMode();
        TapDetector1.DestroyCurrentPrefab(0f);
    }
}*/