using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TetrisBlockManager : MonoBehaviour {

#region SingleTon

    public static TetrisBlockManager instance = null;

    private void Awake()
    {
        if (instance == null)
            instance = this;
    }

#endregion

    public GameObject goParentTetrisBlock;
    public GameObject[] goTetrisBlocksTemplate;
    protected TetrisBlock currentBlock = null;
    protected TetrisBlock nextBlock = null;
    //public TetrisBlock currentBlock = null;
    //public TetrisBlock nextBlock = null;

    // Use this for initialization
    void Start () {
        

    }

    public void Init()
    {
        for(int i = 0; i < goParentTetrisBlock.transform.childCount; ++i)
        {
            GameObject.Destroy(goParentTetrisBlock.transform.GetChild(i).gameObject);
        }

        currentBlock = nextBlock = null;
        SpwanRandomNextBlock();
    }

    
    public void SpwanBlock()
    {
        SpwanCurrentBlock();
        SpwanRandomNextBlock();
    }

    void SpwanCurrentBlock()
    {
        currentBlock = nextBlock;
        currentBlock.isCurrent = true;
        currentBlock.transform.localPosition = new Vector3(0, ((CommonDefine.MAX_BACKGROUND_HEIGHT / 2) - CommonDefine.BLOCK_START_Y_POSITION) * CommonDefine.BLOCK_SIZE, 0f);
    }

    void SpwanRandomNextBlock()
    {
        int type = Random.Range(0, (int)BLOCK_TYPE.MAX);
        nextBlock = CreateBlock((BLOCK_TYPE)type, CommonDefine.NEXT_BLOCK_POSITION_X, CommonDefine.NEXT_BLOCK_POSITION_Y);
        nextBlock.isCurrent = false;
    }

    TetrisBlock CreateBlock(BLOCK_TYPE type, int x, int y)
    {
        GameObject block = GameObject.Instantiate(goTetrisBlocksTemplate[(int)type]);
        block.transform.parent = goParentTetrisBlock.gameObject.transform;
        block.transform.localPosition = new Vector3(x * CommonDefine.BLOCK_SIZE - CommonDefine.MAX_BACKGROUND_WIDTH / 2 * CommonDefine.BLOCK_SIZE,
            -y * CommonDefine.BLOCK_SIZE + CommonDefine.MAX_BACKGROUND_HEIGHT / 2 * CommonDefine.BLOCK_SIZE, 0f);
        block.transform.localScale = Vector3.one;
        block.SetActive(true);

        return block.GetComponent<TetrisBlock>();
    }

    // Update is called once per frame
    void Update () {

#if UNITY_EDITOR
        if (currentBlock != null)
        {
            if (Input.GetKeyDown(KeyCode.UpArrow))
            {
                currentBlock.Rotate();
            }

            if (Input.GetKeyDown(KeyCode.LeftArrow))
            {
                currentBlock.MoveHorizontal(Vector2.left);
            }
            else if (Input.GetKeyDown(KeyCode.RightArrow))
            {
                currentBlock.MoveHorizontal(Vector2.right);
            }

            if (Input.GetKeyDown(KeyCode.DownArrow))
            {
                currentBlock.AddMoveSpeedTime(CommonDefine.DOWN_ADD_SPEED_TIME);
            }
            else if (Input.GetKeyUp(KeyCode.DownArrow))
            {
                currentBlock.AddMoveSpeedTime(CommonDefine.DEFAULT_DOWN_ADD_SPEED_TIME);
            }

            if (Input.GetKeyDown(KeyCode.Space))
            {
                currentBlock.MoveFallingDirectly();
            }
        }
#endif

    }


#region OnClick

    public void OnClickJoypad(GameObject pad)
    {
        if (currentBlock == null)
            return;

        if(pad.name.Contains("Up") == true)
        {
            currentBlock.Rotate();
        }
        else if (pad.name.Contains("Down") == true)
        {
            currentBlock.AddMoveSpeedTime(CommonDefine.DOWN_ADD_SPEED_TIME);
        }
        else if (pad.name.Contains("Left") == true)
        {
            currentBlock.MoveHorizontal(Vector2.left);
        }
        else if (pad.name.Contains("Right") == true)
        {
            currentBlock.MoveHorizontal(Vector2.right);
        }

    }

    public void OnClickFallingDirectly()
    {
        if (currentBlock == null)
            return;

        currentBlock.MoveFallingDirectly();
    }

    #endregion

    #region OnRelease
    public void OnReleaseDown()
    {
        if (currentBlock == null)
            return;

        currentBlock.AddMoveSpeedTime(CommonDefine.DEFAULT_DOWN_ADD_SPEED_TIME);
    }

#endregion

}
