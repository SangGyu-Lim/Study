using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TetrisBlockManager : MonoBehaviour {

    public GameObject[] goTetrisBlocks;
    protected TetrisBlock currentBlock = null;

    float currentMoveTime = 0.0f;

    bool isFastMove = false;

    private int _currentBlcokCount = 0;
    public int currentBlcokCount { get { return _currentBlcokCount; } private set {  } }
        

    // Use this for initialization
    void Start () {


    }

    public void Init()
    {
        for(int i = 0; i < _currentBlcokCount; ++i)
        {
            GameObject.Destroy(this.transform.GetChild(i).gameObject);
        }

        currentMoveTime = 0.0f;
        _currentBlcokCount = 0;
    }

    public void SpwanRandomBlock()
    {
        int type = Random.Range(0, (int)BLOCK_TYPE.MAX);
        currentBlock = CreateBlock((BLOCK_TYPE)type, 4, 0);
        currentBlock.blockType = (BLOCK_TYPE)type;
        currentBlock.isMove = true;
        ++_currentBlcokCount;
    }

    TetrisBlock CreateBlock(BLOCK_TYPE type, int x, int y)
    {
        GameObject block = GameObject.Instantiate(goTetrisBlocks[(int)type]);
        block.transform.parent = this.gameObject.transform;
        block.transform.localPosition = new Vector3(x * CommonDefine.BLOCK_SIZE - CommonDefine.MAX_BACKGROUND_WIDTH / 2 * CommonDefine.BLOCK_SIZE,
            -y * CommonDefine.BLOCK_SIZE + CommonDefine.MAX_BACKGROUND_HEIGHT / 2 * CommonDefine.BLOCK_SIZE, 0f);
        block.transform.localScale = Vector3.one;
        block.name = currentBlcokCount.ToString();
        block.SetActive(true);

        return block.GetComponent<TetrisBlock>();
    }

    // Update is called once per frame
    void Update () {

        if(currentBlock != null)
        {
            // 블럭 스스로 추락.
            if(isFastMove == false)
            {
                // 블럭 로테이션
                if (Input.GetKeyDown(KeyCode.UpArrow))
                {
                    currentBlock.Rotate();
                }

                // 좌우 이동
                if (Input.GetKeyDown(KeyCode.LeftArrow))
                {
                    currentBlock.MoveHorizontal(Vector2.left);

                    //Debug.LogError("TetrisBlockManager Block >> " + currentBlock.transform.localPosition);
                }
                else if (Input.GetKeyDown(KeyCode.RightArrow))
                {
                    currentBlock.MoveHorizontal(Vector2.right);

                    //Debug.LogError("TetrisBlockManager Block >> " + currentBlock.transform.localPosition);
                }


                // 테스트 코드
                if (Input.GetKeyDown(KeyCode.DownArrow))
                {
                    currentBlock.MoveFall();
                    currentMoveTime = 0.0f;

                    if (currentBlock.isMove == false)
                    {
                        currentBlock.PileBlock();
                        SpwanRandomBlock();
                    }
                }

                // 자유 낙하 운동
                currentMoveTime += Time.deltaTime;
                if (currentMoveTime >= CommonDefine.DEFAULT_MOVE_TIME)
                {
                    currentBlock.MoveFall();
                    currentMoveTime = 0.0f;

                    if (currentBlock.isMove == false)
                    {
                        currentBlock.PileBlock();
                        CheckFillLine();
                        SpwanRandomBlock();
                    }

                    //Debug.LogError("TetrisBlock Block >> " + this.transform.localPosition);
                }

                // 빠르게 자유 낙하 운동 설정
                if (Input.GetKeyDown(KeyCode.Space))
                {
                    isFastMove = true;
                }
            }

            // 빠르게 자유 낙하 운동
            if (isFastMove)
            {
                currentBlock.MoveFall();
                currentMoveTime = 0.0f;

                if (currentBlock.isMove == false)
                {
                    currentBlock.PileBlock();
                    CheckFillLine();
                    SpwanRandomBlock();
                    isFastMove = false;
                }
            }

        }
    }

    void CheckFillLine()
    {
        for (int i = 0; i < CommonDefine.MAX_BACKGROUND_HEIGHT; ++i)
        {
            if (GameManager.Instance.IsFillLine(i))
            {
                DeleteLine(i);
                DownLine(i);
                --i;
            }
        }
    }

    void DeleteLine(int height)
    {
        for (int i = 0; i < CommonDefine.MAX_BACKGROUND_WIDTH; ++i)
        {
            Vector2 block = GameManager.Instance.existBlockArrayPosition[i, height];
            Transform childBlock = this.transform.GetChild((int)block.x);
            Transform[] childPiece = childBlock.GetComponentsInChildren<Transform>();

            for (int j = 1; j < childPiece.Length; ++j)
            {
                if(childPiece[(int)block.y].position.y > childPiece[j].position.y)
                    childPiece[j].position += new Vector3(0, CommonDefine.BLOCK_RANGE, 0);
            }

            //GameManager.Instance.InitLine(i, height);
            //GameObject.Destroy(childPiece[(int)block.y].gameObject);
            UISprite spritePiece = childPiece[(int)block.y].GetComponent<UISprite>();
            spritePiece.enabled = false;
        }
    }

    void DownLine(int index)
    {
        float deleteLinePositionY = GameManager.Instance.GetLinePosition(index);
        GameManager.Instance.DownLine(index);

        for (int i = 0; i < currentBlcokCount; ++i)
        {
            Transform childBlock = this.transform.GetChild(i);            
            Transform[] childPiece = childBlock.GetComponentsInChildren<Transform>();

            for (int j = 1; j < childPiece.Length; ++j)
            {
                if (deleteLinePositionY < childPiece[j].position.y)
                {
                    childBlock.position -= new Vector3(0, CommonDefine.BLOCK_RANGE, 0);
                    //childBlock.localPosition -= new Vector3(0, CommonDefine.BLOCK_SIZE, 0);
                    
                    break;
                }
            }
        }
    }
    

}
