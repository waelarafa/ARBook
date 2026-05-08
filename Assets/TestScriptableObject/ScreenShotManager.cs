// ScreenshotManager.cs
// Capture l'écran AR et enregistre dans la galerie Android (MediaStore API).
// Attacher ce script sur le même GameObject que AROverlayUI (ou tout GameObject persistant).

using System;
using System.Collections;
using System.IO;
using UnityEngine;

public class ScreenshotManager : MonoBehaviour
{
    public static ScreenshotManager Instance { get; private set; }

    // ─────────────────────────────────────────────────────────────
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    // ─────────────────────────────────────────────────────────────
    /// <summary>
    /// Appel principal depuis AROverlayUI quand le bouton photo est tapé.
    /// </summary>
    public void TakeAndSaveScreenshot()
    {
        StartCoroutine(CaptureCoroutine());
    }

    // ─────────────────────────────────────────────────────────────
    private IEnumerator CaptureCoroutine()
    {
        // Attend la fin du rendu pour avoir l'image AR complète
        yield return new WaitForEndOfFrame();

        Texture2D screenshot = new Texture2D(Screen.width, Screen.height, TextureFormat.RGB24, false);
        screenshot.ReadPixels(new Rect(0, 0, Screen.width, Screen.height), 0, 0);
        screenshot.Apply();

        byte[] pngData = screenshot.EncodeToPNG();
        Destroy(screenshot);

        string fileName = "AR_Photo_" + DateTime.Now.ToString("yyyyMMdd_HHmmss") + ".png";

#if UNITY_ANDROID && !UNITY_EDITOR
        SaveToAndroidGallery(pngData, fileName);
#else
        // Éditeur Unity : sauvegarde locale pour tester
        string path = Path.Combine(Application.persistentDataPath, fileName);
        File.WriteAllBytes(path, pngData);
        Debug.Log("📸 [EDITOR] Screenshot sauvegardé : " + path);
#endif
    }

    // ─────────────────────────────────────────────────────────────
    // Android : écriture dans Pictures/ARAnimalApp + scan galerie
    // ─────────────────────────────────────────────────────────────
#if UNITY_ANDROID && !UNITY_EDITOR
    private void SaveToAndroidGallery(byte[] pngData, string fileName)
    {
        try
        {
            // Récupère le dossier public Pictures
            AndroidJavaClass  environment = new AndroidJavaClass("android.os.Environment");
            AndroidJavaObject picturesDir = environment.CallStatic<AndroidJavaObject>(
                                               "getExternalStoragePublicDirectory",
                                               environment.GetStatic<string>("DIRECTORY_PICTURES"));

            // Sous-dossier propre à l'application
            string appFolder = Path.Combine(picturesDir.Call<string>("getAbsolutePath"), "ARAnimalApp");
            Directory.CreateDirectory(appFolder);

            string fullPath = Path.Combine(appFolder, fileName);
            File.WriteAllBytes(fullPath, pngData);

            // Notifie la galerie Android pour que la photo apparaisse immédiatement
            AndroidJavaClass  unityPlayer = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
            AndroidJavaObject context     = unityPlayer.GetStatic<AndroidJavaObject>("currentActivity");

            AndroidJavaObject mediaScan = new AndroidJavaObject("android.media.MediaScannerConnection");
            mediaScan.CallStatic(
                "scanFile",
                context,
                new string[] { fullPath },
                new string[] { "image/png" },
                null);

            Debug.Log("📸 [ANDROID] Screenshot sauvegardé : " + fullPath);

            // Toast natif Android
            ShowToast(context, "Photo enregistree dans la galerie !");
        }
        catch (Exception ex)
        {
            Debug.LogError("Erreur screenshot : " + ex.Message);
        }
    }

    // ─────────────────────────────────────────────────────────────
    private void ShowToast(AndroidJavaObject context, string message)
    {
        AndroidJavaClass  toastClass = new AndroidJavaClass("android.widget.Toast");
        AndroidJavaObject toast      = toastClass.CallStatic<AndroidJavaObject>(
                                           "makeText",
                                           context,
                                           message,
                                           toastClass.GetStatic<int>("LENGTH_SHORT"));
        toast.Call("show");
    }
#endif
}