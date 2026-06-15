using UnityEngine;

#if UNITY_EDITOR
using UnityEditor;
#endif

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
    private bool isApplying;

    private void OnEnable()
    {
        rect = GetComponent<RectTransform>();

#if UNITY_EDITOR
        if (!Application.isPlaying)
        {
            RequestEditorApply();
            return;
        }
#endif

        Apply();
    }

    private void Update()
    {
        if (Screen.safeArea != lastSafeArea || lastScreenSize.x != Screen.width || lastScreenSize.y != Screen.height)
            Apply();
    }

#if UNITY_EDITOR
    private void OnValidate()
    {
        rect = GetComponent<RectTransform>();
        RequestEditorApply();
    }

    private void RequestEditorApply()
    {
        EditorApplication.delayCall -= DelayedEditorApply;
        EditorApplication.delayCall += DelayedEditorApply;
    }

    private void DelayedEditorApply()
    {
        if (this == null || !isActiveAndEnabled)
            return;

        Apply();
    }
#endif

    public void Apply()
    {
        if (isApplying)
            return;

        if (rect == null)
            rect = GetComponent<RectTransform>();

        if (rect == null || Screen.width <= 0 || Screen.height <= 0)
            return;

        isApplying = true;

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

        isApplying = false;
    }
}