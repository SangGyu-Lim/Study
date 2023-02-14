using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour {

    public static GameManager instance = null;

    private void Awake()
    {
        if (instance == null)
            instance = this;
    }

    public GameObject[] goScenes;

    public UILabel labelStart;

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
                    TetrisBlockManager.instance.Init();
                    UIBackgroundManager.instance.Init();

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

        TetrisBlockManager.instance.SpwanRandomBlock();
    }

    
    public bool IsValidPosition(Transform block)
    {
        for (int i = 0; i < block.transform.childCount; ++i)
        {
            Transform piece = block.transform.GetChild(i);

            // float 버그 해결
            float x = Mathf.Round(piece.transform.position.x * 100f) / 100f;

            // 테트리스 벽 충돌
            if (x > UIBackgroundManager.instance.borderRightPosition || x < UIBackgroundManager.instance.borderLeftPosition || piece.transform.position.y < UIBackgroundManager.instance.borderBottomPosition)
            {
                return false;
            }

            // 블럭이 이미 존재하는지
            if (UIBackgroundManager.instance.IsExistHoldPiece(piece) == true)
                return false;
            
        }

        return true;
    }

    public void OnPlaceBlock(TetrisBlock block)
    {
        // 현재 블럭 색상으로 배경 블럭 색 변경.
        for (int i = 0; i < block.transform.childCount; ++i)
        {
            Transform piece = block.transform.GetChild(i);

            UIBackgroundManager.instance.OnPlacePiece(piece);           
            
        }

        // 현재 블럭 제거
        GameObject.Destroy(block.transform.gameObject);

        UIBackgroundManager.instance.DeleteRows();

        TetrisBlockManager.instance.SpwanRandomBlock();
    }


}
