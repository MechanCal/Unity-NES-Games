using UnityEngine;
 using System.Collections;
 
 public class Flashlight : MonoBehaviour {
 
     public Light light;    //assign gameobject with light component attached
 
     void Update () {
         if (Input.GetMouseButtonDown (0)) {      //Left mouse button
             light.enabled = !light.enabled;      //changes light on/off
         }
     }
 }