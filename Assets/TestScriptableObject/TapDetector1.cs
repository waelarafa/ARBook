using UnityEngine;
using UnityEngine.XR.ARFoundation;

public class TapDetector1 : BaseTapDetector
{
    public bool           isSpawnedPrefab = false;
    public bool           isValidated     = false;
    public ARTrackedImage trackedImage    = null;

    protected override bool CanDrag()  => isSpawnedPrefab;
    protected override bool CanScale() => isSpawnedPrefab;

    // ─────────────────────────────────────────
    protected override void OnPressDown(Vector2 screenPosition)
    {
        if (CheckOverlayButtons(screenPosition)) return;
        if (IsTapOnUI(screenPosition))           return;
        if (!RaycastHitThis(screenPosition))     return;

        BeginPress(screenPosition);
        Debug.Log("👇 Appui : " + gameObject.name
                + (isSpawnedPrefab ? " [prefab]" : " [image AR]"));
    }

    // ─────────────────────────────────────────
    protected override void OnPressUp(Vector2 screenPosition)
    {
        if (!isPressing) return;
        float duration = Time.time - pressStartTime;
        isPressing     = false;

        if (isDragging)       { isDragging = false;RestoreScaleAfterDrag(); return; }
        if (longPressHandled) return;
        if (duration >= LongPressDuration) return;
        if (!RaycastHitThis(screenPosition)) return;

        if (isSpawnedPrefab)
        {
            Debug.Log("👆 Tap court prefab → son : " + gameObject.name);
            PlaySound();
        }
        else
        {
            if (!isValidated)
            {
                Debug.Log("🔒 Tap ignoré — image pas validée : " + gameObject.name);
                return;
            }
            Debug.Log("✅ Tap image AR → spawn : " + gameObject.name);
            HandleImageTap();
        }
    }

    // ─────────────────────────────────────────
    public void HandleImageTap()
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (data == null)               { Debug.LogWarning("⚠️ data NULL");          return; }
        if (!data.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");  return; }
        if (data.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL"); return; }

        Camera arCam = cam != null ? cam : Camera.main;
        if (arCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        _isSpawning = true;
        GameObject spawned = SpawnPrefab(data, arCam);
        _isSpawning = false;

        TapDetector1 tap    = spawned.AddComponent<TapDetector1>();
        tap.cam             = arCam;
        tap.data            = data;
        tap.isSpawnedPrefab = true;
        tap.isValidated     = true;

        _currentSpawned = spawned;

        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.HideAllCubes();
            Debug.Log("🙈 Cubes AR cachés");
        }

        AROverlayUI.Instance?.EnterPrefabMode(showPhoto: true);

        Debug.Log("🐾 Prefab AR spawné : " + spawned.name);
    }

    // ─────────────────────────────────────────
    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ Destroy AR : "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Destroy(_currentSpawned, delay);

        _currentSpawned = null;

        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.ShowAllCubes();
            Debug.Log("👁️ Cubes AR réaffichés");
        }

        AROverlayUI.Instance?.ExitPrefabMode();
        Debug.Log("🗑️ Prefab AR détruit + UI restaurée");
    }
}
/*modification 23:13 27/04
using UnityEngine;
using UnityEngine.XR.ARFoundation;

public class TapDetector1 : BaseTapDetector
{
    public bool           isSpawnedPrefab = false;
    public bool           isValidated     = false;
    public ARTrackedImage trackedImage    = null;

    // ── CanDrag et CanScale : autorisés seulement sur prefab spawné ──
    protected override bool CanDrag()  => isSpawnedPrefab;
    protected override bool CanScale() => isSpawnedPrefab;

    // ─────────────────────────────────────────
    protected override void OnPressDown(Vector2 screenPosition)
    {
        if (CheckOverlayButtons(screenPosition)) return;
        if (IsTapOnUI(screenPosition))           return;
        if (!RaycastHitThis(screenPosition))     return;

        BeginPress(screenPosition);
        Debug.Log("👇 Appui : " + gameObject.name
                + (isSpawnedPrefab ? " [prefab]" : " [image AR]"));
    }

    // ─────────────────────────────────────────
    protected override void OnPressUp(Vector2 screenPosition)
    {
        if (!isPressing) return;
        float duration = Time.time - pressStartTime;
        isPressing     = false;

        if (isDragging)       { isDragging = false; return; }
        if (longPressHandled) return;
        if (duration >= LongPressDuration) return;
        if (!RaycastHitThis(screenPosition)) return;

        if (isSpawnedPrefab)
        {
            Debug.Log("👆 Tap court prefab → son : " + gameObject.name);
            PlaySound();
        }
        else
        {
            if (!isValidated)
            {
                Debug.Log("🔒 Tap ignoré — image pas validée : " + gameObject.name);
                return;
            }
            Debug.Log("✅ Tap image AR → spawn : " + gameObject.name);
            HandleImageTap();
        }
    }

    // ─────────────────────────────────────────
    public void HandleImageTap()
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (data == null)               { Debug.LogWarning("⚠️ data NULL");          return; }
        if (!data.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");  return; }
        if (data.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL"); return; }

        Camera arCam = cam != null ? cam : Camera.main;
        if (arCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        _isSpawning = true;
        GameObject spawned = SpawnPrefab(data, arCam);
        _isSpawning = false;

        TapDetector1 tap    = spawned.AddComponent<TapDetector1>();
        tap.cam             = arCam;
        tap.data            = data;
        tap.isSpawnedPrefab = true;
        tap.isValidated     = true;

        _currentSpawned = spawned;

        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.HideAllCubes();
            Debug.Log("🙈 Cubes AR cachés");
        }

        // showPhoto = true car scène AR
        AROverlayUI.Instance?.SetCurrentData(data);
        AROverlayUI.Instance?.EnterPrefabMode(showPhoto: true);

        Debug.Log("🐾 Prefab AR spawné : " + spawned.name);
    }

    // ─────────────────────────────────────────
    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ Destroy AR : "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Destroy(_currentSpawned, delay);

        _currentSpawned = null;

        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.ShowAllCubes();
            Debug.Log("👁️ Cubes AR réaffichés");
        }

        AROverlayUI.Instance?.ExitPrefabMode();
        Debug.Log("🗑️ Prefab AR détruit + UI restaurée");
    }
}
/*
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using System.Collections;

public class TapDetector1 : BaseTapDetector
{
    public bool isSpawnedPrefab = false;
    public bool isValidated     = false;
    public ARTrackedImage trackedImage = null;

    private static GameObject _currentSpawned = null;
    private static bool       _isSpawning     = false;

    // ─────────────────────────────────────────
    protected override void OnPressDown(Vector2 screenPosition)
    {
        // 1. Overlay EN PREMIER
        if (CheckOverlayButtons(screenPosition)) return;

        // 2. UI Unity
        if (IsTapOnUI(screenPosition)) return;

        // 3. Raycast 3D
        if (!RaycastHitThis(screenPosition)) return;

        BeginPress(screenPosition);
        Debug.Log("👇 Appui sur : " + gameObject.name
                + (isSpawnedPrefab ? " [prefab]" : " [image]"));
    }

    // ─────────────────────────────────────────
    protected override void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            Debug.Log("↔️ Drag : " + gameObject.name);
        }

        // Drag seulement si prefab spawné
        if (isDragging && isSpawnedPrefab)
        {
            float   dist      = Vector3.Distance(
                cam.transform.position, transform.position);
            Vector3 screenPos = new Vector3(
                screenPosition.x, screenPosition.y, dist);
            transform.position = cam.ScreenToWorldPoint(screenPos);
        }

        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                if (isSpawnedPrefab)
                {
                    Debug.Log("⏱️ Appui long → scale : " + gameObject.name);
                    if (!isAnimating) StartCoroutine(ScaleEffect());
                }
            }
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────
    protected override void OnPressUp(Vector2 screenPosition)
    {
        if (!isPressing) return;
        float duration = Time.time - pressStartTime;
        isPressing     = false;

        if (isDragging)       { isDragging = false; return; }
        if (longPressHandled) return;
        if (duration >= LongPressDuration) return;

        if (!RaycastHitThis(screenPosition)) return;

        if (isSpawnedPrefab)
        {
            Debug.Log("👆 Tap court prefab → son : " + gameObject.name);
            PlaySound();
        }
        else
        {
            if (!isValidated)
            {
                Debug.Log("🔒 Tap ignoré : pas validée : " + gameObject.name);
                return;
            }
            Debug.Log("✅ Tap image → spawn : " + gameObject.name);
            HandleImageTap();
        }
    }

    // ─────────────────────────────────────────
    public void HandleImageTap()
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (data == null)               { Debug.LogWarning("⚠️ data NULL");          return; }
        if (!data.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");  return; }
        if (data.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL"); return; }

        Camera arCam = cam != null ? cam : Camera.main;
        if (arCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        _isSpawning = true;
        GameObject spawned = SpawnPrefab(data, arCam);
        _isSpawning = false;

        TapDetector1 tap    = spawned.AddComponent<TapDetector1>();
        tap.cam             = arCam;
        tap.data            = data;
        tap.isSpawnedPrefab = true;
        tap.isValidated     = true;

        _currentSpawned = spawned;

        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.HideAllCubes();
            Debug.Log("🙈 Cubes cachés après spawn");
        }

        AROverlayUI.Instance?.SetCurrentData(data);
        AROverlayUI.Instance?.EnterPrefabMode();

        Debug.Log("🐾 Spawné : " + spawned.name
                + " | pos="   + spawned.transform.position
                + " | scale=" + spawned.transform.localScale);
    }

    // ─────────────────────────────────────────
    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ DestroyCurrentPrefab : "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Destroy(_currentSpawned, delay);

        _currentSpawned = null;

        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.ShowAllCubes();
            Debug.Log("👁️ Cubes réaffichés");
        }

        AROverlayUI.Instance?.ExitPrefabMode();
        Debug.Log("🗑️ Prefab détruit + UI restaurée");
    }
}
/*derniere version qui marche bien apres lajout de 3d scene 
using UnityEngine;
using UnityEngine.InputSystem;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.EventSystems;

public class TapDetector1 : MonoBehaviour
{
    public Camera cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    public bool isSpawnedPrefab = false;
    public bool isValidated     = false;

    public ARTrackedImage trackedImage = null;

    private const float LongPressDuration = 0.5f;
    private const float DragThreshold     = 10f;

    private const float SpawnHeightAboveImage = 0.05f;
    private const float TiltTowardCamera      = 15f;

    private bool        isAnimating    = false;
    private AudioSource audioSource;

    private bool    isPressing       = false;
    private float   pressStartTime   = 0f;
    private bool    longPressHandled = false;
    private Vector2 pressStartPos    = Vector2.zero;
    private Vector2 lastDragPos      = Vector2.zero;
    private bool    isDragging       = false;

    private static GameObject _currentSpawned = null;
    private static bool       _isSpawning     = false;

    // ─────────────────────────────────────────────────────────────
    void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    // ─────────────────────────────────────────────────────────────
    void Update()
    {
#if UNITY_EDITOR
        if (Mouse.current == null) return;
        Vector2 pos = Mouse.current.position.ReadValue();
        if      (Mouse.current.leftButton.wasPressedThisFrame)     OnPressDown(pos);
        else if (Mouse.current.leftButton.wasReleasedThisFrame)    OnPressUp(pos);
        else if (Mouse.current.leftButton.isPressed && isPressing) OnPressMoved(pos);
#else
        if (Touchscreen.current == null) return;
        var touch = Touchscreen.current.primaryTouch;
        Vector2 pos = touch.position.ReadValue();
        if      (touch.press.wasPressedThisFrame)                  OnPressDown(pos);
        else if (touch.press.wasReleasedThisFrame)                 OnPressUp(pos);
        else if (touch.press.isPressed && isPressing)              OnPressMoved(pos);
#endif
    }

    // ─────────────────────────────────────────────────────────────
    private bool IsTapOnUI(Vector2 screenPosition)
    {
        if (EventSystem.current == null) return false;

        PointerEventData pointer = new PointerEventData(EventSystem.current)
        {
            position = screenPosition
        };

        List<RaycastResult> results = new List<RaycastResult>();
        EventSystem.current.RaycastAll(pointer, results);

        if (results.Count > 0)
        {
            Debug.Log("🖱️ Tap sur UI : " + results[0].gameObject.name
                    + " — TapDetector1 ignoré");
            return true;
        }

        return false;
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressDown(Vector2 screenPosition)
    {
        // ── 1. Boutons de langue EN PREMIER ───────────────────────
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnLanguageButton(screenPosition))
        {
            Debug.Log("🌐 Tap sur bouton de langue détecté");
            return;
        }

        // ── 2. Bouton Fermer ───────────────────────────────────────
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnCloseButton(screenPosition))
        {
            Debug.Log("🔴 Tap sur bouton Fermer détecté");
            AROverlayUI.Instance.OnFermerPressed();
            return;
        }

        // ── 3. Bouton Photo ────────────────────────────────────────
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnPhotoButton(screenPosition))
        {
            Debug.Log("📷 Tap sur bouton Photo détecté");
            return;
        }

        // ── 4. Tap sur UI Unity ────────────────────────────────────
        if (IsTapOnUI(screenPosition)) return;

        // ── 5. Logique normale ─────────────────────────────────────
        if (cam == null) return;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return;
        if (hit.collider.gameObject != gameObject) return;

        isPressing       = true;
        pressStartTime   = Time.time;
        pressStartPos    = screenPosition;
        lastDragPos      = screenPosition;
        longPressHandled = false;
        isDragging       = false;

        Debug.Log("👇 Appui sur : " + gameObject.name
                + (isSpawnedPrefab ? " [prefab]" : " [image]"));
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            Debug.Log("↔️ Drag sur : " + gameObject.name);
        }

        if (isDragging && isSpawnedPrefab)
        {
            float distanceFromCamera = Vector3.Distance(
                cam.transform.position, transform.position);
            Vector3 screenPos  = new Vector3(
                screenPosition.x, screenPosition.y, distanceFromCamera);
            Vector3 worldPos   = cam.ScreenToWorldPoint(screenPos);
            transform.position = worldPos;
        }

        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                if (isSpawnedPrefab)
                {
                    Debug.Log("⏱️ Appui long → scale : " + gameObject.name);
                    if (!isAnimating) StartCoroutine(ScaleEffect());
                }
            }
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressUp(Vector2 screenPosition)
    {
        if (!isPressing) return;
        float duration = Time.time - pressStartTime;
        isPressing = false;

        if (isDragging) { isDragging = false; return; }
        if (longPressHandled) return;
        if (duration >= LongPressDuration) return;

        if (cam == null) return;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return;
        if (hit.collider.gameObject != gameObject) return;

        if (isSpawnedPrefab)
        {
            Debug.Log("👆 Tap court prefab → son : " + gameObject.name);
            PlaySound();
        }
        else
        {
            if (!isValidated)
            {
                Debug.Log("🔒 Tap ignoré : pas validée : " + gameObject.name);
                return;
            }
            Debug.Log("✅ Tap image → spawn : " + gameObject.name);
            HandleImageTap();
        }
    }

    // ─────────────────────────────────────────────────────────────
    public void HandleImageTap()
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (data == null)               { Debug.LogWarning("⚠️ data NULL");           return; }
        if (!data.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");   return; }
        if (data.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL");  return; }

        Camera arCam = cam != null ? cam : Camera.main;
        if (arCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        float   distanceFromCamera = 0.5f;
        Vector3 screenCenter       = new Vector3(
            Screen.width / 2f, Screen.height / 2f, distanceFromCamera);
        Vector3 spawnPosition      = arCam.ScreenToWorldPoint(screenCenter);

        Vector3 dirToCamera = arCam.transform.position - spawnPosition;
        dirToCamera.y       = 0f;
        if (dirToCamera == Vector3.zero) dirToCamera = arCam.transform.forward;
        Quaternion lookAtCam     = Quaternion.LookRotation(dirToCamera);
        Quaternion tilt          = Quaternion.Euler(-TiltTowardCamera, 0f, 0f);
        Quaternion spawnRotation = lookAtCam * tilt;

        _isSpawning = true;
        GameObject spawned = Instantiate(data.prefabToSpawn, spawnPosition, spawnRotation);
        _isSpawning = false;

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = data.prefabToSpawn.transform.localScale;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        TapDetector1 tap    = spawned.AddComponent<TapDetector1>();
        tap.cam             = arCam;
        tap.data            = data;
        tap.isSpawnedPrefab = true;
        tap.isValidated     = true;

        _currentSpawned = spawned;

        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.HideAllCubes();
            Debug.Log("🙈 [TAP] Cubes cachés après spawn prefab");
        }
        else
        {
            Debug.LogWarning("⚠️ [TAP] ARImageCubeOverlay introuvable");
        }

        AROverlayUI.Instance?.SetCurrentData(data);
        AROverlayUI.Instance?.EnterPrefabMode();

        Debug.Log("🐾 Animal spawné"
                + " | pos="   + spawned.transform.position
                + " | rot="   + spawned.transform.eulerAngles
                + " | scale=" + spawned.transform.localScale);
    }

    // ─────────────────────────────────────────────────────────────
    void PlaySound()
    {
        if (data == null) return;
        if (data.doPlaySound && data.soundConfig != null
                             && data.soundConfig.clip != null)
        {
            if (AudioManager.Instance != null)
            {
                AudioManager.Instance.Play(data.soundConfig);
                Debug.Log("🔊 AudioManager : " + data.soundConfig.clip.name);
            }
            else
            {
                audioSource.clip   = data.soundConfig.clip;
                audioSource.volume = data.soundConfig.volume;
                audioSource.Play();
                Debug.Log("🔊 Fallback : " + data.soundConfig.clip.name);
            }
        }
        else
        {
            Debug.LogWarning("⚠️ Son absent — doPlaySound=" + data.doPlaySound
                + " | soundConfig=" + data.soundConfig
                + " | clip=" + (data.soundConfig != null
                    ? data.soundConfig.clip : null));
        }
    }

    // ─────────────────────────────────────────────────────────────
    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ DestroyCurrentPrefab | prefab = "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Destroy(_currentSpawned, delay);

        _currentSpawned = null;

        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.ShowAllCubes();
            Debug.Log("👁️ [DESTROY] Cubes réaffichés");
        }
        else
        {
            Debug.LogWarning("⚠️ [DESTROY] ARImageCubeOverlay introuvable");
        }

        AROverlayUI.Instance?.ExitPrefabMode();
        Debug.Log("🗑️ Prefab détruit + UI restaurée");
    }

    // ─────────────────────────────────────────────────────────────
    IEnumerator ScaleEffect()
    {
        if (data == null) { isAnimating = false; yield break; }

        isAnimating      = true;
        Vector3 original = transform.localScale;
        Vector3 target   = original * data.scaleMultiplier;
        float   time     = 0f;

        while (time < data.scaleDuration)
        {
            transform.localScale = Vector3.Lerp(
                original, target, time / data.scaleDuration);
            time += Time.deltaTime;
            yield return null;
        }

        transform.localScale = target;
        time = 0f;

        while (time < data.scaleDuration)
        {
            transform.localScale = Vector3.Lerp(
                target, original, time / data.scaleDuration);
            time += Time.deltaTime;
            yield return null;
        }

        transform.localScale = original;
        isAnimating          = false;
    }
}
/*
//ajout d'un quiz sur tel version correcte
using UnityEngine;
using UnityEngine.InputSystem;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.EventSystems;

public class TapDetector1 : MonoBehaviour
{
    public Camera cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    public bool isSpawnedPrefab = false;
    public bool isValidated     = false;

    public ARTrackedImage trackedImage = null;

    private const float LongPressDuration = 0.5f;
    private const float DragThreshold     = 10f;

    private const float SpawnHeightAboveImage = 0.05f;
    private const float TiltTowardCamera      = 15f;

    private bool        isAnimating    = false;
    private AudioSource audioSource;

    private bool    isPressing       = false;
    private float   pressStartTime   = 0f;
    private bool    longPressHandled = false;
    private Vector2 pressStartPos    = Vector2.zero;
    private Vector2 lastDragPos      = Vector2.zero;
    private bool    isDragging       = false;

    private static GameObject _currentSpawned = null;
    private static bool       _isSpawning     = false;

    // ─────────────────────────────────────────────────────────────
    void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    // ─────────────────────────────────────────────────────────────
    void Update()
    {
#if UNITY_EDITOR
        if (Mouse.current == null) return;
        Vector2 pos = Mouse.current.position.ReadValue();
        if      (Mouse.current.leftButton.wasPressedThisFrame)     OnPressDown(pos);
        else if (Mouse.current.leftButton.wasReleasedThisFrame)    OnPressUp(pos);
        else if (Mouse.current.leftButton.isPressed && isPressing) OnPressMoved(pos);
#else
        if (Touchscreen.current == null) return;
        var touch = Touchscreen.current.primaryTouch;
        Vector2 pos = touch.position.ReadValue();
        if      (touch.press.wasPressedThisFrame)                  OnPressDown(pos);
        else if (touch.press.wasReleasedThisFrame)                 OnPressUp(pos);
        else if (touch.press.isPressed && isPressing)              OnPressMoved(pos);
#endif
    }

    // ─────────────────────────────────────────────────────────────
    private bool IsTapOnUI(Vector2 screenPosition)
    {
        if (EventSystem.current == null) return false;

        PointerEventData pointer = new PointerEventData(EventSystem.current)
        {
            position = screenPosition
        };

        List<RaycastResult> results = new List<RaycastResult>();
        EventSystem.current.RaycastAll(pointer, results);

        if (results.Count > 0)
        {
            Debug.Log("🖱️ Tap sur UI : " + results[0].gameObject.name + " — TapDetector1 ignoré");
            return true;
        }

        return false;
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressDown(Vector2 screenPosition)
    {
        // ── 0. Si tap sur un élément UI, laisser Unity gérer ─────
        if (IsTapOnUI(screenPosition)) return;

        // ── 1. Vérifier les boutons de langue EN PREMIER ──────────
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnLanguageButton(screenPosition))
        {
            Debug.Log("🌐 Tap sur bouton de langue détecté");
            return;
        }

        // ── 2. Vérifier le bouton Photo ───────────────────────────
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnPhotoButton(screenPosition))
        {
            Debug.Log("📷 Tap sur bouton Photo détecté");
            return;
        }

        // ── 3. Vérifier le bouton Fermer ──────────────────────────
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnCloseButton(screenPosition))
        {
            Debug.Log("🔴 Tap sur bouton Fermer détecté");
            AROverlayUI.Instance.OnFermerPressed();
            return;
        }

        // ── 4. Logique normale ────────────────────────────────────
        if (cam == null) return;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return;
        if (hit.collider.gameObject != gameObject) return;

        isPressing       = true;
        pressStartTime   = Time.time;
        pressStartPos    = screenPosition;
        lastDragPos      = screenPosition;
        longPressHandled = false;
        isDragging       = false;

        Debug.Log("👇 Appui sur : " + gameObject.name
                + (isSpawnedPrefab ? " [prefab]" : " [image]"));
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            Debug.Log("↔️ Drag sur : " + gameObject.name);
        }

        if (isDragging && isSpawnedPrefab)
        {
            float distanceFromCamera = Vector3.Distance(cam.transform.position, transform.position);
            Vector3 screenPos = new Vector3(screenPosition.x, screenPosition.y, distanceFromCamera);
            Vector3 worldPos  = cam.ScreenToWorldPoint(screenPos);
            transform.position = worldPos;
        }

        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                if (isSpawnedPrefab)
                {
                    Debug.Log("⏱️ Appui long → scale : " + gameObject.name);
                    if (!isAnimating) StartCoroutine(ScaleEffect());
                }
            }
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressUp(Vector2 screenPosition)
    {
        if (!isPressing) return;
        float duration = Time.time - pressStartTime;
        isPressing = false;

        if (isDragging) { isDragging = false; return; }
        if (longPressHandled) return;
        if (duration >= LongPressDuration) return;

        if (cam == null) return;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return;
        if (hit.collider.gameObject != gameObject) return;

        if (isSpawnedPrefab)
        {
            Debug.Log("👆 Tap court prefab → son : " + gameObject.name);
            PlaySound();
        }
        else
        {
            if (!isValidated)
            {
                Debug.Log("🔒 Tap ignoré : pas validée : " + gameObject.name);
                return;
            }
            Debug.Log("✅ Tap image → spawn : " + gameObject.name);
            HandleImageTap();
        }
    }

    // ─────────────────────────────────────────────────────────────
    public void HandleImageTap()
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (data == null)               { Debug.LogWarning("⚠️ data NULL");           return; }
        if (!data.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");   return; }
        if (data.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL");  return; }

        Camera arCam = cam != null ? cam : Camera.main;
        if (arCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        float distanceFromCamera = 0.5f;
        Vector3 screenCenter  = new Vector3(Screen.width / 2f, Screen.height / 2f, distanceFromCamera);
        Vector3 spawnPosition = arCam.ScreenToWorldPoint(screenCenter);

        Vector3 dirToCamera = arCam.transform.position - spawnPosition;
        dirToCamera.y = 0f;
        if (dirToCamera == Vector3.zero) dirToCamera = arCam.transform.forward;
        Quaternion lookAtCam     = Quaternion.LookRotation(dirToCamera);
        Quaternion tilt          = Quaternion.Euler(-TiltTowardCamera, 0f, 0f);
        Quaternion spawnRotation = lookAtCam * tilt;

        _isSpawning = true;
        GameObject spawned = Instantiate(data.prefabToSpawn, spawnPosition, spawnRotation);
        _isSpawning = false;

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = data.prefabToSpawn.transform.localScale;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        TapDetector1 tap    = spawned.AddComponent<TapDetector1>();
        tap.cam             = arCam;
        tap.data            = data;
        tap.isSpawnedPrefab = true;
        tap.isValidated     = true;

        _currentSpawned = spawned;

        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.HideAllCubes();
            Debug.Log("🙈 [TAP] Cubes cachés après spawn prefab");
        }
        else
        {
            Debug.LogWarning("⚠️ [TAP] ARImageCubeOverlay introuvable — cubes non cachés");
        }

        AROverlayUI.Instance?.SetCurrentData(data);
        AROverlayUI.Instance?.EnterPrefabMode();

        Debug.Log("🐾 Animal spawné au centre de l'écran"
                + " | pos=" + spawned.transform.position
                + " | rot=" + spawned.transform.eulerAngles
                + " | scale=" + spawned.transform.localScale);
    }

    // ─────────────────────────────────────────────────────────────
    void PlaySound()
    {
        if (data == null) return;
        if (data.doPlaySound && data.soundConfig != null && data.soundConfig.clip != null)
        {
            if (AudioManager.Instance != null)
            {
                AudioManager.Instance.Play(data.soundConfig);
                Debug.Log("🔊 AudioManager : " + data.soundConfig.clip.name);
            }
            else
            {
                audioSource.clip   = data.soundConfig.clip;
                audioSource.volume = data.soundConfig.volume;
                audioSource.Play();
                Debug.Log("🔊 Fallback : " + data.soundConfig.clip.name);
            }
        }
        else
        {
            Debug.LogWarning("⚠️ Son absent — doPlaySound=" + data.doPlaySound
                + " | soundConfig=" + data.soundConfig
                + " | clip=" + (data.soundConfig != null ? data.soundConfig.clip : null));
        }
    }

    // ─────────────────────────────────────────────────────────────
    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ DestroyCurrentPrefab | prefab = "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Destroy(_currentSpawned, delay);

        _currentSpawned = null;

        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.ShowAllCubes();
            Debug.Log("👁️ [DESTROY] Cubes réaffichés après fermeture prefab");
        }
        else
        {
            Debug.LogWarning("⚠️ [DESTROY] ARImageCubeOverlay introuvable — cubes non réaffichés");
        }

        AROverlayUI.Instance?.ExitPrefabMode();
        Debug.Log("🗑️ Prefab détruit + UI restaurée");
    }

    // ─────────────────────────────────────────────────────────────
    IEnumerator ScaleEffect()
    {
        if (data == null) { isAnimating = false; yield break; }

        isAnimating = true;
        Vector3 original = transform.localScale;
        Vector3 target   = original * data.scaleMultiplier;
        float   time     = 0f;

        while (time < data.scaleDuration)
        {
            transform.localScale = Vector3.Lerp(original, target, time / data.scaleDuration);
            time += Time.deltaTime;
            yield return null;
        }
        transform.localScale = target;
        time = 0f;

        while (time < data.scaleDuration)
        {
            transform.localScale = Vector3.Lerp(target, original, time / data.scaleDuration);
            time += Time.deltaTime;
            yield return null;
        }

        transform.localScale = original;
        isAnimating          = false;
    }
}
/*ajout de photo taken
// TapDetector1.cs
using UnityEngine;
using UnityEngine.InputSystem;
using System.Collections;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;

public class TapDetector1 : MonoBehaviour
{
    public Camera cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    public bool isSpawnedPrefab = false;
    public bool isValidated     = false;

    public ARTrackedImage trackedImage = null;

    private const float LongPressDuration = 0.5f;
    private const float DragThreshold     = 10f;

    private const float SpawnHeightAboveImage = 0.05f;
    private const float TiltTowardCamera      = 15f;

    private bool        isAnimating    = false;
    private AudioSource audioSource;

    private bool    isPressing       = false;
    private float   pressStartTime   = 0f;
    private bool    longPressHandled = false;
    private Vector2 pressStartPos    = Vector2.zero;
    private Vector2 lastDragPos      = Vector2.zero;
    private bool    isDragging       = false;

    private static GameObject _currentSpawned = null;
    private static bool       _isSpawning     = false;

    // ─────────────────────────────────────────────────────────────
    void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    // ─────────────────────────────────────────────────────────────
    void Update()
    {
#if UNITY_EDITOR
        if (Mouse.current == null) return;
        Vector2 pos = Mouse.current.position.ReadValue();
        if      (Mouse.current.leftButton.wasPressedThisFrame)     OnPressDown(pos);
        else if (Mouse.current.leftButton.wasReleasedThisFrame)    OnPressUp(pos);
        else if (Mouse.current.leftButton.isPressed && isPressing) OnPressMoved(pos);
#else
        if (Touchscreen.current == null) return;
        var touch = Touchscreen.current.primaryTouch;
        Vector2 pos = touch.position.ReadValue();
        if      (touch.press.wasPressedThisFrame)                  OnPressDown(pos);
        else if (touch.press.wasReleasedThisFrame)                 OnPressUp(pos);
        else if (touch.press.isPressed && isPressing)              OnPressMoved(pos);
#endif
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressDown(Vector2 screenPosition)
    {
        // ── 1. Vérifier les boutons de langue EN PREMIER ──────────
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnLanguageButton(screenPosition))
        {
            Debug.Log("🌐 Tap sur bouton de langue détecté");
            return;
        }

        // ── 2. NOUVEAU : Vérifier le bouton Photo ─────────────────
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnPhotoButton(screenPosition))
        {
            Debug.Log("📷 Tap sur bouton Photo détecté");
            return;
        }

        // ── 3. Vérifier le bouton Fermer ──────────────────────────
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnCloseButton(screenPosition))
        {
            Debug.Log("🔴 Tap sur bouton Fermer détecté");
            AROverlayUI.Instance.OnFermerPressed();
            return;
        }

        // ── 4. Logique normale ────────────────────────────────────
        if (cam == null) return;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return;
        if (hit.collider.gameObject != gameObject) return;

        isPressing       = true;
        pressStartTime   = Time.time;
        pressStartPos    = screenPosition;
        lastDragPos      = screenPosition;
        longPressHandled = false;
        isDragging       = false;

        Debug.Log("👇 Appui sur : " + gameObject.name
                + (isSpawnedPrefab ? " [prefab]" : " [image]"));
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            Debug.Log("↔️ Drag sur : " + gameObject.name);
        }

        if (isDragging && isSpawnedPrefab)
        {
            float distanceFromCamera = Vector3.Distance(cam.transform.position, transform.position);
            Vector3 screenPos = new Vector3(screenPosition.x, screenPosition.y, distanceFromCamera);
            Vector3 worldPos  = cam.ScreenToWorldPoint(screenPos);
            transform.position = worldPos;
        }

        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                if (isSpawnedPrefab)
                {
                    Debug.Log("⏱️ Appui long → scale : " + gameObject.name);
                    if (!isAnimating) StartCoroutine(ScaleEffect());
                }
            }
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressUp(Vector2 screenPosition)
    {
        if (!isPressing) return;
        float duration = Time.time - pressStartTime;
        isPressing = false;

        if (isDragging) { isDragging = false; return; }
        if (longPressHandled) return;
        if (duration >= LongPressDuration) return;

        if (cam == null) return;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return;
        if (hit.collider.gameObject != gameObject) return;

        if (isSpawnedPrefab)
        {
            Debug.Log("👆 Tap court prefab → son : " + gameObject.name);
            PlaySound();
        }
        else
        {
            if (!isValidated)
            {
                Debug.Log("🔒 Tap ignoré : pas validée : " + gameObject.name);
                return;
            }
            Debug.Log("✅ Tap image → spawn : " + gameObject.name);
            HandleImageTap();
        }
    }

    // ─────────────────────────────────────────────────────────────
    public void HandleImageTap()
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (data == null)               { Debug.LogWarning("⚠️ data NULL");           return; }
        if (!data.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");   return; }
        if (data.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL");  return; }

        Camera arCam = cam != null ? cam : Camera.main;
        if (arCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        float distanceFromCamera = 0.5f;
        Vector3 screenCenter  = new Vector3(Screen.width / 2f, Screen.height / 2f, distanceFromCamera);
        Vector3 spawnPosition = arCam.ScreenToWorldPoint(screenCenter);

        Vector3 dirToCamera = arCam.transform.position - spawnPosition;
        dirToCamera.y = 0f;
        if (dirToCamera == Vector3.zero) dirToCamera = arCam.transform.forward;
        Quaternion lookAtCam     = Quaternion.LookRotation(dirToCamera);
        Quaternion tilt          = Quaternion.Euler(-TiltTowardCamera, 0f, 0f);
        Quaternion spawnRotation = lookAtCam * tilt;

        _isSpawning = true;
        GameObject spawned = Instantiate(data.prefabToSpawn, spawnPosition, spawnRotation);
        _isSpawning = false;

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = data.prefabToSpawn.transform.localScale;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        TapDetector1 tap    = spawned.AddComponent<TapDetector1>();
        tap.cam             = arCam;
        tap.data            = data;
        tap.isSpawnedPrefab = true;
        tap.isValidated     = true;

        _currentSpawned = spawned;

        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.HideAllCubes();
            Debug.Log("🙈 [TAP] Cubes cachés après spawn prefab");
        }
        else
        {
            Debug.LogWarning("⚠️ [TAP] ARImageCubeOverlay introuvable — cubes non cachés");
        }

        AROverlayUI.Instance?.SetCurrentData(data);
        AROverlayUI.Instance?.EnterPrefabMode();

        Debug.Log("🐾 Animal spawné au centre de l'écran"
                + " | pos=" + spawned.transform.position
                + " | rot=" + spawned.transform.eulerAngles
                + " | scale=" + spawned.transform.localScale);
    }

    // ─────────────────────────────────────────────────────────────
    void PlaySound()
    {
        if (data == null) return;
        if (data.doPlaySound && data.soundConfig != null && data.soundConfig.clip != null)
        {
            if (AudioManager.Instance != null)
            {
                AudioManager.Instance.Play(data.soundConfig);
                Debug.Log("🔊 AudioManager : " + data.soundConfig.clip.name);
            }
            else
            {
                audioSource.clip   = data.soundConfig.clip;
                audioSource.volume = data.soundConfig.volume;
                audioSource.Play();
                Debug.Log("🔊 Fallback : " + data.soundConfig.clip.name);
            }
        }
        else
        {
            Debug.LogWarning("⚠️ Son absent — doPlaySound=" + data.doPlaySound
                + " | soundConfig=" + data.soundConfig
                + " | clip=" + (data.soundConfig != null ? data.soundConfig.clip : null));
        }
    }

    // ─────────────────────────────────────────────────────────────
    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ DestroyCurrentPrefab | prefab = "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Destroy(_currentSpawned, delay);

        _currentSpawned = null;

        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.ShowAllCubes();
            Debug.Log("👁️ [DESTROY] Cubes réaffichés après fermeture prefab");
        }
        else
        {
            Debug.LogWarning("⚠️ [DESTROY] ARImageCubeOverlay introuvable — cubes non réaffichés");
        }

        AROverlayUI.Instance?.ExitPrefabMode();
        Debug.Log("🗑️ Prefab détruit + UI restaurée");
    }

    // ─────────────────────────────────────────────────────────────
    IEnumerator ScaleEffect()
    {
        if (data == null) { isAnimating = false; yield break; }

        isAnimating = true;
        Vector3 original = transform.localScale;
        Vector3 target   = original * data.scaleMultiplier;
        float   time     = 0f;

        while (time < data.scaleDuration)
        {
            transform.localScale = Vector3.Lerp(original, target, time / data.scaleDuration);
            time += Time.deltaTime;
            yield return null;
        }
        transform.localScale = target;
        time = 0f;

        while (time < data.scaleDuration)
        {
            transform.localScale = Vector3.Lerp(target, original, time / data.scaleDuration);
            time += Time.deltaTime;
            yield return null;
        }

        transform.localScale = original;
        isAnimating          = false;
    }
}
/*ajout de la langue 
// TapDetector1.cs
using UnityEngine;
using UnityEngine.InputSystem;
using System.Collections;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;

public class TapDetector1 : MonoBehaviour
{
    public Camera cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    public bool isSpawnedPrefab = false;
    public bool isValidated     = false;

    public ARTrackedImage trackedImage = null;

    private const float LongPressDuration = 0.5f;
    private const float DragThreshold     = 10f;

    private const float SpawnHeightAboveImage = 0.05f;
    private const float TiltTowardCamera      = 15f;

    private bool        isAnimating    = false;
    private AudioSource audioSource;

    private bool    isPressing       = false;
    private float   pressStartTime   = 0f;
    private bool    longPressHandled = false;
    private Vector2 pressStartPos    = Vector2.zero;
    private Vector2 lastDragPos      = Vector2.zero;
    private bool    isDragging       = false;

    private static GameObject _currentSpawned = null;
    private static bool       _isSpawning     = false;

    // ─────────────────────────────────────────────────────────────
    void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    // ─────────────────────────────────────────────────────────────
    void Update()
    {
#if UNITY_EDITOR
        if (Mouse.current == null) return;
        Vector2 pos = Mouse.current.position.ReadValue();
        if      (Mouse.current.leftButton.wasPressedThisFrame)     OnPressDown(pos);
        else if (Mouse.current.leftButton.wasReleasedThisFrame)    OnPressUp(pos);
        else if (Mouse.current.leftButton.isPressed && isPressing) OnPressMoved(pos);
#else
        if (Touchscreen.current == null) return;
        var touch = Touchscreen.current.primaryTouch;
        Vector2 pos = touch.position.ReadValue();
        if      (touch.press.wasPressedThisFrame)                  OnPressDown(pos);
        else if (touch.press.wasReleasedThisFrame)                 OnPressUp(pos);
        else if (touch.press.isPressed && isPressing)              OnPressMoved(pos);
#endif
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressDown(Vector2 screenPosition)
    {
        // ── 1. Vérifier les boutons de langue EN PREMIER ──────────
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnLanguageButton(screenPosition))
        {
            Debug.Log("🌐 Tap sur bouton de langue détecté");
            return; // son joué dans AROverlayUI, on arrête ici
        }

        // ── 2. Vérifier le bouton Fermer ──────────────────────────
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnCloseButton(screenPosition))
        {
            Debug.Log("🔴 Tap sur bouton Fermer détecté");
            AROverlayUI.Instance.OnFermerPressed();
            return;
        }

        // ── 3. Logique normale ────────────────────────────────────
        if (cam == null) return;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return;
        if (hit.collider.gameObject != gameObject) return;

        isPressing       = true;
        pressStartTime   = Time.time;
        pressStartPos    = screenPosition;
        lastDragPos      = screenPosition;
        longPressHandled = false;
        isDragging       = false;

        Debug.Log("👇 Appui sur : " + gameObject.name
                + (isSpawnedPrefab ? " [prefab]" : " [image]"));
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            Debug.Log("↔️ Drag sur : " + gameObject.name);
        }

        if (isDragging && isSpawnedPrefab)
        {
            float distanceFromCamera = Vector3.Distance(cam.transform.position, transform.position);
            Vector3 screenPos = new Vector3(screenPosition.x, screenPosition.y, distanceFromCamera);
            Vector3 worldPos  = cam.ScreenToWorldPoint(screenPos);
            transform.position = worldPos;
        }

        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                if (isSpawnedPrefab)
                {
                    Debug.Log("⏱️ Appui long → scale : " + gameObject.name);
                    if (!isAnimating) StartCoroutine(ScaleEffect());
                }
            }
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressUp(Vector2 screenPosition)
    {
        if (!isPressing) return;
        float duration = Time.time - pressStartTime;
        isPressing = false;

        if (isDragging) { isDragging = false; return; }
        if (longPressHandled) return;
        if (duration >= LongPressDuration) return;

        if (cam == null) return;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return;
        if (hit.collider.gameObject != gameObject) return;

        if (isSpawnedPrefab)
        {
            Debug.Log("👆 Tap court prefab → son : " + gameObject.name);
            PlaySound();
        }
        else
        {
            if (!isValidated)
            {
                Debug.Log("🔒 Tap ignoré : pas validée : " + gameObject.name);
                return;
            }
            Debug.Log("✅ Tap image → spawn : " + gameObject.name);
            HandleImageTap();
        }
    }

    // ─────────────────────────────────────────────────────────────
    public void HandleImageTap()
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (data == null)               { Debug.LogWarning("⚠️ data NULL");           return; }
        if (!data.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");   return; }
        if (data.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL");  return; }

        Camera arCam = cam != null ? cam : Camera.main;
        if (arCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        float distanceFromCamera = 0.5f;
        Vector3 screenCenter  = new Vector3(Screen.width / 2f, Screen.height / 2f, distanceFromCamera);
        Vector3 spawnPosition = arCam.ScreenToWorldPoint(screenCenter);

        Vector3 dirToCamera = arCam.transform.position - spawnPosition;
        dirToCamera.y = 0f;
        if (dirToCamera == Vector3.zero) dirToCamera = arCam.transform.forward;
        Quaternion lookAtCam     = Quaternion.LookRotation(dirToCamera);
        Quaternion tilt          = Quaternion.Euler(-TiltTowardCamera, 0f, 0f);
        Quaternion spawnRotation = lookAtCam * tilt;

        _isSpawning = true;
        GameObject spawned = Instantiate(data.prefabToSpawn, spawnPosition, spawnRotation);
        _isSpawning = false;

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = data.prefabToSpawn.transform.localScale;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        TapDetector1 tap    = spawned.AddComponent<TapDetector1>();
        tap.cam             = arCam;
        tap.data            = data;
        tap.isSpawnedPrefab = true;
        tap.isValidated     = true;

        _currentSpawned = spawned;

        // ── Cache tous les cubes quand le prefab spawne ────────
        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.HideAllCubes();
            Debug.Log("🙈 [TAP] Cubes cachés après spawn prefab");
        }
        else
        {
            Debug.LogWarning("⚠️ [TAP] ARImageCubeOverlay introuvable — cubes non cachés");
        }

        AROverlayUI.Instance?.SetCurrentData(data);
        AROverlayUI.Instance?.EnterPrefabMode();//ajout de tts

        Debug.Log("🐾 Animal spawné au centre de l'écran"
                + " | pos=" + spawned.transform.position
                + " | rot=" + spawned.transform.eulerAngles
                + " | scale=" + spawned.transform.localScale);
    }

    // ─────────────────────────────────────────────────────────────
    void PlaySound()
    {
        if (data == null) return;
        if (data.doPlaySound && data.soundConfig != null && data.soundConfig.clip != null)
        {
            if (AudioManager.Instance != null)
            {
                AudioManager.Instance.Play(data.soundConfig);
                Debug.Log("🔊 AudioManager : " + data.soundConfig.clip.name);
            }
            else
            {
                audioSource.clip   = data.soundConfig.clip;
                audioSource.volume = data.soundConfig.volume;
                audioSource.Play();
                Debug.Log("🔊 Fallback : " + data.soundConfig.clip.name);
            }
        }
        else
        {
            Debug.LogWarning("⚠️ Son absent — doPlaySound=" + data.doPlaySound
                + " | soundConfig=" + data.soundConfig
                + " | clip=" + (data.soundConfig != null ? data.soundConfig.clip : null));
        }
    }

    // ─────────────────────────────────────────────────────────────
    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ DestroyCurrentPrefab | prefab = "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Destroy(_currentSpawned, delay);

        _currentSpawned = null;

        // ── Réaffiche tous les cubes quand on ferme le prefab ──
        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.ShowAllCubes();
            Debug.Log("👁️ [DESTROY] Cubes réaffichés après fermeture prefab");
        }
        else
        {
            Debug.LogWarning("⚠️ [DESTROY] ARImageCubeOverlay introuvable — cubes non réaffichés");
        }

        AROverlayUI.Instance?.ExitPrefabMode();
        Debug.Log("🗑️ Prefab détruit + UI restaurée");
    }

    // ─────────────────────────────────────────────────────────────
    IEnumerator ScaleEffect()
    {
        if (data == null) { isAnimating = false; yield break; }

        isAnimating = true;
        Vector3 original = transform.localScale;
        Vector3 target   = original * data.scaleMultiplier;
        float   time     = 0f;

        while (time < data.scaleDuration)
        {
            transform.localScale = Vector3.Lerp(original, target, time / data.scaleDuration);
            time += Time.deltaTime;
            yield return null;
        }
        transform.localScale = target;
        time = 0f;

        while (time < data.scaleDuration)
        {
            transform.localScale = Vector3.Lerp(target, original, time / data.scaleDuration);
            time += Time.deltaTime;
            yield return null;
        }

        transform.localScale = original;
        isAnimating          = false;
    }
}
/*essaye deliminer tout ui lors de spawn
// TapDetector1.cs
using UnityEngine;
using UnityEngine.InputSystem;
using System.Collections;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;

public class TapDetector1 : MonoBehaviour
{
    public Camera cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    public bool isSpawnedPrefab = false;
    public bool isValidated     = false;

    public ARTrackedImage trackedImage = null;

    private const float LongPressDuration = 0.5f;
    private const float DragThreshold     = 10f;

    private const float SpawnHeightAboveImage = 0.05f;
    private const float TiltTowardCamera      = 15f;

    private bool        isAnimating    = false;
    private AudioSource audioSource;

    private bool    isPressing       = false;
    private float   pressStartTime   = 0f;
    private bool    longPressHandled = false;
    private Vector2 pressStartPos    = Vector2.zero;
    private Vector2 lastDragPos      = Vector2.zero;
    private bool    isDragging       = false;

    private static GameObject _currentSpawned = null;
    private static bool       _isSpawning     = false;

    // ─────────────────────────────────────────────────────────────
    void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    // ─────────────────────────────────────────────────────────────
    void Update()
    {
#if UNITY_EDITOR
        if (Mouse.current == null) return;
        Vector2 pos = Mouse.current.position.ReadValue();
        if      (Mouse.current.leftButton.wasPressedThisFrame)     OnPressDown(pos);
        else if (Mouse.current.leftButton.wasReleasedThisFrame)    OnPressUp(pos);
        else if (Mouse.current.leftButton.isPressed && isPressing) OnPressMoved(pos);
#else
        if (Touchscreen.current == null) return;
        var touch = Touchscreen.current.primaryTouch;
        Vector2 pos = touch.position.ReadValue();
        if      (touch.press.wasPressedThisFrame)                  OnPressDown(pos);
        else if (touch.press.wasReleasedThisFrame)                 OnPressUp(pos);
        else if (touch.press.isPressed && isPressing)              OnPressMoved(pos);
#endif
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressDown(Vector2 screenPosition)
    {
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnCloseButton(screenPosition))
        {
            Debug.Log("🔴 Tap sur bouton Fermer détecté");
            AROverlayUI.Instance.OnFermerPressed();
            return;
        }

        if (cam == null) return;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return;
        if (hit.collider.gameObject != gameObject) return;

        isPressing       = true;
        pressStartTime   = Time.time;
        pressStartPos    = screenPosition;
        lastDragPos      = screenPosition;
        longPressHandled = false;
        isDragging       = false;

        Debug.Log("👇 Appui sur : " + gameObject.name
                + (isSpawnedPrefab ? " [prefab]" : " [image]"));
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            Debug.Log("↔️ Drag sur : " + gameObject.name);
        }

        if (isDragging && isSpawnedPrefab)
        {
            float distanceFromCamera = Vector3.Distance(cam.transform.position, transform.position);
            Vector3 screenPos = new Vector3(screenPosition.x, screenPosition.y, distanceFromCamera);
            Vector3 worldPos  = cam.ScreenToWorldPoint(screenPos);
            transform.position = worldPos;
        }

        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                if (isSpawnedPrefab)
                {
                    Debug.Log("⏱️ Appui long → scale : " + gameObject.name);
                    if (!isAnimating) StartCoroutine(ScaleEffect());
                }
            }
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressUp(Vector2 screenPosition)
    {
        if (!isPressing) return;
        float duration = Time.time - pressStartTime;
        isPressing = false;

        if (isDragging) { isDragging = false; return; }
        if (longPressHandled) return;
        if (duration >= LongPressDuration) return;

        if (cam == null) return;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return;
        if (hit.collider.gameObject != gameObject) return;

        if (isSpawnedPrefab)
        {
            Debug.Log("👆 Tap court prefab → son : " + gameObject.name);
            PlaySound();
        }
        else
        {
            if (!isValidated)
            {
                Debug.Log("🔒 Tap ignoré : pas validée : " + gameObject.name);
                return;
            }
            Debug.Log("✅ Tap image → spawn : " + gameObject.name);
            HandleImageTap();
        }
    }

    // ─────────────────────────────────────────────────────────────
    public void HandleImageTap()
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (data == null)               { Debug.LogWarning("⚠️ data NULL");           return; }
        if (!data.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");   return; }
        if (data.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL");  return; }

        Camera arCam = cam != null ? cam : Camera.main;
        if (arCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        float distanceFromCamera = 0.5f;
        Vector3 screenCenter  = new Vector3(Screen.width / 2f, Screen.height / 2f, distanceFromCamera);
        Vector3 spawnPosition = arCam.ScreenToWorldPoint(screenCenter);

        Vector3 dirToCamera = arCam.transform.position - spawnPosition;
        dirToCamera.y = 0f;
        if (dirToCamera == Vector3.zero) dirToCamera = arCam.transform.forward;
        Quaternion lookAtCam     = Quaternion.LookRotation(dirToCamera);
        Quaternion tilt          = Quaternion.Euler(-TiltTowardCamera, 0f, 0f);
        Quaternion spawnRotation = lookAtCam * tilt;

        _isSpawning = true;
        GameObject spawned = Instantiate(data.prefabToSpawn, spawnPosition, spawnRotation);
        _isSpawning = false;

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = data.prefabToSpawn.transform.localScale;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        TapDetector1 tap    = spawned.AddComponent<TapDetector1>();
        tap.cam             = arCam;
        tap.data            = data;
        tap.isSpawnedPrefab = true;
        tap.isValidated     = true;

        _currentSpawned = spawned;

        // ── Cache tous les cubes quand le prefab spawne ────────
        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.HideAllCubes();
            Debug.Log("🙈 [TAP] Cubes cachés après spawn prefab");
        }
        else
        {
            Debug.LogWarning("⚠️ [TAP] ARImageCubeOverlay introuvable — cubes non cachés");
        }

        AROverlayUI.Instance?.EnterPrefabMode();

        Debug.Log("🐾 Animal spawné au centre de l'écran"
                + " | pos=" + spawned.transform.position
                + " | rot=" + spawned.transform.eulerAngles
                + " | scale=" + spawned.transform.localScale);
    }

    // ─────────────────────────────────────────────────────────────
    void PlaySound()
    {
        if (data == null) return;
        if (data.doPlaySound && data.soundConfig != null && data.soundConfig.clip != null)
        {
            if (AudioManager.Instance != null)
            {
                AudioManager.Instance.Play(data.soundConfig);
                Debug.Log("🔊 AudioManager : " + data.soundConfig.clip.name);
            }
            else
            {
                audioSource.clip   = data.soundConfig.clip;
                audioSource.volume = data.soundConfig.volume;
                audioSource.Play();
                Debug.Log("🔊 Fallback : " + data.soundConfig.clip.name);
            }
        }
        else
        {
            Debug.LogWarning("⚠️ Son absent — doPlaySound=" + data.doPlaySound
                + " | soundConfig=" + data.soundConfig
                + " | clip=" + (data.soundConfig != null ? data.soundConfig.clip : null));
        }
    }

    // ─────────────────────────────────────────────────────────────
    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ DestroyCurrentPrefab | prefab = "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Destroy(_currentSpawned, delay);

        _currentSpawned = null;

        // ── Réaffiche tous les cubes quand on ferme le prefab ──
        ARImageCubeOverlay overlay = Object.FindFirstObjectByType<ARImageCubeOverlay>();
        if (overlay != null)
        {
            overlay.ShowAllCubes();
            Debug.Log("👁️ [DESTROY] Cubes réaffichés après fermeture prefab");
        }
        else
        {
            Debug.LogWarning("⚠️ [DESTROY] ARImageCubeOverlay introuvable — cubes non réaffichés");
        }

        AROverlayUI.Instance?.ExitPrefabMode();
        Debug.Log("🗑️ Prefab détruit + UI restaurée");
    }

    // ─────────────────────────────────────────────────────────────
    IEnumerator ScaleEffect()
    {
        if (data == null) { isAnimating = false; yield break; }

        isAnimating = true;
        Vector3 original = transform.localScale;
        Vector3 target   = original * data.scaleMultiplier;
        float   time     = 0f;

        while (time < data.scaleDuration)
        {
            transform.localScale = Vector3.Lerp(original, target, time / data.scaleDuration);
            time += Time.deltaTime;
            yield return null;
        }
        transform.localScale = target;
        time = 0f;

        while (time < data.scaleDuration)
        {
            transform.localScale = Vector3.Lerp(target, original, time / data.scaleDuration);
            time += Time.deltaTime;
            yield return null;
        }

        transform.localScale = original;
        isAnimating          = false;
    }
}*/