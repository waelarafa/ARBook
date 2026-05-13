using UnityEngine;
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
}