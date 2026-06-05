using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;

/// <summary>
/// Écran de blocage affiché quand le quota est épuisé.
/// Gère un compte à rebours dynamique en temps réel pour la période de renouvellement.
/// </summary>
public class TimerBlockScreen : MonoBehaviour
{
    [Header("── Panel Principal (Prend 80% ou 100% de l'écran) ──")]
    public GameObject panelTimerBlock;

    [Header("── UI Elements ──")]
    public TextMeshProUGUI txtMessage;
    public TextMeshProUGUI txtPeriodInfo; // Exemple: "Disponible dans 03h 20min 15s"
    public Button btnUnlock;

    private const string MSG = "Time for a break !";
    private Coroutine _countdownCoroutine;

    // ══════════════════════════════════════════════════════════
    void Awake()
    {
        if (panelTimerBlock != null) panelTimerBlock.SetActive(false);
        if (txtMessage != null) txtMessage.text = MSG;

        if (btnUnlock != null)
        {
            btnUnlock.onClick.RemoveAllListeners();
            btnUnlock.onClick.AddListener(OnUnlockClicked);
        }
    }

    // ══════════════════════════════════════════════════════════
    // API PUBLIQUE
    // ══════════════════════════════════════════════════════════

    public void Show()
    {
        if (panelTimerBlock == null) return;

        panelTimerBlock.SetActive(true);

        // Lancer la mise à jour dynamique du texte chaque seconde
        if (_countdownCoroutine != null) StopCoroutine(_countdownCoroutine);
        _countdownCoroutine = StartCoroutine(UpdateCountdownRoutine());
    }

    public void Hide()
    {
        if (_countdownCoroutine != null)
        {
            StopCoroutine(_countdownCoroutine);
            _countdownCoroutine = null;
        }
        if (panelTimerBlock != null) panelTimerBlock.SetActive(false);
    }

    // ══════════════════════════════════════════════════════════
    // COMPTE À REBOURS DYNAMIQUE EN TEMPS RÉEL
    // ══════════════════════════════════════════════════════════

    IEnumerator UpdateCountdownRoutine()
    {
        var mgr = ParentalSettingsManager.Instance;
        if (mgr == null) yield break;

        while (panelTimerBlock.activeSelf)
        {
            long secondsLeft = mgr.SecondsUntilPeriodEnd();

            if (secondsLeft <= 0)
            {
                txtPeriodInfo.text = "New session available !";

                // Déblocage automatique instantané en temps réel !
                Hide();
                SessionTimerManager.Instance?.StartChildSession();
                yield break;
            }
            else
            {
                txtPeriodInfo.text = $"It will be available again in: \n {FormatDuration(secondsLeft)}";
            }

            yield return new WaitForSeconds(1f);
        }
    }

    string FormatDuration(long totalSeconds)
    {
        long h = totalSeconds / 3600;
        long m = (totalSeconds % 3600) / 60;
        long s = totalSeconds % 60;

        // Format propre avec deux chiffres (02h 05min 09s)
        if (h > 0) return $"{h:D2}h {m:D2}min {s:D2}s";
        if (m > 0) return $"{m:D2}min {s:D2}s";
        return $"{s:D2}s";
    }

    // ══════════════════════════════════════════════════════════
    // DÉBLOCAGE MANUEL PARENTAL
    // ══════════════════════════════════════════════════════════

    void OnUnlockClicked()
    {
        if (ParentalChallengeManager.Instance == null) return;

        ParentalChallengeManager.Instance.RequestAccess(() =>
        {
            Hide();
            SessionTimerManager.Instance?.StopTimer();

            // Redirection vers le panneau parental
            var authMgr = FindObjectOfType<AuthManagerV2>();
            if (authMgr != null)
            {
                authMgr.GoToParentPanelDirect();
            }
            else
            {
                Debug.LogWarning("[TimerBlockScreen] AuthManagerV2 introuvable dans la scène courante.");
            }
        });
    }
}