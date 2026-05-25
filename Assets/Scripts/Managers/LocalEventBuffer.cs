using System;
using System.Collections.Generic;
using UnityEngine;

[Serializable]
public class LocalEvent
{
    public string type;
    public long timestamp;
    public string bookId;
    public string themeId;
    public string pageId;
    public string itemName;
    public string mode;
    public float durationSeconds;
    public string activityId;
    public int score;
    public int totalQuestions;
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
    private const string ENCRYPTION_PASSWORD = "ARBook_2026_XkZ9!";
    private LocalEventList _buffer;

    private ES3Settings GetSettings() => new ES3Settings
    {
        encryptionType     = ES3.EncryptionType.AES,
        encryptionPassword = ENCRYPTION_PASSWORD
    };

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        Load();
    }

    void Load()
    {
        if (ES3.KeyExists(ES3_KEY, GetSettings()))
        {
            _buffer = new LocalEventList();
            _buffer.events = ES3.Load<List<LocalEvent>>(ES3_KEY, GetSettings());
        }
        else
        {
            _buffer = new LocalEventList();
        }
        Debug.Log($"[LocalBuffer] 📂 {_buffer.events.Count} events chargés");
    }

    void Save()
    {
        if (_buffer == null) _buffer = new LocalEventList();
        ES3.Save(ES3_KEY, _buffer.events, GetSettings());
        Debug.Log($"[LocalBuffer] 💾 {_buffer.events.Count} events sauvés");
    }

    // ══════════════════════════════════════════════════════════
    // ADD
    // ══════════════════════════════════════════════════════════

    public void AddPageView(string bookId, string themeId, string pageId)
    {
        if (_buffer == null) _buffer = new LocalEventList();
        _buffer.events.Add(new LocalEvent
        {
            type      = "page_view",
            bookId    = bookId,
            themeId   = themeId,
            pageId    = pageId,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
    }

    public void AddSession(float durationSeconds)
    {
        if (_buffer == null) _buffer = new LocalEventList();
        _buffer.events.Add(new LocalEvent
        {
            type            = "session",
            durationSeconds = durationSeconds,
            timestamp       = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
    }

    public void AddChildSession(string mode, float durationSeconds)
    {
        if (_buffer == null) _buffer = new LocalEventList();
        _buffer.events.Add(new LocalEvent
        {
            type            = "child_session",
            mode            = mode,
            durationSeconds = durationSeconds,
            timestamp       = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
    }

    public void AddItemDiscovered(string bookId, string themeId, string pageId, string itemName)
    {
        if (_buffer == null) _buffer = new LocalEventList();
        _buffer.events.Add(new LocalEvent
        {
            type      = "item_discovered",
            bookId    = bookId,
            themeId   = themeId,
            pageId    = pageId,
            itemName  = itemName,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ item_discovered — {itemName}");
    }

    public void AddActivitySession(string bookId, string themeId, string activityId, float durationSeconds)
    {
        if (_buffer == null) _buffer = new LocalEventList();
        _buffer.events.Add(new LocalEvent
        {
            type            = "activity_session",
            bookId          = bookId,
            themeId         = themeId,
            activityId      = activityId,
            durationSeconds = durationSeconds,
            timestamp       = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
    }

    public void AddQuizScore(string bookId, string themeId, int score, int totalQuestions)
    {
        if (_buffer == null) _buffer = new LocalEventList();
        _buffer.events.Add(new LocalEvent
        {
            type           = "quiz_score",
            bookId         = bookId,
            themeId        = themeId,
            score          = score,
            totalQuestions = totalQuestions,
            timestamp      = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
    }

    // ══════════════════════════════════════════════════════════
    // READ — pour LevelMapBuilder et ActivityMapManager
    // ══════════════════════════════════════════════════════════

    public bool IsItemDiscovered(string itemName)
    {
        if (_buffer == null) return false;
        return _buffer.events.Exists(e =>
            e.type == "item_discovered" && e.itemName == itemName);
    }

    public bool IsActivityCompleted(string bookId, string themeId, string activityId)
    {
        if (_buffer == null) return false;
        return _buffer.events.Exists(e =>
            e.type == "activity_session" &&
            e.bookId == bookId &&
            e.themeId == themeId &&
            e.activityId == activityId);
    }

    public List<LocalEvent> GetAll() => new List<LocalEvent>(_buffer?.events ?? new List<LocalEvent>());

    public void Clear()
    {
        if (_buffer == null) _buffer = new LocalEventList();
        _buffer.events.Clear();
        Save();
        Debug.Log("[LocalBuffer] 🧹 Buffer vidé");
    }
}


/*using System;
using System.Collections.Generic;
using UnityEngine;

[Serializable]
public class LocalEvent
{
    public string type;           // "page_view" | "session" | "child_session"
                                  // | "item_discovered" | "activity_session"
    // ── Commun ───────────────────────────────────────────────
    public long timestamp;        // Unix ms — horodatage réel de l'event

    // ── Page view / Item ──────────────────────────────────────
    public string bookId;
    public string themeId;
    public string pageId;
    public string itemName;

    // ── Session enfant ────────────────────────────────────────
    public string mode;           // "AR" | "3D" | "Activity"
    public float durationSeconds;

    // ── Activité session ─────────────────────────────────────
    public string activityId;
    public int score;
    public int totalQuestions;
}

[Serializable]
public class LocalEventList
{
    public List<LocalEvent> events = new List<LocalEvent>();
}

public class LocalEventBuffer : MonoBehaviour
{
    public static LocalEventBuffer Instance { get; private set; }

    private const string ES3_KEY = "local_events_v2";

    // ── Clé de chiffrement personnalisée ─────────────────────
    private const string ENCRYPTION_PASSWORD = "ARBook_2026_XkZ9!";

    // ── Propriété lazy — _buffer ne sera JAMAIS null ─────────
    private LocalEventList _bufferBacking;
    private LocalEventList _buffer
    {
        get
        {
            if (_bufferBacking == null)
            {
                Debug.LogWarning("[LocalBuffer] ⚠️ _buffer null, rechargement forcé...");
                Load();
            }
            return _bufferBacking;
        }
    }

    // ── Settings ES3 avec AES personnalisé ───────────────────
    private ES3Settings GetSettings()
    {
        return new ES3Settings
        {
            encryptionType     = ES3.EncryptionType.AES,
            encryptionPassword = ENCRYPTION_PASSWORD
        };
    }

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
        Debug.Log("[LocalBuffer] Load() appelé");
        try
        {
            if (ES3.KeyExists(ES3_KEY, GetSettings()))
            {
                _bufferBacking = new LocalEventList();
                _bufferBacking.events = ES3.Load<List<LocalEvent>>(ES3_KEY, GetSettings());

                if (_bufferBacking.events == null)
                    _bufferBacking.events = new List<LocalEvent>();
            }
            else
            {
                _bufferBacking = new LocalEventList();
            }
        }
        catch (Exception e)
        {
            Debug.LogWarning($"[LocalBuffer] ⚠️ Erreur chargement, reset: {e.Message}");
            _bufferBacking = new LocalEventList();
        }

        Debug.Log($"[LocalBuffer] 📂 {_bufferBacking.events.Count} events chargés (ES3)");
    }

    void Save()
    {
        try
        {
            ES3.Save(ES3_KEY, _buffer.events, GetSettings());
            Debug.Log($"[LocalBuffer] 💾 {_buffer.events.Count} events sauvés (ES3)");
        }
        catch (Exception e)
        {
            Debug.LogError($"[LocalBuffer] ❌ Erreur sauvegarde: {e.Message}");
        }
    }

    // ══════════════════════════════════════════════════════════
    // API PUBLIQUE
    // ══════════════════════════════════════════════════════════

    public void AddPageView(string bookId, string themeId, string pageId)
    {
        _buffer.events.Add(new LocalEvent
        {
            type      = "page_view",
            bookId    = bookId,
            themeId   = themeId,
            pageId    = pageId,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ page_view — {bookId}/{themeId}/{pageId}");
    }

    public void AddSession(float durationSeconds)
    {
        _buffer.events.Add(new LocalEvent
        {
            type            = "session",
            durationSeconds = durationSeconds,
            timestamp       = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ session — {durationSeconds:F0}s");
    }

    public void AddChildSession(string mode, float durationSeconds)
    {
        _buffer.events.Add(new LocalEvent
        {
            type            = "child_session",
            mode            = mode,
            durationSeconds = durationSeconds,
            timestamp       = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ child_session — {mode} {durationSeconds:F0}s");
    }

    public void AddItemDiscovered(string bookId, string themeId, string pageId, string itemName)
    {
        Debug.Log($"bookId: {bookId}, themeId: {themeId}, pageId: {pageId}, itemName: {itemName}");

        _buffer.events.Add(new LocalEvent
        {
            type      = "item_discovered",
            bookId    = bookId,
            themeId   = themeId,
            pageId    = pageId,
            itemName  = itemName,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ item_discovered — {itemName}");
    }

    public void AddActivitySession(string bookId, string themeId, string activityId, float durationSeconds)
    {
        _buffer.events.Add(new LocalEvent
        {
            type            = "activity_session",
            bookId          = bookId,
            themeId         = themeId,
            activityId      = activityId,
            durationSeconds = durationSeconds,
            timestamp       = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ activity_session — {bookId}/{themeId}/{activityId} {durationSeconds:F0}s");
    }

    public void AddQuizScore(string bookId, string themeId, int score, int totalQuestions)
    {
        _buffer.events.Add(new LocalEvent
        {
            type           = "quiz_score",
            bookId         = bookId,
            themeId        = themeId,
            score          = score,
            totalQuestions = totalQuestions,
            timestamp      = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ quiz_score — {bookId}/{themeId} {score}/{totalQuestions}");
    }

    public List<LocalEvent> GetAll() => new List<LocalEvent>(_buffer.events);

    public void Clear()
    {
        _buffer.events.Clear();
        Save();
        Debug.Log("[LocalBuffer] 🧹 Buffer vidé après sync");
    }
}


using System;
using System.Collections.Generic;
using UnityEngine;

[Serializable]
public class LocalEvent
{
    public string type;           // "page_view" | "session" | "child_session"
                                  // | "item_discovered" | "activity_session"
    // ── Commun ───────────────────────────────────────────────
    public long timestamp;        // Unix ms — horodatage réel de l'event

    // ── Page view / Item ──────────────────────────────────────
    public string bookId;
    public string themeId;
    public string pageId;
    public string itemName;

    // ── Session enfant ────────────────────────────────────────
    public string mode;           // "AR" | "3D" | "Activity"
    public float durationSeconds;

    // ── Activité session ─────────────────────────────────────
    public string activityId;
    public int score;
    public int totalQuestions;
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

    // ── Clé de chiffrement personnalisée ─────────────────────
    private const string ENCRYPTION_PASSWORD = "ARBook_2026_XkZ9!";

    private LocalEventList _buffer;

    // ── Settings ES3 avec AES personnalisé ───────────────────
    private ES3Settings GetSettings()
    {
        return new ES3Settings
        {
            encryptionType = ES3.EncryptionType.AES,
            encryptionPassword = ENCRYPTION_PASSWORD
        };
    }

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
        if (ES3.KeyExists(ES3_KEY, GetSettings()))
        {
            _buffer = new LocalEventList();
            _buffer.events = ES3.Load<List<LocalEvent>>(ES3_KEY, GetSettings());
        }
        else
        {
            _buffer = new LocalEventList();
        }
        Debug.Log($"[LocalBuffer] 📂 {_buffer.events.Count} events chargés (ES3)");
    }

    void Save()
    {
        ES3.Save(ES3_KEY, _buffer.events, GetSettings());
        Debug.Log($"[LocalBuffer] 💾 {_buffer.events.Count} events sauvés (ES3)");
    }

    // ══════════════════════════════════════════════════════════
    // API PUBLIQUE
    // ══════════════════════════════════════════════════════════

    public void AddPageView(string bookId, string themeId, string pageId)
    {
        _buffer.events.Add(new LocalEvent
        {
            type      = "page_view",
            bookId    = bookId,
            themeId   = themeId,
            pageId    = pageId,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ page_view — {bookId}/{themeId}/{pageId}");
    }

    public void AddSession(float durationSeconds)
    {
        _buffer.events.Add(new LocalEvent
        {
            type            = "session",
            durationSeconds = durationSeconds,
            timestamp       = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ session — {durationSeconds:F0}s");
    }

    public void AddChildSession(string mode, float durationSeconds)
    {
        _buffer.events.Add(new LocalEvent
        {
            type            = "child_session",
            mode            = mode,
            durationSeconds = durationSeconds,
            timestamp       = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ child_session — {mode} {durationSeconds:F0}s");
    }

    public void AddItemDiscovered(string bookId, string themeId, string pageId, string itemName)
    {
        Debug.Log($"bookId: {bookId}, themeId: {themeId}, pageId: {pageId}, itemName: {itemName}");
        
        _buffer.events.Add(new LocalEvent
        {
            type      = "item_discovered",
            bookId    = bookId,
            themeId   = themeId,
            pageId    = pageId,
            itemName  = itemName,
            timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ item_discovered — {itemName}");
    }

    public void AddActivitySession(string bookId, string themeId, string activityId, float durationSeconds)
    {
        _buffer.events.Add(new LocalEvent
        {
            type            = "activity_session",
            bookId          = bookId,
            themeId         = themeId,
            activityId      = activityId,
            durationSeconds = durationSeconds,
            timestamp       = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ activity_session — {bookId}/{themeId}/{activityId} {durationSeconds:F0}s");
    }
    public void AddQuizScore(string bookId, string themeId, int score, int totalQuestions)
    {
        _buffer.events.Add(new LocalEvent
        {
            type           = "quiz_score",
            bookId         = bookId,
            themeId        = themeId,
            score          = score,
            totalQuestions = totalQuestions,
            timestamp      = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds()
        });
        Save();
        Debug.Log($"[LocalBuffer] ✅ quiz_score — {bookId}/{themeId} {score}/{totalQuestions}");
    }

    public List<LocalEvent> GetAll() => new List<LocalEvent>(_buffer.events);

    public void Clear()
    {
        _buffer.events.Clear();
        Save();
        Debug.Log("[LocalBuffer] 🧹 Buffer vidé après sync");
    }
}
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

    // ── Clé de chiffrement personnalisée ─────────────────────
    private const string ENCRYPTION_PASSWORD = "ARBook_2026_XkZ9!";

    private LocalEventList _buffer;

    // ── Settings ES3 avec AES personnalisé ───────────────────
    private ES3Settings GetSettings()
    {
        return new ES3Settings
        {
            encryptionType = ES3.EncryptionType.AES,
            encryptionPassword = ENCRYPTION_PASSWORD
        };
    }

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
        if (ES3.KeyExists(ES3_KEY, GetSettings()))
        {
            _buffer = new LocalEventList();
            _buffer.events = ES3.Load<List<LocalEvent>>(ES3_KEY, GetSettings());
        }
        else
        {
            _buffer = new LocalEventList();
        }
        Debug.Log($"[LocalBuffer] 📂 {_buffer.events.Count} events chargés (ES3)");
    }

    void Save()
    {
        ES3.Save(ES3_KEY, _buffer.events, GetSettings());
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
///////////////////////////////////
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
using System;
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