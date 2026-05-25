/*ajout de scaler et rotate env*/
using UnityEngine;

public class NodeTapDetector : BaseTapDetector
{
    protected override bool CanDrag()  => true;
    protected override bool CanScale() => true;

    private static GameObject _currentEnvironment = null;

    // ─────────────────────────────────────────
    protected override void OnPressDown(Vector2 screenPosition)
    {
        if (CheckOverlayButtons(screenPosition)) return;
        if (IsTapOnUI(screenPosition))           return;
        if (!RaycastHitThis(screenPosition))     return;

        BeginPress(screenPosition);
        Debug.Log("👇 Appui prefab map : " + gameObject.name);
    }

    // ─────────────────────────────────────────
    protected override void OnPressUp(Vector2 screenPosition)
    {
        if (!isPressing) return;
        float duration = Time.time - pressStartTime;
        isPressing     = false;

        if (isDragging)       { isDragging = false; RestoreScaleAfterDrag(); return; }
        if (longPressHandled) return;
        if (duration >= LongPressDuration) return;
        if (!RaycastHitThis(screenPosition)) return;

        Debug.Log("👆 Tap court map → son : " + gameObject.name);
        PlaySound();
    }

    // ─────────────────────────────────────────
    public static void SpawnFromEntry(
        ImageCubeDataLibrary.ImageDataEntry entry, Camera cam)
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (entry == null)               { Debug.LogWarning("⚠️ entry NULL");         return; }
        if (!entry.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");  return; }
        if (entry.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL"); return; }

        Camera usedCam = cam != null ? cam : Camera.main;
        if (usedCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        _isSpawning = true;
        GameObject spawned = SpawnPrefab(entry, usedCam);
        _isSpawning = false;

        NodeTapDetector tap = spawned.AddComponent<NodeTapDetector>();
        tap.cam             = usedCam;
        tap.data            = entry;

        _currentSpawned = spawned;

        // ── Environnement spawné depuis l'inspector ───────────
        SpawnEnvironment(entry, spawned.transform, usedCam);

        // ── Centrage APRÈS l'environnement ────────────────────
        Renderer[] renderers = spawned.GetComponentsInChildren<Renderer>();
        if (renderers.Length > 0)
        {
            Bounds bounds = renderers[0].bounds;
            foreach (Renderer r in renderers)
                bounds.Encapsulate(r.bounds);

            Vector3 offset = spawned.transform.position - bounds.center;
            spawned.transform.position += offset;
        }
        // ─────────────────────────────────────────────────────

        AROverlayUI.Instance?.SetFermerCallback(() => DestroyCurrentPrefab(0f));
        AROverlayUI.Instance?.EnterPrefabMode(showPhoto: false);

        Debug.Log("🐾 Prefab map spawné : " + spawned.name);
    }

    // ─────────────────────────────────────────
    static void SpawnEnvironment(
        ImageCubeDataLibrary.ImageDataEntry entry,
        Transform prefabTransform,
        Camera usedCam)
    {
        if (_currentEnvironment != null)
        {
            Object.Destroy(_currentEnvironment);
            _currentEnvironment = null;
        }

        if (entry.environmentPrefab == null)
        {
            Debug.Log("🌍 Pas d'environnement pour : " + entry.imageName);
            return;
        }

        // ── Position, rotation et scale lus depuis l'inspector du prefab ──
        Vector3    envPosition = entry.environmentPrefab.transform.position;
        Quaternion envRotation = entry.environmentPrefab.transform.rotation;
        Vector3    envScale    = entry.environmentPrefab.transform.localScale;

        _currentEnvironment      = Object.Instantiate(
            entry.environmentPrefab, envPosition, envRotation);
        _currentEnvironment.name = "Env_" + entry.imageName;

        // Respecte la scale de l'inspector
        _currentEnvironment.transform.localScale = envScale;

        foreach (Collider col in
            _currentEnvironment.GetComponentsInChildren<Collider>(true))
        {
            Object.Destroy(col);
            Debug.Log("🚫 Collider supprimé : " + col.gameObject.name);
        }

        foreach (Renderer rend in
            _currentEnvironment.GetComponentsInChildren<Renderer>(true))
        {
            foreach (Material mat in rend.materials)
                mat.renderQueue = 1999;

            rend.shadowCastingMode =
                UnityEngine.Rendering.ShadowCastingMode.Off;
            rend.receiveShadows = false;
        }

        foreach (Renderer rend in
            prefabTransform.GetComponentsInChildren<Renderer>(true))
        {
            foreach (Material mat in rend.materials)
                mat.renderQueue = 2001;
        }

        Debug.Log("🌍 Environnement spawné : " + _currentEnvironment.name
                + " | pos=" + envPosition
                + " | rot=" + envRotation.eulerAngles
                + " | scale=" + envScale);
    }

    // ─────────────────────────────────────────
    static Bounds GetBounds(GameObject go)
    {
        Renderer[] renderers = go.GetComponentsInChildren<Renderer>();

        if (renderers.Length == 0)
            return new Bounds(Vector3.zero, Vector3.zero);

        Bounds bounds = renderers[0].bounds;
        foreach (Renderer r in renderers)
            bounds.Encapsulate(r.bounds);

        return bounds;
    }

    // ─────────────────────────────────────────
    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ Destroy map : "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Object.Destroy(_currentSpawned, delay);
        _currentSpawned = null;

        if (_currentEnvironment != null)
            Object.Destroy(_currentEnvironment, delay);
        _currentEnvironment = null;

        AROverlayUI.Instance?.SetFermerCallback(null);
        AROverlayUI.Instance?.ExitPrefabMode();

        Debug.Log("🗑️ Prefab + environnement détruits");
    }
}
/*using UnityEngine;

public class NodeTapDetector : BaseTapDetector
{
    protected override bool CanDrag()  => true;
    protected override bool CanScale() => true;

    private static GameObject _currentEnvironment = null;

    // ─────────────────────────────────────────
    protected override void OnPressDown(Vector2 screenPosition)
    {
        if (CheckOverlayButtons(screenPosition)) return;
        if (IsTapOnUI(screenPosition))           return;
        if (!RaycastHitThis(screenPosition))     return;

        BeginPress(screenPosition);
        Debug.Log("👇 Appui prefab map : " + gameObject.name);
    }

    // ─────────────────────────────────────────
    protected override void OnPressUp(Vector2 screenPosition)
    {
        if (!isPressing) return;
        float duration = Time.time - pressStartTime;
        isPressing     = false;

        if (isDragging)       { isDragging = false; RestoreScaleAfterDrag(); return; }
        if (longPressHandled) return;
        if (duration >= LongPressDuration) return;
        if (!RaycastHitThis(screenPosition)) return;

        Debug.Log("👆 Tap court map → son : " + gameObject.name);
        PlaySound();
    }

    // ─────────────────────────────────────────
    public static void SpawnFromEntry(
        ImageCubeDataLibrary.ImageDataEntry entry, Camera cam)
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (entry == null)               { Debug.LogWarning("⚠️ entry NULL");         return; }
        if (!entry.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");  return; }
        if (entry.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL"); return; }

        Camera usedCam = cam != null ? cam : Camera.main;
        if (usedCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        _isSpawning = true;
        GameObject spawned = SpawnPrefab(entry, usedCam);
        _isSpawning = false;

        NodeTapDetector tap = spawned.AddComponent<NodeTapDetector>();
        tap.cam             = usedCam;
        tap.data            = entry;

        _currentSpawned = spawned;

        // ── Environnement spawné sur la position brute ────────
        SpawnEnvironment(entry, spawned.transform, usedCam);

        // ── Centrage APRÈS l'environnement ────────────────────
        Renderer[] renderers = spawned.GetComponentsInChildren<Renderer>();
        if (renderers.Length > 0)
        {
            Bounds bounds = renderers[0].bounds;
            foreach (Renderer r in renderers)
                bounds.Encapsulate(r.bounds);

            Vector3 offset = spawned.transform.position - bounds.center;
            spawned.transform.position += offset;
        }
        // ─────────────────────────────────────────────────────

        AROverlayUI.Instance?.SetFermerCallback(() => DestroyCurrentPrefab(0f));
        AROverlayUI.Instance?.EnterPrefabMode(showPhoto: false);

        Debug.Log("🐾 Prefab map spawné : " + spawned.name);
    }

    // ─────────────────────────────────────────
    static void SpawnEnvironment(
        ImageCubeDataLibrary.ImageDataEntry entry,
        Transform prefabTransform,
        Camera usedCam)
    {
        if (_currentEnvironment != null)
        {
            Object.Destroy(_currentEnvironment);
            _currentEnvironment = null;
        }

        if (entry.environmentPrefab == null)
        {
            Debug.Log("🌍 Pas d'environnement pour : " + entry.imageName);
            return;
        }

        Vector3 dirCamToPrefab = (prefabTransform.position
                                 - usedCam.transform.position).normalized;

        float   offsetBehind = 0.8f;
        Vector3 envPosition  = prefabTransform.position
                             + dirCamToPrefab * offsetBehind;

        Vector3    lookDir     = usedCam.transform.position - envPosition;
        Quaternion envRotation = Quaternion.LookRotation(-lookDir,
                                     usedCam.transform.up);

        _currentEnvironment      = Object.Instantiate(
            entry.environmentPrefab, envPosition, envRotation);
        _currentEnvironment.name = "Env_" + entry.imageName;

        foreach (Collider col in
            _currentEnvironment.GetComponentsInChildren<Collider>(true))
        {
            Object.Destroy(col);
            Debug.Log("🚫 Collider supprimé : " + col.gameObject.name);
        }

        float distToCam    = Vector3.Distance(envPosition, usedCam.transform.position);
        float screenHeight = 2f * distToCam
                           * Mathf.Tan(usedCam.fieldOfView * 0.5f * Mathf.Deg2Rad);
        float screenWidth  = screenHeight * usedCam.aspect;

        Bounds envBounds = GetBounds(_currentEnvironment);

        float finalScale;
        if (envBounds.size == Vector3.zero)
        {
            finalScale = Mathf.Max(screenWidth, screenHeight);
        }
        else
        {
            float scaleX = screenWidth  / envBounds.size.x;
            float scaleY = screenHeight / envBounds.size.y;
            finalScale   = Mathf.Max(scaleX, scaleY);
        }

        _currentEnvironment.transform.localScale = new Vector3(
            finalScale, finalScale, finalScale);

        foreach (Renderer rend in
            _currentEnvironment.GetComponentsInChildren<Renderer>(true))
        {
            foreach (Material mat in rend.materials)
                mat.renderQueue = 1999;

            rend.shadowCastingMode =
                UnityEngine.Rendering.ShadowCastingMode.Off;
            rend.receiveShadows = false;
        }

        foreach (Renderer rend in
            prefabTransform.GetComponentsInChildren<Renderer>(true))
        {
            foreach (Material mat in rend.materials)
                mat.renderQueue = 2001;
        }

        Debug.Log("🌍 Environnement spawné : " + _currentEnvironment.name
                + " | scale=" + _currentEnvironment.transform.localScale);
    }

    // ─────────────────────────────────────────
    static Bounds GetBounds(GameObject go)
    {
        Renderer[] renderers = go.GetComponentsInChildren<Renderer>();

        if (renderers.Length == 0)
            return new Bounds(Vector3.zero, Vector3.zero);

        Bounds bounds = renderers[0].bounds;
        foreach (Renderer r in renderers)
            bounds.Encapsulate(r.bounds);

        return bounds;
    }

    // ─────────────────────────────────────────
    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ Destroy map : "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Object.Destroy(_currentSpawned, delay);
        _currentSpawned = null;

        if (_currentEnvironment != null)
            Object.Destroy(_currentEnvironment, delay);
        _currentEnvironment = null;

        AROverlayUI.Instance?.SetFermerCallback(null);
        AROverlayUI.Instance?.ExitPrefabMode();

        Debug.Log("🗑️ Prefab + environnement détruits");
    }
}
/*using UnityEngine;

public class NodeTapDetector : BaseTapDetector
{
    protected override bool CanDrag()  => true;
    protected override bool CanScale() => true;

    private static GameObject _currentEnvironment = null;

    // ─────────────────────────────────────────
    protected override void OnPressDown(Vector2 screenPosition)
    {
        if (CheckOverlayButtons(screenPosition)) return;
        if (IsTapOnUI(screenPosition))           return;
        if (!RaycastHitThis(screenPosition))     return;

        BeginPress(screenPosition);
        Debug.Log("👇 Appui prefab map : " + gameObject.name);
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

        Debug.Log("👆 Tap court map → son : " + gameObject.name);
        PlaySound();
    }

    // ─────────────────────────────────────────
    public static void SpawnFromEntry(
        ImageCubeDataLibrary.ImageDataEntry entry, Camera cam)
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (entry == null)               { Debug.LogWarning("⚠️ entry NULL");         return; }
        if (!entry.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");  return; }
        if (entry.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL"); return; }

        Camera usedCam = cam != null ? cam : Camera.main;
        if (usedCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        _isSpawning = true;
        GameObject spawned = SpawnPrefab(entry, usedCam);
        _isSpawning = false;

        NodeTapDetector tap = spawned.AddComponent<NodeTapDetector>();
        tap.cam             = usedCam;
        tap.data            = entry;

        _currentSpawned = spawned;

        // Spawn environnement derrière le prefab
        SpawnEnvironment(entry, spawned.transform, usedCam);

        AROverlayUI.Instance?.SetFermerCallback(() => DestroyCurrentPrefab(0f));
        AROverlayUI.Instance?.EnterPrefabMode(showPhoto: false);

        Debug.Log("🐾 Prefab map spawné : " + spawned.name);
    }

    // ─────────────────────────────────────────
    static void SpawnEnvironment(
        ImageCubeDataLibrary.ImageDataEntry entry,
        Transform prefabTransform,
        Camera usedCam)
    {
        // Détruit l'ancien environnement
        if (_currentEnvironment != null)
        {
            Object.Destroy(_currentEnvironment);
            _currentEnvironment = null;
        }

        if (entry.environmentPrefab == null)
        {
            Debug.Log("🌍 Pas d'environnement pour : " + entry.imageName);
            return;
        }

        // ── Position ───────────────────────────────────────────
        // Direction caméra → prefab
        Vector3 dirCamToPrefab = (prefabTransform.position
                                 - usedCam.transform.position).normalized;

        // Place l'environnement derrière le prefab
        float   offsetBehind = 0.8f;
        Vector3 envPosition  = prefabTransform.position
                             + dirCamToPrefab * offsetBehind;

        // ── Rotation — vertical face à la caméra ──────────────
        Vector3    lookDir     = usedCam.transform.position - envPosition;
        Quaternion envRotation = Quaternion.LookRotation(-lookDir,
                                     usedCam.transform.up);

        // ── Instanciation ──────────────────────────────────────
        _currentEnvironment      = Object.Instantiate(
            entry.environmentPrefab, envPosition, envRotation);
        _currentEnvironment.name = "Env_" + entry.imageName;

        // ── Supprime TOUS les colliders ────────────────────────
        foreach (Collider col in
            _currentEnvironment.GetComponentsInChildren<Collider>(true))
        {
            Object.Destroy(col);
            Debug.Log("🚫 Collider supprimé : " + col.gameObject.name);
        }

        // ── Scale pour couvrir l'écran ─────────────────────────
        float distToCam    = Vector3.Distance(
            envPosition, usedCam.transform.position);
        float screenHeight = 2f * distToCam
                           * Mathf.Tan(usedCam.fieldOfView
                           * 0.5f * Mathf.Deg2Rad);
        float screenWidth  = screenHeight * usedCam.aspect;

        Bounds envBounds = GetBounds(_currentEnvironment);

        float finalScale;
        if (envBounds.size == Vector3.zero)
        {
            finalScale = Mathf.Max(screenWidth, screenHeight);
        }
        else
        {
            float scaleX = screenWidth  / envBounds.size.x;
            float scaleY = screenHeight / envBounds.size.y;
            finalScale   = Mathf.Max(scaleX, scaleY);
        }

        _currentEnvironment.transform.localScale = new Vector3(
            finalScale, finalScale, finalScale);

        // ── Render order — environnement DERRIÈRE le prefab ───
        // renderQueue 1999 = rendu avant le prefab = apparaît derrière
        foreach (Renderer rend in
            _currentEnvironment.GetComponentsInChildren<Renderer>(true))
        {
            foreach (Material mat in rend.materials)
                mat.renderQueue = 1999;

            rend.shadowCastingMode =
                UnityEngine.Rendering.ShadowCastingMode.Off;
            rend.receiveShadows    = false;
        }

        // renderQueue 2001 = rendu après l'environnement = apparaît devant
        foreach (Renderer rend in
            prefabTransform.GetComponentsInChildren<Renderer>(true))
        {
            foreach (Material mat in rend.materials)
                mat.renderQueue = 2001;
        }

        Debug.Log("🌍 Environnement spawné : " + _currentEnvironment.name
                + " | scale=" + _currentEnvironment.transform.localScale);
    }

    // ─────────────────────────────────────────
    // Calcule le bounds total de tous les Renderers
    // ─────────────────────────────────────────
    static Bounds GetBounds(GameObject go)
    {
        Renderer[] renderers = go.GetComponentsInChildren<Renderer>();

        if (renderers.Length == 0)
            return new Bounds(Vector3.zero, Vector3.zero);

        Bounds bounds = renderers[0].bounds;
        foreach (Renderer r in renderers)
            bounds.Encapsulate(r.bounds);

        return bounds;
    }

    // ─────────────────────────────────────────
    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ Destroy map : "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Object.Destroy(_currentSpawned, delay);
        _currentSpawned = null;

        if (_currentEnvironment != null)
            Object.Destroy(_currentEnvironment, delay);
        _currentEnvironment = null;

        AROverlayUI.Instance?.SetFermerCallback(null);
        AROverlayUI.Instance?.ExitPrefabMode();

        Debug.Log("🗑️ Prefab + environnement détruits");
    }
}
/*using UnityEngine;

public class NodeTapDetector : BaseTapDetector
{
    protected override bool CanDrag()  => true;
    protected override bool CanScale() => true;

    // ─────────────────────────────────────────
    protected override void OnPressDown(Vector2 screenPosition)
    {
        if (CheckOverlayButtons(screenPosition)) return;
        if (IsTapOnUI(screenPosition))           return;
        if (!RaycastHitThis(screenPosition))     return;

        BeginPress(screenPosition);
        Debug.Log("👇 Appui prefab map : " + gameObject.name);
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

        Debug.Log("👆 Tap court map → son : " + gameObject.name);
        PlaySound();
    }

    // ─────────────────────────────────────────
    public static void SpawnFromEntry(
        ImageCubeDataLibrary.ImageDataEntry entry, Camera cam)
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (entry == null)               { Debug.LogWarning("⚠️ entry NULL");         return; }
        if (!entry.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");  return; }
        if (entry.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL"); return; }

        Camera usedCam = cam != null ? cam : Camera.main;
        if (usedCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        _isSpawning = true;
        GameObject spawned = SpawnPrefab(entry, usedCam);
        _isSpawning = false;

        NodeTapDetector tap = spawned.AddComponent<NodeTapDetector>();
        tap.cam             = usedCam;
        tap.data            = entry;

        _currentSpawned = spawned;

        AROverlayUI.Instance?.SetFermerCallback(() => DestroyCurrentPrefab(0f));
        AROverlayUI.Instance?.EnterPrefabMode(showPhoto: false);

        Debug.Log("🐾 Prefab map spawné : " + spawned.name);
    }

    // ─────────────────────────────────────────
    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ Destroy map : "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Object.Destroy(_currentSpawned, delay);

        _currentSpawned = null;

        AROverlayUI.Instance?.SetFermerCallback(null);
        AROverlayUI.Instance?.ExitPrefabMode();

        Debug.Log("🗑️ Prefab map détruit + UI restaurée");
    }
}
/*modification 23:13 27/04
using UnityEngine;

public class NodeTapDetector : BaseTapDetector
{
    // CanDrag et CanScale toujours true — toujours sur un prefab
    protected override bool CanDrag()  => true;
    protected override bool CanScale() => true;

    // ─────────────────────────────────────────
    protected override void OnPressDown(Vector2 screenPosition)
    {
        if (CheckOverlayButtons(screenPosition)) return;
        if (IsTapOnUI(screenPosition))           return;
        if (!RaycastHitThis(screenPosition))     return;

        BeginPress(screenPosition);
        Debug.Log("👇 Appui prefab map : " + gameObject.name);
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

        Debug.Log("👆 Tap court map → son : " + gameObject.name);
        PlaySound();
    }

    // ─────────────────────────────────────────
    public static void SpawnFromEntry(
        ImageCubeDataLibrary.ImageDataEntry entry, Camera cam)
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (entry == null)               { Debug.LogWarning("⚠️ entry NULL");         return; }
        if (!entry.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");  return; }
        if (entry.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL"); return; }

        Camera usedCam = cam != null ? cam : Camera.main;
        if (usedCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        _isSpawning = true;
        GameObject spawned = SpawnPrefab(entry, usedCam);
        _isSpawning = false;

        NodeTapDetector tap = spawned.AddComponent<NodeTapDetector>();
        tap.cam             = usedCam;
        tap.data            = entry;

        _currentSpawned = spawned;

        AROverlayUI.Instance?.SetFermerCallback(() => DestroyCurrentPrefab(0f));
        AROverlayUI.Instance?.SetCurrentData(entry);

        // showPhoto = false car scène Map
        AROverlayUI.Instance?.EnterPrefabMode(showPhoto: false);

        Debug.Log("🐾 Prefab map spawné : " + spawned.name);
    }

    // ─────────────────────────────────────────
    public static void DestroyCurrentPrefab(float delay = 0f)
    {
        Debug.Log("🗑️ Destroy map : "
                + (_currentSpawned != null ? _currentSpawned.name : "NULL"));

        if (_currentSpawned != null)
            Object.Destroy(_currentSpawned, delay);

        _currentSpawned = null;

        AROverlayUI.Instance?.SetFermerCallback(null);
        AROverlayUI.Instance?.ExitPrefabMode();

        Debug.Log("🗑️ Prefab map détruit + UI restaurée");
    }
}
/*using UnityEngine;
using System.Collections;

public class NodeTapDetector : BaseTapDetector
{
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
        Debug.Log("👇 Appui sur prefab : " + gameObject.name);
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

        Debug.Log("👆 Tap court → son : " + gameObject.name);
        PlaySound();
    }

    // ─────────────────────────────────────────
    public static void SpawnFromEntry(
        ImageCubeDataLibrary.ImageDataEntry entry, Camera cam)
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (entry == null)               { Debug.LogWarning("⚠️ entry NULL");         return; }
        if (!entry.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");  return; }
        if (entry.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL"); return; }

        Camera usedCam = cam != null ? cam : Camera.main;
        if (usedCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        _isSpawning = true;
        GameObject spawned = SpawnPrefab(entry, usedCam);
        _isSpawning = false;

        NodeTapDetector tap = spawned.AddComponent<NodeTapDetector>();
        tap.cam             = usedCam;
        tap.data            = entry;

        _currentSpawned = spawned;

        AROverlayUI.Instance?.SetFermerCallback(() => DestroyCurrentPrefab(0f));
        AROverlayUI.Instance?.SetCurrentData(entry);
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
            Object.Destroy(_currentSpawned, delay);

        _currentSpawned = null;

        AROverlayUI.Instance?.SetFermerCallback(null);
        AROverlayUI.Instance?.ExitPrefabMode();

        Debug.Log("🗑️ Prefab détruit + UI restaurée");
    }
}
/*using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;

public class NodeTapDetector : MonoBehaviour
{
    public Camera                              cam;
    public ImageCubeDataLibrary.ImageDataEntry data;

    private const float LongPressDuration = 0.5f;
    private const float DragThreshold     = 10f;
    private const float TiltTowardCamera  = 15f;

    private bool        isAnimating  = false;
    private AudioSource audioSource;

    private bool    isPressing       = false;
    private float   pressStartTime   = 0f;
    private bool    longPressHandled = false;
    private Vector2 pressStartPos    = Vector2.zero;
    private Vector2 lastDragPos      = Vector2.zero;
    private bool    isDragging       = false;

    private static GameObject _currentSpawned = null;
    private static bool       _isSpawning     = false;

    // ─────────────────────────────────────────
    void Start()
    {
        audioSource             = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    // ─────────────────────────────────────────
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

    // ─────────────────────────────────────────
    bool IsTapOnUI(Vector2 screenPosition)
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
    void OnPressDown(Vector2 screenPosition)
    {
        // ── 1. Boutons de langue EN PREMIER ───────────────────────
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnLanguageButton(screenPosition))
        {
            Debug.Log("🌐 Tap bouton de langue");
            return;
        }

        // ── 2. Bouton Fermer ───────────────────────────────────────
        if (AROverlayUI.Instance != null &&
            AROverlayUI.Instance.IsTapOnCloseButton(screenPosition))
        {
            Debug.Log("🔴 Tap bouton Fermer");
            AROverlayUI.Instance.OnFermerPressed();
            return;
        }

        // ── 3. Tap sur UI Unity ────────────────────────────────────
        if (IsTapOnUI(screenPosition)) return;

        // ── 4. Raycast 3D sur le prefab ───────────────────────────
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

        Debug.Log("👇 Appui sur prefab : " + gameObject.name);
    }

    // ─────────────────────────────────────────
    void OnPressMoved(Vector2 screenPosition)
    {
        if (!isPressing) return;

        float movedTotal = Vector2.Distance(screenPosition, pressStartPos);

        if (!isDragging && movedTotal > DragThreshold)
        {
            isDragging       = true;
            longPressHandled = true;
            Debug.Log("↔️ Drag prefab : " + gameObject.name);
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
    void OnPressUp(Vector2 screenPosition)
    {
        if (!isPressing) return;
        float duration = Time.time - pressStartTime;
        isPressing     = false;

        if (isDragging)       { isDragging = false; return; }
        if (longPressHandled) return;
        if (duration >= LongPressDuration) return;

        if (cam == null) return;
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (!Physics.Raycast(ray, out RaycastHit hit)) return;
        if (hit.collider.gameObject != gameObject) return;

        Debug.Log("👆 Tap court → son : " + gameObject.name);
        PlaySound();
    }

    // ─────────────────────────────────────────
    //  SPAWN
    // ─────────────────────────────────────────
    public static void SpawnFromEntry(ImageCubeDataLibrary.ImageDataEntry entry, Camera cam)
    {
        if (_currentSpawned != null || _isSpawning)
        {
            Debug.Log("⛔ Spawn ignoré : prefab déjà actif.");
            return;
        }

        if (entry == null)               { Debug.LogWarning("⚠️ entry NULL");         return; }
        if (!entry.doSpawn)              { Debug.LogWarning("⚠️ doSpawn désactivé");  return; }
        if (entry.prefabToSpawn == null) { Debug.LogWarning("⚠️ prefabToSpawn NULL"); return; }

        Camera usedCam = cam != null ? cam : Camera.main;
        if (usedCam == null) { Debug.LogError("❌ Aucune caméra !"); return; }

        float   dist         = 0.5f;
        Vector3 screenCenter = new Vector3(Screen.width / 2f, Screen.height / 2f, dist);
        Vector3 spawnPos     = usedCam.ScreenToWorldPoint(screenCenter);

        Vector3    dir      = usedCam.transform.position - spawnPos;
        dir.y               = 0f;
        if (dir == Vector3.zero) dir = usedCam.transform.forward;
        Quaternion lookAt   = Quaternion.LookRotation(dir);
        Quaternion tilt     = Quaternion.Euler(-TiltTowardCamera, 0f, 0f);
        Quaternion spawnRot = lookAt * tilt;

        _isSpawning = true;
        GameObject spawned = Object.Instantiate(entry.prefabToSpawn, spawnPos, spawnRot);
        _isSpawning = false;

        Rigidbody rb = spawned.GetComponent<Rigidbody>();
        if (rb != null) { rb.isKinematic = true; rb.useGravity = false; }

        spawned.transform.localScale = entry.prefabToSpawn.transform.localScale;
        spawned.name                 = "Spawned_" + entry.imageName;

        if (spawned.GetComponent<Collider>() == null)
            spawned.AddComponent<BoxCollider>();

        NodeTapDetector tap = spawned.AddComponent<NodeTapDetector>();
        tap.cam             = usedCam;
        tap.data            = entry;

        _currentSpawned = spawned;

        // Callback Fermer → cette scène
        AROverlayUI.Instance?.SetFermerCallback(() => DestroyCurrentPrefab(0f));
        AROverlayUI.Instance?.SetCurrentData(entry);

        // EnterPrefabMode sans bouton photo
        AROverlayUI.Instance?.EnterPrefabMode();
        AROverlayUI.Instance?.ShowCloseButton(true, false);

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
            Object.Destroy(_currentSpawned, delay);

        _currentSpawned = null;

        // Remettre callback null → scène AR reprend comportement par défaut
        AROverlayUI.Instance?.SetFermerCallback(null);
        AROverlayUI.Instance?.ExitPrefabMode();

        Debug.Log("🗑️ Prefab détruit + UI restaurée");
    }

    // ─────────────────────────────────────────
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
            Debug.LogWarning("⚠️ Son absent pour : " + gameObject.name);
        }
    }

    // ─────────────────────────────────────────
    IEnumerator ScaleEffect()
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
}*/