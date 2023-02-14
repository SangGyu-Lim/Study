using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour {

    static GameManager instance = null;
    public static GameManager Instance
    {
        get { return instance; }
    }

    private void Awake()
    {
        if (instance == null)
            instance = this;
    }

    public struct RankInfo
    {
        public string nickName;
        public int score;
    }

    protected List<RankInfo> listRankInfo = new List<RankInfo>();

    public GameObject[] goScenes;

    public UILabel labelStart;
    public UILabel labelGameLevel;
    public UILabel labelGameScore;

    protected int currentGameLevel = 0;
    protected int currentGameScore = 0;
    public float moveSpeedTime = CommonDefine.DEFAULT_MOVE_TIME;

    public GameObject goRankPopup;
    public UILabel labelRankList;

    // Use this for initialization
    void Start () {
        ChangeStage(STAGE_TYPE.INTRO);
    }
	
	// Update is called once per frame
	void Update () {
        

    }

    protected void InitGameInfo()
    {
        currentGameScore = 0;
        currentGameLevel = 1;

        labelGameLevel.text = currentGameLevel.ToString();
        labelGameScore.text = currentGameScore.ToString();

    }

    void ChangeStage(STAGE_TYPE type)
    {
        // 다 끄기
        for(int i = 0; i < (int)STAGE_TYPE.MAX; ++i)
            goScenes[i].SetActive(false);

        switch (type)
        {
            case STAGE_TYPE.INTRO:
                {
                    if (PlayerPrefs.HasKey("SINGLE_RANK_LIST") == true)
                    {
                        SettingRankList(PlayerPrefs.GetString("SINGLE_RANK_LIST"));
                    }

                    goRankPopup.gameObject.SetActive(false);
                    labelStart.gameObject.SetActive(false);
                    StopAllCoroutines();

                    goScenes[(int)STAGE_TYPE.INTRO].SetActive(true);
                    
                } break;
            case STAGE_TYPE.GAME:
                {
                    InitGameInfo();
                    TetrisBlockManager.Instance.Init();
                    UIBackgroundManager.Instance.Init();

                    StartCoroutine(StartGame());
                    goScenes[(int)STAGE_TYPE.GAME].SetActive(true);
                    
                } break;
        }
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

        TetrisBlockManager.Instance.SpwanRandomBlock();

        StartCoroutine(OnLevelUpGame());
    }


    #region OnClick
    public void OnClickSinglePlay()
    {
        ChangeStage(STAGE_TYPE.GAME);     

    }

    public void OnClickMultiPlay()
    {
        ChangeStage(STAGE_TYPE.GAME);

    }

    public void OnClickBack()
    {
        ChangeStage(STAGE_TYPE.INTRO);
    }
#endregion

    //레벨업 관리
    IEnumerator OnLevelUpGame()
    {
        for (int i = 0; i < CommonDefine.MAX_GAME_LEVEL; ++i)
        {
            yield return new WaitForSeconds(CommonDefine.LEVEL_UP_SECOND);

            currentGameLevel++;
            labelGameLevel.text = currentGameLevel.ToString();
            moveSpeedTime *= CommonDefine.LEVEL_UP_SPEED_RATIO;//반띵..빨라지게.
        }
    }


    public bool IsValidPosition(Transform block)
    {
        for (int i = 0; i < block.transform.childCount; ++i)
        {
            Transform piece = block.transform.GetChild(i);

            // float 버그 해결
            float x = Mathf.Round(piece.transform.position.x * 100f) / 100f;

            // 테트리스 벽 충돌
            if (x > UIBackgroundManager.Instance.borderRightPosition
                || x < UIBackgroundManager.Instance.borderLeftPosition 
                || piece.transform.position.y < UIBackgroundManager.Instance.borderBottomPosition)
            {
                return false;
            }

            // 블럭이 이미 존재하는지
            if (UIBackgroundManager.Instance.IsExistHoldPiece(piece) == true)
                return false;
            
        }

        return true;
    }

    public void OnPlaceBlock(TetrisBlock block)
    {
        block.enabled = false;

        if (IsGameEndPosition(block.transform) == false)
        {
            // 현재 블럭 색상으로 배경 블럭 색 변경.
            for (int i = 0; i < block.transform.childCount; ++i)
            {
                Transform piece = block.transform.GetChild(i);

                UIBackgroundManager.Instance.OnPlacePiece(piece);

            }

            // 현재 블럭 제거
            GameObject.Destroy(block.transform.gameObject);

            UIBackgroundManager.Instance.DeleteRows();

            TetrisBlockManager.Instance.SpwanRandomBlock();
        }
        else
        {
            OnGameOver();
        }

    }

    // 테트리스 블럭 벽 충돌체크
    public bool IsGameEndPosition(Transform block)
    {
        for (int i = 0; i < block.transform.childCount; ++i)
        {
            // 자식 가져오기
            Transform child = block.transform.GetChild(i);
            if (child.transform.position.y > UIBackgroundManager.Instance.borderTopPosition)
            {
                return true;
            }

        }
        return false;
    }

    protected void SettingRankList(string rankList)
    {
        listRankInfo.Clear();

        // 이름, 점수 ;
        string[] scoreList = rankList.Split(';');
        for (int i = 0; i < scoreList.Length; ++i)
        {
            RankInfo rankInfo = new RankInfo();
            rankInfo.nickName = scoreList[0];
            rankInfo.score = int.Parse(scoreList[1]);
            listRankInfo.Add(rankInfo);
        }


        //소팅
        //   listRankInfo.Sort( new Delegate

    }

    protected void OnGameOver()
    {
        StartCoroutine(UIBackgroundManager.Instance.GameOverBlocks());

        // 랭크인포에 존재한다면.
        if (listRankInfo.Count > 0)
        {
            labelRankList.text = GetRankStringByList();
        }
        else
        {

        }

        goRankPopup.SetActive(true);

        //저장하기..
    }

    protected string GetRankStringByList()
    {
        // listRankInfo 소팅해주시고

        string stringRankInfo = "";
        for (int i = 0; i < listRankInfo.Count; ++i)
        {
            stringRankInfo += (i + 1) + ".";
            stringRankInfo += listRankInfo[i].nickName;
            stringRankInfo += " : ";
            stringRankInfo += listRankInfo[i].score;
        }

        return stringRankInfo;
    }

    protected void AddRankList(string nickName, int score)
    {
        RankInfo rankInfo = new RankInfo();
        rankInfo.nickName = nickName;
        rankInfo.score = score;
        listRankInfo.Add(rankInfo);

    }
    public void OnScoreUp()
    {
        currentGameScore += CommonDefine.DELETE_ONEROW_SCORE;
        labelGameScore.text = currentGameScore.ToString();
    }
}
