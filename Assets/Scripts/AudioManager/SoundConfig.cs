using UnityEngine;
[CreateAssetMenu(fileName = "SoundConfig", menuName = "AR Book/Sound Config")]
public class SoundConfig : ScriptableObject
{
    [Header("Audio")]
    public AudioClip clip;

    [Header("Playback Settings")]
    public bool allowOverlap = false;      // jouer par-dessus si déjà en cours ?
    public float cooldown = 1.0f;          // délai minimum entre deux plays (anti-spam)
    [Range(0f, 1f)] public float volume = 1.0f;
}