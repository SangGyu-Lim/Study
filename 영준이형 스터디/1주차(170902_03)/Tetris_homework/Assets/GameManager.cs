using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour {

    #region Singleton
    private static GameManager _instance;
    public static GameManager Instance
    {
        get
        {
            if (_instance == null)
            {
                _instance = UnityEngine.Object.FindObjectOfType(typeof(GameManager)) as GameManager;

                GameObject go = new GameObject("CommonUI");
                _instance = go.AddComponent<GameManager>();
            }

            return _instance;
        }
    }

    private void Awake()
    {
        if (_instance == null)
            _instance = this;
        else if (_instance != this)
            Destroy(gameObject);
    }
    #endregion

    public GameObject[] goScenes;

    public UILabel labelStart;

    public TetrisBlockManager tetrisBlockManager;
    public UIBackground uiBackground;

    // 해당하는 배열 위치에 블럭 존재여부
    public bool[,] isExistBlock;
    // x = 몇 번째 블럭인지 / y = 블럭에서 몇번째 피스인지.
    public Vector2[,] existBlockArrayPosition;

    // Use this for initialization
    void Start () {
        isExistBlock = new bool[CommonDefine.MAX_BACKGROUND_WIDTH, CommonDefine.MAX_BACKGROUND_HEIGHT];
        existBlockArrayPosition = new Vector2[CommonDefine.MAX_BACKGROUND_WIDTH, CommonDefine.MAX_BACKGROUND_HEIGHT];

        ChangeStage(STAGE_TYPE.INTRO);
    }
	
	// Update is called once per frame
	void Update () {


    }

    public void Init()
    {
        for (int i = 0; i < CommonDefine.MAX_BACKGROUND_WIDTH; ++i)
        {
            for (int j = 0; j < CommonDefine.MAX_BACKGROUND_HEIGHT; ++j)
            {
                isExistBlock[i, j] = false;
                existBlockArrayPosition[i, j].x = -1;
                existBlockArrayPosition[i, j].y = -1;
            }

        }
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
                    Init();
                    tetrisBlockManager.Init();

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
        /*
        labelStart.text = "3";

        yield return new WaitForSeconds(1f);
        labelStart.text = "2";

        yield return new WaitForSeconds(1f);
        labelStart.text = "1";
        
        yield return new WaitForSeconds(1f);
        */    
        labelStart.text = "START";

        yield return new WaitForSeconds(1f);
        labelStart.gameObject.SetActive(false);
                
        Init();

        tetrisBlockManager.SpwanRandomBlock();
    }

    public bool IsValidNextPosition(MOVE_ARROW type, float positionX, float positionY)
    {
        // 벽 체크
        switch (type)
        {
            case MOVE_ARROW.LEFT:
                {
                    if (positionX < uiBackground.wallPositionXMin)
                        return false;
                } break;
            case MOVE_ARROW.RIGHT:
                {
                    if (positionX > uiBackground.wallPositionXMax)
                        return false;
                }
                break;
            case MOVE_ARROW.DOWN:
                {
                    if (positionY < uiBackground.wallPositionY)
                        return false;
                } break;
            case MOVE_ARROW.ROTATE:
                {
                    if ((positionX < uiBackground.wallPositionXMin)
                        || (positionX > uiBackground.wallPositionXMax)
                        || (positionY < uiBackground.wallPositionY))
                        return false;

                } break;
        }

        // 쌓인 블럭 체크
        float minX = uiBackground.wallPositionXMin;
        float minY = uiBackground.wallPositionY;
        float blockRange = (uiBackground.wallPositionXMax - minX) / (CommonDefine.MAX_BACKGROUND_WIDTH - 1);

        for (int i = 0; i < CommonDefine.MAX_BACKGROUND_WIDTH; ++i)
        {
            for (int j = 0; j < CommonDefine.MAX_BACKGROUND_HEIGHT; ++j)
            {
                if ((positionX >= (minX + (i * blockRange)))
                    && (positionX < (minX + ((i + 1) * blockRange))))
                {
                    if ((positionY >= (minY + (j * blockRange)))
                    && (positionY < (minY + ((j + 1) * blockRange))))
                    {
                        if (isExistBlock[i, j] == true)
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }

    public void PileBlock(float positionX, float positionY, int piece)
    {
        float minX = uiBackground.wallPositionXMin;
        float minY = uiBackground.wallPositionY;
        float blockRange = (uiBackground.wallPositionXMax - minX) / (CommonDefine.MAX_BACKGROUND_WIDTH - 1);

        for (int i = 0; i < CommonDefine.MAX_BACKGROUND_WIDTH; ++i)
        {
            for (int j = 0; j < CommonDefine.MAX_BACKGROUND_HEIGHT; ++j)
            {
                if((positionX >= (minX + (i * blockRange)))
                    && (positionX < (minX + ((i + 1) * blockRange))))
                {
                    if ((positionY >= (minY + (j * blockRange)))
                    && (positionY < (minY + ((j + 1) * blockRange))))
                    {
                        isExistBlock[i, j] = true;
                        existBlockArrayPosition[i, j].x = tetrisBlockManager.currentBlcokCount - 1;
                        existBlockArrayPosition[i, j].y = piece;
                        return;
                    }
                }                
            }
        }
    }

    public MOVE_ARROW CrashDirection(float positionX, float positionY)
    {
        if (positionX <= uiBackground.wallPositionXMin)
            return MOVE_ARROW.LEFT;

        if (positionX >= uiBackground.wallPositionXMax)
            return MOVE_ARROW.RIGHT;

        if (positionY <= uiBackground.wallPositionY)
            return MOVE_ARROW.DOWN;

        return MOVE_ARROW.ROTATE;
    }

    public bool IsFillLine(int height)
    {
        for (int i = 0; i < CommonDefine.MAX_BACKGROUND_WIDTH; ++i)
        {
            if (isExistBlock[i, height] == false)
                return false;            
        }

        return true;
    }

    public void InitLine(int width, int height)
    {
        isExistBlock[width, height] = false;
        existBlockArrayPosition[width, height].x = -1;
        existBlockArrayPosition[width, height].y = -1;
    }

    public void DownLine(int lineNum)
    {
        for (int i = 0; i < CommonDefine.MAX_BACKGROUND_WIDTH; ++i)
        {
            for (int j = lineNum; j < (CommonDefine.MAX_BACKGROUND_HEIGHT - 1); ++j)
            {
                isExistBlock[i, j] = isExistBlock[i, (j + 1)];
                existBlockArrayPosition[i, j].x = existBlockArrayPosition[i, (j + 1)].x;
                existBlockArrayPosition[i, j].y = existBlockArrayPosition[i, (j + 1)].y;
            }
        }

        for(int i = 0; i < CommonDefine.MAX_BACKGROUND_WIDTH; ++i)
        {
            InitLine(i, (CommonDefine.MAX_BACKGROUND_HEIGHT - 1));
        }
    }

    public float GetLinePosition(int index)
    {
        float minY = uiBackground.wallPositionY;
        float blockRange = (uiBackground.wallPositionXMax - uiBackground.wallPositionXMin) / (CommonDefine.MAX_BACKGROUND_WIDTH - 1);

        return (minY + (index * blockRange));
    }
}
