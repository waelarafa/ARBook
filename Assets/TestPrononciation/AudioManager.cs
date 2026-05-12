using UnityEngine;

public class PronunciationAudioManager : MonoBehaviour
{
    public static PronunciationAudioManager Instance { get; private set; }

    private AudioSource audioSource;

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;

        // Créer AudioSource par code
        audioSource = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    public void PlayWord(string mot)
    {
        AudioClip clip = Resources.Load<AudioClip>("Audio/AudioPrononciation/" + mot);

        if (clip == null)
        {
            Debug.LogWarning($"[AudioManager] Fichier audio introuvable : Audio/{mot}");
            return;
        }

        audioSource.Stop();
        audioSource.PlayOneShot(clip);
        Debug.Log($"[AudioManager] ▶ Lecture : {mot}");
    }

    public bool IsPlaying() => audioSource.isPlaying;
}