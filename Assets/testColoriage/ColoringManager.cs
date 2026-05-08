using UnityEngine;
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
}