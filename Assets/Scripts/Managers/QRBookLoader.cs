using System.Collections;
using System.Collections.Generic;
using Unity.Collections;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using ZXing;
using ZXing.Common;

public class QRBookLoader : MonoBehaviour
{
    [Header("AR Setup")]
    public ARCameraManager cameraManager;

    private BarcodeReaderGeneric _reader;
    private bool _isProcessing = false;
    private string _lastScannedId = "";
    private Texture2D _cameraTexture;

    // 🔥 Anti-spam scan
    private float lastScanTime = 0f;
    private float scanDelay = 2f;

    void Start()
    {
        Debug.Log("[QRBookLoader] ✅ Script démarré !");

        if (cameraManager == null)
        {
            Debug.LogError("[QRBookLoader] ❌ cameraManager NULL !");
            return;
        }

        Debug.Log("[QRBookLoader] ✅ cameraManager OK : " + cameraManager.name);

        // Abonnement ici dans Start, pas dans OnEnable
        cameraManager.frameReceived += OnCameraFrameReceived;
        Debug.Log("[QRBookLoader] ✅ Abonné aux frames caméra");

        _reader = new BarcodeReaderGeneric
        {
            Options = new DecodingOptions
            {
                TryHarder = true,
                PossibleFormats = new List<BarcodeFormat> { BarcodeFormat.QR_CODE }
            }
        };
    }

    void OnDisable()
    {
        if (cameraManager != null)
            cameraManager.frameReceived -= OnCameraFrameReceived;
    }

    // Supprime OnEnable complètement

    void OnDestroy()
    {
        if (_cameraTexture != null)
            Destroy(_cameraTexture);
    }
    private int _frameCount = 0;

    void OnCameraFrameReceived(ARCameraFrameEventArgs args)
    {
        // Log seulement toutes les 60 frames
        _frameCount++;
        if (_frameCount % 60 == 0)
            Debug.Log($"[QRBookLoader] 📷 Frames reçues : {_frameCount}");

        if (_isProcessing) return;

        if (!cameraManager.TryAcquireLatestCpuImage(out XRCpuImage image))
        {
            if (_frameCount % 60 == 0)
                Debug.LogWarning("[QRBookLoader] ⚠️ TryAcquireLatestCpuImage échoué");
            return;
        }

        _isProcessing = true;

        try
        {
            int width = image.width;
            int height = image.height;

            var conversionParams = new XRCpuImage.ConversionParams
            {
                inputRect = new RectInt(0, 0, width, height),
                outputDimensions = new Vector2Int(width / 2, height / 2), // 🔥 optimisation perf
                outputFormat = TextureFormat.RGBA32,
                transformation = XRCpuImage.Transformation.MirrorY
            };

            int bufferSize = image.GetConvertedDataSize(conversionParams);
            var buffer = new NativeArray<byte>(bufferSize, Allocator.Temp);

            image.Convert(conversionParams, buffer);
            image.Dispose();

            int outW = conversionParams.outputDimensions.x;
            int outH = conversionParams.outputDimensions.y;

            if (_cameraTexture == null || _cameraTexture.width != outW || _cameraTexture.height != outH)
            {
                if (_cameraTexture != null) Destroy(_cameraTexture);
                _cameraTexture = new Texture2D(outW, outH, TextureFormat.RGBA32, false);
            }

            _cameraTexture.LoadRawTextureData(buffer);
            _cameraTexture.Apply();
            buffer.Dispose();

            byte[] rawData = _cameraTexture.GetRawTextureData();

            var luminance = new RGBLuminanceSource(rawData, outW, outH);

            var result = _reader.Decode(luminance);

            // 🔥 Anti-spam + éviter double scan
            if (result != null &&
                result.Text != _lastScannedId &&
                Time.time - lastScanTime > scanDelay)
            {
                _lastScannedId = result.Text;
                lastScanTime = Time.time;

                Debug.Log($"[QRBookLoader] QR détecté : {result.Text}");
                OnQRCodeDetected(result.Text);
            }
        }
        finally
        {
            _isProcessing = false;
        }
    }

    void OnQRCodeDetected(string bookId)
    {
        var entry = DataManager.Instance.GetBookEntry(bookId);

        if (entry == null)
        {
            Debug.LogWarning($"[QRBookLoader] Aucun livre pour l'ID : {bookId}");
            return;
        }

        Debug.Log($"[QRBookLoader] Livre trouvé : {entry.title}");
        StartCoroutine(LoadAndDisplay(bookId));
    }

    private IEnumerator LoadAndDisplay(string bookId)
    {
        // Télécharger le JSON du livre
        yield return StartCoroutine(DataManager.Instance.LoadBookFromUrl(bookId));

        ARBook.Models.BookData bookData = DataManager.Instance.GetBookData(bookId);

        if (bookData == null)
        {
            Debug.LogError($"[QRBookLoader] Échec chargement : {bookId}");
            yield break;
        }

        Debug.Log($"[QRBookLoader] ✅ Livre prêt : {bookData.title} ({bookData.pages.Count} page(s))");

        // Lancer le préchargement de la première page
        // (et les voisines en background automatiquement)
        if (bookData.pages.Count > 0)
        {
            string firstPageId = bookData.pages[0].id;
            Debug.Log($"[QRBookLoader] 🚀 Préchargement page : {firstPageId}");
            DataManager.Instance.OnPageDetected(bookId, firstPageId);
        }
    }
}