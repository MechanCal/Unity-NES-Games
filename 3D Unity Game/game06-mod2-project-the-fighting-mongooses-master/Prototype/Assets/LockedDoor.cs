using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class LockedDoor : MonoBehaviour
{
    public Keypad KP;
    public DoubleSlidingDoorController animationScript;
    void Start()
    {
      animationScript = GetComponent<DoubleSlidingDoorController> ();
    }

    void Update()
    {
        if(KP.unlock)
        {
         // Destroy(gameObject);  
           animationScript.enabled = true;     
        }
        
    }
}
