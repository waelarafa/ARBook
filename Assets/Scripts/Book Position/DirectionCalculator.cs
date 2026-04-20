using UnityEngine;

public class DirectionCalculator : MonoBehaviour
{
    [Header("AR Camera")]
    public Camera arCamera;

    public float AngleToBook { get; private set; }
    public Vector2 ScreenDirection { get; private set; }

    private void Update()
    {
        if (!BookPositionMemory.BookDetected) return;

        // 🔥 1. Convertir position monde → écran (viewport 0 → 1)
        Vector3 viewportPos = arCamera.WorldToViewportPoint(BookPositionMemory.BookWorldPosition);

        // 🔥 2. Centre de l’écran = (0.5, 0.5)
        Vector2 screenCenter = new Vector2(0.5f, 0.5f);

        // 🔥 3. Direction du centre vers le livre
        ScreenDirection = new Vector2(
            viewportPos.x - screenCenter.x,
            viewportPos.y - screenCenter.y
        );

        // 🔥 4. Calcul de l’angle (IMPORTANT)
        AngleToBook = Mathf.Atan2(ScreenDirection.y, ScreenDirection.x) * Mathf.Rad2Deg;
    }
}