using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Keypad : MonoBehaviour
{
    public string password = "1234";
    public string input;
    public string tempInput;
    public bool unlock;
    public bool onTrigger;
    public bool keypadScreen;
    Transform Player;
    float radius = 50;

    //public CameraScript cameraScript;
    void Start()
    {
       // _nma = GetComponent<UnityEngine.AI.NavMeshAgent>();
	   //_target = GameObject.FindWithTag ("Player").transform;
       Player = GameObject.FindWithTag ("Player").transform;
    }


    // Update is called once per frame
    void Update()
    {
        if(input == password)
        {
            unlock = true;
        }

        if(unlock)
        {
            //Give player key or open door
            Debug.Log("Password was correct!");


        }
        if( Vector3.Distance(Player.position, transform.position) < radius)
        {
            onTrigger = true;
        }
        else
        {
           onTrigger = false;
           keypadScreen = false;
           input = "";
        }

        if(onTrigger)
        {
            if(Input.GetKeyDown(KeyCode.Alpha1) || Input.GetKeyDown(KeyCode.Keypad1)) 
            {
                input = input + "1";
            }
            if(Input.GetKeyDown(KeyCode.Alpha2) || Input.GetKeyDown(KeyCode.Keypad2)) 
            {
                input = input + "2";
            }
            if(Input.GetKeyDown(KeyCode.Alpha3) || Input.GetKeyDown(KeyCode.Keypad3)) 
            {
                input = input + "3";
            }
            if(Input.GetKeyDown(KeyCode.Alpha4) || Input.GetKeyDown(KeyCode.Keypad4)) 
            {
                input = input + "4";
            }
            if(Input.GetKeyDown(KeyCode.Alpha5) || Input.GetKeyDown(KeyCode.Keypad5)) 
            {
                input = input + "5";
            }
            if(Input.GetKeyDown(KeyCode.Alpha6) || Input.GetKeyDown(KeyCode.Keypad6)) 
            {
                input = input + "6";
            }
            if(Input.GetKeyDown(KeyCode.Alpha7) || Input.GetKeyDown(KeyCode.Keypad7)) 
            {
                input = input + "7";
            }
            if(Input.GetKeyDown(KeyCode.Alpha8) || Input.GetKeyDown(KeyCode.Keypad8)) 
            {
                input = input + "8";
            }
            if(Input.GetKeyDown(KeyCode.Alpha9) || Input.GetKeyDown(KeyCode.Keypad9)) 
            {
                input = input + "9";
            }
            if(Input.GetKeyDown(KeyCode.Alpha0) || Input.GetKeyDown(KeyCode.Keypad0)) 
            {
                input = input + "0";
            }

            if(input.Length == 5)
            {
                input = "";
            }
        }

    }

    void OnGUI()
    {
        if(!unlock)
        {
            if(onTrigger)
            {
                GUI.Box(new Rect(0, 0, 200, 25), "Press 'E' to access keypad");
 
                if(Input.GetKeyDown(KeyCode.E))
                {
                    keypadScreen = true;
                    onTrigger = false;
                }
            }
 
            if(keypadScreen)
            {
                // Cursor.visible = true;
               // cameraScript.enabled = false;
                // Camera.main.GetComponent<CameraScript>().paused = true;
                GUI.Box(new Rect(0, 0, 320, 455), ""); //Keypad
                GUI.Box(new Rect(5, 5, 310, 25), input); 
 
                GUI.Button(new Rect(5, 35, 100, 100), "1"); 
                GUI.Button(new Rect(110, 35, 100, 100), "2");
                GUI.Button(new Rect(215, 35, 100, 100), "3");
                GUI.Button(new Rect(5, 140, 100, 100), "4");
                GUI.Button(new Rect(110, 140, 100, 100), "5");
                GUI.Button(new Rect(215, 140, 100, 100), "6");
                GUI.Button(new Rect(5, 245, 100, 100), "7");
                GUI.Button(new Rect(110, 245, 100, 100), "8");
                GUI.Button(new Rect(215, 245, 100, 100), "9");
                GUI.Button(new Rect(110, 350, 100, 100), "0");
            }
        }
            //Cursor.visible = false;
           // cameraScript.enabled = true;
           // Camera.main.GetComponent<CameraScript>().paused = false;
    if(unlock)
    {
       GUI.Box(new Rect(100, 100, 500, 100), "A Door has unlocked");
    }


    }
    
}