using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;

public abstract class BaseTapDetector : MonoBehaviour
{
    public Camera                              cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    protected const float LongPressDuration = 0.5f;
    protected const float DragThreshold     = 10f;
    protected const float TiltTowardCamera  = 15f;

    // Limites de scale pour le pinch zoom
    private const float MinScale        = 0.1f;
    private const float MaxScale        = 5.0f;
    private const float PinchSensitivity = 0.002f;

    protected bool        isAnimating  = false;
    protected AudioSource audioSource;

    protected bool    isPressing       = false;
    protected float   pressStartTime   = 0f;
    protected bool    longPressHandled = false;
    protected Vector2 pressStartPos    = Vector2.zero;
    protected Vector2 lastDragPos      = Vector2.zero;
    protected bool    isDragging       = false;

    protected float   _dragDepth     = 0f;
    protected Vector3 _originalScale = Vector3.one;

    // Pinch zoom
    private float _lastPinchDistance = 0f;
    private bool  _isPinching        = false;

    // Rotation appui long
    protected bool    _isRotating  = false;
    private   Vector2 _lastRotPos  = Vector2.zero;

    protected static GameObject _currentSpawned = null;
    protected static bool       _isSpawning     = false;

    protected virtual bool CanDrag()  => true;
    protected virtual bool CanScale() => true;

    // ─────────────────────────────────────────
    protected virtual void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
        _originalScale          = transform.localScale;
    }

    // ─────────────────────────────────────────
    protected virtual void Update()
    {
#if UNITY_EDITOR
        if (Mouse.current == null) return;
        Vector2 pos = Mouse.current.position.ReadValue();
        if      (Mouse.current.leftButton.wasPressedThisFrame)     OnPressDown(pos);
        else if (Mouse.current.leftButton.wasReleasedThisFrame)    OnPressUp(pos);
        else if (Mouse.current.leftButton.isPressed && isPressing) OnPressMoved(pos);

        // Scroll souris → zoom en éditeur
        float scroll = Mouse.current.scroll.ReadValue().y;
        if (Mathf.Abs(scroll) > 0.01f && _currentSpawned != null)
            ApplyPinchZoom(_currentSpawned.transform, scroll * 1f);
#else
        if (Touchscreen.current == null) return;

        // ── 2 doigts → pinch zoom ──────────────────────────────
        var touches    = Touchscreen.current.touches;
        bool finger0   = touches[0].press.isPressed;
        bool finger1   = touches[1].press.isPressed;

        if (finger0 && finger1)
        {
            Vector2 pos0 = touches[0].position.ReadValue();
            Vector2 pos1 = touches[1].position.ReadValue();
            float   dist = Vector2.Distance(pos0, pos1);

            if (!_isPinching)
            {
                _lastPinchDistance = dist;
                _isPinching        = true;
                isPressing         = false; // annule le tap 1 doigt
            }
            else
            {
                float delta = dist - _lastPinchDistance;
                if (_currentSpawned != null)
                    ApplyPinchZoom(_currentSpawned.transform, delta);
                _lastPinchDistance = dist;
            }
            return; // 2 doigts actifs → ignore le 1 doigt
        }
        else
        {
            _isPinching = false;
        }

        // ── 1 doigt → tap/drag normal ──────────────────────────
        var touch = Touchscreen.current.primaryTouch;
        Vector2 touchPos = touch.position.ReadValue();
        if      (touch.press.wasPressedThisFrame)                      OnPressDown(touchPos);
        else if (touch.press.wasReleasedThisFrame)                     OnPressUp(touchPos);
        else if (touch.press.isPressed && isPressing)                  OnPressMoved(touchPos);
#endif
    }

    // ─────────────────────────────────────────
    // Applique le zoom pinch sur le transform cible
    private void ApplyPinchZoom(Transform target, float delta)
    {
        float   current  = target.localScale.x;
        float   newScale = Mathf.Clamp(current + delta * PinchSensitivity, MinScale, MaxScale);
        target.localScale = new Vector3(newScale, newScale, newScale);
    }

    // ─────────────────────────────────────────
    protected bool IsTapOnUI(Vector2 screenPosition)
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
            Debug.Log("🖱️ Tap sur UI : " + results[0].gameObject.name);
            return true;
        }
        return false;
    }

    // ─────────────────────────────────────────
    protected bool CheckOverlayButtons(Vector2 pos)
    {
        if (AROverlayUI.Instance == null) return false;

        if (AROverlayUI.Instance.IsTapOnCloseButton(pos))
        {
            Debug.Log("🔴 Tap Fermer");
            AROverlayUI.Instance.OnFermerPressed();
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnPhotoButton(pos))
        {
            Debug.Log("📷 Tap Photo");
            ScreenshotManager.Instance?.TakeAndSaveScreenshot();
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnArabeButton(pos))
        {
            Debug.Log("🌐 Tap Arabe");
            PlaySoundConfig(data?.soundConfigArabe);
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnFrancaisButton(pos))
        {
            Debug.Log("🌐 Tap Français");
            PlaySoundConfig(data?.soundConfigFrancais);
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnAnglaisButton(pos))
        {
            Debug.Log("🌐 Tap Anglais");
            PlaySoundConfig(data?.soundConfigAnglais);
            return true;
        }

        return false;
    }

    // ─────────────────────────────────────────
    protected void PlaySoundConfig(SoundConfig config)
    {
        if (config == null || config.clip == null)
        {
            Debug.LogWarning("⚠️ SoundConfig absent ou clip NULL");
            return;
        }

        if (AudioManager.Instance != null)
        {
            AudioManager.Instance.Play(config);
            Debug.Log("🔊 AudioManager : " + config.clip.name);
        }
        else
        {
            if (!config.allowOverlap && audioSource.isPlaying) return;
            audioSource.clip   = config.clip;
            audioSource.volume = config.volume;
            audioSource.Play();
            Debug.Log("🔊 Fallback : " + config.clip.name);
        }
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressDown(Vector2 screenPosition);

    // ─────────────────────────────────────────
    protected virtual void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            _dragDepth       = Vector3.Distance(
                cam.transform.position, transform.position);
            Debug.Log("↔️ Drag : " + gameObject.name);
        }

        if (isDragging && CanDrag() && !_isRotating)
        {
            // Déplacement uniquement — scale non touchée
            Vector3 screenPos  = new Vector3(screenPosition.x, screenPosition.y, _dragDepth);
            transform.position = cam.ScreenToWorldPoint(screenPos);
        }

        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                _isRotating      = true;
                _lastRotPos      = screenPosition;
                Debug.Log("⏱️ Appui long → rotation : " + gameObject.name);
            }
        }

        // Rotation par glissement du doigt pendant l'appui long
        if (_isRotating && _currentSpawned != null)
        {
            // Sensibilité depuis l'inspector (data.rotationSensitivity)
            // Si data est null ou sensibilité à 0 → pas de rotation
            float sensitivity = (data != null && data.rotationSensitivity > 0f)
                ? data.rotationSensitivity
                : 0f;

            if (sensitivity > 0f)
            {
                Vector2 delta = screenPosition - _lastRotPos;
                // Détecte AR ou 3D pour corriger le sens de rotation
                bool isAR = cam != null &&
                            cam.GetComponent<UnityEngine.XR.ARFoundation.ARCameraBackground>() != null;
                float sign = isAR ? -1f : 1f;

                float rotX =  delta.y * sensitivity * sign;
                float rotY = -delta.x * sensitivity * sign;
                _currentSpawned.transform.Rotate(rotX, rotY, 0f, Space.World);
            }
            _lastRotPos = screenPosition;
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressUp(Vector2 screenPosition);

    // ─────────────────────────────────────────
    protected void RestoreScaleAfterDrag()
    {
        if (!isAnimating)
            StartCoroutine(RestoreScaleCoroutine());
    }

    private IEnumerator RestoreScaleCoroutine()
    {
        // Le drag ne modifie plus la scale — rien à restaurer
        // On garde la scale telle quelle (pinch zoom respecté)
        yield return null;
    }

    // ─────────────────────────────────────────
    protected bool RaycastHitThis(Vector2 screenPosition)
    {
        if (cam == null) return false;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return false;
        return hit.collider.gameObject == gameObject;
    }

    // ─────────────────────────────────────────
    protected void BeginPress(Vector2 screenPosition)
    {
        isPressing       = true;
        pressStartTime   = Time.time;
        pressStartPos    = screenPosition;
        lastDragPos      = screenPosition;
        longPressHandled = false;
        isDragging       = false;
        _isRotating      = false;
    }

    // ─────────────────────────────────────────
    protected void PlaySound()
    {
        if (data == null) return;
        PlaySoundConfig(data.soundConfig);
    }

    // ─────────────────────────────────────────
    protected IEnumerator ScaleEffect()
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

    // ─────────────────────────────────────────
    // SpawnPrefab — rotation depuis l'inspector du prefab
    // ─────────────────────────────────────────
    protected static GameObject SpawnPrefab(
        ImageCubeDataLibrary.ImageDataEntry entry,
        Camera usedCam)
    {
        bool  isAR = usedCam.GetComponent<UnityEngine.XR.ARFoundation.ARCameraBackground>() != null;
        float dist = isAR ? 0.6f : 0.6f;

        Vector3 screenCenter = new Vector3(Screen.width / 2f, Screen.height / 2f, dist);
        Vector3 spawnPos     = usedCam.ScreenToWorldPoint(screenCenter);

        Quaternion spawnRot = entry.prefabToSpawn.transform.rotation;
        GameObject spawned  = Object.Instantiate(entry.prefabToSpawn, spawnPos, spawnRot);

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = entry.prefabToSpawn.transform.localScale;
        spawned.name                 = "Spawned_" + entry.imageName;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        return spawned;
    }
}
/*ajout de zoom
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;

public abstract class BaseTapDetector : MonoBehaviour
{
    public Camera                              cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    protected const float LongPressDuration = 0.5f;
    protected const float DragThreshold     = 10f;
    protected const float TiltTowardCamera  = 15f;

    // Limites de scale pour le pinch zoom
    private const float MinScale        = 0.1f;
    private const float MaxScale        = 5.0f;
    private const float PinchSensitivity = 0.01f;

    protected bool        isAnimating  = false;
    protected AudioSource audioSource;

    protected bool    isPressing       = false;
    protected float   pressStartTime   = 0f;
    protected bool    longPressHandled = false;
    protected Vector2 pressStartPos    = Vector2.zero;
    protected Vector2 lastDragPos      = Vector2.zero;
    protected bool    isDragging       = false;

    protected float   _dragDepth     = 0f;
    protected Vector3 _originalScale = Vector3.one;

    // Pinch zoom
    private float _lastPinchDistance = 0f;
    private bool  _isPinching        = false;

    protected static GameObject _currentSpawned = null;
    protected static bool       _isSpawning     = false;

    protected virtual bool CanDrag()  => true;
    protected virtual bool CanScale() => true;

    // ─────────────────────────────────────────
    protected virtual void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
        _originalScale          = transform.localScale;
    }

    // ─────────────────────────────────────────
    protected virtual void Update()
    {
#if UNITY_EDITOR
        if (Mouse.current == null) return;
        Vector2 pos = Mouse.current.position.ReadValue();
        if      (Mouse.current.leftButton.wasPressedThisFrame)     OnPressDown(pos);
        else if (Mouse.current.leftButton.wasReleasedThisFrame)    OnPressUp(pos);
        else if (Mouse.current.leftButton.isPressed && isPressing) OnPressMoved(pos);

        // Scroll souris → zoom en éditeur
        float scroll = Mouse.current.scroll.ReadValue().y;
        if (Mathf.Abs(scroll) > 0.01f && _currentSpawned != null)
            ApplyPinchZoom(_currentSpawned.transform, scroll * 5f);
#else
        if (Touchscreen.current == null) return;

        // ── 2 doigts → pinch zoom ──────────────────────────────
        var touches    = Touchscreen.current.touches;
        bool finger0   = touches[0].press.isPressed;
        bool finger1   = touches[1].press.isPressed;

        if (finger0 && finger1)
        {
            Vector2 pos0 = touches[0].position.ReadValue();
            Vector2 pos1 = touches[1].position.ReadValue();
            float   dist = Vector2.Distance(pos0, pos1);

            if (!_isPinching)
            {
                _lastPinchDistance = dist;
                _isPinching        = true;
                isPressing         = false; // annule le tap 1 doigt
            }
            else
            {
                float delta = dist - _lastPinchDistance;
                if (_currentSpawned != null)
                    ApplyPinchZoom(_currentSpawned.transform, delta);
                _lastPinchDistance = dist;
            }
            return; // 2 doigts actifs → ignore le 1 doigt
        }
        else
        {
            _isPinching = false;
        }

        // ── 1 doigt → tap/drag normal ──────────────────────────
        var touch = Touchscreen.current.primaryTouch;
        Vector2 touchPos = touch.position.ReadValue();
        if      (touch.press.wasPressedThisFrame)                      OnPressDown(touchPos);
        else if (touch.press.wasReleasedThisFrame)                     OnPressUp(touchPos);
        else if (touch.press.isPressed && isPressing)                  OnPressMoved(touchPos);
#endif
    }

    // ─────────────────────────────────────────
    // Applique le zoom pinch sur le transform cible
    private void ApplyPinchZoom(Transform target, float delta)
    {
        float   current  = target.localScale.x;
        float   newScale = Mathf.Clamp(current + delta * PinchSensitivity, MinScale, MaxScale);
        target.localScale = new Vector3(newScale, newScale, newScale);
    }

    // ─────────────────────────────────────────
    protected bool IsTapOnUI(Vector2 screenPosition)
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
            Debug.Log("🖱️ Tap sur UI : " + results[0].gameObject.name);
            return true;
        }
        return false;
    }

    // ─────────────────────────────────────────
    protected bool CheckOverlayButtons(Vector2 pos)
    {
        if (AROverlayUI.Instance == null) return false;

        if (AROverlayUI.Instance.IsTapOnCloseButton(pos))
        {
            Debug.Log("🔴 Tap Fermer");
            AROverlayUI.Instance.OnFermerPressed();
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnPhotoButton(pos))
        {
            Debug.Log("📷 Tap Photo");
            ScreenshotManager.Instance?.TakeAndSaveScreenshot();
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnArabeButton(pos))
        {
            Debug.Log("🌐 Tap Arabe");
            PlaySoundConfig(data?.soundConfigArabe);
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnFrancaisButton(pos))
        {
            Debug.Log("🌐 Tap Français");
            PlaySoundConfig(data?.soundConfigFrancais);
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnAnglaisButton(pos))
        {
            Debug.Log("🌐 Tap Anglais");
            PlaySoundConfig(data?.soundConfigAnglais);
            return true;
        }

        return false;
    }

    // ─────────────────────────────────────────
    protected void PlaySoundConfig(SoundConfig config)
    {
        if (config == null || config.clip == null)
        {
            Debug.LogWarning("⚠️ SoundConfig absent ou clip NULL");
            return;
        }

        if (AudioManager.Instance != null)
        {
            AudioManager.Instance.Play(config);
            Debug.Log("🔊 AudioManager : " + config.clip.name);
        }
        else
        {
            if (!config.allowOverlap && audioSource.isPlaying) return;
            audioSource.clip   = config.clip;
            audioSource.volume = config.volume;
            audioSource.Play();
            Debug.Log("🔊 Fallback : " + config.clip.name);
        }
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressDown(Vector2 screenPosition);

    // ─────────────────────────────────────────
    protected virtual void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            _dragDepth       = Vector3.Distance(
                cam.transform.position, transform.position);
            Debug.Log("↔️ Drag : " + gameObject.name);
        }

        if (isDragging && CanDrag())
        {
            Vector3 screenPos    = new Vector3(screenPosition.x, screenPosition.y, _dragDepth);
            transform.position   = cam.ScreenToWorldPoint(screenPos);

            Vector3 dragScale    = _originalScale * 0.92f;
            transform.localScale = Vector3.Lerp(
                transform.localScale, dragScale, Time.deltaTime * 8f);
        }

        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                if (CanScale())
                {
                    Debug.Log("⏱️ Appui long → scale : " + gameObject.name);
                    if (!isAnimating) StartCoroutine(ScaleEffect());
                }
            }
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressUp(Vector2 screenPosition);

    // ─────────────────────────────────────────
    protected void RestoreScaleAfterDrag()
    {
        if (!isAnimating)
            StartCoroutine(RestoreScaleCoroutine());
    }

    private IEnumerator RestoreScaleCoroutine()
    {
        float   time    = 0f;
        float   dur     = 0.15f;
        Vector3 current = transform.localScale;

        while (time < dur)
        {
            transform.localScale = Vector3.Lerp(current, _originalScale, time / dur);
            time += Time.deltaTime;
            yield return null;
        }
        transform.localScale = _originalScale;
    }

    // ─────────────────────────────────────────
    protected bool RaycastHitThis(Vector2 screenPosition)
    {
        if (cam == null) return false;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return false;
        return hit.collider.gameObject == gameObject;
    }

    // ─────────────────────────────────────────
    protected void BeginPress(Vector2 screenPosition)
    {
        isPressing       = true;
        pressStartTime   = Time.time;
        pressStartPos    = screenPosition;
        lastDragPos      = screenPosition;
        longPressHandled = false;
        isDragging       = false;
    }

    // ─────────────────────────────────────────
    protected void PlaySound()
    {
        if (data == null) return;
        PlaySoundConfig(data.soundConfig);
    }

    // ─────────────────────────────────────────
    protected IEnumerator ScaleEffect()
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

    // ─────────────────────────────────────────
    // SpawnPrefab — rotation depuis l'inspector du prefab
    // ─────────────────────────────────────────
    protected static GameObject SpawnPrefab(
        ImageCubeDataLibrary.ImageDataEntry entry,
        Camera usedCam)
    {
        bool  isAR = usedCam.GetComponent<UnityEngine.XR.ARFoundation.ARCameraBackground>() != null;
        float dist = isAR ? 0.6f : 0.6f;

        Vector3 screenCenter = new Vector3(Screen.width / 2f, Screen.height / 2f, dist);
        Vector3 spawnPos     = usedCam.ScreenToWorldPoint(screenCenter);

        Quaternion spawnRot = entry.prefabToSpawn.transform.rotation;
        GameObject spawned  = Object.Instantiate(entry.prefabToSpawn, spawnPos, spawnRot);

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = entry.prefabToSpawn.transform.localScale;
        spawned.name                 = "Spawned_" + entry.imageName;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        return spawned;
    }
}
/*using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;

public abstract class BaseTapDetector : MonoBehaviour
{
    public Camera                              cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    protected const float LongPressDuration = 0.5f;
    protected const float DragThreshold     = 10f;
    protected const float TiltTowardCamera  = 15f;

    protected bool        isAnimating  = false;
    protected AudioSource audioSource;

    protected bool    isPressing       = false;
    protected float   pressStartTime   = 0f;
    protected bool    longPressHandled = false;
    protected Vector2 pressStartPos    = Vector2.zero;
    protected Vector2 lastDragPos      = Vector2.zero;
    protected bool    isDragging       = false;

    protected float   _dragDepth     = 0f;
    protected Vector3 _originalScale = Vector3.one;

    protected static GameObject _currentSpawned = null;
    protected static bool       _isSpawning     = false;

    protected virtual bool CanDrag()  => true;
    protected virtual bool CanScale() => true;

    // ─────────────────────────────────────────
    protected virtual void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
        _originalScale          = transform.localScale;
    }

    // ─────────────────────────────────────────
    protected virtual void Update()
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

    // ─────────────────────────────────────────
    protected bool IsTapOnUI(Vector2 screenPosition)
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
            Debug.Log("🖱️ Tap sur UI : " + results[0].gameObject.name);
            return true;
        }
        return false;
    }

    // ─────────────────────────────────────────
    protected bool CheckOverlayButtons(Vector2 pos)
    {
        if (AROverlayUI.Instance == null) return false;

        if (AROverlayUI.Instance.IsTapOnCloseButton(pos))
        {
            Debug.Log("🔴 Tap Fermer");
            AROverlayUI.Instance.OnFermerPressed();
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnPhotoButton(pos))
        {
            Debug.Log("📷 Tap Photo");
            ScreenshotManager.Instance?.TakeAndSaveScreenshot();
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnArabeButton(pos))
        {
            Debug.Log("🌐 Tap Arabe");
            PlaySoundConfig(data?.soundConfigArabe);
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnFrancaisButton(pos))
        {
            Debug.Log("🌐 Tap Français");
            PlaySoundConfig(data?.soundConfigFrancais);
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnAnglaisButton(pos))
        {
            Debug.Log("🌐 Tap Anglais");
            PlaySoundConfig(data?.soundConfigAnglais);
            return true;
        }

        return false;
    }

    // ─────────────────────────────────────────
    protected void PlaySoundConfig(SoundConfig config)
    {
        if (config == null || config.clip == null)
        {
            Debug.LogWarning("⚠️ SoundConfig absent ou clip NULL");
            return;
        }

        if (AudioManager.Instance != null)
        {
            AudioManager.Instance.Play(config);
            Debug.Log("🔊 AudioManager : " + config.clip.name);
        }
        else
        {
            if (!config.allowOverlap && audioSource.isPlaying) return;
            audioSource.clip   = config.clip;
            audioSource.volume = config.volume;
            audioSource.Play();
            Debug.Log("🔊 Fallback : " + config.clip.name);
        }
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressDown(Vector2 screenPosition);

    // ─────────────────────────────────────────
    protected virtual void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            _dragDepth       = Vector3.Distance(
                cam.transform.position, transform.position);
            Debug.Log("↔️ Drag : " + gameObject.name);
        }

        if (isDragging && CanDrag())
        {
            Vector3 screenPos    = new Vector3(screenPosition.x, screenPosition.y, _dragDepth);
            transform.position   = cam.ScreenToWorldPoint(screenPos);

            Vector3 dragScale    = _originalScale * 0.92f;
            transform.localScale = Vector3.Lerp(
                transform.localScale, dragScale, Time.deltaTime * 8f);
        }

        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                if (CanScale())
                {
                    Debug.Log("⏱️ Appui long → scale : " + gameObject.name);
                    if (!isAnimating) StartCoroutine(ScaleEffect());
                }
            }
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressUp(Vector2 screenPosition);

    // ─────────────────────────────────────────
    protected void RestoreScaleAfterDrag()
    {
        if (!isAnimating)
            StartCoroutine(RestoreScaleCoroutine());
    }

    private IEnumerator RestoreScaleCoroutine()
    {
        float   time    = 0f;
        float   dur     = 0.15f;
        Vector3 current = transform.localScale;

        while (time < dur)
        {
            transform.localScale = Vector3.Lerp(current, _originalScale, time / dur);
            time += Time.deltaTime;
            yield return null;
        }
        transform.localScale = _originalScale;
    }

    // ─────────────────────────────────────────
    protected bool RaycastHitThis(Vector2 screenPosition)
    {
        if (cam == null) return false;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return false;
        return hit.collider.gameObject == gameObject;
    }

    // ─────────────────────────────────────────
    protected void BeginPress(Vector2 screenPosition)
    {
        isPressing       = true;
        pressStartTime   = Time.time;
        pressStartPos    = screenPosition;
        lastDragPos      = screenPosition;
        longPressHandled = false;
        isDragging       = false;
    }

    // ─────────────────────────────────────────
    protected void PlaySound()
    {
        if (data == null) return;
        PlaySoundConfig(data.soundConfig);
    }

    // ─────────────────────────────────────────
    protected IEnumerator ScaleEffect()
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

    // ─────────────────────────────────────────
    // SpawnPrefab — rotation fixe dans le monde (explorable à 360°)
    // ─────────────────────────────────────────
    protected static GameObject SpawnPrefab(
        ImageCubeDataLibrary.ImageDataEntry entry,
        Camera usedCam)
    {
        bool  isAR = usedCam.GetComponent<UnityEngine.XR.ARFoundation.ARCameraBackground>() != null;
        float dist = isAR ? 0.6f : 0.6f;

        Vector3 screenCenter = new Vector3(Screen.width / 2f, Screen.height / 2f, dist);
        Vector3 spawnPos     = usedCam.ScreenToWorldPoint(screenCenter);

        // Rotation fixe — le prefab ne fait plus face à la caméra.
        // Il reste orienté dans le monde, tu peux tourner autour pour voir tous ses côtés.
        Quaternion spawnRot = entry.prefabToSpawn.transform.rotation;
        GameObject spawned  = Object.Instantiate(entry.prefabToSpawn, spawnPos, spawnRot);

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = entry.prefabToSpawn.transform.localScale;
        spawned.name                 = "Spawned_" + entry.imageName;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        return spawned;
    }
}
/*using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;

public abstract class BaseTapDetector : MonoBehaviour
{
    public Camera                              cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    protected const float LongPressDuration = 0.5f;
    protected const float DragThreshold     = 10f;
    protected const float TiltTowardCamera  = 15f;

    protected bool        isAnimating  = false;
    protected AudioSource audioSource;

    protected bool    isPressing       = false;
    protected float   pressStartTime   = 0f;
    protected bool    longPressHandled = false;
    protected Vector2 pressStartPos    = Vector2.zero;
    protected Vector2 lastDragPos      = Vector2.zero;
    protected bool    isDragging       = false;

    protected float   _dragDepth     = 0f;
    protected Vector3 _originalScale = Vector3.one;

    protected static GameObject _currentSpawned = null;
    protected static bool       _isSpawning     = false;

    protected virtual bool CanDrag()  => true;
    protected virtual bool CanScale() => true;

    // ─────────────────────────────────────────
    protected virtual void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
        _originalScale          = transform.localScale;
    }

    // ─────────────────────────────────────────
    protected virtual void Update()
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

    // ─────────────────────────────────────────
    protected bool IsTapOnUI(Vector2 screenPosition)
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
            Debug.Log("🖱️ Tap sur UI : " + results[0].gameObject.name);
            return true;
        }
        return false;
    }

    // ─────────────────────────────────────────
    protected bool CheckOverlayButtons(Vector2 pos)
    {
        if (AROverlayUI.Instance == null) return false;

        if (AROverlayUI.Instance.IsTapOnCloseButton(pos))
        {
            Debug.Log("🔴 Tap Fermer");
            AROverlayUI.Instance.OnFermerPressed();
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnPhotoButton(pos))
        {
            Debug.Log("📷 Tap Photo");
            ScreenshotManager.Instance?.TakeAndSaveScreenshot();
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnArabeButton(pos))
        {
            Debug.Log("🌐 Tap Arabe");
            PlaySoundConfig(data?.soundConfigArabe);
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnFrancaisButton(pos))
        {
            Debug.Log("🌐 Tap Français");
            PlaySoundConfig(data?.soundConfigFrancais);
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnAnglaisButton(pos))
        {
            Debug.Log("🌐 Tap Anglais");
            PlaySoundConfig(data?.soundConfigAnglais);
            return true;
        }

        return false;
    }

    // ─────────────────────────────────────────
    protected void PlaySoundConfig(SoundConfig config)
    {
        if (config == null || config.clip == null)
        {
            Debug.LogWarning("⚠️ SoundConfig absent ou clip NULL");
            return;
        }

        if (AudioManager.Instance != null)
        {
            AudioManager.Instance.Play(config);
            Debug.Log("🔊 AudioManager : " + config.clip.name);
        }
        else
        {
            if (!config.allowOverlap && audioSource.isPlaying) return;
            audioSource.clip   = config.clip;
            audioSource.volume = config.volume;
            audioSource.Play();
            Debug.Log("🔊 Fallback : " + config.clip.name);
        }
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressDown(Vector2 screenPosition);

    // ─────────────────────────────────────────
    protected virtual void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            _dragDepth       = Vector3.Distance(
                cam.transform.position, transform.position);
            Debug.Log("↔️ Drag : " + gameObject.name);
        }

        if (isDragging && CanDrag())
        {
            Vector3 screenPos    = new Vector3(screenPosition.x, screenPosition.y, _dragDepth);
            transform.position   = cam.ScreenToWorldPoint(screenPos);

            Vector3 dragScale    = _originalScale * 0.92f;
            transform.localScale = Vector3.Lerp(
                transform.localScale, dragScale, Time.deltaTime * 8f);
        }

        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                if (CanScale())
                {
                    Debug.Log("⏱️ Appui long → scale : " + gameObject.name);
                    if (!isAnimating) StartCoroutine(ScaleEffect());
                }
            }
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressUp(Vector2 screenPosition);

    // ─────────────────────────────────────────
    protected void RestoreScaleAfterDrag()
    {
        if (!isAnimating)
            StartCoroutine(RestoreScaleCoroutine());
    }

    private IEnumerator RestoreScaleCoroutine()
    {
        float   time    = 0f;
        float   dur     = 0.15f;
        Vector3 current = transform.localScale;

        while (time < dur)
        {
            transform.localScale = Vector3.Lerp(current, _originalScale, time / dur);
            time += Time.deltaTime;
            yield return null;
        }
        transform.localScale = _originalScale;
    }

    // ─────────────────────────────────────────
    protected bool RaycastHitThis(Vector2 screenPosition)
    {
        if (cam == null) return false;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return false;
        return hit.collider.gameObject == gameObject;
    }

    // ─────────────────────────────────────────
    protected void BeginPress(Vector2 screenPosition)
    {
        isPressing       = true;
        pressStartTime   = Time.time;
        pressStartPos    = screenPosition;
        lastDragPos      = screenPosition;
        longPressHandled = false;
        isDragging       = false;
    }

    // ─────────────────────────────────────────
    protected void PlaySound()
    {
        if (data == null) return;
        PlaySoundConfig(data.soundConfig);
    }

    // ─────────────────────────────────────────
    protected IEnumerator ScaleEffect()
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

    // ─────────────────────────────────────────
    // SpawnPrefab — sans centrage (géré dans NodeTapDetector)
    // ─────────────────────────────────────────
    protected static GameObject SpawnPrefab(
        ImageCubeDataLibrary.ImageDataEntry entry,
        Camera usedCam)
    {
        bool  isAR = usedCam.GetComponent<UnityEngine.XR.ARFoundation.ARCameraBackground>() != null;
        float dist = isAR ? 0.4f : 0.4f;

        Vector3 screenCenter = new Vector3(Screen.width / 2f, Screen.height / 2f, dist);
        Vector3 spawnPos     = usedCam.ScreenToWorldPoint(screenCenter);

        Vector3    dir      = usedCam.transform.position - spawnPos;
        dir.y               = 0f;
        if (dir == Vector3.zero) dir = usedCam.transform.forward;
        Quaternion lookAt   = Quaternion.LookRotation(dir);
        Quaternion tilt     = Quaternion.Euler(-TiltTowardCamera, 0f, 0f);
        Quaternion spawnRot = lookAt * tilt;

        GameObject spawned  = Object.Instantiate(entry.prefabToSpawn, spawnPos, spawnRot);

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = entry.prefabToSpawn.transform.localScale;
        spawned.name                 = "Spawned_" + entry.imageName;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        return spawned;
    }
}
/*using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;

public abstract class BaseTapDetector : MonoBehaviour
{
    public Camera                              cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    protected const float LongPressDuration = 0.5f;
    protected const float DragThreshold     = 10f;
    protected const float TiltTowardCamera  = 15f;

    protected bool        isAnimating  = false;
    protected AudioSource audioSource;

    protected bool    isPressing       = false;
    protected float   pressStartTime   = 0f;
    protected bool    longPressHandled = false;
    protected Vector2 pressStartPos    = Vector2.zero;
    protected Vector2 lastDragPos      = Vector2.zero;
    protected bool    isDragging       = false;

    // ── Fix drag ──────────────────────────────
    protected float   _dragDepth       = 0f;
    protected Vector3 _originalScale   = Vector3.one;

    protected static GameObject _currentSpawned = null;
    protected static bool       _isSpawning     = false;

    protected virtual bool CanDrag()  => true;
    protected virtual bool CanScale() => true;

    // ─────────────────────────────────────────
    protected virtual void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;

        // Mémorise la scale originale
        _originalScale = transform.localScale;
    }

    // ─────────────────────────────────────────
    protected virtual void Update()
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

    // ─────────────────────────────────────────
    protected bool IsTapOnUI(Vector2 screenPosition)
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
            Debug.Log("🖱️ Tap sur UI : " + results[0].gameObject.name);
            return true;
        }
        return false;
    }

    // ─────────────────────────────────────────
    protected bool CheckOverlayButtons(Vector2 pos)
    {
        if (AROverlayUI.Instance == null) return false;

        if (AROverlayUI.Instance.IsTapOnCloseButton(pos))
        {
            Debug.Log("🔴 Tap Fermer");
            AROverlayUI.Instance.OnFermerPressed();
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnPhotoButton(pos))
        {
            Debug.Log("📷 Tap Photo");
            ScreenshotManager.Instance?.TakeAndSaveScreenshot();
            return true;
        }

        // ── Fix son : SoundConfig direct au lieu de TTS ──
        if (AROverlayUI.Instance.IsTapOnArabeButton(pos))
        {
            Debug.Log("🌐 Tap Arabe");
            PlaySoundConfig(data?.soundConfigArabe);
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnFrancaisButton(pos))
        {
            Debug.Log("🌐 Tap Français");
            PlaySoundConfig(data?.soundConfigFrancais);
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnAnglaisButton(pos))
        {
            Debug.Log("🌐 Tap Anglais");
            PlaySoundConfig(data?.soundConfigAnglais);
            return true;
        }

        return false;
    }

    // ─────────────────────────────────────────
    // Fix son : joue un SoundConfig directement
    // ─────────────────────────────────────────
    protected void PlaySoundConfig(SoundConfig config)
    {
        if (config == null || config.clip == null)
        {
            Debug.LogWarning("⚠️ SoundConfig absent ou clip NULL");
            return;
        }

        if (AudioManager.Instance != null)
        {
            AudioManager.Instance.Play(config);
            Debug.Log("🔊 AudioManager : " + config.clip.name);
        }
        else
        {
            if (!config.allowOverlap && audioSource.isPlaying) return;
            audioSource.clip   = config.clip;
            audioSource.volume = config.volume;
            audioSource.Play();
            Debug.Log("🔊 Fallback : " + config.clip.name);
        }
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressDown(Vector2 screenPosition);

    // ─────────────────────────────────────────
    // Fix drag : distance fixe + scale légère
    // ─────────────────────────────────────────
    protected virtual void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            // Mémorise la distance UNE SEULE FOIS au début du drag
            _dragDepth = Vector3.Distance(cam.transform.position, transform.position);
            Debug.Log("↔️ Drag : " + gameObject.name);
        }

        if (isDragging && CanDrag())
        {
            // Utilise _dragDepth fixe, pas recalculé
            Vector3 screenPos  = new Vector3(screenPosition.x, screenPosition.y, _dragDepth);
            transform.position = cam.ScreenToWorldPoint(screenPos);

            // Réduction scale légère pendant le drag
            Vector3 dragScale = _originalScale * 0.92f;
            transform.localScale = Vector3.Lerp(
                transform.localScale, dragScale, Time.deltaTime * 8f);
        }

        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                if (CanScale())
                {
                    Debug.Log("⏱️ Appui long → scale : " + gameObject.name);
                    if (!isAnimating) StartCoroutine(ScaleEffect());
                }
            }
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressUp(Vector2 screenPosition);

    // Restaure la scale après drag (à appeler dans OnPressUp)
    protected void RestoreScaleAfterDrag()
    {
        if (!isAnimating)
            StartCoroutine(RestoreScaleCoroutine());
    }

    private IEnumerator RestoreScaleCoroutine()
    {
        float   time    = 0f;
        float   dur     = 0.15f;
        Vector3 current = transform.localScale;

        while (time < dur)
        {
            transform.localScale = Vector3.Lerp(current, _originalScale, time / dur);
            time += Time.deltaTime;
            yield return null;
        }
        transform.localScale = _originalScale;
    }

    // ─────────────────────────────────────────
    protected bool RaycastHitThis(Vector2 screenPosition)
    {
        if (cam == null) return false;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return false;
        return hit.collider.gameObject == gameObject;
    }

    // ─────────────────────────────────────────
    protected void BeginPress(Vector2 screenPosition)
    {
        isPressing       = true;
        pressStartTime   = Time.time;
        pressStartPos    = screenPosition;
        lastDragPos      = screenPosition;
        longPressHandled = false;
        isDragging       = false;
    }

    // ─────────────────────────────────────────
    protected void PlaySound()
    {
        if (data == null) return;
        PlaySoundConfig(data.soundConfig);
    }

    // ─────────────────────────────────────────
    protected IEnumerator ScaleEffect()
    {
        if (data == null) { isAnimating = false; yield break; }

        isAnimating      = true;
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

    // ─────────────────────────────────────────
    protected static GameObject SpawnPrefab(
        ImageCubeDataLibrary.ImageDataEntry entry,
        Camera usedCam)
    {
        bool  isAR = usedCam.GetComponent<UnityEngine.XR.ARFoundation.ARCameraBackground>() != null;
        float dist = isAR ? 1.5f : 0.4f;

        Vector3 screenCenter = new Vector3(Screen.width / 2f, Screen.height / 2f, dist);
        Vector3 spawnPos     = usedCam.ScreenToWorldPoint(screenCenter);

        Vector3    dir      = usedCam.transform.position - spawnPos;
        dir.y               = 0f;
        if (dir == Vector3.zero) dir = usedCam.transform.forward;
        Quaternion lookAt   = Quaternion.LookRotation(dir);
        Quaternion tilt     = Quaternion.Euler(-TiltTowardCamera, 0f, 0f);
        Quaternion spawnRot = lookAt * tilt;

        GameObject spawned = Object.Instantiate(entry.prefabToSpawn, spawnPos, spawnRot);
        // ── Centrage automatique ──────────────────────────────
        Renderer[] renderers = spawned.GetComponentsInChildren<Renderer>();
        if (renderers.Length > 0)
        {
            // Calcule le vrai centre visuel du prefab
            Bounds bounds = renderers[0].bounds;
            foreach (Renderer r in renderers)
                bounds.Encapsulate(r.bounds);

            // Décalage entre le pivot actuel et le centre visuel
            Vector3 offset = spawned.transform.position - bounds.center;
            spawned.transform.position += offset;
        }
        // ─────────────────────────────────────────────────────


        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = entry.prefabToSpawn.transform.localScale;
        spawned.name                 = "Spawned_" + entry.imageName;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        return spawned;
    }
}
/*using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;

public abstract class BaseTapDetector : MonoBehaviour
{
    public Camera                              cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    protected const float LongPressDuration = 0.5f;
    protected const float DragThreshold     = 10f;
    protected const float TiltTowardCamera  = 15f;

    protected bool        isAnimating  = false;
    protected AudioSource audioSource;

    protected bool    isPressing       = false;
    protected float   pressStartTime   = 0f;
    protected bool    longPressHandled = false;
    protected Vector2 pressStartPos    = Vector2.zero;
    protected Vector2 lastDragPos      = Vector2.zero;
    protected bool    isDragging       = false;

    protected static GameObject _currentSpawned = null;
    protected static bool       _isSpawning     = false;

    protected virtual bool CanDrag()  => true;
    protected virtual bool CanScale() => true;

    // ─────────────────────────────────────────
    protected virtual void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    // ─────────────────────────────────────────
    protected virtual void Update()
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

    // ─────────────────────────────────────────
    protected bool IsTapOnUI(Vector2 screenPosition)
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
            Debug.Log("🖱️ Tap sur UI : " + results[0].gameObject.name);
            return true;
        }
        return false;
    }

    // ─────────────────────────────────────────
    //  TOUTE LA LOGIQUE DES BOUTONS ICI
    // ─────────────────────────────────────────
    protected bool CheckOverlayButtons(Vector2 pos)
    {
        if (AROverlayUI.Instance == null) return false;

        // ── Bouton Fermer ──────────────────────────────────────
        if (AROverlayUI.Instance.IsTapOnCloseButton(pos))
        {
            Debug.Log("🔴 Tap Fermer");
            AROverlayUI.Instance.OnFermerPressed();
            return true;
        }

        // ── Bouton Photo ───────────────────────────────────────
        if (AROverlayUI.Instance.IsTapOnPhotoButton(pos))
        {
            Debug.Log("📷 Tap Photo");
            ScreenshotManager.Instance?.TakeAndSaveScreenshot();
            return true;
        }

        // ── Bouton Arabe ───────────────────────────────────────
        if (AROverlayUI.Instance.IsTapOnArabeButton(pos))
        {
            Debug.Log("🌐 Tap Arabe");
            TTSLanguagePlayer.Instance?.PlayLangue(
                TTSLanguagePlayer.Langue.Arabe, data);
            return true;
        }

        // ── Bouton Français ────────────────────────────────────
        if (AROverlayUI.Instance.IsTapOnFrancaisButton(pos))
        {
            Debug.Log("🌐 Tap Français");
            TTSLanguagePlayer.Instance?.PlayLangue(
                TTSLanguagePlayer.Langue.Francais, data);
            return true;
        }

        // ── Bouton Anglais ─────────────────────────────────────
        if (AROverlayUI.Instance.IsTapOnAnglaisButton(pos))
        {
            Debug.Log("🌐 Tap Anglais");
            TTSLanguagePlayer.Instance?.PlayLangue(
                TTSLanguagePlayer.Langue.Anglais, data);
            return true;
        }

        return false;
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressDown(Vector2 screenPosition);

    // ─────────────────────────────────────────
    protected virtual void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            Debug.Log("↔️ Drag : " + gameObject.name);
        }

        if (isDragging && CanDrag())
        {
            float   dist      = Vector3.Distance(
                cam.transform.position, transform.position);
            Vector3 screenPos = new Vector3(screenPosition.x, screenPosition.y, dist);
            transform.position = cam.ScreenToWorldPoint(screenPos);
        }

        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                if (CanScale())
                {
                    Debug.Log("⏱️ Appui long → scale : " + gameObject.name);
                    if (!isAnimating) StartCoroutine(ScaleEffect());
                }
            }
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressUp(Vector2 screenPosition);

    // ─────────────────────────────────────────
    protected bool RaycastHitThis(Vector2 screenPosition)
    {
        if (cam == null) return false;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return false;
        return hit.collider.gameObject == gameObject;
    }

    // ─────────────────────────────────────────
    protected void BeginPress(Vector2 screenPosition)
    {
        isPressing       = true;
        pressStartTime   = Time.time;
        pressStartPos    = screenPosition;
        lastDragPos      = screenPosition;
        longPressHandled = false;
        isDragging       = false;
    }

    // ─────────────────────────────────────────
    protected void PlaySound()
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
            Debug.LogWarning("⚠️ Son absent pour : " + gameObject.name);
        }
    }

    // ─────────────────────────────────────────
    protected IEnumerator ScaleEffect()
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

    // ─────────────────────────────────────────
    protected static GameObject SpawnPrefab(
        ImageCubeDataLibrary.ImageDataEntry entry,
        Camera usedCam)
    {
        // Détection AR vs 3D
        bool isAR = usedCam.GetComponent<UnityEngine.XR.ARFoundation.ARCameraBackground>() != null;
        float dist = isAR ? 1.5f : 0.4f;

        Vector3 screenCenter = new Vector3(Screen.width / 2f, Screen.height / 2f, dist);
        Vector3 spawnPos     = usedCam.ScreenToWorldPoint(screenCenter);
        //float   dist         = 0.5f;
        //Vector3 screenCenter = new Vector3(
            //Screen.width / 2f, Screen.height / 2f, dist);
        //Vector3 spawnPos     = usedCam.ScreenToWorldPoint(screenCenter);

        Vector3    dir      = usedCam.transform.position - spawnPos;
        dir.y               = 0f;
        if (dir == Vector3.zero) dir = usedCam.transform.forward;
        Quaternion lookAt   = Quaternion.LookRotation(dir);
        Quaternion tilt     = Quaternion.Euler(-TiltTowardCamera, 0f, 0f);
        Quaternion spawnRot = lookAt * tilt;

        GameObject spawned  = Object.Instantiate(
            entry.prefabToSpawn, spawnPos, spawnRot);

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = entry.prefabToSpawn.transform.localScale;
        spawned.name                 = "Spawned_" + entry.imageName;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        return spawned;
    }
}
/*modification 23:13 27/04
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;

public abstract class BaseTapDetector : MonoBehaviour
{
    public Camera                              cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    protected const float LongPressDuration = 0.5f;
    protected const float DragThreshold     = 10f;
    protected const float TiltTowardCamera  = 15f;

    protected bool        isAnimating  = false;
    protected AudioSource audioSource;

    protected bool    isPressing       = false;
    protected float   pressStartTime   = 0f;
    protected bool    longPressHandled = false;
    protected Vector2 pressStartPos    = Vector2.zero;
    protected Vector2 lastDragPos      = Vector2.zero;
    protected bool    isDragging       = false;

    // ── Prefab actif centralisé ici pour toutes les sous-classes ──
    protected static GameObject _currentSpawned = null;
    protected static bool       _isSpawning     = false;

    // ─────────────────────────────────────────
    // Contrôle drag et scale — chaque sous-classe
    // décide si ces actions sont autorisées
    // ─────────────────────────────────────────
    protected virtual bool CanDrag()  => true;
    protected virtual bool CanScale() => true;

    // ─────────────────────────────────────────
    protected virtual void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    // ─────────────────────────────────────────
    protected virtual void Update()
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

    // ─────────────────────────────────────────
    protected bool IsTapOnUI(Vector2 screenPosition)
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
            Debug.Log("🖱️ Tap sur UI : " + results[0].gameObject.name);
            return true;
        }
        return false;
    }

    // ─────────────────────────────────────────
    protected bool CheckOverlayButtons(Vector2 screenPosition)
    {
        if (AROverlayUI.Instance == null) return false;

        if (AROverlayUI.Instance.IsTapOnLanguageButton(screenPosition))
        {
            Debug.Log("🌐 Tap bouton de langue");
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnCloseButton(screenPosition))
        {
            Debug.Log("🔴 Tap bouton Fermer");
            AROverlayUI.Instance.OnFermerPressed();
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnPhotoButton(screenPosition))
        {
            Debug.Log("📷 Tap bouton Photo");
            return true;
        }

        return false;
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressDown(Vector2 screenPosition);

    // ─────────────────────────────────────────
    // OnPressMoved dans la base — drag et scale
    // contrôlés par CanDrag() et CanScale()
    // plus besoin de l'override dans TapDetector1
    // ─────────────────────────────────────────
    protected virtual void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            Debug.Log("↔️ Drag : " + gameObject.name);
        }

        // Drag autorisé seulement si CanDrag() retourne true
        if (isDragging && CanDrag())
        {
            float   dist      = Vector3.Distance(
                cam.transform.position, transform.position);
            Vector3 screenPos = new Vector3(screenPosition.x, screenPosition.y, dist);
            transform.position = cam.ScreenToWorldPoint(screenPos);
        }

        // Scale autorisé seulement si CanScale() retourne true
        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                if (CanScale())
                {
                    Debug.Log("⏱️ Appui long → scale : " + gameObject.name);
                    if (!isAnimating) StartCoroutine(ScaleEffect());
                }
            }
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressUp(Vector2 screenPosition);

    // ─────────────────────────────────────────
    protected bool RaycastHitThis(Vector2 screenPosition)
    {
        if (cam == null) return false;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return false;
        return hit.collider.gameObject == gameObject;
    }

    // ─────────────────────────────────────────
    protected void BeginPress(Vector2 screenPosition)
    {
        isPressing       = true;
        pressStartTime   = Time.time;
        pressStartPos    = screenPosition;
        lastDragPos      = screenPosition;
        longPressHandled = false;
        isDragging       = false;
    }

    // ─────────────────────────────────────────
    protected void PlaySound()
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
            Debug.LogWarning("⚠️ Son absent pour : " + gameObject.name);
        }
    }

    // ─────────────────────────────────────────
    protected IEnumerator ScaleEffect()
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

    // ─────────────────────────────────────────
    protected static GameObject SpawnPrefab(
        ImageCubeDataLibrary.ImageDataEntry entry,
        Camera usedCam)
    {
        float   dist         = 0.5f;
        Vector3 screenCenter = new Vector3(
            Screen.width / 2f, Screen.height / 2f, dist);
        Vector3 spawnPos     = usedCam.ScreenToWorldPoint(screenCenter);

        Vector3    dir      = usedCam.transform.position - spawnPos;
        dir.y               = 0f;
        if (dir == Vector3.zero) dir = usedCam.transform.forward;
        Quaternion lookAt   = Quaternion.LookRotation(dir);
        Quaternion tilt     = Quaternion.Euler(-TiltTowardCamera, 0f, 0f);
        Quaternion spawnRot = lookAt * tilt;

        GameObject spawned  = Object.Instantiate(
            entry.prefabToSpawn, spawnPos, spawnRot);

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = entry.prefabToSpawn.transform.localScale;
        spawned.name                 = "Spawned_" + entry.imageName;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        return spawned;
    }
}
/*using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;

public abstract class BaseTapDetector : MonoBehaviour
{
    public Camera                              cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    protected const float LongPressDuration = 0.5f;
    protected const float DragThreshold     = 10f;
    protected const float TiltTowardCamera  = 15f;

    protected bool        isAnimating  = false;
    protected AudioSource audioSource;

    protected bool    isPressing       = false;
    protected float   pressStartTime   = 0f;
    protected bool    longPressHandled = false;
    protected Vector2 pressStartPos    = Vector2.zero;
    protected Vector2 lastDragPos      = Vector2.zero;
    protected bool    isDragging       = false;

    // ─────────────────────────────────────────
    protected virtual void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    // ─────────────────────────────────────────
    protected virtual void Update()
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

    // ─────────────────────────────────────────
    protected bool IsTapOnUI(Vector2 screenPosition)
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
            Debug.Log("🖱️ Tap sur UI : " + results[0].gameObject.name);
            return true;
        }
        return false;
    }

    // ─────────────────────────────────────────
    // Vérifie les boutons overlay EN PREMIER
    // Retourne true si un bouton overlay a été tappé
    protected bool CheckOverlayButtons(Vector2 screenPosition)
    {
        if (AROverlayUI.Instance == null) return false;

        if (AROverlayUI.Instance.IsTapOnLanguageButton(screenPosition))
        {
            Debug.Log("🌐 Tap bouton de langue");
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnCloseButton(screenPosition))
        {
            Debug.Log("🔴 Tap bouton Fermer");
            AROverlayUI.Instance.OnFermerPressed();
            return true;
        }

        if (AROverlayUI.Instance.IsTapOnPhotoButton(screenPosition))
        {
            Debug.Log("📷 Tap bouton Photo");
            return true;
        }

        return false;
    }

    // ─────────────────────────────────────────
    // Chaque sous-classe implémente sa propre logique de press
    protected abstract void OnPressDown(Vector2 screenPosition);

    // ─────────────────────────────────────────
    protected virtual void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            Debug.Log("↔️ Drag : " + gameObject.name);
        }

        if (isDragging)
        {
            float   dist      = Vector3.Distance(cam.transform.position, transform.position);
            Vector3 screenPos = new Vector3(screenPosition.x, screenPosition.y, dist);
            transform.position = cam.ScreenToWorldPoint(screenPos);
        }

        if (!isDragging && !longPressHandled)
        {
            if (Time.time - pressStartTime >= LongPressDuration)
            {
                longPressHandled = true;
                Debug.Log("⏱️ Appui long → scale : " + gameObject.name);
                if (!isAnimating) StartCoroutine(ScaleEffect());
            }
        }

        lastDragPos = screenPosition;
    }

    // ─────────────────────────────────────────
    protected abstract void OnPressUp(Vector2 screenPosition);

    // ─────────────────────────────────────────
    protected bool RaycastHitThis(Vector2 screenPosition)
    {
        if (cam == null) return false;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return false;
        return hit.collider.gameObject == gameObject;
    }

    // ─────────────────────────────────────────
    protected void BeginPress(Vector2 screenPosition)
    {
        isPressing       = true;
        pressStartTime   = Time.time;
        pressStartPos    = screenPosition;
        lastDragPos      = screenPosition;
        longPressHandled = false;
        isDragging       = false;
    }

    // ─────────────────────────────────────────
    protected void PlaySound()
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
            Debug.LogWarning("⚠️ Son absent pour : " + gameObject.name);
        }
    }

    // ─────────────────────────────────────────
    protected IEnumerator ScaleEffect()
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

    // ─────────────────────────────────────────
    protected static GameObject SpawnPrefab(
        ImageCubeDataLibrary.ImageDataEntry entry,
        Camera usedCam)
    {
        float   dist         = 0.5f;
        Vector3 screenCenter = new Vector3(
            Screen.width / 2f, Screen.height / 2f, dist);
        Vector3 spawnPos     = usedCam.ScreenToWorldPoint(screenCenter);

        Vector3    dir      = usedCam.transform.position - spawnPos;
        dir.y               = 0f;
        if (dir == Vector3.zero) dir = usedCam.transform.forward;
        Quaternion lookAt   = Quaternion.LookRotation(dir);
        Quaternion tilt     = Quaternion.Euler(-TiltTowardCamera, 0f, 0f);
        Quaternion spawnRot = lookAt * tilt;

        GameObject spawned  = Object.Instantiate(
            entry.prefabToSpawn, spawnPos, spawnRot);

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = entry.prefabToSpawn.transform.localScale;
        spawned.name                 = "Spawned_" + entry.imageName;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        return spawned;
    }
}*/