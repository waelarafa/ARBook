/*version 08/04*/
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

        [Header("Actions communes")]
        public bool doScale;
        public float scaleMultiplier = 1.5f;
        public float scaleDuration   = 0.2f;

        [Header("Prefab (optionnel)")]
        [Tooltip("Cocher pour activer le spawn d'un prefab au tap")]
        public bool       doSpawn;
        public GameObject prefabToSpawn;
        public bool       lookAtCamera;

        [Header("Actions sur le prefab spawné")]
        public bool        doPlaySound;
        public SoundConfig soundConfig;      // ← remplace AudioClip
        public bool        doDestroyOnTap;
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