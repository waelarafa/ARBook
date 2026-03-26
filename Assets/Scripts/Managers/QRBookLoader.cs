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
        _reader = new BarcodeReaderGeneric
        {
            Options = new DecodingOptions
            {
                TryHarder = true,
                PossibleFormats = new List<BarcodeFormat> { BarcodeFormat.QR_CODE }
            }
        };
    }

    void OnEnable()
    {
        if (cameraManager != null)
            cameraManager.frameReceived += OnCameraFrameReceived;
    }

    void OnDisable()
    {
        if (cameraManager != null)
            cameraManager.frameReceived -= OnCameraFrameReceived;
    }

    void OnDestroy()
    {
        if (_cameraTexture != null)
            Destroy(_cameraTexture);
    }

    void OnCameraFrameReceived(ARCameraFrameEventArgs args)
    {
        if (_isProcessing) return;

        if (cameraManager == null)
        {
            Debug.LogError("[QRBookLoader] CameraManager non assigné !");
            return;
        }

        if (!cameraManager.TryAcquireLatestCpuImage(out XRCpuImage image))
            return;

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
        yield return StartCoroutine(DataManager.Instance.LoadBookFromUrl(bookId));

        var bookData = DataManager.Instance.GetBookData(bookId);

        if (bookData == null)
        {
            Debug.LogError($"[QRBookLoader] Échec chargement : {bookId}");
            yield break;
        }

        Debug.Log($"[QRBookLoader] Prêt à afficher : {bookData.title} ({bookData.pages.Count} page(s))");

        // 👉 PROCHAINE ETAPE: envoyer à ton ARManager
        // ARManager.Instance.DisplayBook(bookData);
    }
}