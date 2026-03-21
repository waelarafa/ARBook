using System.Collections;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

public class TestLocalLibrary : MonoBehaviour
{
    private ARTrackedImageManager trackedImageManager;

    [SerializeField]
    private XRReferenceImageLibrary localLibrary; // ← assigne LocalTestLibrary ici

    private Text logText;
    private string logs = "";

    void Awake()
    {
        CreerUI();
        trackedImageManager = GetComponent<ARTrackedImageManager>();
        Log("🚀 Démarrage !");
    }

    void Start()
    {
        Log("📚 Count XRLibrary : " + localLibrary.count);

        for (int i = 0; i < localLibrary.count; i++)
            Log("🖼️ Image " + i + " : " + localLibrary[i].name);

        // Créer runtime library depuis la library locale
        var runtimeLibrary = trackedImageManager
            .CreateRuntimeLibrary(localLibrary);

        trackedImageManager.referenceLibrary = runtimeLibrary;

        Log("✅ Library assignée !");
        Log("📚 Count runtime : " + runtimeLibrary.count);
        Log("👉 Pointe la caméra sur fox !");
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
        foreach (ARTrackedImage image in args.added)
            Log("🎉 DÉTECTÉ : " + image.referenceImage.name);

        foreach (ARTrackedImage image in args.updated)
            if (image.trackingState == TrackingState.Tracking)
                Log("📷 Tracking : " + image.referenceImage.name);
    }

    void Update()
    {
        if (Time.frameCount % 300 == 0)
            Log("💓 count: " + trackedImageManager.referenceLibrary.count);
    }

    void Log(string msg)
    {
        Debug.Log(msg);
        logs = msg + "\n" + logs;
        string[] lignes = logs.Split('\n');
        if (lignes.Length > 15)
            logs = string.Join("\n", lignes, 0, 15);
        if (logText != null)
            logText.text = logs;
    }

    void CreerUI()
    {
        GameObject c = new GameObject("Canvas");
        Canvas canvas = c.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder = 999;
        c.AddComponent<CanvasScaler>();
        c.AddComponent<GraphicRaycaster>();

        GameObject fond = new GameObject("Fond");
        fond.transform.SetParent(c.transform, false);
        Image img = fond.AddComponent<Image>();
        img.color = new Color(0, 0, 0, 0.7f);
        RectTransform r = fond.GetComponent<RectTransform>();
        r.anchorMin = new Vector2(0, 0.5f);
        r.anchorMax = new Vector2(1, 1);
        r.sizeDelta = Vector2.zero;

        GameObject t = new GameObject("LogText");
        t.transform.SetParent(fond.transform, false);
        logText = t.AddComponent<Text>();
        logText.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        logText.fontSize = 30;
        logText.color = Color.white;
        logText.alignment = TextAnchor.UpperLeft;
        RectTransform rt = t.GetComponent<RectTransform>();
        rt.anchorMin = Vector2.zero;
        rt.anchorMax = Vector2.one;
        rt.offsetMin = new Vector2(10, 10);
        rt.offsetMax = new Vector2(-10, -10);
    }
}