using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ColoringManager : MonoBehaviour
{
    public static ColoringManager Instance { get; private set; }

    [Header("UI")]
    public GameObject coloringCanvas;
    public Image targetImage;
    public GameObject completionPanel; // ← glisse ton panel ici

    [System.Serializable]
    public class ThemeColoringConfig
    {
        public string themeId;
        public Sprite coloringSprite;
    }

    [Header("Config par thème")]
    public List<ThemeColoringConfig> themeConfigs = new List<ThemeColoringConfig>();

    private string bookId  => SessionManager.Instance.CurrentBookId;
    private string themeId => SessionManager.Instance.CurrentThemeId;

    private Color selectedColor = Color.red;
    private ColorButton lastSelected;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        coloringCanvas.SetActive(false);
        if (completionPanel != null) completionPanel.SetActive(false);
    }

    public void OpenGame()
    {
        string tId = themeId;

        ThemeColoringConfig config = themeConfigs.Find(c => c.themeId == tId);

        if (config != null && config.coloringSprite != null)
        {
            FloodFill floodFill = targetImage.GetComponent<FloodFill>();
            if (floodFill != null)
            {
                floodFill.SetSprite(config.coloringSprite);
                floodFill.Reset();
            }
        }
        else
        {
            Debug.LogWarning($"[ColoringManager] Pas de config pour '{tId}'");
        }

        AnalyticsManager.Instance?.LogActivityEntered(bookId, tId, "coloring");
        coloringCanvas.SetActive(true);
    }

    public void CloseGame()
    {
        AnalyticsManager.Instance?.LogActivityExited();

        ActivityMapManager[] managers = FindObjectsByType<ActivityMapManager>(FindObjectsSortMode.None);
        foreach (var manager in managers)
        {
            if (manager.themeId == themeId)
            {
                manager.OnActivityCompleted("coloring");
                break;
            }
        }

        coloringCanvas.SetActive(false);

        if (completionPanel != null)
            completionPanel.SetActive(true); // ← affiche le panel
    }

    public void CloseCompletionPanel()
    {
        if (completionPanel != null)
            completionPanel.SetActive(false);
    }

    public Color GetSelectedColor() => selectedColor;

    public void SelectColor(Color color, ColorButton btn)
    {
        selectedColor = color;

        if (lastSelected != null)
            lastSelected.GetComponent<Outline>().enabled = false;

        btn.GetComponent<Outline>().enabled = true;
        lastSelected = btn;
    }
}
/*using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ColoringManager : MonoBehaviour
{
    public static ColoringManager Instance { get; private set; }

    [Header("UI")]
    public GameObject coloringCanvas;
    public Image targetImage;

    [System.Serializable]
    public class ThemeColoringConfig
    {
        public string themeId;
        public Sprite coloringSprite;
    }

    [Header("Config par thème")]
    public List<ThemeColoringConfig> themeConfigs = new List<ThemeColoringConfig>();

    private string bookId  => SessionManager.Instance.CurrentBookId;
    private string themeId => SessionManager.Instance.CurrentThemeId;

    private Color selectedColor = Color.red;
    private ColorButton lastSelected;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        coloringCanvas.SetActive(false);
    }

    public void OpenGame()
{
    string tId = themeId;

    ThemeColoringConfig config = themeConfigs.Find(c => c.themeId == tId);

    if (config != null && config.coloringSprite != null)
    {
        FloodFill floodFill = targetImage.GetComponent<FloodFill>();
        if (floodFill != null)
        {
            floodFill.SetSprite(config.coloringSprite); // ← change le sprite
            floodFill.Reset();                           // ← reset les colorations
        }
    }
    else
    {
        Debug.LogWarning($"[ColoringManager] Pas de config pour '{tId}'");
    }

    AnalyticsManager.Instance?.LogActivityEntered(bookId, tId, "coloring");
    coloringCanvas.SetActive(true);
}

    public void CloseGame()
    {
        AnalyticsManager.Instance?.LogActivityExited();

        ActivityMapManager[] managers = FindObjectsByType<ActivityMapManager>(FindObjectsSortMode.None);
        foreach (var manager in managers)
        {
            if (manager.themeId == themeId)
            {
                manager.OnActivityCompleted("coloring");
                break;
            }
        }

        coloringCanvas.SetActive(false);
    }

    public Color GetSelectedColor() => selectedColor;

    public void SelectColor(Color color, ColorButton btn)
    {
        selectedColor = color;

        if (lastSelected != null)
            lastSelected.GetComponent<Outline>().enabled = false;

        btn.GetComponent<Outline>().enabled = true;
        lastSelected = btn;
    }
}
/*using UnityEngine;
using UnityEngine.UI;

public class ColoringManager : MonoBehaviour
{
    public static ColoringManager Instance { get; private set; }

    [Header("UI")]
    public GameObject coloringCanvas;

    private string bookId  => SessionManager.Instance.CurrentBookId;
    private string themeId => SessionManager.Instance.CurrentThemeId;

    private Color selectedColor = Color.red;
    private ColorButton lastSelected;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        coloringCanvas.SetActive(false);
    }

    public void OpenGame()
    {
        AnalyticsManager.Instance?.LogActivityEntered(bookId, themeId, "coloring");
        coloringCanvas.SetActive(true);
    }

    public void CloseGame()
    {
        AnalyticsManager.Instance?.LogActivityExited();

        ActivityMapManager[] managers = FindObjectsByType<ActivityMapManager>(FindObjectsSortMode.None);
        foreach (var manager in managers)
        {
            if (manager.themeId == themeId)
            {
                manager.OnActivityCompleted("coloring");
                break;
            }
        }

        coloringCanvas.SetActive(false);
    }

    public Color GetSelectedColor() => selectedColor;

    public void SelectColor(Color color, ColorButton btn)
    {
        selectedColor = color;

        if (lastSelected != null)
            lastSelected.GetComponent<Outline>().enabled = false;

        btn.GetComponent<Outline>().enabled = true;
        lastSelected = btn;
    }
}
/*
/*using UnityEngine;
using UnityEngine.UI;

public class ColoringManager : MonoBehaviour
{
    public static ColoringManager Instance { get; private set; }

    [Header("UI")]
    public GameObject coloringCanvas;

    private Color selectedColor = Color.red;
    private ColorButton lastSelected;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        coloringCanvas.SetActive(false);
    }

    public void OpenGame()
    {
        coloringCanvas.SetActive(true);
    }

    public void CloseGame()
    {
        AnalyticsManager.Instance?.LogActivityExited();
        coloringCanvas.SetActive(false);
    }

    public Color GetSelectedColor() => selectedColor;

    public void SelectColor(Color color, ColorButton btn)
    {
        selectedColor = color;

        // contour sur le bouton sélectionné
        if (lastSelected != null)
            lastSelected.GetComponent<Outline>().enabled = false;

        btn.GetComponent<Outline>().enabled = true;
        lastSelected = btn;
    }
}*/