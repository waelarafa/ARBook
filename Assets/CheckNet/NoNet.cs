using UnityEngine;
using UnityEngine.UI;

public class NoInternetPanel : MonoBehaviour
{
    public Button okButton;

    void Start()
    {
        okButton.onClick.AddListener(() => gameObject.SetActive(false));
    }
}