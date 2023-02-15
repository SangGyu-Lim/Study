using UnityEngine;
using System.Collections;

public class monster : MonoBehaviour {

	public enum STATE
	{
		NONE,
		STAND,
		MOVE
	}

	public STATE state = STATE.NONE;

	const float RANGE_MAX = 5.0F;
	const float RANGE_MIN = -5.0F;
	const float speed = 1f;

	private float currrentChangeStateTime = 0f;
	float horizontal = 0f;
	float vertical = 0f;

	public Animation modelAnimation;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
		currrentChangeStateTime -= Time.deltaTime;
		if (currrentChangeStateTime <= 0f) {
			int s = Random.Range ((int)STATE.STAND, (int)STATE.MOVE + 1);
			setState ((STATE)s);
		}
			
		Vector3 moveDir = new Vector3 (-horizontal, 0.0f, -vertical);

		switch (state) {
		case STATE.STAND:
			{				
				transform.rotation = Quaternion.LookRotation (moveDir);
			}
			break;
		case STATE.MOVE:
			{				
				this.gameObject.transform.Translate (moveDir.normalized * Time.deltaTime * speed);
				this.transform.GetChild(0).transform.rotation = Quaternion.LookRotation(moveDir);
			}
			break;
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
				horizontal = 0f;
				vertical = 0f;
				Play ("Idle", true);
			}
			break;
		case STATE.MOVE:
			{
				horizontal = Random.Range (RANGE_MIN, RANGE_MAX);
				vertical = Random.Range (RANGE_MIN, RANGE_MAX);
				Play ("Walk", true);
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
}
