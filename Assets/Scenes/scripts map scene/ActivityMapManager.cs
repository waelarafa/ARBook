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
/*using UnityEngine;
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