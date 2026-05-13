using System.Collections;
using UnityEngine;

/// <summary>
/// Attacher sur chaque animal ET chaque nourriture.
/// Définir le même pairID sur l'animal et sa nourriture correspondante.
/// Ex: Lion → pairID = "lion" | Viande → pairID = "lion"
/// </summary>
public class PairableObject : MonoBehaviour
{
    [Header("Identité")]
    [Tooltip("ID partagé entre l'animal et sa nourriture. Doit être IDENTIQUE sur les deux.")]
    public string pairID = "animal_1";

    [Header("Scale")]
    [Tooltip("Taille agrandie quand sélectionné")]
    public Vector3 selectedScale = new Vector3(1.3f, 1.3f, 1.3f);

    [Tooltip("Durée de l'animation de scale (secondes)")]
    public float scaleDuration = 0.2f;

    // État
    private Vector3 _normalScale;
    private bool _isSelected = false;
    private Coroutine _scaleCoroutine;

    private void Start()
    {
        _normalScale = transform.localScale;
    }

    // ─── Sélection visuelle ──────────────────────────────────────────────────

    public void Select()
    {
        _isSelected = true;
        AnimateTo(selectedScale);
        Debug.Log($"[PairableObject] '{gameObject.name}' sélectionné (pairID={pairID})");
    }

    public void Deselect()
    {
        _isSelected = false;
        AnimateTo(_normalScale);
        Debug.Log($"[PairableObject] '{gameObject.name}' désélectionné");
    }

    public bool IsSelected => _isSelected;

    // ─── Match réussi ────────────────────────────────────────────────────────

    public void OnMatchSuccess()
    {
        StartCoroutine(MatchAnimation());
    }

    private IEnumerator MatchAnimation()
    {
        // Petite animation de victoire : scale up puis disparaît
        float elapsed = 0f;
        float duration = 0.4f;
        Vector3 start = transform.localScale;
        Vector3 big = start * 1.5f;

        while (elapsed < duration / 2f)
        {
            elapsed += Time.deltaTime;
            transform.localScale = Vector3.Lerp(start, big, elapsed / (duration / 2f));
            yield return null;
        }

        elapsed = 0f;
        while (elapsed < duration / 2f)
        {
            elapsed += Time.deltaTime;
            transform.localScale = Vector3.Lerp(big, Vector3.zero, elapsed / (duration / 2f));
            yield return null;
        }

        Destroy(gameObject);
    }

    // ─── Mauvais match : shake ───────────────────────────────────────────────

    public void OnWrongMatch()
    {
        StartCoroutine(ShakeAnimation());
    }

    private IEnumerator ShakeAnimation()
    {
        Vector3 originalPos = transform.localPosition;
        float elapsed = 0f;
        float duration = 0.4f;
        float intensity = 0.05f;

        while (elapsed < duration)
        {
            elapsed += Time.deltaTime;
            float x = originalPos.x + Mathf.Sin(elapsed * 60f) * intensity;
            transform.localPosition = new Vector3(x, originalPos.y, originalPos.z);
            yield return null;
        }

        transform.localPosition = originalPos;
        Deselect();
    }

    // ─── Utilitaire scale ────────────────────────────────────────────────────

    private void AnimateTo(Vector3 target)
    {
        if (_scaleCoroutine != null)
            StopCoroutine(_scaleCoroutine);
        _scaleCoroutine = StartCoroutine(ScaleCoroutine(target));
    }

    private IEnumerator ScaleCoroutine(Vector3 target)
    {
        Vector3 start = transform.localScale;
        float elapsed = 0f;

        while (elapsed < scaleDuration)
        {
            elapsed += Time.deltaTime;
            float t = Mathf.Clamp01(elapsed / scaleDuration);
            // EaseOut
            t = 1f - (1f - t) * (1f - t);
            transform.localScale = Vector3.Lerp(start, target, t);
            yield return null;
        }

        transform.localScale = target;
    }
}