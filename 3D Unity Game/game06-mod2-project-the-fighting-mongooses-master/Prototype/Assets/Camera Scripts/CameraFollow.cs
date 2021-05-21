using UnityEngine;

public class CameraFollow : MonoBehaviour
{
    public Transform PlayerTransform;
    [Range(0.01f, 1.0f)]
    public float smoothFactor = 0.5f;
    public Vector3 _cameraoffset;


    void Start()
    {
        _cameraoffset = transform.position - PlayerTransform.position;



    }

    void LateUpdate()
    {
        Vector3 newPos = PlayerTransform.position + _cameraoffset;

        transform.position =Vector3.Slerp(transform.position, newPos, smoothFactor);


    }



}
