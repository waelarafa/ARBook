using UnityEngine;

/// <summary>
/// Script de test temporaire — À SUPPRIMER avant la release.
/// Attacher sur n'importe quel GameObject dans la scène.
/// </summary>
public class TimerTestHelper : MonoBehaviour
{
    void OnGUI()
    {
        GUILayout.BeginArea(new Rect(10, 10, 260, 420));

        GUILayout.Label("── Timer Test ──");

        // ── Actions timer ──────────────────────────────────────
        if (GUILayout.Button("▶ Start Session (GoToLibrary)"))
        {
            Debug.Log("[TEST] StartChildSession");
            SessionTimerManager.Instance?.StartChildSession();
        }

        if (GUILayout.Button("⏸ Pause (GoToParent)"))
        {
            Debug.Log("[TEST] PauseTimer");
            SessionTimerManager.Instance?.PauseTimer();
        }

        if (GUILayout.Button("▶ Resume"))
        {
            Debug.Log("[TEST] ResumeTimer");
            SessionTimerManager.Instance?.ResumeTimer();
        }

        if (GUILayout.Button("⏹ Stop Timer"))
        {
            Debug.Log("[TEST] StopTimer");
            SessionTimerManager.Instance?.StopTimer();
        }

        // ── Forcer le blocage immédiatement ───────────────────
        if (GUILayout.Button("💥 Épuiser quota → blocage"))
        {
            Debug.Log("[TEST] Forcer quota épuisé");
            var mgr = ParentalSettingsManager.Instance;
            if (mgr != null)
            {
                // Vider tout le réservoir
                mgr.AddConsumedSeconds(mgr.RemainingSeconds + 1f);
                // Stopper la coroutine
                SessionTimerManager.Instance?.StopTimer();
                // Afficher le block screen
                FindObjectOfType<TimerBlockScreen>()?.Show();
                Debug.Log("[TEST] Block screen affiché");
            }
            else
            {
                Debug.LogError("[TEST] ParentalSettingsManager.Instance est null !");
            }
        }

        // ── Reset période ──────────────────────────────────────
        if (GUILayout.Button("🔄 Reset période (nouvelle session)"))
        {
            Debug.Log("[TEST] StartNewPeriod");
            ParentalSettingsManager.Instance?.StartNewPeriod();
            FindObjectOfType<TimerBlockScreen>()?.Hide();
        }

        // ── État en temps réel ─────────────────────────────────
        GUILayout.Space(8);
        GUILayout.Label("── État actuel ──");

        var s = ParentalSettingsManager.Instance;
        if (s != null)
        {
            GUILayout.Label($"Quota configuré : {s.QuotaMinutes} min");
            GUILayout.Label($"Période configurée : {s.PeriodHours}h");
            GUILayout.Label($"Consommé : {s.ConsumedSeconds:F0}s");
            GUILayout.Label($"Restant : {s.RemainingSeconds:F0}s");
            GUILayout.Label($"Période expirée : {s.IsPeriodExpired()}");
            GUILayout.Label($"Fin période dans : {s.SecondsUntilPeriodEnd()}s");
        }
        else
        {
            GUILayout.Label("⚠ ParentalSettingsManager null !");
        }

        GUILayout.EndArea();
    }
}