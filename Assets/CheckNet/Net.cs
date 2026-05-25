using UnityEngine;
using UnityEngine.UI;

public class RequireInternetButton : MonoBehaviour
{
    public GameObject noInternetPanel;

    private Button btn;

    void Awake()
    {
        btn = GetComponent<Button>();
        btn.onClick.AddListener(OnClickCheck);
    }

    void OnClickCheck()
    {
        if (Application.internetReachability == NetworkReachability.NotReachable)
        {
            noInternetPanel.SetActive(true);
            return;
        }

        Debug.Log("✅ Internet disponible");
    }
}
/*using UnityEngine;
using UnityEngine.UI;
using System.Collections.Generic;

public class InternetManager : MonoBehaviour
{
    public List<Button> internetButtons;
    public GameObject noInternetPanel;

    void Start()
    {
        noInternetPanel.SetActive(false);

        foreach (Button btn in internetButtons)
        {
            btn.onClick.AddListener(() =>
            {
                if (Application.internetReachability == NetworkReachability.NotReachable)
                    noInternetPanel.SetActive(true);
            });
        }
    }
}*/