/*apres la correction 
// TTSLanguagePlayer.cs
using System;
using System.Collections;
using UnityEngine;
using UnityEngine.Networking;

public class TTSLanguagePlayer : MonoBehaviour
{
    public static TTSLanguagePlayer Instance { get; private set; }

    [Header("Clé API Speechify (console.speechify.ai/api-keys)")]
    [SerializeField] private string SPEECHIFY_API_KEY;

    public enum SpeechifyVoice
    {
        george, henry, carly, kyle, kristy, oliver, tasha, joe, lisa,
        emily, rob, julie, mark, nick, erin, jack, jesse, monica,
        stacy, evelyn, jacob, james, mason, victoria, keenan, lindsey,
        russell, benjamin, michael, carol, helen, beverly, collin,
        phil, declan, archie, freddy, harper, kim, linda, ankit,
        arun, elijah, daan, lotte
    }

    [Header("Voix par langue")]
    [SerializeField] private SpeechifyVoice voixArabe    = SpeechifyVoice.george;
    [SerializeField] private SpeechifyVoice voixFrancais = SpeechifyVoice.george;
    [SerializeField] private SpeechifyVoice voixAnglais  = SpeechifyVoice.george;

    public enum Langue { Arabe, Francais, Anglais }

    // ── URL correcte (validée par le test) ────────────────────────
    private const string TTS_API_URI = "https://api.speechify.ai/v1/audio/stream";

    // ── Modèles validés ───────────────────────────────────────────
    // simba-english     → anglais uniquement
    // simba-multilingual → arabe, français, autres langues
    private const string MODELE_ANGLAIS = "simba-english";
    private const string MODELE_MULTI   = "simba-multilingual";

    // ── Codes langue validés ──────────────────────────────────────
    private const string CODE_ARABE    = "ar-AE";
    private const string CODE_FRANCAIS = "fr-FR";
    private const string CODE_ANGLAIS  = "en-US";

    private AudioSource _audio;
    private bool        _isPlaying = false;

    // ─────────────────────────────────────────────────────────────
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);

        _audio             = gameObject.AddComponent<AudioSource>();
        _audio.playOnAwake = false;
    }

    void OnDestroy()
    {
        if (Instance == this) Instance = null;
    }

    // ─────────────────────────────────────────────────────────────
    public void PlayLangue(Langue langue, ImageCubeDataLibrary.ImageDataEntry data)
    {
        if (data == null)
        {
            Debug.LogWarning("⚠️ TTSLanguagePlayer.PlayLangue : data est NULL");
            return;
        }

        if (string.IsNullOrEmpty(SPEECHIFY_API_KEY))
        {
            Debug.LogError("❌ SPEECHIFY_API_KEY vide ! Configure-la dans l'Inspector.");
            return;
        }

        string texte      = "";
        string voixId     = "";
        string codeLangue = "";
        string modele     = "";

        switch (langue)
        {
            case Langue.Arabe:
                texte      = data.texteArabe;
                voixId     = voixArabe.ToString();
                codeLangue = CODE_ARABE;
                modele     = MODELE_MULTI;
                break;

            case Langue.Francais:
                texte      = data.texteFrancais;
                voixId     = voixFrancais.ToString();
                codeLangue = CODE_FRANCAIS;
                modele     = MODELE_MULTI;
                break;

            case Langue.Anglais:
                texte      = data.texteAnglais;
                voixId     = voixAnglais.ToString();
                codeLangue = CODE_ANGLAIS;
                modele     = MODELE_ANGLAIS;
                break;
        }

        if (string.IsNullOrEmpty(texte))
        {
            Debug.LogWarning($"⚠️ Texte [{langue}] vide pour : {data.imageName}");
            return;
        }

        if (_isPlaying)
        {
            StopAllCoroutines();
            _audio.Stop();
            _isPlaying = false;
        }

        StartCoroutine(PlayTTS(texte, voixId, modele, codeLangue));
    }

    // ─────────────────────────────────────────────────────────────
    IEnumerator PlayTTS(string texte, string voixId, string modele, string codeLangue)
    {
        _isPlaying = true;

        // JSON construit manuellement — JsonUtility inclut les champs
        // vides ce qui cause un rejet 400 par Speechify
        string jsonBody = "{"
            + $"\"input\":\"{EscapeJson(texte)}\","
            + $"\"voice_id\":\"{voixId}\","
            + $"\"model\":\"{modele}\","
            + $"\"language\":\"{codeLangue}\""
            + "}";

        Debug.Log($"🎙️ TTS envoi → {jsonBody}");

        using (var request = new UnityWebRequest(TTS_API_URI, UnityWebRequest.kHttpVerbPOST))
        {
            byte[] bodyRaw        = System.Text.Encoding.UTF8.GetBytes(jsonBody);
            request.uploadHandler = new UploadHandlerRaw(bodyRaw);

            var dh         = new DownloadHandlerAudioClip(TTS_API_URI, AudioType.MPEG);
            dh.streamAudio = true;
            request.downloadHandler = dh;

            request.SetRequestHeader("Content-Type",  "application/json");
            request.SetRequestHeader("Accept",        "audio/mpeg");
            request.SetRequestHeader("Authorization", "Bearer " + SPEECHIFY_API_KEY);

            yield return request.SendWebRequest();

            if (request.result != UnityWebRequest.Result.Success)
            {
                string errorBody = "";
                try
                {
                    byte[] eb = request.downloadHandler?.data;
                    if (eb != null && eb.Length > 0)
                        errorBody = System.Text.Encoding.UTF8.GetString(eb);
                }
                catch (Exception e) { errorBody = e.Message; }

                Debug.LogError(
                    $"❌ TTS {request.responseCode} : {request.error}\n" +
                    $"📋 Body : {(string.IsNullOrEmpty(errorBody) ? "(vide)" : errorBody)}\n" +
                    $"📤 JSON : {jsonBody}");

                _isPlaying = false;
                yield break;
            }

            byte[] bytes = request.downloadHandler?.data;
            if (bytes == null || bytes.Length < 200)
            {
                string c = bytes != null
                    ? System.Text.Encoding.UTF8.GetString(bytes)
                    : "null";
                Debug.LogError($"❌ TTS réponse trop courte ({bytes?.Length ?? 0} bytes) : {c}");
                _isPlaying = false;
                yield break;
            }

            AudioClip clip = null;
            try
            {
                clip = DownloadHandlerAudioClip.GetContent(request);
                Debug.Log($"✅ AudioClip : {clip?.length:F2}s");
            }
            catch (Exception e)
            {
                Debug.LogError($"❌ GetContent : {e.Message}");
                _isPlaying = false;
                yield break;
            }

            if (clip == null)
            {
                Debug.LogError("❌ AudioClip null après GetContent");
                _isPlaying = false;
                yield break;
            }

            _audio.Stop();
            _audio.clip = clip;
            _audio.loop = false;
            _audio.Play();
            Debug.Log($"🔊 TTS lecture OK : {clip.length:F1}s");

            while (_audio != null && _audio.isPlaying)
                yield return null;
        }

        _isPlaying = false;
    }

    // ─────────────────────────────────────────────────────────────
    string EscapeJson(string s)
    {
        if (string.IsNullOrEmpty(s)) return "";
        return s.Replace("\\", "\\\\")
                .Replace("\"", "\\\"")
                .Replace("\n", "\\n")
                .Replace("\r", "\\r")
                .Replace("\t", "\\t");
    }
}
/*TTSLanguagePlayer.cs
using System.Collections;
using UnityEngine;
using UnityEngine.Networking;
using System; 

public class TTSLanguagePlayer : MonoBehaviour
{
    public static TTSLanguagePlayer Instance { get; private set; }

    [Header("Clé API Speechify (console.speechify.ai/api-keys)")]
    [SerializeField] private string SPEECHIFY_API_KEY;

    public enum SpeechifyVoice
    {
        henry, carly, kyle, kristy, oliver, tasha, joe, lisa,
        george, emily, rob, julie, mark, nick,
        erin, jack, jesse, monica, stacy, evelyn,
        jacob, james, mason, victoria, keenan, lindsey,
        russell, benjamin, michael, carol, helen,
        beverly, collin, phil, declan, archie, freddy, harper,
        kim, linda, ankit, arun, elijah,
        daan, lotte
    }

    [Header("Voix par langue")]
    [SerializeField] private SpeechifyVoice voixArabe    = SpeechifyVoice.george;
    [SerializeField] private SpeechifyVoice voixFrancais = SpeechifyVoice.george;
    [SerializeField] private SpeechifyVoice voixAnglais  = SpeechifyVoice.henry;

    public enum Langue { Arabe, Francais, Anglais }

    private const string CODE_ARABE    = "ar-AE";
    private const string CODE_FRANCAIS = "fr-FR";
    private const string CODE_ANGLAIS  = "en";

    private const string MODELE_MULTI   = "simba-multilingual"; // arabe + français
    private const string MODELE_ANGLAIS = "simba-turbo";        // anglais uniquement

    private const string TTS_API_URI = "https://api.sws.speechify.com/v1/audio/stream";

    private AudioSource _audio;
    private bool        _isPlaying = false;

    // ─────────────────────────────────────────────────────────────
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);

        _audio             = gameObject.AddComponent<AudioSource>();
        _audio.playOnAwake = false;
    }

    void OnDestroy()
    {
        if (Instance == this) Instance = null;
    }

    // ─────────────────────────────────────────────────────────────
    public void PlayLangue(Langue langue, ImageCubeDataLibrary.ImageDataEntry data)
    {
        if (data == null)
        {
            Debug.LogWarning("⚠️ TTSLanguagePlayer.PlayLangue : data est NULL");
            return;
        }

        string texte      = "";
        string voixId     = "";
        string codeLangue = "";
        string modele     = MODELE_MULTI;

        switch (langue)
        {
            case Langue.Arabe:
                texte      = data.texteArabe;
                voixId     = voixArabe.ToString();
                codeLangue = CODE_ARABE;
                modele     = MODELE_MULTI;
                break;

            case Langue.Francais:
                texte      = data.texteFrancais;
                voixId     = voixFrancais.ToString();
                codeLangue = CODE_FRANCAIS;
                modele     = MODELE_MULTI;
                break;

            case Langue.Anglais:
                texte      = data.texteAnglais;
                voixId     = voixAnglais.ToString();
                codeLangue = CODE_ANGLAIS;
                modele     = MODELE_ANGLAIS;
                break;
        }

        if (string.IsNullOrEmpty(texte))
        {
            Debug.LogWarning($"⚠️ Texte [{langue}] vide pour : {data.imageName}");
            return;
        }

        if (string.IsNullOrEmpty(SPEECHIFY_API_KEY))
        {
            Debug.LogError("❌ SPEECHIFY_API_KEY est vide ! Configure-la dans l'Inspector.");
            return;
        }

        if (_isPlaying)
        {
            StopAllCoroutines();
            _audio.Stop();
            _isPlaying = false;
        }

        StartCoroutine(PlayTTS(texte, voixId, modele, codeLangue));
    }

    // ─────────────────────────────────────────────────────────────
    IEnumerator PlayTTS(string texte, string voixId, string modele, string codeLangue)
    {
        _isPlaying = true;

        // ── JSON construit manuellement ────────────────────────────
        // JsonUtility inclut tous les champs même vides → rejet 400
        // On n'inclut "language" que s'il est renseigné
        string jsonBody;
        if (!string.IsNullOrEmpty(codeLangue))
        {
            jsonBody = "{"
                + $"\"input\":\"{EscapeJson(texte)}\","
                + $"\"voice_id\":\"{voixId}\","
                + $"\"model\":\"{modele}\","
                + $"\"language\":\"{codeLangue}\""
                + "}";
        }
        else
        {
            jsonBody = "{"
                + $"\"input\":\"{EscapeJson(texte)}\","
                + $"\"voice_id\":\"{voixId}\","
                + $"\"model\":\"{modele}\""
                + "}";
        }

        Debug.Log($"🎙️ TTS envoi → {jsonBody}");

        using (var request = new UnityWebRequest(TTS_API_URI, UnityWebRequest.kHttpVerbPOST))
        {
            byte[] bodyRaw = System.Text.Encoding.UTF8.GetBytes(jsonBody);
            request.uploadHandler   = new UploadHandlerRaw(bodyRaw);

            var dh         = new DownloadHandlerAudioClip(TTS_API_URI, AudioType.MPEG);
            dh.streamAudio = true;
            request.downloadHandler = dh;

            request.SetRequestHeader("Content-Type",  "application/json");
            request.SetRequestHeader("Accept",        "audio/mpeg");
            request.SetRequestHeader("Authorization", "Bearer " + SPEECHIFY_API_KEY);

            yield return request.SendWebRequest();

            // ── Gestion erreur détaillée ───────────────────────────
            if (request.result != UnityWebRequest.Result.Success)
            {
                string errorBody = "";
                try
                {
                    byte[] errBytes = request.downloadHandler?.data;
                    if (errBytes != null && errBytes.Length > 0)
                        errorBody = System.Text.Encoding.UTF8.GetString(errBytes);
                }
                catch { }

                Debug.LogError(
                    $"❌ TTS {request.responseCode} : {request.error}\n" +
                    $"📋 Réponse serveur : {errorBody}\n" +
                    $"📤 JSON envoyé : {jsonBody}");

                _isPlaying = false;
                yield break;
            }

            // ── Vérification données reçues ────────────────────────
            byte[] bytes = request.downloadHandler?.data;
            if (bytes == null || bytes.Length < 200)
            {
                string contenu = bytes != null
                    ? System.Text.Encoding.UTF8.GetString(bytes)
                    : "null";
                Debug.LogError($"❌ TTS réponse trop courte ({bytes?.Length ?? 0} bytes) : {contenu}");
                _isPlaying = false;
                yield break;
            }

            // ── Récupération AudioClip ─────────────────────────────
            AudioClip clip = null;
            try
            {
                clip = DownloadHandlerAudioClip.GetContent(request);
            }
            catch (Exception e)
            {
                Debug.LogError("❌ TTS GetContent exception : " + e.Message);
            }

            if (clip == null)
            {
                Debug.LogError("❌ TTS : AudioClip null après GetContent");
                _isPlaying = false;
                yield break;
            }

            // ── Lecture ────────────────────────────────────────────
            _audio.Stop();
            _audio.clip = clip;
            _audio.loop = false;
            _audio.Play();
            Debug.Log($"🔊 TTS OK : {clip.length:F1}s");

            while (_audio != null && _audio.isPlaying)
                yield return null;
        }

        _isPlaying = false;
    }

    // ─────────────────────────────────────────────────────────────
    /// <summary>Échappe les caractères spéciaux pour JSON valide.</summary>
    string EscapeJson(string s)
    {
        if (string.IsNullOrEmpty(s)) return "";
        return s.Replace("\\", "\\\\")
                .Replace("\"", "\\\"")
                .Replace("\n", "\\n")
                .Replace("\r", "\\r")
                .Replace("\t", "\\t");
    }
}*/