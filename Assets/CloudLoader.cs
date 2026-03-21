using System.Collections;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;
using System.Collections.Generic;

[System.Serializable]
public class ItemData
{
    public string nom;
    public float x, y, z;
}

[System.Serializable]
public class PageData
{
    public string id;
    public string nom;
    public string feuille;
    public List<ItemData> items;
}

[System.Serializable]
public class LivreData
{
    public List<PageData> pages;
}

public class CloudLoader : MonoBehaviour
{
    [Header("URL GitHub Pages")]
    public string jsonURL =
        "https://tesnimemechmech.github.io/ar-livre-assets/livre.json";

    public LivreData livre { get; private set; }
    public bool estCharge { get; private set; } = false;

    private AnimalDetector detector;
    private CloudImageLoader imageLoader;

    private GameObject canvasChargement;
    private Text messageChargement;

    void Start()
    {
        detector = GetComponent<AnimalDetector>();
        imageLoader = GetComponent<CloudImageLoader>();
        CreerUIChargement();

        // 1. D'abord charger le JSON
        StartCoroutine(ChargerJSON());
    }

    IEnumerator ChargerJSON()
    {
        AfficherMessage("⏳ Connexion à GitHub...");
        Debug.Log("📥 Téléchargement JSON : " + jsonURL);

        UnityWebRequest request = UnityWebRequest.Get(jsonURL);
        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            string json = request.downloadHandler.text;
            Debug.Log("✅ JSON reçu : " + json);

            livre = JsonUtility.FromJson<LivreData>(json);

            if (livre != null && livre.pages != null)
            {
                Debug.Log("✅ " + livre.pages.Count + " pages chargées !");

                // 2. Extraire tous les noms d'images depuis le JSON
                List<string> toutesLesImages = ExtraireNomImages(livre);

                // 3. Passer les noms à CloudImageLoader
                AfficherMessage("⏳ Chargement des images...");
                yield return StartCoroutine(
                    imageLoader.ChargerImages(toutesLesImages, OnImagesChargees)
                );
            }
            else
            {
                AfficherMessage("❌ JSON invalide !");
                Debug.LogError("❌ JSON invalide !");
            }
        }
        else
        {
            AfficherMessage("❌ Erreur connexion !\n" + request.error);
            Debug.LogError("❌ Erreur : " + request.error);
        }
    }

    // Extraire tous les noms depuis le JSON automatiquement
    List<string> ExtraireNomImages(LivreData livre)
    {
        List<string> noms = new List<string>();

        foreach (PageData page in livre.pages)
        {
            // Ajouter la feuille
            if (!noms.Contains(page.feuille))
            {
                noms.Add(page.feuille);
                Debug.Log("📄 Feuille trouvée : " + page.feuille);
            }

            // Ajouter les animaux
            foreach (ItemData item in page.items)
            {
                string nomImage = item.nom;
                if (!noms.Contains(nomImage))
                {
                    noms.Add(nomImage);
                    Debug.Log("🐾 Animal trouvé : " + nomImage);
                }
            }
        }

        return noms;
    }

    // Appelée quand toutes les images sont chargées
    void OnImagesChargees()
    {
        AfficherMessage("");
        canvasChargement.SetActive(false);
        estCharge = true;

        // 4. Maintenant démarrer la détection
        detector.OnCloudCharge(livre);
    }

    void CreerUIChargement()
    {
        canvasChargement = new GameObject("CanvasChargement");
        Canvas canvas = canvasChargement.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder = 1000;
        canvasChargement.AddComponent<CanvasScaler>();
        canvasChargement.AddComponent<GraphicRaycaster>();

        GameObject fond = new GameObject("Fond");
        fond.transform.SetParent(canvasChargement.transform, false);
        Image img = fond.AddComponent<Image>();
        img.color = new Color(0, 0, 0, 0.95f);
        RectTransform r = fond.GetComponent<RectTransform>();
        r.anchorMin = Vector2.zero;
        r.anchorMax = Vector2.one;
        r.sizeDelta = Vector2.zero;

        GameObject textObj = new GameObject("TexteChargement");
        textObj.transform.SetParent(canvasChargement.transform, false);
        messageChargement = textObj.AddComponent<Text>();
        messageChargement.font =
            Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        messageChargement.fontSize = 40;
        messageChargement.color = Color.white;
        messageChargement.alignment = TextAnchor.MiddleCenter;
        messageChargement.text = "⏳ Chargement...";
        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin = Vector2.zero;
        rt.anchorMax = Vector2.one;
        rt.sizeDelta = Vector2.zero;
    }

    void AfficherMessage(string msg)
    {
        if (messageChargement != null)
            messageChargement.text = msg;
    }
}
/*using System.Collections;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;
using System.Collections.Generic;

[System.Serializable]
public class ItemData
{
    public string nom;
    public float x, y, z;
}

[System.Serializable]
public class PageData
{
    public string id;
    public string nom;
    public string feuille;
    public List<ItemData> items;
}

[System.Serializable]
public class LivreData
{
    public List<PageData> pages;
}

public class CloudLoader : MonoBehaviour
{
    [Header("URL GitHub Pages")]
    public string jsonURL =
        "https://TON_USERNAME.github.io/ar-livre-assets/livre.json";

    public LivreData livre
    { get; private set; }

    public bool estCharge
    { get; private set; } = false;

    private AnimalDetector detector;
    private CloudImageLoader imageLoader; // ← ajouté

    private GameObject canvasChargement;
    private Text messageChargement;

    void Start()
    {
        detector = GetComponent<AnimalDetector>();
        imageLoader = GetComponent<CloudImageLoader>(); // ← ajouté
        CreerUIChargement();
        StartCoroutine(AttendreEtCharger()); // ← modifié
    }

    // ← Nouvelle méthode ajoutée
    IEnumerator AttendreEtCharger()
    {
        // Attendre que les images soient chargées depuis GitHub
        AfficherMessage("⏳ Chargement des images...");

        while (!imageLoader.imagesChargees)
        {
            yield return null;
        }

        // Ensuite charger le JSON
        StartCoroutine(ChargerJSON());
    }

    void CreerUIChargement()
    {
        canvasChargement =
            new GameObject("CanvasChargement");
        Canvas canvas =
            canvasChargement.AddComponent<Canvas>();
        canvas.renderMode =
            RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder = 1000;
        canvasChargement.AddComponent<CanvasScaler>();
        canvasChargement
            .AddComponent<GraphicRaycaster>();

        GameObject fond = new GameObject("Fond");
        fond.transform.SetParent(
            canvasChargement.transform, false);
        Image img = fond.AddComponent<Image>();
        img.color = new Color(0, 0, 0, 0.95f);
        RectTransform r =
            fond.GetComponent<RectTransform>();
        r.anchorMin = Vector2.zero;
        r.anchorMax = Vector2.one;
        r.sizeDelta = Vector2.zero;

        GameObject textObj =
            new GameObject("TexteChargement");
        textObj.transform.SetParent(
            canvasChargement.transform, false);
        messageChargement =
            textObj.AddComponent<Text>();
        messageChargement.font =
            Resources.GetBuiltinResource<Font>(
                "LegacyRuntime.ttf");
        messageChargement.fontSize = 40;
        messageChargement.color = Color.white;
        messageChargement.alignment =
            TextAnchor.MiddleCenter;
        messageChargement.text =
            "⏳ Chargement...";
        RectTransform rt =
            textObj.GetComponent<RectTransform>();
        rt.anchorMin = Vector2.zero;
        rt.anchorMax = Vector2.one;
        rt.sizeDelta = Vector2.zero;
    }

    IEnumerator ChargerJSON()
    {
        AfficherMessage(
            "⏳ Connexion à GitHub...");
        Debug.Log("📥 Téléchargement : "
            + jsonURL);

        UnityWebRequest request =
            UnityWebRequest.Get(jsonURL);
        yield return request.SendWebRequest();

        if (request.result ==
            UnityWebRequest.Result.Success)
        {
            string json =
                request.downloadHandler.text;
            Debug.Log("✅ JSON reçu : " + json);

            livre = JsonUtility.FromJson
                <LivreData>(json);

            if (livre != null
                && livre.pages != null)
            {
                Debug.Log("✅ "
                    + livre.pages.Count
                    + " pages chargées !");

                AfficherMessage("");
                canvasChargement
                    .SetActive(false);

                estCharge = true;

                detector.OnCloudCharge(livre);
            }
            else
            {
                AfficherMessage(
                    "❌ JSON invalide !");
                Debug.LogError(
                    "❌ JSON invalide !");
            }
        }
        else
        {
            AfficherMessage(
                "❌ Erreur connexion !\n"
                + request.error);
            Debug.LogError(
                "❌ Erreur : " + request.error);
        }
    }

    void AfficherMessage(string msg)
    {
        if (messageChargement != null)
            messageChargement.text = msg;
    }
}
/*using System.Collections;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;
using System.Collections.Generic;

[System.Serializable]
public class ItemData
{
    public string nom;
    public float x, y, z;
}

[System.Serializable]
public class PageData
{
    public string id;
    public string nom;
    public string feuille;
    public List<ItemData> items;
}

[System.Serializable]
public class LivreData
{
    public List<PageData> pages;
}

public class CloudLoader : MonoBehaviour
{
    [Header("URL GitHub Pages")]
    public string jsonURL =
        "https://TON_USERNAME.github.io/ar-livre-assets/livre.json";

    // Livre chargé depuis GitHub
    public LivreData livre
    { get; private set; }

    public bool estCharge
    { get; private set; } = false;

    // Référence au detector
    private AnimalDetector detector;

    // UI chargement
    private GameObject canvasChargement;
    private Text messageChargement;

    void Start()
    {
        detector = GetComponent<AnimalDetector>();
        CreerUIChargement();
        StartCoroutine(ChargerJSON());
    }

    void CreerUIChargement()
    {
        // Canvas qui couvre tout l'écran
        canvasChargement =
            new GameObject("CanvasChargement");
        Canvas canvas =
            canvasChargement.AddComponent<Canvas>();
        canvas.renderMode =
            RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder = 1000;
        canvasChargement.AddComponent<CanvasScaler>();
        canvasChargement
            .AddComponent<GraphicRaycaster>();

        // Fond noir
        GameObject fond = new GameObject("Fond");
        fond.transform.SetParent(
            canvasChargement.transform, false);
        Image img = fond.AddComponent<Image>();
        img.color = new Color(0, 0, 0, 0.95f);
        RectTransform r =
            fond.GetComponent<RectTransform>();
        r.anchorMin = Vector2.zero;
        r.anchorMax = Vector2.one;
        r.sizeDelta = Vector2.zero;

        // Message chargement
        GameObject textObj =
            new GameObject("TexteChargement");
        textObj.transform.SetParent(
            canvasChargement.transform, false);
        messageChargement =
            textObj.AddComponent<Text>();
        messageChargement.font =
            Resources.GetBuiltinResource<Font>(
                "LegacyRuntime.ttf");
        messageChargement.fontSize = 40;
        messageChargement.color = Color.white;
        messageChargement.alignment =
            TextAnchor.MiddleCenter;
        messageChargement.text =
            "⏳ Chargement...";
        RectTransform rt =
            textObj.GetComponent<RectTransform>();
        rt.anchorMin = Vector2.zero;
        rt.anchorMax = Vector2.one;
        rt.sizeDelta = Vector2.zero;
    }

    IEnumerator ChargerJSON()
    {
        AfficherMessage(
            "⏳ Connexion à GitHub...");
        Debug.Log("📥 Téléchargement : "
            + jsonURL);

        UnityWebRequest request =
            UnityWebRequest.Get(jsonURL);
        yield return request.SendWebRequest();

        if (request.result ==
            UnityWebRequest.Result.Success)
        {
            string json =
                request.downloadHandler.text;
            Debug.Log("✅ JSON reçu : " + json);

            livre = JsonUtility.FromJson
                <LivreData>(json);

            if (livre != null
                && livre.pages != null)
            {
                Debug.Log("✅ "
                    + livre.pages.Count
                    + " pages chargées !");

                // Cache l'écran de chargement
                AfficherMessage("");
                canvasChargement
                    .SetActive(false);

                estCharge = true;

                // Notifie le detector
                detector.OnCloudCharge(livre);
            }
            else
            {
                AfficherMessage(
                    "❌ JSON invalide !");
                Debug.LogError(
                    "❌ JSON invalide !");
            }
        }
        else
        {
            AfficherMessage(
                "❌ Erreur connexion !\n"
                + request.error);
            Debug.LogError(
                "❌ Erreur : " + request.error);
        }
    }

    void AfficherMessage(string msg)
    {
        if (messageChargement != null)
            messageChargement.text = msg;
    }
}*/