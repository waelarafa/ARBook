/*version 08/04 fix*/
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