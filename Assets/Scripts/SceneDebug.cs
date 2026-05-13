using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneDebug : MonoBehaviour
{
    void Start()
    {
        Debug.Log("✅ GYMTESNIME START");
        Debug.Log("Scene active : " + SceneManager.GetActiveScene().name);
    }
}