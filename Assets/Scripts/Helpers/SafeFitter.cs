using UnityEngine;

[ExecuteAlways]
[RequireComponent(typeof(RectTransform))]
public class SafeFitter : MonoBehaviour
{
    public bool applyLeft = true;
    public bool applyRight = true;
    public bool applyTop = true;
    public bool applyBottom = true;

    private RectTransform rect;
    private Rect lastSafeArea;
    private Vector2Int lastScreenSize;

    private void OnEnable()
    {
        rect = GetComponent<RectTransform>();
        Apply();
    }

    private void Update()
    {
        if (Screen.safeArea != lastSafeArea || lastScreenSize.x != Screen.width || lastScreenSize.y != Screen.height)
        {
            Apply();
        }
    }

    private void OnValidate()
    {
        Apply();
    }

    public void Apply()
    {
        if (rect == null) rect = GetComponent<RectTransform>();

        Rect safeArea = Screen.safeArea;

        lastSafeArea = safeArea;
        lastScreenSize = new Vector2Int(Screen.width, Screen.height);

        Vector2 anchorMin = safeArea.position;
        Vector2 anchorMax = safeArea.position + safeArea.size;

        anchorMin.x /= Screen.width;
        anchorMin.y /= Screen.height;
        anchorMax.x /= Screen.width;
        anchorMax.y /= Screen.height;

        if (!applyLeft) anchorMin.x = 0f;
        if (!applyRight) anchorMax.x = 1f;
        if (!applyBottom) anchorMin.y = 0f;
        if (!applyTop) anchorMax.y = 1f;

        rect.anchorMin = anchorMin;
        rect.anchorMax = anchorMax;
        rect.offsetMin = Vector2.zero;
        rect.offsetMax = Vector2.zero;
    }
}