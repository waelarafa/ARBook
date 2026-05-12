using System;
using UnityEngine;
using Firebase;

public class AppManager : MonoBehaviour
{
    private float _sessionStart;

    async void Start()
    {
        try
        {
            var status = await FirebaseApp.CheckAndFixDependenciesAsync();
            if (status == DependencyStatus.Available)
            {
                Debug.Log("[AppManager] ✅ Firebase prêt");
                _sessionStart = Time.realtimeSinceStartup;
                AnalyticsManager.Instance?.LogSessionStarted();
            }
            else
            {
                Debug.LogError("[AppManager] ❌ Firebase : " + status);
            }
        }
        catch (Exception e)
        {
            Debug.LogError("[AppManager] ❌ " + e.Message);
        }
    }

    void OnApplicationQuit()
    {
        AnalyticsManager.Instance?.LogSessionEnded();
    }

    void OnApplicationPause(bool paused)
    {
        if (paused) AnalyticsManager.Instance?.LogSessionEnded();
    }
}