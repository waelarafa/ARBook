using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class StarFrameWorldUI : MonoBehaviour
{
    [Header("Réglages cadre")]
    public int   starsPerSide  = 4;      // étoiles par côté
    public float frameWidth    = 0.3f;   // largeur du cadre autour du prefab
    public float frameHeight   = 0.3f;   // hauteur du cadre
    public float starSize      = 0.03f;  // taille de chaque étoile
    public float starOffset    = 0.01f;  // distance du bord

    private List<GameObject>   _starObjects   = new List<GameObject>();
    private List<MeshRenderer> _starRenderers = new List<MeshRenderer>();
    private bool _frameVisible = false;

    // ─────────────────────────────────────────────
    void Start()
    {
        BuildFrame();
        SetFrameVisible(false); // caché au départ
    }

    // ─────────────────────────────────────────────
    void BuildFrame()
    {
        _starObjects.Clear();
        _starRenderers.Clear();

        float hw = frameWidth  / 2f;
        float hh = frameHeight / 2f;

        // 4 côtés : top, bottom, left, right
        List<Vector3> positions = new List<Vector3>();

        // Top & Bottom
        for (int i = 0; i < starsPerSide; i++)
        {
            float t = (float)i / (starsPerSide - 1);
            float x = Mathf.Lerp(-hw, hw, t);

            positions.Add(new Vector3(x,  hh + starOffset, 0f)); // top
            positions.Add(new Vector3(x, -hh - starOffset, 0f)); // bottom
        }

        // Left & Right (sans les coins déjà placés)
        for (int i = 1; i < starsPerSide - 1; i++)
        {
            float t = (float)i / (starsPerSide - 1);
            float y = Mathf.Lerp(-hh, hh, t);

            positions.Add(new Vector3(-hw - starOffset, y, 0f)); // left
            positions.Add(new Vector3( hw + starOffset, y, 0f)); // right
        }

        foreach (Vector3 pos in positions)
        {
            GameObject star = new GameObject("FrameStar");
            star.transform.SetParent(transform, false);
            star.transform.localPosition = pos;
            star.transform.localScale    = Vector3.one * starSize;

            MeshFilter   mf = star.AddComponent<MeshFilter>();
            MeshRenderer mr = star.AddComponent<MeshRenderer>();
            mf.mesh = CreateStarMesh();

            Material mat = new Material(Shader.Find("Universal Render Pipeline/Lit"));
            mat.color = new Color(0.25f, 0.25f, 0.1f, 1f); // éteint
            mat.EnableKeyword("_EMISSION");
            mat.SetColor("_EmissionColor", Color.black);
            mr.material = mat;

            _starObjects.Add(star);
            _starRenderers.Add(mr);
        }
    }

    // ─────────────────────────────────────────────
    // Appelle depuis ARPrefabManager quand le prefab est spawné
    public void ShowFrame()
    {
        if (_frameVisible) return;
        _frameVisible = true;
        SetFrameVisible(true);
        StartCoroutine(AppearEffect());
        StartCoroutine(PulseLoop());
    }

    public void HideFrame()
    {
        _frameVisible = false;
        StopAllCoroutines();
        SetFrameVisible(false);
    }

    void SetFrameVisible(bool visible)
    {
        foreach (var star in _starObjects)
            if (star != null) star.SetActive(visible);
    }

    // ─────────────────────────────────────────────
    IEnumerator AppearEffect()
    {
        // Les étoiles apparaissent une par une en cascade
        for (int i = 0; i < _starRenderers.Count; i++)
        {
            MeshRenderer mr  = _starRenderers[i];
            if (mr == null) continue;

            Material mat = mr.material;
            mat.color    = new Color(1f, 0.85f, 0f);
            mat.SetColor("_EmissionColor", new Color(1f, 0.7f, 0f) * 2f);

            // Mini bounce
            StartCoroutine(StarBounce(_starObjects[i].transform));

            yield return new WaitForSeconds(0.04f);
        }
    }

    IEnumerator StarBounce(Transform t)
    {
        Vector3 baseScale = t.localScale;
        float elapsed = 0f;
        while (elapsed < 0.35f)
        {
            elapsed += Time.deltaTime;
            float s = 1f + Mathf.Sin(elapsed / 0.35f * Mathf.PI) * 0.7f;
            t.localScale = baseScale * s;
            yield return null;
        }
        t.localScale = baseScale * 1.1f;
    }

    IEnumerator PulseLoop()
    {
        // Pulse dorée continue sur tout le cadre
        while (true)
        {
            float pulse = (Mathf.Sin(Time.time * 2.5f) + 1f) / 2f;
            Color emCol = new Color(1f, 0.7f, 0f) * (0.6f + pulse * 1.8f);

            foreach (var mr in _starRenderers)
            {
                if (mr == null) continue;
                mr.material.SetColor("_EmissionColor", emCol);
            }
            yield return null;
        }
    }

    // ─────────────────────────────────────────────
    void LateUpdate()
    {
        // Le cadre fait toujours face à la caméra
        if (Camera.main == null) return;
        Vector3 dir = transform.position - Camera.main.transform.position;
        transform.rotation = Quaternion.LookRotation(dir);
    }

    // ─────────────────────────────────────────────
    Mesh CreateStarMesh()
    {
        int   points = 5;
        float outerR = 0.5f;
        float innerR = 0.21f;
        int   vCount = points * 2;

        Vector3[] verts = new Vector3[vCount + 1];
        int[]     tris  = new int[vCount * 3];

        verts[vCount] = Vector3.zero;

        for (int i = 0; i < vCount; i++)
        {
            float angle = i * Mathf.PI / points - Mathf.PI / 2f;
            float r     = (i % 2 == 0) ? outerR : innerR;
            verts[i]    = new Vector3(
                Mathf.Cos(angle) * r,
                Mathf.Sin(angle) * r,
                0f
            );
        }

        for (int i = 0; i < vCount; i++)
        {
            int next        = (i + 1) % vCount;
            tris[i * 3]     = vCount;
            tris[i * 3 + 1] = i;
            tris[i * 3 + 2] = next;
        }

        Mesh mesh      = new Mesh();
        mesh.vertices  = verts;
        mesh.triangles = tris;
        mesh.RecalculateNormals();
        return mesh;
    }
}