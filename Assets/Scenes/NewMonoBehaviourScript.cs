using UnityEngine;

public class CubeMaterialTest : MonoBehaviour
{
    [SerializeField] private float cubeSize = 0.3f;
    [SerializeField] private float spacing  = 0.4f;

    private readonly string[] cubeNames = { "fox", "hedgehog", "squirrel" };

    void Start()
    {
        for (int i = 0; i < cubeNames.Length; i++)
        {
            Vector3 position = new Vector3(i * (cubeSize + spacing), 0f, 0f);
            CreateCube(cubeNames[i], position);
        }
    }

    void CreateCube(string cubeName, Vector3 position)
    {
        GameObject cube = GameObject.CreatePrimitive(PrimitiveType.Cube);
        cube.name = cubeName;
        cube.transform.position   = position;
        cube.transform.localScale = Vector3.one * cubeSize;

        // Chargement de la texture depuis Assets/Resources/
        Texture2D texture = Resources.Load<Texture2D>(cubeName);
        if (texture == null)
        {
            Debug.LogError("❌ Texture introuvable dans Resources/ pour : " + cubeName);
            return;
        }

        // Même shader que le material qui marche manuellement
        Shader shader = Shader.Find("Universal Render Pipeline/Lit");
        if (shader == null)
        {
            Debug.LogError("❌ Shader URP/Lit introuvable !");
            return;
        }

        // Création du material exactement comme dans l'inspecteur
        Material mat = new Material(shader);
        mat.SetTexture("_BaseMap", texture); // Base Map = _BaseMap en URP/Lit

        cube.GetComponent<MeshRenderer>().material = mat;
        Debug.Log("✅ Material URP/Lit + texture appliqués sur : " + cubeName);
    }
}