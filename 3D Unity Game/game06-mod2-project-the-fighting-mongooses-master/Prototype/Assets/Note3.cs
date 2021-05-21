using UnityEngine;
 using System.Collections;
 
 public class Note3 : MonoBehaviour {
 
    public string input;
    public string tempInput;
    public bool openBox;
    public bool onTrigger;
    public bool keypadScreen;
    Transform Player;
    float radius = 30;



    void Start(){
         Player = GameObject.FindWithTag ("Player").transform;
    }
 




     void Update () {
         if( Vector3.Distance(Player.position, transform.position) < radius)
        {
            onTrigger = true;
        }
    else
        {
           onTrigger = false;
           keypadScreen = false;
        }


     }
 
    void OnGUI()
    {
        if(!openBox)
        {
            if(onTrigger)
            {
                GUI.Box(new Rect(500, 300, 200, 25), "Press 'E' to read note"); //1st # :      , 2nd #: moves position of text, 3rd #: makes box long, 4th #: makes box wide
 
                if(Input.GetKeyDown(KeyCode.E))
                {
                    keypadScreen = true;
                    onTrigger = false;
                }
            }
 
            if(keypadScreen)
            {

                GUI.Box(new Rect(100, 100, 500, 100), "Note 3: Investigate the rooms thoroughly. There could be a surprise for you");
            }
        }


    }
 }
