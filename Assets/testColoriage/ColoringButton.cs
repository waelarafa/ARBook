using UnityEngine;

public class ColoringButton : MonoBehaviour
{
    public ActivityMapManager activityMapManager;

    public void OnClick()
    {
        activityMapManager.OpenActivity("coloring");
    }
}
/*using UnityEngine;

public class ColoringButton : MonoBehaviour
{
    public string themeId = "";
    public string bookId  = "";

    public void OnClick()
    {
        //AnalyticsManager.Instance?.LogActivityEntered(bookId, themeId, "coloriage");
        ColoringManager.Instance.OpenGame();
    }
}*/