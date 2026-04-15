/*version 14/04 - avec sensibilité rotation*/
// ImageCubeDataLibrary.cs
using UnityEngine;
using System.Collections.Generic;

[CreateAssetMenu(fileName = "ImageCubeDataLibrary", menuName = "AR/Image Cube Data Library")]
public class ImageCubeDataLibrary : ScriptableObject
{
    [System.Serializable]
    public class ImageDataEntry
    {
        [Tooltip("Nom exact de l'image dans l'AR Reference Image Library")]
        public string imageName;

        [Header("Prefab à spawner au tap image")]
        public bool       doSpawn;
        public GameObject prefabToSpawn;

        [Header("Son — tap court sur le prefab")]
        public bool        doPlaySound;
        public SoundConfig soundConfig;

        [Header("Scale — appui long sur le prefab")]
        [Tooltip("Facteur d'agrandissement au maintien")]
        public float scaleMultiplier = 1.5f;
        [Tooltip("Durée de l'animation scale (secondes)")]
        public float scaleDuration   = 0.2f;

        [Header("Rotation — drag sur le prefab")]
        [Tooltip("Sensibilité de la rotation par glissement (degrés/pixel). 0 = non rotatif")]
        public float rotationSensitivity = 0.3f;
    }

    public List<ImageDataEntry> entries = new List<ImageDataEntry>();

    public ImageDataEntry GetEntryForImage(string imageName)
    {
        foreach (var entry in entries)
            if (entry.imageName == imageName)
                return entry;

        Debug.LogWarning("⚠️ Aucune entrée trouvée pour : " + imageName);
        return null;
    }
}