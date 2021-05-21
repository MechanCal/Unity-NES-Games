using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyScript : MonoBehaviour
{
    //UnityEngine.AI.NavMeshAgent _nma;
	Transform _target;
    float radius = 150;

    void Start()
    {
       // _nma = GetComponent<UnityEngine.AI.NavMeshAgent>();
	   //_target = GameObject.FindWithTag ("Player").transform;
       _target = GameObject.FindWithTag ("Player").transform;
    }

    void Update()
    {
        //_nma.SetDestination(_target.position); 
        if( Vector3.Distance(_target.position, transform.position) < radius)
        {
            Destroy(gameObject);         
            Debug.Log("within radius");
        }
    }
}
