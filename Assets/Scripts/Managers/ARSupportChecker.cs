using System.Collections;
using UnityEngine;
using UnityEngine.XR.ARFoundation;

public class ARButtonVisibility : MonoBehaviour
{
    private IEnumerator Start()
    {
        yield return ARSession.CheckAvailability();

        bool arSupported =
            ARSession.state != ARSessionState.Unsupported &&
            ARSession.state != ARSessionState.None;

        gameObject.SetActive(arSupported);
    }
}