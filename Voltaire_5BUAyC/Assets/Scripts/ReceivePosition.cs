//recordar setActive y crear un array de imagenes


using UnityEngine;
using System.Collections;

public class ReceivePosition : MonoBehaviour
{
    
	public OSC osc;
	private float escenaNumero=0f;
	public Vector3 valorVector;
	public SelectorEscena selEscena;


	// Use this for initialization
	public void Start ()
	{
		osc.SetAddressHandler ("/CubeXYZ", OnReceiveXYZ);
		osc.SetAddressHandler ("/CubeX", OnReceiveX);
		osc.SetAddressHandler ("/CubeY", OnReceiveY);
		osc.SetAddressHandler ("/CubeZ", OnReceiveZ);
		osc.SetAddressHandler ("/EscenaSlider", OnReceiveEscena);
	
	}
	
	// Update is called once per frame
	void Update ()
	{
	
	}

	void OnReceiveXYZ (OscMessage message)
	{
		float x = message.GetFloat (0);
		float y = message.GetFloat (1);
		float z = message.GetFloat (2);

		transform.position = new Vector3 (x, y, z);
		valorVector = new Vector3 (x,y,z);
	}

	void OnReceiveX (OscMessage message)
	{
		float x = message.GetFloat (0);

		Vector3 position = transform.position;

		position.x = x;

		transform.position = position;
	}

	void OnReceiveY (OscMessage message)
	{
		float y = message.GetFloat (0);

		Vector3 position = transform.position;

		position.y = y;

		transform.position = position;
	}

	void OnReceiveZ (OscMessage message)
	{
		float z = message.GetFloat (0);

		Vector3 position = transform.position;

		position.z = z;

		transform.position = position;
	}


	void OnReceiveEscena (OscMessage message)
	{
		escenaNumero = message.GetFloat (0);
		selEscena.seleccionaEscena ();
	
	
	}

	public float getNumeroEscena ()
	{
		
		return escenaNumero;
	}

	public Vector3 getValorVector ()
	{

		return valorVector;
	}





}
