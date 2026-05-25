using System;
using System.Collections.Generic;
using UnityEngine;
using Firebase.Firestore;

public class FirestoreManager : MonoBehaviour
{
    public static FirestoreManager Instance { get; private set; }
    private FirebaseFirestore _db;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        _db = FirebaseFirestore.DefaultInstance;
        Debug.Log("[Firestore] ✅ Initialisé — db = " + (_db != null ? "OK" : "NULL"));
    }

    private Timestamp FromUnixMs(long unixMs)
    {
        DateTime epoch = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
        return Timestamp.FromDateTime(epoch.AddMilliseconds(unixMs));
    }

    private Timestamp ResolveTimestamp(long timestampMs)
        => timestampMs > 0 ? FromUnixMs(timestampMs) : Timestamp.GetCurrentTimestamp();

    // ══════════════════════════════════════════════════════════
    // PAGE VIEW
    // ══════════════════════════════════════════════════════════
    public void LogPageViewed(string userId, string bookId, string themeId,
                              string pageId, long timestampMs = 0)
    {
        if (_db == null) return;
        var data = new Dictionary<string, object>
        {
            { "userId", userId }, { "bookId", bookId }, { "themeId", themeId },
            { "pageId", pageId }, { "timestamp", ResolveTimestamp(timestampMs) }
        };
        _db.Collection("page_views").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted) Debug.LogError("[Firestore] ❌ page_viewed : " + task.Exception?.InnerException?.Message);
            else Debug.Log($"[Firestore] ✅ page_viewed — {bookId}/{themeId}/{pageId}");
        });
    }

    // ══════════════════════════════════════════════════════════
    // ITEM DISCOVERED
    // ══════════════════════════════════════════════════════════
    public void LogItemDiscovered(string userId, string bookId, string themeId,
                                  string pageId, string itemName, long timestampMs = 0)
    {
        if (_db == null) return;
        var data = new Dictionary<string, object>
        {
            { "userId", userId }, { "bookId", bookId }, { "themeId", themeId },
            { "pageId", pageId }, { "itemName", itemName },
            { "timestamp", ResolveTimestamp(timestampMs) }
        };
        _db.Collection("items_discovered").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted) Debug.LogError("[Firestore] ❌ item_discovered : " + task.Exception?.InnerException?.Message);
            else Debug.Log($"[Firestore] ✅ item_discovered — {itemName}");
        });
    }

    // ══════════════════════════════════════════════════════════
    // SESSION GLOBALE
    // ══════════════════════════════════════════════════════════
    public void LogSessionTime(string userId, float durationSeconds, long timestampMs = 0)
    {
        if (_db == null) return;
        var data = new Dictionary<string, object>
        {
            { "userId", userId },
            { "durationSeconds", Mathf.RoundToInt(durationSeconds) },
            { "timestamp", ResolveTimestamp(timestampMs) }
        };
        _db.Collection("sessions").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted) Debug.LogError("[Firestore] ❌ session : " + task.Exception?.InnerException?.Message);
            else Debug.Log($"[Firestore] ✅ session — {durationSeconds:F0}s");
        });
    }

    // ══════════════════════════════════════════════════════════
    // CHILD SESSION
    // ══════════════════════════════════════════════════════════
    public void LogChildSession(string userId, string mode,
                                float durationSeconds, long timestampMs = 0)
    {
        if (_db == null) return;
        var data = new Dictionary<string, object>
        {
            { "userId", userId }, { "mode", mode },
            { "durationSeconds", Mathf.RoundToInt(durationSeconds) },
            { "timestamp", ResolveTimestamp(timestampMs) }
        };
        _db.Collection("child_sessions").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted) Debug.LogError("[Firestore] ❌ child_session : " + task.Exception?.InnerException?.Message);
            else Debug.Log($"[Firestore] ✅ child_session — {mode} {durationSeconds:F0}s");
        });
    }

    // ══════════════════════════════════════════════════════════
    // ACTIVITY SESSION
    // ══════════════════════════════════════════════════════════
    public void LogActivitySession(string userId, string bookId, string themeId,
                                   string activityId, float durationSeconds, long timestampMs = 0)
    {
        if (_db == null) return;
        var data = new Dictionary<string, object>
        {
            { "userId", userId }, { "bookId", bookId }, { "themeId", themeId },
            { "activityId", activityId },
            { "durationSeconds", Mathf.RoundToInt(durationSeconds) },
            { "timestamp", ResolveTimestamp(timestampMs) }
        };
        _db.Collection("activity_sessions").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted) Debug.LogError("[Firestore] ❌ activity_session : " + task.Exception?.InnerException?.Message);
            else Debug.Log($"[Firestore] ✅ activity_session — {bookId}/{themeId}/{activityId} {durationSeconds:F0}s");
        });
    }

    // ══════════════════════════════════════════════════════════
    // QUIZ SCORE
    // ══════════════════════════════════════════════════════════
    public void LogQuizScore(string userId, string bookId, string themeId,
                             int score, int totalQuestions, long timestampMs = 0)
    {
        if (_db == null) return;
        var data = new Dictionary<string, object>
        {
            { "userId", userId }, { "bookId", bookId }, { "themeId", themeId },
            { "score", score }, { "totalQuestions", totalQuestions },
            { "timestamp", ResolveTimestamp(timestampMs) }
        };
        _db.Collection("quiz_scores").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted) Debug.LogError("[Firestore] ❌ quiz_score : " + task.Exception?.InnerException?.Message);
            else Debug.Log($"[Firestore] ✅ quiz_score — {bookId}/{themeId} {score}/{totalQuestions}");
        });
    }

    // ══════════════════════════════════════════════════════════
    // READ — IsItemDiscovered
    // ══════════════════════════════════════════════════════════
    public void IsItemDiscovered(string userId, string itemName, System.Action<bool> callback)
    {
        if (_db == null) { callback?.Invoke(false); return; }

        _db.Collection("items_discovered")
           .WhereEqualTo("userId", userId)
           .WhereEqualTo("itemName", itemName)
           .GetSnapshotAsync().ContinueWith(task =>
        {
            if (task.IsFaulted) { callback?.Invoke(false); return; }
            callback?.Invoke(task.Result.Count > 0);
        });
    }

    // ══════════════════════════════════════════════════════════
    // READ — IsActivityCompleted
    // ══════════════════════════════════════════════════════════
    public void IsActivityCompleted(string userId, string bookId, string themeId,
                                    string activityId, System.Action<bool> callback)
    {
        if (_db == null) { callback?.Invoke(false); return; }

        _db.Collection("activity_sessions")
           .WhereEqualTo("userId", userId)
           .WhereEqualTo("bookId", bookId)
           .WhereEqualTo("themeId", themeId)
           .WhereEqualTo("activityId", activityId)
           .GetSnapshotAsync().ContinueWith(task =>
        {
            if (task.IsFaulted) { callback?.Invoke(false); return; }
            callback?.Invoke(task.Result.Count > 0);
        });
    }

    // ══════════════════════════════════════════════════════════
    // SYNC LOCAL → FIRESTORE
    // ══════════════════════════════════════════════════════════
    public void SyncLocalBuffer(string userId, System.Action onComplete = null)
{
    var events = LocalEventBuffer.Instance?.GetAll();
    Debug.Log($"[Firestore] SyncLocalBuffer — events count = {events?.Count ?? 0}");
    
    if (events == null || events.Count == 0)
    {   
        Debug.Log("[Firestore] Rien à sync");
        onComplete?.Invoke();
        return;
    }

    Debug.Log($"[Firestore] 🔄 Sync {events.Count} events pour userId={userId}");

    int total     = events.Count;
    int completed = 0;

    foreach (var e in events)
    {
        System.Action onEachComplete = () =>
        {
            completed++;
            if (completed >= total)
            {
                LocalEventBuffer.Instance.Clear();
                Debug.Log("[Firestore] ✅ Sync terminée");
                onComplete?.Invoke();
            }
        };

        switch (e.type)
        {
            case "page_view":
                _db.Collection("page_views").AddAsync(BuildPageViewData(userId, e)).ContinueWith(t => onEachComplete());
                break;
            case "session":
                _db.Collection("sessions").AddAsync(BuildSessionData(userId, e)).ContinueWith(t => onEachComplete());
                break;
            case "child_session":
                _db.Collection("child_sessions").AddAsync(BuildChildSessionData(userId, e)).ContinueWith(t => onEachComplete());
                break;
            case "item_discovered":
                _db.Collection("items_discovered").AddAsync(BuildItemDiscoveredData(userId, e)).ContinueWith(t => onEachComplete());
                break;
            case "activity_session":
                _db.Collection("activity_sessions").AddAsync(BuildActivitySessionData(userId, e)).ContinueWith(t => onEachComplete());
                break;
            case "quiz_score":
                _db.Collection("quiz_scores").AddAsync(BuildQuizScoreData(userId, e)).ContinueWith(t => onEachComplete());
                break;
            default:
                Debug.LogWarning($"[Firestore] ⚠️ type inconnu : {e.type}");
                onEachComplete();
                break;
        }
    }
}

// ── Helpers data builders ─────────────────────────────────

private Dictionary<string, object> BuildPageViewData(string userId, LocalEvent e) =>
    new Dictionary<string, object>
    {
        { "userId", userId }, { "bookId", e.bookId }, { "themeId", e.themeId },
        { "pageId", e.pageId }, { "timestamp", ResolveTimestamp(e.timestamp) }
    };

private Dictionary<string, object> BuildSessionData(string userId, LocalEvent e) =>
    new Dictionary<string, object>
    {
        { "userId", userId },
        { "durationSeconds", Mathf.RoundToInt(e.durationSeconds) },
        { "timestamp", ResolveTimestamp(e.timestamp) }
    };

private Dictionary<string, object> BuildChildSessionData(string userId, LocalEvent e) =>
    new Dictionary<string, object>
    {
        { "userId", userId }, { "mode", e.mode },
        { "durationSeconds", Mathf.RoundToInt(e.durationSeconds) },
        { "timestamp", ResolveTimestamp(e.timestamp) }
    };

private Dictionary<string, object> BuildItemDiscoveredData(string userId, LocalEvent e) =>
    new Dictionary<string, object>
    {
        { "userId", userId }, { "bookId", e.bookId }, { "themeId", e.themeId },
        { "pageId", e.pageId }, { "itemName", e.itemName },
        { "timestamp", ResolveTimestamp(e.timestamp) }
    };

private Dictionary<string, object> BuildActivitySessionData(string userId, LocalEvent e) =>
    new Dictionary<string, object>
    {
        { "userId", userId }, { "bookId", e.bookId }, { "themeId", e.themeId },
        { "activityId", e.activityId },
        { "durationSeconds", Mathf.RoundToInt(e.durationSeconds) },
        { "timestamp", ResolveTimestamp(e.timestamp) }
    };

private Dictionary<string, object> BuildQuizScoreData(string userId, LocalEvent e) =>
    new Dictionary<string, object>
    {
        { "userId", userId }, { "bookId", e.bookId }, { "themeId", e.themeId },
        { "score", e.score }, { "totalQuestions", e.totalQuestions },
        { "timestamp", ResolveTimestamp(e.timestamp) }
    };
}
/*using System;
using System.Collections.Generic;
using UnityEngine;
using Firebase.Firestore;

public class FirestoreManager : MonoBehaviour
{
    public static FirestoreManager Instance { get; private set; }
    private FirebaseFirestore _db;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        _db = FirebaseFirestore.DefaultInstance;
        Debug.Log("[Firestore] ✅ Initialisé — db = " + (_db != null ? "OK" : "NULL"));
    }

    // ══════════════════════════════════════════════════════════
    // HELPER — Convert Unix ms → Firestore Timestamp
    // ══════════════════════════════════════════════════════════
    private Timestamp FromUnixMs(long unixMs)
    {
        DateTime epoch = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
        DateTime dt = epoch.AddMilliseconds(unixMs);
        return Timestamp.FromDateTime(dt);
    }

    private Timestamp ResolveTimestamp(long timestampMs)
        => timestampMs > 0 ? FromUnixMs(timestampMs) : Timestamp.GetCurrentTimestamp();

    // ══════════════════════════════════════════════════════════
    // PAGE VIEW
    // ══════════════════════════════════════════════════════════
    public void LogPageViewed(string userId, string bookId, string themeId,
                              string pageId, long timestampMs = 0)
    {
        if (_db == null) { Debug.LogError("[Firestore] ❌ db null"); return; }

        var data = new Dictionary<string, object>
        {
            { "userId",    userId },
            { "bookId",    bookId },
            { "themeId",   themeId },
            { "pageId",    pageId },
            { "timestamp", ResolveTimestamp(timestampMs) }
        };

        _db.Collection("page_views").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ page_viewed : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ page_viewed — {bookId}/{themeId}/{pageId}");
        });
    }

    // ══════════════════════════════════════════════════════════
    // ITEM DISCOVERED
    // ══════════════════════════════════════════════════════════
    public void LogItemDiscovered(string userId, string bookId, string themeId,
                                  string pageId, string itemName, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",    userId },
            { "bookId",    bookId },
            { "themeId",   themeId },
            { "pageId",    pageId },
            { "itemName",  itemName },
            { "timestamp", ResolveTimestamp(timestampMs) }
        };

        _db.Collection("items_discovered").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ item_discovered : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ item_discovered — {itemName}");
        });
    }

    // ══════════════════════════════════════════════════════════
    // SESSION GLOBALE
    // ══════════════════════════════════════════════════════════
    public void LogSessionTime(string userId, float durationSeconds, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",          userId },
            { "durationSeconds", Mathf.RoundToInt(durationSeconds) },
            { "timestamp",       ResolveTimestamp(timestampMs) }
        };

        _db.Collection("sessions").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ session : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ session — {durationSeconds:F0}s");
        });
    }

    // ══════════════════════════════════════════════════════════
    // CHILD SESSION (AR / 3D / Activity)
    // ══════════════════════════════════════════════════════════
    public void LogChildSession(string userId, string mode,
                                float durationSeconds, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",          userId },
            { "mode",            mode },
            { "durationSeconds", Mathf.RoundToInt(durationSeconds) },
            { "timestamp",       ResolveTimestamp(timestampMs) }
        };

        _db.Collection("child_sessions").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ child_session : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ child_session — {mode} {durationSeconds:F0}s");
        });
    }

    // ══════════════════════════════════════════════════════════
    // ACTIVITY SESSION
    // ══════════════════════════════════════════════════════════
    public void LogActivitySession(string userId, string bookId, string themeId,
                                   string activityId, float durationSeconds, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",          userId },
            { "bookId",          bookId },
            { "themeId",         themeId },
            { "activityId",      activityId },
            { "durationSeconds", Mathf.RoundToInt(durationSeconds) },
            { "timestamp",       ResolveTimestamp(timestampMs) }
        };

        _db.Collection("activity_sessions").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ activity_session : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ activity_session — {bookId}/{themeId}/{activityId} {durationSeconds:F0}s");
        });
    }

    // ══════════════════════════════════════════════════════════
    // QUIZ SCORE
    // ══════════════════════════════════════════════════════════
    public void LogQuizScore(string userId, string bookId, string themeId,
                             int score, int totalQuestions, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",         userId },
            { "bookId",         bookId },
            { "themeId",        themeId },
            { "score",          score },
            { "totalQuestions", totalQuestions },
            { "timestamp",      ResolveTimestamp(timestampMs) }
        };

        _db.Collection("quiz_scores").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ quiz_score : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ quiz_score — {bookId}/{themeId} {score}/{totalQuestions}");
        });
    }

    // ══════════════════════════════════════════════════════════
    // CHILD PROGRESS — SAVE
    // ══════════════════════════════════════════════════════════
    public void SaveChildProgress(string userId, ChildProgress progress)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "exploredNodes",       progress.exploredNodes },
            { "completedActivities", progress.completedActivities },
            { "lastUpdated",         progress.lastUpdated }
        };

        _db.Collection("child_progress").Document(userId).SetAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ child_progress save : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log("[Firestore] ✅ child_progress sauvegardé");
        });
    }

    // ══════════════════════════════════════════════════════════
    // CHILD PROGRESS — LOAD
    // ══════════════════════════════════════════════════════════
    public void LoadChildProgress(string userId, System.Action<ChildProgress> onLoaded)
    {
        if (_db == null) { onLoaded?.Invoke(null); return; }

        _db.Collection("child_progress").Document(userId).GetSnapshotAsync().ContinueWith(task =>
        {
            if (task.IsFaulted)
            {
                Debug.LogError("[Firestore] ❌ child_progress load : " + task.Exception?.InnerException?.Message);
                onLoaded?.Invoke(null);
                return;
            }

            DocumentSnapshot snapshot = task.Result;
            if (!snapshot.Exists) { onLoaded?.Invoke(null); return; }

            ChildProgress progress = new ChildProgress();

            if (snapshot.TryGetValue("exploredNodes", out List<string> nodes))
                progress.exploredNodes = nodes;

            if (snapshot.TryGetValue("completedActivities", out List<string> activities))
                progress.completedActivities = activities;

            if (snapshot.TryGetValue("lastUpdated", out long lastUpdated))
                progress.lastUpdated = lastUpdated;

            Debug.Log($"[Firestore] ✅ child_progress chargé — " +
                      $"{progress.exploredNodes.Count} nœuds | " +
                      $"{progress.completedActivities.Count} activités");

            onLoaded?.Invoke(progress);
        });
    }

    // ══════════════════════════════════════════════════════════
    // SYNC LOCAL → FIRESTORE
    // ══════════════════════════════════════════════════════════
    public void SyncLocalBuffer(string userId)
    {
        var events = LocalEventBuffer.Instance?.GetAll();
        if (events == null || events.Count == 0)
        {
            Debug.Log("[Firestore] Rien à sync");
            return;
        }

        Debug.Log($"[Firestore] 🔄 Sync {events.Count} events pour userId={userId}");

        foreach (var e in events)
        {
            switch (e.type)
            {
                case "page_view":
                    LogPageViewed(userId, e.bookId, e.themeId, e.pageId, e.timestamp);
                    break;
                case "session":
                    LogSessionTime(userId, e.durationSeconds, e.timestamp);
                    break;
                case "child_session":
                    LogChildSession(userId, e.mode, e.durationSeconds, e.timestamp);
                    break;
                case "item_discovered":
                    LogItemDiscovered(userId, e.bookId, e.themeId, e.pageId, e.itemName, e.timestamp);
                    break;
                case "activity_session":
                    LogActivitySession(userId, e.bookId, e.themeId, e.activityId, e.durationSeconds, e.timestamp);
                    break;
                case "quiz_score":
                    LogQuizScore(userId, e.bookId, e.themeId, e.score, e.totalQuestions, e.timestamp);
                    break;
                default:
                    Debug.LogWarning($"[Firestore] ⚠️ type inconnu ignoré : {e.type}");
                    break;
            }
        }

        LocalEventBuffer.Instance.Clear();
    }
}
/*using System;
using System.Collections.Generic;
using UnityEngine;
using Firebase.Firestore;

public class FirestoreManager : MonoBehaviour
{
    public static FirestoreManager Instance { get; private set; }
    private FirebaseFirestore _db;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        _db = FirebaseFirestore.DefaultInstance;
        Debug.Log("[Firestore] ✅ Initialisé — db = " + (_db != null ? "OK" : "NULL"));
    }

    // ══════════════════════════════════════════════════════════
    // HELPER — Convert Unix ms → Firestore Timestamp
    // ══════════════════════════════════════════════════════════
    private Timestamp FromUnixMs(long unixMs)
    {
        DateTime epoch = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
        DateTime dt = epoch.AddMilliseconds(unixMs);
        return Timestamp.FromDateTime(dt);
    }

    private Timestamp ResolveTimestamp(long timestampMs)
        => timestampMs > 0 ? FromUnixMs(timestampMs) : Timestamp.GetCurrentTimestamp();

    // ══════════════════════════════════════════════════════════
    // PAGE VIEW
    // ══════════════════════════════════════════════════════════
    public void LogPageViewed(string userId, string bookId, string themeId,
                              string pageId, long timestampMs = 0)
    {
        if (_db == null) { Debug.LogError("[Firestore] ❌ db null"); return; }

        var data = new Dictionary<string, object>
        {
            { "userId",    userId },
            { "bookId",    bookId },
            { "themeId",   themeId },
            { "pageId",    pageId },
            { "timestamp", ResolveTimestamp(timestampMs) }
        };

        _db.Collection("page_views").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ page_viewed : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ page_viewed — {bookId}/{themeId}/{pageId}");
        });
    }

    // ══════════════════════════════════════════════════════════
    // ITEM DISCOVERED
    // ══════════════════════════════════════════════════════════
    public void LogItemDiscovered(string userId, string bookId, string themeId,
                                  string pageId, string itemName, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",    userId },
            { "bookId",    bookId },
            { "themeId",   themeId },
            { "pageId",    pageId },
            { "itemName",  itemName },
            { "timestamp", ResolveTimestamp(timestampMs) }
        };

        _db.Collection("items_discovered").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ item_discovered : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ item_discovered — {itemName}");
        });
    }

    // ══════════════════════════════════════════════════════════
    // SESSION GLOBALE
    // ══════════════════════════════════════════════════════════
    public void LogSessionTime(string userId, float durationSeconds, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",          userId },
            { "durationSeconds", Mathf.RoundToInt(durationSeconds) },
            { "timestamp",       ResolveTimestamp(timestampMs) }
        };

        _db.Collection("sessions").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ session : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ session — {durationSeconds:F0}s");
        });
    }

    // ══════════════════════════════════════════════════════════
    // CHILD SESSION (AR / 3D / Activity)
    // ══════════════════════════════════════════════════════════
    public void LogChildSession(string userId, string mode,
                                float durationSeconds, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",          userId },
            { "mode",            mode },
            { "durationSeconds", Mathf.RoundToInt(durationSeconds) },
            { "timestamp",       ResolveTimestamp(timestampMs) }
        };

        _db.Collection("child_sessions").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ child_session : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ child_session — {mode} {durationSeconds:F0}s");
        });
    }

    // ══════════════════════════════════════════════════════════
    // ACTIVITY SESSION (temps passé dans une activité)
    // ══════════════════════════════════════════════════════════
    public void LogActivitySession(string userId, string bookId, string themeId,
                                   string activityId, float durationSeconds, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",          userId },
            { "bookId",          bookId },
            { "themeId",         themeId },
            { "activityId",      activityId },
            { "durationSeconds", Mathf.RoundToInt(durationSeconds) },
            { "timestamp",       ResolveTimestamp(timestampMs) }
        };

        _db.Collection("activity_sessions").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ activity_session : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ activity_session — {bookId}/{themeId}/{activityId} {durationSeconds:F0}s");
        });
    }

    public void LogQuizScore(string userId, string bookId, string themeId,
                         int score, int totalQuestions, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",         userId },
            { "bookId",         bookId },
            { "themeId",        themeId },
            { "score",          score },
            { "totalQuestions", totalQuestions },
            { "timestamp",      ResolveTimestamp(timestampMs) }
        };

        _db.Collection("quiz_scores").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ quiz_score : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ quiz_score — {bookId}/{themeId} {score}/{totalQuestions}");
        });
    }
    

    // ══════════════════════════════════════════════════════════
    // SYNC LOCAL → FIRESTORE
    // ══════════════════════════════════════════════════════════
    public void SyncLocalBuffer(string userId)
    {
        var events = LocalEventBuffer.Instance?.GetAll();
        if (events == null || events.Count == 0)
        {
            Debug.Log("[Firestore] Rien à sync");
            return;
        }

        Debug.Log($"[Firestore] 🔄 Sync {events.Count} events pour userId={userId}");

        foreach (var e in events)
        {
            switch (e.type)
            {
                case "page_view":
                    LogPageViewed(userId, e.bookId, e.themeId, e.pageId, e.timestamp);
                    break;
                case "session":
                    LogSessionTime(userId, e.durationSeconds, e.timestamp);
                    break;
                case "child_session":
                    LogChildSession(userId, e.mode, e.durationSeconds, e.timestamp);
                    break;
                case "item_discovered":
                    LogItemDiscovered(userId, e.bookId, e.themeId, e.pageId, e.itemName, e.timestamp);
                    break;
                case "activity_session":
                    LogActivitySession(userId, e.bookId, e.themeId, e.activityId, e.durationSeconds, e.timestamp);
                    break;
                case "quiz_score":
                    LogQuizScore(userId, e.bookId, e.themeId, e.score, e.totalQuestions, e.timestamp);
                    break;
                default:
                    Debug.LogWarning($"[Firestore] ⚠️ type inconnu ignoré : {e.type}");
                    break;
            }
        }

        LocalEventBuffer.Instance.Clear();
    }
}
/*using System;
using System.Collections.Generic;
using UnityEngine;
using Firebase.Firestore;

public class FirestoreManager : MonoBehaviour
{
    public static FirestoreManager Instance { get; private set; }
    private FirebaseFirestore _db;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        _db = FirebaseFirestore.DefaultInstance;
        Debug.Log("[Firestore] ✅ Initialisé — db = " + (_db != null ? "OK" : "NULL"));
    }

    // ══════════════════════════════════════════════════════════
    // HELPER — Convert Unix ms → Firestore Timestamp
    // ══════════════════════════════════════════════════════════
    private Timestamp FromUnixMs(long unixMs)
    {
        DateTime epoch = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
        DateTime dt = epoch.AddMilliseconds(unixMs);
        return Timestamp.FromDateTime(dt);
    }

    private Timestamp ResolveTimestamp(long timestampMs)
        => timestampMs > 0 ? FromUnixMs(timestampMs) : Timestamp.GetCurrentTimestamp();

    // ══════════════════════════════════════════════════════════
    // PAGE VIEW
    // ══════════════════════════════════════════════════════════
    public void LogPageViewed(string userId, string bookId, string pageId,
                              string animalName, long timestampMs = 0)
    {
        if (_db == null) { Debug.LogError("[Firestore] ❌ db null"); return; }

        var data = new Dictionary<string, object>
        {
            { "userId",     userId },
            { "bookId",     bookId },
            { "pageId",     pageId },
            { "animalName", animalName },
            { "timestamp",  ResolveTimestamp(timestampMs) }
        };

        _db.Collection("page_views").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ page_viewed : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ page_viewed — {bookId}/{pageId}");
        });
    }

    // ══════════════════════════════════════════════════════════
    // SESSION GLOBALE
    // ══════════════════════════════════════════════════════════
    public void LogSessionTime(string userId, float durationSeconds, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",          userId },
            { "durationSeconds", Mathf.RoundToInt(durationSeconds) },
            { "timestamp",       ResolveTimestamp(timestampMs) }
        };

        _db.Collection("sessions").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ session : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ session — {durationSeconds:F0}s");
        });
    }

    // ══════════════════════════════════════════════════════════
    // CHILD SESSION (AR / 3D / Activity)
    // ══════════════════════════════════════════════════════════
    public void LogChildSession(string userId, string mode,
                                float durationSeconds, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",          userId },
            { "mode",            mode },
            { "durationSeconds", Mathf.RoundToInt(durationSeconds) },
            { "timestamp",       ResolveTimestamp(timestampMs) }
        };

        _db.Collection("child_sessions").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ child_session : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ child_session — {mode} {durationSeconds:F0}s");
        });
    }

    // ══════════════════════════════════════════════════════════
    // ANIMAL DISCOVERED
    // ══════════════════════════════════════════════════════════
    public void LogAnimalDiscovered(string userId, string bookId, string pageId,
                                    string animalName, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",     userId },
            { "bookId",     bookId },
            { "pageId",     pageId },
            { "animalName", animalName },
            { "timestamp",  ResolveTimestamp(timestampMs) }
        };

        _db.Collection("animals_discovered").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ animal_discovered : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ animal_discovered — {animalName}");
        });
    }

    // ══════════════════════════════════════════════════════════
    // MAP NODE
    // ══════════════════════════════════════════════════════════
    public void LogMapNodeExplored(string userId, string nodeId, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",    userId },
            { "nodeId",    nodeId },
            { "timestamp", ResolveTimestamp(timestampMs) }
        };

        _db.Collection("map_nodes").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ map_node : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ map_node — {nodeId}");
        });
    }

    // ══════════════════════════════════════════════════════════
    // ACTIVITY COMPLETED
    // ══════════════════════════════════════════════════════════
    public void LogActivityCompleted(string userId, string activityId,
                                     int score, long timestampMs = 0)
    {
        if (_db == null) return;

        var data = new Dictionary<string, object>
        {
            { "userId",     userId },
            { "activityId", activityId },
            { "score",      score },
            { "timestamp",  ResolveTimestamp(timestampMs) }
        };

        _db.Collection("activities").AddAsync(data).ContinueWith(task =>
        {
            if (task.IsFaulted)
                Debug.LogError("[Firestore] ❌ activity : " + task.Exception?.InnerException?.Message);
            else
                Debug.Log($"[Firestore] ✅ activity_completed — {activityId}");
        });
    }

    // ══════════════════════════════════════════════════════════
    // SYNC LOCAL → FIRESTORE
    // Passe le timestamp réel de chaque event sauvé en local
    // ══════════════════════════════════════════════════════════
    public void SyncLocalBuffer(string userId)
    {
        var events = LocalEventBuffer.Instance?.GetAll();
        if (events == null || events.Count == 0)
        {
            Debug.Log("[Firestore] Rien à sync");
            return;
        }

        Debug.Log($"[Firestore] 🔄 Sync {events.Count} events pour userId={userId}");

        foreach (var e in events)
        {
            switch (e.type)
            {
                case "page_view":
                    LogPageViewed(userId, e.bookId, e.pageId, e.animalName, e.timestamp);
                    break;
                case "session":
                    LogSessionTime(userId, e.durationSeconds, e.timestamp);
                    break;
                case "child_session":
                    LogChildSession(userId, e.mode, e.durationSeconds, e.timestamp);
                    break;
                case "animal_discovered":
                    LogAnimalDiscovered(userId, e.bookId, e.pageId, e.animalName, e.timestamp);
                    break;
                case "map_node_explored":
                    LogMapNodeExplored(userId, e.nodeId, e.timestamp);
                    break;
                case "activity_completed":
                    LogActivityCompleted(userId, e.activityId, e.score, e.timestamp);
                    break;
                default:
                    Debug.LogWarning($"[Firestore] ⚠️ type inconnu ignoré : {e.type}");
                    break;
            }
        }

        LocalEventBuffer.Instance.Clear();
    }
}*/