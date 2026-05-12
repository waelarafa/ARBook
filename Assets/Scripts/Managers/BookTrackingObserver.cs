using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;

// Ce script observe le tracking AR sans modifier Book1Detector
public class BookTrackingObserver : MonoBehaviour
{
    [Header("Assigne le ARTrackedImageManager ici")]
    public ARTrackedImageManager trackedImageManager;

    private const string BOOK_FEUILLE_PREFIX = "F"; // les feuilles commencent par "F"
    private float _bookDetectedTime = -1f;
    private bool _bookCurrentlyTracked = false;
    private float _sessionStartTime;

    void Start()
    {
        _sessionStartTime = Time.realtimeSinceStartup;
    }

    void OnEnable()
    {
        if (trackedImageManager != null)
            trackedImageManager.trackedImagesChanged += OnImagesChanged;
    }

    void OnDisable()
    {
        if (trackedImageManager != null)
            trackedImageManager.trackedImagesChanged -= OnImagesChanged;
    }

    void OnImagesChanged(ARTrackedImagesChangedEventArgs args)
    {
        // Détection : une feuille (commence par "F") est trackée
        foreach (var img in args.added)
        {
            if (img.referenceImage.name.StartsWith(BOOK_FEUILLE_PREFIX)
                && img.trackingState == TrackingState.Tracking
                && !_bookCurrentlyTracked)
            {
                _bookCurrentlyTracked = true;
                _bookDetectedTime = Time.realtimeSinceStartup;
                float timeToDetect = _bookDetectedTime - _sessionStartTime;

                if (AnalyticsManager.Instance != null)
                    AnalyticsManager.Instance.LogBookDetected("book_001", timeToDetect);
            }
        }

        // Perte : la feuille n'est plus trackée
        foreach (var img in args.removed)
        {
            if (img.referenceImage.name.StartsWith(BOOK_FEUILLE_PREFIX)
                && _bookCurrentlyTracked)
            {
                _bookCurrentlyTracked = false;
                float duration = Time.realtimeSinceStartup - _bookDetectedTime;

                if (AnalyticsManager.Instance != null)
                    AnalyticsManager.Instance.LogBookLost("book_001", duration);
            }
        }
    }
}