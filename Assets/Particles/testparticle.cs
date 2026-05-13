using UnityEngine;

public class CubeParticleTest : MonoBehaviour
{
    [SerializeField] private GameObject particlePrefab;

    private GameObject particleInstance;

    void Start()
    {
        if (particlePrefab == null)
        {
            Debug.LogError("❌ particlePrefab non assigné !");
            return;
        }

        // Spawn enfant du cube
        particleInstance = Instantiate(particlePrefab, transform);

        // Seule la position est forcée au centre du cube
        particleInstance.transform.localPosition = Vector3.zero;

        Debug.Log("✨ Particules spawnées");
    }
}