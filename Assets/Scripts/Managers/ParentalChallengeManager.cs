using System;
using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// Gère le défi mathématique qui protège l'espace parental.
/// - Génère un calcul aléatoire multi-étapes : (A ± B) × C - D
/// - 3 tentatives max → cooldown 30s → nouveau calcul
/// - RequestAccess(callback) = point d'entrée unique
/// </summary>
public class ParentalChallengeManager : MonoBehaviour
{
    public static ParentalChallengeManager Instance { get; private set; }

    [Header("── Panel Challenge ──")]
    public GameObject panelChallenge;

    [Header("── UI Elements ──")]
    public TextMeshProUGUI txtQuestion;
    public TMP_InputField inputAnswer;
    public Button btnSubmit;
    public TextMeshProUGUI txtFeedback;
    public TextMeshProUGUI txtCooldown;

    // ── Config ─────────────────────────────────────────────────
    private const int MAX_ATTEMPTS = 3;
    private const float COOLDOWN_SECONDS = 30f;

    // ── State ──────────────────────────────────────────────────
    private int _correctAnswer;
    private int _attemptsLeft;
    private bool _inCooldown = false;
    private Action _onSuccess;

    // ══════════════════════════════════════════════════════════
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

    void Start()
    {
        if (panelChallenge != null)
            panelChallenge.SetActive(false);
    }

    // ══════════════════════════════════════════════════════════
    // API PUBLIQUE
    // ══════════════════════════════════════════════════════════

    /// <summary>
    /// Appeler depuis n'importe quel bouton qui mène à l'espace parental.
    /// onSuccess = ce qui doit se passer si le défi est réussi.
    /// </summary>
    public void RequestAccess(Action onSuccess)
    {
        _onSuccess = onSuccess;
        _attemptsLeft = MAX_ATTEMPTS;
        _inCooldown = false;

        GenerateChallenge();
        ShowPanel(true);
    }

    // ══════════════════════════════════════════════════════════
    // GÉNÉRATION DU CALCUL
    // ══════════════════════════════════════════════════════════

    void GenerateChallenge()
    {
        // Formule : (A + B) × C - D  ou  (A - B) × C + D
        // On garantit un résultat positif et raisonnable (< 500)
        int A = UnityEngine.Random.Range(5,15);
        int B = UnityEngine.Random.Range(2, 8);
        int C = UnityEngine.Random.Range(2,4);
        int D = UnityEngine.Random.Range(1, 10);

        bool addFirst = UnityEngine.Random.value > 0.5f;

        int intermediate;
        string formula;

        if (addFirst)
        {
            intermediate = A + B;
            int result = intermediate * C - D;

            // S'assurer que le résultat est positif
            if (result <= 0) { D = 1; result = intermediate * C - D; }

            _correctAnswer = result;
            formula = $"( {A} + {B} ) × {C} - {D}";
        }
        else
        {
            // S'assurer que A > B pour éviter résultat négatif
            if (A <= B) A = B + UnityEngine.Random.Range(3, 10);
            intermediate = A - B;
            int result = intermediate * C + D;

            _correctAnswer = result;
            formula = $"( {A} - {B} ) × {C} + {D}";
        }

        txtQuestion.text = formula + " = ?";
        inputAnswer.text = "";
        txtFeedback.text = "";
        txtCooldown.text = "";

        Debug.Log($"[Challenge] Calcul généré : {formula} = {_correctAnswer}");
    }

    // ══════════════════════════════════════════════════════════
    // VALIDATION
    // ══════════════════════════════════════════════════════════

    /// Appelé par Btn_Submit (onClick dans l'Inspector)
    public void OnSubmitAnswer()
    {
        if (_inCooldown) return;

        if (!int.TryParse(inputAnswer.text.Trim(), out int userAnswer))
        {
            txtFeedback.text = "⚠ Entre un nombre entier.";
            return;
        }

        if (userAnswer == _correctAnswer)
        {
            // ✅ Succès
            txtFeedback.text = "✅ Correct !";
            ShowPanel(false);
            _onSuccess?.Invoke();
        }
        else
        {
            // ❌ Mauvaise réponse
            _attemptsLeft--;

            if (_attemptsLeft > 0)
            {
                txtFeedback.text = $"❌ Incorrect. {_attemptsLeft} essai(s) restant(s).";
            }
            else
            {
                // Cooldown
                StartCoroutine(CooldownRoutine());
            }
        }
    }

    IEnumerator CooldownRoutine()
    {
        _inCooldown = true;
        btnSubmit.interactable = false;
        inputAnswer.interactable = false;
        txtFeedback.text = "🔒 Trop de tentatives.";

        float remaining = COOLDOWN_SECONDS;
        while (remaining > 0)
        {
            txtCooldown.text = $"Réessayer dans {Mathf.CeilToInt(remaining)}s";
            yield return new WaitForSeconds(1f);
            remaining -= 1f;
        }

        // Reset après cooldown
        _inCooldown = false;
        _attemptsLeft = MAX_ATTEMPTS;
        btnSubmit.interactable = true;
        inputAnswer.interactable = true;
        txtCooldown.text = "";
        GenerateChallenge();
        txtFeedback.text = "Nouveau calcul généré.";
    }

    // ══════════════════════════════════════════════════════════
    // FERMETURE (bouton Annuler)
    // ══════════════════════════════════════════════════════════

    /// Appelé par Btn_Cancel dans Panel_Challenge
    public void OnCancel()
    {
        StopAllCoroutines();
        ShowPanel(false);
    }

    void ShowPanel(bool show)
    {
        if (panelChallenge != null)
            panelChallenge.SetActive(show);
    }
}