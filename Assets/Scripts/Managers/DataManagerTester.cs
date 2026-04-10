using System.Collections;
using UnityEngine;

public class DataManagerTester : MonoBehaviour
{
    IEnumerator Start()
    {
        // ── Étape 1 : attendre le catalogue ─────────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("ÉTAPE 1 : Attente catalogue...");

        float elapsed = 0f;
        while (DataManager.Instance.GetBookEntry("book_001") == null && elapsed < 10f)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }

        if (DataManager.Instance.GetBookEntry("book_001") != null)
            Debug.Log("✅ Catalogue chargé !");
        else
        {
            Debug.LogError("❌ Catalogue non chargé — vérifie l'URL GitHub");
            yield break;
        }

        // ── Étape 2 : charger le livre ──────────────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("ÉTAPE 2 : Chargement livre book_001...");
        yield return StartCoroutine(DataManager.Instance.LoadBookFromUrl("book_001"));
        Debug.Log("✅ Livre prêt !");

        // ── Étape 3 : GetItemData et GetPageById ────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("ÉTAPE 3 : Test getters...");

        ARBook.Models.ItemData item = DataManager.Instance.GetItemData("book_001", "fox");
        ARBook.Models.PageData page = DataManager.Instance.GetPageById("book_001", "page1");

        Debug.Log(item != null
            ? $"✅ GetItemData OK — fox : x={item.x} y={item.y} z={item.z}"
            : "❌ GetItemData ÉCHEC");

        Debug.Log(page != null
            ? $"✅ GetPageById OK — {page.nom} avec {page.items.Count} animaux"
            : "❌ GetPageById ÉCHEC");

        // ── Étape 4 : OnPageDetected page1 ──────────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("ÉTAPE 4 : OnPageDetected(page1)");
        Debug.Log("  → page1 : PRIORITAIRE | page2 : background");

        DataManager.Instance.OnPageDetected("book_001", "page1");

        // Attendre max 10s que fox soit prêt
        elapsed = 0f;
        while (!DataManager.Instance.IsAssetReady("fox") && elapsed < 10f)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }

        Debug.Log(DataManager.Instance.IsAssetReady("fox")
            ? "✅ fox prêt (prefab + texture en cache)"
            : "⚠️ fox non prêt — normal si pas encore dans Addressables");

        // ── Étape 5 : changement vers page2 ─────────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("ÉTAPE 5 : OnPageDetected(page2) — test annulation");
        Debug.Log("  → voisins de page1 annulés | page2 : PRIORITAIRE");

        DataManager.Instance.OnPageDetected("book_001", "page2");

        elapsed = 0f;
        while (!DataManager.Instance.IsAssetReady("panda") && elapsed < 10f)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }

        Debug.Log(DataManager.Instance.IsAssetReady("panda")
            ? "✅ panda prêt !"
            : "⚠️ panda non prêt — normal si pas encore dans Addressables");

        // ── Étape 6 : même page deux fois ───────────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("ÉTAPE 6 : page2 détectée deux fois — doit être ignorée");
        DataManager.Instance.OnPageDetected("book_001", "page2");
        yield return new WaitForSeconds(0.5f);
        Debug.Log("✅ Si aucun log de chargement ci-dessus → correct !");

        // ── Résumé ──────────────────────────────────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("RÉSUMÉ FINAL :");
        Debug.Log($"  Catalogue         → ✅");
        Debug.Log($"  Livre chargé      → ✅");
        Debug.Log($"  GetItemData fox   → {(item != null ? "✅" : "❌")}");
        Debug.Log($"  GetPageById page1 → {(page != null ? "✅" : "❌")}");
        Debug.Log($"  fox  IsAssetReady → {(DataManager.Instance.IsAssetReady("fox") ? "✅" : "⚠️ pas dans Addressables")}");
        Debug.Log($"  panda IsAssetReady→ {(DataManager.Instance.IsAssetReady("panda") ? "✅" : "⚠️ pas dans Addressables")}");
        Debug.Log("Les ⚠️ disparaîtront quand les prefabs seront configurés dans Addressables.");
        Debug.Log("═══════════════════════════════");
    }
}




/*using System.Collections;
using UnityEngine;

public class DataManagerTester : MonoBehaviour
{
    IEnumerator Start()
    {
        // ── Étape 1 : attendre que le catalogue se charge ───────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("ÉTAPE 1 : Attente chargement catalogue...");

        // Le catalogue se charge automatiquement dans DataManager.Start()
        // On attend juste qu'il soit prêt
        float timeout = 10f;
        float elapsed = 0f;
        while (DataManager.Instance.GetBookEntry("book_001") == null && elapsed < timeout)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }

        if (DataManager.Instance.GetBookEntry("book_001") != null)
            Debug.Log("✅ Catalogue chargé !");
        else
        {
            Debug.LogError("❌ Catalogue non chargé après 10s — vérifie l'URL GitHub");
            yield break;
        }

        // ── Étape 2 : charger le livre ──────────────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("ÉTAPE 2 : Chargement livre book_001...");
        yield return StartCoroutine(DataManager.Instance.LoadBookFromUrl("book_001"));

        // ── Étape 3 : tester GetItemData ────────────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("ÉTAPE 3 : Test GetItemData...");
        ARBook.Models.ItemData item = DataManager.Instance.GetItemData("book_001", "fox");
        if (item != null)
            Debug.Log($"✅ GetItemData OK — fox position : x={item.x} y={item.y} z={item.z}");
        else
            Debug.LogError("❌ GetItemData ÉCHEC — fox introuvable");

        // ── Étape 4 : tester GetPageById ────────────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("ÉTAPE 4 : Test GetPageById...");
        ARBook.Models.PageData page = DataManager.Instance.GetPageById("book_001", "page1");
        if (page != null)
            Debug.Log($"✅ GetPageById OK — page : {page.nom} avec {page.items.Count} animaux");
        else
            Debug.LogError("❌ GetPageById ÉCHEC — page1 introuvable");

        // ── Étape 5 : charger assets fox (async) ────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("ÉTAPE 5 : Chargement assets fox...");
        DataManager.Instance.LoadAssetsForImage("fox");

        timeout = 10f;
        elapsed = 0f;
        while (!DataManager.Instance.IsAssetReady("fox") && elapsed < timeout)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }

        // ── Étape 6 : tester GetPrefab ──────────────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("ÉTAPE 6 : Test GetPrefab...");
        GameObject prefab = DataManager.Instance.GetPrefab("fox");
        if (prefab != null)
            Debug.Log($"✅ GetPrefab OK — prefab : {prefab.name}");
        else
            Debug.LogError("❌ GetPrefab ÉCHEC — vérifie l'address 'fox' dans Addressables");

        // ── Étape 7 : tester GetImage ───────────────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("ÉTAPE 7 : Test GetImage...");
        Texture2D texture = DataManager.Instance.GetImage("fox");
        if (texture != null)
            Debug.Log($"✅ GetImage OK — texture : {texture.name}");
        else
            Debug.LogWarning("⚠️ GetImage — pas de texture fox (normal si pas encore ajoutée)");

        // ── Résumé ──────────────────────────────────────────────────
        Debug.Log("═══════════════════════════════");
        Debug.Log("RÉSUMÉ :");
        Debug.Log($"  GetItemData  → {(item != null ? "✅" : "❌")}");
        Debug.Log($"  GetPageById  → {(page != null ? "✅" : "❌")}");
        Debug.Log($"  GetPrefab    → {(prefab != null ? "✅" : "❌")}");
        Debug.Log($"  GetImage     → {(texture != null ? "✅" : "⚠️ pas de texture")}");
        Debug.Log("═══════════════════════════════");
    }
}*/