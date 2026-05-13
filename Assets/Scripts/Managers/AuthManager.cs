using Firebase;
using Firebase.Auth;
using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class AuthManager : MonoBehaviour
{
    // ══════════════════════════════════════
    // PANELS
    // ══════════════════════════════════════
    [Header("Panels")]
    public GameObject panelGetStarted;
    public GameObject panelSignUp;
    public GameObject panelSignIn;
    public GameObject panelForgotPassword;

    // ══════════════════════════════════════
    // SIGN UP FIELDS
    // ══════════════════════════════════════
    [Header("Sign Up Fields")]
    public TMP_InputField signUp_Email;
    public TMP_InputField signUp_Username;
    public TMP_InputField signUp_Age;
    public TMP_InputField signUp_Password;
    public TMP_InputField signUp_ConfirmPassword;
    public TextMeshProUGUI signUp_Feedback;

    // ══════════════════════════════════════
    // SIGN IN FIELDS
    // ══════════════════════════════════════
    [Header("Sign In Fields")]
    public TMP_InputField signIn_Email;
    public TMP_InputField signIn_Password;
    public TextMeshProUGUI signIn_Feedback;

    [Header("AR Support")]
    public GameObject panelChooseExperience;
    public ARSupportChecker arSupportChecker;
    // ══════════════════════════════════════
    // FORGOT PASSWORD FIELDS
    // ══════════════════════════════════════
    [Header("Forgot Password")]
    public TMP_InputField forgot_Email;
    public TextMeshProUGUI forgot_Feedback;

    // ══════════════════════════════════════
    // FIREBASE
    // ══════════════════════════════════════
    private FirebaseAuth auth;
    private bool firebaseReady = false;

   
    // ══════════════════════════════════════
    // INIT
    // ══════════════════════════════════════
    void Start()
    {
        // Affiche GetStarted au départ
        ShowPanel(panelGetStarted);

        // Init Firebase
        FirebaseApp.CheckAndFixDependenciesAsync().ContinueWith(task =>
        {
            if (task.Result == DependencyStatus.Available)
            {
                auth = FirebaseAuth.DefaultInstance;
                firebaseReady = true;
                Debug.Log("✅ Firebase prêt");
            }
            else
            {
                Debug.LogError("❌ Firebase error: " + task.Result);
            }
        });
    }

    // ══════════════════════════════════════
    // NAVIGATION ENTRE PANELS
    // ══════════════════════════════════════
    void ShowPanel(GameObject target)
    {
        panelGetStarted.SetActive(false);
        panelSignUp.SetActive(false);
        panelSignIn.SetActive(false);
        panelForgotPassword.SetActive(false);
        panelChooseExperience.SetActive(false);
        target.SetActive(true);
    }

    // Boutons de navigation (connecter dans Inspector)
    public void GoToSignUp() => ShowPanel(panelSignUp);
    public void GoToSignIn() => ShowPanel(panelSignIn);
    public void GoToGetStarted() => ShowPanel(panelGetStarted);
    public void GoToForgotPassword() => ShowPanel(panelForgotPassword);

    // ══════════════════════════════════════
    // 🔐 REGISTER
    // ══════════════════════════════════════
    public void Register()
    {
        if (!firebaseReady) return;

        string email = signUp_Email.text.Trim();
        string username = signUp_Username.text.Trim();
        string ageText = signUp_Age.text.Trim();
        string password = signUp_Password.text;
        string confirm = signUp_ConfirmPassword.text;

        // Validations
        if (string.IsNullOrEmpty(email) || string.IsNullOrEmpty(password))
        { ShowSignUpFeedback("⚠️ Email et mot de passe requis."); return; }

        if (password != confirm)
        { ShowSignUpFeedback("⚠️ Les mots de passe ne correspondent pas."); return; }

        if (password.Length < 6)
        { ShowSignUpFeedback("⚠️ Mot de passe : 6 caractères minimum."); return; }

        if (!int.TryParse(ageText, out int age) || age < 3 || age > 18)
        { ShowSignUpFeedback("⚠️ Age invalide (3-18)."); return; }

        // Création du compte Firebase
        auth.CreateUserWithEmailAndPasswordAsync(email, password).ContinueWith(task =>
        {
            if (task.IsFaulted || task.IsCanceled)
            {
                ShowSignUpFeedback("❌ " + GetFirebaseError(task.Exception));
                return;
            }

            // Sauvegarde locale avec PlayerPrefs
            string userId = task.Result.User.UserId;
            PlayerPrefs.SetString("username", username);
            PlayerPrefs.SetInt("age", age);
            PlayerPrefs.SetString("userId", userId);
            PlayerPrefs.SetString("email", email);
            PlayerPrefs.Save();

            ShowSignUpFeedback("✅ Compte créé avec succès !");
            if (AnalyticsManager.Instance != null)
                AnalyticsManager.Instance.LogUserSignedUp("email");

            // Aller au Sign In après inscription
            UnityMainThreadDispatcher.Instance().Enqueue(() =>
            {
                ShowPanel(panelSignIn);
            });
        });
    }

    // ══════════════════════════════════════
    // 🔑 LOGIN
    // ══════════════════════════════════════
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

            // Charger la scène AR

            UnityMainThreadDispatcher.Instance().Enqueue(() =>
            {
                var events = LocalEventBuffer.Instance?.GetAll();
                Debug.Log($"[Auth] Buffer contient {events?.Count ?? 0} events avant sync");
                // userId déjà déclaré plus haut dans la lambda — on utilise directement
                FirestoreManager.Instance?.SyncLocalBuffer(userId);
                ShowPanel(panelChooseExperience);
                arSupportChecker.targetPanel = panelChooseExperience;
                arSupportChecker.StartCheck();
            });
        });
    }

    // ══════════════════════════════════════
    // 👤 GUEST LOGIN
    // ══════════════════════════════════════
    /*public void GuestLogin()
    {
        if (!firebaseReady) return;

        auth.SignInAnonymouslyAsync().ContinueWith(task =>
        {
            if (task.IsFaulted || task.IsCanceled)
            {
                Debug.LogError("❌ Guest login failed");
                return;
            }

            PlayerPrefs.SetString("userId", task.Result.User.UserId);
            PlayerPrefs.SetString("username", "Guest");
            PlayerPrefs.Save();

            if (AnalyticsManager.Instance != null)
                AnalyticsManager.Instance.LogUserLoggedIn("guest");

            UnityMainThreadDispatcher.Instance().Enqueue(() =>
            {
                ShowPanel(panelChooseExperience);
                arSupportChecker.targetPanel = panelChooseExperience;
                arSupportChecker.StartCheck();
            });
        });
    }*/

    // ══════════════════════════════════════
    // 👤 CONTINUER SANS COMPTE (plus de Firebase anonymous)
    // ══════════════════════════════════════
    public void GuestLogin()
    {
        // Pas de Firebase Auth — juste navigation directe
        PlayerPrefs.SetString("username", "Guest");
        PlayerPrefs.DeleteKey("userId"); // s'assurer qu'aucun ancien ID traîne
        PlayerPrefs.Save();

        UnityMainThreadDispatcher.Instance().Enqueue(() =>
        {
            ShowPanel(panelChooseExperience);
            arSupportChecker.targetPanel = panelChooseExperience;
            arSupportChecker.StartCheck();
        });
    }

    // ══════════════════════════════════════
    // 🔁 FORGOT PASSWORD
    // ══════════════════════════════════════
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

    // ══════════════════════════════════════
    // 🚪 LOGOUT (appelé depuis ARScene)
    // ══════════════════════════════════════
    public void Logout()
    {
        auth.SignOut();
        PlayerPrefs.DeleteAll();
        UnityEngine.SceneManagement.SceneManager.LoadScene("LoginScene");
    }

    // ══════════════════════════════════════
    // HELPERS
    // ══════════════════════════════════════
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
}


/*using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using Firebase;
using Firebase.Auth;
using TMPro;

public class AuthManager : MonoBehaviour
{
    // ── Firebase ──
    private FirebaseAuth auth;

    // ── UI References ──
    [Header("UI Elements")]
    public TMP_InputField emailInput;
    public TMP_InputField passwordInput;
    public TextMeshProUGUI feedbackText;

    // ── Init ──
    void Start()
    {
        // Vérifie que Firebase est bien configuré
        FirebaseApp.CheckAndFixDependenciesAsync().ContinueWith(task =>
        {
            if (task.Result == DependencyStatus.Available)
            {
                auth = FirebaseAuth.DefaultInstance;
                Debug.Log("✅ Firebase initialisé avec succès");
            }
            else
            {
                Debug.LogError("❌ Firebase non disponible : " + task.Result);
            }
        });
    }

    // ────────────────────────────────────────────
    // 🔐 REGISTER — Créer un compte
    // ────────────────────────────────────────────
    public void Register()
    {
        string email = emailInput.text.Trim();
        string password = passwordInput.text;

        if (string.IsNullOrEmpty(email) || string.IsNullOrEmpty(password))
        {
            ShowFeedback("⚠️ Veuillez remplir tous les champs.");
            return;
        }

        auth.CreateUserWithEmailAndPasswordAsync(email, password).ContinueWith(task =>
        {
            if (task.IsCanceled || task.IsFaulted)
            {
                ShowFeedback("❌ Erreur : " + task.Exception.InnerException.Message);
                return;
            }

            FirebaseUser newUser = task.Result.User;
            ShowFeedback("✅ Compte créé : " + newUser.Email);
            Debug.Log("Utilisateur créé : " + newUser.UserId);
        });
    }

    // ────────────────────────────────────────────
    // 🔑 LOGIN — Se connecter
    // ────────────────────────────────────────────
    public void Login()
    {
        string email = emailInput.text.Trim();
        string password = passwordInput.text;

        if (string.IsNullOrEmpty(email) || string.IsNullOrEmpty(password))
        {
            ShowFeedback("⚠️ Veuillez remplir tous les champs.");
            return;
        }

        auth.SignInWithEmailAndPasswordAsync(email, password).ContinueWith(task =>
        {
            if (task.IsCanceled || task.IsFaulted)
            {
                ShowFeedback("❌ Erreur : " + task.Exception.InnerException.Message);
                return;
            }

            FirebaseUser user = task.Result.User;
            ShowFeedback("✅ Connecté : " + user.Email);
            Debug.Log("User ID : " + user.UserId);

            // 👉 Tu peux charger la scène AR ici
            // UnityMainThreadDispatcher.Enqueue(() => SceneManager.LoadScene("ARScene"));
        });
    }

    // ────────────────────────────────────────────
    // 👤 GUEST LOGIN — Sans compte
    // ────────────────────────────────────────────
    public void GuestLogin()
    {
        auth.SignInAnonymouslyAsync().ContinueWith(task =>
        {
            if (task.IsCanceled || task.IsFaulted)
            {
                ShowFeedback("❌ Erreur Guest : " + task.Exception.InnerException.Message);
                return;
            }

            FirebaseUser guestUser = task.Result.User;
            ShowFeedback("👤 Connecté en tant qu'invité");
            Debug.Log("Guest ID : " + guestUser.UserId);

            // 👉 Charger la scène AR directement
        });
    }

    // ────────────────────────────────────────────
    // 🚪 LOGOUT — Se déconnecter
    // ────────────────────────────────────────────
    public void Logout()
    {
        auth.SignOut();
        ShowFeedback("🚪 Déconnecté.");
        Debug.Log("Utilisateur déconnecté");

        // 👉 Revenir à la scène Login si nécessaire
        // SceneManager.LoadScene("LoginScene");
    }

    // ────────────────────────────────────────────
    // 💬 Afficher un message dans l'UI
    // ────────────────────────────────────────────
    private void ShowFeedback(string message)
    {
        // Firebase tourne sur un thread séparé → on revient au main thread
        UnityMainThreadDispatcher.Instance().Enqueue(() =>
        {
            feedbackText.text = message;
        });
    }
}*/