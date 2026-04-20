using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Collections.Generic;

public class StarUIManager : MonoBehaviour
{
    public static StarUIManager Instance { get; private set; }

    private List<Image> _stars = new List<Image>();
    private int _totalStars  = 0;
    private int _litStars    = 0;

    private Canvas _canvas;
    private GameObject _starsContainer;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        // FIX : DontDestroyOnLoad manquant — empêche la destruction lors du rechargement de scène
        DontDestroyOnLoad(gameObject);
    }

    // Appelle cette méthode au début de chaque page
    // pour initialiser le bon nombre d'étoiles
    public void InitStars(int count)
    {
        _totalStars = count;
        _litStars   = 0;

        if (_canvas == null) CreateCanvas();

        // Nettoie les étoiles précédentes
        foreach (var s in _stars)
            if (s != null) Destroy(s.gameObject);
        _stars.Clear();

        // Crée les nouvelles étoiles
        for (int i = 0; i < count; i++)
            _stars.Add(CreateStarImage(i, count));
    }

    // Appelle cette méthode quand une image est validée
    public void LightNextStar()
    {
        if (_litStars >= _stars.Count) return;
        StartCoroutine(AnimateStar(_stars[_litStars]));
        _litStars++;

        if (_litStars == _totalStars)
            StartCoroutine(AllStarsEffect());
    }

    public void ResetStars()
    {
        _litStars = 0;
        foreach (var s in _stars)
        {
            if (s == null) continue;
            s.color = new Color(0.3f, 0.3f, 0.3f, 0.5f);
            s.transform.localScale = Vector3.one;
        }
    }

    // ─────────────────────────────────────────
    IEnumerator AnimateStar(Image star)
    {
        // Bounce + allumage
        star.color = Color.yellow;
        float t = 0f;
        while (t < 0.4f)
        {
            t += Time.deltaTime;
            float s = 1f + Mathf.Sin(t / 0.4f * Mathf.PI) * 0.5f;
            star.transform.localScale = Vector3.one * s;
            yield return null;
        }
        star.transform.localScale = Vector3.one * 1.1f;
    }

    IEnumerator AllStarsEffect()
    {
        yield return new WaitForSeconds(0.3f);
        // Toutes les étoiles clignotent ensemble
        for (int i = 0; i < 3; i++)
        {
            foreach (var s in _stars)
                if (s != null) s.color = Color.white;
            yield return new WaitForSeconds(0.15f);
            foreach (var s in _stars)
                if (s != null) s.color = Color.yellow;
            yield return new WaitForSeconds(0.15f);
        }
    }

    // ─────────────────────────────────────────
    void CreateCanvas()
    {
        GameObject canvasObj = new GameObject("StarCanvas");
        _canvas              = canvasObj.AddComponent<Canvas>();
        _canvas.renderMode   = RenderMode.ScreenSpaceOverlay;
        _canvas.sortingOrder = 10;
        canvasObj.AddComponent<CanvasScaler>();
        // Pas de GraphicRaycaster — lecture seule

        _starsContainer = new GameObject("StarsContainer");
        _starsContainer.transform.SetParent(canvasObj.transform, false);

        RectTransform rt = _starsContainer.AddComponent<RectTransform>();
        rt.anchorMin        = new Vector2(0.5f, 1f);
        rt.anchorMax        = new Vector2(0.5f, 1f);
        rt.pivot            = new Vector2(0.5f, 1f);
        rt.anchoredPosition = new Vector2(0f, -30f);
        rt.sizeDelta        = new Vector2(300f, 70f);

        HorizontalLayoutGroup hlg = _starsContainer.AddComponent<HorizontalLayoutGroup>();
        hlg.spacing            = 10f;
        hlg.childAlignment     = TextAnchor.MiddleCenter;
        hlg.childControlWidth  = false;
        hlg.childControlHeight = false;
        hlg.childForceExpandWidth  = false;
        hlg.childForceExpandHeight = false;
    }

    Image CreateStarImage(int index, int total)
    {
        GameObject obj = new GameObject("Star_" + index);
        obj.transform.SetParent(_starsContainer.transform, false);

        RectTransform rt = obj.AddComponent<RectTransform>();
        rt.sizeDelta = new Vector2(50f, 50f);

        Image img  = obj.AddComponent<Image>();
        img.sprite = CreateStarSprite();
        img.color  = new Color(0.3f, 0.3f, 0.3f, 0.5f); // gris éteint
        img.raycastTarget = false;

        return img;
    }

    // Génère un sprite étoile procédural
    Sprite CreateStarSprite()
    {
        int size = 64;
        Texture2D tex = new Texture2D(size, size, TextureFormat.RGBA32, false);
        Color[] pixels = new Color[size * size];

        Vector2 center = new Vector2(size / 2f, size / 2f);
        float outerR   = size / 2f - 2f;
        float innerR   = outerR * 0.4f;
        int   points   = 5;

        for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
        {
            Vector2 p     = new Vector2(x, y) - center;
            float   angle = Mathf.Atan2(p.y, p.x) - Mathf.PI / 2f;
            float   dist  = p.magnitude;
            float   seg   = Mathf.PI * 2f / points;
            float   a     = ((angle % seg) + seg) % seg;
            float   t     = a / seg;
            float   rOuter = outerR;
            float   rInner = innerR;
            float   rBorder = t < 0.5f
                ? Mathf.Lerp(rOuter, rInner, t * 2f)
                : Mathf.Lerp(rInner, rOuter, (t - 0.5f) * 2f);

            pixels[y * size + x] = dist <= rBorder
                ? Color.white
                : Color.clear;
        }

        tex.SetPixels(pixels);
        tex.Apply();
        return Sprite.Create(tex,
            new Rect(0, 0, size, size),
            new Vector2(0.5f, 0.5f));
    }
}