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
}