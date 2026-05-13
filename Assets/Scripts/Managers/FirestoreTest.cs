using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Firebase;
using Firebase.Firestore;

public class FirestoreTest : MonoBehaviour
{
    IEnumerator Start()
    {
        // Attendre 3 secondes que tout soit initialisé
        yield return new WaitForSeconds(3f);

        Debug.Log("[TEST] Tentative d'écriture Firestore...");

        var task = FirebaseApp.CheckAndFixDependenciesAsync();
        yield return new WaitUntil(() => task.IsCompleted);

        if (task.Result != DependencyStatus.Available)
        {
            Debug.LogError("[TEST] ❌ Firebase pas disponible : " + task.Result);
            yield break;
        }

        var db = FirebaseFirestore.DefaultInstance;

        if (db == null)
        {
            Debug.LogError("[TEST] ❌ Firestore DefaultInstance est NULL");
            yield break;
        }

        Debug.Log("[TEST] ✅ Firestore instance OK — écriture...");

        var data = new Dictionary<string, object>
        {
            { "userId", "test_user_123" },
            { "message", "test depuis Unity" },
            { "timestamp", Timestamp.GetCurrentTimestamp() }
        };

        var writeTask = db.Collection("test").AddAsync(data);
        yield return new WaitUntil(() => writeTask.IsCompleted);

        if (writeTask.IsFaulted)
            Debug.LogError("[TEST] ❌ Écriture échouée : " + writeTask.Exception?.InnerException?.Message);
        else
            Debug.Log("[TEST] ✅ Écriture réussie ! Vérifie Firestore Console.");
    }
}