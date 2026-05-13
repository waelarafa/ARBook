////////////////////////////////////
///remplacer PlayerPrefs par ES3
///// EasySave3 
///////////////////////////////////////

using System;
using System.Collections.Generic;
using UnityEngine;

[Serializable]
public class LocalEvent
{
    public string type;           // "page_view" | "session" | "child_session"
                                  // | "animal_discovered" | "map_node_explored"
                                  // | "activity_completed"
                                  // ── Commun ───────────────────────────────────────────────
    public long timestamp;        // Unix ms — horodatage réel de l'event

    // ── Page view / Animal ────────────────────────────────────
    public string bookId;
    public string pageId;
    public string animalName;

    // ── Session enfant ────────────────────────────────────────
    public string mode;           // "AR" | "3D" | "Activity"
    public float durationSeconds;

    // ── Map 3D ───────────────────────────────────────────────
    public string nodeId;

    // ── Activité ─────────────────────────────────────────────
    public string activityId;
    public int score;
}

[Serializable]
public class LocalEventList
{
    public List<LocalEvent> events = new List<LocalEvent>();
}

public class LocalEventBuffer : MonoBehaviour
{
    public static LocalEventBuffer Instance { get; private set; }

    private const string ES3_KEY = "local_events";
    private LocalEventList _buffer;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        Load();
    }

    // ══════════════════════════════════════════════════════════
    // PERSISTANCE ES3
    // ══════════════════════════════════════════════════════════

    void Load()
    {
        if (ES3.KeyExists(ES3_KEY))
        {
            _buffer = new LocalEventList();
            _buffer.events = ES3.Load<List<LocalEvent>>(ES3_KEY);
        }
        else
        {
            _buffer = new LocalEventList();
        }
        Debug.Log($"[LocalBuffer] 📂 {_buffer.events.Count} events chargés (ES3)");
    }

    void Save()
    {
        ES3.Save(ES3_KEY, _buffer.events);
        Debug.Log($"[LocalBuffer] 💾 {_buffer.events.Count} events sauvés (ES3)");
    }

    // ══════════════════════════════════════════════════════════
    // API PUBLIQUE
    // ══════════════════════════════════════════════════════════

    public void AddPageView(string bookId, string pageId, string animalName)
    {
        _buffer.events.Add(new LocalEvent
        {
            type = "page_view",
            bookId = bookId,
            pageId = pageId,
            animalName = animalName,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ page_view — {bookId}/{pageId}");
    }

    public void AddSession(float durationSeconds)
    {
        _buffer.events.Add(new LocalEvent
        {
            type = "session",
            durationSeconds = durationSeconds,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ session — {durationSeconds:F0}s");
    }

    public void AddChildSession(string mode, float durationSeconds)
    {
        _buffer.events.Add(new LocalEvent
        {
            type = "child_session",
            mode = mode,
            durationSeconds = durationSeconds,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ child_session — {mode} {durationSeconds:F0}s");
    }

    public void AddAnimalDiscovered(string bookId, string pageId, string animalName)
    {
        _buffer.events.Add(new LocalEvent
        {
            type = "animal_discovered",
            bookId = bookId,
            pageId = pageId,
            animalName = animalName,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ animal_discovered — {animalName}");
    }

    public void AddMapNodeExplored(string nodeId)
    {
        _buffer.events.Add(new LocalEvent
        {
            type = "map_node_explored",
            nodeId = nodeId,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ map_node_explored — {nodeId}");
    }

    public void AddActivityCompleted(string activityId, int score)
    {
        _buffer.events.Add(new LocalEvent
        {
            type = "activity_completed",
            activityId = activityId,
            score = score,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ activity_completed — {activityId} score={score}");
    }

    public List<LocalEvent> GetAll() => new List<LocalEvent>(_buffer.events);

    public void Clear()
    {
        _buffer.events.Clear();
        Save();
        Debug.Log("[LocalBuffer] 🧹 Buffer vidé après sync");
    }
}

/////////////////////////////////////
//Stockage local par PlayerPrefs 
//////////////////////////////////////
/*using System;
using System.Collections.Generic;
using UnityEngine;

[Serializable]
public class LocalEvent
{
    public string type;       // "page_view" | "session"
    public string bookId;
    public string pageId;
    public string animalName;
    public float durationSeconds;
    public long timestamp;    // Unix ms
}

[Serializable]
public class LocalEventList
{
    public List<LocalEvent> events = new List<LocalEvent>();
}

public class LocalEventBuffer : MonoBehaviour
{
    public static LocalEventBuffer Instance { get; private set; }

    private const string PREFS_KEY = "local_events";
    private LocalEventList _buffer;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        Load();
    }

    void Load()
    {
        string json = PlayerPrefs.GetString(PREFS_KEY, "{\"events\":[]}");
        _buffer = JsonUtility.FromJson<LocalEventList>(json) ?? new LocalEventList();
        Debug.Log($"[LocalBuffer] {_buffer.events.Count} events en attente");
    }

    void Save()
    {
        PlayerPrefs.SetString(PREFS_KEY, JsonUtility.ToJson(_buffer));
        PlayerPrefs.Save();
    }

    public void AddPageView(string bookId, string pageId, string animalName)
    {
        _buffer.events.Add(new LocalEvent
        {
            type = "page_view",
            bookId = bookId,
            pageId = pageId,
            animalName = animalName,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ page_view sauvé local — {bookId}/{pageId}");
    }

    public void AddSession(float durationSeconds)
    {
        _buffer.events.Add(new LocalEvent
        {
            type = "session",
            durationSeconds = durationSeconds,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
    }

    public List<LocalEvent> GetAll() => new List<LocalEvent>(_buffer.events);

    public void Clear()
    {
        _buffer.events.Clear();
        Save();
        Debug.Log("[LocalBuffer] 🧹 Buffer vidé après sync");
    }
}*/