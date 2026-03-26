using System.Collections;
using UnityEngine;

public class DesktopTester : MonoBehaviour
{
    [Header("Test Settings")]
    public string testBookId = "book_001";
    public string testPageId = "page1";

    void Start()
    {
        Debug.Log("🧪 ===== TEST DESKTOP START =====");
        StartCoroutine(TestFlow());
    }

    IEnumerator TestFlow()
    {
        // ✅ FIX : Attendre d'abord que DataManager.Instance existe
        Debug.Log("⏳ Attente chargement catalogue...");
        yield return new WaitUntil(() => DataManager.Instance != null);

        // ✅ Puis attendre que le catalogue soit chargé
        yield return new WaitUntil(() => DataManager.Instance.GetBookEntry(testBookId) != null);

        // ─── Étape 1 : Vérification catalogue ───
        Debug.Log("🔍 Étape 1 : Vérification catalogue");

        var entry = DataManager.Instance.GetBookEntry(testBookId);

        if (entry == null)
        {
            Debug.LogError("❌ BookEntry introuvable !");
            yield break;
        }

        // ✅ FIX 2 : entry.title n'existe pas → on utilise entry.id
        Debug.Log($"✅ BookEntry trouvé : ID = {entry.id} | JSON = {entry.jsonFile}");

        // ─── Étape 2 : Chargement JSON du livre ───
        Debug.Log("📥 Étape 2 : Chargement JSON...");
        yield return StartCoroutine(DataManager.Instance.LoadBookFromUrl(testBookId));

        var book = DataManager.Instance.GetBookData(testBookId);

        if (book == null)
        {
            Debug.LogError("❌ BookData introuvable !");
            yield break;
        }

        Debug.Log($"✅ Livre chargé : {book.title} ({book.pages.Count} pages)");

        // ─── Étape 3 : Téléchargement Addressables ───
        Debug.Log("📦 Étape 3 : Téléchargement Addressables...");
        yield return StartCoroutine(DataManager.Instance.DownloadBookAssets(entry.addressable_group));
        Debug.Log("✅ Addressables prêts !");

        // ─── Étape 4 : Test GetPageById (O(1) Dictionary lookup) ───
        Debug.Log($"🔎 Étape 4 : Test lookup page '{testPageId}'");

        var page = DataManager.Instance.GetPageById(testBookId, testPageId);

        if (page != null)
        {
            Debug.Log($"✅ Page trouvée : {page.id}");

            if (page.items == null || page.items.Count == 0)
            {
                Debug.LogWarning("⚠️ La page n'a pas d'items");
            }
            else
            {
                foreach (var item in page.items)
                {
                    Debug.Log($"🐾 Item: {item.nom} | Position ({item.x}, {item.y}, {item.z})");
                }
            }
        }
        else
        {
            Debug.LogWarning($"⚠️ Page '{testPageId}' introuvable dans '{testBookId}'");
        }

        Debug.Log("🎉 ===== TEST TERMINÉ AVEC SUCCÈS =====");
    }
}
