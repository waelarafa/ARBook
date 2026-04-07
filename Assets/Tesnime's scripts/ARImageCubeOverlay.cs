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
/*// ARImageCubeOverlay.cs
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
}/*
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