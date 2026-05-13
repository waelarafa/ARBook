using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class tapsafari : MonoBehaviour
{
    public void Retour()
    {
        SceneManager.LoadScene("testingscene", LoadSceneMode.Single);
    }
}