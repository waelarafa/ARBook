using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class FloodFill : MonoBehaviour, IPointerClickHandler
{
    private Texture2D texture;
    private Texture2D originalTexture;
    private Image image;

    void Awake()
{
    image = GetComponent<Image>();
    if (image.sprite != null)
        CopyTexture(image.sprite);
}

    public void SetSprite(Sprite newSprite)
    {
        if (image == null) image = GetComponent<Image>();
        CopyTexture(newSprite);
        Debug.Log($"[FloodFill] ✅ SetSprite terminé pour {newSprite.name}");
    }

    private void CopyTexture(Sprite sprite)
    {
        Texture2D original = sprite.texture;

        // sauvegarder les pixels originaux pour reset
        originalTexture = new Texture2D(original.width, original.height, TextureFormat.RGBA32, false);
        originalTexture.SetPixels(original.GetPixels());
        originalTexture.Apply();

        // créer texture modifiable
        texture = new Texture2D(original.width, original.height, TextureFormat.RGBA32, false);
        texture.SetPixels(original.GetPixels());
        texture.Apply();

        image.sprite = Sprite.Create(
            texture,
            new Rect(0, 0, texture.width, texture.height),
            new Vector2(0.5f, 0.5f)
        );
        Debug.Log($"[FloodFill] CopyTexture appelé avec : {sprite.name}");
    }

    public void OnPointerClick(PointerEventData eventData)
    {
        RectTransform rt = GetComponent<RectTransform>();
        Vector2 localPoint;

        RectTransformUtility.ScreenPointToLocalPointInRectangle(
            rt, eventData.position, eventData.pressEventCamera, out localPoint
        );

        float normalizedX = (localPoint.x + rt.rect.width / 2) / rt.rect.width;
        float normalizedY = (localPoint.y + rt.rect.height / 2) / rt.rect.height;

        int px = Mathf.RoundToInt(normalizedX * texture.width);
        int py = Mathf.RoundToInt(normalizedY * texture.height);

        if (px < 0 || px >= texture.width || py < 0 || py >= texture.height) return;

        Color targetColor = texture.GetPixel(px, py);
        Color fillColor = ColoringManager.Instance.GetSelectedColor();

        if (ColorsSimilar(targetColor, fillColor)) return;
        if (IsOutline(targetColor)) return;

        Fill(px, py, targetColor, fillColor);
        texture.Apply();
    }

    void Fill(int x, int y, Color targetColor, Color fillColor)
    {
        Queue<Vector2Int> queue = new Queue<Vector2Int>();
        queue.Enqueue(new Vector2Int(x, y));

        while (queue.Count > 0)
        {
            Vector2Int point = queue.Dequeue();
            int px = point.x;
            int py = point.y;

            if (px < 0 || px >= texture.width) continue;
            if (py < 0 || py >= texture.height) continue;

            Color currentColor = texture.GetPixel(px, py);

            if (!ColorsSimilar(currentColor, targetColor)) continue;
            if (IsOutline(currentColor)) continue;

            texture.SetPixel(px, py, fillColor);

            queue.Enqueue(new Vector2Int(px + 1, py));
            queue.Enqueue(new Vector2Int(px - 1, py));
            queue.Enqueue(new Vector2Int(px, py + 1));
            queue.Enqueue(new Vector2Int(px, py - 1));
        }
    }

    bool ColorsSimilar(Color a, Color b, float tolerance = 0.1f)
    {
        return Mathf.Abs(a.r - b.r) < tolerance &&
               Mathf.Abs(a.g - b.g) < tolerance &&
               Mathf.Abs(a.b - b.b) < tolerance;
    }

    bool IsOutline(Color c)
    {
        return c.r < 0.2f && c.g < 0.2f && c.b < 0.2f;
    }

    public void Reset()
    {
        texture.SetPixels(originalTexture.GetPixels());
        texture.Apply();
    }
}
/*using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class FloodFill : MonoBehaviour, IPointerClickHandler
{
    private Texture2D texture;
    private Sprite originalSprite;
    private Image image;

    void Awake()
    {
        image = GetComponent<Image>();
        // copie la texture pour pouvoir la modifier
        originalSprite = image.sprite;
        Texture2D original = originalSprite.texture;

        // créer une copie modifiable
        texture = new Texture2D(original.width, original.height, TextureFormat.RGBA32, false);
        texture.SetPixels(original.GetPixels());
        texture.Apply();

        // remplacer le sprite par la copie
        image.sprite = Sprite.Create(
            texture,
            new Rect(0, 0, texture.width, texture.height),
            new Vector2(0.5f, 0.5f)
        );
    }

    public void OnPointerClick(PointerEventData eventData)
    {
        // convertir la position du tap en position sur la texture
        RectTransform rt = GetComponent<RectTransform>();
        Vector2 localPoint;

        RectTransformUtility.ScreenPointToLocalPointInRectangle(
            rt, eventData.position, eventData.pressEventCamera, out localPoint
        );

        // normaliser entre 0 et 1
        float normalizedX = (localPoint.x + rt.rect.width / 2) / rt.rect.width;
        float normalizedY = (localPoint.y + rt.rect.height / 2) / rt.rect.height;

        // convertir en coordonnées pixel
        int px = Mathf.RoundToInt(normalizedX * texture.width);
        int py = Mathf.RoundToInt(normalizedY * texture.height);

        // vérifier les limites
        if (px < 0 || px >= texture.width || py < 0 || py >= texture.height) return;

        Color targetColor = texture.GetPixel(px, py);
        Color fillColor = ColoringManager.Instance.GetSelectedColor();

        // ne pas remplir si même couleur ou si c'est un contour noir
        if (ColorsSimilar(targetColor, fillColor)) return;
        if (IsOutline(targetColor)) return;

        Fill(px, py, targetColor, fillColor);
        texture.Apply();
    }

    void Fill(int x, int y, Color targetColor, Color fillColor)
    {
        Queue<Vector2Int> queue = new Queue<Vector2Int>();
        queue.Enqueue(new Vector2Int(x, y));

        while (queue.Count > 0)
        {
            Vector2Int point = queue.Dequeue();
            int px = point.x;
            int py = point.y;

            if (px < 0 || px >= texture.width) continue;
            if (py < 0 || py >= texture.height) continue;

            Color currentColor = texture.GetPixel(px, py);

            if (!ColorsSimilar(currentColor, targetColor)) continue;
            if (IsOutline(currentColor)) continue;

            texture.SetPixel(px, py, fillColor);

            queue.Enqueue(new Vector2Int(px + 1, py));
            queue.Enqueue(new Vector2Int(px - 1, py));
            queue.Enqueue(new Vector2Int(px, py + 1));
            queue.Enqueue(new Vector2Int(px, py - 1));
        }
    }

    // vérifie si deux couleurs sont similaires (tolérance)
    bool ColorsSimilar(Color a, Color b, float tolerance = 0.1f)
    {
        return Mathf.Abs(a.r - b.r) < tolerance &&
               Mathf.Abs(a.g - b.g) < tolerance &&
               Mathf.Abs(a.b - b.b) < tolerance;
    }

    // les contours noirs ne se colorient pas
    bool IsOutline(Color c)
    {
        return c.r < 0.2f && c.g < 0.2f && c.b < 0.2f;
    }

    // réinitialiser le coloriage
    public void Reset()
    {
        texture.SetPixels(originalSprite.texture.GetPixels());
        texture.Apply();
    }
   
}*/