using UnityEngine;
using System.Collections.Generic;

public class AnalyticsManager : MonoBehaviour
{
    public static AnalyticsManager Instance { get; private set; }

    // Cache local des activités terminées pendant CETTE session (clé = book|theme|activity).
    // Renseigné par LogActivityExited() AVANT l'écriture Firestore (asynchrone) ; permet à
    // CheckActivityCompleted() de répondre "true" instantanément, sans attendre la confirmation
    // serveur. Firestore reste la source de vérité persistante entre les sessions.
    private readonly HashSet<string> _completedActivities = new HashSet<string>();

    private static string ActivityKey(string bookId, string themeId, string activityId)
        => $"{bookId}|{themeId}|{activityId}";

    private float _sessionStartTime;
    private int _pagesViewedThisSession;
    private float _childSessionStart;
    private string _currentChildMode;
    private bool _childSessionActive = false;
    private float _activitySessionStart;
    private string _currentActivityId;
    private string _currentActivityThemeId;
    private string _currentActivityBookId;
    private bool _activitySessionActive = false;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

    // ══════════════════════════════════════════════════════════
    // SESSION GLOBALE
    // ══════════════════════════════════════════════════════════

    public void LogSessionStarted()
    {
        _sessionStartTime = Time.realtimeSinceStartup;
        _pagesViewedThisSession = 0;
        Debug.Log("[Analytics] session_started");
    }

    public void LogSessionEnded()
    {
        if (_childSessionActive) LogChildSessionEnded();
        if (_activitySessionActive) LogActivityExited();

        float duration = Time.realtimeSinceStartup - _sessionStartTime;
        LocalEventBuffer.Instance?.AddSession(duration);

        string userId = GetUserId();
        if (userId != "anonymous")
            FirestoreManager.Instance?.LogSessionTime(userId, duration);

        Debug.Log($"[Analytics] session_ended — {duration:F0}s");
    }

    // ══════════════════════════════════════════════════════════
    // SESSION ENFANT
    // ══════════════════════════════════════════════════════════

    public void LogChildSessionStarted(string mode)
    {
        if (_childSessionActive) LogChildSessionEnded();
        _currentChildMode = mode;
        _childSessionStart = Time.realtimeSinceStartup;
        _childSessionActive = true;
        Debug.Log($"[Analytics] child_session_started — mode={mode}");
    }

    public void LogChildSessionEnded()
    {
        if (!_childSessionActive) return;
        float duration = Time.realtimeSinceStartup - _childSessionStart;
        _childSessionActive = false;

        string userId = GetUserId();
        if (userId != "anonymous")
            FirestoreManager.Instance?.LogChildSession(userId, _currentChildMode, duration);
        else
            LocalEventBuffer.Instance?.AddChildSession(_currentChildMode, duration);

        Debug.Log($"[Analytics] child_session_ended — {_currentChildMode} {duration:F0}s");
    }

    // ══════════════════════════════════════════════════════════
    // AR — PAGE & ITEM
    // ══════════════════════════════════════════════════════════

    public void LogPageViewed(string bookId, string themeId, string pageId)
    {
        _pagesViewedThisSession++;
        string userId = GetUserId();
        if (userId != "anonymous")
            FirestoreManager.Instance?.LogPageViewed(userId, bookId, themeId, pageId);
        else
            LocalEventBuffer.Instance?.AddPageView(bookId, themeId, pageId);
        Debug.Log($"[Analytics] page_viewed — {bookId}/{themeId}/{pageId}");
    }

    public void LogItemDiscovered(string bookId, string themeId, string pageId, string itemName)
    {
        string userId = GetUserId();
        if (userId != "anonymous")
            FirestoreManager.Instance?.LogItemDiscovered(userId, bookId, themeId, pageId, itemName);
        else
            LocalEventBuffer.Instance?.AddItemDiscovered(bookId, themeId, pageId, itemName);
        Debug.Log($"[Analytics] item_discovered — {itemName}");
    }

    public void LogBookDetected(string bookId, float timeToDetect) =>
        Debug.Log($"[Analytics] book_detected — {bookId} ({timeToDetect:F1}s)");

    public void LogBookLost(string bookId, float duration) =>
        Debug.Log($"[Analytics] book_lost — {bookId} ({duration:F1}s)");

    // ══════════════════════════════════════════════════════════
    // ACTIVITÉS
    // ══════════════════════════════════════════════════════════

    public void LogActivityEntered(string bookId, string themeId, string activityId)
    {
        //if (_activitySessionActive) LogActivityExited();
        _currentActivityBookId  = bookId;
        _currentActivityThemeId = themeId;
        _currentActivityId      = activityId;
        _activitySessionStart   = Time.realtimeSinceStartup;
        _activitySessionActive  = true;
        Debug.Log($"[Analytics] activity_entered — {bookId}/{themeId}/{activityId}");
    }

    public void LogActivityExited()
    {
        if (!_activitySessionActive) return;
        float duration = Time.realtimeSinceStartup - _activitySessionStart;
        _activitySessionActive = false;

        // Marque la complétion en cache AVANT de lancer l'écriture Firestore
        // (fire-and-forget). Le refresh de la map déclenché juste après verra donc
        // cette activité comme complétée sans attendre la confirmation réseau.
        _completedActivities.Add(ActivityKey(_currentActivityBookId, _currentActivityThemeId, _currentActivityId));

        string userId = GetUserId();
        if (userId != "anonymous")
            FirestoreManager.Instance?.LogActivitySession(userId, _currentActivityBookId, _currentActivityThemeId, _currentActivityId, duration);
        else
            LocalEventBuffer.Instance?.AddActivitySession(_currentActivityBookId, _currentActivityThemeId, _currentActivityId, duration);

        Debug.Log($"[Analytics] activity_exited — {_currentActivityBookId}/{_currentActivityThemeId}/{_currentActivityId} duration={duration:F0}s");
    }

    public void LogQuizScore(string bookId, string themeId, int score, int totalQuestions)
    {
        string userId = GetUserId();
        if (userId != "anonymous")
            FirestoreManager.Instance?.LogQuizScore(userId, bookId, themeId, score, totalQuestions);
        else
            LocalEventBuffer.Instance?.AddQuizScore(bookId, themeId, score, totalQuestions);
        Debug.Log($"[Analytics] quiz_score — {bookId}/{themeId} score={score}/{totalQuestions}");
    }

    // ══════════════════════════════════════════════════════════
    // CHECK — pour LevelMapBuilder et ActivityMapManager
    // ══════════════════════════════════════════════════════════

    public void CheckItemDiscovered(string itemName, System.Action<bool> callback)
    {
        string userId = GetUserId();
        if (userId != "anonymous")
            FirestoreManager.Instance?.IsItemDiscovered(userId, itemName, callback);
        else
            callback?.Invoke(LocalEventBuffer.Instance?.IsItemDiscovered(itemName) ?? false);
    }

    public void CheckActivityCompleted(string bookId, string themeId, string activityId,
                                       System.Action<bool> callback)
    {
        // 1) Cache local d'abord : une activité terminée pendant cette session est
        //    visible immédiatement, avant même que l'écriture Firestore soit confirmée.
        //    C'est ce qui supprime la race avec le refresh de la map.
        if (_completedActivities.Contains(ActivityKey(bookId, themeId, activityId)))
        {
            callback?.Invoke(true);
            return;
        }

        // 2) Sinon, source de vérité persistante (Firestore en ligne, sinon buffer local).
        string userId = GetUserId();
        if (userId != "anonymous")
            FirestoreManager.Instance?.IsActivityCompleted(userId, bookId, themeId, activityId, callback);
        else
            callback?.Invoke(LocalEventBuffer.Instance?.IsActivityCompleted(bookId, themeId, activityId) ?? false);
    }

    // ══════════════════════════════════════════════════════════
    // AUTH
    // ══════════════════════════════════════════════════════════

    public void LogUserLoggedIn(string method) =>
        Debug.Log($"[Analytics] user_logged_in — {method}");

    public void LogUserSignedUp(string method) =>
        Debug.Log($"[Analytics] user_signed_up — {method}");

    // ══════════════════════════════════════════════════════════
    // HELPER
    // ══════════════════════════════════════════════════════════

    private string GetUserId()
    {
        var user = Firebase.Auth.FirebaseAuth.DefaultInstance.CurrentUser;
        if (user != null && !user.IsAnonymous) return user.UserId;
        return "anonymous";
    }
}
/*using UnityEngine;

public class AnalyticsManager : MonoBehaviour
{
    public static AnalyticsManager Instance { get; private set; }

    // ── Session globale app ───────────────────────────────────
    private float _sessionStartTime;
    private int _pagesViewedThisSession;

    // ── Session enfant (par mode) ─────────────────────────────
    private float _childSessionStart;
    private string _currentChildMode; // "AR" | "3D" | "Activity"
    private bool _childSessionActive = false;

    // ── Activité session ──────────────────────────────────────
    private float _activitySessionStart;
    private string _currentActivityId;
    private string _currentActivityThemeId;
    private string _currentActivityBookId;
    private bool _activitySessionActive = false;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

    // ════════════════════════════════════════════════════════
    // SESSION GLOBALE (app ouvre / ferme)
    // ════════════════════════════════════════════════════════

    public void LogSessionStarted()
    {
        _sessionStartTime = Time.realtimeSinceStartup;
        _pagesViewedThisSession = 0;
        Debug.Log("[Analytics] session_started");
    }

    public void LogSessionEnded()
    {
        if (_childSessionActive)
            LogChildSessionEnded();
        if (_activitySessionActive)
            LogActivityExited();

        float duration = Time.realtimeSinceStartup - _sessionStartTime;
        LocalEventBuffer.Instance?.AddSession(duration);

        string userId = GetUserId();
        if (userId != "anonymous")
            FirestoreManager.Instance?.LogSessionTime(userId, duration);

        Debug.Log($"[Analytics] session_ended — {duration:F0}s");
    }

    // ════════════════════════════════════════════════════════
    // SESSION ENFANT (par mode : AR / 3D / Activity)
    // ════════════════════════════════════════════════════════

    public void LogChildSessionStarted(string mode)
    {
        if (_childSessionActive)
            LogChildSessionEnded();

        _currentChildMode = mode;
        _childSessionStart = Time.realtimeSinceStartup;
        _childSessionActive = true;
        Debug.Log($"[Analytics] child_session_started — mode={mode}");
    }

    public void LogChildSessionEnded()
    {
        if (!_childSessionActive) return;

        float duration = Time.realtimeSinceStartup - _childSessionStart;
        _childSessionActive = false;

        string userId = GetUserId();
        if (userId != "anonymous")
            FirestoreManager.Instance?.LogChildSession(userId, _currentChildMode, duration);
        else
            LocalEventBuffer.Instance?.AddChildSession(_currentChildMode, duration);

        Debug.Log($"[Analytics] child_session_ended — {_currentChildMode} {duration:F0}s");
    }

    // ════════════════════════════════════════════════════════
    // AR — PAGE & ITEM
    // ════════════════════════════════════════════════════════

    public void LogPageViewed(string bookId, string themeId, string pageId)
    {
        _pagesViewedThisSession++;
        string userId = GetUserId();

        if (userId != "anonymous")
            FirestoreManager.Instance?.LogPageViewed(userId, bookId, themeId, pageId);
        else
            LocalEventBuffer.Instance?.AddPageView(bookId, themeId, pageId);

        Debug.Log($"[Analytics] page_viewed — {bookId}/{themeId}/{pageId}");
    }

    public void LogItemDiscovered(string bookId, string themeId, string pageId, string itemName)
    {

        string userId = GetUserId();
        Debug.Log($"[Analytics] userId={userId}");
        Debug.Log($"[Analytics] FirestoreManager={FirestoreManager.Instance}");
        Debug.Log($"[Analytics] LocalBuffer={LocalEventBuffer.Instance}");

        if (userId != "anonymous")
            FirestoreManager.Instance?.LogItemDiscovered(userId, bookId, themeId, pageId, itemName);
        else
            LocalEventBuffer.Instance?.AddItemDiscovered(bookId, themeId, pageId, itemName);

        Debug.Log($"[Analytics] item_discovered — {itemName}");
    }
    

    public void LogBookDetected(string bookId, float timeToDetect) =>
        Debug.Log($"[Analytics] book_detected — {bookId} ({timeToDetect:F1}s)");

    public void LogBookLost(string bookId, float duration) =>
        Debug.Log($"[Analytics] book_lost — {bookId} ({duration:F1}s)");

    // ════════════════════════════════════════════════════════
    // ACTIVITÉS
    // ════════════════════════════════════════════════════════

    public void LogActivityEntered(string bookId, string themeId, string activityId)
    {
        if (_activitySessionActive)
            LogActivityExited();

        _currentActivityBookId = bookId;
        _currentActivityThemeId = themeId;
        _currentActivityId = activityId;
        _activitySessionStart = Time.realtimeSinceStartup;
        _activitySessionActive = true;

        Debug.Log($"[Analytics] activity_entered — {bookId}/{themeId}/{activityId}");
    }

    public void LogActivityExited()
    {
        if (!_activitySessionActive) return;

        float duration = Time.realtimeSinceStartup - _activitySessionStart;
        _activitySessionActive = false;

        string userId = GetUserId();
        if (userId != "anonymous")
            FirestoreManager.Instance?.LogActivitySession(userId, _currentActivityBookId, _currentActivityThemeId, _currentActivityId, duration);
        else
            LocalEventBuffer.Instance?.AddActivitySession(_currentActivityBookId, _currentActivityThemeId, _currentActivityId, duration);

        Debug.Log($"[Analytics] activity_exited — {_currentActivityBookId}/{_currentActivityThemeId}/{_currentActivityId} duration={duration:F0}s");
    }
    public void LogQuizScore(string bookId, string themeId, int score, int totalQuestions)
    {
        string userId = GetUserId();

        if (userId != "anonymous")
            FirestoreManager.Instance?.LogQuizScore(userId, bookId, themeId, score, totalQuestions);
        else
            LocalEventBuffer.Instance?.AddQuizScore(bookId, themeId, score, totalQuestions);

        Debug.Log($"[Analytics] quiz_score — {bookId}/{themeId} score={score}/{totalQuestions}");
    }

    // ════════════════════════════════════════════════════════
    // AUTH
    // ════════════════════════════════════════════════════════

    public void LogUserLoggedIn(string method) =>
        Debug.Log($"[Analytics] user_logged_in — {method}");

    public void LogUserSignedUp(string method) =>
        Debug.Log($"[Analytics] user_signed_up — {method}");

    // ════════════════════════════════════════════════════════
    // HELPER
    // ════════════════════════════════════════════════════════

    private string GetUserId()
    {
        var user = Firebase.Auth.FirebaseAuth.DefaultInstance.CurrentUser;
        if (user != null && !user.IsAnonymous)
            return user.UserId;
        return "anonymous";
    }
}
/*using UnityEngine;

public class AnalyticsManager : MonoBehaviour
{
    public static AnalyticsManager Instance { get; private set; }

    // ── Session globale app ───────────────────────────────────
    private float _sessionStartTime;
    private int _pagesViewedThisSession;

    // ── Session enfant (par mode) ─────────────────────────────
    private float _childSessionStart;
    private string _currentChildMode; // "AR" | "3D" | "Activity"
    private bool _childSessionActive = false;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

    // ════════════════════════════════════════════════════════
    // SESSION GLOBALE (app ouvre / ferme)
    // ════════════════════════════════════════════════════════

    public void LogSessionStarted()
    {
        _sessionStartTime = Time.realtimeSinceStartup;
        _pagesViewedThisSession = 0;
        Debug.Log("[Analytics] session_started");
    }

    public void LogSessionEnded()
    {
        // Si une session enfant est encore active → on la termine aussi
        if (_childSessionActive)
            LogChildSessionEnded();

        float duration = Time.realtimeSinceStartup - _sessionStartTime;
        LocalEventBuffer.Instance?.AddSession(duration);

        string userId = GetUserId();
        if (userId != "anonymous")
            FirestoreManager.Instance?.LogSessionTime(userId, duration);

        Debug.Log($"[Analytics] session_ended — {duration:F0}s");
    }

    // ════════════════════════════════════════════════════════
    // SESSION ENFANT (par mode : AR / 3D / Activity)
    // Appelée par la binôme quand l'enfant entre/sort d'un mode
    // ════════════════════════════════════════════════════════

    public void LogChildSessionStarted(string mode)
    {
        // Si une session était déjà active, on la termine d'abord
        if (_childSessionActive)
            LogChildSessionEnded();

        _currentChildMode = mode;
        _childSessionStart = Time.realtimeSinceStartup;
        _childSessionActive = true;
        Debug.Log($"[Analytics] child_session_started — mode={mode}");
    }

    public void LogChildSessionEnded()
    {
        if (!_childSessionActive) return;

        float duration = Time.realtimeSinceStartup - _childSessionStart;
        _childSessionActive = false;

        string userId = GetUserId();
        if (userId != "anonymous")
            FirestoreManager.Instance?.LogChildSession(userId, _currentChildMode, duration);
        else
            LocalEventBuffer.Instance?.AddChildSession(_currentChildMode, duration);

        Debug.Log($"[Analytics] child_session_ended — {_currentChildMode} {duration:F0}s");
    }

    // ════════════════════════════════════════════════════════
    // AR — PAGE & ANIMAL
    // ════════════════════════════════════════════════════════

    public void LogPageViewed(string bookId, string pageId)
    {
        _pagesViewedThisSession++;
        string userId = GetUserId();
        string animalName = pageId;

        if (userId != "anonymous")
            FirestoreManager.Instance?.LogPageViewed(userId, bookId, pageId, animalName);
        else
            LocalEventBuffer.Instance?.AddPageView(bookId, pageId, animalName);

        Debug.Log($"[Analytics] page_viewed — {bookId}/{pageId}");
    }

    public void LogAnimalDiscovered(string bookId, string pageId, string animalName)
    {
        string userId = GetUserId();

        if (userId != "anonymous")
            FirestoreManager.Instance?.LogAnimalDiscovered(userId, bookId, pageId, animalName);
        else
            LocalEventBuffer.Instance?.AddAnimalDiscovered(bookId, pageId, animalName);

        Debug.Log($"[Analytics] animal_discovered — {animalName}");
    }

    public void LogBookDetected(string bookId, float timeToDetect) =>
        Debug.Log($"[Analytics] book_detected — {bookId} ({timeToDetect:F1}s)");

    public void LogBookLost(string bookId, float duration) =>
        Debug.Log($"[Analytics] book_lost — {bookId} ({duration:F1}s)");

    // ════════════════════════════════════════════════════════
    // MAP 3D — NŒUDS
    // ════════════════════════════════════════════════════════

    public void LogMapNodeExplored(string nodeId)
    {
        string userId = GetUserId();

        if (userId != "anonymous")
            FirestoreManager.Instance?.LogMapNodeExplored(userId, nodeId);
        else
            LocalEventBuffer.Instance?.AddMapNodeExplored(nodeId);

        Debug.Log($"[Analytics] map_node_explored — {nodeId}");
    }

    // ════════════════════════════════════════════════════════
    // ACTIVITÉS
    // ════════════════════════════════════════════════════════

    public void LogActivityCompleted(string activityId, int score)
    {
        string userId = GetUserId();

        if (userId != "anonymous")
            FirestoreManager.Instance?.LogActivityCompleted(userId, activityId, score);
        else
            LocalEventBuffer.Instance?.AddActivityCompleted(activityId, score);

        Debug.Log($"[Analytics] activity_completed — {activityId} score={score}");
    }

    // ════════════════════════════════════════════════════════
    // AUTH
    // ════════════════════════════════════════════════════════

    public void LogUserLoggedIn(string method) =>
        Debug.Log($"[Analytics] user_logged_in — {method}");

    public void LogUserSignedUp(string method) =>
        Debug.Log($"[Analytics] user_signed_up — {method}");

    // ════════════════════════════════════════════════════════
    // HELPER
    // ════════════════════════════════════════════════════════

    private string GetUserId()
    {
        var user = Firebase.Auth.FirebaseAuth.DefaultInstance.CurrentUser;
        if (user != null && !user.IsAnonymous)
            return user.UserId;
        return "anonymous";
    }
}*/


