using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

public class AnimalDetector : MonoBehaviour
{
    [Header("Distance max pour valider (mètres)")]
    public float distanceMax = 0.05f;

    private ARTrackedImageManager trackedImageManager;

    private ARTrackedImage feuilleDetectee = null;
    private LivreData livre = null;
    private bool cloudCharge = false;

    private string nomFeuille = "";

    public Dictionary<string, Vector3> positionsCorrectes =
        new Dictionary<string, Vector3>();

    public Dictionary<string, ARTrackedImage> imagesDetectees =
        new Dictionary<string, ARTrackedImage>();

    private HashSet<string> animauxValides = new HashSet<string>();
    public HashSet<string> AnimauxValides => animauxValides;

    private Dictionary<string, Text> etiquettes =
        new Dictionary<string, Text>();
    private Text messageHaut;

    void Start()
    {
        CreerUI();
        AfficherMessageHaut("⏳ Chargement...");
    }

    public void OnCloudCharge(LivreData livreCharge)
    {
        livre = livreCharge;
        cloudCharge = true;
        AfficherMessageHaut("📱 Scanne la feuille !");
    }

    // ← Utilisé par TapOnAnimal pour ignorer la feuille automatiquement
    public bool EstUneFeuille(string nom)
    {
        if (livre == null) return false;
        foreach (PageData page in livre.pages)
            if (page.feuille == nom) return true;
        return false;
    }

    void OnEnable()
    {
        trackedImageManager = GetComponent<ARTrackedImageManager>();
        trackedImageManager.trackedImagesChanged += OnImagesChanged;
    }

    void OnDisable()
    {
        trackedImageManager.trackedImagesChanged -= OnImagesChanged;
    }

    void OnImagesChanged(ARTrackedImagesChangedEventArgs args)
    {
        if (!cloudCharge) return;

        foreach (ARTrackedImage image in args.added)
            TraiterImage(image);

        foreach (ARTrackedImage image in args.updated)
            if (image.trackingState == TrackingState.Tracking)
                TraiterImage(image);
    }

    void TraiterImage(ARTrackedImage image)
    {
        string nomImage = image.referenceImage.name;
        PageData page = TrouverPage(nomImage);

        if (page != null)
        {
            // C'est la feuille
            nomFeuille = nomImage;
            feuilleDetectee = image;
            AfficherMessageHaut("✅ Feuille détectée !");
            PositionnerZones(image, page);
            MettreAJourEtiquettes(page);

            foreach (var item in page.items)
            {
                string animal = item.nom;
                if (!imagesDetectees.ContainsKey(animal))
                    imagesDetectees[animal] = null;
            }
        }
        else
        {
            // C'est un animal
            string nomBase = nomImage;

            if (imagesDetectees.ContainsKey(nomBase))
            {
                imagesDetectees[nomBase] = image;
                Debug.Log("🐾 Animal détecté : " + nomBase);
            }
            else
            {
                Debug.Log("⚠️ Animal inconnu ou feuille pas encore détectée : "
                    + nomBase);
            }
        }
    }

    PageData TrouverPage(string nomFeuille)
    {
        if (livre == null) return null;
        foreach (PageData page in livre.pages)
            if (page.feuille == nomFeuille)
                return page;
        return null;
    }

    void PositionnerZones(ARTrackedImage feuille, PageData page)
    {
        positionsCorrectes.Clear();
        foreach (ItemData item in page.items)
        {
            Vector3 offset = new Vector3(item.x, item.y, item.z);
            Vector3 posCorrecte = feuille.transform.position
                + feuille.transform.TransformVector(offset);
            positionsCorrectes[item.nom] = posCorrecte;
            Debug.Log("📍 Position correcte " + item.nom + " : " + posCorrecte);
        }
    }

    void Update()
    {
        if (feuilleDetectee != null)
        {
            VerifierTousLesAnimaux();
        }
    }

    void VerifierTousLesAnimaux()
    {
        foreach (var animal in positionsCorrectes)
        {
            string nom = animal.Key;

            if (!etiquettes.ContainsKey(nom)) continue;

            if (animauxValides.Contains(nom))
            {
                etiquettes[nom].color = Color.green;
                continue;
            }

            ARTrackedImage img = null;
            if (imagesDetectees.ContainsKey(nom))
                img = imagesDetectees[nom];

            if (img == null)
            {
                etiquettes[nom].color = Color.white;
            }
            else
            {
                float distance = Vector3.Distance(
                    img.transform.position,
                    positionsCorrectes[nom]
                );

                if (distance <= distanceMax)
                {
                    etiquettes[nom].color = Color.green;
                    animauxValides.Add(nom);
                    Debug.Log("✅ Animal validé : " + nom);
                }
                else
                {
                    etiquettes[nom].color = Color.red;
                }
            }
        }
    }

    void MettreAJourEtiquettes(PageData page)
    {
        foreach (var etiq in etiquettes.Values)
            if (etiq != null) Destroy(etiq.gameObject);
        etiquettes.Clear();

        GameObject canvas = GameObject.Find("Canvas");
        if (canvas == null) return;

        int count = page.items.Count;
        for (int i = 0; i < count; i++)
        {
            string nom = page.items[i].nom;
            GameObject textObj = new GameObject("Etiq_" + nom);
            textObj.transform.SetParent(canvas.transform, false);

            Text t = textObj.AddComponent<Text>();
            t.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
            t.fontSize = 26;
            t.color = Color.white;
            t.alignment = TextAnchor.MiddleCenter;
            t.text = nom.ToUpper();

            RectTransform tr = textObj.GetComponent<RectTransform>();
            tr.anchorMin = new Vector2(i * (1f / count), 0);
            tr.anchorMax = new Vector2((i + 1f) * (1f / count), 0.1f);
            tr.sizeDelta = new Vector2(-10, 120);
            tr.anchoredPosition = Vector2.zero;

            etiquettes[nom] = t;
        }
    }

    void CreerUI()
    {
        GameObject canvasObj = new GameObject("Canvas");
        Canvas canvas = canvasObj.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        canvasObj.AddComponent<CanvasScaler>();
        canvasObj.AddComponent<GraphicRaycaster>();

        GameObject textHautObj = new GameObject("MessageHaut");
        textHautObj.transform.SetParent(canvasObj.transform, false);
        messageHaut = textHautObj.AddComponent<Text>();
        messageHaut.font =
            Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        messageHaut.fontSize = 32;
        messageHaut.color = Color.yellow;
        messageHaut.alignment = TextAnchor.MiddleCenter;

        RectTransform rt = textHautObj.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0, 1);
        rt.anchorMax = new Vector2(1, 1);
        rt.sizeDelta = new Vector2(0, 120);
    }

    void AfficherMessageHaut(string msg)
    {
        if (messageHaut != null)
            messageHaut.text = msg;
    }
}
/*using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

public class AnimalDetector : MonoBehaviour
{
    [Header("Distance max pour valider (mètres)")]
    public float distanceMax = 0.05f;

    private ARTrackedImageManager trackedImageManager;

    private ARTrackedImage feuilleDetectee = null;
    private LivreData livre = null;
    private bool cloudCharge = false;

    // positions correctes des animaux
    public Dictionary<string, Vector3> positionsCorrectes = new Dictionary<string, Vector3>();

    // images détectées
    public Dictionary<string, ARTrackedImage> imagesDetectees = new Dictionary<string, ARTrackedImage>();

    // animaux validés
    private HashSet<string> animauxValides = new HashSet<string>();
    public HashSet<string> AnimauxValides => animauxValides; // propriété publique

    // labels UI
    private Dictionary<string, Text> etiquettes = new Dictionary<string, Text>();
    private Text messageHaut;

    void Start()
    {
        CreerUI();
        AfficherMessageHaut("⏳ Chargement...");
    }

    public void OnCloudCharge(LivreData livreCharge)
    {
        livre = livreCharge;
        cloudCharge = true;
        AfficherMessageHaut("📱 Scanne la feuille !");
    }

    void OnEnable()
    {
        trackedImageManager = GetComponent<ARTrackedImageManager>();
        trackedImageManager.trackedImagesChanged += OnImagesChanged;
    }

    void OnDisable()
    {
        trackedImageManager.trackedImagesChanged -= OnImagesChanged;
    }

    void OnImagesChanged(ARTrackedImagesChangedEventArgs args)
    {
        if (!cloudCharge) return;

        foreach (ARTrackedImage image in args.added)
            TraiterImage(image);

        foreach (ARTrackedImage image in args.updated)
            if (image.trackingState == TrackingState.Tracking)
                TraiterImage(image);
    }

    void TraiterImage(ARTrackedImage image)
    {
        string nomImage = image.referenceImage.name;

        PageData page = TrouverPage(nomImage);

        if (page != null)
        {
            feuilleDetectee = image;
            AfficherMessageHaut("✅ Feuille détectée !");
            PositionnerZones(image, page);
            MettreAJourEtiquettes(page);

            foreach (var item in page.items)
            {
                string animal = item.nom;
                if (!imagesDetectees.ContainsKey(animal))
                    imagesDetectees[animal] = null;
            }
        }
        else
        {
            string nomBase = nomImage.Replace("_img", "");
            imagesDetectees[nomBase] = image;
        }
    }

    PageData TrouverPage(string nomFeuille)
    {
        if (livre == null) return null;
        foreach (PageData page in livre.pages)
            if (page.feuille == nomFeuille)
                return page;
        return null;
    }

    void PositionnerZones(ARTrackedImage feuille, PageData page)
    {
        positionsCorrectes.Clear();
        foreach (ItemData item in page.items)
        {
            Vector3 offset = new Vector3(item.x, item.y, item.z);
            Vector3 posCorrecte = feuille.transform.position + feuille.transform.TransformVector(offset);
            positionsCorrectes[item.nom] = posCorrecte;
        }
    }

    void Update()
    {
        if (feuilleDetectee != null)
        {
            VerifierTousLesAnimaux();
        }
    }

    void VerifierTousLesAnimaux()
    {
        foreach (var animal in positionsCorrectes)
        {
            string nom = animal.Key;

            if (!etiquettes.ContainsKey(nom)) continue;

            // si déjà validé -> rester vert
            if (animauxValides.Contains(nom))
            {
                etiquettes[nom].color = Color.green;
                continue;
            }

            ARTrackedImage img = null;
            if (imagesDetectees.ContainsKey(nom))
                img = imagesDetectees[nom];

            if (img == null)
            {
                etiquettes[nom].color = Color.white;
            }
            else
            {
                float distance = Vector3.Distance(img.transform.position, positionsCorrectes[nom]);
                if (distance <= distanceMax)
                {
                    etiquettes[nom].color = Color.green;
                    animauxValides.Add(nom); // verrouiller l’animal
                }
                else
                {
                    etiquettes[nom].color = Color.red;
                }
            }
        }
    }

    void MettreAJourEtiquettes(PageData page)
    {
        foreach (var etiq in etiquettes.Values)
            if (etiq != null) Destroy(etiq.gameObject);

        etiquettes.Clear();
        GameObject canvas = GameObject.Find("Canvas");
        if (canvas == null) return;

        int count = page.items.Count;
        for (int i = 0; i < count; i++)
        {
            string nom = page.items[i].nom;
            GameObject textObj = new GameObject("Etiq_" + nom);
            textObj.transform.SetParent(canvas.transform, false);

            Text t = textObj.AddComponent<Text>();
            t.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
            t.fontSize = 26;
            t.color = Color.white;
            t.alignment = TextAnchor.MiddleCenter;
            t.text = nom.ToUpper();

            RectTransform tr = textObj.GetComponent<RectTransform>();
            tr.anchorMin = new Vector2(i * (1f / count), 0);
            tr.anchorMax = new Vector2((i + 1f) * (1f / count), 0.1f);
            tr.sizeDelta = new Vector2(-10, 120);
            tr.anchoredPosition = Vector2.zero;

            etiquettes[nom] = t;
        }
    }

    void CreerUI()
    {
        GameObject canvasObj = new GameObject("Canvas");
        Canvas canvas = canvasObj.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        canvasObj.AddComponent<CanvasScaler>();
        canvasObj.AddComponent<GraphicRaycaster>();

        GameObject textHautObj = new GameObject("MessageHaut");
        textHautObj.transform.SetParent(canvasObj.transform, false);
        messageHaut = textHautObj.AddComponent<Text>();
        messageHaut.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        messageHaut.fontSize = 32;
        messageHaut.color = Color.yellow;
        messageHaut.alignment = TextAnchor.MiddleCenter;

        RectTransform rt = textHautObj.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0, 1);
        rt.anchorMax = new Vector2(1, 1);
        rt.sizeDelta = new Vector2(0, 120);
    }

    void AfficherMessageHaut(string msg)
    {
        if (messageHaut != null)
            messageHaut.text = msg;
    }
}
/*using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

public class AnimalDetector : MonoBehaviour
{
    [Header("Distance max pour valider (mètres)")]
    public float distanceMax = 0.05f;

    private ARTrackedImageManager trackedImageManager;

    private ARTrackedImage feuilleDetectee = null;
    private LivreData livre = null;
    private bool cloudCharge = false;

    // Dictionnaires pour positions et images détectées
    public Dictionary<string, Vector3> positionsCorrectes = new Dictionary<string, Vector3>();
    public Dictionary<string, ARTrackedImage> imagesDetectees = new Dictionary<string, ARTrackedImage>();

    // Labels UI
    private Dictionary<string, Text> etiquettes = new Dictionary<string, Text>();

    // UI message en haut
    private Text messageHaut;

    void Start()
    {
        CreerUI();
        AfficherMessageHaut("⏳ Chargement...");
    }

    public void OnCloudCharge(LivreData livreCharge)
    {
        livre = livreCharge;
        cloudCharge = true;
        AfficherMessageHaut("📱 Scanne la feuille !");
    }

    void OnEnable()
    {
        trackedImageManager = GetComponent<ARTrackedImageManager>();
        trackedImageManager.trackedImagesChanged += OnImagesChanged;
    }

    void OnDisable()
    {
        trackedImageManager.trackedImagesChanged -= OnImagesChanged;
    }

    void OnImagesChanged(ARTrackedImagesChangedEventArgs args)
    {
        if (!cloudCharge) return;

        foreach (ARTrackedImage image in args.added)
            TraiterImage(image);

        foreach (ARTrackedImage image in args.updated)
            if (image.trackingState == TrackingState.Tracking)
                TraiterImage(image);
    }

    void TraiterImage(ARTrackedImage image)
    {
        string nomImage = image.referenceImage.name;

        PageData page = TrouverPage(nomImage);
        if (page != null)
        {
            feuilleDetectee = image;
            AfficherMessageHaut("✅ Feuille détectée !");
            PositionnerZones(image, page);
            MettreAJourEtiquettes(page);

            // Ajouter toutes les images de la page au dictionnaire
            foreach (var item in page.items)
            {
                string animal = item.nom;
                if (!imagesDetectees.ContainsKey(animal))
                    imagesDetectees[animal] = null; // image pas encore détectée
            }
        }
        else
        {
            // Animal détecté
            string nomBase = nomImage.Replace("_img", "");
            imagesDetectees[nomBase] = image;
        }
    }

    PageData TrouverPage(string nomFeuille)
    {
        if (livre == null) return null;
        foreach (PageData page in livre.pages)
            if (page.feuille == nomFeuille)
                return page;
        return null;
    }

    void PositionnerZones(ARTrackedImage feuille, PageData page)
    {
        positionsCorrectes.Clear();
        foreach (ItemData item in page.items)
        {
            Vector3 offset = new Vector3(item.x, item.y, item.z);
            Vector3 posCorrecte = feuille.transform.position + feuille.transform.TransformVector(offset);
            positionsCorrectes[item.nom] = posCorrecte;
        }
    }

    void Update()
    {
        if (feuilleDetectee != null)
        {
            VerifierTousLesAnimaux();
            DetecterClicsAnimaux();
        }
    }

    void VerifierTousLesAnimaux()
    {
        foreach (var animal in positionsCorrectes)
        {
            string nomBase = animal.Key;
            Vector3 posCorrecte = animal.Value;

            ARTrackedImage img = null;
            if (imagesDetectees.ContainsKey(nomBase))
                img = imagesDetectees[nomBase];

            if (!etiquettes.ContainsKey(nomBase)) continue;

            if (img == null)
                etiquettes[nomBase].color = Color.white;
            else
            {
                float distance = Vector3.Distance(img.transform.position, posCorrecte);
                etiquettes[nomBase].color = (distance <= distanceMax) ? Color.green : Color.red;
            }
        }
    }

    void DetecterClicsAnimaux()
    {
        if (Input.touchCount > 0)
        {
            Touch touch = Input.GetTouch(0);
            if (touch.phase == TouchPhase.Began)
            {
                Vector2 touchPos = touch.position;

                foreach (var kv in imagesDetectees)
                {
                    string nom = kv.Key;
                    ARTrackedImage img = kv.Value;

                    if (img == null) continue;

                    float distance = Vector3.Distance(img.transform.position, positionsCorrectes[nom]);
                    if (distance > distanceMax) continue; // uniquement animaux verts

                    // Calcul de la distance écran → image
                    Vector3 screenPos = Camera.main.WorldToScreenPoint(img.transform.position);
                    float pixelDist = Vector2.Distance(touchPos, new Vector2(screenPos.x, screenPos.y));

                    if (pixelDist < 100f) // tolérance en pixels
                    {
                        AfficherTexteAnimal(nom);
                        break;
                    }
                }
            }
        }
    }

    void AfficherTexteAnimal(string nomAnimal)
    {
        GameObject canvasObj = GameObject.Find("Canvas");
        if (canvasObj == null) return;

        GameObject textObj = new GameObject("TexteAnimal");
        textObj.transform.SetParent(canvasObj.transform, false);

        Text t = textObj.AddComponent<Text>();
        t.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        t.fontSize = 36;
        t.color = Color.cyan;
        t.alignment = TextAnchor.MiddleCenter;

        string texte = nomAnimal switch
        {
            "fox_img" => "Hello, I'm the fox!",
            "squirrel_img" => "Hello, I'm the squirrel!",
            _ => "Hello, I'm an animal!"
        };
        t.text = texte;

        RectTransform rt = textObj.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.1f, 0.4f);
        rt.anchorMax = new Vector2(0.9f, 0.6f);
        rt.pivot = new Vector2(0.5f, 0.5f);
        rt.anchoredPosition = Vector2.zero;

        Destroy(textObj, 2f);
    }

    void MettreAJourEtiquettes(PageData page)
    {
        foreach (var etiq in etiquettes.Values)
            if (etiq != null) Destroy(etiq.gameObject);
        etiquettes.Clear();

        GameObject canvas = GameObject.Find("Canvas");
        if (canvas == null) return;

        int count = page.items.Count;
        for (int i = 0; i < count; i++)
        {
            string nom = page.items[i].nom;
            GameObject textObj = new GameObject("Etiq_" + nom);
            textObj.transform.SetParent(canvas.transform, false);
            Text t = textObj.AddComponent<Text>();
            t.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
            t.fontSize = 26;
            t.color = Color.white;
            t.alignment = TextAnchor.MiddleCenter;
            t.text = nom.ToUpper();

            RectTransform tr = textObj.GetComponent<RectTransform>();
            tr.anchorMin = new Vector2(i * (1f / count), 0);
            tr.anchorMax = new Vector2((i + 1f) * (1f / count), 0.1f);
            tr.pivot = new Vector2(0.5f, 0);
            tr.sizeDelta = new Vector2(-10, 120);
            tr.anchoredPosition = Vector2.zero;

            etiquettes[nom] = t;
        }
    }

    void CreerUI()
    {
        GameObject canvasObj = new GameObject("Canvas");
        Canvas canvas = canvasObj.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder = 999;
        canvasObj.AddComponent<CanvasScaler>();
        canvasObj.AddComponent<GraphicRaycaster>();

        // Message en haut
        GameObject textHautObj = new GameObject("MessageHaut");
        textHautObj.transform.SetParent(canvasObj.transform, false);
        messageHaut = textHautObj.AddComponent<Text>();
        messageHaut.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        messageHaut.fontSize = 32;
        messageHaut.color = Color.yellow;
        messageHaut.alignment = TextAnchor.MiddleCenter;

        RectTransform rtHaut = textHautObj.GetComponent<RectTransform>();
        rtHaut.anchorMin = new Vector2(0, 1);
        rtHaut.anchorMax = new Vector2(1, 1);
        rtHaut.pivot = new Vector2(0.5f, 1);
        rtHaut.sizeDelta = new Vector2(0, 120);
        rtHaut.anchoredPosition = Vector2.zero;
    }

    void AfficherMessageHaut(string msg)
    {
        if (messageHaut != null) messageHaut.text = msg;
    }
}
/*using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using UnityEngine.UI;

public class AnimalDetector : MonoBehaviour
{
    [Header("Distance max pour valider (mètres)")]
    public float distanceMax = 0.05f;

    private ARTrackedImageManager trackedImageManager;

    private ARTrackedImage feuilleDetectee = null;
    private LivreData livre = null;
    private bool cloudCharge = false;

    private Dictionary<string, Vector3> positionsCorrectes = new Dictionary<string, Vector3>();

    private Dictionary<string, Text> etiquettes = new Dictionary<string, Text>();
    private Dictionary<string, ARTrackedImage> imagesDetectees = new Dictionary<string, ARTrackedImage>();

    // UI
    private Text messageHaut;      // message général en haut

    void Start()
    {
        CreerUI();
        AfficherMessageHaut("⏳ Chargement...");
    }

    public void OnCloudCharge(LivreData livreCharge)
    {
        livre = livreCharge;
        cloudCharge = true;
        AfficherMessageHaut("📱 Scanne la feuille !");
    }

    void OnEnable()
    {
        trackedImageManager = GetComponent<ARTrackedImageManager>();
        trackedImageManager.trackedImagesChanged += OnImagesChanged;
    }

    void OnDisable()
    {
        trackedImageManager.trackedImagesChanged -= OnImagesChanged;
    }

    void OnImagesChanged(ARTrackedImagesChangedEventArgs args)
    {
        if (!cloudCharge) return;

        foreach (ARTrackedImage image in args.added)
            TraiterImage(image);

        foreach (ARTrackedImage image in args.updated)
            if (image.trackingState == TrackingState.Tracking)
                TraiterImage(image);
    }

    void TraiterImage(ARTrackedImage image)
    {
        string nomImage = image.referenceImage.name;

        // Vérifie si c'est une feuille
        PageData page = TrouverPage(nomImage);

        if (page != null)
        {
            // Feuille détectée
            feuilleDetectee = image;
            AfficherMessageHaut("✅ Feuille détectée !");
            PositionnerZones(image, page);
            MettreAJourEtiquettes(page); // crée tous les labels en blanc
        }
        else
        {
            // Animal détecté
            if (!imagesDetectees.ContainsKey(nomImage))
                imagesDetectees.Add(nomImage, image);
            else
                imagesDetectees[nomImage] = image;
        }
    }

    PageData TrouverPage(string nomFeuille)
    {
        if (livre == null) return null;
        foreach (PageData page in livre.pages)
            if (page.feuille == nomFeuille)
                return page;
        return null;
    }

    void PositionnerZones(ARTrackedImage feuille, PageData page)
    {
        positionsCorrectes.Clear();
        foreach (ItemData item in page.items)
        {
            Vector3 offset = new Vector3(item.x, item.y, item.z);
            Vector3 posCorrecte = feuille.transform.position + feuille.transform.TransformVector(offset);
            positionsCorrectes[item.nom] = posCorrecte;
        }
    }

    void Update()
    {
        if (feuilleDetectee != null)
        {
            VerifierTousLesAnimaux();
        }
    }

    void VerifierTousLesAnimaux()
    {
        foreach (var animal in positionsCorrectes)
        {
            string nomBase = animal.Key;
            Vector3 posCorrecte = animal.Value;

            // Cherche l'image détectée correspondante
            ARTrackedImage img = null;
            if (img.GetComponent<BoxCollider>() == null)
            {
                img.gameObject.AddComponent<BoxCollider>();
            }
            foreach (var imgDetectee in imagesDetectees.Values)
            {
                string nom = imgDetectee.referenceImage.name.Replace("_img", "");
                if (nom == nomBase)
                {
                    img = imgDetectee;
                    break;
                }
            }

            if (!etiquettes.ContainsKey(nomBase)) continue;

            if (img == null)
            {
                // Animal non détecté → reste blanc
                etiquettes[nomBase].color = Color.white;
            }
            else
            {
                // Vérifie distance
                float distance = Vector3.Distance(img.transform.position, posCorrecte);
                if (distance <= distanceMax)
                {
                    etiquettes[nomBase].color = Color.green;
                }
                else
                {
                    etiquettes[nomBase].color = Color.red;
                }
            }
        }
    }

    void MettreAJourEtiquettes(PageData page)
    {
        foreach (var etiq in etiquettes.Values)
            if (etiq != null) Destroy(etiq.gameObject);
        etiquettes.Clear();

        GameObject canvas = GameObject.Find("Canvas");
        if (canvas == null) return;

        int count = page.items.Count;
        for (int i = 0; i < count; i++)
        {
            string nom = page.items[i].nom;
            GameObject textObj = new GameObject("Etiq_" + nom);
            textObj.transform.SetParent(canvas.transform, false);
            Text t = textObj.AddComponent<Text>();
            t.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
            t.fontSize = 26;
            t.color = Color.white; // blanc par défaut
            t.alignment = TextAnchor.MiddleCenter;
            t.text = nom.ToUpper();

            RectTransform tr = textObj.GetComponent<RectTransform>();
            tr.anchorMin = new Vector2(i * (1f / count), 0);
            tr.anchorMax = new Vector2((i + 1f) * (1f / count), 0.1f);
            tr.pivot = new Vector2(0.5f, 0);
            tr.sizeDelta = new Vector2(-10, 120);
            tr.anchoredPosition = Vector2.zero;

            etiquettes[nom] = t;
        }
    }

    void CreerUI()
    {
        GameObject canvasObj = new GameObject("Canvas");
        Canvas canvas = canvasObj.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder = 999;
        CanvasScaler scaler = canvasObj.AddComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1080, 1920);
        canvasObj.AddComponent<GraphicRaycaster>();

        // Message en haut (général)
        GameObject textHautObj = new GameObject("MessageHaut");
        textHautObj.transform.SetParent(canvasObj.transform, false);
        messageHaut = textHautObj.AddComponent<Text>();
        messageHaut.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        messageHaut.fontSize = 32;
        messageHaut.color = Color.yellow;
        messageHaut.alignment = TextAnchor.MiddleCenter;
        RectTransform rtHaut = textHautObj.GetComponent<RectTransform>();
        rtHaut.anchorMin = new Vector2(0, 1);
        rtHaut.anchorMax = new Vector2(1, 1);
        rtHaut.pivot = new Vector2(0.5f, 1);
        rtHaut.sizeDelta = new Vector2(0, 120);
        rtHaut.anchoredPosition = Vector2.zero;
    }

    void AfficherMessageHaut(string msg)
    {
        if (messageHaut != null) messageHaut.text = msg;
    }
}*/