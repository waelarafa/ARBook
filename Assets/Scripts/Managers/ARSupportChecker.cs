using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.ARFoundation;
using TMPro;
using UnityEngine.SceneManagement;

public class ARSupportChecker : MonoBehaviour
{
    [Header("Panel cible (assigné par AuthManager)")]
    public GameObject targetPanel;

    [Header("Scene Names")]
    [SerializeField] private string arSceneName = "GymTesnime";
    [SerializeField] private string nonArSceneName = "NonARScene";

    [Header("Button Colors")]
    [SerializeField] private Color arButtonColor = new Color(0.2f, 0.6f, 1f);
    [SerializeField] private Color nonArButtonColor = new Color(0.3f, 0.8f, 0.4f);
    [SerializeField] private Color textColor = Color.white;
    [SerializeField] private Color statsButtonColor = new Color(0.6f, 0.3f, 0.9f);

    // ══════════════════════════════════════════════════════════
    // RÉFÉRENCE VERS AuthManagerV2
    // Assigne-la dans l'Inspector — ARSupportChecker délègue
    // le clic Stats à AuthManagerV2.OnStatsClicked()
    // ══════════════════════════════════════════════════════════
    [Header("── Auth Manager V2 (pour déléguer Stats) ──")]
    [Tooltip("Glisse ici le GameObject qui porte AuthManagerV2")]
    public AuthManagerV2 authManagerV2;

    private bool _arSupported = false;

    // ── Appelé après login ────────────────────────────────────
    public void StartCheck()
    {
        StartCoroutine(CheckARSupportAndBuildUI());
    }

    private IEnumerator CheckARSupportAndBuildUI()
    {
        yield return ARSession.CheckAvailability();

        _arSupported =
            ARSession.state != ARSessionState.Unsupported &&
            ARSession.state != ARSessionState.None &&
            ARSession.state != ARSessionState.CheckingAvailability;

        Debug.Log($"[ARSupportChecker] AR supported: {_arSupported} | State: {ARSession.state}");

        BuildUI();
    }

    // ══════════════════════════════════════════════════════════
    // UI BUILD
    // ══════════════════════════════════════════════════════════
    private void BuildUI()
    {
        foreach (Transform child in targetPanel.transform)
            Destroy(child.gameObject);

        CreateTitle();

        if (_arSupported)
        {
            CreateCardButton("AR Experience", arButtonColor, 130f, OnARButtonClicked);
            CreateCardButton("Non-AR Experience", nonArButtonColor, -60f, OnNonARButtonClicked);
        }
        else
        {
            CreateCardButton("Non-AR Experience", nonArButtonColor, 60f, OnNonARButtonClicked);
            CreateUnsupportedMessage();
        }

        // ✅ Bouton Stats — délègue à AuthManagerV2.OnStatsClicked()
        CreateCardButton("Statistiques 📊", statsButtonColor, -250f, OnStatsButtonClicked);
    }

    // ══════════════════════════════════════════════════════════
    // TITLE
    // ══════════════════════════════════════════════════════════
    private void CreateTitle()
    {
        GameObject titleGO = new GameObject("Title");
        titleGO.transform.SetParent(targetPanel.transform, false);

        TextMeshProUGUI tmp = titleGO.AddComponent<TextMeshProUGUI>();
        tmp.text = _arSupported ? "Choose your experience" : "Welcome to ARBook";
        tmp.fontSize = 52;
        tmp.fontStyle = FontStyles.Bold;
        tmp.color = Color.white;
        tmp.alignment = TextAlignmentOptions.Center;

        RectTransform rt = titleGO.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.5f, 0.5f);
        rt.anchorMax = new Vector2(0.5f, 0.5f);
        rt.sizeDelta = new Vector2(900f, 100f);
        rt.anchoredPosition = new Vector2(0f, 220f);
    }

    // ══════════════════════════════════════════════════════════
    // CARD BUTTON
    // ══════════════════════════════════════════════════════════
    private void CreateCardButton(string label, Color color, float yPosition,
                                  UnityEngine.Events.UnityAction onClick)
    {
        GameObject btnGO = new GameObject($"Button_{label}");
        btnGO.transform.SetParent(targetPanel.transform, false);

        Image bg = btnGO.AddComponent<Image>();
        bg.color = color;

        Button btn = btnGO.AddComponent<Button>();
        btn.targetGraphic = bg;
        btn.onClick.AddListener(onClick);

        RectTransform rt = btnGO.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.5f, 0.5f);
        rt.anchorMax = new Vector2(0.5f, 0.5f);
        rt.sizeDelta = new Vector2(520f, 180f);
        rt.anchoredPosition = new Vector2(0f, yPosition);

        // Icon
        GameObject iconGO = new GameObject("Icon");
        iconGO.transform.SetParent(btnGO.transform, false);

        TextMeshProUGUI icon = iconGO.AddComponent<TextMeshProUGUI>();
        icon.text = label.Contains("AR") ? "🌐" : "🎮";
        icon.fontSize = 64;
        icon.alignment = TextAlignmentOptions.Center;
        icon.color = Color.white;

        RectTransform iconRT = iconGO.GetComponent<RectTransform>();
        iconRT.anchorMin = new Vector2(0.5f, 0.65f);
        iconRT.anchorMax = new Vector2(0.5f, 0.65f);
        iconRT.sizeDelta = new Vector2(100f, 100f);

        // Label
        GameObject textGO = new GameObject("Label");
        textGO.transform.SetParent(btnGO.transform, false);

        TextMeshProUGUI tmp = textGO.AddComponent<TextMeshProUGUI>();
        tmp.text = label;
        tmp.fontSize = 30;
        tmp.fontStyle = FontStyles.Bold;
        tmp.color = textColor;
        tmp.alignment = TextAlignmentOptions.Center;

        RectTransform textRT = textGO.GetComponent<RectTransform>();
        textRT.anchorMin = new Vector2(0.5f, 0.25f);
        textRT.anchorMax = new Vector2(0.5f, 0.25f);
        textRT.sizeDelta = new Vector2(400f, 60f);
    }

    // ══════════════════════════════════════════════════════════
    // UNSUPPORTED MESSAGE
    // ══════════════════════════════════════════════════════════
    private void CreateUnsupportedMessage()
    {
        GameObject msgGO = new GameObject("UnsupportedMsg");
        msgGO.transform.SetParent(targetPanel.transform, false);

        TextMeshProUGUI tmp = msgGO.AddComponent<TextMeshProUGUI>();
        tmp.text = "⚠️ AR is not supported on this device.\nYou can still enjoy the experience!";
        tmp.fontSize = 28;
        tmp.color = new Color(1f, 0.85f, 0.3f);
        tmp.alignment = TextAlignmentOptions.Center;

        RectTransform rt = msgGO.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.5f, 0.5f);
        rt.anchorMax = new Vector2(0.5f, 0.5f);
        rt.sizeDelta = new Vector2(850f, 120f);
        rt.anchoredPosition = new Vector2(0f, -180f);
    }

    // ══════════════════════════════════════════════════════════
    // ACTIONS
    // ══════════════════════════════════════════════════════════
    private void OnARButtonClicked()
    {
        Debug.Log("[ARSupportChecker] AR selected");
        SceneManager.LoadScene(arSceneName);
    }

    private void OnNonARButtonClicked()
    {
        Debug.Log("[ARSupportChecker] Non-AR selected");
        SceneManager.LoadScene(nonArSceneName);
    }

    /// ✅ Délègue à AuthManagerV2 → c'est lui qui vérifie si connecté
    /// et affiche Panel_Notification si besoin
    private void OnStatsButtonClicked()
    {
        if (authManagerV2 != null)
        {
            // AuthManagerV2 gère la vérification connexion + notification
            authManagerV2.OnStatsClicked();
        }
        else
        {
            // Fallback si authManagerV2 pas assigné : ancienne logique directe
            Debug.LogWarning("[ARSupportChecker] authManagerV2 non assigné — fallback direct");

            string userId = Firebase.Auth.FirebaseAuth.DefaultInstance.CurrentUser?.UserId;
            if (string.IsNullOrEmpty(userId))
                userId = PlayerPrefs.GetString("userId", "");

            if (string.IsNullOrEmpty(userId))
            {
                Debug.LogWarning("[Stats] Aucun userId trouvé — user non connecté");
                return;
            }

            string url = "https://arbook-dashboard.vercel.app?userId=" + userId;
            Application.OpenURL(url);
        }
    }
}


///////////////////////////////////////////////
// ceci marche avec scenelogin
/*using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.ARFoundation;
using TMPro;
using UnityEngine.SceneManagement;

public class ARSupportChecker : MonoBehaviour
{
    [Header("Panel cible (assigné par AuthManager)")]
    public GameObject targetPanel;

    [Header("Scene Names")]
    [SerializeField] private string arSceneName = "GymTesnime";
    [SerializeField] private string nonArSceneName = "NonARScene";

    [Header("Button Colors")]
    [SerializeField] private Color arButtonColor = new Color(0.2f, 0.6f, 1f);
    [SerializeField] private Color nonArButtonColor = new Color(0.3f, 0.8f, 0.4f);
    [SerializeField] private Color textColor = Color.white;

    [SerializeField] private Color statsButtonColor = new Color(0.6f, 0.3f, 0.9f);

    private bool _arSupported = false;

    // Appelé après login
    public void StartCheck()
    {
        StartCoroutine(CheckARSupportAndBuildUI());
    }

    private IEnumerator CheckARSupportAndBuildUI()
    {
        yield return ARSession.CheckAvailability();

        _arSupported =
            ARSession.state != ARSessionState.Unsupported &&
            ARSession.state != ARSessionState.None &&
            ARSession.state != ARSessionState.CheckingAvailability;

        Debug.Log($"[ARSupportChecker] AR supported: {_arSupported} | State: {ARSession.state}");

        BuildUI();
    }

    // ───────────────────────── UI BUILD ─────────────────────────

    private void BuildUI()
    {
        foreach (Transform child in targetPanel.transform)
            Destroy(child.gameObject);

        CreateTitle();

        if (_arSupported)
        {
            CreateCardButton("AR Experience", arButtonColor, 130f, OnARButtonClicked);
            CreateCardButton("Non-AR Experience", nonArButtonColor, -60f, OnNonARButtonClicked);
        }
        else
        {
            CreateCardButton("Non-AR Experience", nonArButtonColor, 60f, OnNonARButtonClicked);
            CreateUnsupportedMessage();
        }

        // Bouton Stats — toujours visible
        CreateCardButton("Statistiques 📊", statsButtonColor, -250f, OnStatsButtonClicked);
    }

    // ───────────────────────── TITLE ─────────────────────────

    private void CreateTitle()
    {
        GameObject titleGO = new GameObject("Title");
        titleGO.transform.SetParent(targetPanel.transform, false);

        TextMeshProUGUI tmp = titleGO.AddComponent<TextMeshProUGUI>();
        tmp.text = _arSupported ? "Choose your experience" : "Welcome to ARBook";
        tmp.fontSize = 52;
        tmp.fontStyle = FontStyles.Bold;
        tmp.color = Color.white;
        tmp.alignment = TextAlignmentOptions.Center;

        RectTransform rt = titleGO.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.5f, 0.5f);
        rt.anchorMax = new Vector2(0.5f, 0.5f);
        rt.sizeDelta = new Vector2(900f, 100f);
        rt.anchoredPosition = new Vector2(0f, 220f);
    }

    // ───────────────────────── CARD BUTTON ─────────────────────────

    private void CreateCardButton(string label, Color color, float yPosition, UnityEngine.Events.UnityAction onClick)
    {
        GameObject btnGO = new GameObject($"Button_{label}");
        btnGO.transform.SetParent(targetPanel.transform, false);

        // BACKGROUND CARD
        Image bg = btnGO.AddComponent<Image>();
        bg.color = color;

        Button btn = btnGO.AddComponent<Button>();
        btn.targetGraphic = bg;
        btn.onClick.AddListener(onClick);

        RectTransform rt = btnGO.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.5f, 0.5f);
        rt.anchorMax = new Vector2(0.5f, 0.5f);
        rt.sizeDelta = new Vector2(520f, 180f);
        rt.anchoredPosition = new Vector2(0f, yPosition);

        // ICON (placeholder emoji style via text)
        GameObject iconGO = new GameObject("Icon");
        iconGO.transform.SetParent(btnGO.transform, false);

        TextMeshProUGUI icon = iconGO.AddComponent<TextMeshProUGUI>();
        icon.text = label.Contains("AR") ? "🌐" : "🎮";
        icon.fontSize = 64;
        icon.alignment = TextAlignmentOptions.Center;
        icon.color = Color.white;

        RectTransform iconRT = iconGO.GetComponent<RectTransform>();
        iconRT.anchorMin = new Vector2(0.5f, 0.65f);
        iconRT.anchorMax = new Vector2(0.5f, 0.65f);
        iconRT.sizeDelta = new Vector2(100f, 100f);

        // TEXT
        GameObject textGO = new GameObject("Label");
        textGO.transform.SetParent(btnGO.transform, false);

        TextMeshProUGUI tmp = textGO.AddComponent<TextMeshProUGUI>();
        tmp.text = label;
        tmp.fontSize = 30;
        tmp.fontStyle = FontStyles.Bold;
        tmp.color = textColor;
        tmp.alignment = TextAlignmentOptions.Center;

        RectTransform textRT = textGO.GetComponent<RectTransform>();
        textRT.anchorMin = new Vector2(0.5f, 0.25f);
        textRT.anchorMax = new Vector2(0.5f, 0.25f);
        textRT.sizeDelta = new Vector2(400f, 60f);
    }

    // ───────────────────────── MESSAGE ─────────────────────────

    private void CreateUnsupportedMessage()
    {
        GameObject msgGO = new GameObject("UnsupportedMsg");
        msgGO.transform.SetParent(targetPanel.transform, false);

        TextMeshProUGUI tmp = msgGO.AddComponent<TextMeshProUGUI>();
        tmp.text = "⚠️ AR is not supported on this device.\nYou can still enjoy the experience!";
        tmp.fontSize = 28;
        tmp.color = new Color(1f, 0.85f, 0.3f);
        tmp.alignment = TextAlignmentOptions.Center;

        RectTransform rt = msgGO.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.5f, 0.5f);
        rt.anchorMax = new Vector2(0.5f, 0.5f);
        rt.sizeDelta = new Vector2(850f, 120f);
        rt.anchoredPosition = new Vector2(0f, -180f);
    }

    // ───────────────────────── ACTIONS ─────────────────────────

    private void OnARButtonClicked()
    {
        Debug.Log("[ARSupportChecker] AR selected");
        SceneManager.LoadScene(arSceneName);
    }

    private void OnNonARButtonClicked()
    {
        Debug.Log("[ARSupportChecker] Non-AR selected");
        SceneManager.LoadScene(nonArSceneName);
    }

    private void OnStatsButtonClicked()
    {
        // Essayer Firebase Auth d'abord
        string userId = Firebase.Auth.FirebaseAuth.DefaultInstance.CurrentUser?.UserId;

        // Fallback sur PlayerPrefs si Firebase Auth ne répond pas
        if (string.IsNullOrEmpty(userId))
            userId = PlayerPrefs.GetString("userId", "");

        if (string.IsNullOrEmpty(userId))
        {
            Debug.LogWarning("[Stats] Aucun userId trouvé — user non connecté");
            return;
        }

        string url = "https://arbook-dashboard.vercel.app?userId=" + userId;
        Debug.Log("[Stats] Ouverture : " + url); // vérifie l'URL dans les logs
        Application.OpenURL(url);
    }
}*/



