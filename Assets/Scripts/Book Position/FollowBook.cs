using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using TMPro;

public class FollowBook : MonoBehaviour
{
    [Header("AR References")]
    [SerializeField] private ARTrackedImageManager trackedImageManager;
    [SerializeField] private Camera arCamera;

    [Header("Placeholder Icon")]
    [SerializeField] private Sprite placeholderSprite;
    [SerializeField] private float iconSize = 100f;
    [SerializeField] private Color iconColor = Color.white;
    [SerializeField] private float iconRotationSpeed = 360f;

    [Header("Frame Settings")]
    [SerializeField] private float framePadding = 50f;

    [Header("Found Message")]
    [SerializeField] private Color foundMessageColor = Color.white;
    [SerializeField] private float foundMessageFontSize = 48f;

    [SerializeField] private bool rotateIcon = false;

    public static Vector3 BookWorldPosition { get; private set; }
    public static bool BookDetected { get; private set; } = false;

    private Canvas _canvas;
    private RectTransform _frameRect;
    private RectTransform _iconRect;
    private Image _iconImage;
    private GameObject _foundMessageGO;
    private TextMeshProUGUI _foundMessageText;

    private bool _bookVisible = false;
    private bool _foundMessageShown = false;
    private Coroutine _messageCoroutine;

    private float _currentAngle = 90f;
    private bool _angleInitialized = false;
    private Vector2 _screenDirection;

    // 🔥 Vibration control
    private bool _wasVisible = false;

    private void Awake()
    {
        if (arCamera == null)
            arCamera = Camera.main;

        BuildUI();
    }

    private void OnEnable()
    {
        if (trackedImageManager != null)
            trackedImageManager.trackablesChanged.AddListener(OnTrackedImagesChanged);
    }

    private void OnDisable()
    {
        if (trackedImageManager != null)
            trackedImageManager.trackablesChanged.RemoveListener(OnTrackedImagesChanged);
    }

    private void OnTrackedImagesChanged(ARTrackablesChangedEventArgs<ARTrackedImage> args)
    {
        foreach (var img in args.added)
            MemorizePosition(img);

        foreach (var img in args.updated)
            if (img.trackingState == TrackingState.Tracking)
                MemorizePosition(img);

        bool stillVisible = false;
        foreach (var img in trackedImageManager.trackables)
        {
            if (img.trackingState == TrackingState.Tracking)
            {
                stillVisible = true;
                break;
            }
        }

        _bookVisible = stillVisible;
    }

    private void MemorizePosition(ARTrackedImage trackedImage)
    {
        BookWorldPosition = trackedImage.transform.position;
        BookDetected = true;
    }

    private void Update()
    {
        if (_iconRect == null) return;

        // ❌ livre jamais détecté
        if (!BookDetected)
        {
            _iconRect.gameObject.SetActive(false);
            _foundMessageGO?.SetActive(false);
            _angleInitialized = false;
            _foundMessageShown = false;
            _wasVisible = false;
            return;
        }

        // 📳 VIBRATION (une seule fois à l'apparition)
        if (_bookVisible && !_wasVisible)
        {
            Handheld.Vibrate();
            Debug.Log("📳 Livre détecté → vibration");
        }

        _wasVisible = _bookVisible;

        UpdateScreenDirection();

        // 📖 LIVRE VISIBLE
        if (_bookVisible)
        {
            _iconRect.gameObject.SetActive(false);

            if (!_foundMessageShown)
            {
                _foundMessageShown = true;
                ShowFoundMessage();
            }
        }
        // 🔍 LIVRE NON VISIBLE
        else
        {
            _foundMessageShown = false;

            HideFoundMessage();
            _iconRect.gameObject.SetActive(true);
            MoveIconToEdge();
        }
    }

    // ───── DIRECTION ─────

    private void UpdateScreenDirection()
    {
        if (arCamera == null) return;

        Vector3 viewportPos = arCamera.WorldToViewportPoint(BookWorldPosition);
        Vector2 center = new Vector2(0.5f, 0.5f);

        _screenDirection = new Vector2(
            viewportPos.x - center.x,
            viewportPos.y - center.y
        );
    }

    private void MoveIconToEdge()
    {
        if (_screenDirection.magnitude < 0.001f) return;

        float halfW = _frameRect.rect.width * 0.5f;
        float halfH = _frameRect.rect.height * 0.5f;

        float targetAngle = Mathf.Atan2(_screenDirection.y, _screenDirection.x) * Mathf.Rad2Deg;

        if (!_angleInitialized)
        {
            _currentAngle = targetAngle;
            _angleInitialized = true;
        }

        _currentAngle = Mathf.MoveTowardsAngle(
            _currentAngle,
            targetAngle,
            iconRotationSpeed * Time.deltaTime
        );

        float rad = _currentAngle * Mathf.Deg2Rad;
        Vector2 dir = new Vector2(Mathf.Cos(rad), Mathf.Sin(rad));

        float scaleX = (dir.x != 0) ? halfW / Mathf.Abs(dir.x) : float.MaxValue;
        float scaleY = (dir.y != 0) ? halfH / Mathf.Abs(dir.y) : float.MaxValue;
        float scale = Mathf.Min(scaleX, scaleY);

        _iconRect.anchoredPosition = dir * scale;

        if (rotateIcon)
            _iconRect.localEulerAngles = new Vector3(0f, 0f, _currentAngle - 90f);
        else
            _iconRect.localEulerAngles = Vector3.zero;
    }

    // ───── MESSAGE ─────

    private void ShowFoundMessage()
    {
        if (_foundMessageGO == null) return;

        _foundMessageGO.SetActive(true);

        if (_foundMessageText != null)
            _foundMessageText.text = "📖 Livre Trouvé !";

        if (_messageCoroutine != null)
            StopCoroutine(_messageCoroutine);

        _messageCoroutine = StartCoroutine(ShowMessageTemporarily());
    }

    private IEnumerator ShowMessageTemporarily()
    {
        yield return AnimateFoundMessage();
        yield return new WaitForSeconds(2.5f);
        _foundMessageGO.SetActive(false);
    }

    private void HideFoundMessage()
    {
        if (_foundMessageGO != null)
            _foundMessageGO.SetActive(false);

        if (_messageCoroutine != null)
        {
            StopCoroutine(_messageCoroutine);
            _messageCoroutine = null;
        }
    }

    private IEnumerator AnimateFoundMessage()
    {
        RectTransform rt = _foundMessageGO.GetComponent<RectTransform>();
        rt.localScale = Vector3.zero;

        yield return ScaleTo(rt, 0f, 1.3f, 0.4f);
        yield return ScaleTo(rt, 1.3f, 0.9f, 0.25f);
        yield return ScaleTo(rt, 0.9f, 1f, 0.2f);

        rt.localScale = Vector3.one;
    }

    private IEnumerator ScaleTo(RectTransform rt, float from, float to, float duration)
    {
        float elapsed = 0f;

        while (elapsed < duration)
        {
            elapsed += Time.deltaTime;

            rt.localScale = Vector3.one *
                Mathf.Lerp(from, to,
                Mathf.SmoothStep(0f, 1f, elapsed / duration));

            yield return null;
        }
    }

    // ───── UI ─────

    private void BuildUI()
    {
        GameObject canvasGO = new GameObject("Canvas");
        canvasGO.transform.SetParent(transform);

        Canvas canvas = canvasGO.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;

        CanvasScaler scaler = canvasGO.AddComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1080, 1920);

        canvasGO.AddComponent<GraphicRaycaster>();

        GameObject frameGO = new GameObject("FrameRect");
        frameGO.transform.SetParent(canvasGO.transform, false);

        Image frameBg = frameGO.AddComponent<Image>();
        frameBg.color = new Color(0, 0, 0, 0);

        _frameRect = frameGO.GetComponent<RectTransform>();
        _frameRect.anchorMin = Vector2.zero;
        _frameRect.anchorMax = Vector2.one;
        _frameRect.offsetMin = new Vector2(framePadding, framePadding);
        _frameRect.offsetMax = new Vector2(-framePadding, -framePadding);

        GameObject iconGO = new GameObject("Icon");
        iconGO.transform.SetParent(frameGO.transform, false);

        _iconImage = iconGO.AddComponent<Image>();
        _iconImage.sprite = placeholderSprite;
        _iconImage.color = iconColor;

        _iconRect = iconGO.GetComponent<RectTransform>();
        _iconRect.anchorMin = _iconRect.anchorMax = new Vector2(0.5f, 0.5f);
        _iconRect.sizeDelta = new Vector2(iconSize, iconSize);
        _iconRect.gameObject.SetActive(false);

        // 📩 MESSAGE EN BAS
        _foundMessageGO = new GameObject("FoundMessage");
        _foundMessageGO.transform.SetParent(canvasGO.transform, false);

        _foundMessageText = _foundMessageGO.AddComponent<TextMeshProUGUI>();
        _foundMessageText.fontSize = foundMessageFontSize;
        _foundMessageText.color = foundMessageColor;
        _foundMessageText.alignment = TextAlignmentOptions.Center;

        RectTransform msgRect = _foundMessageGO.GetComponent<RectTransform>();
        msgRect.anchorMin = new Vector2(0.5f, 0f);
        msgRect.anchorMax = new Vector2(0.5f, 0f);
        msgRect.pivot = new Vector2(0.5f, 0f);
        msgRect.sizeDelta = new Vector2(700, 120);
        msgRect.anchoredPosition = new Vector2(0, 100);

        _foundMessageGO.SetActive(false);
    }
}

/*using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using TMPro;

public class FollowBook : MonoBehaviour
{
    // ─── Inspecteur ───────────────────────────────────────────────────────────

    [Header("AR References")]
    [SerializeField] private ARTrackedImageManager trackedImageManager;
    [SerializeField] private Camera arCamera;

    [Header("Placeholder Icon")]
    [SerializeField] private Sprite placeholderSprite;   // ← assigne ton sprite ici !
    [SerializeField] private float iconSize = 100f;
    [SerializeField] private Color iconColor = Color.white;
    [SerializeField] private float iconRotationSpeed = 360f;

    [Header("Frame Settings")]
    [SerializeField] private float framePadding = 50f;   // offset 50 sur les 4 côtés

    [Header("Found Message")]
    [SerializeField] private Color foundMessageColor = Color.white;
    [SerializeField] private float foundMessageFontSize = 48f;

    [SerializeField] private bool rotateIcon = false;

    // ─── Données statiques ────────────────────────────────────────────────────

    public static Vector3 BookWorldPosition { get; private set; }
    public static bool BookDetected { get; private set; } = false;

    // ─── UI ───────────────────────────────────────────────────────────────────

    private Canvas _canvas;
    private RectTransform _frameRect;
    private RectTransform _iconRect;
    private Image _iconImage;
    private GameObject _foundMessageGO;
    private TextMeshProUGUI _foundMessageText;

    // ─── État ─────────────────────────────────────────────────────────────────

    private bool _bookVisible = false;
    private bool _foundMessageShown = false;
    private Coroutine _messageCoroutine;
    private float _currentAngle = 90f;
    private bool _angleInitialized = false;
    private Vector2 _screenDirection;

    // ─────────────────────────────────────────────────────────────────────────
    // LIFECYCLE
    // ─────────────────────────────────────────────────────────────────────────

    private void Awake()
    {
        if (arCamera == null)
            arCamera = Camera.main;

        BuildUI();
    }

    private void OnEnable()
    {
        if (trackedImageManager != null)
            trackedImageManager.trackablesChanged.AddListener(OnTrackedImagesChanged);
    }

    private void OnDisable()
    {
        if (trackedImageManager != null)
            trackedImageManager.trackablesChanged.RemoveListener(OnTrackedImagesChanged);
    }

    // ─────────────────────────────────────────────────────────────────────────
    // AR TRACKING
    // ─────────────────────────────────────────────────────────────────────────

    private void OnTrackedImagesChanged(ARTrackablesChangedEventArgs<ARTrackedImage> args)
    {
        foreach (var img in args.added)
            MemorizePosition(img);

        foreach (var img in args.updated)
            if (img.trackingState == TrackingState.Tracking)
                MemorizePosition(img);

        bool stillVisible = false;
        foreach (var img in trackedImageManager.trackables)
        {
            if (img.trackingState == TrackingState.Tracking)
            {
                stillVisible = true;
                break;
            }
        }
        _bookVisible = stillVisible;
    }

    private void MemorizePosition(ARTrackedImage trackedImage)
    {
        BookWorldPosition = trackedImage.transform.position;
        BookDetected = true;
        Debug.Log($"[FrameIndicator] 📖 Livre détecté → {BookWorldPosition}");
    }

    // ─────────────────────────────────────────────────────────────────────────
    // UPDATE
    // ─────────────────────────────────────────────────────────────────────────

    private void Update()
    {
        if (_iconRect == null) return;

        if (!BookDetected)
        {
            _iconRect.gameObject.SetActive(false);
            _foundMessageGO?.SetActive(false);
            _angleInitialized = false;
            _foundMessageShown = false;
            return;
        }

        UpdateScreenDirection();

        if (_bookVisible)
        {
            _iconRect.gameObject.SetActive(false);

            if (!_foundMessageShown)
            {
                _foundMessageShown = true;
                ShowFoundMessage();
            }
        }
        else
        {
            HideFoundMessage();
            _iconRect.gameObject.SetActive(true);
            MoveIconToEdge();
        }
    }

    // ─────────────────────────────────────────────────────────────────────────
    // DIRECTION
    // ─────────────────────────────────────────────────────────────────────────

    private void UpdateScreenDirection()
    {
        if (arCamera == null) return;
        Vector3 viewportPos = arCamera.WorldToViewportPoint(BookWorldPosition);
        Vector2 center = new Vector2(0.5f, 0.5f);
        _screenDirection = new Vector2(viewportPos.x - center.x, viewportPos.y - center.y);
    }

    // ─────────────────────────────────────────────────────────────────────────
    // ICÔNE DE BORD
    // ─────────────────────────────────────────────────────────────────────────

    private void MoveIconToEdge()
    {
        if (_screenDirection.magnitude < 0.001f) return;

        float halfW = _frameRect.rect.width * 0.5f;
        float halfH = _frameRect.rect.height * 0.5f;

        float targetAngle = Mathf.Atan2(_screenDirection.y, _screenDirection.x) * Mathf.Rad2Deg;

        if (!_angleInitialized)
        {
            _currentAngle = targetAngle;
            _angleInitialized = true;
        }

        _currentAngle = Mathf.MoveTowardsAngle(
            _currentAngle, targetAngle,
            iconRotationSpeed * Time.deltaTime
        );

        float rad = _currentAngle * Mathf.Deg2Rad;
        Vector2 dir = new Vector2(Mathf.Cos(rad), Mathf.Sin(rad));

        float scaleX = (dir.x != 0) ? halfW / Mathf.Abs(dir.x) : float.MaxValue;
        float scaleY = (dir.y != 0) ? halfH / Mathf.Abs(dir.y) : float.MaxValue;
        float scale = Mathf.Min(scaleX, scaleY);

        _iconRect.anchoredPosition = dir * scale;
        if (rotateIcon)
        {
            _iconRect.localEulerAngles = new Vector3(0f, 0f, _currentAngle - 90f);
        }
        else
        {
            _iconRect.localEulerAngles = Vector3.zero;
        }
    }

    // ─────────────────────────────────────────────────────────────────────────
    // FOUND MESSAGE
    // ─────────────────────────────────────────────────────────────────────────

    private void ShowFoundMessage()
    {
        if (_foundMessageGO == null) return;
        _foundMessageGO.SetActive(true);
        if (_foundMessageText != null)
            _foundMessageText.text = "📖 Livre Trouvé !";
        if (_messageCoroutine != null) StopCoroutine(_messageCoroutine);
        _messageCoroutine = StartCoroutine(AnimateFoundMessage());
    }

    private void HideFoundMessage()
    {
        if (_foundMessageGO != null && _foundMessageGO.activeSelf)
        {
            _foundMessageGO.SetActive(false);
            _foundMessageShown = false;
            if (_messageCoroutine != null) { StopCoroutine(_messageCoroutine); _messageCoroutine = null; }
        }
    }

    private IEnumerator AnimateFoundMessage()
    {
        RectTransform rt = _foundMessageGO.GetComponent<RectTransform>();
        rt.localScale = Vector3.zero;
        yield return ScaleTo(rt, 0f, 1.3f, 0.4f);
        yield return ScaleTo(rt, 1.3f, 0.9f, 0.25f);
        yield return ScaleTo(rt, 0.9f, 1f, 0.2f);
        rt.localScale = Vector3.one;
        StartCoroutine(FloatEffect(rt));
    }

    private IEnumerator ScaleTo(RectTransform rt, float from, float to, float duration)
    {
        float elapsed = 0f;
        while (elapsed < duration)
        {
            elapsed += Time.deltaTime;
            rt.localScale = Vector3.one * Mathf.Lerp(from, to, Mathf.SmoothStep(0f, 1f, elapsed / duration));
            yield return null;
        }
    }

    private IEnumerator FloatEffect(RectTransform rect)
    {
        Vector2 startPos = rect.anchoredPosition;
        while (_foundMessageGO != null && _foundMessageGO.activeSelf)
        {
            rect.anchoredPosition = startPos + new Vector2(0, Mathf.Sin(Time.time * 2f) * 10f);
            yield return null;
        }
    }

    // ─────────────────────────────────────────────────────────────────────────
    // BUILD UI
    // ─────────────────────────────────────────────────────────────────────────

    private void BuildUI()
    {
        // ── Canvas ──────────────────────────────────────────────────────────
        GameObject canvasGO = new GameObject("Canvas");
        canvasGO.transform.SetParent(transform);

        _canvas = canvasGO.AddComponent<Canvas>();
        _canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        _canvas.sortingOrder = 5;

        CanvasScaler scaler = canvasGO.AddComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1080, 1920);
        scaler.matchWidthOrHeight = 0.5f;

        canvasGO.AddComponent<GraphicRaycaster>();

        // ── FrameRect (stretch - offset 50 partout) ─────────────────────────
        GameObject frameGO = new GameObject("FrameRect");
        frameGO.transform.SetParent(canvasGO.transform, false);

        // Image invisible (juste pour le RectTransform)
        Image frameBg = frameGO.AddComponent<Image>();
        frameBg.color = new Color(0f, 0f, 0f, 0f);
        frameBg.raycastTarget = false;

        _frameRect = frameGO.GetComponent<RectTransform>();
        // Reproduit exactement : stretch, Left=50, Top=50, Right=50, Bottom=50
        _frameRect.anchorMin = Vector2.zero;
        _frameRect.anchorMax = Vector2.one;
        _frameRect.offsetMin = new Vector2(framePadding, framePadding);   // Left, Bottom
        _frameRect.offsetMax = new Vector2(-framePadding, -framePadding); // -Right, -Top

        // ── PlaceholderIcon (centre, 100x100) ───────────────────────────────
        GameObject iconGO = new GameObject("PlaceholderIcon");
        iconGO.transform.SetParent(frameGO.transform, false);

        _iconImage = iconGO.AddComponent<Image>();
        _iconImage.color = iconColor;
        _iconImage.type = Image.Type.Simple;
        _iconImage.raycastTarget = false;

        // ← Assigne le sprite depuis l'Inspector
        if (placeholderSprite != null)
            _iconImage.sprite = placeholderSprite;

        _iconRect = iconGO.GetComponent<RectTransform>();
        // Reproduit exactement : center middle, Pos X=0, Y=0, W=100, H=100
        _iconRect.anchorMin = new Vector2(0.5f, 0.5f);
        _iconRect.anchorMax = new Vector2(0.5f, 0.5f);
        _iconRect.pivot = new Vector2(0.5f, 0.5f);
        _iconRect.sizeDelta = new Vector2(iconSize, iconSize);
        _iconRect.anchoredPosition = Vector2.zero;
        _iconRect.gameObject.SetActive(false);

        // ── FoundMessage ────────────────────────────────────────────────────
        _foundMessageGO = new GameObject("FoundMessage");
        _foundMessageGO.transform.SetParent(canvasGO.transform, false);

        _foundMessageText = _foundMessageGO.AddComponent<TextMeshProUGUI>();
        _foundMessageText.text = "📖 Livre Trouvé !";
        _foundMessageText.fontSize = foundMessageFontSize;
        _foundMessageText.fontStyle = FontStyles.Bold;
        _foundMessageText.color = foundMessageColor;
        _foundMessageText.alignment = TextAlignmentOptions.Center;

        RectTransform msgRect = _foundMessageGO.GetComponent<RectTransform>();
        msgRect.anchorMin = new Vector2(0.5f, 0.5f);
        msgRect.anchorMax = new Vector2(0.5f, 0.5f);
        msgRect.pivot = new Vector2(0.5f, 0.5f);
        msgRect.sizeDelta = new Vector2(700f, 120f);
        msgRect.anchoredPosition = new Vector2(0f, -120f);

        _foundMessageGO.SetActive(false);
    }
}*/