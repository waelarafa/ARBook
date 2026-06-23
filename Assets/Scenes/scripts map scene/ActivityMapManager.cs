using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Collections.Generic;

public class ActivityMapManager : MonoBehaviour
{
    [Header("Paramètres")]
    public string bookId  = "";
    public string themeId = "";

    [Header("Library")]
    public ImageCubeDataLibrary library;

    [Header("Sprites")]
    public Sprite spriteLocked;
    public Sprite spriteUnlocked;

    [System.Serializable]
    public class ActivityEntry
    {
        public string activityId;
        public Button button;
    }

    [Header("Boutons dans l'ordre")]
    public List<ActivityEntry> activities = new List<ActivityEntry>();

    private bool _isRefreshing = false;
    private Dictionary<Button, Sprite> originalSprites = new Dictionary<Button, Sprite>();

    void Start()
    {
        SessionManager.Instance?.SetContext(bookId, themeId);
        StartCoroutine(BuildAfterReady());
    }

    public void OpenActivity(string activityId, QuizData quiz = null)
    {
        SessionManager.Instance?.SetContext(bookId, themeId);

        switch (activityId)
        {
            case "pronunciation":
                PronunciationManager.Instance.OpenWithTheme();
                break;
            case "coloring":
                ColoringManager.Instance.OpenGame();
                break;
            case "safari":
                AnalyticsManager.Instance?.LogActivityEntered(bookId, themeId, "safari");
                UnityEngine.SceneManagement.SceneManager.LoadScene("testingscene",
                    UnityEngine.SceneManagement.LoadSceneMode.Single);
                break;
            case "quiz":
                AnalyticsManager.Instance?.LogActivityEntered(bookId, themeId, "quiz");
                QuizManager.Instance.StartQuiz(quiz);
                break;
        }
    }

    IEnumerator BuildAfterReady()
    {
        yield return new WaitUntil(() => AnalyticsManager.Instance != null);
        yield return new WaitForEndOfFrame();

        // Sauvegarde les sprites originaux assignés dans l'Inspector
        foreach (var entry in activities)
        {
            if (entry.button == null) continue;
            Image img = entry.button.GetComponent<Image>();
            if (img != null && !originalSprites.ContainsKey(entry.button))
                originalSprites[entry.button] = img.sprite;
        }

        yield return RefreshAllAsync();
    }

    public void RefreshAll() => StartCoroutine(RefreshAllAsync());

    IEnumerator RefreshAllAsync()
    {
        if (_isRefreshing) yield break;
        _isRefreshing = true;

        for (int i = 0; i < activities.Count; i++)
        {
            var entry  = activities[i];
            Button btn = entry.button;
            if (btn == null) continue;

            bool completed = false;
            bool unlocked  = false;
            bool doneCmp   = false;
            bool doneUnl   = false;

            Debug.Log($"[ActivityMap] Vérification index={i} activityId={entry.activityId}");

            AnalyticsManager.Instance.CheckActivityCompleted(
                bookId, themeId, entry.activityId, result =>
                {
                    completed = result;
                    doneCmp   = true;
                });

            yield return new WaitUntil(() => doneCmp);

            yield return StartCoroutine(CheckUnlocked(i, result =>
            {
                unlocked = result;
                doneUnl  = true;
            }));

            yield return new WaitUntil(() => doneUnl);

            btn.interactable = unlocked;

            if (completed)
                SetButtonCompleted(btn);
            else
                SetButtonSprite(btn, unlocked ? spriteUnlocked : spriteLocked);

            Debug.Log($"[ActivityMap] {entry.activityId} — unlocked={unlocked} completed={completed}");
        }

        _isRefreshing = false;
    }

    void SetButtonCompleted(Button btn)
    {
        // Restaure le sprite naturel du bouton assigné dans l'Inspector
        if (originalSprites.TryGetValue(btn, out Sprite original))
        {
            Image btnImage = btn.GetComponent<Image>();
            if (btnImage != null)
            {
                btnImage.sprite = original;
                btnImage.color  = Color.white;
            }
        }

        btn.transition = Selectable.Transition.ColorTint;

        ColorBlock cb    = btn.colors;
        cb.disabledColor = Color.white;
        btn.colors       = cb;
    }

    void SetButtonSprite(Button btn, Sprite sprite)
    {
        if (sprite == null) return;

        Image btnImage = btn.GetComponent<Image>();
        if (btnImage != null)
        {
            btnImage.sprite = sprite;
            btnImage.color  = Color.white;
        }

        SpriteState ss       = btn.spriteState;
        ss.highlightedSprite = sprite;
        ss.pressedSprite     = sprite;
        ss.selectedSprite    = sprite;
        ss.disabledSprite    = spriteLocked;
        btn.spriteState      = ss;

        btn.transition = Selectable.Transition.SpriteSwap;

        ColorBlock cb    = btn.colors;
        cb.disabledColor = Color.white;
        btn.colors       = cb;
    }

    IEnumerator CheckUnlocked(int index, System.Action<bool> callback)
    {
        if (index == 0)
        {
            yield return StartCoroutine(AreAllThemeNodesExplored(callback));
        }
        else
        {
            bool done = false;
            AnalyticsManager.Instance.CheckActivityCompleted(
                bookId, themeId, activities[index - 1].activityId, result =>
                {
                    callback?.Invoke(result);
                    done = true;
                });
            yield return new WaitUntil(() => done);
        }
    }

    IEnumerator AreAllThemeNodesExplored(System.Action<bool> callback)
    {
        if (library == null)
        {
            Debug.LogWarning("[ActivityMap] library non assignée !");
            callback?.Invoke(false);
            yield break;
        }

        List<string> themeItems = new List<string>();
        foreach (var entry in library.entries)
            if (entry.themeId == themeId)
                themeItems.Add(entry.imageName);

        if (themeItems.Count == 0) { callback?.Invoke(false); yield break; }

        int checkedCount  = 0;
        int exploredCount = 0;

        foreach (string itemName in themeItems)
        {
            string captured = itemName;
            AnalyticsManager.Instance.CheckItemDiscovered(captured, result =>
            {
                if (result) exploredCount++;
                checkedCount++;
            });
        }

        yield return new WaitUntil(() => checkedCount == themeItems.Count);

        bool allExplored = exploredCount == themeItems.Count;
        Debug.Log($"[ActivityMap] {exploredCount}/{themeItems.Count} nœuds explorés pour '{themeId}'");
        callback?.Invoke(allExplored);
    }

    public void OnActivityCompleted(string activityId)
    {
        Debug.Log($"[ActivityMap] ✅ Activité complétée : {activityId}");
        StartCoroutine(WaitAndRefresh());
    }

    private IEnumerator WaitAndRefresh()
    {
        yield return new WaitUntil(() => !_isRefreshing);
        RefreshAll();
    }
}
/*using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Collections.Generic;

public class ActivityMapManager : MonoBehaviour
{
    [Header("Paramètres")]
    public string bookId  = "";
    public string themeId = "";

    [Header("Library")]
    public ImageCubeDataLibrary library;

    [Header("Sprites")]
    public Sprite spriteLocked;
    public Sprite spriteUnlocked;
    public Sprite spriteCompleted;

    [System.Serializable]
    public class ActivityEntry
    {
        public string activityId;
        public Button button;
    }

    [Header("Boutons dans l'ordre")]
    public List<ActivityEntry> activities = new List<ActivityEntry>();

    private bool _isRefreshing = false;

    void Start()
    {
        SessionManager.Instance?.SetContext(bookId, themeId);
        StartCoroutine(BuildAfterReady());
    }

    public void OpenActivity(string activityId, QuizData quiz = null)
    {
        SessionManager.Instance?.SetContext(bookId, themeId);

        switch (activityId)
        {
            case "pronunciation":
                PronunciationManager.Instance.OpenWithTheme();
                break;
            case "coloring":
                ColoringManager.Instance.OpenGame();
                break;
            case "safari":
                AnalyticsManager.Instance?.LogActivityEntered(bookId, themeId, "safari");
                UnityEngine.SceneManagement.SceneManager.LoadScene("testingscene",
                    UnityEngine.SceneManagement.LoadSceneMode.Single);
                break;
            case "quiz":
                AnalyticsManager.Instance?.LogActivityEntered(bookId, themeId, "quiz");
                QuizManager.Instance.StartQuiz(quiz);
                break;
        }
    }

    IEnumerator BuildAfterReady()
    {
        yield return new WaitUntil(() => AnalyticsManager.Instance != null);
        yield return new WaitForEndOfFrame();
        yield return RefreshAllAsync();
    }

    public void RefreshAll() => StartCoroutine(RefreshAllAsync());

    IEnumerator RefreshAllAsync()
    {
        if (_isRefreshing) yield break;
        _isRefreshing = true;

        for (int i = 0; i < activities.Count; i++)
        {
            var entry  = activities[i];
            Button btn = entry.button;
            if (btn == null) continue;

            bool completed = false;
            bool unlocked  = false;
            bool doneCmp   = false;
            bool doneUnl   = false;

            Debug.Log($"[ActivityMap] Vérification index={i} activityId={entry.activityId}");

            AnalyticsManager.Instance.CheckActivityCompleted(
                bookId, themeId, entry.activityId, result =>
                {
                    completed = result;
                    doneCmp   = true;
                });

            yield return new WaitUntil(() => doneCmp);

            yield return StartCoroutine(CheckUnlocked(i, result =>
            {
                unlocked = result;
                doneUnl  = true;
            }));

            yield return new WaitUntil(() => doneUnl);

            btn.interactable = unlocked;

            Sprite sprite = completed ? spriteCompleted
                          : unlocked  ? spriteUnlocked
                          :             spriteLocked;

            SetButtonSprite(btn, sprite);

            Debug.Log($"[ActivityMap] {entry.activityId} — unlocked={unlocked} completed={completed}");
        }

        _isRefreshing = false;
    }

    void SetButtonSprite(Button btn, Sprite sprite)
    {
        if (sprite == null) return;

        Image btnImage = btn.GetComponent<Image>();
        if (btnImage != null)
        {
            btnImage.sprite = sprite;
            btnImage.color  = Color.white;
        }

        SpriteState ss       = btn.spriteState;
        ss.highlightedSprite = sprite;
        ss.pressedSprite     = sprite;
        ss.selectedSprite    = sprite;
        ss.disabledSprite    = spriteLocked;
        btn.spriteState      = ss;

        btn.transition = Selectable.Transition.SpriteSwap;

        ColorBlock cb    = btn.colors;
        cb.disabledColor = Color.white;
        btn.colors       = cb;
    }

    IEnumerator CheckUnlocked(int index, System.Action<bool> callback)
    {
        if (index == 0)
        {
            yield return StartCoroutine(AreAllThemeNodesExplored(callback));
        }
        else
        {
            bool done = false;
            AnalyticsManager.Instance.CheckActivityCompleted(
                bookId, themeId, activities[index - 1].activityId, result =>
                {
                    callback?.Invoke(result);
                    done = true;
                });
            yield return new WaitUntil(() => done);
        }
    }

    IEnumerator AreAllThemeNodesExplored(System.Action<bool> callback)
    {
        if (library == null)
        {
            Debug.LogWarning("[ActivityMap] library non assignée !");
            callback?.Invoke(false);
            yield break;
        }

        List<string> themeItems = new List<string>();
        foreach (var entry in library.entries)
            if (entry.themeId == themeId)
                themeItems.Add(entry.imageName);

        if (themeItems.Count == 0) { callback?.Invoke(false); yield break; }

        int checkedCount  = 0;
        int exploredCount = 0;

        foreach (string itemName in themeItems)
        {
            string captured = itemName;
            AnalyticsManager.Instance.CheckItemDiscovered(captured, result =>
            {
                if (result) exploredCount++;
                checkedCount++;
            });
        }

        yield return new WaitUntil(() => checkedCount == themeItems.Count);

        bool allExplored = exploredCount == themeItems.Count;
        Debug.Log($"[ActivityMap] {exploredCount}/{themeItems.Count} nœuds explorés pour '{themeId}'");
        callback?.Invoke(allExplored);
    }

    public void OnActivityCompleted(string activityId)
    {
        Debug.Log($"[ActivityMap] ✅ Activité complétée : {activityId}");
        StartCoroutine(WaitAndRefresh());
    }

    private IEnumerator WaitAndRefresh()
    {
        yield return new WaitUntil(() => !_isRefreshing);
        RefreshAll();
    }
}
/*using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Collections.Generic;

public class ActivityMapManager : MonoBehaviour
{
    [Header("Paramètres")]
    public string bookId  = "";
    public string themeId = "";

    [Header("Library")]
    public ImageCubeDataLibrary library;

    [Header("Couleurs")]
    public Color colorLocked    = new Color(0.5f, 0.5f, 0.5f, 1f);
    public Color colorUnlocked  = new Color(0.6f, 0.8f, 1f, 1f);
    public Color colorCompleted = new Color(0.1f, 0.4f, 0.9f, 1f);

    [System.Serializable]
    public class ActivityEntry
    {
        public string activityId;
        public Button button;
    }

    [Header("Boutons dans l'ordre")]
    public List<ActivityEntry> activities = new List<ActivityEntry>();

    private bool _isRefreshing = false;

    void Start()
    {
        StartCoroutine(BuildAfterReady());
    }

    IEnumerator BuildAfterReady()
    {
        yield return new WaitUntil(() => AnalyticsManager.Instance != null);
        yield return new WaitForEndOfFrame();
        yield return RefreshAllAsync();
    }

    public void RefreshAll() => StartCoroutine(RefreshAllAsync());

    IEnumerator RefreshAllAsync()
    {
        if (_isRefreshing) yield break;
        _isRefreshing = true;

        for (int i = 0; i < activities.Count; i++)
        {
            var entry  = activities[i];
            Button btn = entry.button;
            if (btn == null) continue;

            bool completed = false;
            bool unlocked  = false;
            bool doneCmp   = false;
            bool doneUnl   = false;

            Debug.Log($"[ActivityMap] Vérification index={i} activityId={entry.activityId}");

            AnalyticsManager.Instance.CheckActivityCompleted(
                bookId, themeId, entry.activityId, result =>
                {
                    completed = result;
                    doneCmp   = true;
                    Debug.Log($"[ActivityMap] CheckCompleted — bookId={bookId} themeId={themeId} activityId={entry.activityId} → {result}");
                });

            yield return new WaitUntil(() => doneCmp);

            yield return StartCoroutine(CheckUnlocked(i, result =>
            {
                unlocked = result;
                doneUnl  = true;
            }));

            yield return new WaitUntil(() => doneUnl);

            btn.interactable = unlocked;

            Color color = completed ? colorCompleted
                        : unlocked  ? colorUnlocked
                        :             colorLocked;

            Image img = btn.GetComponent<Image>();
            if (img != null) img.color = color;

            Debug.Log($"[ActivityMap] {entry.activityId} — unlocked={unlocked} completed={completed}");
        }

        _isRefreshing = false;
    }

    IEnumerator CheckUnlocked(int index, System.Action<bool> callback)
    {
        if (index == 0)
        {
            yield return StartCoroutine(AreAllThemeNodesExplored(callback));
        }
        else
        {
            bool done = false;
            AnalyticsManager.Instance.CheckActivityCompleted(
                bookId, themeId, activities[index - 1].activityId, result =>
                {
                    callback?.Invoke(result);
                    done = true;
                });
            yield return new WaitUntil(() => done);
        }
    }

    IEnumerator AreAllThemeNodesExplored(System.Action<bool> callback)
    {
        if (library == null)
        {
            Debug.LogWarning("[ActivityMap] library non assignée !");
            callback?.Invoke(false);
            yield break;
        }

        List<string> themeItems = new List<string>();
        foreach (var entry in library.entries)
            if (entry.themeId == themeId)
                themeItems.Add(entry.imageName);

        if (themeItems.Count == 0) { callback?.Invoke(false); yield break; }

        int checkedCount  = 0;
        int exploredCount = 0;

        foreach (string itemName in themeItems)
        {
            string captured = itemName;
            AnalyticsManager.Instance.CheckItemDiscovered(captured, result =>
            {
                if (result) exploredCount++;
                checkedCount++;
            });
        }

        yield return new WaitUntil(() => checkedCount == themeItems.Count);

        bool allExplored = exploredCount == themeItems.Count;
        Debug.Log($"[ActivityMap] {exploredCount}/{themeItems.Count} nœuds explorés pour '{themeId}'");
        callback?.Invoke(allExplored);
    }

    public void OnActivityCompleted(string activityId)
    {
        Debug.Log($"[ActivityMap] ✅ Activité complétée : {activityId}");
        StartCoroutine(WaitAndRefresh());
    }

    private IEnumerator WaitAndRefresh()
    {
        yield return new WaitUntil(() => !_isRefreshing);
        RefreshAll();
    }
}
/*using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Collections.Generic;

public class ActivityMapManager : MonoBehaviour
{
    [Header("Paramètres")]
    public string bookId  = "";
    public string themeId = "";

    [Header("Library")]
    public ImageCubeDataLibrary library;

    [Header("Couleurs")]
    public Color colorLocked    = new Color(0.5f, 0.5f, 0.5f, 1f);
    public Color colorUnlocked  = new Color(0.6f, 0.8f, 1f, 1f);
    public Color colorCompleted = new Color(0.1f, 0.4f, 0.9f, 1f);

    [System.Serializable]
    public class ActivityEntry
    {
        public string activityId;
        public Button button;
    }

    [Header("Boutons dans l'ordre")]
    public List<ActivityEntry> activities = new List<ActivityEntry>();

    void Start()
    {
        StartCoroutine(BuildAfterReady());
    }

    IEnumerator BuildAfterReady()
    {
        yield return new WaitUntil(() => AnalyticsManager.Instance != null);
        yield return new WaitForEndOfFrame();
        yield return RefreshAllAsync();
    }

    public void RefreshAll() => StartCoroutine(RefreshAllAsync());

    IEnumerator RefreshAllAsync()
    {
        for (int i = 0; i < activities.Count; i++)
        {
            var entry  = activities[i];
            Button btn = entry.button;
            if (btn == null) continue;

            int capturedIndex = i;
            var capturedEntry = entry;

            bool completed = false;
            bool unlocked  = false;
            bool doneCmp   = false;
            bool doneUnl   = false;

            // Vérifier si complétée
            AnalyticsManager.Instance.CheckActivityCompleted(
                bookId, themeId, entry.activityId, result =>
                {
                    completed = result;
                    doneCmp   = true;
                });
            

            yield return new WaitUntil(() => doneCmp);

            // Vérifier si débloquée
            yield return StartCoroutine(CheckUnlocked(i, result =>
            {
                unlocked = result;
                doneUnl  = true;
            }));

            yield return new WaitUntil(() => doneUnl);

            btn.interactable = unlocked;

            Color color = completed ? colorCompleted
                        : unlocked  ? colorUnlocked
                        :             colorLocked;

            Image img = btn.GetComponent<Image>();
            if (img != null) img.color = color;

            Debug.Log($"[ActivityMap] {entry.activityId} — unlocked={unlocked} completed={completed}");
        }
    }

    IEnumerator CheckUnlocked(int index, System.Action<bool> callback)
    {
        if (index == 0)
        {
            yield return StartCoroutine(AreAllThemeNodesExplored(callback));
        }
        else
        {
            bool done = false;
            AnalyticsManager.Instance.CheckActivityCompleted(
                bookId, themeId, activities[index - 1].activityId, result =>
                {
                    callback?.Invoke(result);
                    done = true;
                });
            yield return new WaitUntil(() => done);
        }
    }

    IEnumerator AreAllThemeNodesExplored(System.Action<bool> callback)
    {
        if (library == null)
        {
            Debug.LogWarning("[ActivityMap] library non assignée !");
            callback?.Invoke(false);
            yield break;
        }

        List<string> themeItems = new List<string>();
        foreach (var entry in library.entries)
            if (entry.themeId == themeId)
                themeItems.Add(entry.imageName);

        if (themeItems.Count == 0) { callback?.Invoke(false); yield break; }

        int checkedCount  = 0;
        int exploredCount = 0;

        foreach (string itemName in themeItems)
        {
            string captured = itemName;
            AnalyticsManager.Instance.CheckItemDiscovered(captured, result =>
            {
                if (result) exploredCount++;
                checkedCount++;
            });
        }

        yield return new WaitUntil(() => checkedCount == themeItems.Count);

        bool allExplored = exploredCount == themeItems.Count;
        Debug.Log($"[ActivityMap] {exploredCount}/{themeItems.Count} nœuds explorés pour '{themeId}'");
        callback?.Invoke(allExplored);
    }

    public void OnActivityCompleted(string activityId)
    {
        AnalyticsManager.Instance?.LogActivityExited();
        RefreshAll();
        Debug.Log($"[ActivityMap] ✅ Activité complétée : {activityId}");
    }
}
using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Collections.Generic;

public class ActivityMapManager : MonoBehaviour
{
    [Header("Paramètres")]
    public string bookId  = "";
    public string themeId = "";

    [Header("Library — glisser ImageCubeDataLibrary ici")]
    public ImageCubeDataLibrary library;

    [Header("Couleurs")]
    public Color colorLocked    = new Color(0.5f, 0.5f, 0.5f, 1f);
    public Color colorUnlocked  = new Color(0.6f, 0.8f, 1f, 1f);
    public Color colorCompleted = new Color(0.1f, 0.4f, 0.9f, 1f);

    [System.Serializable]
    public class ActivityEntry
    {
        public string activityId;
        public Button button;
    }

    [Header("Boutons dans l'ordre")]
    public List<ActivityEntry> activities = new List<ActivityEntry>();

    void Start()
    {
        StartCoroutine(BuildAfterReady());
    }

    IEnumerator BuildAfterReady()
    {
        yield return new WaitUntil(() => ChildProgressManager.Instance != null);
        yield return new WaitForEndOfFrame();
        RefreshAll();
    }

    public void RefreshAll()
    {
        for (int i = 0; i < activities.Count; i++)
        {
            var entry  = activities[i];
            Button btn = entry.button;
            if (btn == null) continue;

            bool completed = ChildProgressManager.Instance
                             .IsActivityCompleted(GetFullId(entry.activityId));
            bool unlocked  = IsUnlocked(i);

            btn.interactable = unlocked;

            Color color = completed ? colorCompleted
                        : unlocked  ? colorUnlocked
                        :             colorLocked;

            Image img = btn.GetComponent<Image>();
            if (img != null) img.color = color;

            Debug.Log($"[ActivityMap] {entry.activityId} — unlocked={unlocked} completed={completed}");
        }
    }

    bool IsUnlocked(int index)
    {
        if (index == 0)
            return AreAllThemeNodesExplored();
        else
            return ChildProgressManager.Instance
                   .IsActivityCompleted(GetFullId(activities[index - 1].activityId));
    }

    bool AreAllThemeNodesExplored()
    {
        if (library == null)
        {
            Debug.LogWarning("[ActivityMap] library non assignée dans l'Inspector !");
            return false;
        }

        foreach (var entry in library.entries)
        {
            if (entry.themeId == themeId)
            {
                if (!ChildProgressManager.Instance.IsNodeExplored(entry.imageName))
                {
                    Debug.Log($"[ActivityMap] Nœud pas encore exploré : {entry.imageName}");
                    return false;
                }
            }
        }

        Debug.Log($"[ActivityMap] ✅ Tous les nœuds du thème '{themeId}' explorés");
        return true;
    }

    public void OnActivityCompleted(string activityId)
    {
        ChildProgressManager.Instance.CompleteActivity(GetFullId(activityId));
        RefreshAll();
        Debug.Log($"[ActivityMap] ✅ Activité complétée : {activityId}");
    }

    public string GetFullId(string activityId)
        => $"{bookId}_{themeId}_{activityId}";
}*/