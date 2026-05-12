using System.Collections;
using System.Collections.Generic;
using Unity.Collections;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using ZXing;
using ZXing.Common;
using TMPro;

/// <summary>
/// QRScanner — Version Panel_Scanner (espace parental).
///
/// FIX CAMERA NOIRE :
///   Active/désactive ARSession + XR Origin au moment d'ouvrir/fermer le scanner.
///   Sans ça, ARCameraManager ne reçoit aucune frame → fond noir.
///
/// SETUP INSPECTOR :
///   - cameraManager : ARCameraManager (enfant de AR Camera sous XR Origin)
///   - arSession     : GameObject qui porte le composant ARSession
///   - xrOrigin      : GameObject XR Origin (ou AR Session Origin)
///   - txt_Status    : TextMeshProUGUI dans Panel_Scanner
/// </summary>
public class QRScanner : MonoBehaviour
{
    [Header("AR Setup")]
    public ARCameraManager cameraManager;

    [Tooltip("GameObject qui porte le composant ARSession — sera activé pendant le scan")]
    public GameObject arSession;

    [Tooltip("GameObject XR Origin (ou AR Session Origin) — sera activé pendant le scan")]
    public GameObject xrOrigin;

    [Header("UI Feedback")]
    public TextMeshProUGUI txt_Status;

    // ── ZXing ─────────────────────────────────────────────────
    private BarcodeReaderGeneric _reader;

    // ── Anti-spam ─────────────────────────────────────────────
    private float _lastScanTime = 0f;
    private const float SCAN_DELAY = 2f;

    // ── État ──────────────────────────────────────────────────
    private bool _isProcessing = false;
    private string _lastScannedId = "";
    private bool _scanActive = false;

    // ── Texture réutilisable ──────────────────────────────────
    private Texture2D _camTexture;

    // ══════════════════════════════════════════════════════════
    // INIT
    // ══════════════════════════════════════════════════════════
    void Start()
    {
        if (cameraManager == null)
        {
            Debug.LogError("[QRScanner] ❌ ARCameraManager non assigné !");
            enabled = false;
            return;
        }

        _reader = new BarcodeReaderGeneric
        {
            AutoRotate = true,
            Options = new DecodingOptions
            {
                TryHarder = true,
                PossibleFormats = new List<BarcodeFormat> { BarcodeFormat.QR_CODE }
            }
        };

        // AR désactivé au départ — s'active seulement quand Panel_Scanner s'ouvre
        SetARActive(false);

        cameraManager.frameReceived += OnCameraFrameReceived;
        SetStatus("📷 Prêt à scanner");
        Debug.Log("[QRScanner] ✅ Initialisé");
    }

    void OnDisable()
    {
        if (cameraManager != null)
            cameraManager.frameReceived -= OnCameraFrameReceived;
    }

    void OnDestroy()
    {
        if (_camTexture != null)
            Destroy(_camTexture);
    }

    // ══════════════════════════════════════════════════════════
    // CONTRÔLE AR SESSION
    // ══════════════════════════════════════════════════════════

    /// Active ou désactive ARSession + XR Origin ensemble.
    void SetARActive(bool active)
    {
        if (arSession != null)
            arSession.SetActive(active);

        if (xrOrigin != null)
            xrOrigin.SetActive(active);

        Debug.Log($"[QRScanner] AR {(active ? "▶️ activé" : "⏹️ désactivé")}");
    }

    // ══════════════════════════════════════════════════════════
    // CONTRÔLE EXTERNE — appelé par AuthManagerV2
    // ══════════════════════════════════════════════════════════

    /// Appelé par AuthManagerV2.GoToScanner() quand Panel_Scanner s'affiche.
    public void EnableScanner()
    {
        _scanActive = true;
        _lastScannedId = ""; // reset pour re-scanner

        // ✅ Activer la session AR → la caméra démarre
        SetARActive(true);

        // Laisser une frame pour que ARSession s'initialise avant de scanner
        StartCoroutine(WaitAndSetStatus());
    }

    private IEnumerator WaitAndSetStatus()
    {
        yield return new WaitForSeconds(0.5f);
        SetStatus("📷 Pointez la caméra vers le QR code du livre");
    }

    /// Appelé par AuthManagerV2.BackFromScanner() quand Panel_Scanner se ferme.
    public void DisableScanner()
    {
        _scanActive = false;

        // ✅ Désactiver la session AR pour économiser la batterie
        SetARActive(false);

        Debug.Log("[QRScanner] ⏹️ Scanner désactivé");
    }

    // ══════════════════════════════════════════════════════════
    // RÉCEPTION FRAME
    // ══════════════════════════════════════════════════════════
    void OnCameraFrameReceived(ARCameraFrameEventArgs args)
    {
        if (!_scanActive) return;
        if (Time.time - _lastScanTime < SCAN_DELAY) return;
        if (_isProcessing) return;
        if (!cameraManager.TryAcquireLatestCpuImage(out XRCpuImage image)) return;

        _isProcessing = true;

        try
        {
            ProcessImage(image);
        }
        finally
        {
            image.Dispose();
            _isProcessing = false;
        }
    }

    // ══════════════════════════════════════════════════════════
    // TRAITEMENT IMAGE + DÉCODAGE QR
    // ══════════════════════════════════════════════════════════
    private void ProcessImage(XRCpuImage image)
    {
        var convParams = new XRCpuImage.ConversionParams
        {
            inputRect = new RectInt(0, 0, image.width, image.height),
            outputDimensions = new Vector2Int(image.width / 2, image.height / 2),
            outputFormat = TextureFormat.RGB24,
            transformation = XRCpuImage.Transformation.MirrorY
        };

        int size = image.GetConvertedDataSize(convParams);
        var buffer = new NativeArray<byte>(size, Allocator.Temp);
        image.Convert(convParams, buffer);

        int w = convParams.outputDimensions.x;
        int h = convParams.outputDimensions.y;

        if (_camTexture == null || _camTexture.width != w || _camTexture.height != h)
        {
            if (_camTexture != null) Destroy(_camTexture);
            _camTexture = new Texture2D(w, h, TextureFormat.RGB24, false);
        }

        _camTexture.LoadRawTextureData(buffer);
        _camTexture.Apply();
        buffer.Dispose();

        byte[] rawBytes = _camTexture.GetRawTextureData();
        var result = _reader.Decode(rawBytes, w, h, RGBLuminanceSource.BitmapFormat.RGB24);

        if (result != null && result.Text != _lastScannedId)
        {
            _lastScannedId = result.Text;
            _lastScanTime = Time.time;

            Debug.Log($"[QRScanner] ✅ QR détecté : {result.Text}");
            StartCoroutine(HandleBookId(result.Text.Trim()));
        }
    }

    // ══════════════════════════════════════════════════════════
    // LOGIQUE APRÈS SCAN
    // ══════════════════════════════════════════════════════════
    private IEnumerator HandleBookId(string bookId)
    {
        SetStatus($"⏳ Chargement du livre...");

        if (DataManager.Instance == null)
        {
            SetStatus("❌ DataManager introuvable !");
            Debug.LogError("[QRScanner] ❌ DataManager.Instance introuvable !");
            yield break;
        }

        // Attendre catalogue (max 20s)
        float timer = 0f;
        while (DataManager.Instance.GetBookEntry(bookId) == null && timer < 20f)
        {
            if (timer % 2f < Time.deltaTime)
                Debug.Log($"[QRScanner] ⏳ Attente catalogue... ({timer:F0}s)");
            timer += Time.deltaTime;
            yield return null;
        }

        if (DataManager.Instance.GetBookEntry(bookId) == null)
        {
            SetStatus("❌ Livre introuvable — vérifie la connexion");
            yield break;
        }

        yield return StartCoroutine(DataManager.Instance.LoadBookFromUrl(bookId));

        var bookData = DataManager.Instance.GetBookData(bookId);
        if (bookData == null)
        {
            SetStatus($"❌ Échec chargement : {bookId}");
            yield break;
        }

        // ✅ Enregistrer dans BookLibraryManager
        if (BookLibraryManager.Instance != null)
        {
            bool isNew = BookLibraryManager.Instance.AddScannedBook(bookId, bookData.title);
            SetStatus(isNew
                ? $"✅ \"{bookData.title}\" ajouté !\nActivez-le dans Paramètres."
                : $"ℹ️ \"{bookData.title}\" déjà dans la liste.");
        }
        else
        {
            SetStatus($"✅ Détecté : {bookData.title}");
        }

        Debug.Log($"[QRScanner] ✅ Livre traité : {bookData.title}");

        // Stop le scan après succès
        _scanActive = false;
    }

    // ══════════════════════════════════════════════════════════
    // HELPER
    // ══════════════════════════════════════════════════════════
    void SetStatus(string msg)
    {
        if (txt_Status != null)
            txt_Status.text = msg;
        Debug.Log($"[QRScanner] {msg}");
    }
}



/*using System.Collections;
using System.Collections.Generic;
using Unity.Collections;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using ZXing;
using ZXing.Common;
using UnityEngine.SceneManagement;

public class QRScanner : MonoBehaviour
{
    [Header("AR Setup")]
    public ARCameraManager cameraManager;

    // ───── ZXing ─────
    private BarcodeReaderGeneric _reader;

    // ───── Anti-spam ─────
    private float _lastScanTime = 0f;
    private const float SCAN_DELAY = 2f;

    // ───── État ─────
    private bool _isProcessing = false;
    private string _lastScannedId = "";

    // ───── Texture réutilisable ─────
    private Texture2D _camTexture;

    // ─────────────────────────────────────────────
    void Start()
    {
        if (cameraManager == null)
        {
            Debug.LogError("[QRScanner] ❌ ARCameraManager non assigné dans l'Inspector !");
            enabled = false;
            return;
        }

        // ZXing : lecteur QR uniquement
        _reader = new BarcodeReaderGeneric
        {
            AutoRotate = true,
            Options = new DecodingOptions
            {
                TryHarder = true,
                PossibleFormats = new List<BarcodeFormat> { BarcodeFormat.QR_CODE }
            }
        };

        cameraManager.frameReceived += OnCameraFrameReceived;
        Debug.Log("[QRScanner] ✅ Scanner prêt.");
    }

    void OnDisable()
    {
        if (cameraManager != null)
            cameraManager.frameReceived -= OnCameraFrameReceived;
    }

    void OnDestroy()
    {
        if (_camTexture != null)
            Destroy(_camTexture);
    }

    // ─────────────────────────────────────────────
    // RÉCEPTION FRAME
    // ─────────────────────────────────────────────
    void OnCameraFrameReceived(ARCameraFrameEventArgs args)
    {
        // Anti-spam : on attend SCAN_DELAY secondes entre chaque tentative
        if (Time.time - _lastScanTime < SCAN_DELAY) return;
        if (_isProcessing) return;
        if (!cameraManager.TryAcquireLatestCpuImage(out XRCpuImage image)) return;

        _isProcessing = true;

        try
        {
            ProcessImage(image);
        }
        finally
        {
            image.Dispose(); // toujours libérer
            _isProcessing = false;
        }
    }

    // ─────────────────────────────────────────────
    // TRAITEMENT IMAGE + DÉCODAGE QR
    // ─────────────────────────────────────────────
    private void ProcessImage(XRCpuImage image)
    {
        // On réduit la résolution de moitié pour les perfs
        var convParams = new XRCpuImage.ConversionParams
        {
            inputRect = new RectInt(0, 0, image.width, image.height),
            outputDimensions = new Vector2Int(image.width / 2, image.height / 2),
            outputFormat = TextureFormat.RGB24, // ✅ RGB24, plus simple pour ZXing
            transformation = XRCpuImage.Transformation.MirrorY
        };

        int size = image.GetConvertedDataSize(convParams);
        var buffer = new NativeArray<byte>(size, Allocator.Temp);
        image.Convert(convParams, buffer);

        int w = convParams.outputDimensions.x;
        int h = convParams.outputDimensions.y;

        // Réutiliser la texture si même taille
        if (_camTexture == null || _camTexture.width != w || _camTexture.height != h)
        {
            if (_camTexture != null) Destroy(_camTexture);
            _camTexture = new Texture2D(w, h, TextureFormat.RGB24, false);
        }

        _camTexture.LoadRawTextureData(buffer);
        _camTexture.Apply();
        buffer.Dispose();

        // ✅ Color32[] → ZXing lit correctement RGB
        byte[] rawBytes = _camTexture.GetRawTextureData();
        var result = _reader.Decode(rawBytes, w, h, RGBLuminanceSource.BitmapFormat.RGB24);

        if (result != null && result.Text != _lastScannedId)
        {
            _lastScannedId = result.Text;
            _lastScanTime = Time.time;

            Debug.Log($"[QRScanner] ✅ QR détecté : {result.Text}");
            string cleanId = result.Text.Trim();
            StartCoroutine(HandleBookId(cleanId));
        }
    }
    private IEnumerator HandleBookId(string bookId)
    {
        Debug.Log($"[QRScanner] 📖 Recherche du livre : {bookId}");

        if (DataManager.Instance == null)
        {
            Debug.LogError("[QRScanner] ❌ DataManager.Instance introuvable !");
            yield break;
        }

        // Attendre que le catalogue soit chargé
        float timer = 0f;
        while (DataManager.Instance.GetBookEntry(bookId) == null && timer < 20f)
        {
            if (timer % 2f < Time.deltaTime) // log toutes les 2s
                Debug.Log($"[QRScanner] ⏳ Attente catalogue... ({timer:F0}s)");
            timer += Time.deltaTime;
            yield return null;
        }

        if (DataManager.Instance.GetBookEntry(bookId) == null)
        {
            Debug.LogError($"[QRScanner] ❌ Catalogue toujours vide après 20s — vérifie la connexion réseau ou l'URL GitHub");
            yield break;
        }

        Debug.Log($"[QRScanner] ✅ Catalogue prêt, chargement du livre...");
        yield return StartCoroutine(DataManager.Instance.LoadBookFromUrl(bookId));

        var bookData = DataManager.Instance.GetBookData(bookId);
        if (bookData == null)
        {
            Debug.LogError($"[QRScanner] ❌ Échec chargement : {bookId}");
            yield break;
        }

        Debug.Log($"[QRScanner] ✅ Livre prêt : {bookData.title}");

        if (bookData.pages.Count > 0)
        {
            string firstPageId = bookData.pages[0].id;
            DataManager.Instance.OnPageDetected(bookId, firstPageId);
        }

        Debug.Log("[QRScanner] 🚀 Tout est prêt !");
        //SceneManager.LoadScene("GymTesnime", LoadSceneMode.Additive);
    }
}

 */