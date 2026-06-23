/*code 08/06/2026*/
/*claude solution*/
/*version : InverseTransformPoint live (sans rotation figée) + validation N frames + UI page active seulement*/
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

/// <summary>
/// Book1Detector — Scène AR.
///
/// CE SCRIPT NE TÉLÉCHARGE RIEN.
/// Il lit DataManager.LastLoadedBookId pour savoir quel livre afficher.
///
/// Calcul de position :
/// - InverseTransformPoint live (position ET rotation live de la feuille)
/// - Comparaison XZ seulement (plan plat, Y ignoré)
/// - Validation après framesRequises frames consécutives correctes
///
/// Pourquoi sans rotation figée :
/// - Position live + rotation figée = matrice incohérente → instabilité
/// - InverseTransformPoint utilise position ET rotation du même instant → cohérent
/// </summary>
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
    public float distanceMax       = 0.05f;  // 5cm
    public int   framesRequises    = 10;     // frames consécutives pour valider
    public float uiRefreshInterval = 0.2f;  // rafraîchissement UI toutes les 200ms

    [Header("Liaison ARImageCubeOverlay")]
    public ARImageCubeOverlay cubeOverlay;

    // ── bookId résolu dynamiquement depuis DataManager.LastLoadedBookId ──
    private string _bookId = "";

    private List<Page> pages     = new List<Page>();
    private bool pagesLoaded     = false;
    private string currentPageId = "";
    private bool switching       = false;

    private Dictionary<string, TrackingState>  detectedImages = new Dictionary<string, TrackingState>();
    public  Dictionary<string, ARTrackedImage> trackedImages  = new Dictionary<string, ARTrackedImage>();
    private ARTrackedImage feuilleDetectee = null;
    public  HashSet<string> imagesValidees = new HashSet<string>();

    // ── positionsGlobales gardé pour compatibilité avec cubeOverlay ───────
    public Dictionary<string, Vector3> positionsGlobales = new Dictionary<string, Vector3>();

    // ── Stabilisation ─────────────────────────────────────────────────────
    private Dictionary<string, int> framesCorrectes = new Dictionary<string, int>();

    // ── Position locale item (pour affichage UI) ──────────────────────────
    private Dictionary<string, Vector3> positionsLocalesReelles = new Dictionary<string, Vector3>();
    private Dictionary<string, float>   distancesReelles        = new Dictionary<string, float>();

    // ── Page courante ──────────────────────────────────────────────────────
    private Page currentPage;

    // ── UI ─────────────────────────────────────────────────────────────────
    private Text  uiText;
    private float uiTimer = 0f;

    // ─────────────────────────────────────────────
    void Awake()
    {
        if (trackedImageManager == null)
            trackedImageManager = GetComponent<ARTrackedImageManager>();
        CreerUI();
    }

    void Start()
    {
        StartCoroutine(WaitForCacheAndBuild());
    }

    void OnEnable()  => trackedImageManager.trackedImagesChanged += OnImagesChanged;
    void OnDisable() => trackedImageManager.trackedImagesChanged -= OnImagesChanged;

    void Update()
    {
        ValiderPositionsFrame();

        uiTimer += Time.deltaTime;
        if (uiTimer >= uiRefreshInterval)
        {
            uiTimer = 0f;
            MettreAJourUI();
        }
    }

    // ─────────────────────────────────────────────
    IEnumerator WaitForCacheAndBuild()
    {
        yield return new WaitUntil(() => DataManager.Instance != null);

        _bookId = DataManager.Instance.LastLoadedBookId;

        if (string.IsNullOrEmpty(_bookId))
        {
            Debug.LogError("[Book1Detector] ❌ Aucun livre scanné (LastLoadedBookId vide).");
            yield break;
        }

        if (!DataManager.Instance.IsBookLoaded(_bookId))
        {
            Debug.LogError($"[Book1Detector] ❌ Livre '{_bookId}' absent du cache.");
            yield break;
        }

        Debug.Log($"[Book1Detector] 📖 Livre reçu depuis le cache : {_bookId}");
        BuildPagesFromData();
    }

    // ─────────────────────────────────────────────
    void BuildPagesFromData()
    {
        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(_bookId);
        if (bookData == null)
        {
            Debug.LogError($"[Book1Detector] ❌ BookData introuvable pour '{_bookId}'.");
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
        Debug.Log($"[Book1Detector] ✅ {pages.Count} page(s) prêtes pour '{_bookId}'.");
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
                    DataManager.Instance.OnPageDetected(_bookId, page.pageId);
                    StartCoroutine(SwitchPage(page, img));
                }
                else
                {
                    // Position ET rotation live → cohérentes au même instant ✅
                    feuilleDetectee = img;
                }
                return;
            }
        }
    }

    // ─────────────────────────────────────────────
    IEnumerator SwitchPage(Page page, ARTrackedImage feuille)
    {
        switching     = true;
        currentPageId = page.pageId;
        currentPage   = page;

        detectedImages.Clear();
        positionsGlobales.Clear();
        trackedImages.Clear();
        imagesValidees.Clear();
        framesCorrectes.Clear();
        positionsLocalesReelles.Clear();
        distancesReelles.Clear();

        if (cubeOverlay != null) cubeOverlay.ClearAllCubes();

        feuilleDetectee = feuille;

        yield return null;
        yield return null;
        yield return null;

        StartCoroutine(RespawnAvecRetry(5, 0.1f));

        Debug.Log($"📘 Active page : {page.pageId}");
        switching = false;
        MettreAJourUI();
    }

    // ─────────────────────────────────────────────
    IEnumerator RespawnAvecRetry(int tentatives, float intervalle)
    {
        for (int i = 0; i < tentatives; i++)
        {
            if (cubeOverlay != null) cubeOverlay.RespawnCubesForActiveTrackables();
            yield return new WaitForSeconds(intervalle);
        }
    }

    // ─────────────────────────────────────────────
    /// <summary>
    /// Validation chaque frame.
    /// InverseTransformPoint utilise position ET rotation live de la feuille
    /// → cohérentes au même instant → pas d'instabilité due au mélange live/figé
    /// → Comparaison XZ avec JSON directement (même espace local)
    /// </summary>
    void ValiderPositionsFrame()
    {
        if (!pagesLoaded || string.IsNullOrEmpty(currentPageId)) return;
        if (feuilleDetectee == null) return;

        foreach (var tracked in trackedImageManager.trackables)
        {
            string imgName = tracked.referenceImage.name;

            // Ignorer la feuille elle-même
            bool estFeuille = false;
            foreach (var p in pages)
                if (p.feuilleName == imgName) { estFeuille = true; break; }
            if (estFeuille) continue;

            if (imagesValidees.Contains(imgName)) continue;
            if (tracked.trackingState != TrackingState.Tracking) continue;

            int idx = currentPage.imageNames.IndexOf(imgName);
            if (idx < 0) continue;

            Vector3 posAttenduLocale = currentPage.positionsCorrectes[idx];

            // ── InverseTransformPoint : position ET rotation live ─────────
            // Les deux valeurs viennent du même instant → cohérentes ✅
            // Tel bouge → feuille et item bougent ensemble → différence stable ✅
            Vector3 posLocaleReelle = feuilleDetectee.transform.InverseTransformPoint(
                tracked.transform.position
            );

            // Sauvegarde pour UI
            positionsLocalesReelles[imgName] = posLocaleReelle;
            positionsGlobales[imgName]       = tracked.transform.position;

            // ── Distance 2D XZ seulement (Y = hauteur caméra, ignoré) ─────
            float dist = Vector2.Distance(
                new Vector2(posLocaleReelle.x,  posLocaleReelle.z),
                new Vector2(posAttenduLocale.x, posAttenduLocale.z)
            );

            distancesReelles[imgName] = dist;

            if (dist <= distanceMax)
            {
                if (!framesCorrectes.ContainsKey(imgName))
                    framesCorrectes[imgName] = 0;
                framesCorrectes[imgName]++;

                if (framesCorrectes[imgName] >= framesRequises)
                {
                    imagesValidees.Add(imgName);
                    Debug.Log($"✅ VALIDATED ({framesRequises} frames) : {imgName} | dist2D={dist*100f:F1}cm");
                }
            }
            else
            {
                framesCorrectes[imgName] = 0;
            }
        }
    }

    // ─────────────────────────────────────────────
    public GameObject  GetPrefabForItem(string itemName) => DataManager.Instance.GetPrefab(itemName);
    public Texture2D   GetImageForItem(string itemName)  => DataManager.Instance.GetImage(itemName);
    public bool        IsItemReady(string itemName)      => DataManager.Instance.IsAssetReady(itemName);
    public ARBook.Models.ItemData GetItemData(string itemName) => DataManager.Instance.GetItemData(_bookId, itemName);

    // ─────────────────────────────────────────────
    void MettreAJourUI()
    {
        if (uiText == null) return;

        System.Text.StringBuilder sb = new System.Text.StringBuilder();
        sb.AppendLine("═══ AR BOOK DETECTOR ═══");
        sb.AppendLine($"📖 BOOK : {(string.IsNullOrEmpty(_bookId) ? "—" : _bookId)}");
        sb.AppendLine($"🔍 Tracked images : {detectedImages.Count}");

        if (!pagesLoaded)
        {
            sb.AppendLine("⏳ Waiting for Data...");
            uiText.text = sb.ToString();
            return;
        }

        if (string.IsNullOrEmpty(currentPageId))
        {
            sb.AppendLine("No pages detected — point your camera at the sheet.");
            uiText.text = sb.ToString();
            return;
        }

        sb.AppendLine($"📚 Page : {currentPageId}");
        sb.AppendLine("----------------------------");

        foreach (var page in pages)
        {
            if (page.pageId != currentPageId) continue;

            for (int i = 0; i < page.imageNames.Count; i++)
            {
                string imgName = page.imageNames[i];

                bool detected       = detectedImages.ContainsKey(imgName);
                TrackingState state = detected ? detectedImages[imgName] : TrackingState.None;
                string icon         = !detected ? "○" : state == TrackingState.Tracking ? "✓" : "~";
                bool assetReady     = DataManager.Instance.IsAssetReady(imgName);
                string cacheIcon    = assetReady ? "💾" : "⏳";
                bool validated      = imagesValidees.Contains(imgName);

                string color = validated                        ? "green"
                             : !detected                       ? "white"
                             : state == TrackingState.Tracking ? "yellow" : "red";

                sb.AppendLine($"  <color={color}>{icon} {imgName} [{state}] {cacheIcon}</color>");

                Vector3 posAttendue = i < page.positionsCorrectes.Count
                    ? page.positionsCorrectes[i]
                    : Vector3.zero;

                if (validated)
                {
                    sb.AppendLine($"    <color=green>✅ Correct position ! Cube spawned.</color>");
                }
                else if (positionsLocalesReelles.ContainsKey(imgName))
                {
                    Vector3 locale = positionsLocalesReelles[imgName];
                    float   dist   = distancesReelles.ContainsKey(imgName) ? distancesReelles[imgName] : -1f;
                    int     frames = framesCorrectes.ContainsKey(imgName)  ? framesCorrectes[imgName]  : 0;
                    bool    proche = dist >= 0f && dist <= distanceMax;

                    sb.AppendLine($"    local real  XZ : ({locale.x:F3}, {locale.z:F3})");
                    sb.AppendLine($"    local JSON  XZ : ({posAttendue.x:F3}, {posAttendue.z:F3})");

                    if (dist >= 0f)
                    {
                        string comparaison = proche
                            ? $"<color=yellow>≈ correct ({dist*100f:F1}cm ≤ {distanceMax*100f:F0}cm)</color>"
                            : $"<color=red>✗ incorrect ({dist*100f:F1}cm > {distanceMax*100f:F0}cm)</color>";
                        sb.AppendLine($"    distance 2D : {comparaison}");

                        if (proche)
                            sb.AppendLine($"    stability   : <color=yellow>{frames}/{framesRequises} frames</color>");
                    }
                }
                else if (detected)
                {
                    sb.AppendLine($"    local JSON  XZ : ({posAttendue.x:F3}, {posAttendue.z:F3})");
                    sb.AppendLine($"    <color=grey>⏳ calculating...</color>");
                }

                sb.AppendLine();
            }
        }

        sb.AppendLine("----------------------------");
        sb.AppendLine("○=not detected ✓=tracked ~=lost");
        sb.AppendLine("YELLOW=close  GREEN=validated ✅");
        uiText.text = sb.ToString();
    }

    // ─────────────────────────────────────────────
    void CreerUI()
    {
        GameObject canvasObj = new GameObject("CanvasTest");
        Canvas canvas        = canvasObj.AddComponent<Canvas>();
        canvas.renderMode    = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder  = 0;

        canvasObj.AddComponent<CanvasScaler>();
        // ⚠️ GraphicRaycaster supprimé intentionnellement

        GameObject textObj = new GameObject("UIText");
        textObj.transform.SetParent(canvasObj.transform, false);

        uiText                 = textObj.AddComponent<Text>();
        uiText.font            = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        uiText.fontSize        = 24;
        uiText.color           = Color.white;
        uiText.alignment       = TextAnchor.UpperLeft;
        uiText.supportRichText = true;
        uiText.raycastTarget   = false;

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin     = new Vector2(0, 0);
        rt.anchorMax     = new Vector2(1, 1);
        rt.offsetMin     = new Vector2(20, 20);
        rt.offsetMax     = new Vector2(-20, -20);
    }
}
/*code 08/06/2026
/*claude solution
/*version : InverseTransformPoint + rotation figée + position live + validation N frames + UI page active seulement
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

/// <summary>
/// Book1Detector — Scène AR.
///
/// CE SCRIPT NE TÉLÉCHARGE RIEN.
/// Il lit DataManager.LastLoadedBookId pour savoir quel livre afficher.
///
/// Calcul de position :
/// - Rotation de la feuille figée au premier tracking stable
/// - Position de la feuille live (suit la feuille si elle bouge)
/// - InverseTransformPoint via matrice (position live + rotation figée)
/// - Comparaison XZ seulement (plan plat, Y ignoré)
/// - Validation après framesRequises frames consécutives correctes
/// </summary>
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
    public float distanceMax       = 0.05f;  // 5cm
    public int   framesRequises    = 10;     // frames consécutives pour valider
    public float uiRefreshInterval = 0.2f;  // rafraîchissement UI toutes les 200ms

    [Header("Liaison ARImageCubeOverlay")]
    public ARImageCubeOverlay cubeOverlay;

    // ── bookId résolu dynamiquement depuis DataManager.LastLoadedBookId ──
    private string _bookId = "";

    private List<Page> pages     = new List<Page>();
    private bool pagesLoaded     = false;
    private string currentPageId = "";
    private bool switching       = false;

    private Dictionary<string, TrackingState>  detectedImages = new Dictionary<string, TrackingState>();
    public  Dictionary<string, ARTrackedImage> trackedImages  = new Dictionary<string, ARTrackedImage>();
    private ARTrackedImage feuilleDetectee = null;
    public  HashSet<string> imagesValidees = new HashSet<string>();

    // ── positionsGlobales gardé pour compatibilité avec cubeOverlay ───────
    public Dictionary<string, Vector3> positionsGlobales = new Dictionary<string, Vector3>();

    // ── Rotation figée — position live ────────────────────────────────────
    private Quaternion feuilleRotationFigee = Quaternion.identity;
    private bool       rotationFigee        = false;

    // ── Stabilisation ─────────────────────────────────────────────────────
    private Dictionary<string, int> framesCorrectes = new Dictionary<string, int>();

    // ── Position locale item (pour affichage UI) ──────────────────────────
    private Dictionary<string, Vector3> positionsLocalesReelles = new Dictionary<string, Vector3>();
    private Dictionary<string, float>   distancesReelles        = new Dictionary<string, float>();

    // ── Page courante ──────────────────────────────────────────────────────
    private Page currentPage;

    // ── UI ─────────────────────────────────────────────────────────────────
    private Text  uiText;
    private float uiTimer = 0f;

    // ─────────────────────────────────────────────
    void Awake()
    {
        if (trackedImageManager == null)
            trackedImageManager = GetComponent<ARTrackedImageManager>();
        CreerUI();
    }

    void Start()
    {
        StartCoroutine(WaitForCacheAndBuild());
    }

    void OnEnable()  => trackedImageManager.trackedImagesChanged += OnImagesChanged;
    void OnDisable() => trackedImageManager.trackedImagesChanged -= OnImagesChanged;

    void Update()
    {
        ValiderPositionsFrame();

        uiTimer += Time.deltaTime;
        if (uiTimer >= uiRefreshInterval)
        {
            uiTimer = 0f;
            MettreAJourUI();
        }
    }

    // ─────────────────────────────────────────────
    IEnumerator WaitForCacheAndBuild()
    {
        yield return new WaitUntil(() => DataManager.Instance != null);

        _bookId = DataManager.Instance.LastLoadedBookId;

        if (string.IsNullOrEmpty(_bookId))
        {
            Debug.LogError("[Book1Detector] ❌ Aucun livre scanné (LastLoadedBookId vide).");
            yield break;
        }

        if (!DataManager.Instance.IsBookLoaded(_bookId))
        {
            Debug.LogError($"[Book1Detector] ❌ Livre '{_bookId}' absent du cache.");
            yield break;
        }

        Debug.Log($"[Book1Detector] 📖 Livre reçu depuis le cache : {_bookId}");
        BuildPagesFromData();
    }

    // ─────────────────────────────────────────────
    void BuildPagesFromData()
    {
        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(_bookId);
        if (bookData == null)
        {
            Debug.LogError($"[Book1Detector] ❌ BookData introuvable pour '{_bookId}'.");
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
        Debug.Log($"[Book1Detector] ✅ {pages.Count} page(s) prêtes pour '{_bookId}'.");
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
                    DataManager.Instance.OnPageDetected(_bookId, page.pageId);
                    StartCoroutine(SwitchPage(page, img));
                }
                else
                {
                    // Position live → toujours à jour
                    feuilleDetectee = img;

                    // ── Figer la ROTATION une seule fois ──────────────────
                    if (!rotationFigee && img.trackingState == TrackingState.Tracking)
                    {
                        feuilleRotationFigee = img.transform.rotation;
                        rotationFigee        = true;
                        Debug.Log($"📌 Sheet frozen rotation : {feuilleRotationFigee.eulerAngles}");
                    }
                }
                return;
            }
        }
    }

    // ─────────────────────────────────────────────
    IEnumerator SwitchPage(Page page, ARTrackedImage feuille)
    {
        switching     = true;
        currentPageId = page.pageId;
        currentPage   = page;

        detectedImages.Clear();
        positionsGlobales.Clear();
        trackedImages.Clear();
        imagesValidees.Clear();
        framesCorrectes.Clear();
        positionsLocalesReelles.Clear();
        distancesReelles.Clear();
        rotationFigee = false;         // ← reset rotation pour nouvelle page

        if (cubeOverlay != null) cubeOverlay.ClearAllCubes();

        feuilleDetectee = feuille;

        // Figer la rotation immédiatement au switch
        feuilleRotationFigee = feuille.transform.rotation;
        rotationFigee        = true;
        Debug.Log($"📌 Frozen rotation on switch : {feuilleRotationFigee.eulerAngles}");

        yield return null;
        yield return null;
        yield return null;

        StartCoroutine(RespawnAvecRetry(5, 0.1f));

        Debug.Log($"📘 Active page : {page.pageId}");
        switching = false;
        MettreAJourUI();
    }

    // ─────────────────────────────────────────────
    IEnumerator RespawnAvecRetry(int tentatives, float intervalle)
    {
        for (int i = 0; i < tentatives; i++)
        {
            if (cubeOverlay != null) cubeOverlay.RespawnCubesForActiveTrackables();
            yield return new WaitForSeconds(intervalle);
        }
    }

    // ─────────────────────────────────────────────
    /// <summary>
    /// Validation chaque frame.
    /// Matrice = position LIVE feuille + rotation FIGÉE
    /// → InverseTransformPoint stable même si tel incliné
    /// → Comparaison XZ avec JSON directement
    /// </summary>
    void ValiderPositionsFrame()
    {
        if (!pagesLoaded || string.IsNullOrEmpty(currentPageId)) return;
        if (feuilleDetectee == null || !rotationFigee) return;

        // ── Matrice : position live + rotation figée ──────────────────────
        Matrix4x4 mat = Matrix4x4.TRS(
            feuilleDetectee.transform.position,  // position live ✅
            feuilleRotationFigee,                // rotation figée ✅
            Vector3.one
        );
        Matrix4x4 matInverse = mat.inverse;

        foreach (var tracked in trackedImageManager.trackables)
        {
            string imgName = tracked.referenceImage.name;

            // Ignorer la feuille elle-même
            bool estFeuille = false;
            foreach (var p in pages)
                if (p.feuilleName == imgName) { estFeuille = true; break; }
            if (estFeuille) continue;

            if (imagesValidees.Contains(imgName)) continue;
            if (tracked.trackingState != TrackingState.Tracking) continue;

            // Index dans la page courante
            int idx = currentPage.imageNames.IndexOf(imgName);
            if (idx < 0) continue;

            Vector3 posAttenduLocale = currentPage.positionsCorrectes[idx];

            // ── Position item en espace local (position live + rotation figée)
            Vector3 posLocaleReelle = matInverse.MultiplyPoint3x4(
                tracked.transform.position
            );

            // Sauvegarde pour UI
            positionsLocalesReelles[imgName] = posLocaleReelle;
            positionsGlobales[imgName]       = tracked.transform.position;

            // ── Distance 2D XZ seulement ──────────────────────────────────
            float dist = Vector2.Distance(
                new Vector2(posLocaleReelle.x,   posLocaleReelle.z),
                new Vector2(posAttenduLocale.x,  posAttenduLocale.z)
            );

            distancesReelles[imgName] = dist;

            if (dist <= distanceMax)
            {
                if (!framesCorrectes.ContainsKey(imgName))
                    framesCorrectes[imgName] = 0;
                framesCorrectes[imgName]++;

                if (framesCorrectes[imgName] >= framesRequises)
                {
                    imagesValidees.Add(imgName);
                    Debug.Log($"✅ VALIDATED ({framesRequises} frames) : {imgName} | dist2D={dist*100f:F1}cm");
                }
            }
            else
            {
                framesCorrectes[imgName] = 0;
            }
        }
    }

    // ─────────────────────────────────────────────
    public GameObject  GetPrefabForItem(string itemName) => DataManager.Instance.GetPrefab(itemName);
    public Texture2D   GetImageForItem(string itemName)  => DataManager.Instance.GetImage(itemName);
    public bool        IsItemReady(string itemName)      => DataManager.Instance.IsAssetReady(itemName);
    public ARBook.Models.ItemData GetItemData(string itemName) => DataManager.Instance.GetItemData(_bookId, itemName);

    // ─────────────────────────────────────────────
    void MettreAJourUI()
    {
        if (uiText == null) return;

        System.Text.StringBuilder sb = new System.Text.StringBuilder();
        sb.AppendLine("═══ AR BOOK DETECTOR ═══");
        sb.AppendLine($"📖 BOOK : {(string.IsNullOrEmpty(_bookId) ? "—" : _bookId)}");
        sb.AppendLine($"🔍 Tracked images : {detectedImages.Count}");
        sb.AppendLine($"📌 Frozen rotation : {(rotationFigee ? "YES ✅" : "NO ⏳")}");

        if (!pagesLoaded)
        {
            sb.AppendLine("⏳ Waiting for Data...");
            uiText.text = sb.ToString();
            return;
        }

        if (string.IsNullOrEmpty(currentPageId))
        {
            sb.AppendLine(" No pages detected — point your camera at the sheet.");
            uiText.text = sb.ToString();
            return;
        }

        sb.AppendLine($"📚 Page : {currentPageId}");
        sb.AppendLine("----------------------------");

        foreach (var page in pages)
        {
            if (page.pageId != currentPageId) continue;

            for (int i = 0; i < page.imageNames.Count; i++)
            {
                string imgName = page.imageNames[i];

                bool detected       = detectedImages.ContainsKey(imgName);
                TrackingState state = detected ? detectedImages[imgName] : TrackingState.None;
                string icon         = !detected ? "○" : state == TrackingState.Tracking ? "✓" : "~";
                bool assetReady     = DataManager.Instance.IsAssetReady(imgName);
                string cacheIcon    = assetReady ? "💾" : "⏳";
                bool validated      = imagesValidees.Contains(imgName);

                string color = validated                        ? "green"
                             : !detected                       ? "white"
                             : state == TrackingState.Tracking ? "yellow" : "red";

                sb.AppendLine($"  <color={color}>{icon} {imgName} [{state}] {cacheIcon}</color>");

                Vector3 posAttendue = i < page.positionsCorrectes.Count
                    ? page.positionsCorrectes[i]
                    : Vector3.zero;

                if (validated)
                {
                    sb.AppendLine($"    <color=green>✅ Position correcte ! Cube spawné.</color>");
                }
                else if (positionsLocalesReelles.ContainsKey(imgName))
                {
                    Vector3 locale = positionsLocalesReelles[imgName];
                    float   dist   = distancesReelles.ContainsKey(imgName) ? distancesReelles[imgName] : -1f;
                    int     frames = framesCorrectes.ContainsKey(imgName)  ? framesCorrectes[imgName]  : 0;
                    bool    proche = dist >= 0f && dist <= distanceMax;

                    sb.AppendLine($"    local réel  XZ : ({locale.x:F3}, {locale.z:F3})");
                    sb.AppendLine($"    local JSON  XZ : ({posAttendue.x:F3}, {posAttendue.z:F3})");

                    if (dist >= 0f)
                    {
                        string comparaison = proche
                            ? $"<color=yellow>≈ correct ({dist*100f:F1}cm ≤ {distanceMax*100f:F0}cm)</color>"
                            : $"<color=red>✗ incorrect ({dist*100f:F1}cm > {distanceMax*100f:F0}cm)</color>";
                        sb.AppendLine($"    distance 2D : {comparaison}");

                        if (proche)
                            sb.AppendLine($"    stabilité   : <color=yellow>{frames}/{framesRequises} frames</color>");
                    }
                }
                else if (detected)
                {
                    sb.AppendLine($"    local JSON  XZ : ({posAttendue.x:F3}, {posAttendue.z:F3})");
                    sb.AppendLine($"    <color=grey>⏳ calcul en cours...</color>");
                }

                sb.AppendLine();
            }
        }

        sb.AppendLine("----------------------------");
        sb.AppendLine("○=not detected ✓=tracked ~=lost");
        sb.AppendLine("YELLOW=close  GREEN=validated ✅");
        uiText.text = sb.ToString();
    }

    // ─────────────────────────────────────────────
    void CreerUI()
    {
        GameObject canvasObj = new GameObject("CanvasTest");
        Canvas canvas        = canvasObj.AddComponent<Canvas>();
        canvas.renderMode    = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder  = 0;

        canvasObj.AddComponent<CanvasScaler>();
        // ⚠️ GraphicRaycaster supprimé intentionnellement

        GameObject textObj = new GameObject("UIText");
        textObj.transform.SetParent(canvasObj.transform, false);

        uiText                 = textObj.AddComponent<Text>();
        uiText.font            = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        uiText.fontSize        = 24;
        uiText.color           = Color.white;
        uiText.alignment       = TextAnchor.UpperLeft;
        uiText.supportRichText = true;
        uiText.raycastTarget   = false;

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin     = new Vector2(0, 0);
        rt.anchorMax     = new Vector2(1, 1);
        rt.offsetMin     = new Vector2(20, 20);
        rt.offsetMax     = new Vector2(-20, -20);
    }
}
/*code 08/06/2026
/*version finale : InverseTransformPoint + validation stable N frames + UI page active seulement
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

/// <summary>
/// Book1Detector — Scène AR.
///
/// CE SCRIPT NE TÉLÉCHARGE RIEN.
/// Il lit DataManager.LastLoadedBookId pour savoir quel livre afficher.
/// Ce champ est rempli par QRScanner après le scan — il survit entre scènes
/// car DataManager est DontDestroyOnLoad.
///
/// Améliorations :
/// - InverseTransformPoint : compare en espace local feuille (même espace que JSON)
/// - Feuille live (pas figée) : stable car tout est relatif
/// - Validation stabilisée : framesRequises frames consécutives correctes
/// - UI : affiche UNIQUEMENT la page active, se met à jour au changement de page
/// </summary>
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
    public float distanceMax       = 0.05f;  // 5cm
    public int   framesRequises    = 10;     // frames consécutives pour valider
    public float uiRefreshInterval = 0.2f;  // rafraîchissement UI toutes les 200ms

    [Header("Liaison ARImageCubeOverlay")]
    public ARImageCubeOverlay cubeOverlay;

    // ── bookId résolu dynamiquement depuis DataManager.LastLoadedBookId ──
    private string _bookId = "";

    private List<Page> pages     = new List<Page>();
    private bool pagesLoaded     = false;
    private string currentPageId = "";
    private bool switching       = false;

    private Dictionary<string, TrackingState>  detectedImages = new Dictionary<string, TrackingState>();
    public  Dictionary<string, ARTrackedImage> trackedImages  = new Dictionary<string, ARTrackedImage>();
    private ARTrackedImage feuilleDetectee = null;
    public  HashSet<string> imagesValidees = new HashSet<string>();

    // ── positionsGlobales gardé pour compatibilité avec cubeOverlay ───────
    public Dictionary<string, Vector3> positionsGlobales = new Dictionary<string, Vector3>();

    // ── Stabilisation : compteur de frames correctes par item ─────────────
    private Dictionary<string, int> framesCorrectes = new Dictionary<string, int>();

    // ── Position locale item (pour affichage UI) ──────────────────────────
    private Dictionary<string, Vector3> positionsLocalesReelles  = new Dictionary<string, Vector3>();
    private Dictionary<string, float>   distancesReelles         = new Dictionary<string, float>();

    // ── Page courante (référence pour InverseTransformPoint) ──────────────
    private Page currentPage;

    // ── UI ─────────────────────────────────────────────────────────────────
    private Text  uiText;
    private float uiTimer = 0f;

    // ─────────────────────────────────────────────
    void Awake()
    {
        if (trackedImageManager == null)
            trackedImageManager = GetComponent<ARTrackedImageManager>();
        CreerUI();
    }

    void Start()
    {
        StartCoroutine(WaitForCacheAndBuild());
    }

    void OnEnable()  => trackedImageManager.trackedImagesChanged += OnImagesChanged;
    void OnDisable() => trackedImageManager.trackedImagesChanged -= OnImagesChanged;

    void Update()
    {
        // Validation logique chaque frame ───────────────────────────────────
        ValiderPositionsFrame();

        // UI rafraîchie toutes les uiRefreshInterval secondes ───────────────
        uiTimer += Time.deltaTime;
        if (uiTimer >= uiRefreshInterval)
        {
            uiTimer = 0f;
            MettreAJourUI();
        }
    }

    // ─────────────────────────────────────────────
    IEnumerator WaitForCacheAndBuild()
    {
        yield return new WaitUntil(() => DataManager.Instance != null);

        _bookId = DataManager.Instance.LastLoadedBookId;

        if (string.IsNullOrEmpty(_bookId))
        {
            Debug.LogError("[Book1Detector] ❌ Aucun livre scanné (LastLoadedBookId vide).");
            yield break;
        }

        if (!DataManager.Instance.IsBookLoaded(_bookId))
        {
            Debug.LogError($"[Book1Detector] ❌ Livre '{_bookId}' absent du cache.");
            yield break;
        }

        Debug.Log($"[Book1Detector] 📖 Livre reçu depuis le cache : {_bookId}");
        BuildPagesFromData();
    }

    // ─────────────────────────────────────────────
    void BuildPagesFromData()
    {
        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(_bookId);
        if (bookData == null)
        {
            Debug.LogError($"[Book1Detector] ❌ BookData introuvable pour '{_bookId}'.");
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
        Debug.Log($"[Book1Detector] ✅ {pages.Count} page(s) prêtes pour '{_bookId}'.");
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
                    DataManager.Instance.OnPageDetected(_bookId, page.pageId);
                    StartCoroutine(SwitchPage(page, img));
                }
                else
                {
                    // Feuille live → toujours à jour pour InverseTransformPoint
                    feuilleDetectee = img;
                }
                return;
            }
        }
    }

    // ─────────────────────────────────────────────
    IEnumerator SwitchPage(Page page, ARTrackedImage feuille)
    {
        switching     = true;
        currentPageId = page.pageId;
        currentPage   = page;

        detectedImages.Clear();
        positionsGlobales.Clear();
        trackedImages.Clear();
        imagesValidees.Clear();
        framesCorrectes.Clear();
        positionsLocalesReelles.Clear();
        distancesReelles.Clear();

        if (cubeOverlay != null) cubeOverlay.ClearAllCubes();

        feuilleDetectee = feuille;

        yield return null;
        yield return null;
        yield return null;

        StartCoroutine(RespawnAvecRetry(5, 0.1f));

        Debug.Log($"📘 Page active : {page.pageId}");
        switching = false;
        MettreAJourUI(); // ← force rafraîchissement UI au changement de page
    }

    // ─────────────────────────────────────────────
    IEnumerator RespawnAvecRetry(int tentatives, float intervalle)
    {
        for (int i = 0; i < tentatives; i++)
        {
            if (cubeOverlay != null) cubeOverlay.RespawnCubesForActiveTrackables();
            yield return new WaitForSeconds(intervalle);
        }
    }

    // ─────────────────────────────────────────────
    /// <summary>
    /// Appelée chaque frame dans Update().
    /// Utilise InverseTransformPoint pour convertir la position monde de l'item
    /// en position locale par rapport à la feuille → même espace que le JSON.
    /// Compare sur XZ seulement (feuille plate, Y ignoré).
    /// </summary>
    void ValiderPositionsFrame()
    {
        if (!pagesLoaded || string.IsNullOrEmpty(currentPageId)) return;
        if (feuilleDetectee == null) return;

        foreach (var tracked in trackedImageManager.trackables)
        {
            string imgName = tracked.referenceImage.name;

            // On ignore la feuille elle-même
            bool estFeuille = false;
            foreach (var p in pages)
                if (p.feuilleName == imgName) { estFeuille = true; break; }
            if (estFeuille) continue;

            // Déjà validé → on ne touche plus
            if (imagesValidees.Contains(imgName)) continue;

            if (tracked.trackingState != TrackingState.Tracking) continue;

            // Trouver la position correcte dans la page courante
            int idx = currentPage.imageNames.IndexOf(imgName);
            if (idx < 0) continue;
            Vector3 posAttenduLocale = currentPage.positionsCorrectes[idx];

            // ── InverseTransformPoint : monde → local feuille ─────────────
            Vector3 posLocaleReelle = feuilleDetectee.transform.InverseTransformPoint(
                tracked.transform.position
            );

            // Sauvegarde pour l'UI
            positionsLocalesReelles[imgName] = posLocaleReelle;

            // ── Distance 2D en espace local (XZ = plan plat feuille) ──────
            float dist = Vector2.Distance(
                new Vector2(posLocaleReelle.x,   posLocaleReelle.z),
                new Vector2(posAttenduLocale.x,  posAttenduLocale.z)
            );

            distancesReelles[imgName] = dist;

            // ── Mise à jour positionsGlobales pour cubeOverlay ────────────
            positionsGlobales[imgName] = tracked.transform.position;

            if (dist <= distanceMax)
            {
                if (!framesCorrectes.ContainsKey(imgName))
                    framesCorrectes[imgName] = 0;
                framesCorrectes[imgName]++;

                if (framesCorrectes[imgName] >= framesRequises)
                {
                    imagesValidees.Add(imgName);
                    Debug.Log($"✅ VALIDÉ STABLE ({framesRequises} frames) : {imgName} | dist2D={dist*100f:F1}cm");
                }
            }
            else
            {
                framesCorrectes[imgName] = 0;
            }
        }
    }

    // ─────────────────────────────────────────────
    public GameObject  GetPrefabForItem(string itemName) => DataManager.Instance.GetPrefab(itemName);
    public Texture2D   GetImageForItem(string itemName)  => DataManager.Instance.GetImage(itemName);
    public bool        IsItemReady(string itemName)      => DataManager.Instance.IsAssetReady(itemName);
    public ARBook.Models.ItemData GetItemData(string itemName) => DataManager.Instance.GetItemData(_bookId, itemName);

    // ─────────────────────────────────────────────
    void MettreAJourUI()
    {
        if (uiText == null) return;

        System.Text.StringBuilder sb = new System.Text.StringBuilder();
        sb.AppendLine("═══ AR BOOK DETECTOR ═══");
        sb.AppendLine($"📖 Livre : {(string.IsNullOrEmpty(_bookId) ? "—" : _bookId)}");
        sb.AppendLine($"🔍 Images trackées : {detectedImages.Count}");

        if (!pagesLoaded)
        {
            sb.AppendLine("⏳ En attente du cache...");
            uiText.text = sb.ToString();
            return;
        }

        if (string.IsNullOrEmpty(currentPageId))
        {
            sb.AppendLine("📚 Aucune page détectée — pointez la caméra sur la feuille.");
            uiText.text = sb.ToString();
            return;
        }

        // ── Affiche UNIQUEMENT la page active ─────────────────────────────
        sb.AppendLine($"📚 Page : {currentPageId}");
        sb.AppendLine("----------------------------");

        foreach (var page in pages)
        {
            if (page.pageId != currentPageId) continue; // ← ignore les autres pages

            for (int i = 0; i < page.imageNames.Count; i++)
            {
                string imgName = page.imageNames[i];

                bool detected       = detectedImages.ContainsKey(imgName);
                TrackingState state = detected ? detectedImages[imgName] : TrackingState.None;
                string icon         = !detected ? "○" : state == TrackingState.Tracking ? "✓" : "~";
                bool assetReady     = DataManager.Instance.IsAssetReady(imgName);
                string cacheIcon    = assetReady ? "💾" : "⏳";
                bool validated      = imagesValidees.Contains(imgName);

                string color = validated                        ? "green"
                             : !detected                       ? "white"
                             : state == TrackingState.Tracking ? "yellow" : "red";

                sb.AppendLine($"  <color={color}>{icon} {imgName} [{state}] {cacheIcon}</color>");

                // ── Affichage détaillé position ──────────────────────────
                Vector3 posAttendue = i < page.positionsCorrectes.Count
                    ? page.positionsCorrectes[i]
                    : Vector3.zero;

                if (validated)
                {
                    sb.AppendLine($"    <color=green>✅ Position correcte ! Cube spawné.</color>");
                }
                else if (positionsLocalesReelles.ContainsKey(imgName))
                {
                    Vector3 locale = positionsLocalesReelles[imgName];
                    float   dist   = distancesReelles.ContainsKey(imgName) ? distancesReelles[imgName] : -1f;
                    int     frames = framesCorrectes.ContainsKey(imgName)  ? framesCorrectes[imgName]  : 0;
                    bool    proche = dist >= 0f && dist <= distanceMax;

                    sb.AppendLine($"    local réel  XZ : ({locale.x:F3}, {locale.z:F3})");
                    sb.AppendLine($"    local JSON  XZ : ({posAttendue.x:F3}, {posAttendue.z:F3})");

                    if (dist >= 0f)
                    {
                        string comparaison = proche
                            ? $"<color=yellow>≈ correct ({dist*100f:F1}cm ≤ {distanceMax*100f:F0}cm)</color>"
                            : $"<color=red>✗ incorrect ({dist*100f:F1}cm > {distanceMax*100f:F0}cm)</color>";
                        sb.AppendLine($"    distance 2D : {comparaison}");

                        if (proche)
                            sb.AppendLine($"    stabilité   : <color=yellow>{frames}/{framesRequises} frames</color>");
                    }
                }
                else if (detected)
                {
                    sb.AppendLine($"    local JSON  XZ : ({posAttendue.x:F3}, {posAttendue.z:F3})");
                    sb.AppendLine($"    <color=grey>⏳ calcul en cours...</color>");
                }

                sb.AppendLine();
            }
        }

        sb.AppendLine("----------------------------");
        sb.AppendLine("○=non détecté ✓=tracké ~=perdu");
        sb.AppendLine("JAUNE=proche  VERT=validé ✅");
        uiText.text = sb.ToString();
    }

    // ─────────────────────────────────────────────
    void CreerUI()
    {
        GameObject canvasObj = new GameObject("CanvasTest");
        Canvas canvas        = canvasObj.AddComponent<Canvas>();
        canvas.renderMode    = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder  = 0;

        canvasObj.AddComponent<CanvasScaler>();
        // ⚠️ GraphicRaycaster supprimé intentionnellement

        GameObject textObj = new GameObject("UIText");
        textObj.transform.SetParent(canvasObj.transform, false);

        uiText                 = textObj.AddComponent<Text>();
        uiText.font            = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        uiText.fontSize        = 24;
        uiText.color           = Color.white;
        uiText.alignment       = TextAnchor.UpperLeft;
        uiText.supportRichText = true;
        uiText.raycastTarget   = false;

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin     = new Vector2(0, 0);
        rt.anchorMax     = new Vector2(1, 1);
        rt.offsetMin     = new Vector2(20, 20);
        rt.offsetMax     = new Vector2(-20, -20);
    }
}
/*claude solution
/*version finale : feuille figée + validation stable N frames + distance 2D (ignore Y)
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

/// <summary>
/// Book1Detector — Scène AR.
///
/// CE SCRIPT NE TÉLÉCHARGE RIEN.
/// Il lit DataManager.LastLoadedBookId pour savoir quel livre afficher.
/// Ce champ est rempli par QRScanner après le scan — il survit entre scènes
/// car DataManager est DontDestroyOnLoad.
///
/// Améliorations :
/// - Feuille figée au premier tracking → positions attendues stables
/// - Validation stabilisée : framesRequises frames consécutives correctes
/// - Distance 2D (XZ seulement) → ignore la hauteur caméra/feuille
/// - UI rafraîchie toutes les uiRefreshInterval secondes (pas chaque frame)
/// - Affichage position réelle vs attendue avec distance et stabilité
/// </summary>
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
    public float distanceMax       = 0.05f;  // 5cm
    public int   framesRequises    = 10;     // frames consécutives pour valider
    public float uiRefreshInterval = 0.2f;  // rafraîchissement UI toutes les 200ms

    [Header("Liaison ARImageCubeOverlay")]
    public ARImageCubeOverlay cubeOverlay;

    // ── bookId résolu dynamiquement depuis DataManager.LastLoadedBookId ──
    private string _bookId = "";

    private List<Page> pages     = new List<Page>();
    private bool pagesLoaded     = false;
    private string currentPageId = "";
    private bool switching       = false;

    private Dictionary<string, TrackingState>  detectedImages    = new Dictionary<string, TrackingState>();
    public  Dictionary<string, Vector3>        positionsGlobales = new Dictionary<string, Vector3>();
    public  Dictionary<string, ARTrackedImage> trackedImages     = new Dictionary<string, ARTrackedImage>();
    private ARTrackedImage feuilleDetectee = null;
    public  HashSet<string> imagesValidees = new HashSet<string>();

    // ── Feuille figée ──────────────────────────────────────────────────────
    private Vector3    feuillePositionFigee = Vector3.zero;
    private Quaternion feuilleRotationFigee = Quaternion.identity;
    private bool       feuilleFigee         = false;

    // ── Stabilisation : compteur de frames correctes par item ─────────────
    private Dictionary<string, int> framesCorrectes = new Dictionary<string, int>();

    // ── Position réelle trackée par item (pour affichage UI) ──────────────
    private Dictionary<string, Vector3> positionsReelles = new Dictionary<string, Vector3>();
    private Dictionary<string, float>   distancesReelles = new Dictionary<string, float>();

    // ── UI ─────────────────────────────────────────────────────────────────
    private Text  uiText;
    private float uiTimer = 0f;

    // ─────────────────────────────────────────────
    void Awake()
    {
        if (trackedImageManager == null)
            trackedImageManager = GetComponent<ARTrackedImageManager>();
        CreerUI();
    }

    void Start()
    {
        StartCoroutine(WaitForCacheAndBuild());
    }

    void OnEnable()  => trackedImageManager.trackedImagesChanged += OnImagesChanged;
    void OnDisable() => trackedImageManager.trackedImagesChanged -= OnImagesChanged;

    void Update()
    {
        // Validation logique chaque frame ───────────────────────────────────
        ValiderPositionsFrame();

        // UI rafraîchie toutes les uiRefreshInterval secondes ───────────────
        uiTimer += Time.deltaTime;
        if (uiTimer >= uiRefreshInterval)
        {
            uiTimer = 0f;
            MettreAJourUI();
        }
    }

    // ─────────────────────────────────────────────
    IEnumerator WaitForCacheAndBuild()
    {
        yield return new WaitUntil(() => DataManager.Instance != null);

        _bookId = DataManager.Instance.LastLoadedBookId;

        if (string.IsNullOrEmpty(_bookId))
        {
            Debug.LogError("[Book1Detector] ❌ Aucun livre scanné (LastLoadedBookId vide).");
            yield break;
        }

        if (!DataManager.Instance.IsBookLoaded(_bookId))
        {
            Debug.LogError($"[Book1Detector] ❌ Livre '{_bookId}' absent du cache.");
            yield break;
        }

        Debug.Log($"[Book1Detector] 📖 Livre reçu depuis le cache : {_bookId}");
        BuildPagesFromData();
    }

    // ─────────────────────────────────────────────
    void BuildPagesFromData()
    {
        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(_bookId);
        if (bookData == null)
        {
            Debug.LogError($"[Book1Detector] ❌ BookData introuvable pour '{_bookId}'.");
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
        Debug.Log($"[Book1Detector] ✅ {pages.Count} page(s) prêtes pour '{_bookId}'.");
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
                    DataManager.Instance.OnPageDetected(_bookId, page.pageId);
                    StartCoroutine(SwitchPage(page, img));
                }
                else
                {
                    feuilleDetectee = img;

                    // ── Figer la feuille UNE SEULE FOIS par page ──────────
                    if (!feuilleFigee)
                    {
                        feuillePositionFigee = img.transform.position;
                        feuilleRotationFigee = img.transform.rotation;
                        feuilleFigee         = true;
                        Debug.Log($"📌 Feuille figée : pos={feuillePositionFigee} rot={feuilleRotationFigee.eulerAngles}");
                        CalculerPositions(page);
                    }
                    // Si déjà figée → on ne recalcule pas
                }
                return;
            }
        }
    }

    // ─────────────────────────────────────────────
    IEnumerator SwitchPage(Page page, ARTrackedImage feuille)
    {
        switching     = true;
        currentPageId = page.pageId;

        detectedImages.Clear();
        positionsGlobales.Clear();
        trackedImages.Clear();
        imagesValidees.Clear();
        framesCorrectes.Clear();
        positionsReelles.Clear();
        distancesReelles.Clear();
        feuilleFigee = false;          // ← reset pour la nouvelle page

        if (cubeOverlay != null) cubeOverlay.ClearAllCubes();

        feuilleDetectee = feuille;

        // Figer immédiatement la feuille dès le switch
        feuillePositionFigee = feuille.transform.position;
        feuilleRotationFigee = feuille.transform.rotation;
        feuilleFigee         = true;
        Debug.Log($"📌 Feuille figée au switch : pos={feuillePositionFigee}");

        yield return null;
        yield return null;
        yield return null;

        CalculerPositions(page);
        StartCoroutine(RespawnAvecRetry(5, 0.1f));

        Debug.Log($"📘 Page active : {page.pageId}");
        switching = false;
        MettreAJourUI();
    }

    // ─────────────────────────────────────────────
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
        if (!feuilleFigee) return;

        positionsGlobales.Clear();

        // ── Matrice basée sur la position FIGÉE ───────────────────────────
        Matrix4x4 feuilleMatrix = Matrix4x4.TRS(
            feuillePositionFigee,
            feuilleRotationFigee,
            Vector3.one
        );

        for (int i = 0; i < page.imageNames.Count; i++)
        {
            if (i >= page.positionsCorrectes.Count) continue;

            // MultiplyPoint3x4 : convertit position locale → monde via la matrice figée
            Vector3 globalPos = feuilleMatrix.MultiplyPoint3x4(page.positionsCorrectes[i]);
            positionsGlobales[page.imageNames[i]] = globalPos;

            Debug.Log($"📍 {page.imageNames[i]} => pos attendue figée : {globalPos}");
        }
    }

    // ─────────────────────────────────────────────
    /// <summary>
    /// Appelée chaque frame dans Update().
    /// Compare les positions sur le plan XZ uniquement (ignore Y = hauteur caméra).
    /// Valide un item seulement après framesRequises frames consécutives correctes.
    /// </summary>
    void ValiderPositionsFrame()
    {
        if (!pagesLoaded || string.IsNullOrEmpty(currentPageId)) return;

        foreach (var tracked in trackedImageManager.trackables)
        {
            string imgName = tracked.referenceImage.name;

            // On ignore la feuille elle-même
            bool estFeuille = false;
            foreach (var p in pages)
                if (p.feuilleName == imgName) { estFeuille = true; break; }
            if (estFeuille) continue;

            // Déjà validé → on ne touche plus au compteur
            if (imagesValidees.Contains(imgName)) continue;

            if (!positionsGlobales.ContainsKey(imgName)) continue;
            if (tracked.trackingState != TrackingState.Tracking) continue;

            Vector3 posReelle   = tracked.transform.position;
            Vector3 posAttendue = positionsGlobales[imgName];

            // ── Distance 2D : ignore Y (hauteur caméra/feuille) ──────────
            float dist = Vector2.Distance(
                new Vector2(posReelle.x,   posReelle.z),
                new Vector2(posAttendue.x, posAttendue.z)
            );

            // Sauvegarde pour l'UI
            positionsReelles[imgName] = posReelle;
            distancesReelles[imgName] = dist;

            if (dist <= distanceMax)
            {
                if (!framesCorrectes.ContainsKey(imgName))
                    framesCorrectes[imgName] = 0;
                framesCorrectes[imgName]++;

                if (framesCorrectes[imgName] >= framesRequises)
                {
                    imagesValidees.Add(imgName);
                    Debug.Log($"✅ VALIDÉ STABLE ({framesRequises} frames) : {imgName} | dist2D={dist*100f:F1}cm");
                }
            }
            else
            {
                // Reset si une frame est incorrecte
                framesCorrectes[imgName] = 0;
            }
        }
    }

    // ─────────────────────────────────────────────
    public GameObject  GetPrefabForItem(string itemName) => DataManager.Instance.GetPrefab(itemName);
    public Texture2D   GetImageForItem(string itemName)  => DataManager.Instance.GetImage(itemName);
    public bool        IsItemReady(string itemName)      => DataManager.Instance.IsAssetReady(itemName);
    public ARBook.Models.ItemData GetItemData(string itemName) => DataManager.Instance.GetItemData(_bookId, itemName);

    // ─────────────────────────────────────────────
    void MettreAJourUI()
    {
        if (uiText == null) return;

        System.Text.StringBuilder sb = new System.Text.StringBuilder();
        sb.AppendLine("═══ AR LIBRARY TESTER ═══");
        sb.AppendLine($"📖 Livre : {(string.IsNullOrEmpty(_bookId) ? "—" : _bookId)}");
        sb.AppendLine(string.IsNullOrEmpty(currentPageId)
            ? "📚 Page active : aucune"
            : $"📚 Page active : {currentPageId}");
        sb.AppendLine($"🔍 Images trackées : {detectedImages.Count}");
        sb.AppendLine($"📌 Feuille figée : {(feuilleFigee ? "OUI ✅" : "NON ⏳")}");

        if (!pagesLoaded) { sb.AppendLine("⏳ En attente du cache..."); uiText.text = sb.ToString(); return; }

        sb.AppendLine("----------------------------");
        foreach (var page in pages)
        {
            bool isActive = page.pageId == currentPageId;
            string prefix = isActive ? "▶ " : "  ";
            sb.AppendLine($"{prefix}[{page.pageId}] feuille: {page.feuilleName}");

            for (int i = 0; i < page.imageNames.Count; i++)
            {
                string imgName = page.imageNames[i];

                bool detected       = detectedImages.ContainsKey(imgName);
                TrackingState state = detected ? detectedImages[imgName] : TrackingState.None;
                string icon         = !detected ? "○" : state == TrackingState.Tracking ? "✓" : "~";
                bool assetReady     = DataManager.Instance.IsAssetReady(imgName);
                string cacheIcon    = assetReady ? "💾" : "⏳";
                bool validated      = imagesValidees.Contains(imgName);

                string color = validated                        ? "green"
                             : !detected                       ? "white"
                             : state == TrackingState.Tracking ? "yellow" : "red";

                sb.AppendLine($"    <color={color}>{icon} {imgName} [{state}] {cacheIcon}</color>");

                // ── Affichage détaillé position ──────────────────────────
                if (isActive && positionsGlobales.ContainsKey(imgName))
                {
                    Vector3 attendue = positionsGlobales[imgName];

                    if (validated)
                    {
                        sb.AppendLine($"      <color=green>✅ Position correcte ! Cube spawné.</color>");
                    }
                    else if (positionsReelles.ContainsKey(imgName))
                    {
                        Vector3 reelle = positionsReelles[imgName];
                        float   dist   = distancesReelles.ContainsKey(imgName) ? distancesReelles[imgName] : -1f;
                        int     frames = framesCorrectes.ContainsKey(imgName)  ? framesCorrectes[imgName]  : 0;
                        bool    proche = dist >= 0f && dist <= distanceMax;

                        // Affichage XZ seulement (plan plat, Y ignoré)
                        sb.AppendLine($"      pos réelle   XZ : ({reelle.x:F3}, {reelle.z:F3})");
                        sb.AppendLine($"      pos attendue XZ : ({attendue.x:F3}, {attendue.z:F3})");

                        if (dist >= 0f)
                        {
                            string comparaison = proche
                                ? $"<color=yellow>≈ correct ({dist*100f:F1}cm ≤ {distanceMax*100f:F0}cm)</color>"
                                : $"<color=red>✗ incorrect ({dist*100f:F1}cm > {distanceMax*100f:F0}cm)</color>";
                            sb.AppendLine($"      distance 2D  : {comparaison}");

                            if (proche)
                                sb.AppendLine($"      stabilité    : <color=yellow>{frames}/{framesRequises} frames</color>");
                        }
                    }
                    else if (detected)
                    {
                        sb.AppendLine($"      pos attendue XZ : ({attendue.x:F3}, {attendue.z:F3})");
                        sb.AppendLine($"      <color=grey>⏳ calcul position en cours...</color>");
                    }
                }
                // ── Fin affichage détaillé ───────────────────────────────
            }
            sb.AppendLine();
        }

        sb.AppendLine("----------------------------");
        sb.AppendLine("○=non détecté ✓=tracké ~=perdu");
        sb.AppendLine("JAUNE=proche  VERT=validé ✅");
        sb.AppendLine("(distance calculée sur plan XZ)");
        uiText.text = sb.ToString();
    }

    // ─────────────────────────────────────────────
    void CreerUI()
    {
        GameObject canvasObj = new GameObject("CanvasTest");
        Canvas canvas        = canvasObj.AddComponent<Canvas>();
        canvas.renderMode    = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder  = 0;

        canvasObj.AddComponent<CanvasScaler>();
        // ⚠️ GraphicRaycaster supprimé intentionnellement

        GameObject textObj = new GameObject("UIText");
        textObj.transform.SetParent(canvasObj.transform, false);

        uiText                 = textObj.AddComponent<Text>();
        uiText.font            = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        uiText.fontSize        = 24;
        uiText.color           = Color.white;
        uiText.alignment       = TextAnchor.UpperLeft;
        uiText.supportRichText = true;
        uiText.raycastTarget   = false;

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin     = new Vector2(0, 0);
        rt.anchorMax     = new Vector2(1, 1);
        rt.offsetMin     = new Vector2(20, 20);
        rt.offsetMax     = new Vector2(-20, -20);
    }
}
/*claude solution
version finale verifiee - fix GraphicRaycaster + bookId dynamique depuis DataManager
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

/// <summary>
/// Book1Detector — Scène AR.
///
/// CE SCRIPT NE TÉLÉCHARGE RIEN.
/// Il lit DataManager.LastLoadedBookId pour savoir quel livre afficher.
/// Ce champ est rempli par QRScanner après le scan — il survit entre scènes
/// car DataManager est DontDestroyOnLoad.
///
/// Si LastLoadedBookId est vide ou le livre absent du cache → erreur console.
/// L'utilisateur ne peut pas arriver ici sans avoir scanné.
/// </summary>
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

    // ── bookId résolu dynamiquement depuis DataManager.LastLoadedBookId ──
    private string _bookId = "";

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
        StartCoroutine(WaitForCacheAndBuild());
    }

    void OnEnable()  => trackedImageManager.trackedImagesChanged += OnImagesChanged;
    void OnDisable() => trackedImageManager.trackedImagesChanged -= OnImagesChanged;
    void Update()    => MettreAJourUI();

    // ─────────────────────────────────────────────
    IEnumerator WaitForCacheAndBuild()
    {
        // Attendre que DataManager soit prêt (DontDestroyOnLoad)
        yield return new WaitUntil(() => DataManager.Instance != null);

        // Récupérer l'id du livre scanné — transmis par QRScanner via DataManager
        _bookId = DataManager.Instance.LastLoadedBookId;

        if (string.IsNullOrEmpty(_bookId))
        {
            Debug.LogError("[Book1Detector] ❌ Aucun livre scanné (LastLoadedBookId vide). " +
                           "L'utilisateur doit scanner un livre avant d'ouvrir cette scène.");
            yield break;
        }

        if (!DataManager.Instance.IsBookLoaded(_bookId))
        {
            Debug.LogError($"[Book1Detector] ❌ Livre '{_bookId}' absent du cache. " +
                           "QRScanner doit terminer le chargement avant le changement de scène.");
            yield break;
        }

        Debug.Log($"[Book1Detector] 📖 Livre reçu depuis le cache : {_bookId}");
        BuildPagesFromData();
    }

    // ─────────────────────────────────────────────
    void BuildPagesFromData()
    {
        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(_bookId);
        if (bookData == null)
        {
            Debug.LogError($"[Book1Detector] ❌ BookData introuvable pour '{_bookId}'.");
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
        Debug.Log($"[Book1Detector] ✅ {pages.Count} page(s) prêtes pour '{_bookId}'.");
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
                    DataManager.Instance.OnPageDetected(_bookId, page.pageId);
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
    public ARBook.Models.ItemData GetItemData(string itemName) => DataManager.Instance.GetItemData(_bookId, itemName);

    // ─────────────────────────────────────────────
    void MettreAJourUI()
    {
        if (uiText == null) return;

        System.Text.StringBuilder sb = new System.Text.StringBuilder();
        sb.AppendLine("═══ AR LIBRARY TESTER ═══");
        sb.AppendLine($"📖 Livre : {(string.IsNullOrEmpty(_bookId) ? "—" : _bookId)}");
        sb.AppendLine(string.IsNullOrEmpty(currentPageId)
            ? "📚 Page active : aucune"
            : $"📚 Page active : {currentPageId}");
        sb.AppendLine($"🔍 Images trackées : {detectedImages.Count}");

        if (!pagesLoaded) { sb.AppendLine("⏳ En attente du cache..."); uiText.text = sb.ToString(); return; }

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
    void CreerUI()
    {
        GameObject canvasObj   = new GameObject("CanvasTest");
        Canvas canvas          = canvasObj.AddComponent<Canvas>();
        canvas.renderMode      = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder    = 0;

        canvasObj.AddComponent<CanvasScaler>();
        // ⚠️ GraphicRaycaster supprimé intentionnellement

        GameObject textObj = new GameObject("UIText");
        textObj.transform.SetParent(canvasObj.transform, false);

        uiText                 = textObj.AddComponent<Text>();
        uiText.font            = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        uiText.fontSize        = 28;
        uiText.color           = Color.white;
        uiText.alignment       = TextAnchor.UpperLeft;
        uiText.supportRichText = true;
        uiText.raycastTarget   = false;

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin     = new Vector2(0, 0);
        rt.anchorMax     = new Vector2(1, 1);
        rt.offsetMin     = new Vector2(20, 20);
        rt.offsetMax     = new Vector2(-20, -20);
    }
}
/*version finale verifiee - fix GraphicRaycaster
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