using UnityEngine;
using UnityEngine.InputSystem;

public class TestHighlightRunner : MonoBehaviour
{
    private ImageHighlight _hl;

    void Start()
    {
        // Simule la taille d'un cube AR (image ~20cm x 20cm)
        transform.localScale = new Vector3(0.20f, 0.005f, 0.20f);

        _hl = gameObject.AddComponent<ImageHighlight>();
        _hl.PlayCorrectEffect();
    }

    void Update()
    {
        // Appuyez sur R pour relancer l'animation
        if (Keyboard.current != null && Keyboard.current.rKey.wasPressedThisFrame)
        {
            Destroy(_hl);
            Invoke(nameof(Restart), 0.05f);
        }
    }

    void Restart()
    {
        _hl = gameObject.AddComponent<ImageHighlight>();
        _hl.PlayCorrectEffect();
    }
}