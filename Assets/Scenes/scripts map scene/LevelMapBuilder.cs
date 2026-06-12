using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using System.Collections.Generic;

public class LevelMapBuilder : MonoBehaviour
{
    public static LevelMapBuilder Instance { get; private set; }

    [Header("Data")]
    public ImageCubeDataLibrary library;

    [Header("Déblocage")]
    public bool unlockAll = false;

    [Header("Sprites bouton")]
    public Sprite spriteUnvisited;
    public Sprite spriteVisited;

    [System.Serializable]
    public class LevelButtonEntry
    {
        [HideInInspector] public string levelName;
        public Button button;
    }

    [Header("Boutons des niveaux")]
    public List<LevelButtonEntry> levelButtons = new List<LevelButtonEntry>();

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    void OnValidate()
    {
        if (library == null) return;
        for (int i = 0; i < levelButtons.Count; i++)
            if (i < library.entries.Count)
                levelButtons[i].levelName = library.entries[i].imageName;
    }

    void Start()
    {
        if (library == null) { Debug.LogError("LevelMapBuilder : library est null !"); return; }
        StartCoroutine(BuildAfterFrame());
    }

    IEnumerator BuildAfterFrame()
    {
        yield return new WaitUntil(() => AnalyticsManager.Instance != null);
        yield return new WaitForEndOfFrame();
        yield return BuildMapAsync();
    }

    IEnumerator BuildMapAsync()
    {
        int count = Mathf.Min(library.entries.Count, levelButtons.Count);

        for (int i = 0; i < count; i++)
        {
            var entry      = library.entries[i];
            var levelEntry = levelButtons[i];
            Button btn     = levelEntry.button;

            if (btn == null) continue;

            btn.gameObject.name = entry.imageName;

            TextMeshProUGUI label = btn.GetComponentInChildren<TextMeshProUGUI>();
            if (label != null) label.text = (i + 1).ToString();

            Image[] images = btn.GetComponentsInChildren<Image>();
            foreach (Image img in images)
            {
                if (img.gameObject != btn.gameObject)
                {
                    Sprite sprite = Resources.Load<Sprite>("LevelImages/" + entry.imageName);
                    if (sprite != null) img.sprite = sprite;
                    break;
                }
            }

            btn.interactable = true;

            CanvasGroup cg = btn.GetComponent<CanvasGroup>();
            if (cg != null) { cg.alpha = 1f; cg.interactable = true; cg.blocksRaycasts = true; }

            int capturedIndex  = i;
            var capturedEntry  = entry;
            Button capturedBtn = btn;

            bool done = false;
            AnalyticsManager.Instance.CheckItemDiscovered(entry.imageName, visited =>
            {
                UnityMainThreadDispatcher.Instance().Enqueue(() =>
                {
                    SetButtonSprite(capturedBtn, visited ? spriteVisited : spriteUnvisited);
                    done = true;
                });
            });

            yield return new WaitUntil(() => done);

            btn.onClick.RemoveAllListeners();
            btn.onClick.AddListener(() => HandleNodeTap(capturedEntry, capturedBtn));
        }
    }

    void HandleNodeTap(ImageCubeDataLibrary.ImageDataEntry entry, Button btn)
    {
        Debug.Log("👆 Bouton tappé → " + entry.imageName);

        NodeTapDetector.SpawnFromEntry(entry, Camera.main);

        AnalyticsManager.Instance?.LogItemDiscovered(
            DataManager.Instance.LastLoadedBookId,
            entry.themeId,
            entry.pageName,
            entry.imageName
        );

        SetButtonSprite(btn, spriteVisited);
        Debug.Log($"[LevelMap] ✅ {entry.imageName} — sprite changé");
    }

    // ─────────────────────────────────────────
    void SetButtonSprite(Button btn, Sprite sprite)
    {
        if (sprite == null) return;

        // Changer le sprite du bouton lui-même
        Image btnImage = btn.GetComponent<Image>();
        if (btnImage != null) btnImage.sprite = sprite;

        // Mettre à jour le SpriteState pour les états hover/press
        SpriteState ss        = btn.spriteState;
        ss.highlightedSprite  = sprite;
        ss.pressedSprite      = sprite;
        ss.selectedSprite     = sprite;
        ss.disabledSprite     = sprite;
        btn.spriteState       = ss;

        // Passer en mode Sprite Swap
        btn.transition = Selectable.Transition.SpriteSwap;
    }

    [ContextMenu("Rebuild Map")]
    public void RebuildMap() => StartCoroutine(BuildMapAsync());
}
/*using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using System.Collections.Generic;

public class LevelMapBuilder : MonoBehaviour
{
    public static LevelMapBuilder Instance { get; private set; }

    [Header("Data")]
    public ImageCubeDataLibrary library;

    [Header("Déblocage")]
    public bool unlockAll = false;

    [Header("Couleurs bouton")]
    public Color colorUnvisited = new Color(0.6f, 0.8f, 1f, 1f);
    public Color colorVisited   = new Color(0.1f, 0.4f, 0.9f, 1f);

    [System.Serializable]
    public class LevelButtonEntry
    {
        [HideInInspector] public string levelName;
        public Button button;
    }

    [Header("Boutons des niveaux")]
    public List<LevelButtonEntry> levelButtons = new List<LevelButtonEntry>();

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    void OnValidate()
    {
        if (library == null) return;
        for (int i = 0; i < levelButtons.Count; i++)
            if (i < library.entries.Count)
                levelButtons[i].levelName = library.entries[i].imageName;
    }

    void Start()
    {
        if (library == null) { Debug.LogError("LevelMapBuilder : library est null !"); return; }
        StartCoroutine(BuildAfterFrame());
    }

    IEnumerator BuildAfterFrame()
    {
        yield return new WaitUntil(() => AnalyticsManager.Instance != null);
        yield return new WaitForEndOfFrame();
        yield return BuildMapAsync();
    }

    IEnumerator BuildMapAsync()
    {
        int count = Mathf.Min(library.entries.Count, levelButtons.Count);

        for (int i = 0; i < count; i++)
        {
            var entry      = library.entries[i];
            var levelEntry = levelButtons[i];
            Button btn     = levelEntry.button;

            if (btn == null) continue;

            btn.gameObject.name = entry.imageName;

            TextMeshProUGUI label = btn.GetComponentInChildren<TextMeshProUGUI>();
            if (label != null) label.text = (i + 1).ToString();

            Image[] images = btn.GetComponentsInChildren<Image>();
            foreach (Image img in images)
            {
                if (img.gameObject != btn.gameObject)
                {
                    Sprite sprite = Resources.Load<Sprite>("LevelImages/" + entry.imageName);
                    if (sprite != null) img.sprite = sprite;
                    break;
                }
            }

            btn.interactable = true;

            CanvasGroup cg = btn.GetComponent<CanvasGroup>();
            if (cg != null) { cg.alpha = 1f; cg.interactable = true; cg.blocksRaycasts = true; }

            // Vérifier si visité via analytics
            int capturedIndex  = i;
            var capturedEntry  = entry;
            Button capturedBtn = btn;

            bool done = false;
AnalyticsManager.Instance.CheckItemDiscovered(entry.imageName, visited =>
{
    UnityMainThreadDispatcher.Instance().Enqueue(() =>
    {
        SetButtonColor(capturedBtn, visited ? colorVisited : colorUnvisited);
        done = true;
    });
});



            yield return new WaitUntil(() => done);

            btn.onClick.RemoveAllListeners();
            btn.onClick.AddListener(() => HandleNodeTap(capturedEntry, capturedBtn));
        }
    }

    void HandleNodeTap(ImageCubeDataLibrary.ImageDataEntry entry, Button btn)
    {
        Debug.Log("👆 Bouton tappé → " + entry.imageName);

        NodeTapDetector.SpawnFromEntry(entry, Camera.main);

        AnalyticsManager.Instance?.LogItemDiscovered(
            DataManager.Instance.LastLoadedBookId,
            entry.themeId,
            entry.pageName,
            entry.imageName
        );

        SetButtonColor(btn, colorVisited);
        Debug.Log($"[LevelMap] ✅ {entry.imageName} — couleur changée");
    }

    void SetButtonColor(Button btn, Color color)
    {
        Image btnImage = btn.GetComponent<Image>();
        if (btnImage != null) btnImage.color = color;

        ColorBlock cb       = btn.colors;
        cb.normalColor      = color;
        cb.highlightedColor = color * 1.1f;
        cb.pressedColor     = color * 0.9f;
        cb.selectedColor    = color;
        cb.disabledColor    = color * 0.5f;
        btn.colors          = cb;
    }

    [ContextMenu("Rebuild Map")]
    public void RebuildMap() => StartCoroutine(BuildMapAsync());
}
/*using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using System.Collections.Generic;

public class LevelMapBuilder : MonoBehaviour
{
    public static LevelMapBuilder Instance { get; private set; }

    [Header("Data")]
    public ImageCubeDataLibrary library;

    [Header("Déblocage")]
    public bool unlockAll = false;

    [Header("Couleurs bouton")]
    public Color colorUnvisited = new Color(0.6f, 0.8f, 1f, 1f);
    public Color colorVisited   = new Color(0.1f, 0.4f, 0.9f, 1f);

    [System.Serializable]
    public class LevelButtonEntry
    {
        [HideInInspector] public string levelName;
        public Button button;
    }

    [Header("Boutons des niveaux")]
    public List<LevelButtonEntry> levelButtons = new List<LevelButtonEntry>();

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    void OnValidate()
    {
        if (library == null) return;
        for (int i = 0; i < levelButtons.Count; i++)
        {
            if (i < library.entries.Count)
                levelButtons[i].levelName = library.entries[i].imageName;
        }
    }

    void Start()
    {
        if (library == null) { Debug.LogError("LevelMapBuilder : library est null !"); return; }
        StartCoroutine(BuildAfterFrame());
    }

    IEnumerator BuildAfterFrame()
    {
        yield return new WaitUntil(() => ChildProgressManager.Instance != null);
        yield return new WaitForEndOfFrame();
        BuildMap();
    }

    public void BuildMap()
    {
        int count = Mathf.Min(library.entries.Count, levelButtons.Count);

        for (int i = 0; i < count; i++)
        {
            var entry      = library.entries[i];
            var levelEntry = levelButtons[i];
            Button btn     = levelEntry.button;

            if (btn == null) continue;

            btn.gameObject.name = entry.imageName;

            // Label numéro
            TextMeshProUGUI label = btn.GetComponentInChildren<TextMeshProUGUI>();
            if (label != null)
                label.text = (i + 1).ToString();

            // Image du niveau
            Image img = btn.GetComponentInChildren<Image>();
            if (img != null)
            {
                Sprite sprite = Resources.Load<Sprite>("LevelImages/" + entry.imageName);
                if (sprite != null) img.sprite = sprite;
            }

            // ── Déblocage via ChildProgressManager ──
            bool visited  = ChildProgressManager.Instance.IsNodeExplored(entry.imageName);
            bool unlocked = unlockAll || i == 0 || visited ||
                            IsAnyPreviousVisited(i);

            btn.interactable = unlocked;

            CanvasGroup cg = btn.GetComponent<CanvasGroup>();
            if (cg != null)
            {
                cg.alpha          = unlocked ? 1f : 0.5f;
                cg.interactable   = unlocked;
                cg.blocksRaycasts = unlocked;
            }

            // ── Couleur selon visité ou non ──
            SetButtonColor(btn, visited ? colorVisited : colorUnvisited);
            Debug.Log($"[LevelMap] {entry.imageName} — visited={visited} unlocked={unlocked}");

            // Listener
            btn.onClick.RemoveAllListeners();
            var capturedEntry = entry;
            Button capturedBtn = btn;
            btn.onClick.AddListener(() => HandleNodeTap(capturedEntry, capturedBtn));
        }
    }

    // Un bouton est débloqué si le précédent a été visité
    bool IsAnyPreviousVisited(int index)
    {
        if (index == 0) return true;
        string previousName = library.entries[index - 1].imageName;
        return ChildProgressManager.Instance.IsNodeExplored(previousName);
    }

    void HandleNodeTap(ImageCubeDataLibrary.ImageDataEntry entry, Button btn)
    {
        Debug.Log("👆 Bouton tappé → " + entry.imageName);

        NodeTapDetector.SpawnFromEntry(entry, Camera.main);

        AnalyticsManager.Instance?.LogItemDiscovered(
            DataManager.Instance.LastLoadedBookId,
            entry.themeId,
            entry.pageName,
            entry.imageName
        );

        // Sauvegarder + changer couleur
        ChildProgressManager.Instance.MarkNodeExplored(entry.imageName);
        SetButtonColor(btn, colorVisited);
        Debug.Log($"[LevelMap] ✅ {entry.imageName} — visité + couleur changée");

        // Rebuild pour débloquer le bouton suivant
        BuildMap();
    }

    void SetButtonColor(Button btn, Color color)
    {
        Image btnImage = btn.GetComponent<Image>();
        if (btnImage != null)
            btnImage.color = color;

        ColorBlock cb       = btn.colors;
        cb.normalColor      = color;
        cb.highlightedColor = color * 1.1f;
        cb.pressedColor     = color * 0.9f;
        cb.selectedColor    = color;
        cb.disabledColor    = color * 0.5f;
        btn.colors          = cb;
    }

    [ContextMenu("Rebuild Map")]
    public void RebuildMap() => BuildMap();
}
/*using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using System.Collections.Generic;

public class LevelMapBuilder : MonoBehaviour
{
    public static LevelMapBuilder Instance { get; private set; }

    [Header("Data")]
    public ImageCubeDataLibrary library;

    [Header("Déblocage")]
    public bool unlockAll = false;

    [Header("Couleurs bouton")]
    public Color colorUnvisited = new Color(0.6f, 0.8f, 1f, 1f);
    public Color colorVisited   = new Color(0.1f, 0.4f, 0.9f, 1f);

    [System.Serializable]
    public class LevelButtonEntry
    {
        [HideInInspector] public string levelName;
        public Button button;
    }

    [Header("Boutons des niveaux")]
    public List<LevelButtonEntry> levelButtons = new List<LevelButtonEntry>();

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    void OnValidate()
    {
        if (library == null) return;
        for (int i = 0; i < levelButtons.Count; i++)
        {
            if (i < library.entries.Count)
                levelButtons[i].levelName = library.entries[i].imageName;
        }
    }

    void Start()
    {
        if (library == null) { Debug.LogError("LevelMapBuilder : library est null !"); return; }
        StartCoroutine(BuildAfterFrame());
    }

    IEnumerator BuildAfterFrame()
    {
        yield return new WaitUntil(() => ChildProgressManager.Instance != null);
        yield return new WaitForEndOfFrame();
        BuildMap();
    }

    public void BuildMap()
    {
        int count = Mathf.Min(library.entries.Count, levelButtons.Count);

        for (int i = 0; i < count; i++)
        {
            var entry      = library.entries[i];
            var levelEntry = levelButtons[i];
            Button btn     = levelEntry.button;

            if (btn == null) continue;

            btn.gameObject.name = entry.imageName;

            // Label numéro
            TextMeshProUGUI label = btn.GetComponentInChildren<TextMeshProUGUI>();
            if (label != null)
                label.text = (i + 1).ToString();

            // Image du niveau
            Image img = btn.GetComponentInChildren<Image>();
            if (img != null)
            {
                Sprite sprite = Resources.Load<Sprite>("LevelImages/" + entry.imageName);
                if (sprite != null) img.sprite = sprite;
            }

            // Déblocage
            int  maxUnlocked = unlockAll ? 999 : PlayerPrefs.GetInt("MaxLevel", 0);
            bool unlocked    = i <= maxUnlocked;
            btn.interactable = unlocked;

            CanvasGroup cg = btn.GetComponent<CanvasGroup>();
            if (cg != null) cg.alpha = unlocked ? 1f : 0.5f;

            // ── Couleur selon visité ou non ──
            bool visited = ChildProgressManager.Instance.IsNodeExplored(entry.imageName);
            SetButtonColor(btn, visited ? colorVisited : colorUnvisited);
            Debug.Log($"[LevelMap] {entry.imageName} — visited={visited}");

            // Listener
            btn.onClick.RemoveAllListeners();
            var capturedEntry = entry;
            Button capturedBtn = btn;
            btn.onClick.AddListener(() => HandleNodeTap(capturedEntry, capturedBtn));
        }
    }

    void HandleNodeTap(ImageCubeDataLibrary.ImageDataEntry entry, Button btn)
    {
        Debug.Log("👆 Bouton tappé → " + entry.imageName);

        NodeTapDetector.SpawnFromEntry(entry, Camera.main);

        AnalyticsManager.Instance?.LogItemDiscovered(
            DataManager.Instance.LastLoadedBookId,
            entry.themeId,
            entry.pageName,
            entry.imageName
        );

        // Sauvegarder + changer couleur
        ChildProgressManager.Instance.MarkNodeExplored(entry.imageName);
        SetButtonColor(btn, colorVisited);
        Debug.Log($"[LevelMap] ✅ {entry.imageName} — visité + couleur changée");
    }

    void SetButtonColor(Button btn, Color color)
    {
        Image btnImage = btn.GetComponent<Image>();
        if (btnImage != null)
            btnImage.color = color;

        ColorBlock cb       = btn.colors;
        cb.normalColor      = color;
        cb.highlightedColor = color * 1.1f;
        cb.pressedColor     = color * 0.9f;
        cb.selectedColor    = color;
        cb.disabledColor    = color * 0.5f;
        btn.colors          = cb;
    }

    public static void UnlockNextLevel(int currentIndex)
    {
        int current = PlayerPrefs.GetInt("MaxLevel", 0);
        if (currentIndex + 1 > current)
        {
            PlayerPrefs.SetInt("MaxLevel", currentIndex + 1);
            PlayerPrefs.Save();
        }
    }

    [ContextMenu("Rebuild Map")]
    public void RebuildMap() => BuildMap();
}
/*
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using System.Collections.Generic;

public class LevelMapBuilder : MonoBehaviour
{
    [Header("Data")]
    public ImageCubeDataLibrary library;

    [Header("Déblocage")]
    public bool unlockAll = false;

    [System.Serializable]
    public class LevelButtonEntry
    {
        [HideInInspector] public string levelName;
        public Button button;
    }

    [Header("Boutons des niveaux")]
    public List<LevelButtonEntry> levelButtons = new List<LevelButtonEntry>();

    // ─────────────────────────────────────────
    void OnValidate()
    {
        if (library == null) return;

        for (int i = 0; i < levelButtons.Count; i++)
        {
            if (i < library.entries.Count)
                levelButtons[i].levelName = library.entries[i].imageName;
        }
    }

    // ─────────────────────────────────────────
    void Start()
    {
        if (library == null)
        {
            Debug.LogError("LevelMapBuilder : library est null !");
            return;
        }

        StartCoroutine(BuildAfterFrame());
    }

    IEnumerator BuildAfterFrame()
    {
        yield return new WaitForEndOfFrame();
        BuildMap();
    }

    // ─────────────────────────────────────────
    public void BuildMap()
    {
        int count = Mathf.Min(library.entries.Count, levelButtons.Count);

        for (int i = 0; i < count; i++)
        {
            var entry      = library.entries[i];
            var levelEntry = levelButtons[i];
            Button btn     = levelEntry.button;

            if (btn == null) continue;

            btn.gameObject.name = entry.imageName;

            // Label numéro
            TextMeshProUGUI label = btn.GetComponentInChildren<TextMeshProUGUI>();
            if (label != null)
                label.text = (i + 1).ToString();

            // Image du niveau
            Image img = btn.GetComponentInChildren<Image>();
            if (img != null)
            {
                Sprite sprite = Resources.Load<Sprite>("LevelImages/" + entry.imageName);
                if (sprite != null) img.sprite = sprite;
            }

            // Déblocage
            int  maxUnlocked = unlockAll ? 999 : PlayerPrefs.GetInt("MaxLevel", 0);
            bool unlocked    = i <= maxUnlocked;

            btn.interactable = unlocked;

            CanvasGroup cg = btn.GetComponent<CanvasGroup>();
            if (cg != null) cg.alpha = unlocked ? 1f : 0.5f;

            // Listener
            btn.onClick.RemoveAllListeners();
            var capturedEntry = entry;
            btn.onClick.AddListener(() => HandleNodeTap(capturedEntry));
        }
    }

    // ─────────────────────────────────────────
    void HandleNodeTap(ImageCubeDataLibrary.ImageDataEntry entry)
    {
        Debug.Log("👆 Bouton tappé → " + entry.imageName);
        NodeTapDetector.SpawnFromEntry(entry, Camera.main);
        AnalyticsManager.Instance?.LogItemDiscovered(
            DataManager.Instance.LastLoadedBookId,
            entry.themeId,    // themeId
            entry.pageName,   // pageId
            entry.imageName   // itemName
        );

    }

    // ─────────────────────────────────────────
    public static void UnlockNextLevel(int currentIndex)
    {
        int current = PlayerPrefs.GetInt("MaxLevel", 0);
        if (currentIndex + 1 > current)
        {
            PlayerPrefs.SetInt("MaxLevel", currentIndex + 1);
            PlayerPrefs.Save();
        }
    }

    [ContextMenu("Rebuild Map")]
    public void RebuildMap() => BuildMap();
}*/