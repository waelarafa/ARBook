using UnityEngine;
using UnityEngine.UI;

public class ColorButton : MonoBehaviour
{
    public Color color;

    void Start()
    {
        GetComponent<Image>().color = color;

        // ajouter Outline pour indiquer sélection
        Outline outline = gameObject.AddComponent<Outline>();
        outline.effectColor = Color.black;
        outline.effectDistance = new Vector2(3, 3);
        outline.enabled = false;
    }

    public void OnClick()
    {
        ColoringManager.Instance.SelectColor(color, this);
    }
}