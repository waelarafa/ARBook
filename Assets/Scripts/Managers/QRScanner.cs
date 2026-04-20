using System.Collections;
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

        float timer = 0f;
        while (DataManager.Instance.GetBookEntry(bookId) == null && timer < 10f)
        {
            timer += Time.deltaTime;
            yield return null;
        }

        if (DataManager.Instance.GetBookEntry(bookId) == null)
        {
            Debug.LogWarning($"[QRScanner] ❌ Livre introuvable : {bookId}");
            yield break;
        }

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

        // ✅ ICI : tout est chargé → on passe à la scène BookFinder
        Debug.Log("[QRScanner] 🚀 Transition vers BookFinder...");
        SceneManager.LoadScene("BookPositionIcon"); // ← mets le nom exact de ta scène
    }
}

    // ─────────────────────────────────────────────
    // CHARGEMENT DU LIVRE
    // ─────────────────────────────────────────────
/*
    private IEnumerator HandleBookId(string bookId)
    {
        Debug.Log($"[QRScanner] 📖 Recherche du livre : {bookId}");

        // Vérifier DataManager
        if (DataManager.Instance == null)
        {
            Debug.LogError("[QRScanner] ❌ DataManager.Instance introuvable !");
            yield break;
        }

        // Attendre que le catalogue soit chargé (max 10 secondes)
        float timer = 0f;
        while (DataManager.Instance.GetBookEntry(bookId) == null && timer < 10f)
        {
            timer += Time.deltaTime;
            yield return null;
        }

        if (DataManager.Instance.GetBookEntry(bookId) == null)
        {
            Debug.LogWarning($"[QRScanner] ❌ Livre introuvable dans le catalogue : {bookId}");
            yield break;
        }

        Debug.Log($"[QRScanner] 📚 Livre trouvé, chargement...");

        // Charger les données du livre
        yield return StartCoroutine(DataManager.Instance.LoadBookFromUrl(bookId));

        var bookData = DataManager.Instance.GetBookData(bookId);
        if (bookData == null)
        {
            Debug.LogError($"[QRScanner] ❌ Échec chargement données : {bookId}");
            yield break;
        }

        Debug.Log($"[QRScanner] ✅ Livre prêt : {bookData.title} ({bookData.pages.Count} pages)");

        // Précharger la première page
        if (bookData.pages.Count > 0)
        {
            string firstPageId = bookData.pages[0].id;
            Debug.Log($"[QRScanner] 🚀 Préchargement première page : {firstPageId}");
            DataManager.Instance.OnPageDetected(bookId, firstPageId);
        }
    }

}*/