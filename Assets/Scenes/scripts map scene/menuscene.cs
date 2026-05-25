using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class MenuManager : MonoBehaviour
{
    public static MenuManager Instance { get; private set; }

    private string _currentBookId = "";

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

    void Start()
    {
        _currentBookId = PlayerPrefs.GetString("selected_book_id", "");

        if (string.IsNullOrEmpty(_currentBookId))
            Debug.LogWarning("[MenuManager] ⚠️ selected_book_id vide dans PlayerPrefs.");
        else
            Debug.Log($"[MenuManager] 📖 Livre récupéré : {_currentBookId}");
    }

    public void SetCurrentBookId(string bookId)
    {
        _currentBookId = bookId;
        Debug.Log($"[MenuManager] 📖 Livre sélectionné : {_currentBookId}");
    }

    public void OuvrirSceneAR()
    {
        if (string.IsNullOrEmpty(_currentBookId))
        {
            Debug.LogError("[MenuManager] ❌ Aucun bookId disponible.");
            return;
        }
        StartCoroutine(ChargerSceneAR());
    }

    public void OuvrirSceneMap()
    {
        AnalyticsManager.Instance?.LogChildSessionStarted("3D");
        SceneManager.LoadScene("3DScene");
    }

    public void OuvrirActivityScene()
    {
        AnalyticsManager.Instance?.LogChildSessionStarted("Activity");
        SceneManager.LoadScene("ActivityScene");
    }

    IEnumerator ChargerSceneAR()
    {
        yield return new WaitUntil(() => DataManager.Instance != null);

        if (!DataManager.Instance.IsBookLoaded(_currentBookId))
        {
            Debug.LogError($"[MenuManager] ❌ '{_currentBookId}' absent du cache DataManager.");
            yield break;
        }

        DataManager.Instance.SetLastLoadedBookId(_currentBookId);
        AnalyticsManager.Instance?.LogChildSessionStarted("AR");

        Debug.Log($"[MenuManager] ✅ Ouverture scène AR pour '{_currentBookId}'");

        yield return new WaitForSeconds(0.3f);
        SceneManager.LoadScene("GymTesnime", LoadSceneMode.Single);
    }
}
/*using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class MenuManager : MonoBehaviour
{
    public static MenuManager Instance { get; private set; }

    private string _currentBookId = "";

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

    void Start()
    {
        _currentBookId = PlayerPrefs.GetString("selected_book_id", "");

        if (string.IsNullOrEmpty(_currentBookId))
            Debug.LogWarning("[MenuManager] ⚠️ selected_book_id vide dans PlayerPrefs.");
        else
            Debug.Log($"[MenuManager] 📖 Livre récupéré : {_currentBookId}");
    }

    public void SetCurrentBookId(string bookId)
    {
        _currentBookId = bookId;
        Debug.Log($"[MenuManager] 📖 Livre sélectionné : {_currentBookId}");
    }

    public void OuvrirSceneAR()
    {
        if (string.IsNullOrEmpty(_currentBookId))
        {
            Debug.LogError("[MenuManager] ❌ Aucun bookId disponible.");
            return;
        }
        StartCoroutine(ChargerSceneAR());
    }

    public void OuvrirSceneMap()      => SceneManager.LoadScene("3DScene");
    public void OuvrirActivityScene() => SceneManager.LoadScene("ActivityScene");

    IEnumerator ChargerSceneAR()
    {
        yield return new WaitUntil(() => DataManager.Instance != null);

        if (!DataManager.Instance.IsBookLoaded(_currentBookId))
        {
            Debug.LogError($"[MenuManager] ❌ '{_currentBookId}' absent du cache DataManager.");
            yield break;
        }

        DataManager.Instance.SetLastLoadedBookId(_currentBookId);
        Debug.Log($"[MenuManager] ✅ Ouverture scène AR pour '{_currentBookId}'");

        yield return new WaitForSeconds(0.3f);
        SceneManager.LoadScene("GymTesnime", LoadSceneMode.Single);
    }
}
/*using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class MenuManager : MonoBehaviour
{
    public void OuvrirSceneAR()
    {
        StartCoroutine(ChargerScene("GymTesnime"));
        //SceneManager.LoadScene("GymTesnime");
    }

    public void OuvrirSceneMap()
    {
        //StartCoroutine(ChargerScene("3DScene"));
        SceneManager.LoadScene("3DScene");
    }
    public void OuvrirActivityScene()
    {
        //StartCoroutine(ChargerScene("ActivityScene"));
        SceneManager.LoadScene("ActivityScene");
        
    }

    IEnumerator ChargerScene(string sceneName)
    {
        // Détruit TOUT dans DontDestroyOnLoad automatiquement
        foreach (GameObject go in
            Resources.FindObjectsOfTypeAll<GameObject>())
        {
            if (go.scene.name == "DontDestroyOnLoad")
                Destroy(go);
        }

        yield return new WaitForSeconds(0.3f);

        SceneManager.LoadScene(sceneName, LoadSceneMode.Single);
    }
}
/*using UnityEngine;
using UnityEngine.SceneManagement;

public class MenuManager : MonoBehaviour
{
    public void OuvrirSceneAR()
    {
        SceneManager.LoadScene("GymTesnime");
    }

    public void OuvrirSceneMap()
    {
        SceneManager.LoadScene("testing design");
    }
}*/