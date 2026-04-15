using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.EnhancedTouch;
using Touch = UnityEngine.InputSystem.EnhancedTouch.Touch;

public class ARPrefabManager : MonoBehaviour
{
    [Header("Prefab Settings")]
    public GameObject prefabToSpawn;
    public float distanceFromCamera = 2f;
    public Vector3 spawnPosition = new Vector3(0f, 0f, 2f); // ← modifie X Y Z dans l'Inspector

    [Header("Cadre d'étoiles")]
    public int   starsPerSide = 4;
    public float frameWidth   = 0.3f;
    public float frameHeight  = 0.3f;
    public float starSize     = 0.03f;

    private GameObject       spawnedPrefab;
    private GameObject       closeButtonGO;
    private Camera           mainCamera;
    private StarFrameWorldUI _starFrame;

    // ─────────────────────────────────────────────
    void OnEnable()  => EnhancedTouchSupport.Enable();
    void OnDisable() => EnhancedTouchSupport.Disable();

    void Start()
    {
        mainCamera = Camera.main;
        SpawnPrefabAtCenter();
        CreateUI();
    }

    // ─────────────────────────────────────────────
    void SpawnPrefabAtCenter()
    {
        if (prefabToSpawn == null)
        {
            Debug.LogWarning("Aucun prefab assigné !");
            return;
        }

        spawnedPrefab = Instantiate(prefabToSpawn, spawnPosition, Quaternion.identity); // ← position fixe

        // ── Ajoute le cadre d'étoiles sur le prefab ──────────
        _starFrame              = spawnedPrefab.AddComponent<StarFrameWorldUI>();
        _starFrame.starsPerSide = starsPerSide;
        _starFrame.frameWidth   = frameWidth;
        _starFrame.frameHeight  = frameHeight;
        _starFrame.starSize     = starSize;

        // Lance l'affichage du cadre après 1 frame
        // (pour laisser Start() de StarFrameWorldUI s'exécuter)
        StartCoroutine(ShowFrameNextFrame());

        Debug.Log("✅ Prefab spawné à : " + spawnPosition);
    }

    System.Collections.IEnumerator ShowFrameNextFrame()
    {
        yield return null;
        if (_starFrame != null) _starFrame.ShowFrame();
    }

    // ─────────────────────────────────────────────
    void Update()
    {
        if (closeButtonGO == null || !closeButtonGO.activeSelf) return;

        if (Touch.activeTouches.Count > 0)
        {
            foreach (var touch in Touch.activeTouches)
                if (touch.phase == UnityEngine.InputSystem.TouchPhase.Began)
                    CheckRaycastHit(touch.screenPosition);
        }

        if (Mouse.current != null && Mouse.current.leftButton.wasPressedThisFrame)
            CheckRaycastHit(Mouse.current.position.ReadValue());
    }

    void CheckRaycastHit(Vector2 screenPos)
    {
        Ray ray = mainCamera.ScreenPointToRay(screenPos);
        RaycastHit[] hits = Physics.RaycastAll(ray, 100f);

        foreach (RaycastHit hit in hits)
        {
            if (hit.collider.gameObject == closeButtonGO)
            {
                OnCloseButtonPressed();
                return;
            }
        }

        RectTransform rect = closeButtonGO.GetComponent<RectTransform>();
        if (RectTransformUtility.RectangleContainsScreenPoint(rect, screenPos, null))
            OnCloseButtonPressed();
    }

    // ─────────────────────────────────────────────
    void CreateUI()
    {
        GameObject canvasGO   = new GameObject("UICanvas");
        Canvas canvas         = canvasGO.AddComponent<Canvas>();
        canvas.renderMode     = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder   = 999;

        CanvasScaler scaler        = canvasGO.AddComponent<CanvasScaler>();
        scaler.uiScaleMode         = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1080, 1920);
        scaler.matchWidthOrHeight  = 0.5f;
        canvasGO.AddComponent<GraphicRaycaster>();

        closeButtonGO = new GameObject("CloseButton");
        closeButtonGO.transform.SetParent(canvasGO.transform, false);

        Image btnImg  = closeButtonGO.AddComponent<Image>();
        btnImg.color  = new Color(1f, 0.2f, 0.2f, 0.9f);

        BoxCollider2D col = closeButtonGO.AddComponent<BoxCollider2D>();
        col.size          = new Vector2(120f, 120f);

        RectTransform rect    = closeButtonGO.GetComponent<RectTransform>();
        rect.sizeDelta        = new Vector2(120f, 120f);
        rect.anchorMin        = new Vector2(0.5f, 1f);
        rect.anchorMax        = new Vector2(0.5f, 1f);
        rect.pivot            = new Vector2(0.5f, 1f);
        rect.anchoredPosition = new Vector2(0f, -60f);

        GameObject textGO   = new GameObject("Label");
        textGO.transform.SetParent(closeButtonGO.transform, false);
        Text label          = textGO.AddComponent<Text>();
        label.text          = "✕";
        label.font          = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        label.fontSize      = 72;
        label.fontStyle     = FontStyle.Bold;
        label.color         = Color.white;
        label.alignment     = TextAnchor.MiddleCenter;
        label.raycastTarget = false;

        RectTransform labelRect = label.GetComponent<RectTransform>();
        labelRect.anchorMin     = Vector2.zero;
        labelRect.anchorMax     = Vector2.one;
        labelRect.offsetMin     = Vector2.zero;
        labelRect.offsetMax     = Vector2.zero;

        Debug.Log("✅ UI créée !");
    }

    // ─────────────────────────────────────────────
    void OnCloseButtonPressed()
    {
        if (spawnedPrefab != null)
        {
            Destroy(spawnedPrefab);
            spawnedPrefab = null;
            _starFrame    = null;
        }

        if (closeButtonGO != null)
            closeButtonGO.SetActive(false);

        Debug.Log("✅ Prefab et cadre supprimés !");
    }
}