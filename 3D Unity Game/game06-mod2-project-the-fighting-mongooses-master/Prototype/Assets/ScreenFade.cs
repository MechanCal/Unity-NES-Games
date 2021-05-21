using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;




public class ScreenFade : MonoBehaviour
{
    //UnityEngine.AI.NavMeshAgent _nma;
	Transform _target;
    float radius = 150;
    public GameObject Fade;
    Image BlackFade;

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
            //BlackFade.GetComponent<ScreenFade>();
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
            //Debug.Log("within radius");
        }
    }
}
