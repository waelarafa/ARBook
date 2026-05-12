using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class MenuManager : MonoBehaviour
{
    public void OuvrirSceneAR()
    {
        StartCoroutine(ChargerScene("GymTesnime"));
    }

    public void OuvrirSceneMap()
    {
        StartCoroutine(ChargerScene("3DScene"));
    }
    public void OuvrirActivityScene()
    {
        StartCoroutine(ChargerScene("ActivityScene"));
    }

    IEnumerator ChargerScene(string sceneName)
    {
        // Détruit TOUT dans DontDestroyOnLoad automatiquement
        foreach (GameObject go in
            Resources.FindObjectsOfTypeAll<GameObject>())
        {
            if (go.scene.name == "DontDestroyOnLoad")
                Destroy(go);
        }

        yield return new WaitForSeconds(0.3f);

        SceneManager.LoadScene(sceneName, LoadSceneMode.Single);
    }
}
/*using UnityEngine;
using UnityEngine.SceneManagement;

public class MenuManager : MonoBehaviour
{
    public void OuvrirSceneAR()
    {
        SceneManager.LoadScene("GymTesnime");
    }

    public void OuvrirSceneMap()
    {
        SceneManager.LoadScene("testing design");
    }
}*/