using UnityEngine;
using UnityEngine.SceneManagement;

public class RetourLibrary : MonoBehaviour
{
    public void Retour()
    {
        // Indiquer qu'on veut ouvrir panel_Library au retour
        PlayerPrefs.SetString("open_panel", "library");
        PlayerPrefs.Save();

        AnalyticsManager.Instance?.LogChildSessionEnded();
        SceneManager.LoadScene("LoginV2"); // ← nom de ta scène auth
    }
}