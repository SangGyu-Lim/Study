using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIBackground : MonoBehaviour {

    public UISprite spriteBlock;
    

	// Use this for initialization
	void Start () {

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
        GameObject block = GameObject.Instantiate(spriteBlock.gameObject);
        block.transform.parent = this.gameObject.transform;
        block.transform.localPosition = new Vector3(x * CommonDefine.BLOCK_SIZE - CommonDefine.MAX_BACKGROUND_WIDTH / 2 * CommonDefine.BLOCK_SIZE,
            -y * CommonDefine.BLOCK_SIZE + CommonDefine.MAX_BACKGROUND_HEIGHT / 2 * CommonDefine.BLOCK_SIZE, 0f);
        block.transform.localScale = Vector3.one;
        block.SetActive(true);
    }
    
	
	// Update is called once per frame
	void Update () {

        
		
	}
}
