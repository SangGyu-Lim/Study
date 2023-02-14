using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour {

    public GameObject[] goScenes;

    public UILabel labelStart;

    public TetrisBlockManager blockManager;

	// Use this for initialization
	void Start () {
        ChangeStage(STAGE_TYPE.INTRO);
    }
	
	// Update is called once per frame
	void Update () {
        
		
	}

    void ChangeStage(STAGE_TYPE type)
    {
        for(int i = 0; i < (int)STAGE_TYPE.MAX; ++i)
            goScenes[i].SetActive(false);

        switch (type)
        {
            case STAGE_TYPE.INTRO:
                {
                    labelStart.gameObject.SetActive(false);
                    StopAllCoroutines();

                    goScenes[(int)STAGE_TYPE.INTRO].SetActive(true);                    
                } break;
            case STAGE_TYPE.GAME:
                {
                    blockManager.Init();

                    StartCoroutine("StartGame");
                    goScenes[(int)STAGE_TYPE.GAME].SetActive(true);
                } break;
        }
    }

    public void OnClickIntro()
    {
        ChangeStage(STAGE_TYPE.GAME);     

    }

    public void OnClickBack()
    {
        ChangeStage(STAGE_TYPE.INTRO);
    }

    IEnumerator StartGame()
    {
        labelStart.gameObject.SetActive(true);

        labelStart.text = "3";

        yield return new WaitForSeconds(1f);
        labelStart.text = "2";

        yield return new WaitForSeconds(1f);
        labelStart.text = "1";

        yield return new WaitForSeconds(1f);
        labelStart.text = "START";

        yield return new WaitForSeconds(1f);
        labelStart.gameObject.SetActive(false);

        blockManager.SpwanRandomBlock();
    }
}
