using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using UnityStandardAssets.CrossPlatformInput;

public class goblin : MonoBehaviour {
	
	public enum STATE
	{
		STAND,
		MOVE,
        ATTACK
	}

    private STATE state = STATE.STAND;	

	public Animation modelAnimation;

    const int beginLevel = 1;
    const int beginAttackPower = 10;
    const float beginSpeed = 3f;

    public int level = 1;
    public int attackPower = 10;
    public int exp = 0;
    public float speed = 5f;

    float horizontal;
    float vertical;
    float backHorizontal;
    float backVertical;

    Vector3 moveDir;
    Vector3 backDir;

    public bool isCollision = false;
    public bool isContinue = true;

    public TextMesh levelTextMesh;

    




	// Use this for initialization
	void Start () {
        Play("idle", true);

        level = beginLevel;
        attackPower = beginAttackPower;
        speed = beginSpeed;
	}
	
	// Update is called once per frame
	void Update () {

        if (isContinue)
        {
            // move
            horizontal = CrossPlatformInputManager.GetAxisRaw("Horizontal");
            vertical = CrossPlatformInputManager.GetAxisRaw("Vertical");

            bool isDrag = true;
            if (horizontal == 0f && vertical == 0f)
                isDrag = false;

            moveDir = new Vector3(-horizontal, 0.0f, -vertical);







            if (!isCollision)
            {
                if (isDrag == false)
                {
                    if (state != STATE.STAND)
                    {
                        state = STATE.STAND;
                        changeAnimation();
                    }
                }
                else
                {
                    if (state != STATE.MOVE)
                    {
                        state = STATE.MOVE;
                        changeAnimation();
                    }
                }

                switch (state)
                {
                    case STATE.STAND:
                        {
                            transform.rotation = Quaternion.LookRotation(moveDir);

                        }
                        break;
                    case STATE.MOVE:
                        {
                            this.gameObject.transform.Translate(moveDir.normalized * Time.deltaTime * speed);
                            this.transform.GetChild(0).transform.rotation = Quaternion.LookRotation(moveDir);
                        }
                        break;
                }
            }
            else
            {
                if (state != STATE.ATTACK)
                {
                    state = STATE.ATTACK;
                    changeAnimation();
                }

                //this.gameObject.transform.Translate(-backDir.normalized * Time.deltaTime * speed);
            }

            // rotation
            //transform.rotation = Quaternion.Euler(new Vector3(moveDir.normalized.x, 0.0f, moveDir.normalized.z));
            //this.gameObject.transform.rotation = Quaternion.LookRotation(moveDir);
        }
		
        

	}

    // 애니메이션 실행
	public AnimationState Play(string animName, bool isLoop)
	{
		if (animName.Length <= 0) {
			Debug.Log ("Animation Name's Lenght is 0");
			return null;
		}

		Animation anim = modelAnimation;
		if (anim == null) {
			Debug.Log ("Play() : I don't have " + animName + " animation");
			return null;
		}

		AnimationState animState = anim [animName];

		anim.Stop ();
		anim.Play (animName);
		anim [animName].speed = 1f;
		anim [animName].time = 0f;

		if (isLoop == true)
			animState.wrapMode = WrapMode.Loop;
		else
			animState.wrapMode = WrapMode.Once;

		return animState;
	}

	// 고블린 상태 애니메이션 변경
	void changeAnimation()
	{
		//if (state == s)
		//	return;
		// 수정해요.
		
		switch (state) {
            case STATE.STAND:
			{
				Play ("idle", true);
			}
			break;
            case STATE.MOVE:
			{
				Play ("run", true);
			}
			break;
            case STATE.ATTACK:
            {
                Play("attack3", false);
            }
            break;
		}
	}

    // 충돌 체크
    void OnCollisionEnter(Collision col)
    {
        Debug.Log("OnCollisionEnter goblin");
        isCollision = true;

        // 뒤로 빠질 위치 계산
        backHorizontal = horizontal;
        backVertical = vertical;

        backDir = new Vector3(-backHorizontal, 0.0f, -backVertical);

        StartCoroutine(MoveBack());
        
        //if (col.name.ToString() == "snake(Clone)")

        //for (int i = 0; i < 50; i++ )
        //    this.gameObject.transform.Translate(-moveDir.normalized * Time.deltaTime * speed);

    }

    // 뒤로 빠지게
    private IEnumerator MoveBack()
    {
        yield return new WaitForSeconds(1.0f);

        isCollision = false;
    }

    public Vector3 getBackDir()
    {
        return backDir;
    }


    // 고블린 정보 최신화
    public void updateGoblinInformation()
    {
        //축제 전까지

        //필드 존재
        //몬스터 생성
        //부딪히면 공격이 되고(공격 애니메이션) 
        //몬스터는 맞는 애니메이션이 나온다.

        //플레이어는 레벨, 공격력, exp, speed 가지고 있다.
        //몬스터는 레벨, HP, 방어력, exp 가지고 있다.

        //Limit 시간 : 60초

        //레벨 1, 공격력 10, 경험치 0, speed 10 으로 시작.
        //exp -> 10이 되면 레벨 +1
        //레벨 +1 되면 atk +2, speed + 10 된다.

        //슬라임의 hp = 50, 레벨 1, exp 2; 레벨이 오를수록 exp+2;
        //필드에 생성된 슬라임(5마리가 최대)을 모두 잡으면
        //레벨이 1 올라간 슬라임이 5마리 생성.

        //스코어 = > exp *10;

        //하이스코어 표시 등...

        level = beginLevel + (exp / 10);
        levelTextMesh.text = "Lv : " + level.ToString();
        attackPower = beginAttackPower + (level - 1) * 2;
        speed = beginSpeed + (level - 1) * 1;
    }
}

