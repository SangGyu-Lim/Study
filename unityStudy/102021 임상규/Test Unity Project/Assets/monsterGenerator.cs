using UnityEngine;
using System.Collections;

public class monsterGenerator : MonoBehaviour {

	public GameObject monsterObject;
    GameObject[] cloneMonster;

	public float generateTime = 0f;

    const int MAX_MOSTER_COUNT = 5;
    const float RANGE_MIN = -10.0F;
    const float RANGE_MAX = 10.0F;

    public int monsterCount = MAX_MOSTER_COUNT;

    int isCollisionNum;

    bool isUpdate = false;
    public bool isContinue = true;

	// Use this for initialization
	void Start () {
        SpawnMonster();
	}
	
	// Update is called once per frame
	void Update () {

        //generateTime -= Time.deltaTime;
        //if (generateTime <= 0f) {
        //    SpawnMonster ();
        //}

        if (isContinue)
        {
            if (isUpdate)
            {
                DeleteMonster();

                if (monsterCount == 0)
                {
                    monsterObject.gameObject.GetComponent<monster>().updateMonsetrInformation();
                    SpawnMonster();
                }

                isUpdate = false;
            }
        }       
        
	
	}    

	void SpawnMonster()
	{
        monsterCount = MAX_MOSTER_COUNT;
        cloneMonster = new GameObject[MAX_MOSTER_COUNT];

        for (int i = 0; i < MAX_MOSTER_COUNT; i++)
        {
			cloneMonster[i] = GameObject.Instantiate (monsterObject);

			cloneMonster[i].transform.localPosition = Vector3.zero;
			cloneMonster[i].transform.localRotation = Quaternion.identity;
			//cloneMonster.transform.localScale = new Vector3(5f, 5f, 5f);
			cloneMonster[i].transform.localScale = Vector3.one;

			cloneMonster[i].name = "Monster";

            float x = Random.Range(RANGE_MIN, RANGE_MAX);
            float z = Random.Range(RANGE_MIN, RANGE_MAX);

			cloneMonster[i].transform.position = new Vector3 (x, 0f, z);
			cloneMonster[i].SetActive (true);
		}

		generateTime = 10f;
	}

    void DeleteMonster()
    {
        for (int i = 0; i < monsterCount; i++)
        {
            if (cloneMonster[i].gameObject.GetComponent<monster>().hp <= 0)
            {
                Debug.Log("moster hp 0");
                GameObject.Destroy(this.cloneMonster[i]);

                for (int j = i; j < monsterCount - 1; j++)
                {
                    cloneMonster[j] = cloneMonster[j + 1];
                }
                
                monsterCount--;
            }
        }        
    }

    public bool isCollision()
    {
        for (int i = 0; i < monsterCount; i++)
        {
            if (cloneMonster[i].gameObject.GetComponent<monster>().collisionOnceCheck)
            {
                isCollisionNum = i;
                isUpdate = true;
                cloneMonster[i].gameObject.GetComponent<monster>().collisionOnceCheck = false;
                return true;
            }
        }

        return false;
    }

    public int getMonsterHp()
    {
        return cloneMonster[isCollisionNum].gameObject.GetComponent<monster>().hp;
    }

    public void setMonsterHp(int hp)
    {
        cloneMonster[isCollisionNum].gameObject.GetComponent<monster>().hp = hp;
        cloneMonster[isCollisionNum].gameObject.GetComponent<monster>().hpTextMesh.text = "Hp : " + hp.ToString();
    }

    public int getMonsterExp()
    {
        return cloneMonster[isCollisionNum].gameObject.GetComponent<monster>().exp;
    }

    public void setBackDir(Vector3 backDir)
    {
        cloneMonster[isCollisionNum].gameObject.GetComponent<monster>().backDir = backDir;
    }

    public void setIsContinue()
    {
        for (int i = 0; i < monsterCount; i++)
        {
            cloneMonster[i].gameObject.GetComponent<monster>().isContinue = false;
        }
    }

}
