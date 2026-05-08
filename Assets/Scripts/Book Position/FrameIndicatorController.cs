using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.Collections;
using TMPro;
using UnityEngine.SceneManagement;

public class FrameIndicatorController : MonoBehaviour
{
    [Header("References")]
    public DirectionCalculator directionCalculator;
    public ARTrackedImageManager trackedImageManager;

    [Header("UI - Cadre")]
    public RectTransform frameRect;
    public RectTransform placeholderIcon;

    [Header("UI - Message")]
    public GameObject foundMessage;
    public TextMeshProUGUI foundMessageText;

    [Header("Settings")]
    public float iconRotationDegreesPerSecond = 360f;

    // État
    private bool bookCurrentlyVisible = false;
    private bool foundMessageShown = false;
    private Coroutine messageCoroutine;
    private float currentAngle = 90f;
    private bool angleInitialized = false; // ← clé de la solution

    private void Awake()
    {
        if (placeholderIcon != null) placeholderIcon.gameObject.SetActive(false);
        if (foundMessage != null) foundMessage.SetActive(false);
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
        bool stillVisible = false;

        foreach (var img in trackedImageManager.trackables)
        {
            if (img.trackingState == TrackingState.Tracking)
            {
                stillVisible = true;
                break;
            }
        }

        bookCurrentlyVisible = stillVisible;
    }

    private void Update()
    {
        if (placeholderIcon == null || frameRect == null) return;

        // ─── Livre jamais détecté → cacher tout
        if (!BookPositionMemory.BookDetected)
        {
            placeholderIcon.gameObject.SetActive(false);
            if (foundMessage != null) foundMessage.SetActive(false);
            angleInitialized = false; // reset pour la prochaine fois
            return;
        }

        // ─── Livre visible → cacher icône, montrer message
        if (bookCurrentlyVisible)
        {
            placeholderIcon.gameObject.SetActive(false);

            if (!foundMessageShown)
            {
                foundMessageShown = true;
                ShowFoundMessage();
                StartCoroutine(TransitionToARScene());
            }
        }
        else
        {
            // ─── Livre hors champ → bouger l'icône sur le bord
            if (foundMessage != null && foundMessage.activeSelf)
            {
                foundMessage.SetActive(false);
                foundMessageShown = false;
                if (messageCoroutine != null)
                {
                    StopCoroutine(messageCoroutine);
                    messageCoroutine = null;
                }
            }

            if (directionCalculator == null)
            {
                Debug.LogError("DirectionCalculator NOT assigned !");
                return;
            }

            placeholderIcon.gameObject.SetActive(true);
            MoveIconToEdge(directionCalculator.ScreenDirection);
        }
    }
    private IEnumerator TransitionToARScene()
    {
        // Attendre que l'enfant voie le message "Livre Trouvé"
        yield return new WaitForSeconds(2f);

        Debug.Log("[BookFinder] 🚀 Transition vers ARDetection...");
        SceneManager.LoadScene("GymTesnime"); 
    }

    private void MoveIconToEdge(Vector2 direction)
    {
        if (direction.magnitude < 0.001f) return;

        float halfW = frameRect.rect.width * 0.5f;
        float halfH = frameRect.rect.height * 0.5f;

        // ✅ Angle cible — toujours calculé depuis la vraie direction (comme Code 2)
        float targetAngle = Mathf.Atan2(direction.y, direction.x) * Mathf.Rad2Deg;

        // ✅ Initialisation : première fois → on se téléporte directement à la bonne position
        // sans animation, pour éviter un départ bizarre depuis 90°
        if (!angleInitialized)
        {
            currentAngle = targetAngle;
            angleInitialized = true;
        }

        // ✅ Rotation progressive (longe le bord, jamais de traversée)
        currentAngle = Mathf.MoveTowardsAngle(
            currentAngle,
            targetAngle,
            iconRotationDegreesPerSecond * Time.deltaTime
        );

        // ✅ Direction depuis l'angle courant
        float rad = currentAngle * Mathf.Deg2Rad;
        Vector2 dir = new Vector2(Mathf.Cos(rad), Mathf.Sin(rad));

        // ✅ Projection sur le bord (même logique que Code 2 → position toujours correcte)
        float scaleX = (dir.x != 0) ? halfW / Mathf.Abs(dir.x) : float.MaxValue;
        float scaleY = (dir.y != 0) ? halfH / Mathf.Abs(dir.y) : float.MaxValue;
        float scale = Mathf.Min(scaleX, scaleY);

        placeholderIcon.anchoredPosition = dir * scale;
    }

    private void ShowFoundMessage()
    {
        if (foundMessage == null) return;

        foundMessage.SetActive(true);
        RectTransform msgRect = foundMessage.GetComponent<RectTransform>();
        msgRect.anchoredPosition = new Vector2(0, -120);
        msgRect.localScale = Vector3.one;

        if (foundMessageText != null)
            foundMessageText.text = "📖 Livre Trouvé !";

        if (messageCoroutine != null) StopCoroutine(messageCoroutine);
        messageCoroutine = StartCoroutine(AnimateFoundMessage());
    }

    private IEnumerator AnimateFoundMessage()
    {
        RectTransform msgRect = foundMessage.GetComponent<RectTransform>();
        msgRect.localScale = Vector3.zero;

        float elapsed = 0f;
        while (elapsed < 0.4f)
        {
            elapsed += Time.deltaTime;
            float t = Mathf.SmoothStep(0f, 1f, elapsed / 0.4f);
            msgRect.localScale = Vector3.one * Mathf.Lerp(0f, 1.3f, t);
            yield return null;
        }

        elapsed = 0f;
        while (elapsed < 0.25f)
        {
            elapsed += Time.deltaTime;
            msgRect.localScale = Vector3.one * Mathf.Lerp(1.3f, 0.9f, elapsed / 0.25f);
            yield return null;
        }

        elapsed = 0f;
        while (elapsed < 0.2f)
        {
            elapsed += Time.deltaTime;
            msgRect.localScale = Vector3.one * Mathf.Lerp(0.9f, 1f, elapsed / 0.2f);
            yield return null;
        }

        msgRect.localScale = Vector3.one;
        StartCoroutine(FloatEffect(msgRect));
    }

    private IEnumerator FloatEffect(RectTransform rect)
    {
        Vector2 startPos = rect.anchoredPosition;
        while (foundMessage != null && foundMessage.activeSelf)
        {
            float yOffset = Mathf.Sin(Time.time * 2f) * 10f;
            rect.anchoredPosition = startPos + new Vector2(0, yOffset);
            yield return null;
        }
    }
}


//2 
/*
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.Collections;
using TMPro;

public class FrameIndicatorController : MonoBehaviour
{
    [Header("References")]
    public DirectionCalculator directionCalculator;
    public ARTrackedImageManager trackedImageManager;

    [Header("UI - Cadre")]
    public RectTransform frameRect;
    public RectTransform placeholderIcon;

    [Header("UI - Message")]
    public GameObject foundMessage;
    public TextMeshProUGUI foundMessageText;

    [Header("Settings")]
    public float iconRotationDegreesPerSecond = 360f;

    // État
    private bool bookCurrentlyVisible = false;
    private bool foundMessageShown = false;
    private Coroutine messageCoroutine;
    private float currentAngle = 90f; // démarre en haut du cadre

    private void Awake()
    {
        if (placeholderIcon != null) placeholderIcon.gameObject.SetActive(false);
        if (foundMessage != null) foundMessage.SetActive(false);
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
        bool stillVisible = false;

        foreach (var img in trackedImageManager.trackables)
        {
            if (img.trackingState == TrackingState.Tracking)
            {
                stillVisible = true;
                break;
            }
        }

        bookCurrentlyVisible = stillVisible;
    }

    private void Update()
    {
        if (placeholderIcon == null || frameRect == null) return;

        // ─── Livre jamais détecté → cacher tout
        if (!BookPositionMemory.BookDetected)
        {
            placeholderIcon.gameObject.SetActive(false);
            if (foundMessage != null) foundMessage.SetActive(false);
            return;
        }

        // ─── Livre visible → cacher icône, montrer message
        if (bookCurrentlyVisible)
        {
            placeholderIcon.gameObject.SetActive(false);

            if (!foundMessageShown)
            {
                foundMessageShown = true;
                ShowFoundMessage();
            }
        }
        else
        {
            // ─── Livre hors champ → bouger l'icône sur le bord

            // Cacher le message si affiché
            if (foundMessage != null && foundMessage.activeSelf)
            {
                foundMessage.SetActive(false);
                foundMessageShown = false;
                if (messageCoroutine != null)
                {
                    StopCoroutine(messageCoroutine);
                    messageCoroutine = null;
                }
            }

            if (directionCalculator == null)
            {
                Debug.LogError("DirectionCalculator NOT assigned !");
                return;
            }

            placeholderIcon.gameObject.SetActive(true);
            MoveIconToEdge(directionCalculator.ScreenDirection);
        }
    }

    private void MoveIconToEdge(Vector2 direction)
    {
        if (direction.magnitude < 0.001f) return;

        float halfW = frameRect.rect.width * 0.5f;
        float halfH = frameRect.rect.height * 0.5f;

        // 1. Angle CIBLE depuis la direction du livre
        float targetAngle = Mathf.Atan2(direction.y, direction.x) * Mathf.Rad2Deg;

        // 2. Avancer vers l'angle cible en longeant le bord (chemin le plus court)
        currentAngle = Mathf.MoveTowardsAngle(
            currentAngle,
            targetAngle,
            iconRotationDegreesPerSecond * Time.deltaTime
        );

        // 3. Reconstruire la direction depuis l'angle courant
        float rad = currentAngle * Mathf.Deg2Rad;
        Vector2 dir = new Vector2(Mathf.Cos(rad), Mathf.Sin(rad));

        // 4. Projeter sur le bord du rectangle
        float scaleX = (dir.x != 0) ? halfW / Mathf.Abs(dir.x) : float.MaxValue;
        float scaleY = (dir.y != 0) ? halfH / Mathf.Abs(dir.y) : float.MaxValue;
        float scale = Mathf.Min(scaleX, scaleY);

        // 5. Placer l'icône sur le bord
        placeholderIcon.anchoredPosition = dir * scale;
    }

    private void ShowFoundMessage()
    {
        if (foundMessage == null) return;

        foundMessage.SetActive(true);
        RectTransform msgRect = foundMessage.GetComponent<RectTransform>();
        msgRect.anchoredPosition = new Vector2(0, -120);
        msgRect.localScale = Vector3.one;

        if (foundMessageText != null)
            foundMessageText.text = "📖 Livre Trouvé !";

        if (messageCoroutine != null) StopCoroutine(messageCoroutine);
        messageCoroutine = StartCoroutine(AnimateFoundMessage());
    }

    private IEnumerator AnimateFoundMessage()
    {
        RectTransform msgRect = foundMessage.GetComponent<RectTransform>();
        msgRect.localScale = Vector3.zero;

        float elapsed = 0f;
        while (elapsed < 0.4f)
        {
            elapsed += Time.deltaTime;
            float t = Mathf.SmoothStep(0f, 1f, elapsed / 0.4f);
            msgRect.localScale = Vector3.one * Mathf.Lerp(0f, 1.3f, t);
            yield return null;
        }

        elapsed = 0f;
        while (elapsed < 0.25f)
        {
            elapsed += Time.deltaTime;
            msgRect.localScale = Vector3.one * Mathf.Lerp(1.3f, 0.9f, elapsed / 0.25f);
            yield return null;
        }

        elapsed = 0f;
        while (elapsed < 0.2f)
        {
            elapsed += Time.deltaTime;
            msgRect.localScale = Vector3.one * Mathf.Lerp(0.9f, 1f, elapsed / 0.2f);
            yield return null;
        }

        msgRect.localScale = Vector3.one;
        StartCoroutine(FloatEffect(msgRect));
    }

    private IEnumerator FloatEffect(RectTransform rect)
    {
        Vector2 startPos = rect.anchoredPosition;
        while (foundMessage != null && foundMessage.activeSelf)
        {
            float yOffset = Mathf.Sin(Time.time * 2f) * 10f;
            rect.anchoredPosition = startPos + new Vector2(0, yOffset);
            yield return null;
        }
    }
}
 */


/*
 using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.Collections;
using TMPro;

public class FrameIndicatorController : MonoBehaviour
{
    [Header("References")]
    public DirectionCalculator directionCalculator;
    public ARTrackedImageManager trackedImageManager;

    [Header("UI - Cadre")]
    public RectTransform frameRect;
    public RectTransform placeholderIcon;

    [Header("UI - Message")]
    public GameObject foundMessage;
    public TextMeshProUGUI foundMessageText;

    [Header("Settings")]
    public float iconSmoothSpeed = 8f;

    // État
    private bool bookCurrentlyVisible = false;
    private bool foundMessageShown = false;
    private Coroutine messageCoroutine;

    private void Awake()
    {
        // Vérifications de sécurité
        if (placeholderIcon != null) placeholderIcon.gameObject.SetActive(false);
        if (foundMessage != null) foundMessage.SetActive(false);
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
        // ✅ FIX : On recalcule proprement l'état visible
        // D'abord, supposer qu'on ne voit plus le livre
        bool stillVisible = false;

        foreach (var img in trackedImageManager.trackables)
        {
            if (img.trackingState == TrackingState.Tracking)
            {
                stillVisible = true;
                break;
            }
        }

        bookCurrentlyVisible = stillVisible;
    }

    private void Update()
    {
        // ✅ Vérifier les refs avant tout
        if (placeholderIcon == null || frameRect == null) return;

        // ─── Livre jamais détecté → pas encore d'icône
        if (!BookPositionMemory.BookDetected)
        {
            placeholderIcon.gameObject.SetActive(false);
            if (foundMessage != null) foundMessage.SetActive(false);
            return;
        }

        // ─── Livre visible dans le champ → montrer message, cacher icône
        if (bookCurrentlyVisible)
        {
            placeholderIcon.gameObject.SetActive(false);

            if (!foundMessageShown)
            {
                foundMessageShown = true;
                ShowFoundMessage();
            }
        }
        else
        {
            // ─── Livre hors champ → bouger l'icône vers sa direction

            // Cacher le message si affiché
            if (foundMessage != null && foundMessage.activeSelf)
            {
                foundMessage.SetActive(false);
                foundMessageShown = false;
                if (messageCoroutine != null)
                {
                    StopCoroutine(messageCoroutine);
                    messageCoroutine = null;
                }
            }

            // ✅ FIX : Vérifier directionCalculator AVANT utilisation
            if (directionCalculator == null)
            {
                Debug.LogError("DirectionCalculator NOT assigned !");
                return;
            }

            placeholderIcon.gameObject.SetActive(true);
            MoveIconToEdge(directionCalculator.ScreenDirection);
        }
    }

    private void MoveIconToEdge(Vector2 direction)
    {
        // ✅ FIX : Si direction nulle (livre pile au centre), ne pas bouger
        if (direction.magnitude < 0.001f) return;

        float halfW = frameRect.rect.width * 0.5f;
        float halfH = frameRect.rect.height * 0.5f;

        Vector2 dir = direction.normalized;

        float scaleX = (dir.x != 0) ? halfW / Mathf.Abs(dir.x) : float.MaxValue;
        float scaleY = (dir.y != 0) ? halfH / Mathf.Abs(dir.y) : float.MaxValue;

        float scale = Mathf.Min(scaleX, scaleY);
        Vector2 targetPos = dir * scale;

        placeholderIcon.anchoredPosition = Vector2.Lerp(
            placeholderIcon.anchoredPosition,
            targetPos,
            Time.deltaTime * iconSmoothSpeed
        );
    }

    private void ShowFoundMessage()
    {
        if (foundMessage == null) return;

        foundMessage.SetActive(true);
        RectTransform msgRect = foundMessage.GetComponent<RectTransform>();
        msgRect.anchoredPosition = new Vector2(0, -120);
        msgRect.localScale = Vector3.one;

        if (foundMessageText != null)
            foundMessageText.text = "📖 Livre Trouvé !";

        if (messageCoroutine != null) StopCoroutine(messageCoroutine);
        messageCoroutine = StartCoroutine(AnimateFoundMessage());
    }

    private IEnumerator AnimateFoundMessage()
    {
        RectTransform msgRect = foundMessage.GetComponent<RectTransform>();
        msgRect.localScale = Vector3.zero;

        float elapsed = 0f;
        while (elapsed < 0.4f)
        {
            elapsed += Time.deltaTime;
            float t = Mathf.SmoothStep(0f, 1f, elapsed / 0.4f);
            msgRect.localScale = Vector3.one * Mathf.Lerp(0f, 1.3f, t);
            yield return null;
        }

        elapsed = 0f;
        while (elapsed < 0.25f)
        {
            elapsed += Time.deltaTime;
            msgRect.localScale = Vector3.one * Mathf.Lerp(1.3f, 0.9f, elapsed / 0.25f);
            yield return null;
        }

        elapsed = 0f;
        while (elapsed < 0.2f)
        {
            elapsed += Time.deltaTime;
            msgRect.localScale = Vector3.one * Mathf.Lerp(0.9f, 1f, elapsed / 0.2f);
            yield return null;
        }

        msgRect.localScale = Vector3.one;
        StartCoroutine(FloatEffect(msgRect));
    }

    private IEnumerator FloatEffect(RectTransform rect)
    {
        Vector2 startPos = rect.anchoredPosition;
        while (foundMessage != null && foundMessage.activeSelf)
        {
            float yOffset = Mathf.Sin(Time.time * 2f) * 10f;
            rect.anchoredPosition = startPos + new Vector2(0, yOffset);
            yield return null;
        }
    }
}
 */