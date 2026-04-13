using UnityEngine;

public class AudioInteractable : MonoBehaviour
{
    [Header("Sounds to play on tap")]
    public SoundConfig[] soundConfigs;

    public void OnTap()
    {
        if (soundConfigs == null || soundConfigs.Length == 0) return;

        // 👉 jouer un son aléatoire
        int index = Random.Range(0, soundConfigs.Length);
        AudioManager.Instance?.Play(soundConfigs[index]);
    }
}

/*using UnityEngine;

public class AudioInteractable : MonoBehaviour
{
    [Header("Sound to play on tap")]
    public SoundConfig soundConfig;

    // Méthode publique → ton binôme peut l'appeler depuis OnTap()
    // OU tu peux l'appeler toi-même selon comment OnTap() est défini
    public void OnTap()
    {
        AudioManager.Instance?.Play(soundConfig);
    }
}*/