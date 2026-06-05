using UnityEngine;

[ExecuteAlways]
[RequireComponent(typeof(RectTransform))]
public class AspectFitter : MonoBehaviour
{
    public enum FitMode
    {
        FitInside,
        FillOutside,
        WidthControlsHeight,
        HeightControlsWidth
    }

    public RectTransform target;
    public float aspectRatio = 16f / 9f;
    public FitMode fitMode = FitMode.FitInside;

    private RectTransform rect;

    private void OnEnable()
    {
        rect = GetComponent<RectTransform>();
        Apply();
    }

    private void OnRectTransformDimensionsChange()
    {
        Apply();
    }

    private void OnValidate()
    {
        if (aspectRatio <= 0f) aspectRatio = 16f / 9f;
        Apply();
    }

    private void Update()
    {
#if UNITY_EDITOR
        if (!Application.isPlaying) Apply();
#endif
    }

    public void Apply()
    {
        if (rect == null) rect = GetComponent<RectTransform>();
        if (target == null) target = rect.parent as RectTransform;
        if (target == null || aspectRatio <= 0f) return;

        Rect parentRect = target.rect;
        float parentWidth = parentRect.width;
        float parentHeight = parentRect.height;

        if (parentWidth <= 0f || parentHeight <= 0f) return;

        float width = parentWidth;
        float height = parentHeight;
        float parentAspect = parentWidth / parentHeight;

        switch (fitMode)
        {
            case FitMode.FitInside:
                if (parentAspect > aspectRatio) width = parentHeight * aspectRatio;
                else height = parentWidth / aspectRatio;
                break;

            case FitMode.FillOutside:
                if (parentAspect < aspectRatio) width = parentHeight * aspectRatio;
                else height = parentWidth / aspectRatio;
                break;

            case FitMode.WidthControlsHeight:
                height = parentWidth / aspectRatio;
                break;

            case FitMode.HeightControlsWidth:
                width = parentHeight * aspectRatio;
                break;
        }

        rect.anchorMin = new Vector2(0.5f, 0.5f);
        rect.anchorMax = new Vector2(0.5f, 0.5f);
        rect.pivot = new Vector2(0.5f, 0.5f);
        rect.anchoredPosition = Vector2.zero;
        rect.SetSizeWithCurrentAnchors(RectTransform.Axis.Horizontal, width);
        rect.SetSizeWithCurrentAnchors(RectTransform.Axis.Vertical, height);
    }
}