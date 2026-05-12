using UnityEngine;

[System.Serializable]
public class QuestionData
{
    [TextArea] public string questionText;
    public string[] choices; // ✅ plus de limite à 4
    public int correctIndex;
}

[CreateAssetMenu(fileName = "Quiz", menuName = "Quiz/Quiz")]
public class QuizData : ScriptableObject
{
    public string quizName;
    public QuestionData[] questions;
}