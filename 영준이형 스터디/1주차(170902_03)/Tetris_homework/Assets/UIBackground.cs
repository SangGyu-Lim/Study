using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIBackground : MonoBehaviour {

    public UISprite spriteBlock;

    public float wallPositionXMin;
    public float wallPositionXMax;
    public float wallPositionY;    

    // Use this for initialization
    void Start () {          

        // 게임 배경 생성
        for (int i = 0; i < CommonDefine.MAX_BACKGROUND_WIDTH; ++i)
        {
            for(int j = 0; j < CommonDefine.MAX_BACKGROUND_HEIGHT; ++j)
            {
                CreateBlock(i, j);
            }
            
        }
		
	}    

    void CreateBlock(int x, int y)
    {
        // 복사 및 세팅
        GameObject block = GameObject.Instantiate(spriteBlock.gameObject);
        block.transform.parent = this.gameObject.transform;
        block.transform.localPosition = new Vector3(x * CommonDefine.BLOCK_SIZE - CommonDefine.MAX_BACKGROUND_WIDTH / 2 * CommonDefine.BLOCK_SIZE,
            -y * CommonDefine.BLOCK_SIZE + CommonDefine.MAX_BACKGROUND_HEIGHT / 2 * CommonDefine.BLOCK_SIZE, 0f);
        block.transform.localScale = Vector3.one;
        block.SetActive(true);

        //Debug.LogWarning(x + " , " + y + " >> " + block.transform.position);
        //Debug.LogWarning("x(" + x + ") >> " + block.transform.position.x + " / y(" + y + ") >> " + block.transform.position.y);
        // 테두리 벽 좌표 지정
        if (x == 0)
        {
            wallPositionXMin = block.transform.position.x;
            //Debug.LogError("wallPositionXMin >> " + wallPositionXMin);
        }            

        if (x == (CommonDefine.MAX_BACKGROUND_WIDTH - 1))
        {
            wallPositionXMax = block.transform.position.x;
            //Debug.LogError("wallPositionXMax >> " + wallPositionXMax);
        }
            

        if (y == (CommonDefine.MAX_BACKGROUND_HEIGHT - 1))
        {
            wallPositionY = block.transform.position.y;
            //Debug.LogError("wallPositionY >> " + wallPositionY);
        }
            

    }
    
	
	// Update is called once per frame
	void Update () {
        
		
	}
}
