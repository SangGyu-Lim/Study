using UnityEngine;
using System.Collections;
using UnityStandardAssets.CrossPlatformInput;

public class goblin : MonoBehaviour {
	
	public enum State
	{
		STAND,
		MOVE
	}

	private State state = State.STAND;

	const float speed = 1f;

	public Animation modelAnimation;

	// Use this for initialization
	void Start () {
		Play ("remove_weapons", true);
	}
	
	// Update is called once per frame
	void Update () {

		// move
		float horizontal = CrossPlatformInputManager.GetAxisRaw("Horizontal");
		float vertical = CrossPlatformInputManager.GetAxisRaw("Vertical");

		bool isDrag = true;
		if (horizontal == 0f && vertical == 0f)
			isDrag = false;

		Vector3 moveDir = new Vector3 (-horizontal, 0.0f, -vertical);

		//Vector3 rotDir = new Vector3 (horizontal, 0f, vertical);
		//if (isDrag == true)
		//	transform.rotation = Quaternion.LookRotation (moveDir);



		if (isDrag == false) {
			if (state != State.STAND) {
				state = State.STAND;
				changeAnimation ();
			}
		} else {
			if (state != State.MOVE) {
				state = State.MOVE;
				changeAnimation ();
			}
		}

		//Vector3 moveDir = new Vector3 (horizontal, 0.0f, vertical);


		this.gameObject.transform.Translate (moveDir.normalized * Time.deltaTime * speed);

		// rotation
		//transform.rotation = Quaternion.Euler(new Vector3(moveDir.normalized.x, 0.0f, moveDir.normalized.z));
		//this.gameObject.transform.rotation = Quaternion.LookRotation(moveDir);
		this.transform.GetChild(0).transform.rotation = Quaternion.LookRotation(moveDir);



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

	//void changeAnimation(State s)
	void changeAnimation()
	{
		//if (state == s)
		//	return;
		// 수정해요.
		
		switch (state) {
		case State.STAND:
			{
				Play ("idle", true);
			}
			break;

		case State.MOVE:
			{
				Play ("run", true);
			}
			break;
		}
	}
}
