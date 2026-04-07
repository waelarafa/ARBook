using System.Collections;
using UnityEngine;

public class DesktopTester : MonoBehaviour
{
    [Header("Test Settings")]
    public string testBookId = "book_001";
    public string testPageId = "page1";
    public string testAnimalName = "fox";

    void Start()
    {
        Debug.Log("🧪 ===== TEST DESKTOP START =====");
        StartCoroutine(TestFlow());
    }

    IEnumerator TestFlow()
    {
        // ── Attendre que DataManager soit prêt ──────────────────────
        Debug.Log("⏳ Attente DataManager...");
        yield return new WaitUntil(() => DataManager.Instance != null);
        yield return new WaitUntil(() => DataManager.Instance.GetBookEntry(testBookId) != null);

        // ─── Étape 1 : Catalogue ────────────────────────────────────
        Debug.Log("═══════════════════════════════════════");
        Debug.Log("🔍 Étape 1 : Vérification catalogue");
        var entry = DataManager.Instance.GetBookEntry(testBookId);
        if (entry == null) { Debug.LogError("❌ BookEntry introuvable !"); yield break; }
        Debug.Log($"✅ BookEntry trouvé : id={entry.id} | jsonFile={entry.jsonFile} | group={entry.addressable_group}");

        // ─── Étape 2 : Chargement JSON ──────────────────────────────
        Debug.Log("═══════════════════════════════════════");
        Debug.Log("📥 Étape 2 : Chargement JSON du livre...");
        yield return StartCoroutine(DataManager.Instance.LoadBookFromUrl(testBookId));
        var book = DataManager.Instance.GetBookData(testBookId);
        if (book == null) { Debug.LogError("❌ BookData introuvable !"); yield break; }
        Debug.Log($"✅ Livre chargé : {book.title} ({book.pages.Count} pages)");

        // ─── Étape 3 : Téléchargement Addressables ──────────────────
        Debug.Log("═══════════════════════════════════════");
        Debug.Log("📦 Étape 3 : Téléchargement Addressables...");
        yield return StartCoroutine(DataManager.Instance.DownloadBookAssets(entry.addressable_group));
        Debug.Log("✅ Addressables téléchargés !");

        // ─── Étape 4 : GetPageById ──────────────────────────────────
        Debug.Log("═══════════════════════════════════════");
        Debug.Log($"🔎 Étape 4 : GetPageById '{testPageId}'");
        var page = DataManager.Instance.GetPageById(testBookId, testPageId);
        if (page != null)
        {
            Debug.Log($"✅ Page trouvée : {page.nom} ({page.items.Count} animaux)");
            foreach (var item in page.items)
                Debug.Log($"   🐾 {item.nom} → ({item.x}, {item.y}, {item.z})");
        }
        else
            Debug.LogWarning($"⚠️ Page '{testPageId}' introuvable");

        // ─── Étape 5 : GetItemData ──────────────────────────────────
        Debug.Log("═══════════════════════════════════════");
        Debug.Log($"🔎 Étape 5 : GetItemData '{testAnimalName}'");
        var item2 = DataManager.Instance.GetItemData(testBookId, testAnimalName);
        if (item2 != null)
            Debug.Log($"✅ GetItemData OK → {item2.nom} ({item2.x}, {item2.y}, {item2.z})");
        else
            Debug.LogError($"❌ GetItemData ÉCHEC — '{testAnimalName}' introuvable");

        // ─── Étape 6 : LoadAssetsForImage + GetPrefab ───────────────
        Debug.Log("═══════════════════════════════════════");
        Debug.Log($"⚡ Étape 6 : LoadAssetsForImage '{testAnimalName}'");
        DataManager.Instance.LoadAssetsForImage(testAnimalName);

        float timeout = 10f;
        float elapsed = 0f;
        while (!DataManager.Instance.IsAssetReady(testAnimalName) && elapsed < timeout)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }

        // ─── Étape 7 : GetPrefab ────────────────────────────────────
        Debug.Log("═══════════════════════════════════════");
        Debug.Log($"🔎 Étape 7 : GetPrefab '{testAnimalName}'");
        var prefab = DataManager.Instance.GetPrefab(testAnimalName);
        if (prefab != null)
            Debug.Log($"✅ GetPrefab OK → {prefab.name}");
        else
            Debug.LogError($"❌ GetPrefab ÉCHEC — vérifie l'address '{testAnimalName}' dans Addressables");

        // ─── Étape 8 : GetImage ─────────────────────────────────────
        Debug.Log("═══════════════════════════════════════");
        Debug.Log($"🔎 Étape 8 : GetImage '{testAnimalName}'");
        var texture = DataManager.Instance.GetImage(testAnimalName);
        if (texture != null)
            Debug.Log($"✅ GetImage OK → {texture.name}");
        else
            Debug.LogWarning($"⚠️ GetImage — pas de texture '{testAnimalName}' (normal si pas encore ajoutée)");

        // ─── Résumé final ───────────────────────────────────────────
        Debug.Log("═══════════════════════════════════════");
        Debug.Log("📊 RÉSUMÉ FINAL :");
        Debug.Log($"   Catalogue     → {(entry != null ? "✅" : "❌")}");
        Debug.Log($"   JSON livre    → {(book != null ? "✅" : "❌")}");
        Debug.Log($"   Addressables  → ✅");
        Debug.Log($"   GetPageById   → {(page != null ? "✅" : "❌")}");
        Debug.Log($"   GetItemData   → {(item2 != null ? "✅" : "❌")}");
        Debug.Log($"   GetPrefab     → {(prefab != null ? "✅" : "❌")}");
        Debug.Log($"   GetImage      → {(texture != null ? "✅" : "⚠️ pas de texture")}");
        Debug.Log("🎉 ===== TEST TERMINÉ =====");
    }
}




/*using System.Collections;
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
}*/
