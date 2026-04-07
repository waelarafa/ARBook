// TapDetector1.cs
using UnityEngine;
using UnityEngine.InputSystem;
using System.Collections;

public class TapDetector1 : MonoBehaviour
{
    public Camera cam;
    public ImageCubeDataLibrary.ImageDataEntry data;
    public ImageCubeDataLibrary.TapTargetType targetType;
    public bool isValidated = false;

    private bool isAnimating = false;
    private AudioSource audioSource;

    void Start()
    {
        audioSource = gameObject.AddComponent<AudioSource>();
        audioSource.playOnAwake = false;
    }

    void Update()
    {
#if UNITY_EDITOR
        if (Mouse.current != null && Mouse.current.leftButton.wasPressedThisFrame)
            DetectTap(Mouse.current.position.ReadValue());
#else
        if (Touchscreen.current != null && Touchscreen.current.primaryTouch.press.wasPressedThisFrame)
            DetectTap(Touchscreen.current.primaryTouch.position.ReadValue());
#endif
    }

    void DetectTap(Vector2 screenPosition)
    {
        Ray ray = cam.ScreenPointToRay(screenPosition);
        if (Physics.Raycast(ray, out RaycastHit hit))
        {
            if (hit.collider.gameObject != gameObject) return;

            // ── Vérification validation ───────────────────
            if (targetType == ImageCubeDataLibrary.TapTargetType.Image && !isValidated)
            {
                Debug.Log("🔒 Tap ignoré : image pas encore validée : " + gameObject.name);
                return;
            }

            Debug.Log("✅ Tap sur : " + gameObject.name + " | Type : " + targetType);

            if (data == null)
            {
                Debug.LogWarning("⚠️ Aucun data assigné sur : " + gameObject.name);
                return;
            }

            // ── Actions communes ──────────────────────────
            if (data.doScale && !isAnimating)
                StartCoroutine(ScaleEffect());

            // ── Actions selon le type ─────────────────────
            switch (targetType)
            {
                case ImageCubeDataLibrary.TapTargetType.Image:
                    HandleImageTap(hit);
                    break;

                case ImageCubeDataLibrary.TapTargetType.Prefab:
                    HandlePrefabTap();
                    break;
            }
        }
    }

    void HandleImageTap(RaycastHit hit)
    {
        if (data.doSpawn && data.prefabToSpawn != null)
        {
            // 🎯 Position EXACTE du tap (sans offset)
            Vector3 spawnPos = hit.point;

            // 🔄 Rotation alignée avec la surface
            Quaternion spawnRot = Quaternion.FromToRotation(Vector3.up, hit.normal);

            // 🚀 Spawn
            GameObject spawned = Instantiate(data.prefabToSpawn, spawnPos, spawnRot);

            // 🧱 Stabiliser (empêcher chute / mouvement)
            Rigidbody rb = spawned.GetComponent<Rigidbody>();
            if (rb != null)
            {
                rb.isKinematic = true;
                rb.useGravity = false;
            }

            // 🔗 Attacher à la surface (important en AR)
            spawned.transform.SetParent(hit.collider.transform);

            // 👆 Ajouter TapDetector sur le prefab
            TapDetector1 tap = spawned.AddComponent<TapDetector1>();
            tap.cam = cam;
            tap.data = data;
            tap.targetType = ImageCubeDataLibrary.TapTargetType.Prefab;
            tap.isValidated = true;

            // 📦 Ajouter collider si absent
            if (spawned.GetComponent<Collider>() == null)
                spawned.AddComponent<BoxCollider>();

            // 👀 Option : regarder la caméra proprement
            if (data.lookAtCamera)
            {
                Vector3 direction = cam.transform.position - spawned.transform.position;
                direction.y = 0;
                if (direction != Vector3.zero)
                    spawned.transform.rotation = Quaternion.LookRotation(-direction);
            }

            Debug.Log("📦 Prefab spawné (stable) : " + spawned.name);
        }
    }

    void HandlePrefabTap()
    {
        if (data.doPlaySound && data.soundToPlay != null)
        {
            audioSource.clip = data.soundToPlay;
            audioSource.Play();
            Debug.Log("🔊 Son joué : " + data.soundToPlay.name);
        }

        if (data.doDestroyOnTap)
        {
            float delay = (data.doPlaySound && data.soundToPlay != null)
                ? data.soundToPlay.length
                : 0f;
            Debug.Log("💥 Prefab détruit au tap");
            Destroy(gameObject, delay);
        }
    }

    IEnumerator ScaleEffect()
    {
        isAnimating = true;
        Vector3 original = transform.localScale;
        Vector3 target = original * data.scaleMultiplier;
        float time = 0f;

        while (time < data.scaleDuration)
        {
            transform.localScale = Vector3.Lerp(original, target, time / data.scaleDuration);
            time += Time.deltaTime;
            yield return null;
        }
        transform.localScale = target;
        time = 0f;

        while (time < data.scaleDuration)
        {
            transform.localScale = Vector3.Lerp(target, original, time / data.scaleDuration);
            time += Time.deltaTime;
            yield return null;
        }

        transform.localScale = original;
        isAnimating = false;
    }
}