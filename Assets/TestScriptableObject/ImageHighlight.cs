using UnityEngine;
using System.Collections;
using System.Collections.Generic;

/// <summary>
/// Bordure animée "étoiles et confettis" :
///   – Des étoiles et confettis colorés défilent exactement sur le
///     contour rectangulaire de l'image trackée.
///   – L'intérieur de l'image reste entièrement visible.
///   – Adapté automatiquement à la taille réelle de l'image AR.
/// Déclenchée via PlayCorrectEffect() par ARImageCubeOverlay.
/// </summary>
public class ImageHighlight : MonoBehaviour
{
    private bool _triggered = false;

    // Taille de l'image (mise à jour via SetImageSize)
    private Vector2 _imageSize = new Vector2(0.15f, 0.15f);

    // Items qui défilent sur le bord
    private class BorderItem
    {
        public GameObject   obj;
        public MeshRenderer mr;
        public float        perimPos;   // position sur le périmètre (0 → perim)
        public float        speed;
        public float        rotSpeed;
        public Color        color;
        public bool         isStar;     // true=étoile, false=confetti
    }

    private List<BorderItem> _items = new List<BorderItem>();
    private GameObject       _itemRoot;
    private const int        ItemCount = 32;

    // Palette arc-en-ciel
    private static readonly Color[] Palette = new Color[]
    {
        new Color(1.00f, 0.22f, 0.22f, 1f),
        new Color(1.00f, 0.75f, 0.00f, 1f),
        new Color(0.10f, 0.85f, 0.35f, 1f),
        new Color(0.15f, 0.55f, 1.00f, 1f),
        new Color(1.00f, 0.40f, 0.80f, 1f),
        new Color(0.65f, 0.20f, 1.00f, 1f),
        new Color(1.00f, 0.55f, 0.10f, 1f),
        new Color(0.10f, 0.90f, 0.95f, 1f),
    };

    // ─────────────────────────────────────────────────────────────
    void Awake()
    {
        BuildItems();
    }

    void OnDestroy()
    {
        StopAllCoroutines();
        if (_itemRoot != null) Destroy(_itemRoot);
    }

    // ─────────────────────────────────────────────────────────────
    /// <summary>Appelé par ARImageCubeOverlay pour adapter à la vraie taille.</summary>
    public void SetImageSize(Vector2 size)
    {
        _imageSize = size;
    }

    // ─────────────────────────────────────────────────────────────
    public void PlayCorrectEffect()
    {
        if (_triggered) return;
        _triggered = true;
        StartCoroutine(BounceIn());
    }

    // ─────────────────────────────────────────────────────────────
    IEnumerator BounceIn()
    {
        // Petit bounce d'entrée
        Vector3 orig = transform.localScale;
        for (float t = 0f; t < 0.4f; t += Time.deltaTime)
        {
            float s = 1f + Mathf.Sin(t / 0.4f * Mathf.PI) * 0.3f;
            transform.localScale = orig * s;
            yield return null;
        }
        transform.localScale = orig;

        // Activer les items
        _itemRoot.SetActive(true);

        // Boucle d'animation infinie
        while (true)
        {
            float now   = Time.time;
            float halfW = _imageSize.x * 0.5f;
            float halfH = _imageSize.y * 0.5f;
            float perim = 2f * (_imageSize.x + _imageSize.y);

            foreach (var item in _items)
            {
                // Avance sur le périmètre
                item.perimPos = (item.perimPos + item.speed * Time.deltaTime) % perim;

                // Convertit la position sur le périmètre en coordonnées locales
                Vector3 localPos = PerimToLocal(item.perimPos, halfW, halfH, perim);
                item.obj.transform.localPosition = localPos;

                // Rotation sur soi-même
                item.obj.transform.localRotation =
                    Quaternion.Euler(0f, now * item.rotSpeed, now * item.rotSpeed * 0.7f);

                // Pulse de taille
                float pulse = 0.85f + Mathf.Sin(now * 5f + item.perimPos) * 0.15f;
                float size  = (item.isStar ? 0.022f : 0.018f) * pulse;
                item.obj.transform.localScale = Vector3.one * size;

                // Pulse de couleur/emission
                Color c = item.color;
                item.mr.material.color = c;
                item.mr.material.SetColor("_EmissionColor", c * (1.2f + pulse * 0.8f));
            }

            yield return null;
        }
    }

    // ─────────────────────────────────────────────────────────────
    /// <summary>
    /// Convertit une position linéaire sur le périmètre en
    /// coordonnée locale XZ (le cube est plat, Y=hauteur du cube).
    /// Sens : haut → droite → bas → gauche.
    /// </summary>
    Vector3 PerimToLocal(float pos, float halfW, float halfH, float perim)
    {
        float p = ((pos % perim) + perim) % perim;
        float yOff = 0.025f; // légèrement au-dessus du cube

        // Côté haut (gauche → droite)
        if (p < _imageSize.x)
            return new Vector3(-halfW + p, yOff, -halfH);

        p -= _imageSize.x;

        // Côté droit (haut → bas)
        if (p < _imageSize.y)
            return new Vector3(halfW, yOff, -halfH + p);

        p -= _imageSize.y;

        // Côté bas (droite → gauche)
        if (p < _imageSize.x)
            return new Vector3(halfW - p, yOff, halfH);

        p -= _imageSize.x;

        // Côté gauche (bas → haut)
        return new Vector3(-halfW, yOff, halfH - p);
    }

    // ─────────────────────────────────────────────────────────────
    void BuildItems()
    {
        _itemRoot = new GameObject("BorderItems");
        _itemRoot.transform.SetParent(transform, false);
        _itemRoot.transform.localPosition = Vector3.zero;
        _itemRoot.SetActive(false);

        float perim = 2f * (_imageSize.x + _imageSize.y);

        for (int i = 0; i < ItemCount; i++)
        {
            bool  isStar = (i % 3 != 1); // 2/3 étoiles, 1/3 confettis
            Color color  = Palette[i % Palette.Length];

            GameObject go = new GameObject(isStar ? "Star_" + i : "Confetti_" + i);
            go.transform.SetParent(_itemRoot.transform, false);

            MeshFilter mf = go.AddComponent<MeshFilter>();
            mf.mesh = isStar
                ? CreateStarMesh(5, 0.5f, 0.20f)
                : CreateQuadMesh(1.4f, 0.6f);

            MeshRenderer mr = go.AddComponent<MeshRenderer>();
            Material mat    = new Material(GetShader());
            mat.color       = color;
            mat.EnableKeyword("_EMISSION");
            mat.SetColor("_EmissionColor", color * 2f);
            mat.renderQueue = 3002;
            mr.material     = mat;
            mr.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
            mr.receiveShadows    = false;

            var item = new BorderItem
            {
                obj      = go,
                mr       = mr,
                perimPos = (i / (float)ItemCount) * perim, // répartis uniformément
                speed    = 0.08f + (i % 4) * 0.02f,        // vitesses légèrement différentes
                rotSpeed = 60f + (i % 5) * 30f,
                color    = color,
                isStar   = isStar,
            };
            _items.Add(item);
        }
    }

    // ─────────────────────────────────────────────────────────────
    //  MESHES
    // ─────────────────────────────────────────────────────────────

    Mesh CreateStarMesh(int points, float outerR, float innerR)
    {
        int total       = points * 2;
        Vector3[] verts = new Vector3[total + 1];
        int[]     tris  = new int[total * 3];

        verts[0] = Vector3.zero;
        for (int i = 0; i < total; i++)
        {
            float angle  = Mathf.PI / 2f + i * Mathf.PI / points;
            float radius = (i % 2 == 0) ? outerR : innerR;
            verts[i + 1] = new Vector3(
                Mathf.Cos(angle) * radius,
                Mathf.Sin(angle) * radius, 0f);
        }
        for (int i = 0; i < total; i++)
        {
            int next    = (i + 1) % total;
            tris[i*3]   = 0;
            tris[i*3+1] = i    + 1;
            tris[i*3+2] = next + 1;
        }
        Mesh mesh      = new Mesh();
        mesh.vertices  = verts;
        mesh.triangles = tris;
        mesh.RecalculateNormals();
        return mesh;
    }

    Mesh CreateQuadMesh(float w, float h)
    {
        float hw = w * 0.5f, hh = h * 0.5f;
        Mesh mesh = new Mesh();
        mesh.vertices = new Vector3[]
        {
            new Vector3(-hw, 0f, -hh),
            new Vector3( hw, 0f, -hh),
            new Vector3( hw, 0f,  hh),
            new Vector3(-hw, 0f,  hh),
        };
        // double face
        mesh.triangles = new int[] { 0,2,1, 0,3,2, 0,1,2, 0,2,3 };
        mesh.RecalculateNormals();
        return mesh;
    }

    // ─────────────────────────────────────────────────────────────
    static Shader GetShader()
    {
        Shader s = Shader.Find("Universal Render Pipeline/Lit");
        if (s != null) return s;
        return Shader.Find("Standard");
    }
}