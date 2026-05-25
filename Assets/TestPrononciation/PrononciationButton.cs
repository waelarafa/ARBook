using UnityEngine;

public class PronunciationButton : MonoBehaviour
{
    [Header("Paramètres")]
    public string bookId  = "";
    public string themeId = "";   // ex: "Les Animaux"

    public void OnClick()
    {
        AnalyticsManager.Instance?.LogActivityEntered(bookId, themeId, "prononciation");
        PronunciationManager.Instance.OpenWithTheme(bookId, themeId);
    }
}