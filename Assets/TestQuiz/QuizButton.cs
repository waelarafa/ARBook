// QuizButton.cs
using UnityEngine;

public class QuizButton : MonoBehaviour
{
    public QuizData quiz; // glisse Quiz1.asset ici dans l'Inspector

    public void OnClick()
    {
        QuizManager.Instance.StartQuiz(quiz);
    }
}