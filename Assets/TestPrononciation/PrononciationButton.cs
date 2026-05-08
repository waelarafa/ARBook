using UnityEngine;

public class PronunciationButton : MonoBehaviour
{
    [Header("Pages à afficher")]
    public string[] pageNames; // ex: ["Animaux", "Fruits"]

    public void OnClick()
    {
        PronunciationManager.Instance.OpenWithPages(pageNames);
    }
}