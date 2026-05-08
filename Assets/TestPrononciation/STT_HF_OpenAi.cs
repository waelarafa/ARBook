using UnityEngine;
using System.Collections;
using UnityEngine.Networking;
using System.IO;
using System.Text;
using System;
using UnityEngine.Android;

public class STT_HF_OpenAi : MonoBehaviour
{
    // ───── Singleton ─────
    public static STT_HF_OpenAi Instance { get; private set; }

    [Header("Recording")]
    [SerializeField] private int sampleRate = 16000; // 44100 → 16000 pour Android
    [SerializeField] private bool forceMono = true;

    [Header("ElevenLabs")]
    [SerializeField] private string elevenlabsApiKey = "YOUR_API_KEY_HERE";
    private const string Endpoint = "https://api.elevenlabs.io/v1/speech-to-text";
    private const string ModelId = "scribe_v1";

    [Header("Transcription Options")]
    [SerializeField] private string languageCode = "en";

    private AudioClip recordedClip;
    private bool isRecording = false;
    private string micDevice = null;
    private float recordStartTime;

    // ─────────────────────────────────────────────
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        StartCoroutine(RequestMicPermission()); // ← Android permission
    }

    // ─────────────────────────────────────────────
    // NOUVEAU : demande permission micro Android
    private IEnumerator RequestMicPermission()
    {
        if (!Permission.HasUserAuthorizedPermission(Permission.Microphone))
        {
            Permission.RequestUserPermission(Permission.Microphone);
            yield return new WaitForSeconds(1f);
        }

        if (!Permission.HasUserAuthorizedPermission(Permission.Microphone))
            Debug.LogError("[STT] Permission micro refusée !");
        else
            Debug.Log("[STT] Permission micro OK");
    }

    // ─────────────────────────────────────────────
    public void ToggleRecording()
    {
        // NOUVEAU : garde permission avant d'enregistrer
        if (!Permission.HasUserAuthorizedPermission(Permission.Microphone))
        {
            Debug.LogWarning("[STT] Micro non autorisé !");
            StartCoroutine(RequestMicPermission());
            return;
        }

        if (!isRecording)
        {
            if (Microphone.devices == null || Microphone.devices.Length == 0)
            {
                Debug.LogError("[STT] No microphone found!");
                return;
            }

            Debug.Log("[STT] Recording started...");
            isRecording = true;
            recordStartTime = Time.time;
            recordedClip = Microphone.Start(micDevice, false, 600, sampleRate);
        }
        else
        {
            Debug.Log("[STT] Recording stopped. Sending audio...");
            isRecording = false;
            Microphone.End(micDevice);

            int samplesRecorded = (int)((Time.time - recordStartTime) * sampleRate);
            float[] allSamples = new float[recordedClip.samples * recordedClip.channels];
            recordedClip.GetData(allSamples, 0);

            float[] trimmedSamples = new float[samplesRecorded * recordedClip.channels];
            Array.Copy(allSamples, trimmedSamples, trimmedSamples.Length);

            AudioClip trimmedClip = AudioClip.Create("trimmed", samplesRecorded,
                recordedClip.channels, recordedClip.frequency, false);
            trimmedClip.SetData(trimmedSamples, 0);

            StartCoroutine(Transcribe(trimmedClip));
        }
    }

    // ─────────────────────────────────────────────
    private IEnumerator Transcribe(AudioClip clip)
    {
        if (!clip)
        {
            Debug.LogError("[STT] Recording failed: AudioClip is null.");
            yield break;
        }

        byte[] wavBytes = EncodeWAV(clip, forceMono);

        var formSections = new System.Collections.Generic.List<IMultipartFormSection>
        {
            new MultipartFormDataSection("model_id", ModelId),
            new MultipartFormDataSection("language_code", string.IsNullOrEmpty(languageCode) ? "en" : languageCode),
            new MultipartFormDataSection("prompt", PronunciationManager.Instance.GetCurrentWord()),
            new MultipartFormFileSection("file", wavBytes, "audio.wav", "audio/wav")
        };

        using (UnityWebRequest www = UnityWebRequest.Post(Endpoint, formSections))
        {
            www.SetRequestHeader("xi-api-key", elevenlabsApiKey);
            www.timeout = 120;

            yield return www.SendWebRequest();

            if (www.result == UnityWebRequest.Result.Success)
            {
                string json = www.downloadHandler.text;
                try
                {
                    var resp = JsonUtility.FromJson<SpeechToTextResponse>(json);
                    if (resp != null && !string.IsNullOrEmpty(resp.text))
                    {
                        Debug.Log($"[STT] Transcript ({resp.language_code}) : {resp.text}");
                        PronunciationManager.Instance.OnTranscriptionReceived(resp.text);
                    }
                    else
                    {
                        Debug.LogWarning("[STT] Réponse vide. Raw:\n" + json);
                    }
                }
                catch (Exception ex)
                {
                    Debug.LogWarning("[STT] JSON parse error. Raw:\n" + json + "\nException: " + ex);
                }
            }
            else
            {
                Debug.LogError($"[STT] Échec : HTTP {www.responseCode} - {www.error}\n{www.downloadHandler.text}");
            }
        }
    }

    // ─────────────────────────────────────────────
    [Serializable]
    private class SpeechToTextResponse
    {
        public string text;
        public string language_code;
    }

    // ─────────────────────────────────────────────
    private static byte[] EncodeWAV(AudioClip clip, bool mono)
    {
        if (clip == null) throw new ArgumentNullException(nameof(clip));

        int channels = clip.channels;
        int sampleRate = clip.frequency;

        float[] samples = new float[clip.samples * channels];
        clip.GetData(samples, 0);

        if (mono && channels > 1)
        {
            int frames = clip.samples;
            float[] monoSamples = new float[frames];
            for (int i = 0; i < frames; i++)
            {
                float sum = 0f;
                for (int c = 0; c < channels; c++)
                    sum += samples[i * channels + c];
                monoSamples[i] = sum / channels;
            }
            samples = monoSamples;
            channels = 1;
        }

        short[] pcm = new short[samples.Length];
        for (int i = 0; i < samples.Length; i++)
        {
            float f = Mathf.Clamp(samples[i], -1f, 1f);
            pcm[i] = (short)Mathf.RoundToInt(f * short.MaxValue);
        }

        using (var ms = new MemoryStream())
        using (var writer = new BinaryWriter(ms, Encoding.UTF8, true))
        {
            int bytesPerSample = 2;
            int byteRate = sampleRate * channels * bytesPerSample;
            int subchunk2Size = pcm.Length * bytesPerSample;
            int chunkSize = 36 + subchunk2Size;

            writer.Write(Encoding.ASCII.GetBytes("RIFF"));
            writer.Write(chunkSize);
            writer.Write(Encoding.ASCII.GetBytes("WAVE"));

            writer.Write(Encoding.ASCII.GetBytes("fmt "));
            writer.Write(16);
            writer.Write((short)1);
            writer.Write((short)channels);
            writer.Write(sampleRate);
            writer.Write(byteRate);
            writer.Write((short)(channels * bytesPerSample));
            writer.Write((short)16);

            writer.Write(Encoding.ASCII.GetBytes("data"));
            writer.Write(subchunk2Size);

            for (int i = 0; i < pcm.Length; i++)
                writer.Write(pcm[i]);

            writer.Flush();
            return ms.ToArray();
        }
    }
}
/*using UnityEngine;
using System.Collections;
using UnityEngine.Networking;
using System.IO;
using System.Text;
using System;

public class STT_HF_OpenAi : MonoBehaviour
{
    // ───── Singleton ─────
    public static STT_HF_OpenAi Instance { get; private set; }

    [Header("Recording")]
    [SerializeField] private int sampleRate = 44100;
    [SerializeField] private bool forceMono = true;

    [Header("Groq Whisper")]
    [SerializeField] private string groqApiKey = "YOUR_GROQ_KEY_HERE";
    private const string Endpoint = "https://api.groq.com/openai/v1/audio/transcriptions";
    private const string ModelId = "whisper-large-v3-turbo";

    [Header("Transcription Options")]
    [SerializeField] private string languageCode = "en";

    private AudioClip recordedClip;
    private bool isRecording = false;
    private string micDevice = null;
    private float recordStartTime;

    // ─────────────────────────────────────────────
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

    // ─────────────────────────────────────────────
    public void ToggleRecording()
    {
        if (!isRecording)
        {
            if (Microphone.devices == null || Microphone.devices.Length == 0)
            {
                Debug.LogError("[STT] No microphone found!");
                return;
            }

            Debug.Log("[STT] Recording started...");
            isRecording = true;
            recordStartTime = Time.time;
            recordedClip = Microphone.Start(micDevice, false, 600, sampleRate);
        }
        else
        {
            Debug.Log("[STT] Recording stopped. Sending audio...");
            isRecording = false;
            Microphone.End(micDevice);

            int samplesRecorded = (int)((Time.time - recordStartTime) * sampleRate);
            float[] allSamples = new float[recordedClip.samples * recordedClip.channels];
            recordedClip.GetData(allSamples, 0);

            float[] trimmedSamples = new float[samplesRecorded * recordedClip.channels];
            Array.Copy(allSamples, trimmedSamples, trimmedSamples.Length);

            AudioClip trimmedClip = AudioClip.Create("trimmed", samplesRecorded,
                recordedClip.channels, recordedClip.frequency, false);
            trimmedClip.SetData(trimmedSamples, 0);

            StartCoroutine(Transcribe(trimmedClip));
        }
    }

    // ─────────────────────────────────────────────
    private IEnumerator Transcribe(AudioClip clip)
    {
        if (!clip)
        {
            Debug.LogError("[STT] Recording failed: AudioClip is null.");
            yield break;
        }

        byte[] wavBytes = EncodeWAV(clip, forceMono);

        var formSections = new System.Collections.Generic.List<IMultipartFormSection>
        {
            new MultipartFormDataSection("model", ModelId),
            new MultipartFormDataSection("language", string.IsNullOrEmpty(languageCode) ? "en" : languageCode),
            new MultipartFormFileSection("file", wavBytes, "audio.wav", "audio/wav")
        };

        using (UnityWebRequest www = UnityWebRequest.Post(Endpoint, formSections))
        {
            www.SetRequestHeader("Authorization", "Bearer " + groqApiKey);
            www.timeout = 120;

            yield return www.SendWebRequest();

            if (www.result == UnityWebRequest.Result.Success)
            {
                string json = www.downloadHandler.text;
                try
                {
                    var resp = JsonUtility.FromJson<SpeechToTextResponse>(json);
                    if (resp != null && !string.IsNullOrEmpty(resp.text))
                    {
                        Debug.Log($"[STT] Transcript : {resp.text}");
                        PronunciationManager.Instance.OnTranscriptionReceived(resp.text);
                    }
                    else
                    {
                        Debug.LogWarning("[STT] Réponse vide. Raw:\n" + json);
                    }
                }
                catch (Exception ex)
                {
                    Debug.LogWarning("[STT] JSON parse error. Raw:\n" + json + "\nException: " + ex);
                }
            }
            else
            {
                Debug.LogError($"[STT] Échec : HTTP {www.responseCode} - {www.error}\n{www.downloadHandler.text}");
            }
        }
    }

    // ─────────────────────────────────────────────
    [Serializable]
    private class SpeechToTextResponse
    {
        public string text;
    }

    // ─────────────────────────────────────────────
    private static byte[] EncodeWAV(AudioClip clip, bool mono)
    {
        if (clip == null) throw new ArgumentNullException(nameof(clip));

        int channels = clip.channels;
        int sampleRate = clip.frequency;

        float[] samples = new float[clip.samples * channels];
        clip.GetData(samples, 0);

        if (mono && channels > 1)
        {
            int frames = clip.samples;
            float[] monoSamples = new float[frames];
            for (int i = 0; i < frames; i++)
            {
                float sum = 0f;
                for (int c = 0; c < channels; c++)
                    sum += samples[i * channels + c];
                monoSamples[i] = sum / channels;
            }
            samples = monoSamples;
            channels = 1;
        }

        short[] pcm = new short[samples.Length];
        for (int i = 0; i < samples.Length; i++)
        {
            float f = Mathf.Clamp(samples[i], -1f, 1f);
            pcm[i] = (short)Mathf.RoundToInt(f * short.MaxValue);
        }

        using (var ms = new MemoryStream())
        using (var writer = new BinaryWriter(ms, Encoding.UTF8, true))
        {
            int bytesPerSample = 2;
            int byteRate = sampleRate * channels * bytesPerSample;
            int subchunk2Size = pcm.Length * bytesPerSample;
            int chunkSize = 36 + subchunk2Size;

            writer.Write(Encoding.ASCII.GetBytes("RIFF"));
            writer.Write(chunkSize);
            writer.Write(Encoding.ASCII.GetBytes("WAVE"));

            writer.Write(Encoding.ASCII.GetBytes("fmt "));
            writer.Write(16);
            writer.Write((short)1);
            writer.Write((short)channels);
            writer.Write(sampleRate);
            writer.Write(byteRate);
            writer.Write((short)(channels * bytesPerSample));
            writer.Write((short)16);

            writer.Write(Encoding.ASCII.GetBytes("data"));
            writer.Write(subchunk2Size);

            for (int i = 0; i < pcm.Length; i++)
                writer.Write(pcm[i]);

            writer.Flush();
            return ms.ToArray();
        }
    }
}*/