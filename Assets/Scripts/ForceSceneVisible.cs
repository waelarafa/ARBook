using UnityEngine;

public class ForceSceneVisible : MonoBehaviour
{
    void Start()
    {
        Debug.Log("🔥 FORCE SCENE VISIBLE");

        Camera cam = Camera.main;

        if (cam != null)
        {
            cam.backgroundColor = Color.red;
            cam.clearFlags = CameraClearFlags.SolidColor;
        }
    }
}