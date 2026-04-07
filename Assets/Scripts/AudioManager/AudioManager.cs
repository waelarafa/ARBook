using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AudioManager : MonoBehaviour
{
    public static AudioManager Instance { get; private set; }

    // On garde un AudioSource "pool" pour éviter d'en créer plein
    private AudioSource _source;

    // Dictionnaire : SoundConfig → dernière fois qu'il a joué
    private Dictionary<SoundConfig, float> _lastPlayedTime = new();

    void Awake()
    {
        // Singleton : une seule instance dans toute la scène
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        DontDestroyOnLoad(gameObject);

        _source = gameObject.AddComponent<AudioSource>();
    }

    public void Play(SoundConfig config)
    {
        if (config == null || config.clip == null) return;

        float now = Time.time;

        // Vérifier le cooldown (anti-spam)
        if (_lastPlayedTime.TryGetValue(config, out float lastTime))
        {
            if (now - lastTime < config.cooldown) return; // trop tôt, on skip
        }

        // Vérifier l'overlap
        if (!config.allowOverlap && _source.isPlaying)
        {
            _source.Stop(); // on coupe l'ancien son et on joue le nouveau
        }

        _source.PlayOneShot(config.clip, config.volume);
        _lastPlayedTime[config] = now;
    }
}