using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.EnhancedTouch;
using UnityEngine.XR.ARFoundation;
using System.Collections.Generic;

using Touch = UnityEngine.InputSystem.EnhancedTouch.Touch;

[RequireComponent(typeof(AnimalDetector))]
public class TapOnAnimal : MonoBehaviour
{
    private AnimalDetector detector;
    private ARCameraManager arCameraManager;

    private Text messageUI;
    private GameObject bgObj;

    private float messageTimer = 0f;
    private float messageDuration = 2f;

    void OnEnable()
    {
        EnhancedTouchSupport.Enable();
        TouchSimulation.Enable();
    }

    void OnDisable()
    {
        EnhancedTouchSupport.Disable();
        TouchSimulation.Disable();
    }

    void Start()
    {
        detector = GetComponent<AnimalDetector>();
        arCameraManager = FindObjectOfType<ARCameraManager>();
        CreerMessageUI();
    }

    void Update()
    {
        bool tapped = false;
        Vector2 tapPosition = Vector2.zero;

        // MOBILE
        foreach (Touch touch in Touch.activeTouches)
        {
            if (touch.phase == UnityEngine.InputSystem.TouchPhase.Began)
            {
                tapped = true;
                tapPosition = touch.screenPosition;
            }
        }

        // EDITEUR
        var mouse = Mouse.current;
        if (mouse != null && mouse.leftButton.wasPressedThisFrame)
        {
            tapped = true;
            tapPosition = mouse.position.ReadValue();
        }

        if (tapped)
        {
            Debug.Log("Tap détecté !");
            VerifierTapSurAnimal(tapPosition);
        }

        // timer message
        if (messageUI != null && messageUI.gameObject.activeSelf)
        {
            messageTimer -= Time.deltaTime;

            if (messageTimer <= 0f)
            {
                messageUI.gameObject.SetActive(false);
                if (bgObj != null)
                    bgObj.SetActive(false);
            }
        }
    }

    void VerifierTapSurAnimal(Vector2 screenPos)
    {
        Camera arCam = arCameraManager != null
            ? arCameraManager.GetComponent<Camera>()
            : Camera.main;

        if (arCam == null)
        {
            Debug.LogWarning("Camera AR introuvable");
            return;
        }

        string animalTouche = null;
        float meilleureDistance = float.MaxValue;

        foreach (var kvp in detector.imagesDetectees)
        {
            string nom = kvp.Key;
            var imageAR = kvp.Value;

            // ← IGNORER LA FEUILLE automatiquement depuis le JSON
            if (detector.EstUneFeuille(nom)) continue;

            if (imageAR == null)
                continue;

            Vector3 screenImage =
                arCam.WorldToScreenPoint(imageAR.transform.position);

            float distance =
                Vector2.Distance(screenPos,
                new Vector2(screenImage.x, screenImage.y));

            Debug.Log($"distance tap {nom} : {distance}");

            if (distance < 120f && distance < meilleureDistance)
            {
                meilleureDistance = distance;
                animalTouche = nom;
            }
        }

        if (animalTouche != null)
        {
            Debug.Log("Animal touché : " + animalTouche);
            AfficherMessage("tu tappe\n" + animalTouche.ToUpper());
        }
        else
        {
            Debug.Log("tap dans le vide");
        }
    }

    void AfficherMessage(string msg)
    {
        messageUI.text = msg;
        messageUI.gameObject.SetActive(true);
        if (bgObj != null)
            bgObj.SetActive(true);
        messageTimer = messageDuration;
    }

    void CreerMessageUI()
    {
        GameObject canvasObj = GameObject.Find("Canvas");

        if (canvasObj == null)
        {
            canvasObj = new GameObject("Canvas");
            Canvas c = canvasObj.AddComponent<Canvas>();
            c.renderMode = RenderMode.ScreenSpaceOverlay;
            canvasObj.AddComponent<CanvasScaler>();
            canvasObj.AddComponent<GraphicRaycaster>();
        }

        bgObj = new GameObject("TapBG");
        bgObj.transform.SetParent(canvasObj.transform, false);
        Image bg = bgObj.AddComponent<Image>();
        bg.color = new Color(0f, 0f, 0f, 0.6f);
        RectTransform bgRt = bgObj.GetComponent<RectTransform>();
        bgRt.anchorMin = new Vector2(0.5f, 0.5f);
        bgRt.anchorMax = new Vector2(0.5f, 0.5f);
        bgRt.pivot = new Vector2(0.5f, 0.5f);
        bgRt.anchoredPosition = Vector2.zero;
        bgRt.sizeDelta = new Vector2(500, 200);

        GameObject textObj = new GameObject("TapMessage");
        textObj.transform.SetParent(bgObj.transform, false);
        messageUI = textObj.AddComponent<Text>();
        messageUI.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        messageUI.fontSize = 52;
        messageUI.fontStyle = FontStyle.Bold;
        messageUI.color = Color.yellow;
        messageUI.alignment = TextAnchor.MiddleCenter;

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.5f, 0.5f);
        rt.anchorMax = new Vector2(0.5f, 0.5f);
        rt.pivot = new Vector2(0.5f, 0.5f);
        rt.anchoredPosition = Vector2.zero;
        rt.sizeDelta = new Vector2(500, 200);

        messageUI.gameObject.SetActive(false);
        bgObj.SetActive(false);

        Debug.Log("UI Tap créée");
    }
}
/*using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.EnhancedTouch;
using UnityEngine.XR.ARFoundation;
using System.Collections.Generic;

using Touch = UnityEngine.InputSystem.EnhancedTouch.Touch;

[RequireComponent(typeof(AnimalDetector))]
public class TapOnAnimal : MonoBehaviour
{
    private AnimalDetector detector;
    private ARCameraManager arCameraManager;

    private Text messageUI;
    private GameObject bgObj;

    private float messageTimer = 0f;
    private float messageDuration = 2f;

    void OnEnable()
    {
        EnhancedTouchSupport.Enable();
        TouchSimulation.Enable();
    }

    void OnDisable()
    {
        EnhancedTouchSupport.Disable();
        TouchSimulation.Disable();
    }

    void Start()
    {
        detector = GetComponent<AnimalDetector>();
        arCameraManager = FindObjectOfType<ARCameraManager>();

        CreerMessageUI();
    }

    void Update()
    {
        bool tapped = false;
        Vector2 tapPosition = Vector2.zero;

        // MOBILE
        foreach (Touch touch in Touch.activeTouches)
        {
            if (touch.phase == UnityEngine.InputSystem.TouchPhase.Began)
            {
                tapped = true;
                tapPosition = touch.screenPosition;
            }
        }

        // EDITEUR
        var mouse = Mouse.current;
        if (mouse != null && mouse.leftButton.wasPressedThisFrame)
        {
            tapped = true;
            tapPosition = mouse.position.ReadValue();
        }

        if (tapped)
        {
            Debug.Log("Tap détecté !");
            VerifierTapSurAnimal(tapPosition);
        }

        // timer message
        if (messageUI != null && messageUI.gameObject.activeSelf)
        {
            messageTimer -= Time.deltaTime;

            if (messageTimer <= 0f)
            {
                messageUI.gameObject.SetActive(false);

                if (bgObj != null)
                    bgObj.SetActive(false);
            }
        }
    }

    void VerifierTapSurAnimal(Vector2 screenPos)
    {
        Camera arCam = arCameraManager != null
            ? arCameraManager.GetComponent<Camera>()
            : Camera.main;

        if (arCam == null)
        {
            Debug.LogWarning("Camera AR introuvable");
            return;
        }

        string animalTouche = null;
        float meilleureDistance = float.MaxValue;

        foreach (var kvp in detector.imagesDetectees)
        {
            string nom = kvp.Key;
            var imageAR = kvp.Value;

            if (imageAR == null)
                continue;

            // position de l'image sur l'écran
            Vector3 screenImage =
                arCam.WorldToScreenPoint(imageAR.transform.position);

            float distance =
                Vector2.Distance(screenPos,
                new Vector2(screenImage.x, screenImage.y));

            Debug.Log($"distance tap {nom} : {distance}");

            if (distance < 120f && distance < meilleureDistance)
            {
                meilleureDistance = distance;
                animalTouche = nom;
            }
        }

        if (animalTouche != null)
        {
            Debug.Log("Animal touché : " + animalTouche);
            AfficherMessage("tu tappe\n" + animalTouche.ToUpper());
        }
        else
        {
            Debug.Log("tap dans le vide");
        }
    }

    void AfficherMessage(string msg)
    {
        messageUI.text = msg;

        messageUI.gameObject.SetActive(true);

        if (bgObj != null)
            bgObj.SetActive(true);

        messageTimer = messageDuration;
    }

    void CreerMessageUI()
    {
        GameObject canvasObj = GameObject.Find("Canvas");

        if (canvasObj == null)
        {
            canvasObj = new GameObject("Canvas");

            Canvas c = canvasObj.AddComponent<Canvas>();
            c.renderMode = RenderMode.ScreenSpaceOverlay;

            canvasObj.AddComponent<CanvasScaler>();
            canvasObj.AddComponent<GraphicRaycaster>();
        }

        // fond
        bgObj = new GameObject("TapBG");
        bgObj.transform.SetParent(canvasObj.transform, false);

        Image bg = bgObj.AddComponent<Image>();
        bg.color = new Color(0f, 0f, 0f, 0.6f);

        RectTransform bgRt = bgObj.GetComponent<RectTransform>();
        bgRt.anchorMin = new Vector2(0.5f, 0.5f);
        bgRt.anchorMax = new Vector2(0.5f, 0.5f);
        bgRt.pivot = new Vector2(0.5f, 0.5f);
        bgRt.anchoredPosition = Vector2.zero;
        bgRt.sizeDelta = new Vector2(500, 200);

        // texte
        GameObject textObj = new GameObject("TapMessage");
        textObj.transform.SetParent(bgObj.transform, false);

        messageUI = textObj.AddComponent<Text>();
        messageUI.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        messageUI.fontSize = 52;
        messageUI.fontStyle = FontStyle.Bold;
        messageUI.color = Color.yellow;
        messageUI.alignment = TextAnchor.MiddleCenter;

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.5f, 0.5f);
        rt.anchorMax = new Vector2(0.5f, 0.5f);
        rt.pivot = new Vector2(0.5f, 0.5f);
        rt.anchoredPosition = Vector2.zero;
        rt.sizeDelta = new Vector2(500, 200);

        messageUI.gameObject.SetActive(false);
        bgObj.SetActive(false);

        Debug.Log("UI Tap créée");
    }
}/*using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem.EnhancedTouch;
using UnityEngine.InputSystem;
using TMPro;
using Touch = UnityEngine.InputSystem.EnhancedTouch.Touch;

public class TapDetector : MonoBehaviour
{
    private TextMeshProUGUI message;
    private float messageTimer = 0f;
    private float messageDuration = 2f;
    private int tapCount = 0;
    private GameObject _bg;

    void OnEnable()
    {
        EnhancedTouchSupport.Enable();
        TouchSimulation.Enable();
    }

    void OnDisable()
    {
        EnhancedTouchSupport.Disable();
        TouchSimulation.Disable();
    }

    void Start()
    {
        // ---------- CANVAS ----------
        GameObject canvasGO = new GameObject("TapCanvas");
        Canvas canvas = canvasGO.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder = 9999;

        CanvasScaler scaler = canvasGO.AddComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1080, 1920);
        scaler.matchWidthOrHeight = 0.5f;

        canvasGO.AddComponent<GraphicRaycaster>();

        // ---------- FOND ----------
        GameObject bgGO = new GameObject("Background");
        bgGO.transform.SetParent(canvasGO.transform, false);
        Image bg = bgGO.AddComponent<Image>();
        bg.color = new Color(0f, 0f, 0f, 0.6f);
        RectTransform bgRt = bgGO.GetComponent<RectTransform>();
        bgRt.anchorMin = new Vector2(0.5f, 0.5f);
        bgRt.anchorMax = new Vector2(0.5f, 0.5f);
        bgRt.pivot = new Vector2(0.5f, 0.5f);
        bgRt.anchoredPosition = Vector2.zero;
        bgRt.sizeDelta = new Vector2(700, 180);
        bgGO.SetActive(false);
        _bg = bgGO;

        // ---------- TEXT ----------
        GameObject textGO = new GameObject("TapMessage");
        textGO.transform.SetParent(canvasGO.transform, false);
        message = textGO.AddComponent<TextMeshProUGUI>();
        message.fontSize = 72;
        message.fontStyle = FontStyles.Bold;
        message.color = Color.yellow;
        message.alignment = TextAlignmentOptions.Center;
        message.raycastTarget = false;

        RectTransform rt = textGO.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.5f, 0.5f);
        rt.anchorMax = new Vector2(0.5f, 0.5f);
        rt.pivot = new Vector2(0.5f, 0.5f);
        rt.anchoredPosition = Vector2.zero;
        rt.sizeDelta = new Vector2(700, 180);

        message.gameObject.SetActive(false);

        Debug.Log("[TapDetector] Start() OK");
    }

    void Update()
    {
        bool tapped = false;

        // MOBILE : EnhancedTouch
        foreach (Touch touch in Touch.activeTouches)
        {
            if (touch.phase == UnityEngine.InputSystem.TouchPhase.Began)
                tapped = true;
        }

        // EDITEUR : souris via nouveau Input System (remplace Input.GetMouseButtonDown)
        var mouse = Mouse.current;
        if (mouse != null && mouse.leftButton.wasPressedThisFrame)
            tapped = true;

        if (tapped)
            ShowMessage();

        // Timer hide
        if (message != null && message.gameObject.activeSelf)
        {
            messageTimer -= Time.deltaTime;
            if (messageTimer <= 0f)
            {
                message.gameObject.SetActive(false);
                if (_bg != null) _bg.SetActive(false);
            }
        }
    }

    void ShowMessage()
    {
        tapCount++;
        message.text = $"tu tappe ({tapCount})";
        message.gameObject.SetActive(true);
        if (_bg != null) _bg.SetActive(true);
        messageTimer = messageDuration;
        Debug.Log($"[TapDetector] tap #{tapCount}");
    }
}
/*using UnityEngine;
using UnityEngine.UI;

public class TapTest : MonoBehaviour
{
    private Canvas canvas;

    void Start()
    {
        // Crée un Canvas si aucun n'existe
        GameObject canvasObj = GameObject.Find("Canvas");
        if (canvasObj == null)
        {
            canvasObj = new GameObject("Canvas");
            canvas = canvasObj.AddComponent<Canvas>();
            canvas.renderMode = RenderMode.ScreenSpaceOverlay;
            canvasObj.AddComponent<CanvasScaler>();
            canvasObj.AddComponent<GraphicRaycaster>();
        }
        else
        {
            canvas = canvasObj.GetComponent<Canvas>();
        }
    }

    void Update()
    {
        if (Input.touchCount == 0) return;

        Touch touch = Input.GetTouch(0);
        if (touch.phase == TouchPhase.Began)
        {
            AfficherMessageTap();
        }
    }

    void AfficherMessageTap()
    {
        // Crée un Text temporaire
        GameObject textObj = new GameObject("MessageTap");
        textObj.transform.SetParent(canvas.transform, false);

        Text t = textObj.AddComponent<Text>();
        t.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        t.fontSize = 36;
        t.color = Color.yellow;
        t.alignment = TextAnchor.MiddleCenter;
        t.text = "Tu tapes !";

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.3f, 0.4f);
        rt.anchorMax = new Vector2(0.7f, 0.6f);
        rt.pivot = new Vector2(0.5f, 0.5f);
        rt.anchoredPosition = Vector2.zero;

        // Supprime le message après 1.5 secondes
        Destroy(textObj, 1.5f);
    }
}
/*using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

public class AnimalInteraction : MonoBehaviour
{
    private AnimalDetector detector;           // Référence au détecteur
    private ARRaycastManager raycastManager;   // Pour détecter les images AR

    void Start()
    {
        detector = GetComponent<AnimalDetector>();
        if (detector == null)
            Debug.LogError("AnimalDetector non trouvé sur cet objet !");

        raycastManager = GetComponent<ARRaycastManager>();
        if (raycastManager == null)
            Debug.LogError("ARRaycastManager non trouvé !");
    }

    void Update()
    {
        if (detector == null || raycastManager == null) return;
        if (Input.touchCount == 0) return;

        Touch touch = Input.GetTouch(0);
        if (touch.phase != TouchPhase.Began) return;

        DetecterAnimalTouch(touch.position);
    }

    void DetecterAnimalTouch(Vector2 touchPosition)
    {
        List<ARRaycastHit> hits = new List<ARRaycastHit>();

        if (raycastManager.Raycast(touchPosition, hits, TrackableType.Image))
        {
            foreach (ARRaycastHit hit in hits)
            {
                ARTrackedImage img = hit.trackable as ARTrackedImage;
                if (img == null) continue;

                string nomAnimal = img.referenceImage.name.Replace("_img", "");
                if (detector.AnimauxValides.Contains(nomAnimal))
                {
                    AfficherTexteAnimal(nomAnimal);
                    break;
                }
            }
        }
    }

    void AfficherTexteAnimal(string nomAnimal)
    {
        GameObject canvasObj = GameObject.Find("Canvas");
        if (canvasObj == null) return;

        GameObject textObj = new GameObject("TexteAnimal");
        textObj.transform.SetParent(canvasObj.transform, false);

        Text t = textObj.AddComponent<Text>();
        t.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        t.fontSize = 36;
        t.color = Color.cyan;
        t.alignment = TextAnchor.MiddleCenter;

        t.text = nomAnimal switch
        {
            "fox_img" => "Hello, I'm the fox!",
            "squirrel_img" => "Hello, I'm the squirrel!",
            _ => "Hello, I'm an animal!"
        };

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.2f, 0.4f);
        rt.anchorMax = new Vector2(0.8f, 0.6f);
        rt.pivot = new Vector2(0.5f, 0.5f);
        rt.anchoredPosition = Vector2.zero;

        Destroy(textObj, 2f);
    }
}*/