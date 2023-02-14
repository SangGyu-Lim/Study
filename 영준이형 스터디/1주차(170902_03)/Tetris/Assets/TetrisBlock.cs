using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TetrisBlock : MonoBehaviour {
        
    float currentMoveTime = 0.0f;

    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
               

        currentMoveTime += Time.deltaTime;
        if(currentMoveTime >= CommonDefine.DEFAULT_MOVE_TIME)
        {
            MoveVertical();
            currentMoveTime = 0.0f;
        }          
        

    }

    public void Rotate()
    {
        transform.Rotate(new Vector3(0f, 0f, 1f), 90.0f);
    }

    public void MoveHorizontal(Vector2 direction)
    {
        float moveDistance = CommonDefine.BLOCK_SIZE;
        float deltaMovement = (direction.Equals(Vector2.right)) ? moveDistance : -moveDistance;

        transform.localPosition += new Vector3(deltaMovement, 0, 0);
    }

    public void MoveVertical()
    {
        float moveDistance = CommonDefine.BLOCK_SIZE;

        transform.localPosition -= new Vector3(0, moveDistance, 0);
    }
}
