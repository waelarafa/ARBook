// TTSTest.cs
using System;
using System.Collections;
using UnityEngine;
using UnityEngine.Networking;

public class TTSTest : MonoBehaviour
{
    [Header("Clé API Speechify")]
    public string apiKey = "";

    [Header("Texte à lire")]
    [TextArea] public string texte = "Hello this is a test";

    [Header("Paramètres — NE PAS MODIFIER pour le test")]
    public string voiceId = "en-US-Wavenet-D";       // voice_id officiel de la doc
    public string model   = "simba-english";          // simba-english | simba-multilingual
    public string langue  = "en-US";                  // en-US | fr-FR | ar-AE

    private AudioSource _audio;

    // ─────────────────────────────────────────────────────────────
    void Start()
    {
        _audio             = gameObject.AddComponent<AudioSource>();
        _audio.playOnAwake = false;
        Debug.Log("🟡 TTSTest Start → lancement...");
        StartCoroutine(SendTTS());
    }

    // ─────────────────────────────────────────────────────────────
    IEnumerator SendTTS()
    {
        Debug.Log("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
        Debug.Log("🔍 ÉTAPE 1 — Vérification paramètres");

        if (string.IsNullOrEmpty(apiKey))
        { Debug.LogError("❌ apiKey vide !"); yield break; }
        else
            Debug.Log($"✅ apiKey : {apiKey.Substring(0, Mathf.Min(10, apiKey.Length))}...");

        Debug.Log($"✅ texte   : \"{texte}\"");
        Debug.Log($"✅ voiceId : \"{voiceId}\"");
        Debug.Log($"✅ model   : \"{model}\"");
        Debug.Log($"✅ langue  : \"{langue}\"");

        // ── JSON ────────────────────────────────────────────────────
        Debug.Log("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
        Debug.Log("🔍 ÉTAPE 2 — Construction JSON");

        string jsonBody = "{"
            + $"\"input\":\"{EscapeJson(texte)}\","
            + $"\"voice_id\":\"{voiceId}\","
            + $"\"model\":\"{model}\","
            + $"\"language\":\"{langue}\""
            + "}";

        Debug.Log($"📤 JSON : {jsonBody}");

        // ── URL correcte selon la doc officielle ────────────────────
        // https://api.speechify.ai  (et non api.sws.speechify.com)
        string url = "https://api.speechify.ai/v1/audio/stream";
        Debug.Log($"🌐 URL : {url}");

        Debug.Log("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
        Debug.Log("🔍 ÉTAPE 3 — Envoi requête...");

        using (var request = new UnityWebRequest(url, UnityWebRequest.kHttpVerbPOST))
        {
            byte[] bodyRaw        = System.Text.Encoding.UTF8.GetBytes(jsonBody);
            request.uploadHandler = new UploadHandlerRaw(bodyRaw);

            var dh         = new DownloadHandlerAudioClip(url, AudioType.MPEG);
            dh.streamAudio = true;
            request.downloadHandler = dh;

            request.SetRequestHeader("Content-Type",  "application/json");
            request.SetRequestHeader("Accept",        "audio/mpeg");
            request.SetRequestHeader("Authorization", "Bearer " + apiKey);

            yield return request.SendWebRequest();

            Debug.Log("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            Debug.Log("🔍 ÉTAPE 4 — Réponse reçue");
            Debug.Log($"📡 Code HTTP : {request.responseCode}");
            Debug.Log($"📡 Result    : {request.result}");

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

                Debug.LogError($"❌ Code HTTP    : {request.responseCode}");
                Debug.LogError($"❌ Erreur       : {request.error}");
                Debug.LogError($"❌ Body réponse : {(string.IsNullOrEmpty(errorBody) ? "(vide)" : errorBody)}");

                switch (request.responseCode)
                {
                    case 400: Debug.LogError("💡 400 → JSON invalide ou paramètre incorrect"); break;
                    case 401: Debug.LogError("💡 401 → Clé API incorrecte ou expirée");        break;
                    case 403: Debug.LogError("💡 403 → Pas d'accès à cette fonctionnalité");   break;
                    case 429: Debug.LogError("💡 429 → Quota dépassé");                        break;
                    case 0:   Debug.LogError("💡 0   → Pas de connexion réseau");              break;
                    default:  Debug.LogError($"💡 {request.responseCode} → Erreur inconnue"); break;
                }
                yield break;
            }

            Debug.Log("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            Debug.Log("🔍 ÉTAPE 5 — Vérification données");

            byte[] bytes = request.downloadHandler?.data;
            int taille   = bytes?.Length ?? 0;
            Debug.Log($"📦 Taille : {taille} bytes");

            if (bytes == null || taille < 200)
            {
                string c = bytes != null ? System.Text.Encoding.UTF8.GetString(bytes) : "null";
                Debug.LogError($"❌ Trop petit ({taille} bytes) : {c}");
                yield break;
            }
            Debug.Log($"✅ {taille} bytes reçus");

            Debug.Log("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            Debug.Log("🔍 ÉTAPE 6 — Création AudioClip");

            AudioClip clip = null;
            try
            {
                clip = DownloadHandlerAudioClip.GetContent(request);
                Debug.Log($"✅ Clip : {clip?.length:F2}s | ch={clip?.channels} | {clip?.frequency}Hz");
            }
            catch (Exception e)
            { Debug.LogError($"❌ GetContent : {e.Message}"); yield break; }

            if (clip == null)
            { Debug.LogError("❌ AudioClip null"); yield break; }

            Debug.Log("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            Debug.Log("🔍 ÉTAPE 7 — Lecture");

            _audio.Stop();
            _audio.clip = clip;
            _audio.loop = false;
            _audio.Play();
            Debug.Log("🔊 Lecture démarrée !");

            while (_audio != null && _audio.isPlaying)
                yield return null;

            Debug.Log("✅ Lecture terminée !");
        }
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