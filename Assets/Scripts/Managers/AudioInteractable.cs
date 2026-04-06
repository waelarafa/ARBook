using UnityEngine;

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
}