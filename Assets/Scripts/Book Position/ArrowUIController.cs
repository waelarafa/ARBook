using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.Collections;
using TMPro;

public class ArrowUIController : MonoBehaviour
{
    [Header("References")]
    public DirectionCalculator directionCalculator;
    public ARTrackedImageManager trackedImageManager;

    [Header("UI Elements")]
    public GameObject arrowContainer;
    public RectTransform arrowImage;
    public GameObject foundMessage;
    public TextMeshProUGUI foundMessageText;

    [Header("Timing")]
    public float centerDuration = 2.5f;

    // Positions
    private readonly Vector2 centerPosition = new Vector2(0f, -60f);
    private readonly Vector2 cornerPosition = new Vector2(-80f, 80f);

    private RectTransform containerRect;
    private bool bookCurrentlyVisible = false;
    private bool compassShownThisCycle = false;

   

    private bool foundMessageShown = false;

    // ✅ Coroutines séparées
    private Coroutine compassCoroutine;
    private Coroutine messageCoroutine;

    private void Awake()
    {
        containerRect = arrowContainer.GetComponent<RectTransform>();

        arrowContainer.SetActive(false);
        foundMessage.SetActive(false);
    }

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
        bookCurrentlyVisible = false;

        foreach (var img in eventArgs.added)
            if (img.trackingState == TrackingState.Tracking)
                bookCurrentlyVisible = true;

        foreach (var img in eventArgs.updated)
            if (img.trackingState == TrackingState.Tracking)
                bookCurrentlyVisible = true;
    }

    private void Update()
    {
        if (!BookPositionMemory.BookDetected)
        {
            arrowContainer.SetActive(false);
            foundMessage.SetActive(false);
            compassShownThisCycle = false;
            foundMessageShown = false;
            
            return;
        }

        // 📖 Livre visible
        if (bookCurrentlyVisible)
        {
            // cacher boussole
            if (arrowContainer.activeSelf)
            {
                arrowContainer.SetActive(false);

                if (compassCoroutine != null)
                {
                    StopCoroutine(compassCoroutine);
                    compassCoroutine = null;
                }

                compassShownThisCycle = false;
            }

            // afficher message une seule fois
            if (!foundMessageShown)
            {
                foundMessageShown = true;
                ShowFoundMessage();
            }
        }
        else
        {
            // cacher message
            if (foundMessage.activeSelf)
            {
                foundMessage.SetActive(false);
                foundMessageShown = false;

                if (messageCoroutine != null)
                {
                    StopCoroutine(messageCoroutine);
                    messageCoroutine = null;
                }
            }

            // lancer boussole une seule fois
            if (!compassShownThisCycle)
            {
                compassShownThisCycle = true;
                ShowCompassAtCenter();
            }

            RotateArrow(directionCalculator.AngleToBook);
        }
    }

    // ───────────── Boussole ─────────────

    private void ShowCompassAtCenter()
    {
        arrowContainer.SetActive(true);
        containerRect.anchoredPosition = new Vector2(0, 100); ;
    }
        /*if (compassCoroutine != null) StopCoroutine(compassCoroutine);
        compassCoroutine = StartCoroutine(AnimateMoveToCorner());
    }
    

    private IEnumerator AnimateMoveToCorner()
    {
        yield return new WaitForSeconds(2f);

        float elapsed = 0f;
        float duration = 0.6f;

        Vector2 startPos = containerRect.anchoredPosition;

        while (elapsed < duration)
        {
            elapsed += Time.deltaTime;
            float t = Mathf.SmoothStep(0f, 1f, elapsed / duration);

            containerRect.anchoredPosition = Vector2.Lerp(startPos, cornerPosition, t);

            yield return null;
        }

        containerRect.anchoredPosition = cornerPosition;
    }*/

    // ───────────── Message ─────────────

    private void ShowFoundMessage()
    {
        RectTransform msgRect = foundMessage.GetComponent<RectTransform>();

        foundMessage.SetActive(true);

        // ✅ Position corrigée (visible en haut)
        msgRect.anchoredPosition = new Vector2(0, -120);

        // ✅ Sécurité visibilité
        msgRect.localScale = Vector3.one;

        if (foundMessageText != null)
            foundMessageText.text = " Livre Trouvé ! ";

        if (messageCoroutine != null) StopCoroutine(messageCoroutine);
        messageCoroutine = StartCoroutine(AnimateFoundMessage());
    }

    private IEnumerator AnimateFoundMessage()
    {
        RectTransform msgRect = foundMessage.GetComponent<RectTransform>();

        // POP (0 → 1.3)
        float elapsed = 0f;
        msgRect.localScale = Vector3.zero;

        while (elapsed < 0.4f)
        {
            elapsed += Time.deltaTime;
            float t = Mathf.SmoothStep(0f, 1f, elapsed / 0.4f);
            msgRect.localScale = Vector3.one * Mathf.Lerp(0f, 1.3f, t);
            yield return null;
        }

        // Bounce
        elapsed = 0f;
        while (elapsed < 0.25f)
        {
            elapsed += Time.deltaTime;
            float scale = Mathf.Lerp(1.3f, 0.9f, elapsed / 0.25f);
            msgRect.localScale = Vector3.one * scale;
            yield return null;
        }

        elapsed = 0f;
        while (elapsed < 0.2f)
        {
            elapsed += Time.deltaTime;
            float scale = Mathf.Lerp(0.9f, 1f, elapsed / 0.2f);
            msgRect.localScale = Vector3.one * scale;
            yield return null;
        }

        msgRect.localScale = Vector3.one;

        // effet flottant
        StartCoroutine(FloatEffect(msgRect));
    }

    private IEnumerator FloatEffect(RectTransform rect)
    {
        Vector2 startPos = rect.anchoredPosition;

        while (true)
        {
            float yOffset = Mathf.Sin(Time.time * 2f) * 10f;
            rect.anchoredPosition = startPos + new Vector2(0, yOffset);
            yield return null;
        }
    }

    // ───────────── Rotation ─────────────

    private void RotateArrow(float angle)
    {
        arrowImage.rotation = Quaternion.Euler(0f, 0f, angle - 90f);
    }
}

/*using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;

public class ArrowUIController : MonoBehaviour
{
    [Header("References")]
    public DirectionCalculator directionCalculator;
    public ARTrackedImageManager trackedImageManager;

    [Header("UI Elements")]
    public GameObject arrowContainer;   // Le GameObject parent de la flèche
    public RectTransform arrowImage;    // La flèche elle-même (RectTransform)
    public GameObject foundMessage;     // Message "Livre trouvé !" (optionnel)

    private bool bookCurrentlyVisible = false;

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
        bookCurrentlyVisible = false;

        // IMPORTANT : added + updated
        foreach (var img in eventArgs.added)
        {
            if (img.trackingState == TrackingState.Tracking)
                bookCurrentlyVisible = true;
        }

        foreach (var img in eventArgs.updated)
        {
            if (img.trackingState == TrackingState.Tracking)
                bookCurrentlyVisible = true;
        }
    }

    private void Update()
    {
        if (!BookPositionMemory.BookDetected)
        {
            // Aucun livre détecté encore → tout cacher
            arrowContainer.SetActive(false);
            if (foundMessage) foundMessage.SetActive(false);
            return;
        }

        if (bookCurrentlyVisible)
        {
            // Livre visible → cacher la flèche, afficher message
            arrowContainer.SetActive(false);
            if (foundMessage) foundMessage.SetActive(true);
        }
        else
        {
            // Livre hors champ → afficher et orienter la flèche
            arrowContainer.SetActive(true);
            if (foundMessage) foundMessage.SetActive(false);

            RotateArrow(directionCalculator.AngleToBook);
        }
    }

    private void RotateArrow(float angle)
    {
        // 🔥 +90 pour que la flèche "vers le haut" soit correcte
        arrowImage.rotation = Quaternion.Euler(0f, 0f, angle - 90f);
    }
}*/