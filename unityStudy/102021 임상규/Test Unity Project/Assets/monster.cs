using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class monster : MonoBehaviour {

	public enum STATE
	{
		NONE,
		STAND,
		MOVE,
        DEFENSE
	}

	public STATE state = STATE.NONE;

    const float MOVE_RANGE_MIN = -5.0F;
	const float MOVE_RANGE_MAX = 5.0F;
    const float RANGE_MIN = -10.0F;
    const float RANGE_MAX = 10.0F;

    Vector3 moveDir;
    public Vector3 backDir;

	const float speed = 1f;

	private float currrentChangeStateTime = 0f;
	float horizontal = 0f;
	float vertical = 0f;

	public Animation modelAnimation;

    public int level = 1;
    public int hp = 50;
    public TextMesh hpTextMesh;
    public int exp = 2;

    bool isCollision = false;
    public bool collisionOnceCheck = false;
    bool isRangeOver = false;

    public bool isContinue = true;

	// Use this for initialization
    void Start() {

    }
	
	// Update is called once per frame
	void Update () {

        if (isContinue)
        {
            currrentChangeStateTime -= Time.deltaTime;
            if (currrentChangeStateTime <= 0f)
            {
                int s = Random.Range((int)STATE.STAND, (int)STATE.MOVE + 1);
                setState((STATE)s);
                isRangeOver = false;
            }

            moveDir = new Vector3(-horizontal, 0.0f, -vertical);

            if (this.gameObject.transform.position.x >= RANGE_MAX || this.gameObject.transform.position.x <= RANGE_MIN
                || this.gameObject.transform.position.z >= RANGE_MAX || this.gameObject.transform.position.z <= RANGE_MIN)
            {
                isRangeOver = true;
            }

            if (!isCollision)
            {
                switch (state)
                {
                    case STATE.MOVE:
                        {
                            if (isRangeOver)
                            {
                                this.gameObject.transform.Translate(-moveDir.normalized * Time.deltaTime * speed);
                                this.transform.GetChild(0).transform.rotation = Quaternion.LookRotation(-moveDir);
                            }
                            else
                            {
                                this.gameObject.transform.Translate(moveDir.normalized * Time.deltaTime * speed);
                                this.transform.GetChild(0).transform.rotation = Quaternion.LookRotation(moveDir);
                            }


                        }
                        break;
                }
            }
            else
            {
                if (state != STATE.DEFENSE)
                {
                    setState(STATE.DEFENSE);
                    
                }

                if (isRangeOver)
                {
                    this.gameObject.transform.Translate(-backDir.normalized * Time.deltaTime * speed);
                    this.transform.GetChild(0).transform.rotation = Quaternion.LookRotation(-moveDir);
                }
                else
                {
                    this.gameObject.transform.Translate(backDir.normalized * Time.deltaTime * speed);
                    this.transform.GetChild(0).transform.rotation = Quaternion.LookRotation(moveDir);
                }
                
            }
        }

        
		

        
	}

	void setState(STATE s)
	{
		if (state == s)
			return;

		currrentChangeStateTime = Random.Range (1.5f, 3f);

		switch (s) {
		case STATE.STAND:
			{
                if (isRangeOver)
                {
                    this.transform.GetChild(0).transform.rotation = Quaternion.LookRotation(-moveDir);
                }
                else
                {
                    this.transform.GetChild(0).transform.rotation = Quaternion.LookRotation(moveDir);
                }
				Play ("Idle", true);
			}
			break;
		case STATE.MOVE:
			{
                horizontal = Random.Range(MOVE_RANGE_MIN, MOVE_RANGE_MAX);
                vertical = Random.Range(MOVE_RANGE_MIN, MOVE_RANGE_MAX);
				Play ("Walk", true);
			}
			break;
        case STATE.DEFENSE:
            {
                Play("Ithcing", false);
            }
            break;
		}

		state = s;

	}

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

    // 충돌 체크
    void OnCollisionEnter(Collision col)
    {
        isCollision = true;
        collisionOnceCheck = true;

        // 뒤로 빠질 위치 계산
        StartCoroutine(MoveBack());

        Debug.Log("OnCollisionEnter monster : " + isCollision.ToString());
        //GameObject.Destroy(this.gameObject);
    }

    private IEnumerator MoveBack()
    {
        yield return new WaitForSeconds(1.0f);

        isCollision = false;
    }    

    public void updateMonsetrInformation()
    {
        level++;
        exp += 2;
    }
}
