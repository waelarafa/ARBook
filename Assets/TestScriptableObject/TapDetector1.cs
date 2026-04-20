/*version finale - RectTransformUtility pour bouton fermer utilisation de raycast*/
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
    private const float TiltTowardCamera = 15f;

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

    void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

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

        // ── MODIFICATION : déplacement au lieu de rotation ────────
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

        Vector3 spawnPosition;
        Quaternion spawnRotation;

        // ── MODIFICATION : spawn au centre de l'écran ─────────────
        float distanceFromCamera = 0.5f;
        Vector3 screenCenter = new Vector3(Screen.width / 2f, Screen.height / 2f, distanceFromCamera);
        spawnPosition = arCam.ScreenToWorldPoint(screenCenter);

        Vector3 dirToCamera = arCam.transform.position - spawnPosition;
        dirToCamera.y = 0f;
        if (dirToCamera == Vector3.zero) dirToCamera = arCam.transform.forward;
        Quaternion lookAtCam = Quaternion.LookRotation(dirToCamera);
        Quaternion tilt      = Quaternion.Euler(-TiltTowardCamera, 0f, 0f);
        spawnRotation        = lookAtCam * tilt;

        // ── Instantiation dans le monde (pas enfant de la caméra) ─
        _isSpawning = true;
        GameObject spawned = Instantiate(data.prefabToSpawn, spawnPosition, spawnRotation);
        _isSpawning = false;

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        // ── PAS de SetParent → l'animal reste fixe dans le monde ──

        spawned.transform.localScale = data.prefabToSpawn.transform.localScale;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        TapDetector1 tap    = spawned.AddComponent<TapDetector1>();
        tap.cam             = arCam;
        tap.data            = data;
        tap.isSpawnedPrefab = true;
        tap.isValidated     = true;

        _currentSpawned = spawned;
        AROverlayUI.Instance?.ShowCloseButton(true);

        Debug.Log("🐾 Animal spawné au centre de l'écran"
                + " | pos=" + spawned.transform.position
                + " | rot=" + spawned.transform.eulerAngles
                + " | scale=" + spawned.transform.localScale);
    }

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

    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ DestroyCurrentPrefab | prefab = "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Destroy(_currentSpawned, delay);

        _currentSpawned = null;
        AROverlayUI.Instance?.ShowCloseButton(false);
        Debug.Log("🗑️ Prefab détruit + bouton caché");
    }

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
/*version finale verifiee
// TapDetector1.cs
using UnityEngine;
using UnityEngine.InputSystem;
using System.Collections;

public class TapDetector1 : MonoBehaviour
{
    public Camera cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    public bool isSpawnedPrefab = false;
    public bool isValidated     = false;

    private const float SpawnDistance     = 0.6f;
    private const float MaxWidth          = 1.5f;
    private const float MaxHeight         = 1.5f;
    private const float LongPressDuration = 0.5f;
    private const float DragThreshold     = 10f;

    private bool        isAnimating    = false;
    private AudioSource audioSource;

    private bool    isPressing       = false;
    private float   pressStartTime   = 0f;
    private bool    longPressHandled = false;
    private Vector2 pressStartPos    = Vector2.zero;
    private Vector2 lastDragPos      = Vector2.zero;
    private bool    isDragging       = false;

    private static GameObject _currentSpawned = null;

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
    // Retourne true si le doigt est sur un élément UI (bouton Fermer)
    bool IsTapOnUI(Vector2 screenPosition)
    {
        if (UnityEngine.EventSystems.EventSystem.current == null) return false;
        var pointer = new UnityEngine.EventSystems.PointerEventData(
            UnityEngine.EventSystems.EventSystem.current)
        { position = screenPosition };
        var results = new System.Collections.Generic.List<UnityEngine.EventSystems.RaycastResult>();
        UnityEngine.EventSystems.EventSystem.current.RaycastAll(pointer, results);
        return results.Count > 0;
    }

    // ─────────────────────────────────────────────────────────────
    void OnPressDown(Vector2 screenPosition)
    {
        bool onUI = IsTapOnUI(screenPosition);
        Debug.Log("🖱️ IsTapOnUI = " + onUI + " | pos = " + screenPosition);
        if (onUI) return;

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
            Vector2 delta = screenPosition - lastDragPos;
            float sens    = (data != null) ? data.rotationSensitivity : 0.3f;
            float rotY    = -delta.x * sens;
            float rotX    =  delta.y * sens;
            transform.Rotate(Vector3.up,    rotY, Space.World);
            transform.Rotate(Vector3.right, rotX, Space.Self);
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
        if (_currentSpawned != null)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }
        if (data == null)               { Debug.LogWarning("⚠️ data NULL : "          + gameObject.name); return; }
        if (!data.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé : "  + data.imageName);  return; }
        if (data.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL : " + data.imageName);  return; }

        Camera arCam = cam != null ? cam : Camera.main;
        if (arCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        Debug.Log("📷 Caméra : " + arCam.gameObject.name);

        GameObject spawned = Instantiate(data.prefabToSpawn);

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.SetParent(arCam.transform, worldPositionStays: false);
        spawned.transform.localPosition = new Vector3(0.09f, -0.26f, 1.66f);
        spawned.transform.localRotation = Quaternion.Euler(0f, 183f, 0f);
        spawned.transform.localScale    = data.prefabToSpawn.transform.localScale;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        TapDetector1 tap    = spawned.AddComponent<TapDetector1>();
        tap.cam             = arCam;
        tap.data            = data;
        tap.isSpawnedPrefab = true;
        tap.isValidated     = true;

        _currentSpawned = spawned;
        AROverlayUI.Instance?.ShowCloseButton(true);

        Debug.Log("📦 Prefab spawné : " + spawned.name
                + " | pos : " + spawned.transform.position
                + " | rot : " + spawned.transform.eulerAngles);
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
        Debug.Log("🗑️ DestroyCurrentPrefab appelé | _currentSpawned = "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        // Unity surcharge == null : un objet détruit répond true à == null
        // On utilise ReferenceEquals pour détecter les deux cas
        if (_currentSpawned != null)
        {
            Destroy(_currentSpawned, delay);
            Debug.Log("🗑️ Destroy lancé sur : " + _currentSpawned.name);
        }

        _currentSpawned = null;
        AROverlayUI.Instance?.ShowCloseButton(false);
        Debug.Log("🗑️ Prefab détruit + bouton caché");
    }

    // ─────────────────────────────────────────────────────────────
    void ConstrainSize(GameObject obj)
    {
        Renderer[] renderers = obj.GetComponentsInChildren<Renderer>();
        if (renderers.Length == 0) return;

        Bounds bounds = renderers[0].bounds;
        foreach (var r in renderers) bounds.Encapsulate(r.bounds);

        float currentW = bounds.size.x;
        float currentH = bounds.size.y;
        if (currentW <= 0 || currentH <= 0) return;

        float factor = Mathf.Min(MaxWidth / currentW, MaxHeight / currentH, 1f);
        if (factor < 1f)
        {
            obj.transform.localScale *= factor;
            Debug.Log($"📐 Redimensionné x{factor:F3}");
        }
    }

    // ─────────────────────────────────────────────────────────────
    IEnumerator ScaleEffect()
    {
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
/*version 08/04 fix
// TapDetector1.cs
using UnityEngine;
using UnityEngine.InputSystem;
using System.Collections;

public class TapDetector1 : MonoBehaviour
{
    public Camera cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    public bool isSpawnedPrefab = false;
    public bool isValidated = false;

    private const float MaxWidth  = 0.105f;
    private const float MaxHeight = 0.085f;

    private bool        isAnimating = false;
    private AudioSource audioSource;

    void Start()
    {
        audioSource            = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    void Update()
    {
#if UNITY_EDITOR
        if (Mouse.current != null && Mouse.current.leftButton.wasPressedThisFrame)
            DetectTap(Mouse.current.position.ReadValue());
#else
        if (Touchscreen.current != null && Touchscreen.current.primaryTouch.press.wasPressedThisFrame)
            DetectTap(Touchscreen.current.primaryTouch.position.ReadValue());
#endif
    }

    void DetectTap(Vector2 screenPosition)
    {
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return;
        if (hit.collider.gameObject != gameObject)      return;

        if (!isSpawnedPrefab && !isValidated)
        {
            Debug.Log("🔒 Tap ignoré : image pas encore validée : " + gameObject.name);
            return;
        }

        Debug.Log("✅ Tap sur : " + gameObject.name
                + (isSpawnedPrefab ? " [prefab]" : " [image]"));

        if (data == null)
        {
            Debug.LogWarning("⚠️ Aucun data assigné sur : " + gameObject.name);
            return;
        }

        // ── Scale uniquement sur le prefab spawné ─────────────────────
        // NE PAS appeler ScaleEffect ici, seulement dans HandleSpawnedPrefabTap
        // ─────────────────────────────────────────────────────────────

        if (isSpawnedPrefab)
            HandleSpawnedPrefabTap();
        else
            HandleImageTap();
    }

    void HandleImageTap()
    {
        if (!data.doSpawn || data.prefabToSpawn == null) return;

        Vector3    spawnPos = transform.position;
        Quaternion spawnRot = transform.rotation;

        GameObject spawned = Instantiate(data.prefabToSpawn, spawnPos, spawnRot);

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.SetParent(transform);

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        ConstrainSizeToImageSurface(spawned);

        if (data.lookAtCamera)
        {
            Vector3 dir = cam.transform.position - spawned.transform.position;
            dir.y = 0;
            if (dir != Vector3.zero)
                spawned.transform.rotation = Quaternion.LookRotation(-dir);
        }

        TapDetector1 tap = spawned.AddComponent<TapDetector1>();
        tap.cam             = cam;
        tap.data            = data;
        tap.isSpawnedPrefab = true;
        tap.isValidated     = true;

        Debug.Log("📦 Prefab spawné : " + spawned.name);
    }

    void HandleSpawnedPrefabTap()
    {
        // ── Scale sur CE prefab uniquement ───────────────────────────
        if (data.doScale && !isAnimating)
            StartCoroutine(ScaleEffect());

        // ── Son ──────────────────────────────────────────────────────
        if (data.doPlaySound && data.soundConfig != null && data.soundConfig.clip != null)
        {
            if (AudioManager.Instance != null)
            {
                AudioManager.Instance.Play(data.soundConfig);
                Debug.Log("🔊 Son joué via AudioManager : " + data.soundConfig.clip.name);
            }
            else
            {
                // Fallback si AudioManager absent de la scène
                audioSource.clip = data.soundConfig.clip;
                audioSource.volume = data.soundConfig.volume;
                audioSource.Play();
                Debug.Log("🔊 Son joué via fallback AudioSource : " + data.soundConfig.clip.name);
            }
        }
        else
        {
            Debug.LogWarning("⚠️ doPlaySound=" + data.doPlaySound
                + " | soundConfig=" + data.soundConfig
                + " | clip=" + (data.soundConfig != null ? data.soundConfig.clip : null));
        }

        // ── Destruction ──────────────────────────────────────────────
        if (data.doDestroyOnTap)
        {
            float delay = (data.doPlaySound && data.soundConfig != null && data.soundConfig.clip != null)
                ? data.soundConfig.clip.length
                : 0f;
            Debug.Log("💥 Prefab détruit au tap");
            Destroy(gameObject, delay);
        }
    }

    void ConstrainSizeToImageSurface(GameObject obj)
    {
        Renderer[] renderers = obj.GetComponentsInChildren<Renderer>();
        if (renderers.Length == 0) return;

        Bounds bounds = renderers[0].bounds;
        foreach (var r in renderers)
            bounds.Encapsulate(r.bounds);

        float currentW = bounds.size.x;
        float currentH = bounds.size.z;

        if (currentW <= 0 || currentH <= 0) return;

        float scaleW = MaxWidth  / currentW;
        float scaleH = MaxHeight / currentH;
        float factor = Mathf.Min(scaleW, scaleH, 1f);

        if (factor < 1f)
        {
            obj.transform.localScale *= factor;
            Debug.Log($"📐 Prefab redimensionné ×{factor:F3}");
        }
    }

    IEnumerator ScaleEffect()
    {
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
/*version 07/04
// TapDetector1.cs
using UnityEngine;
using UnityEngine.InputSystem;
using System.Collections;

public class TapDetector1 : MonoBehaviour
{
    public Camera cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    // true = cette instance est un prefab déjà spawné (répond à doPlaySound / doDestroyOnTap)
    // false = cette instance est posée sur l'image trackée (répond à doSpawn)
    public bool isSpawnedPrefab = false;

    // Contrôle de validation : le tap sur l'image n'est autorisé
    // que si Book1Detector a validé la position de l'image.
    public bool isValidated = false;

    // ── Taille maximale de la surface image (en mètres) ──────────────
    // 10.5 cm × 8.5 cm → l'image physique dans le monde réel
    private const float MaxWidth  = 0.105f;
    private const float MaxHeight = 0.085f;

    private bool        isAnimating = false;
    private AudioSource audioSource;

    void Start()
    {
        audioSource           = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    void Update()
    {
#if UNITY_EDITOR
        if (Mouse.current != null && Mouse.current.leftButton.wasPressedThisFrame)
            DetectTap(Mouse.current.position.ReadValue());
#else
        if (Touchscreen.current != null && Touchscreen.current.primaryTouch.press.wasPressedThisFrame)
            DetectTap(Touchscreen.current.primaryTouch.position.ReadValue());
#endif
    }

    void DetectTap(Vector2 screenPosition)
    {
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return;
        if (hit.collider.gameObject != gameObject)      return;

        // ── Validation (uniquement pour les colliders posés sur l'image) ──
        if (!isSpawnedPrefab && !isValidated)
        {
            Debug.Log("🔒 Tap ignoré : image pas encore validée : " + gameObject.name);
            return;
        }

        Debug.Log("✅ Tap sur : " + gameObject.name
                + (isSpawnedPrefab ? " [prefab]" : " [image]"));

        if (data == null)
        {
            Debug.LogWarning("⚠️ Aucun data assigné sur : " + gameObject.name);
            return;
        }

        // ── Scale commun ──────────────────────────────────────────────
        if (data.doScale && !isAnimating)
            StartCoroutine(ScaleEffect());

        // ── Comportement selon le rôle de cette instance ──────────────
        if (isSpawnedPrefab)
            HandleSpawnedPrefabTap();
        else
            HandleImageTap();
    }

    // ─────────────────────────────────────────────────────────────────
    // Tap sur le collider posé sur l'image trackée
    // → spawn du prefab au centre du collider (= centre de l'image)
    // ─────────────────────────────────────────────────────────────────
    void HandleImageTap()
    {
        if (!data.doSpawn || data.prefabToSpawn == null) return;

        // Centre exact du collider (= centre de l'image trackée)
        Vector3    spawnPos = transform.position;
        Quaternion spawnRot = transform.rotation;

        GameObject spawned = Instantiate(data.prefabToSpawn, spawnPos, spawnRot);

        // ── Stabilisation (AR) ────────────────────────────────────────
        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        // ── Attaché à la surface de l'image ──────────────────────────
        spawned.transform.SetParent(transform);

        // ── Collider si absent ────────────────────────────────────────
        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        // ── Contraindre la taille à la surface de l'image ────────────
        ConstrainSizeToImageSurface(spawned);

        // ── Orientation caméra ────────────────────────────────────────
        if (data.lookAtCamera)
        {
            Vector3 dir = cam.transform.position - spawned.transform.position;
            dir.y = 0;
            if (dir != Vector3.zero)
                spawned.transform.rotation = Quaternion.LookRotation(-dir);
        }

        // ── TapDetector sur le prefab spawné ─────────────────────────
        TapDetector1 tap = spawned.AddComponent<TapDetector1>();
        tap.cam             = cam;
        tap.data            = data;
        tap.isSpawnedPrefab = true;   // ce GameObject EST le prefab
        tap.isValidated     = true;   // toujours autorisé à recevoir des taps

        Debug.Log("📦 Prefab spawné (centré, contraint) : " + spawned.name);
    }

    // ─────────────────────────────────────────────────────────────────
    // Tap sur le prefab déjà spawné
    // → son + destruction optionnelle
    // ─────────────────────────────────────────────────────────────────
    void HandleSpawnedPrefabTap()
    {
        if (data.doPlaySound && data.soundToPlay != null)
        {
            audioSource.clip = data.soundToPlay;
            audioSource.Play();
            Debug.Log("🔊 Son joué : " + data.soundToPlay.name);
        }

        if (data.doDestroyOnTap)
        {
            float delay = (data.doPlaySound && data.soundToPlay != null)
                ? data.soundToPlay.length
                : 0f;
            Debug.Log("💥 Prefab détruit au tap");
            Destroy(gameObject, delay);
        }
    }

    // ─────────────────────────────────────────────────────────────────
    // Redimensionne le prefab pour qu'il ne dépasse pas la surface image
    // La surface image fait MaxWidth × MaxHeight (10.5 cm × 8.5 cm)
    // ─────────────────────────────────────────────────────────────────
    void ConstrainSizeToImageSurface(GameObject obj)
    {
        // Récupère les bounds actuels du prefab (tous ses renderers)
        Renderer[] renderers = obj.GetComponentsInChildren<Renderer>();
        if (renderers.Length == 0) return;

        Bounds bounds = renderers[0].bounds;
        foreach (var r in renderers)
            bounds.Encapsulate(r.bounds);

        // Dimensions actuelles en world-space
        float currentW = bounds.size.x;
        float currentH = bounds.size.z; // profondeur = hauteur sur plan horizontal

        if (currentW <= 0 || currentH <= 0) return;

        // Facteur de réduction uniforme pour rester dans MaxWidth × MaxHeight
        float scaleW = MaxWidth  / currentW;
        float scaleH = MaxHeight / currentH;
        float factor = Mathf.Min(scaleW, scaleH, 1f); // jamais agrandir

        if (factor < 1f)
        {
            obj.transform.localScale *= factor;
            Debug.Log($"📐 Prefab redimensionné ×{factor:F3} pour tenir dans {MaxWidth*100}×{MaxHeight*100} cm");
        }
    }

    // ─────────────────────────────────────────────────────────────────
    IEnumerator ScaleEffect()
    {
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
/ TapDetector1.cs
using UnityEngine;
using UnityEngine.InputSystem;
using System.Collections;

public class TapDetector1 : MonoBehaviour
{
    public Camera cam;
    public ImageCubeDataLibrary.ImageDataEntry data;
    public ImageCubeDataLibrary.TapTargetType targetType;
    public bool isValidated = false;

    private bool isAnimating = false;
    private AudioSource audioSource;

    void Start()
    {
        audioSource = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    void Update()
    {
#if UNITY_EDITOR
        if (Mouse.current != null && Mouse.current.leftButton.wasPressedThisFrame)
            DetectTap(Mouse.current.position.ReadValue());
#else
        if (Touchscreen.current != null && Touchscreen.current.primaryTouch.press.wasPressedThisFrame)
            DetectTap(Touchscreen.current.primaryTouch.position.ReadValue());
#endif
    }

    void DetectTap(Vector2 screenPosition)
    {
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (Physics.Raycast(ray, out RaycastHit hit))
        {
            if (hit.collider.gameObject != gameObject) return;

            // ── Vérification validation ───────────────────
            if (targetType == ImageCubeDataLibrary.TapTargetType.Image && !isValidated)
            {
                Debug.Log("🔒 Tap ignoré : image pas encore validée : " + gameObject.name);
                return;
            }

            Debug.Log("✅ Tap sur : " + gameObject.name + " | Type : " + targetType);

            if (data == null)
            {
                Debug.LogWarning("⚠️ Aucun data assigné sur : " + gameObject.name);
                return;
            }

            // ── Actions communes ──────────────────────────
            if (data.doScale && !isAnimating)
                StartCoroutine(ScaleEffect());

            // ── Actions selon le type ─────────────────────
            switch (targetType)
            {
                case ImageCubeDataLibrary.TapTargetType.Image:
                    HandleImageTap(hit);
                    break;

                case ImageCubeDataLibrary.TapTargetType.Prefab:
                    HandlePrefabTap();
                    break;
            }
        }
    }

    void HandleImageTap(RaycastHit hit)
    {
        if (data.doSpawn && data.prefabToSpawn != null)
        {
            // 🎯 Position EXACTE du tap (sans offset)
            Vector3 spawnPos = hit.point;

            // 🔄 Rotation alignée avec la surface
            Quaternion spawnRot = Quaternion.FromToRotation(Vector3.up, hit.normal);

            // 🚀 Spawn
            GameObject spawned = Instantiate(data.prefabToSpawn, spawnPos, spawnRot);

            // 🧱 Stabiliser (empêcher chute / mouvement)
            Rigidbody rb = spawned.GetComponent<Rigidbody>();
            if (rb != null)
            {
                rb.isKinematic = true;
                rb.useGravity = false;
            }

            // 🔗 Attacher à la surface (important en AR)
            spawned.transform.SetParent(hit.collider.transform);

            // 👆 Ajouter TapDetector sur le prefab
            TapDetector1 tap = spawned.AddComponent<TapDetector1>();
            tap.cam = cam;
            tap.data = data;
            tap.targetType = ImageCubeDataLibrary.TapTargetType.Prefab;
            tap.isValidated = true;

            // 📦 Ajouter collider si absent
            if (spawned.GetComponent<Collider>() == null)
                spawned.AddComponent<BoxCollider>();

            // 👀 Option : regarder la caméra proprement
            if (data.lookAtCamera)
            {
                Vector3 direction = cam.transform.position - spawned.transform.position;
                direction.y = 0;
                if (direction != Vector3.zero)
                    spawned.transform.rotation = Quaternion.LookRotation(-direction);
            }

            Debug.Log("📦 Prefab spawné (stable) : " + spawned.name);
        }
    }

    void HandlePrefabTap()
    {
        if (data.doPlaySound && data.soundToPlay != null)
        {
            audioSource.clip = data.soundToPlay;
            audioSource.Play();
            Debug.Log("🔊 Son joué : " + data.soundToPlay.name);
        }

        if (data.doDestroyOnTap)
        {
            float delay = (data.doPlaySound && data.soundToPlay != null)
                ? data.soundToPlay.length
                : 0f;
            Debug.Log("💥 Prefab détruit au tap");
            Destroy(gameObject, delay);
        }
    }

    IEnumerator ScaleEffect()
    {
        isAnimating = true;
        Vector3 original = transform.localScale;
        Vector3 target = original * data.scaleMultiplier;
        float time = 0f;

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
        isAnimating = false;
    }
}*/