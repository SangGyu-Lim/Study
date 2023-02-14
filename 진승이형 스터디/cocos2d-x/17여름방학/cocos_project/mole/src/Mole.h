#ifndef __MOLE_H__
#define __MOLE_H__

#include "cocos2d.h"

class Mole : public cocos2d::Sprite
{
public:

	enum eSTATE_MOLE
	{
		IDLE = 0,
		SHOW,
		DIE
	};

	static cocos2d::Sprite* createSprite();

	eSTATE_MOLE currentState = eSTATE_MOLE::IDLE;
	cocos2d::Vec2 hidePosition;

	void SetImage(char* imageName);

	void		SetState(eSTATE_MOLE state)	{ currentState = state; }
	eSTATE_MOLE	GetState()					{ return currentState; }
	
	void SetHidePosition(cocos2d::Vec2 position) { hidePosition = position; }

	// action
	void ActionShow();
	void ActionDie();
	void ActionTimeout();
	void ActionStop();
	

	// callback
	void CallbackDie();
	void CallbackSetDieImage();
	void CallbackTimeout();
	
	
	/* mole 자체 스케쥴링 */
	//void ActionSchedule(float scheduleTime);
	//void CallbackSchedule(float time);
	

	virtual bool init();

	CREATE_FUNC(Mole);
};

#endif // __MOLE_H__
