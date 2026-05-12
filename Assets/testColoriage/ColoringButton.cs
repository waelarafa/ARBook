using UnityEngine;

public class ColoringButton : MonoBehaviour
{
    public void OnClick()
    {
        ColoringManager.Instance.OpenGame();
    }
}