using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIController : MonoBehaviour
{
    public GameObject Square;
    // Start is called before the first frame update
    Transform _target;
    float radius = 150;
    // Update is called once per frame
    void Start()
    {
        // _nma = GetComponent<UnityEngine.AI.NavMeshAgent>();
        //_target = GameObject.FindWithTag ("Player").transform;
        _target = GameObject.FindWithTag("Player").transform;
    }
    public void Update()
    {
        if (Input.GetKeyDown(KeyCode.A))
        {
            //if (Vector3.Distance(_target.position, transform.position) < radius)
            StartCoroutine(FadeSquare());
        }
    }

    public IEnumerator FadeSquare(bool fadeToBlack = true, int fadeSpeed = 5)
    {
        Color objectColor = Square.GetComponent<Image>().color;
        float fadeAmount;
        if (fadeToBlack)
        {
            while (Square.GetComponent<Image>().color.a < 1)
            {
                fadeAmount = objectColor.a + (fadeSpeed + Time.deltaTime);

                objectColor = new Color(objectColor.r, objectColor.g, objectColor.b, fadeAmount);
                Square.GetComponent<Image>().color = objectColor;
                yield return null;
            }
        }
        else
        {
            while (Square.GetComponent<Image>().color.a > 0)
            {
                fadeAmount = objectColor.a - (fadeSpeed * Time.deltaTime);

                objectColor = new Color(objectColor.r, objectColor.g, objectColor.b, fadeAmount);
                Square.GetComponent<Image>().color = objectColor;

                yield return null;
            }
        }
    }
}