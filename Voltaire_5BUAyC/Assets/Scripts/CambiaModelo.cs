using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CambiaModelo : MonoBehaviour
{
	public int numeroEtapa;

	// Use this for initialization
	void Start ()
	{
		
	}
	
	// Update is called once per frame
	void Update ()
	{

		if (Input.GetKeyDown (KeyCode.Space)) {

			if (numeroEtapa < 2) {

				numeroEtapa++;
			}

			if (numeroEtapa == 3) {
				numeroEtapa = 0;
			}
		}

		seleccionaModelo ();

	}

	void seleccionaModelo ()
	{

	}


}


