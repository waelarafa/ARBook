
/*using Firebase;
using Firebase.Auth;
using System;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// AuthManagerV2 — Script principal de la nouvelle scène.
///
/// HIÉRARCHIE CANVAS COMPLÈTE :
///   Panel_Splash
///   Panel_Welcome          → Btn_Library | Btn_ParentSpace
///   Panel_Library          → ScrollView(livres activés) | Btn_ParentSpace
///   Panel_Parent           → Btn_Library | Btn_BookManager | Btn_Settings | Btn_Stats | Btn_Login | Btn_Logout | Btn_Back
///   Panel_Scanner          → QRScanner intégré | Txt_Status | Btn_Back
///   Panel_Settings         → ScrollView(tous les livres + toggles) | Btn_Back
///   Panel_Notification     → Txt_Message | Btn_Login | Btn_Close   (overlay)
///   Panel_Auth             → conteneur auth
///     ├── Panel_SignIn
///     ├── Panel_SignUp
///     └── Panel_ForgotPassword
///   Panel_ChooseExperience
/// </summary>
public class AuthManagerV2 : MonoBehaviour
{
    // ══════════════════════════════════════════════════════════
    // PANELS RACINE
    // ══════════════════════════════════════════════════════════
    [Header("── Panels Racine ──")]
    public GameObject panel_Splash;
    public GameObject panel_Welcome;
    public GameObject panel_Library;
    public GameObject panel_Parent;
    public GameObject panel_Scanner;
    public GameObject panel_Settings;
    public GameObject panel_Auth;
    public GameObject panel_ChooseExperience;

    [Header("── Overlay Notification ──")]
    public GameObject panel_Notification;

    // ══════════════════════════════════════════════════════════
    // SOUS-PANELS AUTH
    // ══════════════════════════════════════════════════════════
    [Header("── Sous-panels Auth ──")]
    public GameObject panel_SignIn;
    public GameObject panel_SignUp;
    public GameObject panel_ForgotPassword;

    // ══════════════════════════════════════════════════════════
    // PANEL LIBRARY — références UI
    // ══════════════════════════════════════════════════════════
    [Header("── Panel Library ──")]
    [Tooltip("Transform du Content dans le ScrollView de Panel_Library")]
    public Transform libraryContent;

    [Tooltip("Prefab d'un item livre dans la Library (Button avec TextMeshProUGUI enfant)")]
    public GameObject libraryItemPrefab;

    [Tooltip("Message affiché si aucun livre activé")]
    public TextMeshProUGUI txt_LibraryEmpty;

    // ══════════════════════════════════════════════════════════
    // PANEL SETTINGS — références UI
    // ══════════════════════════════════════════════════════════
    [Header("── Panel Settings ──")]
    [Tooltip("Transform du Content dans le ScrollView de Panel_Settings")]
    public Transform settingsContent;

    [Tooltip("Prefab d'un item dans Settings (contient TextMeshProUGUI + Toggle)")]
    public GameObject settingsItemPrefab;

    [Tooltip("Message affiché si aucun livre scanné")]
    public TextMeshProUGUI txt_SettingsEmpty;

    // ══════════════════════════════════════════════════════════
    // PANEL SCANNER — références UI
    // ══════════════════════════════════════════════════════════
    [Header("── Panel Scanner ──")]
    [Tooltip("Le script QRScanner dans ta scène")]
    public QRScanner qrScanner;

    // ══════════════════════════════════════════════════════════
    // AR SUPPORT
    // ══════════════════════════════════════════════════════════
    [Header("── AR Support ──")]
    public ARSupportChecker arSupportChecker;

    // ══════════════════════════════════════════════════════════
    // SCÈNES ET URLS
    // ══════════════════════════════════════════════════════════
    [Header("── Scènes & URLs ──")]
    public string arSceneName = "GymTesnime";
    public string statsDashboardUrl = "https://arbook-dashboard.vercel.app";

    // ══════════════════════════════════════════════════════════
    // CHAMPS SIGN IN
    // ══════════════════════════════════════════════════════════
    [Header("── Sign In ──")]
    public TMP_InputField signIn_Email;
    public TMP_InputField signIn_Password;
    public TextMeshProUGUI signIn_Feedback;

    // ══════════════════════════════════════════════════════════
    // CHAMPS SIGN UP
    // ══════════════════════════════════════════════════════════
    [Header("── Sign Up ──")]
    public TMP_InputField signUp_Email;
    public TMP_InputField signUp_Username;
    public TMP_InputField signUp_Age;
    public TMP_InputField signUp_Password;
    public TMP_InputField signUp_ConfirmPassword;
    public TextMeshProUGUI signUp_Feedback;

    // ══════════════════════════════════════════════════════════
    // CHAMPS FORGOT PASSWORD
    // ══════════════════════════════════════════════════════════
    [Header("── Forgot Password ──")]
    public TMP_InputField forgot_Email;
    public TextMeshProUGUI forgot_Feedback;

    // ══════════════════════════════════════════════════════════
    // SPLASH
    // ══════════════════════════════════════════════════════════
    [Header("── Splash ──")]
    public float splashDuration = 2.5f;

    // ══════════════════════════════════════════════════════════
    // FIREBASE
    // ══════════════════════════════════════════════════════════
    private FirebaseAuth auth;
    private bool firebaseReady = false;

    // ══════════════════════════════════════════════════════════
    // INIT
    // ══════════════════════════════════════════════════════════
    void Start()
    {
        if (panel_Notification != null)
            panel_Notification.SetActive(false);

        ShowRootPanel(panel_Splash);

        FirebaseApp.CheckAndFixDependenciesAsync().ContinueWith(task =>
        {
            if (task.Result == DependencyStatus.Available)
            {
                auth = FirebaseAuth.DefaultInstance;
                firebaseReady = true;
                Debug.Log("✅ Firebase prêt (AuthManagerV2)");
            }
            else
            {
                Debug.LogError("❌ Firebase error: " + task.Result);
            }
        });

        // S'abonner aux changements de la bibliothèque pour refresh l'UI automatiquement
        if (BookLibraryManager.Instance != null)
            BookLibraryManager.Instance.OnLibraryChanged += OnLibraryDataChanged;

        StartCoroutine(ShowWelcomeAfterSplash());
    }

    void OnDestroy()
    {
        if (BookLibraryManager.Instance != null)
            BookLibraryManager.Instance.OnLibraryChanged -= OnLibraryDataChanged;
    }

    /// Callback déclenché automatiquement quand un livre est ajouté ou son état change
    void OnLibraryDataChanged()
    {
        // Si Panel_Library ou Panel_Settings est visible, refresh son contenu
        if (panel_Library != null && panel_Library.activeSelf)
            RefreshLibraryUI();

        if (panel_Settings != null && panel_Settings.activeSelf)
            RefreshSettingsUI();
    }

    private System.Collections.IEnumerator ShowWelcomeAfterSplash()
    {
        yield return new WaitForSeconds(splashDuration);
        ShowRootPanel(panel_Welcome);
    }

    // ══════════════════════════════════════════════════════════
    // NAVIGATION — CORE
    // ══════════════════════════════════════════════════════════

    void ShowRootPanel(GameObject target)
    {
        panel_Splash.SetActive(false);
        panel_Welcome.SetActive(false);
        panel_Library.SetActive(false);
        panel_Parent.SetActive(false);
        panel_Scanner.SetActive(false);
        panel_Settings.SetActive(false);
        panel_Auth.SetActive(false);
        panel_ChooseExperience.SetActive(false);
        // Panel_Notification est un overlay — pas touché ici

        target.SetActive(true);
    }

    void ShowAuthSubPanel(GameObject subPanel)
    {
        ShowRootPanel(panel_Auth);
        panel_SignIn.SetActive(false);
        panel_SignUp.SetActive(false);
        panel_ForgotPassword.SetActive(false);
        subPanel.SetActive(true);
    }

    // ══════════════════════════════════════════════════════════
    // NAVIGATION — PANEL_WELCOME
    // ══════════════════════════════════════════════════════════

    /// Btn_Library (Welcome) → ouvre la bibliothèque enfant
    public void GoToLibrary()
    {
        ShowRootPanel(panel_Library);
        RefreshLibraryUI();
    }

    /// Btn_ParentSpace (Welcome) → espace parental
    public void GoToParentPanel() => ShowRootPanel(panel_Parent);

    // ══════════════════════════════════════════════════════════
    // NAVIGATION — PANEL_PARENT
    // ══════════════════════════════════════════════════════════

    /// Btn_Library (Parent) → même vue que l'enfant
    public void GoToLibraryFromParent()
    {
        ShowRootPanel(panel_Library);
        RefreshLibraryUI();
    }

    /// Btn_BookManager → Panel_Scanner + active le QR scanner
    public void GoToScanner()
    {
        ShowRootPanel(panel_Scanner);
        qrScanner?.EnableScanner();
    }

    /// Btn_Settings → Panel_Settings
    public void GoToSettings()
    {
        Debug.Log("[Settings] GoToSettings() appele");
        Debug.Log($"[Settings] panel_Settings null? {panel_Settings == null}");
        Debug.Log($"[Settings] settingsContent null? {settingsContent == null}");
        Debug.Log($"[Settings] settingsItemPrefab null? {settingsItemPrefab == null}");
        Debug.Log($"[Settings] BookLibraryManager.Instance null? {BookLibraryManager.Instance == null}");
        if (BookLibraryManager.Instance != null)
            Debug.Log($"[Settings] Livres en memoire : {BookLibraryManager.Instance.GetAllBooks().Count}");
        ShowRootPanel(panel_Settings);
        RefreshSettingsUI();
    }

    /// Btn_Stats → vérifie connexion
    public void OnStatsClicked()
    {
        Debug.Log($"[AuthManagerV2] OnStatsClicked — IsLoggedIn={IsUserLoggedIn()}");

        if (IsUserLoggedIn())
        {
            string userId = auth.CurrentUser.UserId;
            string url = statsDashboardUrl + "?userId=" + userId;
            Debug.Log("[AuthManagerV2] Ouverture stats : " + url);
            Application.OpenURL(url);
        }
        else
        {
            ShowNotification();
        }
    }

    /// Btn_Login (Parent) → SignIn
    public void GoToSignInFromParent() => ShowAuthSubPanel(panel_SignIn);

    /// Btn_Back (Parent) → Welcome
    public void BackToWelcome() => ShowRootPanel(panel_Welcome);

    // ══════════════════════════════════════════════════════════
    // NAVIGATION — PANEL_LIBRARY
    // ══════════════════════════════════════════════════════════

    /// Btn_ParentSpace (Library) → Panel_Parent
    public void GoToParentFromLibrary() => ShowRootPanel(panel_Parent);

    // ══════════════════════════════════════════════════════════
    // NAVIGATION — PANEL_SCANNER
    // ══════════════════════════════════════════════════════════

    /// Btn_Back (Scanner) → désactive scanner + retour Parent
    public void BackFromScanner()
    {
        qrScanner?.DisableScanner();
        ShowRootPanel(panel_Parent);
    }

    // ══════════════════════════════════════════════════════════
    // NAVIGATION — PANEL_SETTINGS
    // ══════════════════════════════════════════════════════════

    /// Btn_Back (Settings) → Panel_Parent
    public void BackFromSettings() => ShowRootPanel(panel_Parent);

    // ══════════════════════════════════════════════════════════
    // NAVIGATION — PANEL_NOTIFICATION (overlay)
    // ══════════════════════════════════════════════════════════

    void ShowNotification()
    {
        if (panel_Notification == null)
        { Debug.LogError("[AuthManagerV2] panel_Notification non assigné !"); return; }
        panel_Notification.SetActive(true);
    }

    public void CloseNotification()
    {
        if (panel_Notification != null)
            panel_Notification.SetActive(false);
    }

    public void GoToSignInFromNotification()
    {
        if (panel_Notification != null)
            panel_Notification.SetActive(false);
        ShowAuthSubPanel(panel_SignIn);
    }

    // ══════════════════════════════════════════════════════════
    // NAVIGATION — PANEL_AUTH interne
    // ══════════════════════════════════════════════════════════

    public void GoToSignUp() => ShowAuthSubPanel(panel_SignUp);
    public void GoToSignIn() => ShowAuthSubPanel(panel_SignIn);
    public void GoToForgotPassword() => ShowAuthSubPanel(panel_ForgotPassword);
    public void BackToParentPanel() => ShowRootPanel(panel_Parent);

    // ══════════════════════════════════════════════════════════
    // UI — PANEL_LIBRARY : génération dynamique
    // ══════════════════════════════════════════════════════════

    /// Construit la liste des livres ACTIVÉS dans Panel_Library.
    void RefreshLibraryUI()
    {
        if (libraryContent == null)
        { Debug.LogWarning("[Library] libraryContent non assigné !"); return; }

        // Vider les anciens items
        foreach (Transform child in libraryContent)
            Destroy(child.gameObject);

        var books = BookLibraryManager.Instance?.GetEnabledBooks()
                    ?? new List<BookLibraryManager.BookEntry>();

        // Message vide
        if (txt_LibraryEmpty != null)
            txt_LibraryEmpty.gameObject.SetActive(books.Count == 0);

        foreach (var book in books)
        {
            // Instancier le prefab item
            var item = Instantiate(libraryItemPrefab, libraryContent);

            // Trouver le TextMeshProUGUI dans le prefab et lui donner le titre
            var label = item.GetComponentInChildren<TextMeshProUGUI>();
            if (label != null)
                label.text = book.title;

            // Clic sur un livre → lancer la scène AR avec ce bookId
            string capturedId = book.bookId; // capture pour la lambda
            var btn = item.GetComponent<Button>();
            if (btn != null)
                btn.onClick.AddListener(() => LaunchARWithBook(capturedId));
        }

        Debug.Log($"[Library] {books.Count} livre(s) affiché(s)");
    }

    /// Lance la scène AR après avoir sélectionné un livre dans Library.
    void LaunchARWithBook(string bookId)
    {
        Debug.Log($"[Library] 🚀 Lancement AR avec livre : {bookId}");
        // Stocker le bookId sélectionné pour que GymTesnime puisse le récupérer
        PlayerPrefs.SetString("selected_bookId", bookId);
        PlayerPrefs.Save();
        UnityEngine.SceneManagement.SceneManager.LoadScene(arSceneName);
    }

    // ══════════════════════════════════════════════════════════
    // UI — PANEL_SETTINGS : génération dynamique
    // ══════════════════════════════════════════════════════════

    /// Construit la liste de TOUS les livres scannés avec leur toggle ON/OFF.
    void RefreshSettingsUI()
    {
        if (settingsContent == null)
        { Debug.LogWarning("[Settings] settingsContent non assigné !"); return; }

        // Vider les anciens items (sauf le premier frame — Destroy est différé)
        foreach (Transform child in settingsContent)
            Destroy(child.gameObject);

        var books = BookLibraryManager.Instance?.GetAllBooks()
                    ?? new List<BookLibraryManager.BookEntry>();

        if (txt_SettingsEmpty != null)
            txt_SettingsEmpty.gameObject.SetActive(books.Count == 0);

        if (settingsItemPrefab == null)
        {
            // ── MODE FALLBACK : pas de prefab → items générés 100% par code ──
            Debug.LogWarning("[Settings] settingsItemPrefab non assigné — mode fallback code");
            BuildSettingsByCode(books);
            return;
        }

        foreach (var book in books)
        {
            var item = Instantiate(settingsItemPrefab, settingsContent);

            // S assurer que le RectTransform a une hauteur fixe
            var rt = item.GetComponent<RectTransform>();
            if (rt != null) rt.sizeDelta = new Vector2(rt.sizeDelta.x, 100f);

            // Label titre
            var label = item.GetComponentInChildren<TextMeshProUGUI>();
            if (label != null)
                label.text = book.title;
            else
                Debug.LogWarning($"[Settings] Pas de TextMeshProUGUI dans le prefab pour {book.bookId}");

            // Toggle ON/OFF
            var toggle = item.GetComponentInChildren<Toggle>();
            if (toggle != null)
            {
                toggle.isOn = book.isEnabled;

                string capturedId = book.bookId;
                toggle.onValueChanged.AddListener((value) =>
                {
                    BookLibraryManager.Instance?.SetBookEnabled(capturedId, value);
                    Debug.Log($"[Settings] {capturedId} → {(value ? "ON" : "OFF")}");
                });
            }
            else
                Debug.LogWarning($"[Settings] Pas de Toggle dans le prefab pour {book.bookId}");
        }

        Debug.Log($"[Settings] {books.Count} livre(s) listé(s) via prefab");
    }

    /// Fallback : construit les items Settings entièrement par code, sans prefab.
    /// Utile pour tester si le problème vient du prefab ou du ScrollView.
    void BuildSettingsByCode(System.Collections.Generic.List<BookLibraryManager.BookEntry> books)
    {
        foreach (var book in books)
        {
            // Conteneur item
            var itemGO = new GameObject($"SettingsItem_{book.bookId}");
            itemGO.transform.SetParent(settingsContent, false);

            var itemImage = itemGO.AddComponent<UnityEngine.UI.Image>();
            itemImage.color = new Color(0.2f, 0.2f, 0.3f, 1f);

            var itemRT = itemGO.GetComponent<RectTransform>();
            itemRT.sizeDelta = new Vector2(0f, 100f); // largeur gérée par layout

            // Layout horizontal pour titre + toggle côte à côte
            var layout = itemGO.AddComponent<UnityEngine.UI.HorizontalLayoutGroup>();
            layout.childAlignment = TextAnchor.MiddleLeft;
            layout.padding = new RectOffset(20, 20, 10, 10);
            layout.spacing = 10f;
            layout.childForceExpandWidth = true;
            layout.childControlWidth = true;
            layout.childControlHeight = true;

            // Layout Element pour hauteur fixe
            var le = itemGO.AddComponent<UnityEngine.UI.LayoutElement>();
            le.minHeight = 100f;
            le.preferredHeight = 100f;

            // ── Titre ──
            var titleGO = new GameObject("Title");
            titleGO.transform.SetParent(itemGO.transform, false);
            var titleTMP = titleGO.AddComponent<TMPro.TextMeshProUGUI>();
            titleTMP.text = book.title;
            titleTMP.fontSize = 28f;
            titleTMP.color = Color.white;
            titleTMP.alignment = TMPro.TextAlignmentOptions.MidlineLeft;
            var titleLE = titleGO.AddComponent<UnityEngine.UI.LayoutElement>();
            titleLE.flexibleWidth = 1f; // prend tout l espace disponible

            // ── Toggle ──
            var toggleGO = new GameObject("Toggle");
            toggleGO.transform.SetParent(itemGO.transform, false);

            // Background du toggle
            var bgGO = new GameObject("Background");
            bgGO.transform.SetParent(toggleGO.transform, false);
            var bgImage = bgGO.AddComponent<UnityEngine.UI.Image>();
            bgImage.color = new Color(0.4f, 0.4f, 0.4f, 1f);
            var bgRT = bgGO.GetComponent<RectTransform>();
            bgRT.sizeDelta = new Vector2(60f, 30f);

            // Checkmark
            var checkGO = new GameObject("Checkmark");
            checkGO.transform.SetParent(bgGO.transform, false);
            var checkImage = checkGO.AddComponent<UnityEngine.UI.Image>();
            checkImage.color = new Color(0.2f, 0.8f, 0.4f, 1f);
            var checkRT = checkGO.GetComponent<RectTransform>();
            checkRT.anchorMin = Vector2.zero;
            checkRT.anchorMax = Vector2.one;
            checkRT.sizeDelta = Vector2.zero;

            var toggle = toggleGO.AddComponent<Toggle>();
            toggle.targetGraphic = bgImage;
            toggle.graphic = checkImage;
            toggle.isOn = book.isEnabled;

            var toggleLE = toggleGO.AddComponent<UnityEngine.UI.LayoutElement>();
            toggleLE.minWidth = 70f;
            toggleLE.preferredWidth = 70f;
            toggleLE.flexibleWidth = 0f;

            string capturedId = book.bookId;
            toggle.onValueChanged.AddListener((value) =>
            {
                BookLibraryManager.Instance?.SetBookEnabled(capturedId, value);
                Debug.Log($"[Settings] {capturedId} → {(value ? "ON" : "OFF")}");
            });
        }

        Debug.Log($"[Settings] {books.Count} livre(s) listé(s) via code (fallback)");
    }

    // ══════════════════════════════════════════════════════════
    // 🔐 REGISTER
    // ══════════════════════════════════════════════════════════
    public void Register()
    {
        if (!firebaseReady) return;

        string email = signUp_Email.text.Trim();
        string username = signUp_Username.text.Trim();
        string ageText = signUp_Age.text.Trim();
        string password = signUp_Password.text;
        string confirm = signUp_ConfirmPassword.text;

        if (string.IsNullOrEmpty(email) || string.IsNullOrEmpty(password))
        { ShowSignUpFeedback("⚠️ Email et mot de passe requis."); return; }

        if (password != confirm)
        { ShowSignUpFeedback("⚠️ Les mots de passe ne correspondent pas."); return; }

        if (password.Length < 6)
        { ShowSignUpFeedback("⚠️ Mot de passe : 6 caractères minimum."); return; }

        if (!int.TryParse(ageText, out int age) || age < 3 || age > 18)
        { ShowSignUpFeedback("⚠️ Age invalide (3-18)."); return; }

        auth.CreateUserWithEmailAndPasswordAsync(email, password).ContinueWith(task =>
        {
            if (task.IsFaulted || task.IsCanceled)
            { ShowSignUpFeedback("❌ " + GetFirebaseError(task.Exception)); return; }

            string userId = task.Result.User.UserId;
            PlayerPrefs.SetString("username", username);
            PlayerPrefs.SetInt("age", age);
            PlayerPrefs.SetString("userId", userId);
            PlayerPrefs.SetString("email", email);
            PlayerPrefs.Save();

            ShowSignUpFeedback("✅ Compte créé avec succès !");

            if (AnalyticsManager.Instance != null)
                AnalyticsManager.Instance.LogUserSignedUp("email");

            UnityMainThreadDispatcher.Instance().Enqueue(() => ShowAuthSubPanel(panel_SignIn));
        });
    }

    // ══════════════════════════════════════════════════════════
    // 🔑 LOGIN — async/await → retour Panel_Parent garanti
    // ══════════════════════════════════════════════════════════
    public async void Login()
    {
        Debug.Log("🟢 [AuthManagerV2] Login() — version V2");

        if (!firebaseReady) { Debug.LogWarning("[AuthManagerV2] Firebase pas encore prêt"); return; }

        string email = signIn_Email.text.Trim();
        string password = signIn_Password.text;

        if (string.IsNullOrEmpty(email) || string.IsNullOrEmpty(password))
        { ShowSignInFeedback("⚠️ Remplis tous les champs."); return; }

        try
        {
            var result = await auth.SignInWithEmailAndPasswordAsync(email, password);

            string userId = result.User.UserId;
            PlayerPrefs.SetString("userId", userId);
            PlayerPrefs.SetString("email", email);
            PlayerPrefs.Save();

            signIn_Feedback.text = "✅ Connecté !";

            if (AnalyticsManager.Instance != null)
                AnalyticsManager.Instance.LogUserLoggedIn("email");

            var events = LocalEventBuffer.Instance?.GetAll();
            Debug.Log($"[AuthManagerV2] Buffer {events?.Count ?? 0} events avant sync");
            FirestoreManager.Instance?.SyncLocalBuffer(userId);

            Debug.Log("🟢 [AuthManagerV2] Login réussi → Panel_Parent");
            ShowRootPanel(panel_Parent);
        }
        catch (Exception ex)
        {
            Debug.LogError("[AuthManagerV2] ❌ Login failed: " + ex.Message);
            signIn_Feedback.text = "❌ " + GetFirebaseErrorFromException(ex);
        }
    }

    // ══════════════════════════════════════════════════════════
    // 🔁 FORGOT PASSWORD
    // ══════════════════════════════════════════════════════════
    public void SendPasswordReset()
    {
        if (!firebaseReady) return;

        string email = forgot_Email.text.Trim();
        if (string.IsNullOrEmpty(email))
        { ShowForgotFeedback("⚠️ Entre ton email."); return; }

        auth.SendPasswordResetEmailAsync(email).ContinueWith(task =>
        {
            if (task.IsFaulted || task.IsCanceled)
            { ShowForgotFeedback("❌ Email introuvable."); return; }
            ShowForgotFeedback("📧 Email de réinitialisation envoyé !");
        });
    }

    // ══════════════════════════════════════════════════════════
    // 🚪 LOGOUT
    // ══════════════════════════════════════════════════════════

    /// Logout complet → recharge la scène (depuis scène AR)
    public void Logout()
    {
        auth?.SignOut();
        PlayerPrefs.DeleteAll();
        UnityEngine.SceneManagement.SceneManager.LoadScene("NewLoginScene");
    }

    /// Logout sur place → reste dans la scène, retour Panel_Parent (pour tests)
    public void LogoutInPlace()
    {
        auth?.SignOut();
        PlayerPrefs.DeleteKey("userId");
        PlayerPrefs.DeleteKey("email");
        PlayerPrefs.Save();
        Debug.Log("[AuthManagerV2] 🚪 Déconnecté — retour Panel_Parent");
        ShowRootPanel(panel_Parent);
    }

    // ══════════════════════════════════════════════════════════
    // HELPERS
    // ══════════════════════════════════════════════════════════

    bool IsUserLoggedIn()
    {
        if (auth == null) return false;
        var user = auth.CurrentUser;
        bool loggedIn = user != null && !user.IsAnonymous;
        Debug.Log($"[AuthManagerV2] IsUserLoggedIn={loggedIn} | user={user?.UserId ?? "null"}");
        return loggedIn;
    }

    void ShowSignUpFeedback(string msg) =>
        UnityMainThreadDispatcher.Instance().Enqueue(() => signUp_Feedback.text = msg);

    void ShowSignInFeedback(string msg) =>
        UnityMainThreadDispatcher.Instance().Enqueue(() => signIn_Feedback.text = msg);

    void ShowForgotFeedback(string msg) =>
        UnityMainThreadDispatcher.Instance().Enqueue(() => forgot_Feedback.text = msg);

    string GetFirebaseError(AggregateException exception)
    {
        var firebaseEx = exception?.InnerException as Firebase.FirebaseException;
        if (firebaseEx == null) return "Erreur inconnue.";
        var errorCode = (AuthError)firebaseEx.ErrorCode;
        return errorCode switch
        {
            AuthError.EmailAlreadyInUse => "Cet email est déjà utilisé.",
            AuthError.WeakPassword => "Mot de passe trop faible.",
            AuthError.InvalidEmail => "Email invalide.",
            AuthError.WrongPassword => "Mot de passe incorrect.",
            AuthError.UserNotFound => "Aucun compte avec cet email.",
            _ => firebaseEx.Message
        };
    }

    string GetFirebaseErrorFromException(Exception exception)
    {
        var firebaseEx = exception as Firebase.FirebaseException
                      ?? exception?.InnerException as Firebase.FirebaseException;
        if (firebaseEx == null) return exception?.Message ?? "Erreur inconnue.";
        var errorCode = (AuthError)firebaseEx.ErrorCode;
        return errorCode switch
        {
            AuthError.EmailAlreadyInUse => "Cet email est déjà utilisé.",
            AuthError.WeakPassword => "Mot de passe trop faible.",
            AuthError.InvalidEmail => "Email invalide.",
            AuthError.WrongPassword => "Mot de passe incorrect.",
            AuthError.UserNotFound => "Aucun compte avec cet email.",
            _ => firebaseEx.Message
        };
    }
}*/


using Firebase;
using Firebase.Auth;
using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// AuthManagerV2 — Nouvelle scène avec architecture UI progressive.
///
/// HIÉRARCHIE CANVAS :
///   Panel_Splash
///   Panel_Welcome        → Btn_Continue(Guest) | Btn_ParentSpace
///   Panel_Parent         → Btn_Stats | Btn_Settings | Btn_BookManager | Btn_Login | Btn_Back
///   Panel_Notification   → msg "connecte-toi" + Btn_Login + Btn_Close
///   Panel_Auth (conteneur)
///     ├── Panel_SignIn
///     ├── Panel_SignUp
///     └── Panel_ForgotPassword
///   Panel_ChooseExperience
/// </summary>
public class AuthManagerV2 : MonoBehaviour
{
    // ── Dans la section [Header] des panels ───────────────────
    [Header("── Nouveaux Panels ──")]
    public GameObject panel_Library;
    public GameObject panel_Settings;
    public GameObject panel_Scanner;

    // ── Référence vers LibraryUIManager ───────────────────────
    [Header("── Library UI ──")]
    public LibraryUIManager libraryUIManager;

    // ── Référence vers QRScanner ──────────────────────────────
    [Header("── QR Scanner ──")]
    public QRScanner qrScanner;

    // ══════════════════════════════════════════════════════════
    // PANELS RACINE
    // ══════════════════════════════════════════════════════════
    [Header("── Panels Racine ──")]
    public GameObject panel_Splash;
    public GameObject panel_Welcome;
    public GameObject panel_Parent;
    public GameObject panel_Auth;
    public GameObject panel_ChooseExperience;

    [Header("── Panel Notification (auth requise) ──")]
    [Tooltip("Overlay affiché quand Stats est cliqué sans être connecté")]
    public GameObject panel_Notification;

    // ══════════════════════════════════════════════════════════
    // SOUS-PANELS AUTH
    // ══════════════════════════════════════════════════════════
    [Header("── Sous-panels Auth ──")]
    public GameObject panel_SignIn;
    public GameObject panel_SignUp;
    public GameObject panel_ForgotPassword;

    // ══════════════════════════════════════════════════════════
    // AR SUPPORT
    // ══════════════════════════════════════════════════════════
    [Header("── AR Support ──")]
    public ARSupportChecker arSupportChecker;

    // ══════════════════════════════════════════════════════════
    // SCÈNE CIBLE
    // ══════════════════════════════════════════════════════════
    [Header("── Scène AR ──")]
    [Tooltip("Nom exact de la scène GymTesnime")]
    public string arSceneName = "GymTesnime";

    [Tooltip("URL du dashboard stats")]
    public string statsDashboardUrl = "https://arbook-dashboard.vercel.app";

    // ══════════════════════════════════════════════════════════
    // CHAMPS SIGN IN
    // ══════════════════════════════════════════════════════════
    [Header("── Sign In ──")]
    public TMP_InputField signIn_Email;
    public TMP_InputField signIn_Password;
    public TextMeshProUGUI signIn_Feedback;

    // ══════════════════════════════════════════════════════════
    // CHAMPS SIGN UP
    // ══════════════════════════════════════════════════════════
    [Header("── Sign Up ──")]
    public TMP_InputField signUp_Email;
    public TMP_InputField signUp_Username;
    public TMP_InputField signUp_Age;
    public TMP_InputField signUp_Password;
    public TMP_InputField signUp_ConfirmPassword;
    public TextMeshProUGUI signUp_Feedback;

    // ══════════════════════════════════════════════════════════
    // CHAMPS FORGOT PASSWORD
    // ══════════════════════════════════════════════════════════
    [Header("── Forgot Password ──")]
    public TMP_InputField forgot_Email;
    public TextMeshProUGUI forgot_Feedback;

    // ══════════════════════════════════════════════════════════
    // SPLASH
    // ══════════════════════════════════════════════════════════
    [Header("── Splash ──")]
    public float splashDuration = 2.5f;

    // ══════════════════════════════════════════════════════════
    // FIREBASE
    // ══════════════════════════════════════════════════════════
    private FirebaseAuth auth;
    private bool firebaseReady = false;

    // ══════════════════════════════════════════════════════════
    // INIT
    // ══════════════════════════════════════════════════════════
    void Start()
    {
        // S'assurer que la notification est fermée au départ
        if (panel_Notification != null)
            panel_Notification.SetActive(false);

        ShowRootPanel(panel_Splash);

        FirebaseApp.CheckAndFixDependenciesAsync().ContinueWith(task =>
        {
            if (task.Result == DependencyStatus.Available)
            {
                auth = FirebaseAuth.DefaultInstance;
                firebaseReady = true;
                Debug.Log("✅ Firebase prêt (AuthManagerV2)");
            }
            else
            {
                Debug.LogError("❌ Firebase error: " + task.Result);
            }
        });

        StartCoroutine(ShowWelcomeAfterSplash());
    }

    private System.Collections.IEnumerator ShowWelcomeAfterSplash()
    {
        yield return new WaitForSeconds(splashDuration);
        ShowRootPanel(panel_Welcome);
    }

    // ══════════════════════════════════════════════════════════
    // NAVIGATION — PANELS RACINE
    // ══════════════════════════════════════════════════════════

    void ShowRootPanel(GameObject target)
    {
        panel_Splash.SetActive(false);
        panel_Welcome.SetActive(false);
        panel_Parent.SetActive(false);
        panel_Auth.SetActive(false);
        panel_ChooseExperience.SetActive(false);
        panel_Library.SetActive(false);   // ← nouveau
        panel_Settings.SetActive(false);  // ← nouveau
        panel_Scanner.SetActive(false);   // ← nouveau

        target.SetActive(true);
    }

    void ShowAuthSubPanel(GameObject subPanel)
    {
        ShowRootPanel(panel_Auth);

        panel_SignIn.SetActive(false);
        panel_SignUp.SetActive(false);
        panel_ForgotPassword.SetActive(false);

        subPanel.SetActive(true);
    }

    // ══════════════════════════════════════════════════════════
    // NAVIGATION — BOUTONS
    // ══════════════════════════════════════════════════════════

    // ── Panel_Welcome ──────────────────────────────────────────

    /// Btn_Continue(Guest) → charge directement la scène AR
    public void ContinueAsGuest()
    {
        PlayerPrefs.SetString("username", "Guest");
        PlayerPrefs.DeleteKey("userId");
        PlayerPrefs.Save();

        UnityEngine.SceneManagement.SceneManager.LoadScene(arSceneName);
    }

    /// Btn_ParentSpace → espace parental
    public void GoToParentPanel() => ShowRootPanel(panel_Parent);

    // ── Panel_Parent ───────────────────────────────────────────

    /// Btn_Stats → vérifie connexion
    /// Appelé aussi depuis ARSupportChecker.OnStatsButtonClicked()
    public void OnStatsClicked()
    {
        Debug.Log($"[AuthManagerV2] OnStatsClicked — IsLoggedIn={IsUserLoggedIn()}");

        if (IsUserLoggedIn())
        {
            // ✅ Connecté → ouvre le dashboard avec l'userId
            string userId = auth.CurrentUser.UserId;
            string url = statsDashboardUrl + "?userId=" + userId;
            Debug.Log("[AuthManagerV2] Ouverture stats : " + url);
            Application.OpenURL(url);
        }
        else
        {
            // ❌ Non connecté → affiche la notification
            Debug.Log("[AuthManagerV2] Non connecté → affichage Panel_Notification");
            ShowNotification();
        }
    }

    /// Btn_Login (dans Panel_Parent) → Panel_SignIn
    public void GoToSignInFromParent() => ShowAuthSubPanel(panel_SignIn);

    /// Btn_Back (dans Panel_Parent) → Welcome
    public void BackToWelcome() => ShowRootPanel(panel_Welcome);

    // ── Panel_Notification (overlay) ───────────────────────────

    void ShowNotification()
    {
        if (panel_Notification == null)
        {
            Debug.LogError("[AuthManagerV2] panel_Notification non assigné dans l'Inspector !");
            return;
        }
        panel_Notification.SetActive(true);
    }

    /// Btn_Close → ferme la notif, reste sur le panel actuel
    public void CloseNotification()
    {
        if (panel_Notification != null)
            panel_Notification.SetActive(false);
    }

    /// Btn_Login dans la notification → ferme notif + ouvre SignIn
    public void GoToSignInFromNotification()
    {
        if (panel_Notification != null)
            panel_Notification.SetActive(false);
        ShowAuthSubPanel(panel_SignIn);
    }

    // ── Panel_Auth — navigation interne ────────────────────────

    public void GoToSignUp() => ShowAuthSubPanel(panel_SignUp);
    public void GoToSignIn() => ShowAuthSubPanel(panel_SignIn);
    public void GoToForgotPassword() => ShowAuthSubPanel(panel_ForgotPassword);

    /// Retour depuis Panel_Auth → Panel_Parent
    public void BackToParentPanel() => ShowRootPanel(panel_Parent);

    // ══════════════════════════════════════════════════════════
    // 🔐 REGISTER
    // ══════════════════════════════════════════════════════════
    public void Register()
    {
        if (!firebaseReady) return;

        string email = signUp_Email.text.Trim();
        string username = signUp_Username.text.Trim();
        string ageText = signUp_Age.text.Trim();
        string password = signUp_Password.text;
        string confirm = signUp_ConfirmPassword.text;

        if (string.IsNullOrEmpty(email) || string.IsNullOrEmpty(password))
        { ShowSignUpFeedback("⚠️ Email et mot de passe requis."); return; }

        if (password != confirm)
        { ShowSignUpFeedback("⚠️ Les mots de passe ne correspondent pas."); return; }

        if (password.Length < 6)
        { ShowSignUpFeedback("⚠️ Mot de passe : 6 caractères minimum."); return; }

        if (!int.TryParse(ageText, out int age) || age < 3 || age > 18)
        { ShowSignUpFeedback("⚠️ Age invalide (3-18)."); return; }

        auth.CreateUserWithEmailAndPasswordAsync(email, password).ContinueWith(task =>
        {
            if (task.IsFaulted || task.IsCanceled)
            { ShowSignUpFeedback("❌ " + GetFirebaseError(task.Exception)); return; }

            string userId = task.Result.User.UserId;
            PlayerPrefs.SetString("username", username);
            PlayerPrefs.SetInt("age", age);
            PlayerPrefs.SetString("userId", userId);
            PlayerPrefs.SetString("email", email);
            PlayerPrefs.Save();

            ShowSignUpFeedback("✅ Compte créé avec succès !");

            if (AnalyticsManager.Instance != null)
                AnalyticsManager.Instance.LogUserSignedUp("email");

            UnityMainThreadDispatcher.Instance().Enqueue(() => ShowAuthSubPanel(panel_SignIn));
        });
    }

    // ══════════════════════════════════════════════════════════
    // 🔑 LOGIN — après connexion → Panel_Parent (pas ChooseExperience)
    // ══════════════════════════════════════════════════════════
    public async void Login()
    {
        Debug.Log("🟢 [AuthManagerV2] Login() appelé — version V2");

        if (!firebaseReady) { Debug.LogWarning("[AuthManagerV2] Firebase pas encore prêt"); return; }

        string email = signIn_Email.text.Trim();
        string password = signIn_Password.text;

        if (string.IsNullOrEmpty(email) || string.IsNullOrEmpty(password))
        { ShowSignInFeedback("⚠️ Remplis tous les champs."); return; }

        try
        {
            var result = await auth.SignInWithEmailAndPasswordAsync(email, password);

            // ✅ On est sur le main thread — pas besoin de Dispatcher
            string userId = result.User.UserId;
            PlayerPrefs.SetString("userId", userId);
            PlayerPrefs.SetString("email", email);
            PlayerPrefs.Save();

            signIn_Feedback.text = "✅ Connecté !";

            if (AnalyticsManager.Instance != null)
                AnalyticsManager.Instance.LogUserLoggedIn("email");

            var events = LocalEventBuffer.Instance?.GetAll();
            Debug.Log($"[AuthManagerV2] Buffer contient {events?.Count ?? 0} events avant sync");
            FirestoreManager.Instance?.SyncLocalBuffer(userId);

            Debug.Log($"🟢 [AuthManagerV2] Login réussi → ShowRootPanel(panel_Parent) | panel_Parent null? {panel_Parent == null}");
            ShowRootPanel(panel_Parent);
        }
        catch (Exception ex)
        {
            Debug.LogError("[AuthManagerV2] ❌ Login failed: " + ex.Message);
            signIn_Feedback.text = "❌ " + GetFirebaseErrorFromException(ex);
        }
    }

    // ══════════════════════════════════════════════════════════
    // 🔁 FORGOT PASSWORD
    // ══════════════════════════════════════════════════════════
    public void SendPasswordReset()
    {
        if (!firebaseReady) return;

        string email = forgot_Email.text.Trim();

        if (string.IsNullOrEmpty(email))
        { ShowForgotFeedback("⚠️ Entre ton email."); return; }

        auth.SendPasswordResetEmailAsync(email).ContinueWith(task =>
        {
            if (task.IsFaulted || task.IsCanceled)
            { ShowForgotFeedback("❌ Email introuvable."); return; }

            ShowForgotFeedback("📧 Email de réinitialisation envoyé !");
        });
    }

    // ══════════════════════════════════════════════════════════
    // 🚪 LOGOUT
    // ══════════════════════════════════════════════════════════

    /// Logout complet → recharge la scène (depuis scène AR par exemple)
    public void Logout()
    {
        auth.SignOut();
        PlayerPrefs.DeleteAll();
        UnityEngine.SceneManagement.SceneManager.LoadScene("NewLoginScene"); // ← adapte
    }

    /// Logout "sur place" → déconnecte et revient à Panel_Parent sans recharger la scène.
    /// Parfait pour tester le cas Stats connecté/non connecté rapidement.
    /// Connecte ce bouton dans Panel_Parent (Btn_Logout).
    public void LogoutInPlace()
    {
        if (auth != null)
            auth.SignOut();

        PlayerPrefs.DeleteKey("userId");
        PlayerPrefs.DeleteKey("email");
        PlayerPrefs.Save();

        Debug.Log("[AuthManagerV2] 🚪 Déconnecté — retour Panel_Parent");

        // Reste sur Panel_Parent pour pouvoir retester Stats immédiatement
        ShowRootPanel(panel_Parent);
    }

    // ══════════════════════════════════════════════════════════
    // HELPERS
    // ══════════════════════════════════════════════════════════

    /// Vérifie via Firebase Auth (source de vérité) si l'utilisateur est connecté.
    bool IsUserLoggedIn()
    {
        // Firebase pas encore prêt → non connecté
        if (auth == null)
        {
            Debug.Log("[AuthManagerV2] auth null — Firebase pas encore initialisé");
            return false;
        }

        var user = auth.CurrentUser;
        bool loggedIn = user != null && !user.IsAnonymous;
        Debug.Log($"[AuthManagerV2] IsUserLoggedIn = {loggedIn} | CurrentUser = {user?.UserId ?? "null"}");
        return loggedIn;
    }

    void ShowSignUpFeedback(string msg) =>
        UnityMainThreadDispatcher.Instance().Enqueue(() => signUp_Feedback.text = msg);

    void ShowSignInFeedback(string msg) =>
        UnityMainThreadDispatcher.Instance().Enqueue(() => signIn_Feedback.text = msg);

    void ShowForgotFeedback(string msg) =>
        UnityMainThreadDispatcher.Instance().Enqueue(() => forgot_Feedback.text = msg);

    string GetFirebaseError(AggregateException exception)
    {
        var firebaseEx = exception?.InnerException as Firebase.FirebaseException;
        if (firebaseEx == null) return "Erreur inconnue.";

        var errorCode = (AuthError)firebaseEx.ErrorCode;
        return errorCode switch
        {
            AuthError.EmailAlreadyInUse => "Cet email est déjà utilisé.",
            AuthError.WeakPassword => "Mot de passe trop faible.",
            AuthError.InvalidEmail => "Email invalide.",
            AuthError.WrongPassword => "Mot de passe incorrect.",
            AuthError.UserNotFound => "Aucun compte avec cet email.",
            _ => firebaseEx.Message
        };
    }

    // Variante pour async/await (Exception directe, pas AggregateException)
    string GetFirebaseErrorFromException(Exception exception)
    {
        var firebaseEx = exception as Firebase.FirebaseException
                      ?? exception?.InnerException as Firebase.FirebaseException;
        if (firebaseEx == null) return exception?.Message ?? "Erreur inconnue.";

        var errorCode = (AuthError)firebaseEx.ErrorCode;
        return errorCode switch
        {
            AuthError.EmailAlreadyInUse => "Cet email est déjà utilisé.",
            AuthError.WeakPassword => "Mot de passe trop faible.",
            AuthError.InvalidEmail => "Email invalide.",
            AuthError.WrongPassword => "Mot de passe incorrect.",
            AuthError.UserNotFound => "Aucun compte avec cet email.",
            _ => firebaseEx.Message
        };
    }
    // ── Nouvelles méthodes de navigation ──────────────────────

    /// Btn_Library (ex-Continue) → Panel_Library
    public void GoToLibrary()
    {
        // ✅ Sauvegarder le nom exact de la scène AR pour BookItemExplore
        PlayerPrefs.SetString("ar_scene_name", arSceneName);
        PlayerPrefs.Save();

        ShowRootPanel(panel_Library);
        libraryUIManager?.RefreshLibrary();
    }

    /// Btn_Settings → Panel_Settings
    public void GoToSettings()
    {
        ShowRootPanel(panel_Settings);
        libraryUIManager?.RefreshSettings();
    }

    /// Btn_BookManager → Panel_Scanner
    public void GoToScanner()
    {
        ShowRootPanel(panel_Scanner);
        qrScanner?.EnableScanner();
    }

    /// Btn_Back depuis Panel_Scanner → Panel_Parent
    public void BackFromScanner()
    {
        qrScanner?.DisableScanner();
        ShowRootPanel(panel_Parent);
    }

    /// Btn_BackToWelcome depuis Panel_Library → Panel_Welcome
    public void BackFromLibrary() => ShowRootPanel(panel_Welcome);

    /// Btn_GoToParent depuis Panel_Library → Panel_Parent
    public void GoToParentFromLibrary() => ShowRootPanel(panel_Parent);

    /// Btn_Back depuis Panel_Settings → Panel_Parent
    public void BackFromSettings() => ShowRootPanel(panel_Parent);




}
/*using Firebase;
using Firebase.Auth;
using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// AuthManagerV2 — Script pour la nouvelle scène avec architecture UI progressive.
///
/// HIÉRARCHIE CANVAS :
///   Panel_Splash
///   Panel_Welcome        → Btn_Continue(Guest) | Btn_ParentSpace
///   Panel_Parent         → Btn_Stats | Btn_Settings | Btn_BookManager | Btn_Login | Btn_Back
///   Panel_Auth (conteneur)
///     ├── Panel_SignIn
///     ├── Panel_SignUp
///     └── Panel_ForgotPassword
///   Panel_ChooseExperience
///
/// NOTE : Logique Firebase identique à AuthManager.cs — seule l'architecture UI change.
/// </summary>
public class AuthManagerV2 : MonoBehaviour
{
    // ══════════════════════════════════════════════════════════
    // PANELS — NIVEAU RACINE (enfants directs du Canvas)
    // ══════════════════════════════════════════════════════════
    [Header("── Panels Racine ──")]
    public GameObject panel_Splash;
    public GameObject panel_Welcome;
    public GameObject panel_Parent;
    public GameObject panel_Auth;           // Conteneur global auth (parent de SignIn/SignUp/Forgot)
    public GameObject panel_ChooseExperience;

    // ══════════════════════════════════════════════════════════
    // SOUS-PANELS AUTH (enfants de Panel_Auth)
    // ══════════════════════════════════════════════════════════
    [Header("── Sous-panels Auth (enfants de Panel_Auth) ──")]
    public GameObject panel_SignIn;
    public GameObject panel_SignUp;
    public GameObject panel_ForgotPassword;

    // ══════════════════════════════════════════════════════════
    // AR SUPPORT
    // ══════════════════════════════════════════════════════════
    [Header("── AR Support ──")]
    public ARSupportChecker arSupportChecker;

    // ══════════════════════════════════════════════════════════
    // SIGN IN FIELDS
    // ══════════════════════════════════════════════════════════
    [Header("── Sign In ──")]
    public TMP_InputField signIn_Email;
    public TMP_InputField signIn_Password;
    public TextMeshProUGUI signIn_Feedback;

    // ══════════════════════════════════════════════════════════
    // SIGN UP FIELDS
    // ══════════════════════════════════════════════════════════
    [Header("── Sign Up ──")]
    public TMP_InputField signUp_Email;
    public TMP_InputField signUp_Username;
    public TMP_InputField signUp_Age;
    public TMP_InputField signUp_Password;
    public TMP_InputField signUp_ConfirmPassword;
    public TextMeshProUGUI signUp_Feedback;

    // ══════════════════════════════════════════════════════════
    // FORGOT PASSWORD FIELDS
    // ══════════════════════════════════════════════════════════
    [Header("── Forgot Password ──")]
    public TMP_InputField forgot_Email;
    public TextMeshProUGUI forgot_Feedback;

    // ══════════════════════════════════════════════════════════
    // SPLASH CONFIG
    // ══════════════════════════════════════════════════════════
    [Header("── Splash ──")]
    [Tooltip("Durée d'affichage du splash screen en secondes")]
    public float splashDuration = 2.5f;

    // ══════════════════════════════════════════════════════════
    // FIREBASE (privé)
    // ══════════════════════════════════════════════════════════
    private FirebaseAuth auth;
    private bool firebaseReady = false;

    // ══════════════════════════════════════════════════════════
    // INIT
    // ══════════════════════════════════════════════════════════
    void Start()
    {
        ShowRootPanel(panel_Splash);

        FirebaseApp.CheckAndFixDependenciesAsync().ContinueWith(task =>
        {
            if (task.Result == DependencyStatus.Available)
            {
                auth = FirebaseAuth.DefaultInstance;
                firebaseReady = true;
                Debug.Log("✅ Firebase prêt (AuthManagerV2)");
            }
            else
            {
                Debug.LogError("❌ Firebase error: " + task.Result);
            }
        });

        StartCoroutine(ShowWelcomeAfterSplash());
    }

    private System.Collections.IEnumerator ShowWelcomeAfterSplash()
    {
        yield return new WaitForSeconds(splashDuration);
        ShowRootPanel(panel_Welcome);
    }

    // ══════════════════════════════════════════════════════════
    // NAVIGATION — PANELS RACINE
    // ══════════════════════════════════════════════════════════

    /// <summary>
    /// Masque tous les panels racine, affiche uniquement la cible.
    /// Panel_Auth est traité comme un panel racine normal ici.
    /// </summary>
    void ShowRootPanel(GameObject target)
    {
        panel_Splash.SetActive(false);
        panel_Welcome.SetActive(false);
        panel_Parent.SetActive(false);
        panel_Auth.SetActive(false);
        panel_ChooseExperience.SetActive(false);

        target.SetActive(true);
    }

    /// <summary>
    /// Active Panel_Auth + affiche uniquement le sous-panel demandé.
    /// Les autres sous-panels sont masqués.
    /// </summary>
    void ShowAuthSubPanel(GameObject subPanel)
    {
        // Activer le conteneur racine Panel_Auth
        ShowRootPanel(panel_Auth);

        // Gérer les sous-panels à l'intérieur
        panel_SignIn.SetActive(false);
        panel_SignUp.SetActive(false);
        panel_ForgotPassword.SetActive(false);

        subPanel.SetActive(true);
    }

    // ══════════════════════════════════════════════════════════
    // NAVIGATION — BOUTONS (à connecter dans l'Inspector)
    // ══════════════════════════════════════════════════════════

    // ── Panel_Welcome ──────────────────────────────────────────

    /// Btn_Continue(Guest) → accès direct sans compte
    public void ContinueAsGuest()
    {
        PlayerPrefs.SetString("username", "Guest");
        PlayerPrefs.DeleteKey("userId");
        PlayerPrefs.Save();

        ShowRootPanel(panel_ChooseExperience);
        arSupportChecker.targetPanel = panel_ChooseExperience;
        arSupportChecker.StartCheck();
    }

    /// Btn_ParentSpace → ouvre l'espace parental
    public void GoToParentPanel() => ShowRootPanel(panel_Parent);

    // ── Panel_Parent ───────────────────────────────────────────

    /// Btn_Login → ouvre Panel_Auth > Panel_SignIn
    public void GoToSignInFromParent() => ShowAuthSubPanel(panel_SignIn);

    /// Btn_Back → retour au Welcome
    public void BackToWelcome() => ShowRootPanel(panel_Welcome);

    // Btn_Stats / Btn_Settings / Btn_BookManager :
    // → Connecte-les directement dans l'Inspector selon ta logique métier
    //   (ouvrir un autre panel, charger une scène, etc.)

    // ── Panel_Auth — navigation interne ────────────────────────

    /// Link_SignUp (depuis SignIn) → Panel_SignUp
    public void GoToSignUp() => ShowAuthSubPanel(panel_SignUp);

    /// Link_BackToSignIn (depuis SignUp ou ForgotPassword) → Panel_SignIn
    public void GoToSignIn() => ShowAuthSubPanel(panel_SignIn);

    /// Link_ForgotPassword (depuis SignIn) → Panel_ForgotPassword
    public void GoToForgotPassword() => ShowAuthSubPanel(panel_ForgotPassword);

    /// Btn retour depuis Panel_Auth → Panel_Parent
    public void BackToParentPanel() => ShowRootPanel(panel_Parent);

    // ══════════════════════════════════════════════════════════
    // 🔐 REGISTER — Logique identique à AuthManager.cs
    // ══════════════════════════════════════════════════════════
    public void Register()
    {
        if (!firebaseReady) return;

        string email = signUp_Email.text.Trim();
        string username = signUp_Username.text.Trim();
        string ageText = signUp_Age.text.Trim();
        string password = signUp_Password.text;
        string confirm = signUp_ConfirmPassword.text;

        if (string.IsNullOrEmpty(email) || string.IsNullOrEmpty(password))
        { ShowSignUpFeedback("⚠️ Email et mot de passe requis."); return; }

        if (password != confirm)
        { ShowSignUpFeedback("⚠️ Les mots de passe ne correspondent pas."); return; }

        if (password.Length < 6)
        { ShowSignUpFeedback("⚠️ Mot de passe : 6 caractères minimum."); return; }

        if (!int.TryParse(ageText, out int age) || age < 3 || age > 18)
        { ShowSignUpFeedback("⚠️ Age invalide (3-18)."); return; }

        auth.CreateUserWithEmailAndPasswordAsync(email, password).ContinueWith(task =>
        {
            if (task.IsFaulted || task.IsCanceled)
            {
                ShowSignUpFeedback("❌ " + GetFirebaseError(task.Exception));
                return;
            }

            string userId = task.Result.User.UserId;
            PlayerPrefs.SetString("username", username);
            PlayerPrefs.SetInt("age", age);
            PlayerPrefs.SetString("userId", userId);
            PlayerPrefs.SetString("email", email);
            PlayerPrefs.Save();

            ShowSignUpFeedback("✅ Compte créé avec succès !");

            if (AnalyticsManager.Instance != null)
                AnalyticsManager.Instance.LogUserSignedUp("email");

            // Après inscription → rediriger vers SignIn
            UnityMainThreadDispatcher.Instance().Enqueue(() => ShowAuthSubPanel(panel_SignIn));
        });
    }

    // ══════════════════════════════════════════════════════════
    // 🔑 LOGIN — Logique identique à AuthManager.cs
    // ══════════════════════════════════════════════════════════
    public void Login()
    {
        if (!firebaseReady) return;

        string email = signIn_Email.text.Trim();
        string password = signIn_Password.text;

        if (string.IsNullOrEmpty(email) || string.IsNullOrEmpty(password))
        { ShowSignInFeedback("⚠️ Remplis tous les champs."); return; }

        auth.SignInWithEmailAndPasswordAsync(email, password).ContinueWith(task =>
        {
            if (task.IsFaulted || task.IsCanceled)
            {
                ShowSignInFeedback("❌ " + GetFirebaseError(task.Exception));
                return;
            }

            string userId = task.Result.User.UserId;
            PlayerPrefs.SetString("userId", userId);
            PlayerPrefs.SetString("email", email);
            PlayerPrefs.Save();

            ShowSignInFeedback("✅ Connecté !");

            if (AnalyticsManager.Instance != null)
                AnalyticsManager.Instance.LogUserLoggedIn("email");

            UnityMainThreadDispatcher.Instance().Enqueue(() =>
            {
                var events = LocalEventBuffer.Instance?.GetAll();
                Debug.Log($"[Auth] Buffer contient {events?.Count ?? 0} events avant sync");
                FirestoreManager.Instance?.SyncLocalBuffer(userId);
ShowRootPanel(panel_Parent);
                //ShowRootPanel(panel_ChooseExperience);
                //arSupportChecker.targetPanel = panel_ChooseExperience;
                //arSupportChecker.StartCheck();

            });
            
        });
    }

    // ══════════════════════════════════════════════════════════
    // 🔁 FORGOT PASSWORD — Logique identique à AuthManager.cs
    // ══════════════════════════════════════════════════════════
    public void SendPasswordReset()
    {
        if (!firebaseReady) return;

        string email = forgot_Email.text.Trim();

        if (string.IsNullOrEmpty(email))
        { ShowForgotFeedback("⚠️ Entre ton email."); return; }

        auth.SendPasswordResetEmailAsync(email).ContinueWith(task =>
        {
            if (task.IsFaulted || task.IsCanceled)
            {
                ShowForgotFeedback("❌ Email introuvable.");
                return;
            }
            ShowForgotFeedback("📧 Email de réinitialisation envoyé !");
        });
    }

    // ══════════════════════════════════════════════════════════
    // 🚪 LOGOUT (appelé depuis la scène AR)
    // ══════════════════════════════════════════════════════════
    public void Logout()
    {
        auth.SignOut();
        PlayerPrefs.DeleteAll();
        UnityEngine.SceneManagement.SceneManager.LoadScene("NewLoginScene"); // ← adapte le nom
    }

    // ══════════════════════════════════════════════════════════
    // HELPERS
    // ══════════════════════════════════════════════════════════
    void ShowSignUpFeedback(string msg) =>
        UnityMainThreadDispatcher.Instance().Enqueue(() => signUp_Feedback.text = msg);

    void ShowSignInFeedback(string msg) =>
        UnityMainThreadDispatcher.Instance().Enqueue(() => signIn_Feedback.text = msg);

    void ShowForgotFeedback(string msg) =>
        UnityMainThreadDispatcher.Instance().Enqueue(() => forgot_Feedback.text = msg);

    string GetFirebaseError(AggregateException exception)
    {
        var firebaseEx = exception?.InnerException as Firebase.FirebaseException;
        if (firebaseEx == null) return "Erreur inconnue.";

        var errorCode = (AuthError)firebaseEx.ErrorCode;
        return errorCode switch
        {
            AuthError.EmailAlreadyInUse => "Cet email est déjà utilisé.",
            AuthError.WeakPassword => "Mot de passe trop faible.",
            AuthError.InvalidEmail => "Email invalide.",
            AuthError.WrongPassword => "Mot de passe incorrect.",
            AuthError.UserNotFound => "Aucun compte avec cet email.",
            _ => firebaseEx.Message
        };
    }
}*/