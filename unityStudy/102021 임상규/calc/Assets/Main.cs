using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class Main : MonoBehaviour {

	public Text textContent;
	public Text textResult;

	int result = 0;

	string currentNumber = "";

	bool isPlus;

	// Use this for initialization
	void Start () {
		ClearText ();
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	public void onClickNumber( string key )
	{
		textContent.text += key;

		//Debug.Log (key);

		if (key != "+" && key != "-")
			currentNumber += key;
		else {
			if (currentNumber.Length > 0) {
				if (key == "+") {					
					if (isPlus) {
						result += int.Parse (currentNumber);
					} else {
						result -= int.Parse (currentNumber);
					}
					isPlus = true;
				} else if (key == "-") {
					if (isPlus) {
						result += int.Parse (currentNumber);
					} else {
						result -= int.Parse (currentNumber);
					}
					isPlus = false;
				}
					
			}
			currentNumber = "";

		}
			
	}

	public void onClickClear()
	{
		ClearText ();
	}

	void ClearText()
	{
		textContent.text = "";
		textResult.text = "";
		currentNumber = "";
		result = 0;
		isPlus = true;
	}

	public void onClickResult()
	{
		Debug.Log (currentNumber);
		if (isPlus) {
			result += int.Parse (currentNumber);
		} else {
			result -= int.Parse (currentNumber);
		}
		textResult.text = result.ToString ();
	}
}
