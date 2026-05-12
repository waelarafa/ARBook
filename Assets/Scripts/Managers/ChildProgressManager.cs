using System;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Gère la progression persistante de l'enfant avec EasySave 3.
/// Complètement indépendant du système analytics.
/// </summary>
public class ChildProgressManager : MonoBehaviour
{
    public static ChildProgressManager Instance { get; private set; }

    private const string ES3_KEY = "child_progress";
    private ChildProgress _progress;

    // Événement pour notifier l'UI quand la progression change
    public event Action OnProgressChanged;

    // ══════════════════════════════════════════════════════════
    // INIT
    // ══════════════════════════════════════════════════════════

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        Load();
    }

    // ══════════════════════════════════════════════════════════
    // PERSISTANCE ES3
    // ══════════════════════════════════════════════════════════

    void Load()
    {
        if (ES3.KeyExists(ES3_KEY))
        {
            _progress = ES3.Load<ChildProgress>(ES3_KEY);
            Debug.Log($"[Progress] 📂 Progression chargée — " +
                      $"{_progress.unlockedThemes.Count} thème(s), " +
                      $"{_progress.completedActivities.Count} activité(s)");
        }
        else
        {
            _progress = new ChildProgress();
            // Thème de départ toujours débloqué
            _progress.unlockedThemes.Add("theme_forest");
            Save();
            Debug.Log("[Progress] 🆕 Nouvelle progression créée");
        }
    }

    void Save()
    {
        _progress.lastUpdated = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
        ES3.Save(ES3_KEY, _progress);
        Debug.Log("[Progress] 💾 Progression sauvegardée");
        OnProgressChanged?.Invoke();
    }

    // ══════════════════════════════════════════════════════════
    // API PUBLIQUE — THÈMES
    // ══════════════════════════════════════════════════════════

    /// Débloque un thème/monde
    public void UnlockTheme(string themeId)
    {
        if (_progress.unlockedThemes.Contains(themeId)) return;
        _progress.unlockedThemes.Add(themeId);
        Save();
        Debug.Log($"[Progress] 🔓 Thème débloqué : {themeId}");
    }

    /// Vérifie si un thème est débloqué
    public bool IsThemeUnlocked(string themeId)
        => _progress.unlockedThemes.Contains(themeId);

    /// Retourne tous les thèmes débloqués
    public List<string> GetUnlockedThemes()
        => new List<string>(_progress.unlockedThemes);

    // ══════════════════════════════════════════════════════════
    // API PUBLIQUE — MAP 3D / NŒUDS
    // ══════════════════════════════════════════════════════════

    /// Marque un nœud comme exploré
    public void MarkNodeExplored(string nodeId)
    {
        if (_progress.exploredNodes.Contains(nodeId)) return;
        _progress.exploredNodes.Add(nodeId);
        Save();
        Debug.Log($"[Progress] 🗺️ Nœud exploré : {nodeId}");
    }

    public bool IsNodeExplored(string nodeId)
        => _progress.exploredNodes.Contains(nodeId);

    public int GetExploredNodesCount()
        => _progress.exploredNodes.Count;

    // ══════════════════════════════════════════════════════════
    // API PUBLIQUE — ACTIVITÉS
    // ══════════════════════════════════════════════════════════

    /// Marque une activité comme terminée + enregistre le score
    public void CompleteActivity(string activityId, int score)
    {
        if (!_progress.completedActivities.Contains(activityId))
            _progress.completedActivities.Add(activityId);

        // Garder le meilleur score uniquement
        if (!_progress.bestScores.ContainsKey(activityId) ||
             _progress.bestScores[activityId] < score)
        {
            _progress.bestScores[activityId] = score;
            Debug.Log($"[Progress] 🏆 Nouveau meilleur score : {activityId} → {score}");
        }

        Save();
        Debug.Log($"[Progress] ✅ Activité terminée : {activityId}");
    }

    public bool IsActivityCompleted(string activityId)
        => _progress.completedActivities.Contains(activityId);

    public int GetBestScore(string activityId)
        => _progress.bestScores.ContainsKey(activityId)
           ? _progress.bestScores[activityId] : 0;

    public List<string> GetCompletedActivities()
        => new List<string>(_progress.completedActivities);

    // ══════════════════════════════════════════════════════════
    // API PUBLIQUE — ANIMAUX & PAGES AR
    // ══════════════════════════════════════════════════════════

    /// Marque un animal comme découvert
    public void DiscoverAnimal(string animalName)
    {
        if (_progress.discoveredAnimals.Contains(animalName)) return;
        _progress.discoveredAnimals.Add(animalName);
        Save();
        Debug.Log($"[Progress] 🐾 Animal découvert : {animalName}");
    }

    public bool IsAnimalDiscovered(string animalName)
        => _progress.discoveredAnimals.Contains(animalName);

    public List<string> GetDiscoveredAnimals()
        => new List<string>(_progress.discoveredAnimals);

    /// Marque une page AR comme vue
    public void MarkPageSeen(string bookId, string pageId)
    {
        string key = $"{bookId}_{pageId}";
        if (_progress.seenPages.Contains(key)) return;
        _progress.seenPages.Add(key);
        Save();
    }

    public bool IsPageSeen(string bookId, string pageId)
        => _progress.seenPages.Contains($"{bookId}_{pageId}");

    // ══════════════════════════════════════════════════════════
    // RESET (debug / nouveau profil)
    // ══════════════════════════════════════════════════════════

    public void ResetProgress()
    {
        _progress = new ChildProgress();
        _progress.unlockedThemes.Add("theme_forest");
        Save();
        Debug.Log("[Progress] 🔄 Progression réinitialisée");
    }

    // ══════════════════════════════════════════════════════════
    // RÉSUMÉ (pour le dashboard)
    // ══════════════════════════════════════════════════════════

    public ChildProgress GetSnapshot()
        => _progress;
}
