using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class RetourMenu : MonoBehaviour
{
    public void Retour()
    {
        StartCoroutine(RetourAvecNettoyage());
    }

    IEnumerator RetourAvecNettoyage()
    {
        // Détruit TOUT dans DontDestroyOnLoad automatiquement
        foreach (GameObject go in
            Resources.FindObjectsOfTypeAll<GameObject>())
        {
            if (go.scene.name == "DontDestroyOnLoad")
                Destroy(go);
        }

        yield return new WaitForSeconds(0.3f);

        SceneManager.LoadScene("menuscene", LoadSceneMode.Single);
    }
}
/*using UnityEngine;
using UnityEngine.SceneManagement;

public class RetourMenu : MonoBehaviour
{
    public void Retour()
    {
        
        SceneManager.LoadScene("menuscene");
    }
}*/