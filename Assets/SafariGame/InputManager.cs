using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.EnhancedTouch;
using Touch = UnityEngine.InputSystem.EnhancedTouch.Touch;
using TouchPhase = UnityEngine.InputSystem.TouchPhase;

/// <summary>
/// Gère les inputs souris (Editor) et touch (Android).
/// Détecte les PairableObject via Raycast et notifie le GameManager.
/// </summary>
public class InputManager : MonoBehaviour
{
    [Header("Raycast")]
    public Camera raycastCamera;
    public float maxRaycastDistance = 100f;
    public LayerMask tappableLayer = ~0;

    private void Awake()
    {
        if (raycastCamera == null)
            raycastCamera = Camera.main;

        EnhancedTouchSupport.Enable();
    }

    private void OnDestroy()
    {
        EnhancedTouchSupport.Disable();
    }

    private void Update()
    {
#if UNITY_EDITOR || UNITY_STANDALONE
        HandleMouseInput();
#else
        HandleTouchInput();
#endif
    }

    private void HandleMouseInput()
    {
        var mouse = Mouse.current;
        if (mouse == null) return;

        if (mouse.leftButton.wasPressedThisFrame)
            PerformRaycast(mouse.position.ReadValue());
    }

    private void HandleTouchInput()
    {
        foreach (Touch touch in Touch.activeTouches)
        {
            if (touch.phase == TouchPhase.Began)
                PerformRaycast(touch.screenPosition);
        }
    }

    private void PerformRaycast(Vector2 screenPosition)
    {
        if (raycastCamera == null) return;

        Ray ray = raycastCamera.ScreenPointToRay(screenPosition);

        if (Physics.Raycast(ray, out RaycastHit hit, maxRaycastDistance, tappableLayer))
        {
            // Chercher un PairableObject sur l'objet ou ses parents
            PairableObject pairable = hit.collider.GetComponentInParent<PairableObject>();

            if (pairable != null)
            {
                Debug.Log($"[InputManager] Tap sur : {hit.collider.name} (pairID={pairable.pairID})");
                GameManager.Instance?.OnObjectTapped(pairable);
            }
        }
    }
}