using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TetrisBlock : MonoBehaviour
{

    public BLOCK_TYPE blockType;
    public bool isRotate = false;

    public bool isMove = false;

    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }

    public void Rotate()
    {
        // 네모 블럭 회전 금지
        if (blockType == BLOCK_TYPE.O)
            return;

        float angle = 90.0f;
        float rotateAngle = 0.0f;

        //T,L,J
        if ((blockType == BLOCK_TYPE.T) || (blockType == BLOCK_TYPE.L) || (blockType == BLOCK_TYPE.J))
            rotateAngle = angle;

        //I,S,Z
        if ((blockType == BLOCK_TYPE.I) || (blockType == BLOCK_TYPE.S) || (blockType == BLOCK_TYPE.Z))
        {
            rotateAngle = isRotate ? -angle : angle;
            isRotate = !isRotate;
        }

        transform.Rotate(Vector3.forward, rotateAngle);

        if (IsValidNextPosition(MOVE_ARROW.ROTATE) == false)
        {
            // 벽 충돌시 동작 안함.
            transform.Rotate(Vector3.forward, -rotateAngle);

            // 벽 충돌시 벽과 멀어진다음 회전
            //MoveAndRotate();
        }
    }    

    void MoveAndRotate()
    {
        bool isValid = false;

        while (isValid == false)
        {

            //UISprite[] sprite = this.GetComponentsInChildren<UISprite>();
            Transform[] childTransforms = this.GetComponentsInChildren<Transform>();

            //for (int i = 0; i < sprite.Length; ++i)
            for (int i = 0; i < childTransforms.Length; ++i)
            {
                //MOVE_ARROW crashType = GameManager.Instance.CrashDirection(sprite[i].transform.position);
                MOVE_ARROW crashType = GameManager.Instance.CrashDirection(DeleteGarbagePosition(childTransforms[i].position.x), DeleteGarbagePosition(childTransforms[i].position.y));

                if (crashType == MOVE_ARROW.LEFT)
                {
                    MoveHorizontal(Vector2.right);
                    break;
                }

                if (crashType == MOVE_ARROW.RIGHT)
                {
                    MoveHorizontal(Vector2.left);
                    break;
                }

            }

            isValid = IsValidNextPosition(MOVE_ARROW.ROTATE);
        }

    }

    public void MoveHorizontal(Vector2 direction)
    {
        float moveDistance = CommonDefine.BLOCK_SIZE;
        float deltaMovement = (direction.Equals(Vector2.right)) ? moveDistance : -moveDistance;

        transform.localPosition += new Vector3(deltaMovement, 0, 0);

        MOVE_ARROW type = (direction.Equals(Vector2.right)) ? MOVE_ARROW.RIGHT : MOVE_ARROW.LEFT;

        if (IsValidNextPosition(type) == false)
        {
            transform.localPosition -= new Vector3(deltaMovement, 0, 0);
        }
    }

    public void MoveFall()
    {
        float moveDistance = CommonDefine.BLOCK_SIZE;

        transform.localPosition -= new Vector3(0, moveDistance, 0);

        if (IsValidNextPosition(MOVE_ARROW.DOWN) == false)
        {
            transform.localPosition += new Vector3(0, moveDistance, 0);
            isMove = false;
        }
    }

    bool IsValidNextPosition(MOVE_ARROW type)
    {
        bool isValid = true;
        
        //UISprite[] sprite = this.GetComponentsInChildren<UISprite>();
        Transform[] childTransforms = this.GetComponentsInChildren<Transform>();

        //for (int i = 0; i < sprite.Length; ++i)
        for (int i = 1; i < childTransforms.Length; ++i)
        {
            //isValid = GameManager.Instance.IsValidNextPosition(type, sprite[i].transform.position);
            isValid = GameManager.Instance.IsValidNextPosition(type, DeleteGarbagePosition(childTransforms[i].position.x), DeleteGarbagePosition(childTransforms[i].position.y));

            if (isValid == false)
                return isValid;
        }



        return isValid;
    }

    public void PileBlock()
    {
        
        //UISprite[] sprite = this.GetComponentsInChildren<UISprite>();
        Transform[] childTransforms = this.GetComponentsInChildren<Transform>();

        //for (int i = 0; i < sprite.Length; ++i)
        for (int i = 1; i < childTransforms.Length; ++i)
        {
            //GameManager.Instance.PileBlock(sprite[i].transform.position.x, sprite[i].transform.position.y);
            GameManager.Instance.PileBlock(DeleteGarbagePosition(childTransforms[i].position.x), DeleteGarbagePosition(childTransforms[i].position.y), i);
        }        
    }

    float DeleteGarbagePosition(float garbagePosition)
    {
        float correctPosition = Mathf.Round(garbagePosition * 10000.0f);
        correctPosition = correctPosition / 10000.0f;

        return correctPosition;
    }
}

