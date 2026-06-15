using System;
using UnityEngine;

/// <summary>
/// Stocke la configuration parentale ET les données de session persistantes.
/// Config  : quotaMinutes (taille réservoir), periodHours (cycle)
/// Session : consumedSeconds, periodStartTimestamp
/// Persistance via EasySave 3.
/// </summary>
public class ParentalSettingsManager : MonoBehaviour
{
    public static ParentalSettingsManager Instance { get; private set; }

    private const string ES3_KEY_CONFIG = "parental_config";
    private const string ES3_KEY_SESSION = "parental_session";

    // ══════════════════════════════════════════════════════════
    // MODÈLES
    // ══════════════════════════════════════════════════════════

    [Serializable]
    public class ParentalConfig
    {
        public int quotaMinutes = 20;
        public int periodHours = 24;
    }

    [Serializable]
    public class SessionData
    {
        public float consumedSeconds = 0f;
        public long periodStartTimestamp = 0L;
    }

    // ══════════════════════════════════════════════════════════
    // DONNÉES PRIVÉES
    // ══════════════════════════════════════════════════════════

    private ParentalConfig _config;
    private SessionData _session;

    // ══════════════════════════════════════════════════════════
    // ACCÈS PUBLICS — CONFIG
    // ══════════════════════════════════════════════════════════

    public int QuotaMinutes => _config.quotaMinutes;
    public int PeriodHours => _config.periodHours;

    // ══════════════════════════════════════════════════════════
    // ACCÈS PUBLICS — SESSION
    // ══════════════════════════════════════════════════════════

    public float ConsumedSeconds => _session.consumedSeconds;

    public float RemainingSeconds =>
        Mathf.Max(0f, _config.quotaMinutes * 60f - _session.consumedSeconds);

    public bool IsPeriodExpired()
    {
        if (_session.periodStartTimestamp == 0L) return true;

        long now = DateTimeOffset.UtcNow.ToUnixTimeSeconds();
        long periodEnd = _session.periodStartTimestamp
                       + ((long)_config.periodHours * 3600L);
        return now >= periodEnd;
    }

    public long SecondsUntilPeriodEnd()
    {
        if (_session.periodStartTimestamp == 0L) return 0L;
        long now = DateTimeOffset.UtcNow.ToUnixTimeSeconds();
        long periodEnd = _session.periodStartTimestamp
                       + ((long)_config.periodHours * 3600L);
        return Math.Max(0L, periodEnd - now);
    }

    // ══════════════════════════════════════════════════════════
    // INIT
    // ══════════════════════════════════════════════════════════

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        Load();
    }

    void Load()
    {
        _config = ES3.KeyExists(ES3_KEY_CONFIG)
                 ? ES3.Load<ParentalConfig>(ES3_KEY_CONFIG)
                 : new ParentalConfig();

        _session = ES3.KeyExists(ES3_KEY_SESSION)
                 ? ES3.Load<SessionData>(ES3_KEY_SESSION)
                 : new SessionData();

        Debug.Log($"[ParentalSettings] Config: quota={_config.quotaMinutes}min " +
                  $"period={_config.periodHours}h | " +
                  $"Session: consumed={_session.consumedSeconds:F0}s " +
                  $"periodStart={_session.periodStartTimestamp}");
    }

    // ══════════════════════════════════════════════════════════
    // SAUVEGARDE CONFIG
    // ══════════════════════════════════════════════════════════

    public void SaveConfig(int quotaMinutes, int periodHours)
    {
        _config.quotaMinutes = Mathf.Clamp(quotaMinutes, 5, 120);
        _config.periodHours = Mathf.Clamp(periodHours, 1, 72);
        ES3.Save(ES3_KEY_CONFIG, _config);

        Debug.Log($"[ParentalSettings] Config sauvegardée — " +
                  $"quota:{_config.quotaMinutes}min " +
                  $"period:{_config.periodHours}h");
    }

    // ══════════════════════════════════════════════════════════
    // GESTION SESSION
    // ══════════════════════════════════════════════════════════

    public void AddConsumedSeconds(float seconds)
    {
        _session.consumedSeconds += seconds;
        SaveSession();
    }

    public void StartNewPeriod()
    {
        _session.consumedSeconds = 0f;
        _session.periodStartTimestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds();
        SaveSession();
        Debug.Log($"[ParentalSettings] Nouvelle période démarrée — " +
                  $"quota:{_config.quotaMinutes}min");
    }

    private void SaveSession()
    {
        ES3.Save(ES3_KEY_SESSION, _session);
    }
}
/*using System;
using UnityEngine;

/// <summary>
/// Stocke la configuration parentale ET les données de session persistantes.
/// Config  : age, quotaMinutes (taille réservoir), periodHours (cycle)
/// Session : consumedSeconds, periodStartTimestamp
/// Persistance via EasySave 3.
/// </summary>
public class ParentalSettingsManager : MonoBehaviour
{
    public static ParentalSettingsManager Instance { get; private set; }

    private const string ES3_KEY_CONFIG = "parental_config";
    private const string ES3_KEY_SESSION = "parental_session";

   

    // ══════════════════════════════════════════════════════════
    // MODÈLES
    // ══════════════════════════════════════════════════════════

    [Serializable]
    public class ParentalConfig
    {
        public int childAge = 5;
        public int quotaMinutes = 20;  // taille du réservoir 20
        public int periodHours = 24;  // durée du cycle 24
    }

    [Serializable]
    public class SessionData
    {
        public float consumedSeconds = 0f;
        public long periodStartTimestamp = 0L; // Unix seconds, 0 = jamais démarré
    }

    // ══════════════════════════════════════════════════════════
    // DONNÉES PRIVÉES
    // ══════════════════════════════════════════════════════════

    private ParentalConfig _config;
    private SessionData _session;

    // ══════════════════════════════════════════════════════════
    // ACCÈS PUBLICS — CONFIG
    // ══════════════════════════════════════════════════════════

    public int ChildAge => _config.childAge;
    public int QuotaMinutes => _config.quotaMinutes;
    public int PeriodHours => _config.periodHours;

    // ══════════════════════════════════════════════════════════
    // ACCÈS PUBLICS — SESSION
    // ══════════════════════════════════════════════════════════

    public float ConsumedSeconds => _session.consumedSeconds;

    /// Quota restant en secondes dans la période courante
    public float RemainingSeconds =>
        Mathf.Max(0f, _config.quotaMinutes * 60f - _session.consumedSeconds);

    /// Vérifie si la période de renouvellement est terminée
    public bool IsPeriodExpired()
    {
        // Jamais démarré → considéré expiré → nouvelle période au prochain jeu
        if (_session.periodStartTimestamp == 0L) return true;

        long now = DateTimeOffset.UtcNow.ToUnixTimeSeconds();
        long periodEnd = _session.periodStartTimestamp
                       + ((long)_config.periodHours * 3600L);
        return now >= periodEnd;
    }

    /// Secondes restantes avant la fin de la période courante
    public long SecondsUntilPeriodEnd()
    {
        if (_session.periodStartTimestamp == 0L) return 0L;
        long now = DateTimeOffset.UtcNow.ToUnixTimeSeconds();
        long periodEnd = _session.periodStartTimestamp
                       + ((long)_config.periodHours * 3600L);
        return Math.Max(0L, periodEnd - now);

        
    }
    

    // ══════════════════════════════════════════════════════════
    // INIT
    // ══════════════════════════════════════════════════════════

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        Load();
    }

    void Load()
    {
        _config = ES3.KeyExists(ES3_KEY_CONFIG)
                 ? ES3.Load<ParentalConfig>(ES3_KEY_CONFIG)
                 : new ParentalConfig();

        _session = ES3.KeyExists(ES3_KEY_SESSION)
                 ? ES3.Load<SessionData>(ES3_KEY_SESSION)
                 : new SessionData();
        // seulement pour le test 
        //_session.consumedSeconds = (_config.quotaMinutes * 60f) - 5f;

        Debug.Log($"[ParentalSettings] Config: quota={_config.quotaMinutes}min " +
                  $"period={_config.periodHours}h | " +
                  $"Session: consumed={_session.consumedSeconds:F0}s " +
                  $"periodStart={_session.periodStartTimestamp}");
        
    }

    // ══════════════════════════════════════════════════════════
    // SAUVEGARDE CONFIG
    // ══════════════════════════════════════════════════════════

    /// Appelé depuis SettingsParentalUI.OnSaveClicked()
    public void SaveConfig(int age, int quotaMinutes, int periodHours)
    {
        _config.childAge = Mathf.Clamp(age, 4, 12);
        _config.quotaMinutes = Mathf.Clamp(quotaMinutes, 5, 120);
        _config.periodHours = Mathf.Clamp(periodHours, 1, 72);
        ES3.Save(ES3_KEY_CONFIG, _config);

        Debug.Log($"[ParentalSettings] Config sauvegardée — " +
                  $"age:{_config.childAge} " +
                  $"quota:{_config.quotaMinutes}min " +
                  $"period:{_config.periodHours}h");
    }

    // ══════════════════════════════════════════════════════════
    // GESTION SESSION
    // ══════════════════════════════════════════════════════════

    /// Ajoute du temps consommé et sauvegarde immédiatement
    public void AddConsumedSeconds(float seconds)
    {
        _session.consumedSeconds += seconds;
        SaveSession();
    }

    /// Démarre une nouvelle période : réservoir plein, timestamp now
    public void StartNewPeriod()
    {
        _session.consumedSeconds = 0f;
        _session.periodStartTimestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds();
        SaveSession();
        Debug.Log($"[ParentalSettings] Nouvelle période démarrée — " +
                  $"quota:{_config.quotaMinutes}min");
    }

    private void SaveSession()
    {
        ES3.Save(ES3_KEY_SESSION, _session);
    }
}*/