using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.Collections.Generic;

public class ARImageCubeOverlay : MonoBehaviour
{
    // ═══════════════════════════════════════════════════════════
    // CHAMPS INSPECTEUR
    // ═══════════════════════════════════════════════════════════

    [Header("Paramètres du cube")]
    [SerializeField] private float cubeHeight = 0.002f;
    [SerializeField] private float cubeSizeMultiplier = 0.8f;

    [Header("Liaison Book1Detector")]
    [SerializeField] private Book1Detector libraryTester;

    [Header("Mapping Image → CubeActionData")]
    [SerializeField] private ImageCubeDataLibrary cubeDataLibrary;
    //particules 
    [Header("Effets")]
    [SerializeField] private GameObject particlePrefab;

    // ═══════════════════════════════════════════════════════════
    // VARIABLES PRIVÉES
    // ═══════════════════════════════════════════════════════════

    private Camera xrCamera;
    private ARTrackedImageManager trackedImageManager;

    private readonly Dictionary<TrackableId, GameObject> spawnedCubes
        = new Dictionary<TrackableId, GameObject>();

    // Flag — true quand un prefab est actif
    // bloque toute réactivation automatique des cubes par le tracking AR
    private bool cubesHidden = false;

    // ═══════════════════════════════════════════════════════════
    // CYCLE DE VIE UNITY
    // ═══════════════════════════════════════════════════════════

    void Awake()
    {
        Debug.Log("🔄 [AWAKE] Démarrage initialisation...");

        trackedImageManager = FindFirstObjectByType<ARTrackedImageManager>();
        if (trackedImageManager == null)
            Debug.LogError("❌ [AWAKE] ARTrackedImageManager introuvable !");
        else
            Debug.Log("✅ [AWAKE] ARTrackedImageManager trouvé");

        GameObject xrOrigin = GameObject.Find("XR Origin (Mobile AR)");
        if (xrOrigin == null) { Debug.LogError("❌ [AWAKE] XR Origin introuvable !"); return; }
        else Debug.Log("✅ [AWAKE] XR Origin trouvé");

        Transform cameraOffset = xrOrigin.transform.Find("Camera Offset");
        if (cameraOffset == null) { Debug.LogError("❌ [AWAKE] Camera Offset introuvable !"); return; }
        else Debug.Log("✅ [AWAKE] Camera Offset trouvé");

        Transform mainCamTransform = cameraOffset.Find("Main Camera");
        if (mainCamTransform == null) { Debug.LogError("❌ [AWAKE] Main Camera introuvable !"); return; }
        else Debug.Log("✅ [AWAKE] Main Camera trouvée");

        xrCamera = mainCamTransform.GetComponent<Camera>();
        if (xrCamera == null) { Debug.LogError("❌ [AWAKE] Composant Camera introuvable !"); return; }
        else Debug.Log("✅ [AWAKE] Composant Camera trouvé : " + xrCamera.name);

        Debug.Log("✅ [AWAKE] Initialisation complète");
    }

    void Start()
    {
        Debug.Log("✅ [START] ARImageCubeOverlay démarré");

        if (libraryTester == null)
            Debug.LogWarning("⚠️ [START] libraryTester non assigné !");
        else
            Debug.Log("✅ [START] libraryTester assigné : " + libraryTester.name);

        if (cubeDataLibrary == null)
            Debug.LogWarning("⚠️ [START] cubeDataLibrary non assigné !");
        else
            Debug.Log("✅ [START] cubeDataLibrary assigné : " + cubeDataLibrary.name);
    }

    void OnEnable()
    {
        Debug.Log("🔄 [ONENABLE] Tentative d'abonnement au listener...");

        if (trackedImageManager != null)
        {
            trackedImageManager.trackablesChanged.AddListener(OnTrackedImagesChanged);
            Debug.Log("✅ [ONENABLE] Listener ajouté avec succès");
        }
        else
        {
            Debug.LogWarning("⚠️ [ONENABLE] trackedImageManager null — listener non ajouté !");
        }
    }

    void OnDisable()
    {
        Debug.Log("🔄 [ONDISABLE] Désabonnement du listener...");

        if (trackedImageManager != null)
        {
            trackedImageManager.trackablesChanged.RemoveListener(OnTrackedImagesChanged);
            Debug.Log("✅ [ONDISABLE] Listener retiré");
        }
    }

    // ═══════════════════════════════════════════════════════════
    // GESTION DES EVENTS AR
    // ═══════════════════════════════════════════════════════════

    void OnTrackedImagesChanged(ARTrackablesChangedEventArgs<ARTrackedImage> eventArgs)
    {
        foreach (ARTrackedImage image in eventArgs.added)
        {
            Debug.Log("🖼️ [ADDED] Nouvelle image détectée : " + image.referenceImage.name
                + " | ID : " + image.trackableId);
            SpawnCubeOnImage(image);
        }

        foreach (ARTrackedImage image in eventArgs.updated)
        {
            TrackableId id = image.trackableId;

            if (image.trackingState == TrackingState.Tracking)
            {
                SpawnCubeOnImage(image);
                UpdateCubeTransform(image);

                // Ne réactive le cube que si aucun prefab n'est actif
                // cubesHidden = true → on ne touche pas aux cubes
                if (spawnedCubes.ContainsKey(id) && !cubesHidden)
                    spawnedCubes[id].SetActive(true);
            }
            else
            {
                // Image perdue — on cache le cube
                if (spawnedCubes.ContainsKey(id) && spawnedCubes[id] != null)
                {
                    spawnedCubes[id].SetActive(false);
                    Debug.Log("👁️ [UPDATED] Image perdue — cube caché : "
                        + image.referenceImage.name);
                }
            }
        }
    }

    // ═══════════════════════════════════════════════════════════
    // CRÉATION DU CUBE
    // ═══════════════════════════════════════════════════════════

    void SpawnCubeOnImage(ARTrackedImage image)
    {
        TrackableId id        = image.trackableId;
        string      imageName = image.referenceImage.name;

        Debug.Log("🔄 [SPAWN] Tentative spawn pour : " + imageName);

        // Filtre 1 : images commençant par 'F'
        if (imageName.StartsWith("F"))
        {
            Debug.Log("🚫 [SPAWN] Image ignorée (commence par 'F') : " + imageName);
            return;
        }

        // Filtre 2 : vérification validité Book1Detector
        if (libraryTester != null && !libraryTester.imagesValidees.Contains(imageName))
        {
            Debug.Log("🚫 [SPAWN] Image non validée par Book1Detector : " + imageName);
            return;
        }

        Debug.Log("✅ [SPAWN] Image validée — spawn autorisé pour : " + imageName);

        // Cube déjà existant → réactivation uniquement si cubes non cachés
        if (spawnedCubes.ContainsKey(id))
        {
            Debug.Log("♻️ [SPAWN] Cube déjà existant — réactivation pour : " + imageName);
            if (!cubesHidden)
                spawnedCubes[id].SetActive(true);
            UpdateCubeTransform(image);
            return;
        }

        // ── Création du cube primitif ──────────────────────────
        Debug.Log("🔄 [SPAWN] Création du cube primitif...");
        GameObject cube = GameObject.CreatePrimitive(PrimitiveType.Cube);
        cube.name = "Cube_" + imageName + "_" + id;
        Debug.Log("✅ [SPAWN] Cube primitif créé : " + cube.name);

        // ── Chargement texture + création material URP/Lit ─────
        Debug.Log("🔄 [SPAWN] Chargement texture depuis Resources/ : " + imageName);
        Texture2D texture = Resources.Load<Texture2D>(imageName);

        if (texture != null)
        {
            Debug.Log("✅ [SPAWN] Texture trouvée : " + imageName
                + " | Taille : " + texture.width + "x" + texture.height);

            Shader shader = Shader.Find("Universal Render Pipeline/Lit");

            if (shader == null)
            {
                Debug.LogError("❌ [SPAWN] Shader URP/Lit introuvable !");
            }
            else
            {
                Material mat = new Material(shader);
                mat.SetTexture("_BaseMap", texture);
                cube.GetComponent<MeshRenderer>().material = mat;
                Debug.Log("✅ [SPAWN] Material URP/Lit + texture appliqués");
            }
        }
        else
        {
            Debug.LogError("❌ [SPAWN] Texture introuvable dans Resources/ pour : " + imageName);
        }

        // ── BoxCollider ────────────────────────────────────────
        BoxCollider col = cube.GetComponent<BoxCollider>();
        if (col != null)
        {
            col.size = Vector3.one;
            Debug.Log("✅ [SPAWN] BoxCollider configuré");
        }
        else
        {
            Debug.LogError("❌ [SPAWN] BoxCollider introuvable !");
        }

        // ── TapDetector ────────────────────────────────────────
        Debug.Log("🔄 [SPAWN] Ajout TapDetector1...");
        TapDetector1 tap    = cube.AddComponent<TapDetector1>();
        tap.cam             = xrCamera;
        tap.data            = cubeDataLibrary?.GetEntryForImage(imageName);
        tap.isSpawnedPrefab = false;
        tap.trackedImage    = image;
        tap.isValidated     = true;

        if (tap.cam == null)
            Debug.LogError("❌ [SPAWN] TapDetector — caméra null !");
        else
            Debug.Log("✅ [SPAWN] TapDetector1 ajouté — caméra : " + tap.cam.name);

        // Si cubes cachés, on cache immédiatement le nouveau cube aussi
        if (cubesHidden)
            cube.SetActive(false);

        spawnedCubes[id] = cube;
        // ── Particules ─────────────────────────────────────────
        if (particlePrefab != null)
        {
            GameObject particles = Instantiate(particlePrefab, cube.transform);
            particles.transform.localPosition = new Vector3(0f,2f, 0f);

            Debug.Log("✨ [SPAWN] Particules attachées au cube : " + imageName);
        }
        UpdateCubeTransform(image);

        Debug.Log("📦 [SPAWN] Cube entièrement créé et positionné pour : " + imageName);
    }

    // ═══════════════════════════════════════════════════════════
    // MISE À JOUR DES TRANSFORMS
    // ═══════════════════════════════════════════════════════════

    void UpdateCubeTransform(ARTrackedImage image)
    {
        TrackableId id = image.trackableId;
        if (!spawnedCubes.ContainsKey(id))
        {
            Debug.LogWarning("⚠️ [UPDATE] Cube introuvable pour UpdateCubeTransform : "
                + image.referenceImage.name);
            return;
        }

        GameObject cube      = spawnedCubes[id];
        Vector2    imageSize = image.size;

        cube.transform.localScale = new Vector3(
            imageSize.x * cubeSizeMultiplier,
            cubeHeight,
            imageSize.y * cubeSizeMultiplier);

        cube.transform.position = image.transform.position
                                + image.transform.up * (cubeHeight / 2f);
        cube.transform.rotation = image.transform.rotation;

        // Correction inversion image
        cube.transform.Rotate(0f, 180f, 0f);
    }

    // ═══════════════════════════════════════════════════════════
    // MÉTHODES PUBLIQUES — HIDE / SHOW CUBES
    // ═══════════════════════════════════════════════════════════

    // Cache tous les cubes — appelé quand un prefab spawne
    // Active le flag cubesHidden pour bloquer toute réactivation AR
    public void HideAllCubes()
    {
        cubesHidden = true;
        foreach (var kvp in spawnedCubes)
            if (kvp.Value != null)
                kvp.Value.SetActive(false);

        Debug.Log("🙈 [HIDE] Tous les cubes cachés — flag cubesHidden = true");
    }

    // Réaffiche tous les cubes — appelé quand on ferme le prefab
    // Désactive le flag cubesHidden pour permettre la réactivation AR
    public void ShowAllCubes()
    {
        cubesHidden = false;
        foreach (var kvp in spawnedCubes)
            if (kvp.Value != null)
                kvp.Value.SetActive(true);

        Debug.Log("👁️ [SHOW] Tous les cubes réaffichés — flag cubesHidden = false");
    }

    // ═══════════════════════════════════════════════════════════
    // MÉTHODES PUBLIQUES UTILITAIRES
    // ═══════════════════════════════════════════════════════════

    public GameObject GetCubeForImage(string imageName)
    {
        Debug.Log("🔍 [GET] Recherche cube pour : " + imageName);
        foreach (var kvp in spawnedCubes)
        {
            if (kvp.Value != null &&
                kvp.Value.name.StartsWith("Cube_" + imageName + "_"))
            {
                Debug.Log("✅ [GET] Cube trouvé : " + kvp.Value.name);
                return kvp.Value;
            }
        }
        Debug.LogWarning("⚠️ [GET] Aucun cube trouvé pour : " + imageName);
        return null;
    }

    public void ClearAllCubes()
    {
        Debug.Log("🔄 [CLEAR] Suppression de " + spawnedCubes.Count + " cubes...");
        foreach (var kvp in spawnedCubes)
            if (kvp.Value != null) Destroy(kvp.Value);

        spawnedCubes.Clear();
        Debug.Log("✅ [CLEAR] Tous les cubes supprimés");
    }

    public void RespawnCubesForActiveTrackables()
    {
        Debug.Log("🔄 [RESPAWN] Début respawn...");

        if (trackedImageManager == null)
        {
            Debug.LogError("❌ [RESPAWN] trackedImageManager null !");
            return;
        }

        int count = 0;
        foreach (ARTrackedImage image in trackedImageManager.trackables)
        {
            if (image.trackingState == TrackingState.Tracking ||
                image.trackingState == TrackingState.Limited)
            {
                SpawnCubeOnImage(image);
                count++;
            }
        }
        Debug.Log("✅ [RESPAWN] Respawn terminé pour " + count + " trackables");
    }
}
/************version valide avec assignation de material au cube
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.Collections.Generic;

public class ARImageCubeOverlay : MonoBehaviour
{
    [Header("Paramètres du cube")]
    [SerializeField] private float cubeHeight = 0.005f;
    [SerializeField] private Material cubeMaterial; // Material assigné depuis l'inspecteur

    [Header("Liaison Book1Detector")]
    [SerializeField] private Book1Detector libraryTester;

    [Header("Mapping Image → CubeActionData")]
    [SerializeField] private ImageCubeDataLibrary cubeDataLibrary;

    private Camera xrCamera;
    private ARTrackedImageManager trackedImageManager;

    private readonly Dictionary<TrackableId, GameObject> spawnedCubes
        = new Dictionary<TrackableId, GameObject>();

    void Awake()
    {
        trackedImageManager = FindFirstObjectByType<ARTrackedImageManager>();
        if (trackedImageManager == null)
            Debug.LogError("❌ ARTrackedImageManager introuvable dans Awake !");

        GameObject xrOrigin = GameObject.Find("XR Origin (Mobile AR)");
        if (xrOrigin == null) { Debug.LogError("❌ XR Origin introuvable !"); return; }

        Transform cameraOffset = xrOrigin.transform.Find("Camera Offset");
        if (cameraOffset == null) { Debug.LogError("❌ Camera Offset introuvable !"); return; }

        Transform mainCamTransform = cameraOffset.Find("Main Camera");
        if (mainCamTransform == null) { Debug.LogError("❌ Main Camera introuvable !"); return; }

        xrCamera = mainCamTransform.GetComponent<Camera>();
        if (xrCamera == null) { Debug.LogError("❌ Composant Camera introuvable !"); return; }

        Debug.Log("✅ ARImageCubeOverlay INITIALISÉ — caméra : " + xrCamera.name);
    }

    void Start()
    {
        Debug.Log("✅ ARImageCubeOverlay DÉMARRÉ");
    }

    void OnEnable()
    {
        if (trackedImageManager != null)
        {
            trackedImageManager.trackablesChanged.AddListener(OnTrackedImagesChanged);
            Debug.Log("✅ Listener ajouté !");
        }
        else
        {
            Debug.LogWarning("⚠️ trackedImageManager null dans OnEnable.");
        }
    }

    void OnDisable()
    {
        if (trackedImageManager != null)
            trackedImageManager.trackablesChanged.RemoveListener(OnTrackedImagesChanged);
    }

    void OnTrackedImagesChanged(ARTrackablesChangedEventArgs<ARTrackedImage> eventArgs)
    {
        foreach (ARTrackedImage image in eventArgs.added)
        {
            Debug.Log("🖼️ Nouvelle image : " + image.referenceImage.name);
            SpawnCubeOnImage(image);
        }

        foreach (ARTrackedImage image in eventArgs.updated)
        {
            TrackableId id = image.trackableId;

            if (image.trackingState == TrackingState.Tracking)
            {
                UpdateCubeTransform(image);

                if (spawnedCubes.ContainsKey(id))
                {
                    spawnedCubes[id].SetActive(true);

                    TapDetector1 tap = spawnedCubes[id].GetComponent<TapDetector1>();
                    if (tap != null)
                    {
                        string imageName = image.referenceImage.name;
                        tap.trackedImage = image;

                        if (libraryTester != null)
                            tap.isValidated = libraryTester.imagesValidees.Contains(imageName);
                        else
                            tap.isValidated = true;
                    }
                }
            }
            else
            {
                if (spawnedCubes.ContainsKey(id) && spawnedCubes[id] != null)
                    spawnedCubes[id].SetActive(false);
            }
        }
    }

    void SpawnCubeOnImage(ARTrackedImage image)
    {
        TrackableId id        = image.trackableId;
        string      imageName = image.referenceImage.name;

        if (imageName.StartsWith("F"))
        {
            Debug.Log("🚫 Image ignorée (commence par 'F') : " + imageName);
            return;
        }

        if (spawnedCubes.ContainsKey(id))
        {
            spawnedCubes[id].SetActive(true);
            UpdateCubeTransform(image);
            return;
        }

        // ── Création du cube avec MeshRenderer + Material ──────
        GameObject cube = GameObject.CreatePrimitive(PrimitiveType.Cube);
        cube.name = "Cube_" + imageName + "_" + id;

        // Applique le material assigné dans l'inspecteur
        if (cubeMaterial != null)
            cube.GetComponent<MeshRenderer>().material = cubeMaterial;
        else
            Debug.LogWarning("⚠️ Aucun material assigné dans l'inspecteur pour le cube !");

        // Remplace le BoxCollider auto par un BoxCollider propre (taille = 1,1,1)
        BoxCollider col = cube.GetComponent<BoxCollider>();
        col.size = Vector3.one;

        TapDetector1 tap    = cube.AddComponent<TapDetector1>();
        tap.cam             = xrCamera;
        tap.data            = cubeDataLibrary?.GetEntryForImage(imageName);
        tap.isSpawnedPrefab = false;
        tap.trackedImage    = image;

        if (libraryTester == null)
            tap.isValidated = true;
        else
            tap.isValidated = libraryTester.imagesValidees.Contains(imageName);

        spawnedCubes[id] = cube;
        UpdateCubeTransform(image);

        Debug.Log("📦 Cube créé avec material pour : " + imageName);
    }

    void UpdateCubeTransform(ARTrackedImage image)
    {
        TrackableId id = image.trackableId;
        if (!spawnedCubes.ContainsKey(id)) return;

        GameObject cube      = spawnedCubes[id];
        Vector2    imageSize = image.size;

        cube.transform.localScale = new Vector3(imageSize.x, cubeHeight, imageSize.y);
        cube.transform.position   = image.transform.position
                                  + image.transform.up * (cubeHeight / 2f);
        cube.transform.rotation   = image.transform.rotation;
    }

    public GameObject GetCubeForImage(string imageName)
    {
        foreach (var kvp in spawnedCubes)
        {
            if (kvp.Value != null &&
                kvp.Value.name.StartsWith("Cube_" + imageName + "_"))
                return kvp.Value;
        }
        return null;
    }

    public void ClearAllCubes()
    {
        foreach (var kvp in spawnedCubes)
            if (kvp.Value != null) Destroy(kvp.Value);

        spawnedCubes.Clear();
        Debug.Log("🗑️ Tous les cubes supprimés");
    }

    public void RespawnCubesForActiveTrackables()
    {
        if (trackedImageManager == null) return;

        int count = 0;
        foreach (ARTrackedImage image in trackedImageManager.trackables)
        {
            if (image.trackingState == TrackingState.Tracking ||
                image.trackingState == TrackingState.Limited)
            {
                SpawnCubeOnImage(image);
                count++;
            }
        }
        Debug.Log("🔄 Respawn pour " + count + " trackables");
    }
}
/*version 14/04 - fix validation
// ARImageCubeOverlay.cs
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.Collections.Generic;

public class ARImageCubeOverlay : MonoBehaviour
{
    [Header("Paramètres du cube")]
    [SerializeField] private float cubeHeight = 0.005f;

    [Header("Liaison Book1Detector")]
    [SerializeField] private Book1Detector libraryTester;

    [Header("Mapping Image → CubeActionData")]
    [SerializeField] private ImageCubeDataLibrary cubeDataLibrary;

    private Camera xrCamera;
    private ARTrackedImageManager trackedImageManager;

    private readonly Dictionary<TrackableId, GameObject> spawnedCubes
        = new Dictionary<TrackableId, GameObject>();

    // ─────────────────────────────────────────────────────────────
    void Start()
    {
        Debug.Log("✅ ARImageCubeOverlay DÉMARRÉ");

        GameObject xrOrigin = GameObject.Find("XR Origin (Mobile AR)");
        if (xrOrigin == null) { Debug.LogError("❌ XR Origin introuvable !"); return; }

        Transform cameraOffset = xrOrigin.transform.Find("Camera Offset");
        if (cameraOffset == null) { Debug.LogError("❌ Camera Offset introuvable !"); return; }

        Transform mainCamTransform = cameraOffset.Find("Main Camera");
        if (mainCamTransform == null) { Debug.LogError("❌ Main Camera introuvable !"); return; }

        xrCamera = mainCamTransform.GetComponent<Camera>();
        if (xrCamera == null) { Debug.LogError("❌ Composant Camera introuvable !"); return; }

        Debug.Log("📷 Caméra trouvée : " + xrCamera.gameObject.name);

        trackedImageManager = FindFirstObjectByType<ARTrackedImageManager>();
        if (trackedImageManager == null) { Debug.LogError("❌ ARTrackedImageManager introuvable !"); return; }

        Debug.Log("🖼️ ARTrackedImageManager trouvé !");
    }

    void OnEnable()
    {
        trackedImageManager = FindFirstObjectByType<ARTrackedImageManager>();
        if (trackedImageManager != null)
        {
            trackedImageManager.trackablesChanged.AddListener(OnTrackedImagesChanged);
            Debug.Log("✅ Listener ajouté !");
        }
    }

    void OnDisable()
    {
        if (trackedImageManager != null)
            trackedImageManager.trackablesChanged.RemoveListener(OnTrackedImagesChanged);
    }

    // ─────────────────────────────────────────────────────────────
    void OnTrackedImagesChanged(ARTrackablesChangedEventArgs<ARTrackedImage> eventArgs)
    {
        foreach (ARTrackedImage image in eventArgs.added)
        {
            Debug.Log("🖼️ Nouvelle image : " + image.referenceImage.name + " | ID : " + image.trackableId);
            SpawnCubeOnImage(image);
        }

        foreach (ARTrackedImage image in eventArgs.updated)
        {
            TrackableId id = image.trackableId;

            if (image.trackingState == TrackingState.Tracking)
            {
                UpdateCubeTransform(image);

                if (spawnedCubes.ContainsKey(id))
                {
                    spawnedCubes[id].SetActive(true);

                    TapDetector1 tap = spawnedCubes[id].GetComponent<TapDetector1>();
                    if (tap != null)
                    {
                        string imageName = image.referenceImage.name;

                        // ── Validation via Book1Detector si dispo ─────
                        if (libraryTester != null)
                        {
                            bool validated = libraryTester.imagesValidees.Contains(imageName);
                            tap.isValidated = validated;
                            Debug.Log("🔍 Validation " + imageName + " : " + validated);
                        }
                        else
                        {
                            // ── Pas de Book1Detector → toujours validé ─
                            tap.isValidated = true;
                            Debug.Log("🔓 Pas de Book1Detector → " + imageName + " validé par défaut");
                        }
                    }
                }
            }
            else
            {
                Debug.Log("⚠️ Image hors champ, collider conservé : " + image.referenceImage.name);
            }
        }

        foreach (var kvp in eventArgs.removed)
            Debug.Log("📌 Image retirée, collider conservé : " + kvp.Value.referenceImage.name);
    }

    // ─────────────────────────────────────────────────────────────
    void SpawnCubeOnImage(ARTrackedImage image)
    {
        TrackableId id        = image.trackableId;
        string      imageName = image.referenceImage.name;

        if (imageName.StartsWith("F"))
        {
            Debug.Log("🚫 Image ignorée (commence par 'F') : " + imageName);
            return;
        }

        if (spawnedCubes.ContainsKey(id))
        {
            spawnedCubes[id].SetActive(true);
            UpdateCubeTransform(image);
            Debug.Log("♻️ Collider réactivé pour : " + imageName);
            return;
        }

        // ── Collider invisible sur l'image ────────────────────
        GameObject cube = new GameObject("Cube_" + imageName + "_" + id);
        BoxCollider col = cube.AddComponent<BoxCollider>();
        col.size = Vector3.one;

        // ── TapDetector ───────────────────────────────────────
        TapDetector1 tap    = cube.AddComponent<TapDetector1>();
        tap.cam             = xrCamera;
        tap.data            = cubeDataLibrary?.GetEntryForImage(imageName);
        tap.isSpawnedPrefab = false;

        // ── Validation initiale ───────────────────────────────
        // Si pas de Book1Detector dans la scène → validé immédiatement
        // Si Book1Detector présent → bloqué jusqu'à validation position
        if (libraryTester == null)
        {
            tap.isValidated = true;
            Debug.Log("🔓 Pas de Book1Detector → " + imageName + " validé immédiatement");
        }
        else
        {
            tap.isValidated = libraryTester.imagesValidees.Contains(imageName);
            Debug.Log("🔒 Validation initiale " + imageName + " : " + tap.isValidated);
        }

        spawnedCubes[id] = cube;
        UpdateCubeTransform(image);

        Debug.Log("📦 Collider créé pour : " + imageName
                + " | data : " + (tap.data != null ? tap.data.imageName : "NULL")
                + " | validé : " + tap.isValidated
                + " | Total : " + spawnedCubes.Count);
    }

    // ─────────────────────────────────────────────────────────────
    void UpdateCubeTransform(ARTrackedImage image)
    {
        TrackableId id = image.trackableId;
        if (!spawnedCubes.ContainsKey(id)) return;

        GameObject cube      = spawnedCubes[id];
        Vector2    imageSize = image.size;

        cube.transform.localScale = new Vector3(imageSize.x, cubeHeight, imageSize.y);
        cube.transform.position   = image.transform.position
                                  + image.transform.up * (cubeHeight / 2f);
        cube.transform.rotation   = image.transform.rotation;
    }

    // ─────────────────────────────────────────────────────────────
    public void ClearAllCubes()
    {
        foreach (var kvp in spawnedCubes)
            if (kvp.Value != null) Destroy(kvp.Value);

        spawnedCubes.Clear();
        Debug.Log("🗑️ Tous les colliders supprimés");
    }

    // ─────────────────────────────────────────────────────────────
    public void RespawnCubesForActiveTrackables()
    {
        if (trackedImageManager == null) return;

        int count = 0;
        foreach (ARTrackedImage image in trackedImageManager.trackables)
        {
            if (image.trackingState == TrackingState.Tracking ||
                image.trackingState == TrackingState.Limited)
            {
                SpawnCubeOnImage(image);
                count++;
            }
        }
        Debug.Log("🔄 Respawn tenté pour " + count + " trackables actifs");
    }
}
/*version07/04
// ============================================================
// ARImageCubeOverlay.cs
// ============================================================
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.Collections.Generic;

public class ARImageCubeOverlay : MonoBehaviour
{
    [Header("Paramètres du cube")]
    [Tooltip("Hauteur (épaisseur) du collider au-dessus de l'image (en mètres)")]
    [SerializeField] private float cubeHeight = 0.005f;

    [Header("Liaison Book1Detector")]
    [SerializeField] private Book1Detector libraryTester;

    [Header("Mapping Image → CubeActionData")]
    [SerializeField] private ImageCubeDataLibrary cubeDataLibrary;

    private Camera xrCamera;
    private ARTrackedImageManager trackedImageManager;

    private readonly Dictionary<TrackableId, GameObject> spawnedCubes
        = new Dictionary<TrackableId, GameObject>();

    // ─────────────────────────────────────────────────────────
    void Start()
    {
        Debug.Log("✅ ARImageCubeOverlay DÉMARRÉ");

        GameObject xrOrigin = GameObject.Find("XR Origin (Mobile AR)");
        if (xrOrigin == null) { Debug.LogError("❌ XR Origin introuvable !"); return; }

        Transform cameraOffset = xrOrigin.transform.Find("Camera Offset");
        if (cameraOffset == null) { Debug.LogError("❌ Camera Offset introuvable !"); return; }

        Transform mainCamTransform = cameraOffset.Find("Main Camera");
        if (mainCamTransform == null) { Debug.LogError("❌ Main Camera introuvable !"); return; }

        xrCamera = mainCamTransform.GetComponent<Camera>();
        if (xrCamera == null) { Debug.LogError("❌ Composant Camera introuvable !"); return; }

        Debug.Log("📷 Caméra trouvée : " + xrCamera.gameObject.name);

        trackedImageManager = FindFirstObjectByType<ARTrackedImageManager>();
        if (trackedImageManager == null) { Debug.LogError("❌ ARTrackedImageManager introuvable !"); return; }

        Debug.Log("🖼️ ARTrackedImageManager trouvé !");
    }

    void OnEnable()
    {
        trackedImageManager = FindFirstObjectByType<ARTrackedImageManager>();
        if (trackedImageManager != null)
        {
            trackedImageManager.trackablesChanged.AddListener(OnTrackedImagesChanged);
            Debug.Log("✅ Listener ajouté !");
        }
    }

    void OnDisable()
    {
        if (trackedImageManager != null)
            trackedImageManager.trackablesChanged.RemoveListener(OnTrackedImagesChanged);
    }

    // ─────────────────────────────────────────────────────────
    void OnTrackedImagesChanged(ARTrackablesChangedEventArgs<ARTrackedImage> eventArgs)
    {
        foreach (ARTrackedImage image in eventArgs.added)
        {
            Debug.Log("🖼️ Nouvelle image : " + image.referenceImage.name + " | ID : " + image.trackableId);
            SpawnCubeOnImage(image);
        }

        foreach (ARTrackedImage image in eventArgs.updated)
        {
            TrackableId id = image.trackableId;

            if (image.trackingState == TrackingState.Tracking)
            {
                UpdateCubeTransform(image);

                if (spawnedCubes.ContainsKey(id))
                {
                    spawnedCubes[id].SetActive(true);

                    TapDetector1 tap = spawnedCubes[id].GetComponent<TapDetector1>();
                    if (tap != null && libraryTester != null)
                    {
                        string imageName = image.referenceImage.name;
                        tap.isValidated = libraryTester.imagesValidees.Contains(imageName);
                        Debug.Log("🔍 Validation " + imageName + " : " + tap.isValidated);
                    }
                }
            }
            else
            {
                Debug.Log("⚠️ Image hors champ, collider conservé : " + image.referenceImage.name);
            }
        }

        foreach (var kvp in eventArgs.removed)
            Debug.Log("📌 Image retirée, collider conservé : " + kvp.Value.referenceImage.name);
    }

    // ─────────────────────────────────────────────────────────
    void SpawnCubeOnImage(ARTrackedImage image)
    {
        TrackableId id        = image.trackableId;
        string      imageName = image.referenceImage.name;

        if (imageName.StartsWith("F"))
        {
            Debug.Log("🚫 Image ignorée (commence par 'F') : " + imageName);
            return;
        }

        if (spawnedCubes.ContainsKey(id))
        {
            spawnedCubes[id].SetActive(true);
            UpdateCubeTransform(image);
            Debug.Log("♻️ Collider réactivé pour : " + imageName);
            return;
        }

        // ── Collider invisible sur l'image ────────────────────────────
        GameObject cube = new GameObject("Cube_" + imageName + "_" + id);
        BoxCollider col = cube.AddComponent<BoxCollider>();
        col.size = Vector3.one;

        // ── TapDetector posé sur l'image (pas un prefab spawné) ───────
        TapDetector1 tap = cube.AddComponent<TapDetector1>();
        tap.cam             = xrCamera;
        tap.data            = cubeDataLibrary?.GetEntryForImage(imageName);
        tap.isSpawnedPrefab = false;   // c'est le collider image
        tap.isValidated     = false;   // bloqué jusqu'à validation

        spawnedCubes[id] = cube;
        UpdateCubeTransform(image);

        Debug.Log("📦 Collider créé pour : " + imageName
                + " | ID : " + id
                + " | data : " + (tap.data != null ? tap.data.imageName : "NULL")
                + " | Total : " + spawnedCubes.Count);
    }

    // ─────────────────────────────────────────────────────────
    void UpdateCubeTransform(ARTrackedImage image)
    {
        TrackableId id = image.trackableId;
        if (!spawnedCubes.ContainsKey(id)) return;

        GameObject cube      = spawnedCubes[id];
        Vector2    imageSize = image.size;

        cube.transform.localScale = new Vector3(imageSize.x, cubeHeight, imageSize.y);

        cube.transform.position = image.transform.position
                                  + image.transform.up * (cubeHeight / 2f);

        cube.transform.rotation = image.transform.rotation;
    }

    // ─────────────────────────────────────────────────────────
    public void ClearAllCubes()
    {
        foreach (var kvp in spawnedCubes)
            if (kvp.Value != null) Destroy(kvp.Value);

        spawnedCubes.Clear();
        Debug.Log("🗑️ Tous les colliders supprimés");
    }

    // ─────────────────────────────────────────────────────────
    public void RespawnCubesForActiveTrackables()
    {
        if (trackedImageManager == null) return;

        int count = 0;
        foreach (ARTrackedImage image in trackedImageManager.trackables)
        {
            if (image.trackingState == TrackingState.Tracking ||
                image.trackingState == TrackingState.Limited)
            {
                SpawnCubeOnImage(image);
                count++;
            }
        }
        Debug.Log("🔄 Respawn tenté pour " + count + " trackables actifs");
    }
}
// ============================================================
// ARImageCubeOverlay.cs
// ============================================================
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.Collections.Generic;

public class ARImageCubeOverlay : MonoBehaviour
{
    [Header("Paramètres du cube")]
    // Épaisseur du collider posé sur l'image (invisible)
    [Tooltip("Hauteur (épaisseur) du collider au-dessus de l'image (en mètres)")]
    [SerializeField] private float cubeHeight = 0.005f;

    [Header("Liaison Book1Detector")]
    // Script qui gère la validation des images correctement placées
    [SerializeField] private Book1Detector libraryTester;

    [Header("Mapping Image → CubeActionData")]
    // Asset ScriptableObject contenant toutes les données par image
    [SerializeField] private ImageCubeDataLibrary cubeDataLibrary;

    // Caméra AR — trouvée automatiquement via XR Origin/Camera Offset/Main Camera
    private Camera xrCamera;

    // Manager AR qui détecte et suit les images dans le monde réel
    private ARTrackedImageManager trackedImageManager;

    // Dictionnaire : TrackableId → GameObject collider invisible
    private readonly Dictionary<TrackableId, GameObject> spawnedCubes
        = new Dictionary<TrackableId, GameObject>();

    // ─────────────────────────────────────────────────────────
    void Start()
    {
        Debug.Log("✅ ARImageCubeOverlay DÉMARRÉ");

        // Cherche le GameObject racine XR Origin dans la scène
        GameObject xrOrigin = GameObject.Find("XR Origin (Mobile AR)");
        if (xrOrigin == null) { Debug.LogError("❌ XR Origin introuvable !"); return; }

        // Cherche Camera Offset, enfant direct de XR Origin
        Transform cameraOffset = xrOrigin.transform.Find("Camera Offset");
        if (cameraOffset == null) { Debug.LogError("❌ Camera Offset introuvable !"); return; }

        // Cherche Main Camera, enfant direct de Camera Offset
        Transform mainCamTransform = cameraOffset.Find("Main Camera");
        if (mainCamTransform == null) { Debug.LogError("❌ Main Camera introuvable !"); return; }

        // Récupère le composant Camera sur Main Camera
        xrCamera = mainCamTransform.GetComponent<Camera>();
        if (xrCamera == null) { Debug.LogError("❌ Composant Camera introuvable !"); return; }

        Debug.Log("📷 Caméra trouvée : " + xrCamera.gameObject.name);

        // Cherche le manager de tracking d'images AR dans la scène
        trackedImageManager = FindFirstObjectByType<ARTrackedImageManager>();
        if (trackedImageManager == null) { Debug.LogError("❌ ARTrackedImageManager introuvable !"); return; }

        Debug.Log("🖼️ ARTrackedImageManager trouvé !");
    }

    void OnEnable()
    {
        // Récupère le manager et s'abonne aux changements de tracking
        trackedImageManager = FindFirstObjectByType<ARTrackedImageManager>();
        if (trackedImageManager != null)
        {
            trackedImageManager.trackablesChanged.AddListener(OnTrackedImagesChanged);
            Debug.Log("✅ Listener ajouté !");
        }
    }

    void OnDisable()
    {
        // Se désabonne pour éviter les erreurs quand le GameObject est désactivé
        if (trackedImageManager != null)
            trackedImageManager.trackablesChanged.RemoveListener(OnTrackedImagesChanged);
    }

    // ─────────────────────────────────────────────────────────
    void OnTrackedImagesChanged(ARTrackablesChangedEventArgs<ARTrackedImage> eventArgs)
    {
        // Nouvelle image détectée → créer son collider
        foreach (ARTrackedImage image in eventArgs.added)
        {
            Debug.Log("🖼️ Nouvelle image : " + image.referenceImage.name + " | ID : " + image.trackableId);
            SpawnCubeOnImage(image);
        }

        // Image mise à jour → repositionner le collider + vérifier validation
        foreach (ARTrackedImage image in eventArgs.updated)
        {
            TrackableId id = image.trackableId;

            if (image.trackingState == TrackingState.Tracking)
            {
                // Met à jour la position/rotation/taille du collider
                UpdateCubeTransform(image);

                if (spawnedCubes.ContainsKey(id))
                {
                    // Réactive le collider s'il était désactivé
                    spawnedCubes[id].SetActive(true);

                    // Récupère le TapDetector1 sur ce collider
                    TapDetector1 tap = spawnedCubes[id].GetComponent<TapDetector1>();
                    if (tap != null && libraryTester != null)
                    {
                        string imageName = image.referenceImage.name;

                        // Met à jour la validation selon libraryTester
                        // true = image correctement placée → tap autorisé
                        tap.isValidated = libraryTester.imagesValidees.Contains(imageName);
                        Debug.Log("🔍 Validation " + imageName + " : " + tap.isValidated);
                    }
                }
            }
            else
            {
                Debug.Log("⚠️ Image hors champ, collider conservé : " + image.referenceImage.name);
            }
        }

        foreach (var kvp in eventArgs.removed)
            Debug.Log("📌 Image retirée, collider conservé : " + kvp.Value.referenceImage.name);
    }

    // ─────────────────────────────────────────────────────────
    void SpawnCubeOnImage(ARTrackedImage image)
    {
        TrackableId id = image.trackableId;
        string imageName = image.referenceImage.name;

        // Ignore les images dont le nom commence par 'F'
        if (imageName.StartsWith("F"))
        {
            Debug.Log("🚫 Image ignorée (commence par 'F') : " + imageName);
            return;
        }

        // Réactive le collider existant plutôt que d'en créer un nouveau
        if (spawnedCubes.ContainsKey(id))
        {
            spawnedCubes[id].SetActive(true);
            UpdateCubeTransform(image);
            Debug.Log("♻️ Collider réactivé pour : " + imageName);
            return;
        }

        // ── Création d'un GameObject vide (invisible) ─────────
        // Pas de MeshRenderer ni MeshFilter → totalement invisible
        GameObject cube = new GameObject("Cube_" + imageName + "_" + id);

        // Ajoute uniquement un BoxCollider pour la détection du tap
        BoxCollider col = cube.AddComponent<BoxCollider>();
        col.size = Vector3.one; // Taille de base, écrasée par UpdateCubeTransform

        // ── Ajout du TapDetector1 ─────────────────────────────
        TapDetector1 tap = cube.AddComponent<TapDetector1>();

        // Caméra AR pour les raycasts
        tap.cam = xrCamera;

        // Données correspondant à cette image dans la librairie
        tap.data = cubeDataLibrary?.GetEntryForImage(imageName);

        // Ce collider est sur une image → comportement Image au tap
        tap.targetType = ImageCubeDataLibrary.TapTargetType.Image;

        // Bloqué par défaut jusqu'à la validation par libraryTester
        tap.isValidated = false;

        // ── Enregistrement et positionnement ──────────────────
        spawnedCubes[id] = cube;
        UpdateCubeTransform(image);

        Debug.Log("📦 Collider créé pour : " + imageName
                + " | ID : " + id
                + " | data : " + (tap.data != null ? tap.data.imageName : "NULL")
                + " | Total : " + spawnedCubes.Count);
    }

    // ─────────────────────────────────────────────────────────
    void UpdateCubeTransform(ARTrackedImage image)
    {
        TrackableId id = image.trackableId;
        if (!spawnedCubes.ContainsKey(id)) return;

        GameObject cube = spawnedCubes[id];
        Vector2 imageSize = image.size;

        // Redimensionne le collider pour couvrir exactement l'image
        // X = largeur, Y = épaisseur (très fine), Z = longueur
        cube.transform.localScale = new Vector3(imageSize.x, cubeHeight, imageSize.y);

        // Positionne le collider centré sur l'image, légèrement au-dessus
        cube.transform.position = image.transform.position
                                  + image.transform.up * (cubeHeight / 2f);

        // Aligne la rotation sur celle de l'image trackée
        cube.transform.rotation = image.transform.rotation;
    }

    // ─────────────────────────────────────────────────────────
    public void ClearAllCubes()
    {
        // Détruit tous les colliders et vide le dictionnaire
        foreach (var kvp in spawnedCubes)
            if (kvp.Value != null) Destroy(kvp.Value);

        spawnedCubes.Clear();
        Debug.Log("🗑️ Tous les colliders supprimés");
    }

    // ─────────────────────────────────────────────────────────
    public void RespawnCubesForActiveTrackables()
    {
        if (trackedImageManager == null) return;

        int count = 0;
        foreach (ARTrackedImage image in trackedImageManager.trackables)
        {
            // Tracking = image bien visible | Limited = partiellement visible
            if (image.trackingState == TrackingState.Tracking ||
                image.trackingState == TrackingState.Limited)
            {
                SpawnCubeOnImage(image);
                count++;
            }
        }
        Debug.Log("🔄 Respawn tenté pour " + count + " trackables actifs");
    }
}
// ARImageCubeOverlay.cs
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.Collections.Generic;

public class ARImageCubeOverlay : MonoBehaviour
{
    [Header("Paramètres du cube")]
    [Tooltip("Hauteur (épaisseur) du cube au-dessus de l'image (en mètres)")]
    [SerializeField] private float cubeHeight = 0.005f;

    [Tooltip("Matériau appliqué au cube (laisser vide = couleur aléatoire)")]
    [SerializeField] private Material cubeMaterial;

    [Header("Liaison ARLibraryTester")]
    [SerializeField] private ARLibraryTester libraryTester;

    [Header("Mapping Image → CubeActionData")]
    [SerializeField] private ImageCubeDataLibrary cubeDataLibrary;

    private Camera xrCamera;
    private ARTrackedImageManager trackedImageManager;

    private readonly Dictionary<TrackableId, GameObject> spawnedCubes
        = new Dictionary<TrackableId, GameObject>();

    // ─────────────────────────────────────────────
    void Start()
    {
        Debug.Log("✅ ARImageCubeOverlay DÉMARRÉ");

        GameObject xrOrigin = GameObject.Find("XR Origin (Mobile AR)");
        if (xrOrigin == null) { Debug.LogError("❌ XR Origin (Mobile AR) introuvable !"); return; }

        xrCamera = xrOrigin.GetComponentInChildren<Camera>();
        if (xrCamera == null) { Debug.LogError("❌ Caméra introuvable dans XR Origin !"); return; }

        Debug.Log("📷 Caméra : " + xrCamera.gameObject.name);

        trackedImageManager = FindFirstObjectByType<ARTrackedImageManager>();
        if (trackedImageManager == null) { Debug.LogError("❌ ARTrackedImageManager introuvable !"); return; }

        Debug.Log("🖼️ ARTrackedImageManager trouvé !");
    }

    void OnEnable()
    {
        trackedImageManager = FindFirstObjectByType<ARTrackedImageManager>();
        if (trackedImageManager != null)
        {
            trackedImageManager.trackablesChanged.AddListener(OnTrackedImagesChanged);
            Debug.Log("✅ Listener ajouté !");
        }
    }

    void OnDisable()
    {
        if (trackedImageManager != null)
            trackedImageManager.trackablesChanged.RemoveListener(OnTrackedImagesChanged);
    }

    // ─────────────────────────────────────────────
    void OnTrackedImagesChanged(ARTrackablesChangedEventArgs<ARTrackedImage> eventArgs)
    {
        foreach (ARTrackedImage image in eventArgs.added)
        {
            Debug.Log("🖼️ Nouvelle image : " + image.referenceImage.name + " | ID : " + image.trackableId);
            SpawnCubeOnImage(image);
        }

        foreach (ARTrackedImage image in eventArgs.updated)
        {
            TrackableId id = image.trackableId;

            if (image.trackingState == TrackingState.Tracking)
            {
                UpdateCubeTransform(image);

                if (spawnedCubes.ContainsKey(id))
                {
                    spawnedCubes[id].SetActive(true);

                    // ── Mettre à jour la validation ───────
                    TapDetector1 tap = spawnedCubes[id].GetComponent<TapDetector1>();
                    if (tap != null && libraryTester != null)
                    {
                        string imageName = image.referenceImage.name;
                        tap.isValidated = libraryTester.imagesValidees.Contains(imageName);
                        Debug.Log("🔍 Validation " + imageName + " : " + tap.isValidated);
                    }
                }
            }
            else
            {
                Debug.Log("⚠️ Image hors champ, cube conservé : " + image.referenceImage.name);
            }
        }

        foreach (var kvp in eventArgs.removed)
        {
            Debug.Log("📌 Image retirée, cube conservé : " + kvp.Value.referenceImage.name);
        }
    }

    // ─────────────────────────────────────────────
    void SpawnCubeOnImage(ARTrackedImage image)
    {
        TrackableId id = image.trackableId;
        string imageName = image.referenceImage.name;

        if (imageName.StartsWith("F"))
        {
            Debug.Log("🚫 Image ignorée (commence par 'F') : " + imageName);
            return;
        }

        if (spawnedCubes.ContainsKey(id))
        {
            spawnedCubes[id].SetActive(true);
            UpdateCubeTransform(image);
            Debug.Log("♻️ Cube réactivé pour : " + imageName);
            return;
        }

        // ── Créer le cube ──────────────────────────────
        GameObject cube = GameObject.CreatePrimitive(PrimitiveType.Cube);
        cube.name = "Cube_" + imageName + "_" + id;

        // Matériau
        Material mat;
        if (cubeMaterial != null)
            mat = new Material(cubeMaterial);
        else
        {
            mat = new Material(Shader.Find("Universal Render Pipeline/Lit"));
            mat.color = Random.ColorHSV(0f, 1f, 0.8f, 1f, 0.8f, 1f);
        }
        cube.GetComponent<Renderer>().material = mat;

        // Collider
        if (cube.GetComponent<BoxCollider>() == null)
            cube.AddComponent<BoxCollider>();

        // ── TapDetector1 ───────────────────────────────
        TapDetector1 tap = cube.AddComponent<TapDetector1>();
        tap.cam = xrCamera;
        tap.data = cubeDataLibrary?.GetEntryForImage(imageName);
        tap.targetType = ImageCubeDataLibrary.TapTargetType.Image;
        tap.isValidated = false; // bloqué par défaut

        // ── Enregistrer et positionner ─────────────────
        spawnedCubes[id] = cube;
        UpdateCubeTransform(image);

        Debug.Log("📦 Cube créé pour : " + imageName
                + " | ID : " + id
                + " | data : " + (tap.data != null ? tap.data.imageName : "NULL")
                + " | Total : " + spawnedCubes.Count);
    }

    // ─────────────────────────────────────────────
    void UpdateCubeTransform(ARTrackedImage image)
    {
        TrackableId id = image.trackableId;
        if (!spawnedCubes.ContainsKey(id)) return;

        GameObject cube = spawnedCubes[id];
        Vector2 imageSize = image.size;

        cube.transform.localScale = new Vector3(imageSize.x, cubeHeight, imageSize.y);
        cube.transform.position = image.transform.position
                                  + image.transform.up * (cubeHeight / 2f);
        cube.transform.rotation = image.transform.rotation;
    }

    // ─────────────────────────────────────────────
    public void ClearAllCubes()
    {
        foreach (var kvp in spawnedCubes)
            if (kvp.Value != null) Destroy(kvp.Value);

        spawnedCubes.Clear();
        Debug.Log("🗑️ Tous les cubes supprimés");
    }

    public void RespawnCubesForActiveTrackables()
    {
        if (trackedImageManager == null) return;

        int count = 0;
        foreach (ARTrackedImage image in trackedImageManager.trackables)
        {
            if (image.trackingState == TrackingState.Tracking ||
                image.trackingState == TrackingState.Limited)
            {
                SpawnCubeOnImage(image);
                count++;
            }
        }
        Debug.Log("🔄 Respawn tenté pour " + count + " trackables actifs");
    }
}
// ============================================================
// ARImageCubeOverlay.cs
// ============================================================
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;

public class ARImageCubeOverlay : MonoBehaviour
{
    [Header("Paramètres du cube")]
    [Tooltip("Hauteur (épaisseur) du cube au-dessus de l'image (en mètres)")]
    [SerializeField] private float cubeHeight = 0.005f;

    [Tooltip("Matériau appliqué au cube (laisser vide = couleur aléatoire)")]
    [SerializeField] private Material cubeMaterial;

    [Header("Liaison ARLibraryTester")]
    [SerializeField] private ARLibraryTester libraryTester;

    private Camera xrCamera;
    private ARTrackedImageManager trackedImageManager;

    private readonly Dictionary<TrackableId, GameObject> spawnedCubes
        = new Dictionary<TrackableId, GameObject>();

    private Text tapMessageText;
    private Coroutine hideMessageCoroutine;

    void Start()
    {
        Debug.Log("✅ ARImageCubeOverlay DÉMARRÉ");

        GameObject xrOrigin = GameObject.Find("XR Origin (Mobile AR)");
        if (xrOrigin == null) { Debug.LogError("❌ XR Origin (Mobile AR) introuvable !"); return; }

        xrCamera = xrOrigin.GetComponentInChildren<Camera>();
        if (xrCamera == null) { Debug.LogError("❌ Caméra introuvable dans XR Origin !"); return; }

        Debug.Log("📷 Caméra : " + xrCamera.gameObject.name);

        trackedImageManager = FindFirstObjectByType<ARTrackedImageManager>();
        if (trackedImageManager == null) { Debug.LogError("❌ ARTrackedImageManager introuvable !"); return; }

        Debug.Log("🖼️ ARTrackedImageManager trouvé !");

        CreerUIMessage();
    }

    void OnEnable()
    {
        trackedImageManager = FindFirstObjectByType<ARTrackedImageManager>();
        if (trackedImageManager != null)
        {
            trackedImageManager.trackablesChanged.AddListener(OnTrackedImagesChanged);
            Debug.Log("✅ Listener ajouté !");
        }
    }

    void OnDisable()
    {
        if (trackedImageManager != null)
            trackedImageManager.trackablesChanged.RemoveListener(OnTrackedImagesChanged);
    }

    void OnTrackedImagesChanged(ARTrackablesChangedEventArgs<ARTrackedImage> eventArgs)
    {
        foreach (ARTrackedImage image in eventArgs.added)
        {
            Debug.Log("🖼️ Nouvelle image : " + image.referenceImage.name + " | ID : " + image.trackableId);
            SpawnCubeOnImage(image);
        }

        foreach (ARTrackedImage image in eventArgs.updated)
        {
            TrackableId id = image.trackableId;

            if (image.trackingState == TrackingState.Tracking)
            {
                UpdateCubeTransform(image);

                if (spawnedCubes.ContainsKey(id))
                    spawnedCubes[id].SetActive(true);
            }
            else
            {
                Debug.Log("⚠️ Image hors champ, cube conservé : " + image.referenceImage.name);
            }
        }

        foreach (var kvp in eventArgs.removed)
        {
            Debug.Log("📌 Image retirée, cube conservé : " + kvp.Value.referenceImage.name);
        }
    }

    void SpawnCubeOnImage(ARTrackedImage image)
    {
        TrackableId id = image.trackableId;
        string imageName = image.referenceImage.name;

        if (imageName.StartsWith("F"))
        {
            Debug.Log("🚫 Image ignorée (commence par 'F') : " + imageName);
            return;
        }

        if (spawnedCubes.ContainsKey(id))
        {
            spawnedCubes[id].SetActive(true);
            UpdateCubeTransform(image);
            Debug.Log("♻️ Cube réactivé pour : " + imageName);
            return;
        }

        GameObject cube = GameObject.CreatePrimitive(PrimitiveType.Cube);
        cube.name = "Cube_" + imageName + "_" + id;

        Material mat;
        if (cubeMaterial != null)
        {
            mat = new Material(cubeMaterial);
        }
        else
        {
            mat = new Material(Shader.Find("Universal Render Pipeline/Lit"));
            mat.color = Random.ColorHSV(0f, 1f, 0.8f, 1f, 0.8f, 1f);
        }
        cube.GetComponent<Renderer>().material = mat;

        if (cube.GetComponent<BoxCollider>() == null)
            cube.AddComponent<BoxCollider>();
        
        TapDetector1 tap = cube.AddComponent<TapDetector1>();
        tap.cam = xrCamera;
        tap.data = ImageCubeDataLibrary?.GetEntryForImage(imageName);


        spawnedCubes[id] = cube;

        UpdateCubeTransform(image);

        Debug.Log("📦 Cube créé pour : " + imageName
                + " | ID : " + id
                + " | Total : " + spawnedCubes.Count);
    }

    void UpdateCubeTransform(ARTrackedImage image)
    {
        TrackableId id = image.trackableId;
        if (!spawnedCubes.ContainsKey(id)) return;

        GameObject cube = spawnedCubes[id];
        Vector2 imageSize = image.size;

        cube.transform.localScale = new Vector3(imageSize.x, cubeHeight, imageSize.y);
        cube.transform.position = image.transform.position
                                  + image.transform.up * (cubeHeight / 2f);
        cube.transform.rotation = image.transform.rotation;
    }

    public void ClearAllCubes()
    {
        foreach (var kvp in spawnedCubes)
        {
            if (kvp.Value != null)
                Destroy(kvp.Value);
        }
        spawnedCubes.Clear();
        Debug.Log("🗑️ Tous les cubes supprimés (changement de feuille)");
    }

    public void RespawnCubesForActiveTrackables()
    {
        if (trackedImageManager == null) return;

        int count = 0;

        foreach (ARTrackedImage image in trackedImageManager.trackables)
        {
            // Accepte Tracking ET Limited pour ne rater aucune image
            if (image.trackingState == TrackingState.Tracking ||
                image.trackingState == TrackingState.Limited)
            {
                SpawnCubeOnImage(image);
                count++;
            }
        }

        Debug.Log("🔄 Respawn tenté pour " + count + " trackables actifs");
    }

    void Update()
    {
        if (xrCamera == null) return;

        bool tapped = false;
        Vector2 tapPosition = Vector2.zero;

#if UNITY_EDITOR
        if (Mouse.current != null && Mouse.current.leftButton.wasPressedThisFrame)
        {
            tapped = true;
            tapPosition = Mouse.current.position.ReadValue();
            Debug.Log("🖥️ Clic détecté (Editor)");
        }
#else
        if (Touchscreen.current != null && Touchscreen.current.primaryTouch.press.wasPressedThisFrame)
        {
            tapped = true;
            tapPosition = Touchscreen.current.primaryTouch.position.ReadValue();
            Debug.Log("📱 Tap détecté (Mobile)");
        }
#endif

        if (!tapped) return;

        Ray ray = xrCamera.ScreenPointToRay(tapPosition);
        Debug.DrawRay(ray.origin, ray.direction * 10f, Color.yellow, 3f);

        RaycastHit[] hits = Physics.RaycastAll(ray, 100f);
        Debug.Log("🔍 Objets touchés par le ray : " + hits.Length);

        bool cubeFound = false;

        foreach (RaycastHit hit in hits)
        {
            Debug.Log("   → " + hit.collider.gameObject.name);

            foreach (KeyValuePair<TrackableId, GameObject> entry in spawnedCubes)
            {
                if (hit.collider.gameObject == entry.Value)
                {
                    cubeFound = true;
                    Debug.Log("✅ Cube touché ! ID : " + entry.Key);
                    OnCubeTapped(entry.Value);
                }
            }
        }

        if (!cubeFound && hits.Length == 0)
            Debug.Log("❌ Le ray ne touche aucun objet");
    }

    void OnCubeTapped(GameObject cube)
    {
        string cubeName = cube.name;
        string[] parts = cubeName.Split('_');
        string imageName = parts.Length >= 2 ? parts[1] : "";

        if (libraryTester != null && !libraryTester.imagesValidees.Contains(imageName))
        {
            Debug.Log("🔒 Tap ignoré : image pas encore validée (pas verte) : " + imageName);
            return;
        }

        string message = "👆 Vous avez tapé : " + imageName;
        Debug.Log(message);

        AfficherMessage(imageName);
    }

    void CreerUIMessage()
    {
        GameObject canvasObj = new GameObject("CanvasTapMessage");
        Canvas canvas = canvasObj.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder = 10;

        canvasObj.AddComponent<CanvasScaler>();
        canvasObj.AddComponent<GraphicRaycaster>();

        GameObject bgObj = new GameObject("Background");
        bgObj.transform.SetParent(canvasObj.transform, false);

        Image bg = bgObj.AddComponent<Image>();
        bg.color = new Color(0f, 0f, 0f, 0.6f);

        RectTransform bgRt = bgObj.GetComponent<RectTransform>();
        bgRt.anchorMin = new Vector2(0.1f, 0.42f);
        bgRt.anchorMax = new Vector2(0.9f, 0.58f);
        bgRt.offsetMin = Vector2.zero;
        bgRt.offsetMax = Vector2.zero;

        GameObject textObj = new GameObject("TapMessageText");
        textObj.transform.SetParent(bgObj.transform, false);

        tapMessageText = textObj.AddComponent<Text>();
        tapMessageText.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        tapMessageText.fontSize = 36;
        tapMessageText.color = Color.white;
        tapMessageText.alignment = TextAnchor.MiddleCenter;
        tapMessageText.text = "";

        RectTransform textRt = textObj.GetComponent<RectTransform>();
        textRt.anchorMin = Vector2.zero;
        textRt.anchorMax = Vector2.one;
        textRt.offsetMin = new Vector2(10, 5);
        textRt.offsetMax = new Vector2(-10, -5);

        bgObj.SetActive(false);
        tapMessageText.transform.parent.gameObject.SetActive(false);
    }

    void AfficherMessage(string imageName)
    {
        if (tapMessageText == null) return;

        tapMessageText.text = "👆 Vous avez tapé : " + imageName;
        tapMessageText.transform.parent.gameObject.SetActive(true);

        if (hideMessageCoroutine != null)
            StopCoroutine(hideMessageCoroutine);

        hideMessageCoroutine = StartCoroutine(CacherMessageApresDelai(3f));
    }

    IEnumerator CacherMessageApresDelai(float delai)
    {
        yield return new WaitForSeconds(delai);

        if (tapMessageText != null)
            tapMessageText.transform.parent.gameObject.SetActive(false);
    }
}*/