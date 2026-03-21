using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.Networking;
using System;

[RequireComponent(typeof(ARTrackedImageManager))]
public class CloudImageLoader : MonoBehaviour
{
    private ARTrackedImageManager trackedImageManager;
    private MutableRuntimeReferenceImageLibrary mutableLibrary;

    public string baseURL =
        "https://tesnimemechmech.github.io/ar-livre-assets/";

    public bool imagesChargees = false;

    void Awake()
    {
        trackedImageManager = GetComponent<ARTrackedImageManager>();

        var runtimeLibrary = trackedImageManager.CreateRuntimeLibrary();
        mutableLibrary = runtimeLibrary as MutableRuntimeReferenceImageLibrary;

        if (mutableLibrary == null)
        {
            Debug.LogError("❌ Mutable library non supportée !");
            return;
        }

        trackedImageManager.referenceLibrary = mutableLibrary;
        Debug.Log("✅ Librairie runtime créée !");
    }

    public IEnumerator ChargerImages(List<string> imageNames, Action onTermine)
    {
        Debug.Log("📥 Chargement de " + imageNames.Count + " images...");

        foreach (string imageName in imageNames)
        {
            yield return StartCoroutine(TelechargerEtAjouter(imageName));
        }

        imagesChargees = true;
        Debug.Log("✅ Toutes les images chargées !");

        onTermine?.Invoke();
    }

    IEnumerator TelechargerEtAjouter(string imageName)
    {
        string url = baseURL + imageName + ".jpg";
        Debug.Log("📥 Téléchargement : " + url);

        UnityWebRequest request = UnityWebRequestTexture.GetTexture(url);
        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            Texture2D texture = DownloadHandlerTexture.GetContent(request);

            // Convertir en RGB24 pour AR Foundation
            Texture2D textureRGB = new Texture2D(
                texture.width,
                texture.height,
                TextureFormat.RGB24,
                false
            );
            textureRGB.SetPixels(texture.GetPixels());
            textureRGB.Apply();

            Debug.Log($"🖼️ {imageName} : {textureRGB.width}x{textureRGB.height} format:{textureRGB.format}");

            yield return StartCoroutine(AjouterImage(textureRGB, imageName));
        }
        else
        {
            Debug.LogError("❌ Erreur téléchargement "
                + imageName + " : " + request.error);
        }
    }

    IEnumerator AjouterImage(Texture2D texture, string imageName)
    {
        // Taille physique selon l'image
        float taillePhysique = 0.1f; // défaut animaux

        // La feuille A4 = 0.21m (21cm largeur)
        if (imageName == "fv")
            taillePhysique = 0.21f;

        var jobState = mutableLibrary.ScheduleAddImageWithValidationJob(
            texture,
            imageName,
            taillePhysique
        );

        while (jobState.status == AddReferenceImageJobStatus.Pending)
        {
            yield return null;
        }

        Debug.Log($"🔍 Status final '{imageName}' : {jobState.status}");

        if (jobState.status == AddReferenceImageJobStatus.Success)
        {
            Debug.Log("✅ '" + imageName + "' prête !");
        }
        else if (jobState.status == AddReferenceImageJobStatus.ErrorUnknown)
        {
            Debug.LogError("❌ Erreur inconnue : " + imageName);
        }
        else if (jobState.status == AddReferenceImageJobStatus.ErrorInvalidImage)
        {
            Debug.LogError("❌ Image invalide : " + imageName);
        }
    }
}