using UnityEngine;
using UnityEngine.SceneManagement;

public class RetourMenu : MonoBehaviour
{
    public void Retour()
    {
        AnalyticsManager.Instance?.LogChildSessionEnded();
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