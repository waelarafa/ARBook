using UnityEngine;
using UnityEngine.InputSystem; // Indispensable pour le nouveau système

public class TapTester : MonoBehaviour
{
    void Update()
    {
        // On vérifie si la souris existe et si le bouton gauche est pressé ce cadre
        if (Mouse.current != null && Mouse.current.leftButton.wasPressedThisFrame)
        {
            // On récupère la position via Mouse.current
            Vector2 mousePosition = Mouse.current.position.ReadValue();
            Ray ray = Camera.main.ScreenPointToRay(mousePosition);

            if (Physics.Raycast(ray, out RaycastHit hit))
            {
                Debug.Log($"[TapTester] Objet touché : {hit.collider.gameObject.name}");
                AudioInteractable audio = hit.collider.GetComponent<AudioInteractable>();

                if (audio != null)
                {
                    audio.OnTap();
                }
            }
        }
    }
}