using UnityEngine;
using UnityEditor;
using System.Collections.Generic;

public class SoundConfigTool : EditorWindow
{
    [SerializeField]
    private List<AudioClip> clips = new List<AudioClip>(); // ✅ utiliser List

    [SerializeField]
    private SoundConfig templateConfig;

    private string savePath = "Assets/SoundConfigs";

    private SerializedObject serializedObject;
    private SerializedProperty clipsProperty;
    private SerializedProperty templateProperty;

    [MenuItem("Window/AR Book/Sound Config Tool")]
    public static void ShowWindow()
    {
        GetWindow<SoundConfigTool>("Sound Config Tool");
    }

    private void OnEnable()
    {
        serializedObject = new SerializedObject(this);
        clipsProperty = serializedObject.FindProperty("clips");
        templateProperty = serializedObject.FindProperty("templateConfig");
    }

    void OnGUI()
    {
        serializedObject.Update();

        GUILayout.Label("🎵 Sound Config Generator", EditorStyles.boldLabel);

        // ✅ affichage propre + drag & drop
        EditorGUILayout.PropertyField(clipsProperty, true);

        EditorGUILayout.Space();

        savePath = EditorGUILayout.TextField("Save Path", savePath);

        EditorGUILayout.Space();
        EditorGUILayout.Space();

        EditorGUILayout.LabelField("Template Config", EditorStyles.boldLabel);
        EditorGUILayout.PropertyField(templateProperty);

        if (GUILayout.Button("Generate SoundConfigs"))
        {
            GenerateConfigs();
        }

        serializedObject.ApplyModifiedProperties();
    }

    void GenerateConfigs()
    {
        if (clips == null || clips.Count == 0)
        {
            Debug.LogWarning("No clips assigned!");
            return;
        }

        // ✅ créer le dossier s'il n'existe pas
        if (!AssetDatabase.IsValidFolder(savePath))
        {
            AssetDatabase.CreateFolder("Assets", "SoundConfigs");
        }

        foreach (var clip in clips)
        {
            if (clip == null) continue;

            SoundConfig config = ScriptableObject.CreateInstance<SoundConfig>();

            // 🔥 Copier depuis template
            config.allowOverlap = templateConfig.allowOverlap;
            config.cooldown = templateConfig.cooldown;
            config.volume = templateConfig.volume;

            // 🎵 assigner le clip
            config.clip = clip;

            string path = $"{savePath}/{clip.name}_Config.asset";

            AssetDatabase.CreateAsset(config, path);
        }

        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();

        Debug.Log("✅ SoundConfigs generated!");
    }
}