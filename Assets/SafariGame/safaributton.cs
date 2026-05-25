using UnityEngine;
using UnityEngine.SceneManagement;

public class SafariButton : MonoBehaviour
{
    public string bookId  = "";
    public string themeId = "";

    public void OnClick()
    {
        AnalyticsManager.Instance?.LogActivityEntered(bookId, themeId, "safari");
        SceneManager.LoadScene("testingscene", LoadSceneMode.Single);
    }
}