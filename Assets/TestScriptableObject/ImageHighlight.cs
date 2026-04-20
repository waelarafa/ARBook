using UnityEngine;
using System.Collections;
using UnityEngine.XR.ARFoundation;

/// <summary>
/// Étoile badge dorée dans le coin supérieur gauche de l'image.
/// Le cube parent reste (pour le tap detector).
/// L'étoile est placée en world space pour être visible en AR mobile.
/// Corrections build mobile :
///   - Shader Unlit opaque (pas de transparence fragile)
///   - XRCamera passée explicitement (Camera.main peut être null en AR)
///   - SetParent(null) pour survivre aux SetActive du cube
/// </summary>
public class ImageHighlight : MonoBehaviour
{
    // Assignés par ARImageCubeOverlay au spawn
    public ARTrackedImage TrackedImage;
    public Camera         XRCamera;

    private bool         _triggered = false;
    private GameObject   _starObj;
    private MeshRenderer _starMR;

    // ── Réglages facilement ajustables ───────────────────────────
    private const float StarFinalSize = 0.025f;  // taille world (mètres)
    private const float StarOffsetUp  = 0.010f;  // hauteur au-dessus du plan AR
    private const float GrowDuration  = 1.2f;    // durée croissance (secondes)

    // ─────────────────────────────────────────────────────────────
    void Awake()
    {
        BuildStar();
    }

    void OnDestroy()
    {
        StopAllCoroutines();
        // _starObj est enfant du cube — détruit automatiquement avec lui
    }

    public void SetImageSize(Vector2 size) { } // conservé pour compatibilité

    // ─────────────────────────────────────────────────────────────
    public void PlayCorrectEffect()
    {
        if (_triggered) return;
        _triggered = true;
        StartCoroutine(GrowAndShimmer());
    }

    // ─────────────────────────────────────────────────────────────
    IEnumerator GrowAndShimmer()
    {
        // L'étoile reste ENFANT du cube — pas de SetParent(null)
        // Le cube a localScale = (imageW, 0.005, imageH)
        // Pour compenser : localScale de l'étoile = StarFinalSize / cubeScale
        // et localPosition.Y élevé pour sortir au-dessus du cube

        _starObj.SetActive(true);

        // Calcul du scale local compensé
        // transform.lossyScale = scale world du cube parent
        Vector3 parentScale = transform.lossyScale;
        float   compX = StarFinalSize / Mathf.Max(parentScale.x, 0.0001f);
        float   compY = StarFinalSize / Mathf.Max(parentScale.y, 0.0001f);
        float   compZ = StarFinalSize / Mathf.Max(parentScale.z, 0.0001f);
        Vector3 targetLocalScale = new Vector3(compX, compY, compZ);

        // Position locale : coin supérieur gauche + au-dessus
        // En local normalisé : X=-0.5 (bord gauche), Z=-0.5 (bord haut)
        // Y = 10f → compense le cubeHeight=0.005 pour sortir bien au-dessus
        float localY   = StarOffsetUp / Mathf.Max(parentScale.y, 0.0001f);
        float localX   = -0.5f - (StarFinalSize * 0.6f / Mathf.Max(parentScale.x, 0.0001f));
        float localZ   = -0.5f - (StarFinalSize * 0.6f / Mathf.Max(parentScale.z, 0.0001f));
        _starObj.transform.localPosition = new Vector3(localX, localY, localZ);

        Debug.Log("⭐ StarBadge DÉMARRÉ"
            + " | worldPos="    + _starObj.transform.position
            + " | localPos="    + _starObj.transform.localPosition
            + " | parentScale=" + parentScale
            + " | compScale="   + targetLocalScale
            + " | shader="      + _starMR.material.shader.name);

        // ── Phase 1 : croissance ──────────────────────────────────
        for (float t = 0f; t < GrowDuration; t += Time.deltaTime)
        {
            float ratio = t / GrowDuration;
            float scale = ratio < 0.8f
                ? Mathf.SmoothStep(0f, 1f, ratio / 0.8f)
                : 1f + Mathf.Sin((ratio - 0.8f) / 0.2f * Mathf.PI) * 0.15f;

            _starObj.transform.localScale = targetLocalScale * Mathf.Max(0f, scale);
            FaceCamera();

            _starMR.material.SetColor("_EmissionColor",
                new Color(1f, 0.75f, 0f) * (ratio * 5f));

            yield return null;
        }

        _starObj.transform.localScale = targetLocalScale;

        // ── Phase 2 : scintillement permanent ────────────────────
        while (true)
        {
            float now   = Time.time;
            float pulse = 1f + Mathf.Sin(now * 2.5f) * 0.08f;
            _starObj.transform.localScale = targetLocalScale * pulse;
            FaceCamera();

            float ep = (Mathf.Sin(now * 2f) + 1f) * 0.5f;
            _starMR.material.SetColor("_EmissionColor",
                new Color(1f, 0.75f, 0f) * (2.5f + ep * 3f));

            yield return null;
        }
    }

    // ─────────────────────────────────────────────────────────────
    Vector3 GetStarWorldPos()
    {
        if (TrackedImage != null)
        {
            Transform img  = TrackedImage.transform;
            Vector2   size = TrackedImage.size;

            // Coin supérieur gauche — légèrement à l'extérieur du bord
            return img.position
                 - img.right   * (size.x * 0.5f + StarFinalSize * 0.6f)
                 - img.forward * (size.y * 0.5f + StarFinalSize * 0.6f)
                 + img.up      * StarOffsetUp;
        }

        // Fallback scène de test (pas de TrackedImage)
        return transform.position
             - transform.right   * (transform.lossyScale.x * 0.5f + StarFinalSize * 0.6f)
             - transform.forward * (transform.lossyScale.z * 0.5f + StarFinalSize * 0.6f)
             + Vector3.up        * StarOffsetUp;
    }

    // ─────────────────────────────────────────────────────────────
    void FaceCamera()
    {
        Camera cam = XRCamera != null ? XRCamera : Camera.main;
        if (cam == null || _starObj == null) return;

        // Rotation world — LookRotation vers la caméra
        Vector3 dir = _starObj.transform.position - cam.transform.position;
        if (dir.sqrMagnitude > 0.0001f)
            _starObj.transform.rotation = Quaternion.LookRotation(dir);
    }

    // ─────────────────────────────────────────────────────────────
    void BuildStar()
    {
        _starObj = new GameObject("StarBadge");
        // Reste enfant du cube — pas de SetParent(null)
        _starObj.transform.SetParent(transform, false);
        _starObj.transform.localPosition = Vector3.zero;
        _starObj.transform.localScale    = Vector3.zero;
        _starObj.SetActive(false);

        MeshFilter mf = _starObj.AddComponent<MeshFilter>();
        mf.mesh = CreateStarMesh(5, 0.5f, 0.20f);

        _starMR = _starObj.AddComponent<MeshRenderer>();
        _starMR.material          = CreateStarMaterial();
        _starMR.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        _starMR.receiveShadows    = false;
    }

    // ─────────────────────────────────────────────────────────────
    Material CreateStarMaterial()
    {
        // Shader Unlit opaque — toujours visible sur mobile AR
        // Pas de dépendance à la transparence ni au ZTest
        Shader shader = Shader.Find("Universal Render Pipeline/Unlit");
        if (shader == null) shader = Shader.Find("Unlit/Color");
        if (shader == null) shader = Shader.Find("Standard");

        Material mat = new Material(shader);
        mat.color = new Color(1f, 0.85f, 0.05f); // or vif opaque

        if (mat.HasProperty("_EmissionColor"))
        {
            mat.EnableKeyword("_EMISSION");
            mat.SetColor("_EmissionColor", new Color(1f, 0.75f, 0f) * 3f);
        }

        mat.renderQueue      = 2000; // Opaque — rendu en priorité
        mat.enableInstancing = true;
        return mat;
    }

    // ─────────────────────────────────────────────────────────────
    Mesh CreateStarMesh(int points, float outerR, float innerR)
    {
        int total       = points * 2;
        Vector3[] verts = new Vector3[total + 1];
        int[]     tris  = new int[total * 3];

        verts[0] = Vector3.zero;
        for (int i = 0; i < total; i++)
        {
            float a = Mathf.PI / 2f + i * Mathf.PI / points;
            float r = (i % 2 == 0) ? outerR : innerR;
            verts[i+1] = new Vector3(Mathf.Cos(a)*r, Mathf.Sin(a)*r, 0f);
        }
        for (int i = 0; i < total; i++)
        {
            int next  = (i+1) % total;
            tris[i*3] = 0; tris[i*3+1] = i+1; tris[i*3+2] = next+1;
        }

        Mesh m = new Mesh();
        m.vertices  = verts;
        m.triangles = tris;
        m.RecalculateNormals();
        return m;
    }
}