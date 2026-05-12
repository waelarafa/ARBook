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
}
/*using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using System.Collections.Generic;

public class LevelMapBuilder : MonoBehaviour
{
    [Header("Data")]
    public ImageCubeDataLibrary library;

    [Header("Map Setup")]
    public GameObject nodePrefab;
    public Transform  nodesContainer;

    [Header("Spawn Setup")]
    public Camera mainCam;

    [Header("Chemin sinueux")]
    public bool      useWaypoints = false;
    public Vector2[] waypoints;

    [Header("Ligne du chemin")]
    public bool   drawPath  = true;
    public Color  pathColor = new Color(1f, 0.5f, 0.7f, 1f);
    public float  pathWidth = 20f;
    public Sprite roundSprite;

    [Header("Déblocage")]
    public bool unlockAll = false;

    readonly List<Vector2> _nodePositions = new List<Vector2>();

    // ─────────────────────────────────────────
    void Start()
    {
        if (library == null)
        {
            Debug.LogError("LevelMapBuilder : library est null !");
            return;
        }

        if (mainCam == null)
            mainCam = Camera.main;

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
        foreach (Transform child in nodesContainer)
            Destroy(child.gameObject);

        _nodePositions.Clear();

        int count = library.entries.Count;

        for (int i = 0; i < count; i++)
        {
            var entry = library.entries[i];

            GameObject node = Instantiate(nodePrefab, nodesContainer);
            node.name = entry.imageName;

            RectTransform rt = node.GetComponent<RectTransform>();
            Vector2 pos = useWaypoints && waypoints != null && i < waypoints.Length
                ? waypoints[i]
                : AutoPosition(i, count);

            rt.anchoredPosition = pos;
            _nodePositions.Add(pos);

            TextMeshProUGUI label = node.GetComponentInChildren<TextMeshProUGUI>();
            if (label != null)
                label.text = (i + 1).ToString();

            Image img = node.GetComponentInChildren<Image>();
            if (img != null)
            {
                Sprite sprite = Resources.Load<Sprite>("LevelImages/" + entry.imageName);
                if (sprite != null) img.sprite = sprite;
            }

            int  maxUnlocked = unlockAll ? 999 : PlayerPrefs.GetInt("MaxLevel", 0);
            bool unlocked    = i <= maxUnlocked;

            Button btn = node.GetComponent<Button>();
            if (btn != null) btn.interactable = unlocked;

            CanvasGroup cg = node.GetComponent<CanvasGroup>();
            if (cg != null) cg.alpha = unlocked ? 1f : 0.5f;

            var capturedEntry = entry;
            if (btn != null)
                btn.onClick.AddListener(() => HandleNodeTap(capturedEntry));
        }

        if (drawPath && _nodePositions.Count > 1)
            DrawPath();
    }

    // ─────────────────────────────────────────
    void HandleNodeTap(ImageCubeDataLibrary.ImageDataEntry entry)
    {
        Debug.Log("👆 Bouton tappé → " + entry.imageName);
        NodeTapDetector.SpawnFromEntry(entry, mainCam);
    }

    // ─────────────────────────────────────────
    void DrawPath()
    {
        Transform old = nodesContainer.parent.Find("PathContainer");
        if (old != null) Destroy(old.gameObject);

        GameObject pathContainer    = new GameObject("PathContainer");
        pathContainer.transform.SetParent(nodesContainer.parent, false);
        pathContainer.transform.SetSiblingIndex(nodesContainer.GetSiblingIndex());

        RectTransform pathRT        = pathContainer.AddComponent<RectTransform>();
        pathRT.anchorMin            = new Vector2(0.5f, 0.5f);
        pathRT.anchorMax            = new Vector2(0.5f, 0.5f);
        pathRT.anchoredPosition     = Vector2.zero;
        pathRT.sizeDelta            = Vector2.zero;

        int maxUnlocked = unlockAll ? 999 : PlayerPrefs.GetInt("MaxLevel", 0);

        for (int i = 0; i < _nodePositions.Count - 1; i++)
        {
            bool segUnlocked = i < maxUnlocked;
            DrawSegment(pathContainer.transform,
                        _nodePositions[i],
                        _nodePositions[i + 1],
                        segUnlocked);
        }
    }

    // ─────────────────────────────────────────
    void DrawSegment(Transform parent, Vector2 from, Vector2 to, bool unlocked)
    {
        Vector2 dir      = to - from;
        float   length   = dir.magnitude;
        float   angle    = Mathf.Atan2(dir.y, dir.x) * Mathf.Rad2Deg;
        Vector2 midPoint = (from + to) * 0.5f;
        Color   color    = unlocked
            ? pathColor
            : new Color(pathColor.r, pathColor.g, pathColor.b, 0.3f);

        CreateRect(parent, "PathSeg", midPoint,
                   new Vector2(length, pathWidth), angle, color);
        AddCircle(parent, from, color);
        AddCircle(parent, to,   color);
    }

    // ─────────────────────────────────────────
    void CreateRect(Transform parent, string objName, Vector2 pos,
                    Vector2 size, float angle, Color color)
    {
        GameObject go       = new GameObject(objName);
        go.transform.SetParent(parent, false);

        RectTransform rt    = go.AddComponent<RectTransform>();
        rt.anchoredPosition = pos;
        rt.sizeDelta        = size;
        rt.localRotation    = Quaternion.Euler(0, 0, angle);

        Image img           = go.AddComponent<Image>();
        img.color           = color;
    }

    // ─────────────────────────────────────────
    void AddCircle(Transform parent, Vector2 pos, Color color)
    {
        GameObject go       = new GameObject("Junction");
        go.transform.SetParent(parent, false);

        RectTransform rt    = go.AddComponent<RectTransform>();
        rt.anchoredPosition = pos;
        rt.sizeDelta        = new Vector2(pathWidth, pathWidth);

        Image img           = go.AddComponent<Image>();
        img.color           = color;
        if (roundSprite != null) img.sprite = roundSprite;
    }

    // ─────────────────────────────────────────
    Vector2 AutoPosition(int index, int total)
    {
        RectTransform containerRT = nodesContainer.GetComponent<RectTransform>();
        float containerHeight     = containerRT != null ? containerRT.rect.height : 800f;

        float yStep      = containerHeight / (total + 1);
        float yPos       = -(index * yStep) - yStep;
        float xAmplitude = 150f;
        float xPos       = Mathf.Sin(index * 1.2f) * xAmplitude;

        return new Vector2(xPos, yPos);
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