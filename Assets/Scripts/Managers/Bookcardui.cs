using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// BookCardUI — Composant attaché sur BookCardPrefab.
///
/// STRUCTURE DU PREFAB (à créer dans Unity) :
///
///   BookCardPrefab
///    ├── CardBackground   (Image — blanc, coins arrondis via Sprite)
///    ├── CoverImage       (Image — couverture du livre)
///    ├── TitleTMP         (TextMeshProUGUI — nom du livre)
///    ├── LockIcon         (GameObject — 🔒 affiché si désactivé dans Settings)
///    ├── ToggleContainer  (GameObject — visible dans Settings seulement)
///    │    └── Toggle      (composant Unity UI)
///    └── Button           (Button sur CardBackground — pour Library)
///
/// USAGE dans AuthManagerV2 :
///   var card = Instantiate(bookCardPrefab, content);
///   card.GetComponent<BookCardUI>().Setup(book, showToggle: true/false, onCLick);
/// </summary>
public class BookCardUI : MonoBehaviour
{
    // ── Références UI (à assigner dans le Prefab) ─────────────
    [Header("── Références Prefab ──")]
    public Image coverImage;
    public TextMeshProUGUI titleText;
    public GameObject lockIcon;          // affiché si désactivé
    public GameObject toggleContainer;   // visible dans Settings
    public Toggle toggle;
    public Button cardButton;        // clic → AR (Library)
    public TextMeshProUGUI stateLabel;        // "Activé" / "Désactivé"

    // ── Couleurs toggle ───────────────────────────────────────
    private static readonly Color ColorEnabled = new Color(0.20f, 0.75f, 0.35f);
    private static readonly Color ColorDisabled = new Color(0.75f, 0.75f, 0.75f);

    // ══════════════════════════════════════════════════════════
    // SETUP PRINCIPAL
    // ══════════════════════════════════════════════════════════

    /// <summary>
    /// Configure la carte selon le contexte.
    /// showToggle = true  → Settings (toggle ON/OFF visible)
    /// showToggle = false → Library  (bouton clic → AR)
    /// onCardClick        → action exécutée au clic (Library uniquement)
    /// </summary>
    public void Setup(BookLibraryManager.BookEntry book,
                      bool showToggle,
                      System.Action onCardClick = null)
    {
        // ── Couverture ────────────────────────────────────────
        SetCover(book.bookId, book.title);

        // ── Titre ─────────────────────────────────────────────
        if (titleText != null)
            titleText.text = book.title;

        // ── Mode Settings (toggle ON/OFF) ─────────────────────
        if (toggleContainer != null)
            toggleContainer.SetActive(showToggle);

        if (showToggle)
            SetupToggle(book);

        // ── Mode Library (bouton clic) ────────────────────────
        if (cardButton != null)
        {
            cardButton.onClick.RemoveAllListeners();
            if (!showToggle && onCardClick != null)
                cardButton.onClick.AddListener(() => onCardClick());

            // En mode Settings, le bouton est désactivé (le toggle gère l'interaction)
            cardButton.interactable = !showToggle;
        }

        // ── Icône cadenas ─────────────────────────────────────
        // Visible dans Settings si le livre est désactivé
        if (lockIcon != null)
            lockIcon.SetActive(showToggle && !book.isEnabled);
    }

    // ══════════════════════════════════════════════════════════
    // COUVERTURE
    // ══════════════════════════════════════════════════════════

    void SetCover(string bookId, string title)
    {
        if (coverImage == null) return;

        // Essayer de charger l'image depuis Resources/BookCovers/
        Sprite cover = Resources.Load<Sprite>("BookCovers/" + bookId);

        if (cover != null)
        {
            // ✅ Image trouvée → l'afficher
            coverImage.sprite = cover;
            coverImage.color = Color.white;
        }
        else
        {
            // ❌ Pas d'image → fallback couleur + emoji
            Debug.Log($"[BookCardUI] Pas d'image pour {bookId} — fallback emoji");
            coverImage.sprite = null;
            coverImage.color = GetBookColor(bookId);

            // Afficher l'emoji dans le coverImage via un enfant texte si présent
            var emojiText = coverImage.GetComponentInChildren<TextMeshProUGUI>();
            if (emojiText != null)
                emojiText.text = GetBookEmoji(title);
        }
    }

    // ══════════════════════════════════════════════════════════
    // TOGGLE SETUP
    // ══════════════════════════════════════════════════════════

    void SetupToggle(BookLibraryManager.BookEntry book)
    {
        if (toggle == null) return;

        // Valeur initiale
        toggle.isOn = book.isEnabled;
        UpdateToggleVisuals(book.isEnabled);

        // Listener
        toggle.onValueChanged.RemoveAllListeners();
        string capturedId = book.bookId;

        toggle.onValueChanged.AddListener((value) =>
        {
            BookLibraryManager.Instance?.SetBookEnabled(capturedId, value);
            UpdateToggleVisuals(value);

            // Mettre à jour le cadenas en temps réel
            if (lockIcon != null)
                lockIcon.SetActive(!value);

            Debug.Log($"[BookCardUI] {capturedId} → {(value ? "ON ✅" : "OFF 🔒")}");
        });
    }

    void UpdateToggleVisuals(bool isEnabled)
    {
        // Couleur du label état
        if (stateLabel != null)
        {
            stateLabel.text = isEnabled ? "Activé" : "Désactivé";
            stateLabel.color = isEnabled ? ColorEnabled : ColorDisabled;
        }

        // Couleur background du toggle (si Image sur le toggle)
        if (toggle != null && toggle.targetGraphic != null)
            toggle.targetGraphic.color = isEnabled ? ColorEnabled : ColorDisabled;
    }

    // ══════════════════════════════════════════════════════════
    // HELPERS — Fallback visuel (si pas d'image)
    // ══════════════════════════════════════════════════════════

    static Color GetBookColor(string bookId)
    {
        Color[] palette =
        {
            new Color(0.98f, 0.45f, 0.25f), // orange
            new Color(0.25f, 0.65f, 0.98f), // bleu
            new Color(0.35f, 0.78f, 0.40f), // vert
            new Color(0.75f, 0.35f, 0.90f), // violet
            new Color(0.98f, 0.75f, 0.10f), // jaune
            new Color(0.90f, 0.30f, 0.50f), // rose
            new Color(0.20f, 0.75f, 0.80f), // cyan
            new Color(0.55f, 0.40f, 0.90f), // indigo
        };
        int hash = 0;
        foreach (char c in bookId) hash += c;
        return palette[hash % palette.Length];
    }

    static string GetBookEmoji(string title)
    {
        string t = title.ToLower();
        if (t.Contains("animal") || t.Contains("animaux") || t.Contains("forêt") || t.Contains("dino"))
            return "🐾";
        if (t.Contains("alphabet") || t.Contains("lettre") || t.Contains("arabe")
            || t.Contains("anglais") || t.Contains("français") || t.Contains("allemand"))
            return "🔤";
        if (t.Contains("math") || t.Contains("chiffre") || t.Contains("nombre"))
            return "🔢";
        if (t.Contains("solaire") || t.Contains("planète") || t.Contains("espace"))
            return "🌍";
        if (t.Contains("anatomie") || t.Contains("corps") || t.Contains("organe"))
            return "🫀";
        if (t.Contains("fruit") || t.Contains("légume"))
            return "🍎";
        return "📖";
    }
}