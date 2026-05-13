using UnityEngine;

/// <summary>
/// Attacher sur GameManager.
/// Glisser le prefab de victoire dans victoryPrefab.
/// Appeler ShowVictory() depuis OnGameComplete.
/// </summary>
public class VictoryManager : MonoBehaviour
{
    [Tooltip("Glisse ton prefab de victoire ici")]
    public GameObject victoryPrefab;

    public void ShowVictory()
    {
        if (victoryPrefab != null)
        {
            Instantiate(victoryPrefab);
            Debug.Log("[VictoryManager] Victoire affichée !");
        }
        else
        {
            Debug.LogWarning("[VictoryManager] Aucun prefab de victoire assigné !");
        }
    }
}