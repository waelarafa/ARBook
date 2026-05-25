using UnityEngine;

public class QuizButton : MonoBehaviour
{
    public QuizData quiz;

    [Header("Paramètres Analytics")]
    public string bookId  = "";
    public string themeId = "";

    public void OnClick()
    {
        AnalyticsManager.Instance?.LogActivityEntered(bookId, themeId, "quiz");
        QuizManager.Instance.StartQuiz(quiz);
    }
}