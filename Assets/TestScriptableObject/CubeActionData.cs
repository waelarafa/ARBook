// ImageCubeDataLibrary.cs
using UnityEngine;
using System.Collections.Generic;

[CreateAssetMenu(fileName = "ImageCubeDataLibrary", menuName = "AR/Image Cube Data Library")]
public class ImageCubeDataLibrary : ScriptableObject
{
    public enum TapTargetType
    {
        Image,
        Prefab
    }

    [System.Serializable]
    public class ImageDataEntry
    {
        [Tooltip("Nom exact de l'image dans l'AR Reference Image Library")]
        public string imageName;

        [Header("Type de cible")]
        public TapTargetType targetType;

        [Header("Actions communes")]
        public bool doScale;
        public float scaleMultiplier = 1.5f;
        public float scaleDuration = 0.2f;

        [Header("Actions si targetType = Image")]
        public bool doSpawn;
        public GameObject prefabToSpawn;
        public Vector3 spawnOffset;
        public bool lookAtCamera;

        [Header("Actions si targetType = Prefab")]
        public bool doPlaySound;
        public AudioClip soundToPlay;
        public bool doDestroyOnTap;
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