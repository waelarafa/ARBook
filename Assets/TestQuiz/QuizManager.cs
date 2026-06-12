using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;

public class QuizManager : MonoBehaviour
{
    public static QuizManager Instance { get; private set; }

    [Header("UI")]
    public GameObject quizCanvas;
    public TMP_Text questionText;
    public Button[] answerButtons;

    [Header("Analytics")]
    public string bookId  = "";
    public string themeId = "";

    [Header("Animation")]
    public float scaleUp = 1.15f;  // taille agrandie
    public float scaleSpeed = 8f;  // vitesse animation

    private QuestionData[] questions;
    private int _currentIndex = 0;
    private int _score = 0;
    private Vector3[] _originalScales;

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

        // Sauvegarder les tailles originales des boutons
        _originalScales = new Vector3[answerButtons.Length];
        for (int i = 0; i < answerButtons.Length; i++)
            _originalScales[i] = answerButtons[i].transform.localScale;

        quizCanvas.SetActive(true);
        ShowQuestion();
    }

    public void CloseQuiz()
    {
        //AnalyticsManager.Instance?.LogActivityExited();
        quizCanvas.SetActive(false);
    }

    void ShowQuestion()
    {
        // Réinitialiser tous les boutons
        for (int i = 0; i < answerButtons.Length; i++)
        {
            answerButtons[i].gameObject.SetActive(false);
            answerButtons[i].interactable = true;
            answerButtons[i].transform.localScale = _originalScales[i];

            Outline outline = answerButtons[i].GetComponent<Outline>();
            if (outline != null) outline.enabled = false;
        }

        if (_currentIndex >= questions.Length)
        {
            EndQuiz();
            return;
        }

        QuestionData q = questions[_currentIndex];
        questionText.text = q.questionText;

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
        }
    }

    void OnAnswer(int chosen)
    {
        foreach (var btn in answerButtons)
            btn.interactable = false;

        int correctIndex = questions[_currentIndex].correctIndex;
        bool correct = chosen == correctIndex;

        if (correct)
        {
            // Agrandir + entourer en vert
            StartCoroutine(ScaleTo(answerButtons[chosen], _originalScales[chosen] * scaleUp));
            SetOutline(answerButtons[chosen], Color.green);
        }
        else
        {
            // Agrandir brièvement puis reprendre taille normale
            StartCoroutine(ScaleBounceBack(answerButtons[chosen], _originalScales[chosen]));
            // Entourer la bonne réponse en vert
            SetOutline(answerButtons[correctIndex], Color.green);
        }

        _score += correct ? 1 : 0;
        _currentIndex++;
        Invoke(nameof(ShowQuestion), 1.5f);
    }

    IEnumerator ScaleTo(Button btn, Vector3 targetScale)
    {
        float elapsed = 0f;
        Vector3 startScale = btn.transform.localScale;
        while (elapsed < 1f)
        {
            elapsed += Time.deltaTime * scaleSpeed;
            btn.transform.localScale = Vector3.Lerp(startScale, targetScale, elapsed);
            yield return null;
        }
        btn.transform.localScale = targetScale;
    }

    IEnumerator ScaleBounceBack(Button btn, Vector3 originalScale)
    {
        // Agrandir
        Vector3 bigScale = originalScale * scaleUp;
        float elapsed = 0f;
        while (elapsed < 1f)
        {
            elapsed += Time.deltaTime * scaleSpeed;
            btn.transform.localScale = Vector3.Lerp(originalScale, bigScale, elapsed);
            yield return null;
        }

        // Reprendre taille normale
        elapsed = 0f;
        while (elapsed < 1f)
        {
            elapsed += Time.deltaTime * scaleSpeed;
            btn.transform.localScale = Vector3.Lerp(bigScale, originalScale, elapsed);
            yield return null;
        }
        btn.transform.localScale = originalScale;
    }

    void SetOutline(Button btn, Color color)
    {
        Outline outline = btn.GetComponent<Outline>();
        if (outline == null)
            outline = btn.gameObject.AddComponent<Outline>();

        outline.effectColor = color;
        outline.effectDistance = new Vector2(4, 4);
        outline.enabled = true;
    }

    void EndQuiz()
    {
        AnalyticsManager.Instance?.LogQuizScore(bookId, themeId, _score, questions.Length);
        AnalyticsManager.Instance?.LogActivityExited();
        //ActivityMapManager.Instance?.OnActivityCompleted("quiz"); // ← ajouter
        // Dans QuizManager.EndQuiz() par exemple
        ActivityMapManager[] managers = FindObjectsByType<ActivityMapManager>(FindObjectsSortMode.None);
        foreach (var manager in managers)
        {
            if (manager.themeId == themeId)
            {
                manager.OnActivityCompleted("quiz");
                break;
            }
        }

        questionText.text = "Bravo ! Tu as terminé ! 🎉";
        foreach (var btn in answerButtons)
            btn.gameObject.SetActive(false);
    }
}
/*using UnityEngine;
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
        AnalyticsManager.Instance?.LogActivityExited();
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
    {   AnalyticsManager.Instance?.LogQuizScore(bookId, themeId, _score, questions.Length);
        questionText.text = $"Terminé ! Score : {_score} / {questions.Length}";
        foreach (var btn in answerButtons)
            btn.gameObject.SetActive(false);
        
    }
}*/