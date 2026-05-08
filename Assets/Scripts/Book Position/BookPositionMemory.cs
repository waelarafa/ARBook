using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.Collections.Generic;

public class BookPositionMemory : MonoBehaviour
{
    [Header("AR Components")]
    public ARTrackedImageManager trackedImageManager;

    // Position mémorisée du livre dans le monde réel
    public static Vector3 BookWorldPosition { get; private set; }
    public static bool BookDetected { get; private set; } = false;

    private void OnEnable()
    {
        trackedImageManager.trackablesChanged.AddListener(OnTrackedImagesChanged);
    }

    private void OnDisable()
    {
        trackedImageManager.trackablesChanged.RemoveListener(OnTrackedImagesChanged);
    }

    private void OnTrackedImagesChanged(ARTrackablesChangedEventArgs<ARTrackedImage> eventArgs)
    {
        // Vérifier les images nouvellement détectées
        foreach (var trackedImage in eventArgs.added)
        {
            MemorizePosition(trackedImage);
        }

        // Mettre à jour si le livre est encore visible
        foreach (var trackedImage in eventArgs.updated)
        {
            if (trackedImage.trackingState == TrackingState.Tracking)
            {
                MemorizePosition(trackedImage);
            }
        }
    }

    private void MemorizePosition(ARTrackedImage trackedImage)
    {
        BookWorldPosition = trackedImage.transform.position;
        BookDetected = true;

        Debug.Log($"📖 Livre détecté : position mémorisée → {BookWorldPosition}");
    }
}