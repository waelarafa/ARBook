/*version finale verifiee - fix GraphicRaycaster*/
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

[RequireComponent(typeof(ARTrackedImageManager))]
public class Book1Detector : MonoBehaviour
{
    [System.Serializable]
    public struct Page
    {
        public string feuilleName;
        public string pageId;
        public List<string> imageNames;
        public List<Vector3> positionsCorrectes;
    }

    [Header("AR")]
    public ARTrackedImageManager trackedImageManager;

    [Header("Validation")]
    public float distanceMax = 0.05f;

    [Header("Liaison ARImageCubeOverlay")]
    public ARImageCubeOverlay cubeOverlay;

    private const string BOOK_ID = "book_001";

    private List<Page> pages      = new List<Page>();
    private bool pagesLoaded      = false;
    private string currentPageId  = "";
    private bool switching        = false;

    private Dictionary<string, TrackingState>  detectedImages    = new Dictionary<string, TrackingState>();
    public  Dictionary<string, Vector3>        positionsGlobales = new Dictionary<string, Vector3>();
    public  Dictionary<string, ARTrackedImage> trackedImages     = new Dictionary<string, ARTrackedImage>();
    private ARTrackedImage feuilleDetectee = null;
    public  HashSet<string> imagesValidees = new HashSet<string>();

    private Text uiText;

    // ─────────────────────────────────────────────
    void Awake()
    {
        if (trackedImageManager == null)
            trackedImageManager = GetComponent<ARTrackedImageManager>();
        CreerUI();
    }

    void Start()
    {
        StartCoroutine(WaitForDataAndLoad());
    }

    void OnEnable()  => trackedImageManager.trackedImagesChanged += OnImagesChanged;
    void OnDisable() => trackedImageManager.trackedImagesChanged -= OnImagesChanged;
    void Update()    => MettreAJourUI();

    // ─────────────────────────────────────────────
    IEnumerator WaitForDataAndLoad()
    {
        yield return new WaitUntil(() => DataManager.Instance != null);
        yield return new WaitUntil(() => DataManager.Instance.GetBookEntry(BOOK_ID) != null);
        yield return StartCoroutine(DataManager.Instance.LoadBookFromUrl(BOOK_ID));
        BuildPagesFromData();
    }

    void BuildPagesFromData()
    {
        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(BOOK_ID);
        if (bookData == null)
        {
            Debug.LogError("[Book1Detector] BookData introuvable après chargement.");
            return;
        }

        pages.Clear();
        foreach (ARBook.Models.PageData pageData in bookData.pages)
        {
            Page page = new Page
            {
                feuilleName        = pageData.feuille,
                pageId             = pageData.id,
                imageNames         = new List<string>(),
                positionsCorrectes = new List<Vector3>()
            };
            foreach (ARBook.Models.ItemData item in pageData.items)
            {
                page.imageNames.Add(item.nom);
                page.positionsCorrectes.Add(new Vector3(item.x, item.y, item.z));
            }
            pages.Add(page);
            Debug.Log($"[Book1Detector] Page : {page.pageId} | {page.imageNames.Count} image(s)");
        }

        pagesLoaded = true;
        Debug.Log($"[Book1Detector] ✅ {pages.Count} page(s) chargée(s).");
    }

    // ─────────────────────────────────────────────
    void OnImagesChanged(ARTrackedImagesChangedEventArgs args)
    {
        if (!pagesLoaded) return;

        foreach (var img in args.added)
        {
            detectedImages[img.referenceImage.name] = img.trackingState;
            trackedImages[img.referenceImage.name]  = img;
            TraiterFeuille(img);
        }
        foreach (var img in args.updated)
        {
            detectedImages[img.referenceImage.name] = img.trackingState;
            trackedImages[img.referenceImage.name]  = img;
            if (img.trackingState == TrackingState.Tracking)
                TraiterFeuille(img);
        }
        foreach (var img in args.removed)
        {
            detectedImages.Remove(img.referenceImage.name);
            trackedImages.Remove(img.referenceImage.name);
        }

        MettreAJourUI();
    }

    // ─────────────────────────────────────────────
    void TraiterFeuille(ARTrackedImage img)
    {
        if (switching) return;
        foreach (var page in pages)
        {
            if (img.referenceImage.name == page.feuilleName)
            {
                if (currentPageId != page.pageId)
                {
                    DataManager.Instance.OnPageDetected(BOOK_ID, page.pageId);
                    StartCoroutine(SwitchPage(page, img));
                }
                else
                {
                    feuilleDetectee = img;
                    CalculerPositions(page);
                }
                return;
            }
        }
    }

    IEnumerator SwitchPage(Page page, ARTrackedImage feuille)
    {
        switching     = true;
        currentPageId = page.pageId;

        detectedImages.Clear();
        positionsGlobales.Clear();
        trackedImages.Clear();
        imagesValidees.Clear();

        if (cubeOverlay != null) cubeOverlay.ClearAllCubes();

        // ── Initialise les étoiles pour cette page ← NOUVEAU
        if (StarUIManager.Instance != null)
            StarUIManager.Instance.InitStars(page.imageNames.Count);

        feuilleDetectee = feuille;
        yield return null;
        yield return null;
        yield return null;

        CalculerPositions(page);
        StartCoroutine(RespawnAvecRetry(5, 0.1f));

        Debug.Log($"📘 Page active : {page.pageId}");
        switching = false;
        MettreAJourUI();
    }

    IEnumerator RespawnAvecRetry(int tentatives, float intervalle)
    {
        for (int i = 0; i < tentatives; i++)
        {
            if (cubeOverlay != null) cubeOverlay.RespawnCubesForActiveTrackables();
            yield return new WaitForSeconds(intervalle);
        }
    }

    // ─────────────────────────────────────────────
    void CalculerPositions(Page page)
    {
        if (feuilleDetectee == null) return;
        positionsGlobales.Clear();
        for (int i = 0; i < page.imageNames.Count; i++)
        {
            if (i >= page.positionsCorrectes.Count) continue;
            Vector3 globalPos = feuilleDetectee.transform.position
                              + feuilleDetectee.transform.TransformVector(page.positionsCorrectes[i]);
            positionsGlobales[page.imageNames[i]] = globalPos;
            Debug.Log($"📍 {page.imageNames[i]} => {globalPos}");
        }
    }

    // ─────────────────────────────────────────────
    public GameObject  GetPrefabForItem(string itemName) => DataManager.Instance.GetPrefab(itemName);
    public Texture2D   GetImageForItem(string itemName)  => DataManager.Instance.GetImage(itemName);
    public bool        IsItemReady(string itemName)      => DataManager.Instance.IsAssetReady(itemName);
    public ARBook.Models.ItemData GetItemData(string itemName) => DataManager.Instance.GetItemData(BOOK_ID, itemName);

    // ─────────────────────────────────────────────
    void MettreAJourUI()
    {
        if (uiText == null) return;

        System.Text.StringBuilder sb = new System.Text.StringBuilder();
        sb.AppendLine("═══ AR LIBRARY TESTER ═══");
        sb.AppendLine(string.IsNullOrEmpty(currentPageId)
            ? "📚 Page active : aucune"
            : $"📚 Page active : {currentPageId}");
        sb.AppendLine($"🔍 Images trackées : {detectedImages.Count}");

        if (!pagesLoaded) { sb.AppendLine("⏳ Chargement..."); uiText.text = sb.ToString(); return; }

        sb.AppendLine("----------------------------");
        foreach (var page in pages)
        {
            bool isActive  = page.pageId == currentPageId;
            string prefix  = isActive ? "▶ " : "  ";
            sb.AppendLine($"{prefix}[{page.pageId}] feuille: {page.feuilleName}");

            foreach (string imgName in page.imageNames)
            {
                bool detected          = detectedImages.ContainsKey(imgName);
                TrackingState state    = detected ? detectedImages[imgName] : TrackingState.None;
                string icon            = !detected ? "○" : state == TrackingState.Tracking ? "✓" : "~";
                bool assetReady        = DataManager.Instance.IsAssetReady(imgName);
                string cacheIcon       = assetReady ? "💾" : "⏳";
                bool inCorrectPosition = false;

                if (imagesValidees.Contains(imgName))
                {
                    inCorrectPosition = true;
                }
                else if (detected && positionsGlobales.ContainsKey(imgName))
                {
                    foreach (var tracked in trackedImageManager.trackables)
                    {
                        if (tracked.referenceImage.name == imgName)
                        {
                            float dist = Vector3.Distance(tracked.transform.position, positionsGlobales[imgName]);
                            if (dist <= distanceMax)
                            {
                                inCorrectPosition = true;
                                imagesValidees.Add(imgName);
                                Debug.Log("✅ VALIDÉ : " + imgName);

                                // ── Highlight sur le cube ← NOUVEAU
                                if (cubeOverlay != null)
                                {
                                    GameObject cube = cubeOverlay.GetCubeForImage(imgName);
                                    if (cube != null)
                                    {
                                        ImageHighlight hl = cube.GetComponent<ImageHighlight>();
                                        if (hl != null) hl.PlayCorrectEffect();
                                    }
                                }

                                // ── Étoile suivante ← NOUVEAU
                                if (StarUIManager.Instance != null)
                                    StarUIManager.Instance.LightNextStar();
                            }
                            break;
                        }
                    }
                }

                string color = inCorrectPosition ? "green"
                             : !detected ? "white"
                             : state == TrackingState.Tracking ? "white" : "red";

                sb.AppendLine($"    <color={color}>{icon} {imgName} [{state}] {cacheIcon}</color>");
            }
            sb.AppendLine();
        }

        sb.AppendLine("----------------------------");
        sb.AppendLine("○=non détecté ✓=tracké ~=perdu VERT=validé");
        uiText.text = sb.ToString();
    }

    // ─────────────────────────────────────────────
    // FIX PRINCIPAL : pas de GraphicRaycaster → ne bloque plus le bouton Fermer
    void CreerUI()
    {
        GameObject canvasObj   = new GameObject("CanvasTest");
        Canvas canvas          = canvasObj.AddComponent<Canvas>();
        canvas.renderMode      = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder    = 0;

        canvasObj.AddComponent<CanvasScaler>();
        // ⚠️ GraphicRaycaster supprimé intentionnellement
        // Ce canvas est lecture seule — il n'a pas besoin de recevoir des taps

        GameObject textObj = new GameObject("UIText");
        textObj.transform.SetParent(canvasObj.transform, false);

        uiText                 = textObj.AddComponent<Text>();
        uiText.font            = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        uiText.fontSize        = 28;
        uiText.color           = Color.white;
        uiText.alignment       = TextAnchor.UpperLeft;
        uiText.supportRichText = true;
        uiText.raycastTarget   = false; // le texte ne capte aucun tap

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin     = new Vector2(0, 0);
        rt.anchorMax     = new Vector2(1, 1);
        rt.offsetMin     = new Vector2(20, 20);
        rt.offsetMax     = new Vector2(-20, -20);
    }
}
/*code apres la modification de datamanager
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

[RequireComponent(typeof(ARTrackedImageManager))]
public class Book1Detector : MonoBehaviour
{
    // ─────────────────────────────────────────────
    // Structures
    // ─────────────────────────────────────────────

    [System.Serializable]
    public struct Page
    {
        public string feuilleName;
        public string pageId;
        public List<string> imageNames;
        public List<Vector3> positionsCorrectes;
    }

    // ─────────────────────────────────────────────
    // Inspecteur
    // ─────────────────────────────────────────────

    [Header("AR")]
    public ARTrackedImageManager trackedImageManager;

    [Header("Validation")]
    public float distanceMax = 0.05f;

    [Header("Liaison ARImageCubeOverlay")]
    public ARImageCubeOverlay cubeOverlay;

    // ─────────────────────────────────────────────
    // État interne
    // ─────────────────────────────────────────────

    private const string BOOK_ID = "book_001";

    // Pages construites depuis le JSON
    private List<Page> pages = new List<Page>();
    private bool pagesLoaded = false;

    // Page courante
    private string currentPageId = "";
    private bool switching = false;

    // Tracking AR
    private Dictionary<string, TrackingState> detectedImages    = new Dictionary<string, TrackingState>();
    public  Dictionary<string, Vector3>       positionsGlobales = new Dictionary<string, Vector3>();
    public  Dictionary<string, ARTrackedImage> trackedImages    = new Dictionary<string, ARTrackedImage>();
    private ARTrackedImage feuilleDetectee = null;
    public  HashSet<string> imagesValidees = new HashSet<string>();

    // UI
    private Text uiText;

    // ─────────────────────────────────────────────
    // Lifecycle
    // ─────────────────────────────────────────────

    void Awake()
    {
        if (trackedImageManager == null)
            trackedImageManager = GetComponent<ARTrackedImageManager>();

        CreerUI();
    }

    void Start()
    {
        StartCoroutine(WaitForDataAndLoad());
    }

    void OnEnable()  => trackedImageManager.trackedImagesChanged += OnImagesChanged;
    void OnDisable() => trackedImageManager.trackedImagesChanged -= OnImagesChanged;

    void Update() => MettreAJourUI();

    // ─────────────────────────────────────────────
    // Chargement JSON → construction des pages
    // ─────────────────────────────────────────────

    IEnumerator WaitForDataAndLoad()
    {
        // Attendre que le DataManager et le catalogue soient prêts
        yield return new WaitUntil(() => DataManager.Instance != null);
        yield return new WaitUntil(() => DataManager.Instance.GetBookEntry(BOOK_ID) != null);

        // Charger le livre (ignoré si déjà chargé côté DataManager)
        yield return StartCoroutine(DataManager.Instance.LoadBookFromUrl(BOOK_ID));

        BuildPagesFromData();
    }

    void BuildPagesFromData()
    {
        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(BOOK_ID);
        if (bookData == null)
        {
            Debug.LogError("[Book1Detector] BookData introuvable après chargement.");
            return;
        }

        pages.Clear();

        foreach (ARBook.Models.PageData pageData in bookData.pages)
        {
            Page page = new Page
            {
                feuilleName        = pageData.feuille,
                pageId             = pageData.id,
                imageNames         = new List<string>(),
                positionsCorrectes = new List<Vector3>()
            };

            foreach (ARBook.Models.ItemData item in pageData.items)
            {
                page.imageNames.Add(item.nom);
                page.positionsCorrectes.Add(new Vector3(item.x, item.y, item.z));
            }

            pages.Add(page);
            Debug.Log($"[Book1Detector] Page construite : {page.pageId} | feuille : {page.feuilleName} | {page.imageNames.Count} image(s)");
        }

        pagesLoaded = true;
        Debug.Log($"[Book1Detector] ✅ {pages.Count} page(s) chargée(s) depuis JSON.");
    }

    // ─────────────────────────────────────────────
    // AR Events
    // ─────────────────────────────────────────────

    void OnImagesChanged(ARTrackedImagesChangedEventArgs args)
    {
        if (!pagesLoaded) return;

        foreach (var img in args.added)
        {
            detectedImages[img.referenceImage.name] = img.trackingState;
            trackedImages[img.referenceImage.name]  = img;
            TraiterFeuille(img);
        }

        foreach (var img in args.updated)
        {
            detectedImages[img.referenceImage.name] = img.trackingState;
            trackedImages[img.referenceImage.name]  = img;

            if (img.trackingState == TrackingState.Tracking)
                TraiterFeuille(img);
        }

        foreach (var img in args.removed)
        {
            detectedImages.Remove(img.referenceImage.name);
            trackedImages.Remove(img.referenceImage.name);
        }

        MettreAJourUI();
    }

    // ─────────────────────────────────────────────
    // Traitement feuille détectée
    // ─────────────────────────────────────────────

    void TraiterFeuille(ARTrackedImage img)
    {
        if (switching) return;

        foreach (var page in pages)
        {
            if (img.referenceImage.name == page.feuilleName)
            {
                if (currentPageId != page.pageId)
                {
                    // ── NOUVEAU : prévenir DataManager pour le préchargement prédictif ──
                    // DataManager va charger en priorité cette page, puis les voisines en background
                    DataManager.Instance.OnPageDetected(BOOK_ID, page.pageId);

                    StartCoroutine(SwitchPage(page, img));
                }
                else
                {
                    feuilleDetectee = img;
                    CalculerPositions(page);
                }
                return;
            }
        }
    }

    IEnumerator SwitchPage(Page page, ARTrackedImage feuille)
    {
        switching = true;
        currentPageId = page.pageId;

        // Réinitialisation de l'état de tracking
        detectedImages.Clear();
        positionsGlobales.Clear();
        trackedImages.Clear();
        imagesValidees.Clear();

        if (cubeOverlay != null)
            cubeOverlay.ClearAllCubes();

        feuilleDetectee = feuille;

        // Laisser le temps au moteur AR de se stabiliser
        yield return null;
        yield return null;
        yield return null;

        CalculerPositions(page);
        StartCoroutine(RespawnAvecRetry(5, 0.1f));

        Debug.Log($"📘 Page active : {page.pageId}");

        switching = false;
        MettreAJourUI();
    }

    IEnumerator RespawnAvecRetry(int tentatives, float intervalle)
    {
        for (int i = 0; i < tentatives; i++)
        {
            // Les assets sont déjà en cache grâce au préchargement prédictif du DataManager.
            // GetPrefab() et GetImage() retournent immédiatement sans délai.
            if (cubeOverlay != null)
                cubeOverlay.RespawnCubesForActiveTrackables();

            yield return new WaitForSeconds(intervalle);
        }
    }

    // ─────────────────────────────────────────────
    // Calcul des positions globales des items
    // ─────────────────────────────────────────────

    void CalculerPositions(Page page)
    {
        if (feuilleDetectee == null) return;

        positionsGlobales.Clear();

        for (int i = 0; i < page.imageNames.Count; i++)
        {
            if (i >= page.positionsCorrectes.Count) continue;

            Vector3 globalPos =
                feuilleDetectee.transform.position +
                feuilleDetectee.transform.TransformVector(page.positionsCorrectes[i]);

            positionsGlobales[page.imageNames[i]] = globalPos;

            Debug.Log($"📍 {page.imageNames[i]} => {globalPos}");
        }
    }

    // ─────────────────────────────────────────────
    // Accès aux assets (lecture cache DataManager)
    // ─────────────────────────────────────────────

    /// <summary>
    /// Retourne le prefab 3D depuis le cache DataManager.
    /// Toujours disponible immédiatement si OnPageDetected a été appelé avant.
    /// </summary>
    public GameObject GetPrefabForItem(string itemName)
    {
        return DataManager.Instance.GetPrefab(itemName);
    }

    /// <summary>
    /// Retourne la texture depuis le cache DataManager.
    /// Toujours disponible immédiatement si OnPageDetected a été appelé avant.
    /// </summary>
    public Texture2D GetImageForItem(string itemName)
    {
        return DataManager.Instance.GetImage(itemName);
    }

    /// <summary>
    /// Vérifie si prefab ET image sont prêts pour un item donné.
    /// Utiliser avant d'appeler GetPrefabForItem / GetImageForItem.
    /// </summary>
    public bool IsItemReady(string itemName)
    {
        return DataManager.Instance.IsAssetReady(itemName);
    }

    /// <summary>
    /// Retourne les données métier d'un item (description, etc.)
    /// </summary>
    public ARBook.Models.ItemData GetItemData(string itemName)
    {
        return DataManager.Instance.GetItemData(BOOK_ID, itemName);
    }

    // ─────────────────────────────────────────────
    // UI Debug
    // ─────────────────────────────────────────────

    void MettreAJourUI()
    {
        if (uiText == null) return;

        System.Text.StringBuilder sb = new System.Text.StringBuilder();

        sb.AppendLine("═══ AR LIBRARY TESTER ═══");

        sb.AppendLine(string.IsNullOrEmpty(currentPageId)
            ? "📚 Page active : aucune"
            : $"📚 Page active : {currentPageId}");

        sb.AppendLine($"🔍 Images trackées : {detectedImages.Count}");

        if (!pagesLoaded)
        {
            sb.AppendLine("⏳ Chargement des données JSON...");
            uiText.text = sb.ToString();
            return;
        }

        sb.AppendLine("----------------------------");

        foreach (var page in pages)
        {
            bool isActive = page.pageId == currentPageId;
            string prefix = isActive ? "▶ " : "  ";

            sb.AppendLine($"{prefix}[{page.pageId}] feuille: {page.feuilleName}");

            foreach (string imgName in page.imageNames)
            {
                bool detected = detectedImages.ContainsKey(imgName);
                TrackingState state = detected ? detectedImages[imgName] : TrackingState.None;

                string icon = !detected ? "○" :
                              state == TrackingState.Tracking ? "✓" : "~";

                // ── NOUVEAU : affichage de l'état du cache DataManager ──
                bool assetReady = DataManager.Instance.IsAssetReady(imgName);
                string cacheIcon = assetReady ? "💾" : "⏳";

                bool inCorrectPosition = false;

                if (imagesValidees.Contains(imgName))
                {
                    inCorrectPosition = true;
                }
                else if (detected && positionsGlobales.ContainsKey(imgName))
                {
                    foreach (var tracked in trackedImageManager.trackables)
                    {
                        if (tracked.referenceImage.name == imgName)
                        {
                            float dist = Vector3.Distance(
                                tracked.transform.position,
                                positionsGlobales[imgName]
                            );

                            if (dist <= distanceMax)
                            {
                                inCorrectPosition = true;
                                imagesValidees.Add(imgName);
                                Debug.Log("✅ VALIDÉ définitivement : " + imgName);
                            }

                            break;
                        }
                    }
                }

                string color =
                    inCorrectPosition ? "green" :
                    (!detected ? "white" :
                    state == TrackingState.Tracking ? "white" : "red");

                sb.AppendLine($"    <color={color}>{icon} {imgName} [{state}] {cacheIcon}</color>");
            }

            sb.AppendLine();
        }

        sb.AppendLine("----------------------------");
        sb.AppendLine("○ = pas détecté");
        sb.AppendLine("✓ = détecté + tracké");
        sb.AppendLine("~ = perdu");
        sb.AppendLine("VERT = bien placé ✅");
        sb.AppendLine("💾 = asset en cache | ⏳ = en chargement");

        uiText.text = sb.ToString();
    }

    void CreerUI()
    {
        GameObject canvasObj = new GameObject("CanvasTest");
        Canvas canvas = canvasObj.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;

        canvasObj.AddComponent<CanvasScaler>();
        canvasObj.AddComponent<GraphicRaycaster>();

        GameObject textObj = new GameObject("UIText");
        textObj.transform.SetParent(canvasObj.transform, false);

        uiText = textObj.AddComponent<Text>();
        uiText.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        uiText.fontSize = 28;
        uiText.color = Color.white;
        uiText.alignment = TextAnchor.UpperLeft;
        uiText.supportRichText = true;

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0, 0);
        rt.anchorMax = new Vector2(1, 1);
        rt.offsetMin = new Vector2(20, 20);
        rt.offsetMax = new Vector2(-20, -20);
    }
}
/*code apres l'ajout des apis 
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

[RequireComponent(typeof(ARTrackedImageManager))]
public class Book1Detector : MonoBehaviour
{
    [System.Serializable]
    public struct Page
    {
        public string feuilleName;
        public string pageId;
        public List<string> imageNames;
        public List<Vector3> positionsCorrectes;
    }

    [Header("AR")]
    public ARTrackedImageManager trackedImageManager;

    [Header("Validation")]
    public float distanceMax = 0.05f;

    [Header("Liaison ARImageCubeOverlay")]
    public ARImageCubeOverlay cubeOverlay;

    // ── Rempli dynamiquement depuis le JSON ──
    private List<Page> pages = new List<Page>();

    private string currentPageId = "";
    private bool switching = false;
    private bool pagesLoaded = false;

    private Dictionary<string, TrackingState> detectedImages     = new Dictionary<string, TrackingState>();
    public  Dictionary<string, Vector3>       positionsGlobales  = new Dictionary<string, Vector3>();
    public  Dictionary<string, ARTrackedImage> trackedImages     = new Dictionary<string, ARTrackedImage>();

    private ARTrackedImage feuilleDetectee = null;
    public  HashSet<string> imagesValidees = new HashSet<string>();

    private Text uiText;

    private const string BOOK_ID = "book_001";

    // ─────────────────────────────────────────────
    // Lifecycle
    // ─────────────────────────────────────────────
    void Awake()
    {
        if (trackedImageManager == null)
            trackedImageManager = GetComponent<ARTrackedImageManager>();

        CreerUI();
    }

    void Start()
    {
        StartCoroutine(WaitForDataAndLoad());
    }

    void OnEnable()  => trackedImageManager.trackedImagesChanged += OnImagesChanged;
    void OnDisable() => trackedImageManager.trackedImagesChanged -= OnImagesChanged;

    void Update() => MettreAJourUI();

    // ─────────────────────────────────────────────
    // Chargement JSON → construction des pages
    // ─────────────────────────────────────────────
    IEnumerator WaitForDataAndLoad()
    {
        yield return new WaitUntil(() => DataManager.Instance != null);
        yield return new WaitUntil(() => DataManager.Instance.GetBookEntry(BOOK_ID) != null);
        yield return StartCoroutine(DataManager.Instance.LoadBookFromUrl(BOOK_ID));
        BuildPagesFromData();
    }

    void BuildPagesFromData()
    {
        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(BOOK_ID);
        if (bookData == null)
        {
            Debug.LogError("[Book1Detector] BookData introuvable après chargement.");
            return;
        }

        pages.Clear();

        foreach (ARBook.Models.PageData pageData in bookData.pages)
        {
            Page page = new Page
            {
                feuilleName        = pageData.feuille,
                pageId             = pageData.id,
                imageNames         = new List<string>(),
                positionsCorrectes = new List<Vector3>()
            };

            foreach (ARBook.Models.ItemData item in pageData.items)
            {
                page.imageNames.Add(item.nom);
                page.positionsCorrectes.Add(new Vector3(item.x, item.y, item.z));
            }

            pages.Add(page);
            Debug.Log($"[Book1Detector] Page construite : {page.pageId} | feuille : {page.feuilleName} | {page.imageNames.Count} image(s)");
        }

        pagesLoaded = true;
        Debug.Log($"[Book1Detector] ✅ {pages.Count} page(s) chargée(s) depuis JSON.");
    }

    // ─────────────────────────────────────────────
    // AR Events
    // ─────────────────────────────────────────────
    void OnImagesChanged(ARTrackedImagesChangedEventArgs args)
    {
        if (!pagesLoaded) return;

        foreach (var img in args.added)
        {
            detectedImages[img.referenceImage.name] = img.trackingState;
            trackedImages[img.referenceImage.name]  = img;
            TraiterFeuille(img);
        }

        foreach (var img in args.updated)
        {
            detectedImages[img.referenceImage.name] = img.trackingState;
            trackedImages[img.referenceImage.name]  = img;

            if (img.trackingState == TrackingState.Tracking)
                TraiterFeuille(img);
        }

        foreach (var img in args.removed)
        {
            detectedImages.Remove(img.referenceImage.name);
            trackedImages.Remove(img.referenceImage.name);
        }

        MettreAJourUI();
    }

    void TraiterFeuille(ARTrackedImage img)
    {
        if (switching) return;

        foreach (var page in pages)
        {
            if (img.referenceImage.name == page.feuilleName)
            {
                if (currentPageId != page.pageId)
                    StartCoroutine(SwitchPage(page, img));
                else
                {
                    feuilleDetectee = img;
                    CalculerPositions(page);
                }
                return;
            }
        }
    }

    IEnumerator SwitchPage(Page page, ARTrackedImage feuille)
    {
        switching = true;
        currentPageId = page.pageId;

        detectedImages.Clear();
        positionsGlobales.Clear();
        trackedImages.Clear();
        imagesValidees.Clear();

        if (cubeOverlay != null)
            cubeOverlay.ClearAllCubes();

        feuilleDetectee = feuille;

        yield return null;
        yield return null;
        yield return null;

        CalculerPositions(page);
        StartCoroutine(RespawnAvecRetry(5, 0.1f));

        Debug.Log("📘 Page active : " + page.pageId);

        switching = false;
        MettreAJourUI();
    }

    IEnumerator RespawnAvecRetry(int tentatives, float intervalle)
    {
        for (int i = 0; i < tentatives; i++)
        {
            if (cubeOverlay != null)
                cubeOverlay.RespawnCubesForActiveTrackables();

            yield return new WaitForSeconds(intervalle);
        }
    }

    void CalculerPositions(Page page)
    {
        if (feuilleDetectee == null) return;

        positionsGlobales.Clear();

        for (int i = 0; i < page.imageNames.Count; i++)
        {
            if (i >= page.positionsCorrectes.Count) continue;

            Vector3 globalPos =
                feuilleDetectee.transform.position +
                feuilleDetectee.transform.TransformVector(page.positionsCorrectes[i]);

            positionsGlobales[page.imageNames[i]] = globalPos;

            Debug.Log($"📍 {page.imageNames[i]} => {globalPos}");
        }
    }

    // ─────────────────────────────────────────────
    // UI — identique à l'original
    // ─────────────────────────────────────────────
    void MettreAJourUI()
    {
        if (uiText == null) return;

        System.Text.StringBuilder sb = new System.Text.StringBuilder();

        sb.AppendLine("═══ AR LIBRARY TESTER ═══");

        sb.AppendLine(string.IsNullOrEmpty(currentPageId)
            ? "📚 Page active : aucune"
            : $"📚 Page active : {currentPageId}");

        sb.AppendLine($"🔍 Images trackées : {detectedImages.Count}");

        // Message de chargement si les pages ne sont pas encore prêtes
        if (!pagesLoaded)
        {
            sb.AppendLine("⏳ Chargement des données JSON...");
            uiText.text = sb.ToString();
            return;
        }

        sb.AppendLine("----------------------------");

        foreach (var page in pages)
        {
            bool isActive = page.pageId == currentPageId;
            string prefix = isActive ? "▶ " : "  ";

            sb.AppendLine($"{prefix}[{page.pageId}] feuille: {page.feuilleName}");

            foreach (string imgName in page.imageNames)
            {
                bool detected = detectedImages.ContainsKey(imgName);
                TrackingState state = detected ? detectedImages[imgName] : TrackingState.None;

                string icon = !detected ? "○" :
                              state == TrackingState.Tracking ? "✓" : "~";

                bool inCorrectPosition = false;

                if (imagesValidees.Contains(imgName))
                {
                    inCorrectPosition = true;
                }
                else if (detected && positionsGlobales.ContainsKey(imgName))
                {
                    foreach (var tracked in trackedImageManager.trackables)
                    {
                        if (tracked.referenceImage.name == imgName)
                        {
                            float dist = Vector3.Distance(
                                tracked.transform.position,
                                positionsGlobales[imgName]
                            );

                            if (dist <= distanceMax)
                            {
                                inCorrectPosition = true;
                                imagesValidees.Add(imgName);
                                Debug.Log("✅ VALIDÉ définitivement : " + imgName);
                            }

                            break;
                        }
                    }
                }

                string color =
                    inCorrectPosition ? "green" :
                    (!detected ? "white" :
                    state == TrackingState.Tracking ? "white" : "red");

                sb.AppendLine($"    <color={color}>{icon} {imgName} [{state}]</color>");
            }

            sb.AppendLine();
        }

        sb.AppendLine("----------------------------");
        sb.AppendLine("○ = pas détecté");
        sb.AppendLine("✓ = détecté + tracké");
        sb.AppendLine("~ = perdu");
        sb.AppendLine("VERT = bien placé ✅");

        uiText.text = sb.ToString();
    }

    void CreerUI()
    {
        GameObject canvasObj = new GameObject("CanvasTest");
        Canvas canvas = canvasObj.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;

        canvasObj.AddComponent<CanvasScaler>();
        canvasObj.AddComponent<GraphicRaycaster>();

        GameObject textObj = new GameObject("UIText");
        textObj.transform.SetParent(canvasObj.transform, false);

        uiText = textObj.AddComponent<Text>();
        uiText.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        uiText.fontSize = 28;
        uiText.color = Color.white;
        uiText.alignment = TextAnchor.UpperLeft;
        uiText.supportRichText = true;

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0, 0);
        rt.anchorMax = new Vector2(1, 1);
        rt.offsetMin = new Vector2(20, 20);
        rt.offsetMax = new Vector2(-20, -20);
    }
}
/*book1detector avant l'ajout des apis*
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

[RequireComponent(typeof(ARTrackedImageManager))]
public class Book1Detector : MonoBehaviour
{
    [System.Serializable]
    public struct Page
    {
        public string feuilleName;
        public string pageId;
        public List<string> imageNames;

        [Tooltip("Positions locales par rapport à la feuille")]
        public List<Vector3> positionsCorrectes;
    }

    [Header("Pages")]
    public List<Page> pages = new List<Page>();

    [Header("AR")]
    public ARTrackedImageManager trackedImageManager;

    [Header("Validation")]
    public float distanceMax = 0.05f;

    [Header("Liaison ARImageCubeOverlay")]
    public ARImageCubeOverlay cubeOverlay;

    private string currentPageId = "";
    private bool switching = false;

    private Dictionary<string, TrackingState> detectedImages   = new Dictionary<string, TrackingState>();
    public  Dictionary<string, Vector3>       positionsGlobales = new Dictionary<string, Vector3>();
    public  Dictionary<string, ARTrackedImage> trackedImages    = new Dictionary<string, ARTrackedImage>();

    private ARTrackedImage feuilleDetectee = null;

    public HashSet<string> imagesValidees = new HashSet<string>();

    private Text uiText;

    void Awake()
    {
        if (trackedImageManager == null)
            trackedImageManager = GetComponent<ARTrackedImageManager>();

        CreerUI();
    }

    void OnEnable()
    {
        trackedImageManager.trackedImagesChanged += OnImagesChanged;
    }

    void OnDisable()
    {
        trackedImageManager.trackedImagesChanged -= OnImagesChanged;
    }

    void OnImagesChanged(ARTrackedImagesChangedEventArgs args)
    {
        foreach (var img in args.added)
        {
            detectedImages[img.referenceImage.name] = img.trackingState;
            trackedImages[img.referenceImage.name]  = img;
            TraiterFeuille(img);
        }

        foreach (var img in args.updated)
        {
            detectedImages[img.referenceImage.name] = img.trackingState;
            trackedImages[img.referenceImage.name]  = img;

            if (img.trackingState == TrackingState.Tracking)
                TraiterFeuille(img);
        }

        foreach (var img in args.removed)
        {
            detectedImages.Remove(img.referenceImage.name);
            trackedImages.Remove(img.referenceImage.name);
        }

        MettreAJourUI();
    }

    void TraiterFeuille(ARTrackedImage img)
    {
        // Si un switch est en cours, on ignore pour éviter les conflits
        if (switching) return;

        foreach (var page in pages)
        {
            if (img.referenceImage.name == page.feuilleName)
            {
                if (currentPageId != page.pageId)
                    StartCoroutine(SwitchPage(page, img));
                else
                {
                    feuilleDetectee = img;
                    CalculerPositions(page);
                }
                return;
            }
        }
    }

    IEnumerator SwitchPage(Page page, ARTrackedImage feuille)
    {
        switching = true;

        currentPageId = page.pageId;

        detectedImages.Clear();
        positionsGlobales.Clear();
        trackedImages.Clear();
        imagesValidees.Clear();

        // Supprime tous les cubes de l'ancienne feuille immédiatement
        if (cubeOverlay != null)
            cubeOverlay.ClearAllCubes();

        feuilleDetectee = feuille;

        // Attend 3 frames pour laisser AR Foundation re-peupler ses trackables
        yield return null;
        yield return null;
        yield return null;

        CalculerPositions(page);

        // Tente le respawn 5 fois toutes les 100ms
        // pour attraper les images qui reviennent progressivement
        StartCoroutine(RespawnAvecRetry(5, 0.1f));

        Debug.Log("📘 Page active : " + page.pageId);

        switching = false;
        MettreAJourUI();
    }

    // Réessaie le respawn N fois toutes les X secondes
    IEnumerator RespawnAvecRetry(int tentatives, float intervalle)
    {
        for (int i = 0; i < tentatives; i++)
        {
            if (cubeOverlay != null)
                cubeOverlay.RespawnCubesForActiveTrackables();

            yield return new WaitForSeconds(intervalle);
        }
    }

    void CalculerPositions(Page page)
    {
        if (feuilleDetectee == null) return;

        positionsGlobales.Clear();

        for (int i = 0; i < page.imageNames.Count; i++)
        {
            if (i >= page.positionsCorrectes.Count) continue;

            Vector3 localOffset = page.positionsCorrectes[i];

            Vector3 globalPos =
                feuilleDetectee.transform.position +
                feuilleDetectee.transform.TransformVector(localOffset);

            positionsGlobales[page.imageNames[i]] = globalPos;

            Debug.Log($"📍 {page.imageNames[i]} => {globalPos}");
        }
    }

    void Update()
    {
        MettreAJourUI();
    }

    void MettreAJourUI()
    {
        if (uiText == null) return;

        System.Text.StringBuilder sb = new System.Text.StringBuilder();

        sb.AppendLine("═══ AR LIBRARY TESTER ═══");

        sb.AppendLine(string.IsNullOrEmpty(currentPageId)
            ? "📚 Page active : aucune"
            : $"📚 Page active : {currentPageId}");

        sb.AppendLine($"🔍 Images trackées : {detectedImages.Count}");
        sb.AppendLine("----------------------------");

        foreach (var page in pages)
        {
            bool isActive = page.pageId == currentPageId;
            string prefix = isActive ? "▶ " : "  ";

            sb.AppendLine($"{prefix}[{page.pageId}] feuille: {page.feuilleName}");

            foreach (string imgName in page.imageNames)
            {
                bool detected = detectedImages.ContainsKey(imgName);
                TrackingState state = detected ? detectedImages[imgName] : TrackingState.None;

                string icon = !detected ? "○" :
                              state == TrackingState.Tracking ? "✓" : "~";

                bool inCorrectPosition = false;

                if (imagesValidees.Contains(imgName))
                {
                    inCorrectPosition = true;
                }
                else if (detected && positionsGlobales.ContainsKey(imgName))
                {
                    foreach (var tracked in trackedImageManager.trackables)
                    {
                        if (tracked.referenceImage.name == imgName)
                        {
                            float dist = Vector3.Distance(
                                tracked.transform.position,
                                positionsGlobales[imgName]
                            );

                            if (dist <= distanceMax)
                            {
                                inCorrectPosition = true;
                                imagesValidees.Add(imgName);
                                Debug.Log("✅ VALIDÉ définitivement : " + imgName);
                            }

                            break;
                        }
                    }
                }

                string color =
                    inCorrectPosition ? "green" :
                    (!detected ? "white" :
                    state == TrackingState.Tracking ? "white" : "red");

                sb.AppendLine($"    <color={color}>{icon} {imgName} [{state}]</color>");
            }

            sb.AppendLine();
        }

        sb.AppendLine("----------------------------");
        sb.AppendLine("○ = pas détecté");
        sb.AppendLine("✓ = détecté + tracké");
        sb.AppendLine("~ = perdu");
        sb.AppendLine("VERT = bien placé ✅");

        uiText.text = sb.ToString();
    }

    void CreerUI()
    {
        GameObject canvasObj = new GameObject("CanvasTest");
        Canvas canvas = canvasObj.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;

        canvasObj.AddComponent<CanvasScaler>();
        canvasObj.AddComponent<GraphicRaycaster>();

        GameObject textObj = new GameObject("UIText");
        textObj.transform.SetParent(canvasObj.transform, false);

        uiText = textObj.AddComponent<Text>();
        uiText.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        uiText.fontSize = 28;
        uiText.color = Color.white;
        uiText.alignment = TextAnchor.UpperLeft;
        uiText.supportRichText = true;

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0, 0);
        rt.anchorMax = new Vector2(1, 1);
        rt.offsetMin = new Vector2(20, 20);
        rt.offsetMax = new Vector2(-20, -20);
    }
}
/* code sans relation avec le code de l'interaction
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

[RequireComponent(typeof(ARTrackedImageManager))]
public class ARLibraryTester : MonoBehaviour
{
    [System.Serializable]
    public struct Page
    {
        public string feuilleName;
        public string pageId;
        public List<string> imageNames;

        [Tooltip("Positions locales par rapport à la feuille")]
        public List<Vector3> positionsCorrectes;
    }

    [Header("Pages")]
    public List<Page> pages = new List<Page>();

    [Header("AR")]
    public ARTrackedImageManager trackedImageManager;

    [Header("Validation")]
    public float distanceMax = 0.05f;

    private string currentPageId = "";
    private bool switching = false;

    private Dictionary<string, TrackingState> detectedImages  = new Dictionary<string, TrackingState>();
    public  Dictionary<string, Vector3>       positionsGlobales = new Dictionary<string, Vector3>();
    public  Dictionary<string, ARTrackedImage> trackedImages   = new Dictionary<string, ARTrackedImage>();

    private ARTrackedImage feuilleDetectee = null;

    public HashSet<string> imagesValidees = new HashSet<string>();

    private Text uiText;

    void Awake()
    {
        if (trackedImageManager == null)
            trackedImageManager = GetComponent<ARTrackedImageManager>();

        CreerUI();
    }

    void OnEnable()
    {
        trackedImageManager.trackedImagesChanged += OnImagesChanged;
    }

    void OnDisable()
    {
        trackedImageManager.trackedImagesChanged -= OnImagesChanged;
    }

    void OnImagesChanged(ARTrackedImagesChangedEventArgs args)
    {
        foreach (var img in args.added)
        {
            detectedImages[img.referenceImage.name] = img.trackingState;
            trackedImages[img.referenceImage.name]  = img;
            TraiterFeuille(img);
        }

        foreach (var img in args.updated)
        {
            detectedImages[img.referenceImage.name] = img.trackingState;
            trackedImages[img.referenceImage.name]  = img;

            if (img.trackingState == TrackingState.Tracking)
                TraiterFeuille(img);
        }

        foreach (var img in args.removed)
        {
            detectedImages.Remove(img.referenceImage.name);
            trackedImages.Remove(img.referenceImage.name);
        }

        MettreAJourUI();
    }

    void TraiterFeuille(ARTrackedImage img)
    {
        foreach (var page in pages)
        {
            if (img.referenceImage.name == page.feuilleName)
            {
                if (currentPageId != page.pageId)
                    StartCoroutine(SwitchPage(page, img));
                else
                {
                    feuilleDetectee = img;
                    CalculerPositions(page);
                }
                return;
            }
        }
    }

    IEnumerator SwitchPage(Page page, ARTrackedImage feuille)
    {
        switching = true;

        currentPageId = page.pageId;

        detectedImages.Clear();
        positionsGlobales.Clear();
        trackedImages.Clear();
        imagesValidees.Clear();

        feuilleDetectee = feuille;

        yield return null;

        CalculerPositions(page);

        Debug.Log("📘 Page active : " + page.pageId);

        switching = false;
        MettreAJourUI();
    }

    void CalculerPositions(Page page)
    {
        if (feuilleDetectee == null) return;

        positionsGlobales.Clear();

        for (int i = 0; i < page.imageNames.Count; i++)
        {
            if (i >= page.positionsCorrectes.Count) continue;

            Vector3 localOffset = page.positionsCorrectes[i];

            Vector3 globalPos =
                feuilleDetectee.transform.position +
                feuilleDetectee.transform.TransformVector(localOffset);

            positionsGlobales[page.imageNames[i]] = globalPos;

            Debug.Log($"📍 {page.imageNames[i]} => {globalPos}");
        }
    }

    void Update()
    {
        MettreAJourUI();
    }

    void MettreAJourUI()
    {
        if (uiText == null) return;

        System.Text.StringBuilder sb = new System.Text.StringBuilder();

        sb.AppendLine("═══ AR LIBRARY TESTER ═══");

        sb.AppendLine(string.IsNullOrEmpty(currentPageId)
            ? "📚 Page active : aucune"
            : $"📚 Page active : {currentPageId}");

        sb.AppendLine($"🔍 Images trackées : {detectedImages.Count}");
        sb.AppendLine("----------------------------");

        foreach (var page in pages)
        {
            bool isActive = page.pageId == currentPageId;
            string prefix = isActive ? "▶ " : "  ";

            sb.AppendLine($"{prefix}[{page.pageId}] feuille: {page.feuilleName}");

            foreach (string imgName in page.imageNames)
            {
                bool detected = detectedImages.ContainsKey(imgName);
                TrackingState state = detected ? detectedImages[imgName] : TrackingState.None;

                string icon = !detected ? "○" :
                              state == TrackingState.Tracking ? "✓" : "~";

                bool inCorrectPosition = false;

                if (imagesValidees.Contains(imgName))
                {
                    inCorrectPosition = true;
                }
                else if (detected && positionsGlobales.ContainsKey(imgName))
                {
                    foreach (var tracked in trackedImageManager.trackables)
                    {
                        if (tracked.referenceImage.name == imgName)
                        {
                            float dist = Vector3.Distance(
                                tracked.transform.position,
                                positionsGlobales[imgName]
                            );

                            if (dist <= distanceMax)
                            {
                                inCorrectPosition = true;
                                imagesValidees.Add(imgName);
                                Debug.Log("✅ VALIDÉ définitivement : " + imgName);
                            }

                            break;
                        }
                    }
                }

                string color =
                    inCorrectPosition ? "green" :
                    (!detected ? "white" :
                    state == TrackingState.Tracking ? "white" : "red");

                sb.AppendLine($"    <color={color}>{icon} {imgName} [{state}]</color>");
            }

            sb.AppendLine();
        }

        sb.AppendLine("----------------------------");
        sb.AppendLine("○ = pas détecté");
        sb.AppendLine("✓ = détecté + tracké");
        sb.AppendLine("~ = perdu");
        sb.AppendLine("VERT = bien placé ✅");

        uiText.text = sb.ToString();
    }

    void CreerUI()
    {
        GameObject canvasObj = new GameObject("CanvasTest");
        Canvas canvas = canvasObj.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;

        canvasObj.AddComponent<CanvasScaler>();
        canvasObj.AddComponent<GraphicRaycaster>();

        GameObject textObj = new GameObject("UIText");
        textObj.transform.SetParent(canvasObj.transform, false);

        uiText = textObj.AddComponent<Text>();
        uiText.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        uiText.fontSize = 28;
        uiText.color = Color.white;
        uiText.alignment = TextAnchor.UpperLeft;
        uiText.supportRichText = true;

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0, 0);
        rt.anchorMax = new Vector2(1, 1);
        rt.offsetMin = new Vector2(20, 20);
        rt.offsetMax = new Vector2(-20, -20);
    }
}*/