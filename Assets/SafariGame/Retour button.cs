using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class Retoursafari : MonoBehaviour
{
    public void Retour()
    {
        SceneManager.LoadScene("ActivityScene", LoadSceneMode.Single);
    }
}