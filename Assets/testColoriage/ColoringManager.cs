using UnityEngine;
using UnityEngine.UI;

public class ColoringManager : MonoBehaviour
{
    public static ColoringManager Instance { get; private set; }

    [Header("UI")]
    public GameObject coloringCanvas;

    [Header("Analytics")]
    public string bookId  = "";
    public string themeId = "";

    private Color selectedColor = Color.red;
    private ColorButton lastSelected;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        coloringCanvas.SetActive(false);
    }

    public void OpenGame()
    {AnalyticsManager.Instance?.LogActivityEntered(bookId, themeId, "coloring");
        coloringCanvas.SetActive(true);
    }

    public void CloseGame()
    {
        // 1. Enregistrer la session
        AnalyticsManager.Instance?.LogActivityExited();

        // 2. Annoncer la terminaison à ActivityMapManager
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