using UnityEngine;

public class SessionManager : MonoBehaviour
{
    public static SessionManager Instance { get; private set; }

    public string CurrentBookId  { get; private set; }
    public string CurrentThemeId { get; private set; }

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    public void SetContext(string bookId, string themeId)
    {
        CurrentBookId  = bookId;
        CurrentThemeId = themeId;
        Debug.Log($"[SessionManager] Contexte : {bookId} / {themeId}");
    }
}