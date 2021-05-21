using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AN_DoorKey : MonoBehaviour
{
    [Tooltip("True - red key object, false - blue key")]
    public bool isRedKey = true;
    AN_HeroInteractive hero;

    // NearView()
    float distance;
    float angleView;
    Vector3 direction;
    Transform target;
    public float radius = 100.0f;

    private void Start()
    {
        hero = FindObjectOfType<AN_HeroInteractive>(); // key will get up and it will saved in "inventary"
        target = GameObject.FindWithTag("Player").transform;
    }

    void Update()
    {
        if ( NearView() && Input.GetKeyDown(KeyCode.E) )
        {
            if (isRedKey) hero.RedKey = true;
            else hero.BlueKey = true;
            Destroy(gameObject);
        }
    }

    bool NearView() // it is true if you near interactive object
    {
        if (Vector3.Distance(target.position, transform.position) < radius)
            return true; // angleView < 35f && 
        else
            return false;
    }
}
