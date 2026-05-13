using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using UnityEngine.SceneManagement;

public class BookItemExplore : MonoBehaviour
{
    [Header("── Références UI ──")]
    public TextMeshProUGUI titleText;
    public Image coverImage;

    private string _bookId;

    public void Setup(string bookId, string title)
    {
        _bookId = bookId;

        if (titleText != null)
            titleText.text = title;
        else
            Debug.LogWarning("[BookItemExplore] ⚠️ titleText non assigné");

        if (coverImage != null)
        {
            Sprite cover = Resources.Load<Sprite>(bookId);
            if (cover != null)
                coverImage.sprite = cover;
            else
                Debug.LogWarning($"[BookItemExplore] ⚠️ Cover introuvable : '{bookId}'");
        }

        var btn = GetComponent<Button>();
        if (btn != null)
        {
            btn.onClick.RemoveAllListeners();
            btn.onClick.AddListener(OnExploreClicked);
        }
        else
        {
            Debug.LogError("[BookItemExplore] ❌ Pas de Button sur le prefab !");
        }
    }

    void OnExploreClicked()
    {
        Debug.Log($"[BookItemExplore] 📖 Clic reçu pour : {_bookId}");
        PlayerPrefs.SetString("selected_book_id", _bookId);
        PlayerPrefs.Save();
        /// c'est pour le passage d'une scene à une autre 
        //StartCoroutine(LoadARScene());
    }

    IEnumerator LoadARScene()
    {
        string sceneName = PlayerPrefs.GetString("ar_scene_name", "GymTesnime");
        Debug.Log($"[BookItemExplore] ▶️ Chargement scène : '{sceneName}'");

        // Masquer tous les Canvas
        Canvas[] allCanvases = FindObjectsByType<Canvas>(FindObjectsSortMode.None);
        foreach (var canvas in allCanvases)
            canvas.gameObject.SetActive(false);

        // ✅ Chargement direct sans allowSceneActivation = false
        // Plus simple et plus fiable pour des scènes AR lourdes
        AsyncOperation op = SceneManager.LoadSceneAsync(sceneName, LoadSceneMode.Single);

        if (op == null)
        {
            Debug.LogError($"[BookItemExplore] ❌ Scène '{sceneName}' absente de Build Settings !");
            foreach (var canvas in allCanvases)
                canvas.gameObject.SetActive(true);
            yield break;
        }

        // Laisser Unity gérer l'activation automatiquement
        while (!op.isDone)
        {
            Debug.Log($"[BookItemExplore] ⏳ {op.progress * 100f:F0}%");
            yield return null;
        }

        Debug.Log("[BookItemExplore] ✅ Scène AR chargée !");
    }
}