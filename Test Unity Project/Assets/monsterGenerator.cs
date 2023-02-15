using UnityEngine;
using System.Collections;

public class monsterGenerator : MonoBehaviour {

	public GameObject monsterObject;

	public float generateTime = 0f;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {

		generateTime -= Time.deltaTime;
		if (generateTime <= 0f) {
			SpawnMonster ();
		}
	
	}

	void SpawnMonster()
	{
		int monsterCount = Random.Range (5, 11);

		for (int i = 0; i < monsterCount; ++i) {
			GameObject cloneMonster = GameObject.Instantiate (monsterObject);

			cloneMonster.transform.localPosition = Vector3.zero;
			cloneMonster.transform.localRotation = Quaternion.identity;
			//cloneMonster.transform.localScale = new Vector3(5f, 5f, 5f);
			cloneMonster.transform.localScale = Vector3.one;

			cloneMonster.name = "Monster";

			float x = Random.Range (-20f, 20f);
			float z = Random.Range (-20f, 20f);

			cloneMonster.transform.position = new Vector3 (x, 0f, z);
			cloneMonster.SetActive (true);
		}

		generateTime = 10f;
	}

}
