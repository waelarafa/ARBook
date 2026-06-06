using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// UI Settings parental : Age + Quota (min) + Période (heures).
/// Le parent ajuste le réservoir et la période ici.
/// </summary>
public class SettingsParentalUI : MonoBehaviour
{
    [Header("── Age ──")]
    public Slider sliderAge;
    public TextMeshProUGUI txtAgeValue;

    [Header("── Quota de jeu ──")]
    public Slider sliderQuota;
    public TextMeshProUGUI txtQuotaValue;   // ex: "30 min"

    [Header("── Période de renouvellement ──")]
    public Slider sliderPeriod;
    public TextMeshProUGUI txtPeriodValue;  // ex: "24h"

    [Header("── Save ──")]
    public Button btnSave;
    public TextMeshProUGUI txtSaveFeedback;

    // ══════════════════════════════════════════════════════════
    void Start()
    {
        // ── Age ───────────────────────────────────────────────
        sliderAge.minValue = 5;
        sliderAge.maxValue = 12;
        sliderAge.wholeNumbers = true;

        // ── Quota : 5 → 120 minutes ───────────────────────────
        sliderQuota.minValue = 5;
        sliderQuota.maxValue = 120;
        sliderQuota.wholeNumbers = true;

        // ── Période : 1 → 72 heures ───────────────────────────
        sliderPeriod.minValue = 1;
        sliderPeriod.maxValue = 72;
        sliderPeriod.wholeNumbers = true;

        // ── Charger valeurs sauvegardées ──────────────────────
        var mgr = ParentalSettingsManager.Instance;
        if (mgr != null)
        {
            sliderAge.value = mgr.ChildAge;
            sliderQuota.value = mgr.QuotaMinutes;
            sliderPeriod.value = mgr.PeriodHours;
        }

        // ── Listeners ─────────────────────────────────────────
        sliderAge.onValueChanged.AddListener(v =>
            txtAgeValue.text = $"{(int)v} ans");

        sliderQuota.onValueChanged.AddListener(v =>
            txtQuotaValue.text = FormatMinutes((int)v));

        sliderPeriod.onValueChanged.AddListener(v =>
            txtPeriodValue.text = FormatHours((int)v));

        btnSave.onClick.AddListener(OnSaveClicked);

        // ── Labels initiaux ───────────────────────────────────
        if (txtAgeValue != null) txtAgeValue.text = $"{(int)sliderAge.value} ans";
        if (txtQuotaValue != null) txtQuotaValue.text = FormatMinutes((int)sliderQuota.value);
        if (txtPeriodValue != null) txtPeriodValue.text = FormatHours((int)sliderPeriod.value);
    }

    // ══════════════════════════════════════════════════════════
    // SAVE
    // ══════════════════════════════════════════════════════════

    void OnSaveClicked()
    {
        ParentalSettingsManager.Instance?.SaveConfig(
            (int)sliderAge.value,
            (int)sliderQuota.value,
            (int)sliderPeriod.value
        );

        if (txtSaveFeedback != null)
        {
            txtSaveFeedback.text = "✅ Enregistré !";
            Invoke(nameof(ClearFeedback), 2f);
        }
    }

    void ClearFeedback()
    {
        if (txtSaveFeedback != null)
            txtSaveFeedback.text = "";
    }

    // ══════════════════════════════════════════════════════════
    // FORMATTERS
    // ══════════════════════════════════════════════════════════

    string FormatMinutes(int m) =>
        m >= 60
        ? $"{m / 60}h{(m % 60 > 0 ? $" {m % 60}min" : "")}"
        : $"{m} min";

    string FormatHours(int h) =>
        h == 1 ? "1h" :
        h == 24 ? "24h (par jour)" :
                  $"{h}h";
}