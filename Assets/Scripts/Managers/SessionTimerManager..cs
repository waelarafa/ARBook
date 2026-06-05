using System.Collections;
using UnityEngine;

public class SessionTimerManager : MonoBehaviour
{
    public static SessionTimerManager Instance { get; private set; }

    [Header("── Timer Block Screen ──")]
    public TimerBlockScreen timerBlockScreen;

    private bool _isRunning = false;
    private Coroutine _timerCoroutine;

    // ══════════════════════════════════════════════════════════
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    // ══════════════════════════════════════════════════════════
    public void StartChildSession()
    {
        var mgr = ParentalSettingsManager.Instance;
        if (mgr == null) return;

        if (mgr.IsPeriodExpired())
        {
            Debug.Log("[SessionTimer] Période expirée → nouvelle période");
            mgr.StartNewPeriod();
            timerBlockScreen?.Hide(); // On s'assure de cacher l'écran si la période s'est renouvelée
        }

        if (mgr.RemainingSeconds <= 0f)
        {
            Debug.Log("[SessionTimer] Quota épuisé → blocage");
            timerBlockScreen?.Show();
            return;
        }

        if (_isRunning) return;

        _isRunning = true;
        if (_timerCoroutine != null) StopCoroutine(_timerCoroutine);
        _timerCoroutine = StartCoroutine(TimerRoutine());

        Debug.Log($"[SessionTimer] ▶ restant: {mgr.RemainingSeconds:F0}s");
    }

    public void PauseTimer()
    {
        if (!_isRunning) return;
        _isRunning = false;
        Debug.Log("[SessionTimer] ⏸ Pausé");
    }

    public void ResumeTimer()
    {
        var mgr = ParentalSettingsManager.Instance;
        if (mgr == null || _isRunning) return;

        if (mgr.RemainingSeconds <= 0f)
        {
            timerBlockScreen?.Show();
            return;
        }

        timerBlockScreen?.Hide(); // Si le parent a augmenté le temps, on cache le message
        _isRunning = true;
        if (_timerCoroutine != null) StopCoroutine(_timerCoroutine);
        _timerCoroutine = StartCoroutine(TimerRoutine());
        Debug.Log($"[SessionTimer] ▶ Reprise — restant:{mgr.RemainingSeconds:F0}s");
    }

    public void StopTimer()
    {
        _isRunning = false;
        if (_timerCoroutine != null)
        {
            StopCoroutine(_timerCoroutine);
            _timerCoroutine = null;
        }
    }

    // ══════════════════════════════════════════════════════════
    IEnumerator TimerRoutine()
    {
        while (true)
        {
            yield return new WaitForSeconds(1f);
            if (!_isRunning) continue;

            var mgr = ParentalSettingsManager.Instance;
            if (mgr == null) continue;

            mgr.AddConsumedSeconds(1f);

            if (mgr.RemainingSeconds <= 0f)
            {
                Debug.Log("[SessionTimer] ⏰ Quota épuisé → blocage");
                _isRunning = false;
                timerBlockScreen?.Show();
                yield break;
            }
        }
    }
}

/*ing System.Collections;
using UnityEngine;

/// <summary>
/// Gère le chronomètre enfant avec logique réservoir persistant.
///
/// AU LANCEMENT (StartChildSession) :
///   1. Période expirée ? → nouvelle période (réservoir plein)
///   2. Réservoir vide ?  → blocage immédiat
///   3. Sinon            → lancer le chrono sur le restant
///
/// PENDANT LE JEU :
///   - Chaque seconde : consumed++ sauvegardé en ES3
///   - Réservoir vide → Panel_TimerBlock
///
/// FERMETURE APP :
///   - consumed + periodStartTimestamp déjà en ES3 → persistants
/// </summary>
public class SessionTimerManager : MonoBehaviour
{
    public static SessionTimerManager Instance { get; private set; }

    [Header("── Timer Block Screen ──")]
    public TimerBlockScreen timerBlockScreen;

    private bool _isRunning = false;
    private Coroutine _timerCoroutine;

    // ══════════════════════════════════════════════════════════
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    // ══════════════════════════════════════════════════════════
    // POINT D'ENTRÉE — GoToLibrary() dans AuthManagerV2
    // ══════════════════════════════════════════════════════════

    public void StartChildSession()
    {
        var mgr = ParentalSettingsManager.Instance;
        if (mgr == null) return;

        // ── 1. Période expirée → réservoir plein ──────────────
        if (mgr.IsPeriodExpired())
        {
            Debug.Log("[SessionTimer] Période expirée → nouvelle période");
            mgr.StartNewPeriod();
        }

        // ── 2. Réservoir vide → bloquer ───────────────────────
        if (mgr.RemainingSeconds <= 0f)
        {
            Debug.Log("[SessionTimer] Quota épuisé → blocage");
            timerBlockScreen?.Show();
            return;
        }

        // ── 3. Quota disponible → lancer le chrono ────────────
        if (_isRunning) return; // déjà en cours (ex: retour depuis panel_Parent)

        _isRunning = true;
        if (_timerCoroutine != null) StopCoroutine(_timerCoroutine);
        _timerCoroutine = StartCoroutine(TimerRoutine());

        Debug.Log($"[SessionTimer] ▶ Session — restant: {mgr.RemainingSeconds:F0}s");
    }

    // ══════════════════════════════════════════════════════════
    // PAUSE — GoToParentPanel() dans AuthManagerV2
    // ══════════════════════════════════════════════════════════

    public void PauseTimer()
    {
        if (!_isRunning) return;
        _isRunning = false;
        Debug.Log($"[SessionTimer] ⏸ Pausé — " +
                  $"consumed:{ParentalSettingsManager.Instance?.ConsumedSeconds:F0}s");
    }

    // ══════════════════════════════════════════════════════════
    // REPRISE — BackFromParent() dans AuthManagerV2
    // ══════════════════════════════════════════════════════════

    public void ResumeTimer()
    {
        var mgr = ParentalSettingsManager.Instance;
        if (mgr == null || _isRunning) return;

        // Re-vérifier le quota (le parent a peut-être modifié)
        if (mgr.RemainingSeconds <= 0f)
        {
            Debug.Log("[SessionTimer] ResumeTimer → quota toujours vide");
            timerBlockScreen?.Show();
            return;
        }

        _isRunning = true;
        if (_timerCoroutine != null) StopCoroutine(_timerCoroutine);
        _timerCoroutine = StartCoroutine(TimerRoutine());

        Debug.Log($"[SessionTimer] ▶ Reprise — restant:{mgr.RemainingSeconds:F0}s");
    }

    // ══════════════════════════════════════════════════════════
    // STOP complet (sécurité)
    // ══════════════════════════════════════════════════════════

    public void StopTimer()
    {
        _isRunning = false;
        if (_timerCoroutine != null)
        {
            StopCoroutine(_timerCoroutine);
            _timerCoroutine = null;
        }
    }

    // ══════════════════════════════════════════════════════════
    // COROUTINE — 1 tick par seconde
    // ══════════════════════════════════════════════════════════

    IEnumerator TimerRoutine()
    {
        while (true)
        {
            yield return new WaitForSeconds(1f);

            if (!_isRunning) continue;

            var mgr = ParentalSettingsManager.Instance;
            if (mgr == null) continue;

            // Incrémenter + sauvegarder en ES3 via AddConsumedSeconds
            mgr.AddConsumedSeconds(1f);

            float remaining = mgr.RemainingSeconds;

            // Réservoir vide → bloquer
            if (remaining <= 0f)
            {
                Debug.Log("[SessionTimer] ⏰ Quota épuisé → blocage");
                _isRunning = false;
                timerBlockScreen?.Show();
                yield break;
            }
        }
    }
}*/