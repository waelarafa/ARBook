/*tesnime*/
using Firebase;
using Firebase.Auth;
using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class AuthManagerV2 : MonoBehaviour
{
    public static AuthManagerV2 Instance { get; private set; }

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
    // SCÈNE CIBLE
    // ══════════════════════════════════════════════════════════
    [Header("── Scène Tesnime ──")]
    [Tooltip("Nom exact de la scène de Tesnime")]
    public string TesnimeSceneName = "menuscene";

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

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

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

        StartCoroutine(ShowWelcomeAfterSplash());
    }

    private System.Collections.IEnumerator ShowWelcomeAfterSplash()
    {
        string openPanel = PlayerPrefs.GetString("open_panel", "");
        PlayerPrefs.DeleteKey("open_panel");
        PlayerPrefs.Save();

        if (openPanel == "library")
        {
            // Aller directement à library sans attendre le splash
            GoToLibrary();
            yield break;
        }

        // Sinon comportement normal avec splash
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
        panel_Library.SetActive(false);
        panel_Settings.SetActive(false);
        panel_Scanner.SetActive(false);

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

    /// Btn_ParentSpace → espace parental (avec challenge)
    public void GoToParentPanel()
    {
        ParentalChallengeManager.Instance.RequestAccess(() =>
        {
            SessionTimerManager.Instance?.PauseTimer();
            ShowRootPanel(panel_Parent);
        });
    }

    // ── Appelé depuis TimerBlockScreen (challenge déjà réussi) ─
    public void GoToParentPanelDirect()
    {
        SessionTimerManager.Instance?.PauseTimer();
        ShowRootPanel(panel_Parent);
    }

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
            Debug.Log("[AuthManagerV2] Non connecté → affichage Panel_Notification");
            ShowNotification();
        }
    }

    public void GoToSignInFromParent() => ShowAuthSubPanel(panel_SignIn);
    public void BackToWelcome()        => ShowRootPanel(panel_Welcome);

    void ShowNotification()
    {
        if (panel_Notification == null)
        {
            Debug.LogError("[AuthManagerV2] panel_Notification non assigné !");
            return;
        }
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

    public void GoToSignUp()          => ShowAuthSubPanel(panel_SignUp);
    public void GoToSignIn()          => ShowAuthSubPanel(panel_SignIn);
    public void GoToForgotPassword()  => ShowAuthSubPanel(panel_ForgotPassword);
    public void BackToParentPanel()   => ShowRootPanel(panel_Parent);

    // ══════════════════════════════════════════════════════════
    // REGISTER
    // ══════════════════════════════════════════════════════════
    public void Register()
    {
        if (!firebaseReady) return;

        string email    = signUp_Email.text.Trim();
        string username = signUp_Username.text.Trim();
        string ageText  = signUp_Age.text.Trim();
        string password = signUp_Password.text;
        string confirm  = signUp_ConfirmPassword.text;

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
    // LOGIN
    // ══════════════════════════════════════════════════════════
    public async void Login()
    {
        Debug.Log("🟢 [AuthManagerV2] Login() appelé");

        if (!firebaseReady) { Debug.LogWarning("[AuthManagerV2] Firebase pas encore prêt"); return; }

        string email    = signIn_Email.text.Trim();
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
            Debug.Log($"[AuthManagerV2] Buffer contient {events?.Count ?? 0} events avant sync");
            FirestoreManager.Instance?.SyncLocalBuffer(userId, () =>
            {
                // Sync terminée → rebuild map avec les nouvelles données
                LevelMapBuilder.Instance?.RebuildMap();
                Debug.Log("[Auth] ✅ Sync terminée — map reconstruite");
            });

            ShowRootPanel(panel_Parent);
        }
        catch (Exception ex)
        {
            Debug.LogError("[AuthManagerV2] ❌ Login failed: " + ex.Message);
            signIn_Feedback.text = "❌ " + GetFirebaseErrorFromException(ex);
        }
    }

    // ══════════════════════════════════════════════════════════
    // FORGOT PASSWORD
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
    // LOGOUT
    // ══════════════════════════════════════════════════════════
    public void Logout()
    {
        auth.SignOut();
        PlayerPrefs.DeleteAll();
        UnityEngine.SceneManagement.SceneManager.LoadScene("NewLoginScene");
    }

    public void LogoutInPlace()
    {
        if (auth != null)
            auth.SignOut();

        PlayerPrefs.DeleteKey("userId");
        PlayerPrefs.DeleteKey("email");
        PlayerPrefs.Save();

        Debug.Log("[AuthManagerV2] 🚪 Déconnecté — retour Panel_Parent");
        ShowRootPanel(panel_Parent);
    }

    // ══════════════════════════════════════════════════════════
    // NOUVELLES NAVIGATIONS
    // ══════════════════════════════════════════════════════════

    public void GoToLibrary()
    {
        PlayerPrefs.SetString("Tesnime_scene_name", TesnimeSceneName);
        PlayerPrefs.Save();

        ShowRootPanel(panel_Library);
        libraryUIManager?.RefreshLibrary();

        SessionTimerManager.Instance?.StartChildSession();
    }

    public void GoToSettings()
    {
        ShowRootPanel(panel_Settings);
        libraryUIManager?.RefreshSettings();
    }

    public void GoToScanner()
    {
        ShowRootPanel(panel_Scanner);
        qrScanner?.EnableScanner();
    }

    public void BackFromScanner()
    {
        qrScanner?.DisableScanner();
        ShowRootPanel(panel_Parent);
    }

    public void BackFromLibrary()        => ShowRootPanel(panel_Welcome);
    public void GoToParentFromLibrary()  => ShowRootPanel(panel_Parent);
    public void BackFromSettings()       => ShowRootPanel(panel_Parent);

    // ══════════════════════════════════════════════════════════
    // HELPERS
    // ══════════════════════════════════════════════════════════

    bool IsUserLoggedIn()
    {
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
            AuthError.WeakPassword      => "Mot de passe trop faible.",
            AuthError.InvalidEmail      => "Email invalide.",
            AuthError.WrongPassword     => "Mot de passe incorrect.",
            AuthError.UserNotFound      => "Aucun compte avec cet email.",
            _                           => firebaseEx.Message
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
            AuthError.WeakPassword      => "Mot de passe trop faible.",
            AuthError.InvalidEmail      => "Email invalide.",
            AuthError.WrongPassword     => "Mot de passe incorrect.",
            AuthError.UserNotFound      => "Aucun compte avec cet email.",
            _                           => firebaseEx.Message
        };
    }
}
/*tesnime
using Firebase;
using Firebase.Auth;
using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class AuthManagerV2 : MonoBehaviour
{
    public static AuthManagerV2 Instance { get; private set; }

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
    // SCÈNE CIBLE
    // ══════════════════════════════════════════════════════════
    [Header("── Scène Tesnime ──")]
    [Tooltip("Nom exact de la scène de Tesnime")]
    public string TesnimeSceneName = "menuscene";

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

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

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

        StartCoroutine(ShowWelcomeAfterSplash());
    }

    private System.Collections.IEnumerator ShowWelcomeAfterSplash()
    {
        string openPanel = PlayerPrefs.GetString("open_panel", "");
        PlayerPrefs.DeleteKey("open_panel");
        PlayerPrefs.Save();

        if (openPanel == "library")
        {
            // Aller directement à library sans attendre le splash
            GoToLibrary();
            yield break;
        }

        // Sinon comportement normal avec splash
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
        panel_Library.SetActive(false);
        panel_Settings.SetActive(false);
        panel_Scanner.SetActive(false);

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

    public void GoToParentPanel() => ShowRootPanel(panel_Parent);

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
            Debug.Log("[AuthManagerV2] Non connecté → affichage Panel_Notification");
            ShowNotification();
        }
    }

    public void GoToSignInFromParent() => ShowAuthSubPanel(panel_SignIn);
    public void BackToWelcome()        => ShowRootPanel(panel_Welcome);

    void ShowNotification()
    {
        if (panel_Notification == null)
        {
            Debug.LogError("[AuthManagerV2] panel_Notification non assigné !");
            return;
        }
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

    public void GoToSignUp()          => ShowAuthSubPanel(panel_SignUp);
    public void GoToSignIn()          => ShowAuthSubPanel(panel_SignIn);
    public void GoToForgotPassword()  => ShowAuthSubPanel(panel_ForgotPassword);
    public void BackToParentPanel()   => ShowRootPanel(panel_Parent);

    // ══════════════════════════════════════════════════════════
    // REGISTER
    // ══════════════════════════════════════════════════════════
    public void Register()
    {
        if (!firebaseReady) return;

        string email    = signUp_Email.text.Trim();
        string username = signUp_Username.text.Trim();
        string ageText  = signUp_Age.text.Trim();
        string password = signUp_Password.text;
        string confirm  = signUp_ConfirmPassword.text;

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
    // LOGIN
    // ══════════════════════════════════════════════════════════
    public async void Login()
    {
        Debug.Log("🟢 [AuthManagerV2] Login() appelé");

        if (!firebaseReady) { Debug.LogWarning("[AuthManagerV2] Firebase pas encore prêt"); return; }

        string email    = signIn_Email.text.Trim();
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
            Debug.Log($"[AuthManagerV2] Buffer contient {events?.Count ?? 0} events avant sync");
            FirestoreManager.Instance?.SyncLocalBuffer(userId, () =>
{
    // Sync terminée → rebuild map avec les nouvelles données
    LevelMapBuilder.Instance?.RebuildMap();
    Debug.Log("[Auth] ✅ Sync terminée — map reconstruite");
});
            

            ShowRootPanel(panel_Parent);
        }
        catch (Exception ex)
        {
            Debug.LogError("[AuthManagerV2] ❌ Login failed: " + ex.Message);
            signIn_Feedback.text = "❌ " + GetFirebaseErrorFromException(ex);
        }
    }

    // ══════════════════════════════════════════════════════════
    // FORGOT PASSWORD
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
    // LOGOUT
    // ══════════════════════════════════════════════════════════
    public void Logout()
    {
        auth.SignOut();
        PlayerPrefs.DeleteAll();
        UnityEngine.SceneManagement.SceneManager.LoadScene("NewLoginScene");
    }

    public void LogoutInPlace()
    {
        if (auth != null)
            auth.SignOut();

        PlayerPrefs.DeleteKey("userId");
        PlayerPrefs.DeleteKey("email");
        PlayerPrefs.Save();

        Debug.Log("[AuthManagerV2] 🚪 Déconnecté — retour Panel_Parent");
        ShowRootPanel(panel_Parent);
    }

    // ══════════════════════════════════════════════════════════
    // NOUVELLES NAVIGATIONS
    // ══════════════════════════════════════════════════════════

    public void GoToLibrary()
    {
        PlayerPrefs.SetString("Tesnime_scene_name", TesnimeSceneName);
        PlayerPrefs.Save();

        ShowRootPanel(panel_Library);
        libraryUIManager?.RefreshLibrary();
    }

    public void GoToSettings()
    {
        ShowRootPanel(panel_Settings);
        libraryUIManager?.RefreshSettings();
    }

    public void GoToScanner()
    {
        ShowRootPanel(panel_Scanner);
        qrScanner?.EnableScanner();
    }

    public void BackFromScanner()
    {
        qrScanner?.DisableScanner();
        ShowRootPanel(panel_Parent);
    }

    public void BackFromLibrary()        => ShowRootPanel(panel_Welcome);
    public void GoToParentFromLibrary()  => ShowRootPanel(panel_Parent);
    public void BackFromSettings()       => ShowRootPanel(panel_Parent);

    // ══════════════════════════════════════════════════════════
    // HELPERS
    // ══════════════════════════════════════════════════════════

    bool IsUserLoggedIn()
    {
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
            AuthError.WeakPassword      => "Mot de passe trop faible.",
            AuthError.InvalidEmail      => "Email invalide.",
            AuthError.WrongPassword     => "Mot de passe incorrect.",
            AuthError.UserNotFound      => "Aucun compte avec cet email.",
            _                           => firebaseEx.Message
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
            AuthError.WeakPassword      => "Mot de passe trop faible.",
            AuthError.InvalidEmail      => "Email invalide.",
            AuthError.WrongPassword     => "Mot de passe incorrect.",
            AuthError.UserNotFound      => "Aucun compte avec cet email.",
            _                           => firebaseEx.Message
        };
    }
}*/