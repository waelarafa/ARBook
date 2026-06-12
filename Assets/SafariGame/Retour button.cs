using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class Retoursafari : MonoBehaviour
{
    public void Retour()
    {
        //AnalyticsManager.Instance?.LogActivityExited();
        SceneManager.LoadScene("ActivityScene", LoadSceneMode.Single);
    }
}