using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TetrisBlockManager : MonoBehaviour {
      

    public GameObject[] goTetrisBlocks;
    protected TetrisBlock currentBlock = null;

	// Use this for initialization
	void Start () {


    }

    public void Init()
    {
        for(int i = 0; i < this.transform.childCount; ++i)
        {
            GameObject.Destroy(this.transform.GetChild(i).gameObject);
        }
    }

    public void SpwanRandomBlock()
    {
        int type = Random.Range(0, (int)BLOCK_TYPE.MAX);
        currentBlock = CreateBlock((BLOCK_TYPE)type, 4, 0);
    }

    TetrisBlock CreateBlock(BLOCK_TYPE type, int x, int y)
    {
        GameObject block = GameObject.Instantiate(goTetrisBlocks[(int)type]);
        block.transform.parent = this.gameObject.transform;
        block.transform.localPosition = new Vector3(x * CommonDefine.BLOCK_SIZE - CommonDefine.MAX_BACKGROUND_WIDTH / 2 * CommonDefine.BLOCK_SIZE,
            -y * CommonDefine.BLOCK_SIZE + CommonDefine.MAX_BACKGROUND_HEIGHT / 2 * CommonDefine.BLOCK_SIZE, 0f);
        block.transform.localScale = Vector3.one;
        block.SetActive(true);

        return block.GetComponent<TetrisBlock>();
    }

    // Update is called once per frame
    void Update () {

        if(currentBlock != null)
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
        }

        if (Input.GetKeyDown(KeyCode.Space))
        {
            SpwanRandomBlock();
        }


    }
}
