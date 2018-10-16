using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SelectorEscena : MonoBehaviour
{
	ReceivePosition recibeOSC;
	int convierte;


	// Use this for initialization
	void Start ()
	{
		recibeOSC= FindObjectOfType<ReceivePosition> ();
	}

	// Update is called once per frame
	void Update ()
	{
		if (Input.GetKeyDown (KeyCode.Space)) {
			seleccionaEscena ();
		}
	}



	public void seleccionaEscena ()
	{
		/*
		int actual = SceneManager.GetActiveScene ().buildIndex;

		if ((actual + 1) < 3) {

			SceneManager.LoadScene (actual + 1);

		}

		if (actual == 3) {
			SceneManager.LoadScene (0);
		}

	//	print (recibeOSC.getValorVector());

		*/

		if (recibeOSC.getNumeroEscena() <1) {

			SceneManager.LoadScene (0);

		}

		if (recibeOSC.getNumeroEscena()<2 && recibeOSC.getNumeroEscena() >1) {

			SceneManager.LoadScene (1);

		}

		if (recibeOSC.getNumeroEscena()<3 && recibeOSC.getNumeroEscena() >2) {

			SceneManager.LoadScene (2);

		}

		if (recibeOSC.getNumeroEscena()<4 && recibeOSC.getNumeroEscena() >3) {

			SceneManager.LoadScene (3);

		}

		convierte=(int)recibeOSC.getNumeroEscena();
		//print (convierte);
		print (recibeOSC.getNumeroEscena());
		print ("hu-hu");






	}

}
