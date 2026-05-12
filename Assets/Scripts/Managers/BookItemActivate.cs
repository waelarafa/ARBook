using System;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class BookItemActivate : MonoBehaviour
{
    [Header("── Références UI ──")]
    public TextMeshProUGUI titleText;
    public Image coverImage;
    public GameObject clockIcon;

    private string _bookId;
    private bool _isEnabled;
    private Action<string, bool> _onToggle;

    public void Setup(string bookId, string title, bool isEnabled,
                      Action<string, bool> onToggle)
    {
        _bookId = bookId;
        _isEnabled = isEnabled;
        _onToggle = onToggle;

        // ✅ 1. Résoudre clockIcon EN PREMIER avant UpdateVisual()
        if (clockIcon == null)
        {
            Transform found = transform.Find("ClockIcon");
            if (found != null)
            {
                clockIcon = found.gameObject;
                Debug.Log("[BookItemActivate] 🔍 ClockIcon trouvé par Find()");
            }
            else
            {
                Debug.LogError("[BookItemActivate] ❌ ClockIcon introuvable !");
            }
        }

        // ✅ 2. Titre
        if (titleText != null)
            titleText.text = title;
        else
            Debug.LogWarning("[BookItemActivate] ⚠️ titleText non assigné");

        // ✅ 3. Cover
        LoadCover(bookId);

        // ✅ 4. Visuel (clockIcon déjà résolu)
        UpdateVisual();

        // ✅ 5. Bouton
        var btn = GetComponent<Button>();
        if (btn != null)
        {
            btn.onClick.RemoveAllListeners();
            btn.onClick.AddListener(OnClicked);
            Debug.Log($"[BookItemActivate] ✅ Bouton lié : {bookId}");
        }
        else
        {
            Debug.LogError($"[BookItemActivate] ❌ Pas de Button sur {gameObject.name}");
        }
    }

    void LoadCover(string bookId)
    {
        if (coverImage == null) return;

        Sprite cover = Resources.Load<Sprite>(bookId);
        if (cover != null)
        {
            coverImage.sprite = cover;
            Debug.Log($"[BookItemActivate] 🖼️ Cover chargée : {bookId}");
        }
        else
        {
            Debug.LogWarning($"[BookItemActivate] ⚠️ Cover introuvable dans Resources/ : '{bookId}'");
        }
    }

    void OnClicked()
    {
        _isEnabled = !_isEnabled;
        Debug.Log($"[BookItemActivate] 🔘 Clic → {_bookId} = {(_isEnabled ? "ACTIVÉ" : "DÉSACTIVÉ")}");
        UpdateVisual();
        _onToggle?.Invoke(_bookId, _isEnabled);
    }

    void UpdateVisual()
    {
        if (clockIcon != null)
        {
            clockIcon.SetActive(!_isEnabled);
            Debug.Log($"[BookItemActivate] 🕐 ClockIcon → {(!_isEnabled ? "visible" : "caché")}");
        }
        else
        {
            Debug.LogError("[BookItemActivate] ❌ clockIcon null dans UpdateVisual() !");
        }
    }
}