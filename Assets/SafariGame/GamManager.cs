using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// Attacher sur un GameObject vide "GameManager".
/// Tous les paramètres sont configurables depuis l'Inspector.
/// </summary>
public class GameManager : MonoBehaviour
{
    public static GameManager Instance { get; private set; }

    // ────────────────────────────────────────────────────────────────────────
    [Header("Son ambiance (joue dès le début)")]
    [Tooltip("Son qui joue en boucle tout au long de la scène")]
    public AudioClip ambianceClip;
    [Range(0f, 1f)]
    public float ambianceVolume = 0.5f;

    // ────────────────────────────────────────────────────────────────────────
    [Header("Match réussi")]
    [Tooltip("Modèle 3D à instancier à chaque match réussi (ex: étoile, confetti 3D...)")]
    public GameObject matchRewardPrefab;
    [Tooltip("Position où le modèle de récompense apparaît")]
    public Vector3 matchRewardPosition = new Vector3(0f, 0.5f, 0f);

    // ────────────────────────────────────────────────────────────────────────
    [Header("Victoire (tous les couples trouvés)")]
    [Tooltip("Prefab affiché quand la game est complète")]
    public GameObject victoryPrefab;
    [Tooltip("Son joué quand la game est complète")]
    public AudioClip victoryClip;
    [Range(0f, 1f)]
    public float victoryVolume = 1f;
    [Tooltip("Message affiché quand la game est complète")]
    public string victoryMessage = "Bravo ! Tu as tout trouvé !";
    [Tooltip("TextMeshPro pour afficher le message de victoire (optionnel)")]
    public TMP_Text victoryText;

    // ────────────────────────────────────────────────────────────────────────

    private PairableObject _firstSelected = null;
    private int _remainingPairs = 0;
    private AudioSource _audioSource;

    private void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;

        _audioSource = gameObject.AddComponent<AudioSource>();
    }

    private void Start()
    {
        CountPairs();
        PlayAmbiance();

        if (victoryText != null)
            victoryText.gameObject.SetActive(false);
    }

    // ─── Ambiance ────────────────────────────────────────────────────────────

    private void PlayAmbiance()
    {
        if (ambianceClip == null) return;

        _audioSource.clip   = ambianceClip;
        _audioSource.volume = ambianceVolume;
        _audioSource.loop   = true;
        _audioSource.Play();
    }

    // ─── Comptage des paires ─────────────────────────────────────────────────

    private void CountPairs()
    {
        var allObjects = FindObjectsByType<PairableObject>(FindObjectsSortMode.None);
        var pairIDs    = new HashSet<string>();
        foreach (var obj in allObjects)
            pairIDs.Add(obj.pairID);

        _remainingPairs = pairIDs.Count;
        Debug.Log($"[GameManager] {_remainingPairs} paire(s) à trouver.");
    }

    // ─── Logique de tap ──────────────────────────────────────────────────────

    public void OnObjectTapped(PairableObject tapped)
    {
        if (_firstSelected == null)
        {
            _firstSelected = tapped;
            _firstSelected.Select();
            return;
        }

        if (_firstSelected == tapped)
        {
            _firstSelected.Deselect();
            _firstSelected = null;
            return;
        }

        if (_firstSelected.pairID == tapped.pairID)
        {
            // ✅ BON MATCH
            _firstSelected.OnMatchSuccess();
            tapped.OnMatchSuccess();
            _firstSelected = null;

            SpawnMatchReward();

            _remainingPairs--;
            if (_remainingPairs <= 0)
                TriggerVictory();
        }
        else
        {
            // ❌ MAUVAIS MATCH → reset silencieux
            _firstSelected.Deselect();
            tapped.Deselect();
            _firstSelected = null;
        }
    }

    // ─── Récompense par match ────────────────────────────────────────────────

    private void SpawnMatchReward()
    {
        if (matchRewardPrefab == null) return;
        Instantiate(matchRewardPrefab, matchRewardPosition, Quaternion.identity);
        Debug.Log("[GameManager] Récompense match spawné.");
    }

    // ─── Victoire ────────────────────────────────────────────────────────────

    private void TriggerVictory()
    {
        Debug.Log($"[GameManager] 🎉 {victoryMessage}");

        _audioSource.Stop();

        if (victoryClip != null)
            _audioSource.PlayOneShot(victoryClip, victoryVolume);

        if (victoryPrefab != null)
            Instantiate(victoryPrefab);

        if (victoryText != null)
        {
            victoryText.gameObject.SetActive(true);
            victoryText.text = victoryMessage;
            StartCoroutine(HideVictoryText());
        }
    }

    private IEnumerator HideVictoryText()
    {
        yield return new WaitForSeconds(1f);
        victoryText.gameObject.SetActive(false);
    }
}