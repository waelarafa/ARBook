using UnityEngine;

public class QuizButton : MonoBehaviour
{
    public ActivityMapManager activityMapManager;
    public QuizData quiz;

    public void OnClick()
    {
        activityMapManager.OpenActivity("quiz", quiz);
    }
}
/*using UnityEngine;

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
}*/