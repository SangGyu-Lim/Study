using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour {

#region SingleTon

    public static GameManager instance = null;

    private void Awake()
    {
        if (instance == null)
            instance = this;
    }

#endregion

    public GameObject[] goScenes;

    public UILabel labelStart;
    public UILabel labelTimer;
    public UILabel labelScore;
    public UILabel labelSpeedUp;
    public UILabel labelGameOver;

    STAGE_TYPE currentStageType = STAGE_TYPE.INTRO;

    bool isWin = false;
    
    int second = 0;
    int minute = 0;
    float currentTime = 0;

    int score = 0;

    public float speedUpRate = 1.0f;

    // Use this for initialization
    void Start () {
        ChangeStage(STAGE_TYPE.INTRO);
    }
	
	// Update is called once per frame
	void Update () {
        if(currentStageType == STAGE_TYPE.GAME)
        {
            currentTime += Time.deltaTime;
            if (second != Mathf.Round(currentTime))
            {
                ++second;
                // 시간 분단위 교환.
                if((second % CommonDefine.SECOND_TO_MINUTE_RATE_TIME) == 0)
                {
                    ++minute;
                    second = 0;
                    currentTime = 0f;
                    
                }
                SetTimerLabel();

                // 시간에 따른 난이도 증가.
                if ((second % CommonDefine.SPEED_UP_TIME) == 0)
                {
                    StartCoroutine("SpeedUp");
                    speedUpRate += CommonDefine.SPEED_UP_RATE;
                }
            }
        }
        
    }

    void Init()
    {
        // 타이머 초기화
        labelTimer.gameObject.SetActive(true);
        second = 0;
        minute = 0;
        currentTime = 0f;
        SetTimerLabel();

        // 점수 초기화
        labelScore.gameObject.SetActive(true);
        score = 0;
        SetScoreLabel();

        // 게임 속도 초기화
        speedUpRate = 1.0f;

        isWin = false;
    }

    public void AddScore()
    {
        score += CommonDefine.DECREASE_ROW_SCORE;
        SetScoreLabel();
    }

    void SetScoreLabel()
    {
        labelScore.text = string.Format("Score {0}", score);
    }

    void SetTimerLabel()
    {
        if(minute != 0)
            labelTimer.text = string.Format("Time {0}'{1}s", minute, second);
        else
            labelTimer.text = string.Format("Time {0}s", second);
            
    }

    void ChangeStage(STAGE_TYPE type)
    {
        for(int i = 0; i < (int)STAGE_TYPE.MAX; ++i)
            goScenes[i].SetActive(false);

        switch (type)
        {
            case STAGE_TYPE.INTRO:
                {
                    currentStageType = STAGE_TYPE.INTRO;

                    labelStart.gameObject.SetActive(false);
                    labelTimer.gameObject.SetActive(false);
                    labelScore.gameObject.SetActive(false);

                    StopAllCoroutines();
                } break;
            case STAGE_TYPE.WAIT:
                {
                    currentStageType = STAGE_TYPE.WAIT;

                    //SocketManager.instance.CheckMulti();
                    SocketManager.instance.StartMulti();
                    
                } break;
            case STAGE_TYPE.GAME:
                {
                    currentStageType = STAGE_TYPE.GAME;

                    TetrisBlockManager.instance.Init();
                    UIBackgroundManager.instance.Init();

                    StartCoroutine("StartGame");
                } break;
            case STAGE_TYPE.GAME_OVER:
                {
                    goScenes[(int)currentStageType].SetActive(true);
                    currentStageType = STAGE_TYPE.GAME_OVER;

                    if(isWin)
                    {
                        labelGameOver.text = "You Win~~!";
                    }
                    else
                    {
                        labelGameOver.text = "You Lose....";
                    }
                } break;
        }

        goScenes[(int)currentStageType].SetActive(true);
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

            // 피스가 제대로 된 위치가 아닐시 게임 종료 조건 설정.
            if (UIBackgroundManager.instance.IsValidPlace(piece) == false)
            {
                isWin = false;
                ChangeStage(STAGE_TYPE.GAME_OVER);
                SocketManager.instance.CallGameOver();

                return;
            }

            UIBackgroundManager.instance.OnPlacePiece(piece);

        }

        // 현재 블럭 제거
        GameObject.Destroy(block.transform.gameObject);

        UIBackgroundManager.instance.DeleteRows();

        SocketManager.instance.UpdateBlock();

        TetrisBlockManager.instance.SpwanBlock();
    }

    public void CallGameStart()
    {
        ChangeStage(STAGE_TYPE.GAME);
    }

    public void CallGameOver()
    {
        isWin = true;
        ChangeStage(STAGE_TYPE.GAME_OVER);
    }


    #region OnClick

    public void OnClickIntro()
    {
        ChangeStage(STAGE_TYPE.WAIT);     
    }

    public void OnClickBack()
    {
        EndGame();
    }

    public void OnClickGameOver()
    {
        EndGame();
    }

    void EndGame()
    {
        ChangeStage(STAGE_TYPE.INTRO);
        SocketManager.instance.EndMulti();
    }

    public void OnClickGameExit()
    {
        Application.Quit();
    }

    #endregion

    #region IEnumerator

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

        Init();
        TetrisBlockManager.instance.SpwanBlock();
    }

    IEnumerator SpeedUp()
    {
        labelSpeedUp.gameObject.SetActive(true);

        yield return new WaitForSeconds(0.8f);

        labelSpeedUp.gameObject.SetActive(false);
    }

    #endregion





}
