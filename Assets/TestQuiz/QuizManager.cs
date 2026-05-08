using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class QuizManager : MonoBehaviour
{
    public static QuizManager Instance { get; private set; }

    [Header("UI")]
    public GameObject quizCanvas;
    public TMP_Text questionText;
    public Button[] answerButtons;
    public TMP_Text scoreText;
    public GameObject feedbackCorrect;
    public GameObject feedbackWrong;

    private QuestionData[] questions;
    private int _currentIndex = 0;
    private int _score = 0;

    void Awake()
    {
        Instance = this;
        quizCanvas.SetActive(false);
    }

    public void StartQuiz(QuizData quiz)
    {
        questions = quiz.questions;
        _currentIndex = 0;
        _score = 0;
        quizCanvas.SetActive(true);
        ShowQuestion();
    }

    public void CloseQuiz()
    {
        quizCanvas.SetActive(false);
    }

    void ShowQuestion()
    {
        feedbackCorrect.SetActive(false);
        feedbackWrong.SetActive(false);

        if (_currentIndex >= questions.Length)
        {
            EndQuiz();
            return;
        }

        QuestionData q = questions[_currentIndex];
        questionText.text = q.questionText;

        // ✅ adapte les boutons selon le nombre de choices
        for (int i = 0; i < answerButtons.Length; i++)
        {
            if (i < q.choices.Length)
            {
                answerButtons[i].gameObject.SetActive(true);
                int capturedIndex = i;
                answerButtons[i].GetComponentInChildren<TMP_Text>().text = q.choices[i];
                answerButtons[i].onClick.RemoveAllListeners();
                answerButtons[i].onClick.AddListener(() => OnAnswer(capturedIndex));
            }
            else
            {
                answerButtons[i].gameObject.SetActive(false);
            }
        }

        scoreText.text = $"Score : {_score}";
    }

    void OnAnswer(int chosen)
    {
        bool correct = chosen == questions[_currentIndex].correctIndex;

        if (correct)
        {
            _score++;
            feedbackCorrect.SetActive(true);
        }
        else
        {
            feedbackWrong.SetActive(true);
        }

        _currentIndex++;
        Invoke(nameof(ShowQuestion), 1.5f);
    }

    void EndQuiz()
    {
        questionText.text = $"Terminé ! Score : {_score} / {questions.Length}";
        foreach (var btn in answerButtons)
            btn.gameObject.SetActive(false);
    }
}