#include "Mole.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Sprite* Mole::createSprite()
{
	return Mole::create();
}

bool Mole::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	SetImage("mob_0.png");




	return true;
}

void Mole::SetImage(char* imageName)
{
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* spriteMole = Sprite::create(imageName);
	if (spriteMole == NULL)
		return;
	spriteMole->setPosition(Vec2::ZERO);
	this->setDisplayFrame(spriteMole->getDisplayFrame());
}

const float moveAliveTime = 0.4f;
const float moveDieTime = 1.0f;
const float showDelayTime = 1.5f;
const float dieDelayTime1 = 0.15f;
const float dieDelayTime2 = 0.35f;
void Mole::ActionShow()
{
	SetState(eSTATE_MOLE::SHOW);

	MoveBy* move = MoveBy::create(moveAliveTime, Vec2(0.0f, this->getContentSize().height * 4 / 7));
	DelayTime* delay = DelayTime::create(showDelayTime);
	CallFunc* callback = CallFunc::create(CC_CALLBACK_0(Mole::ActionTimeout, this));

	Sequence* seq = Sequence::create(move, delay, callback, NULL);
	this->runAction(seq);
}

void Mole::ActionDie()
{
	SetState(eSTATE_MOLE::DIE);
	ActionStop();

	DelayTime* delay1 = DelayTime::create(dieDelayTime1);
	CallFunc* callback1 = CallFunc::create(CC_CALLBACK_0(Mole::CallbackSetDieImage, this));
	DelayTime* delay2 = DelayTime::create(dieDelayTime1);
	//MoveBy* move = MoveBy::create(1, Vec2(0.0f, -(this->getContentSize().height * 2 / 3)));
	MoveTo* move = MoveTo::create(moveDieTime, hidePosition);
	CallFunc* callback2 = CallFunc::create(CC_CALLBACK_0(Mole::CallbackDie, this));

	Sequence* seq = Sequence::create(delay1, callback1, delay2, move, callback2, NULL);
	this->runAction(seq);

}

void Mole::ActionTimeout()
{
	//MoveBy* move = MoveBy::create(1, Vec2(0.0f, -(this->getContentSize().height * 2 / 3)));
	MoveTo* move = MoveTo::create(moveAliveTime, hidePosition);
	CallFunc* callback = CallFunc::create(CC_CALLBACK_0(Mole::CallbackTimeout, this));

	Sequence* seq = Sequence::create(move, callback, NULL);
	this->runAction(seq);
}

void Mole::ActionStop()
{
	this->stopAllActions();
}

void Mole::CallbackDie()
{
	SetState(eSTATE_MOLE::IDLE);
	SetImage("mob_0.png");
}

void Mole::CallbackSetDieImage()
{
	SetImage("mob_1.png");
}

void Mole::CallbackTimeout()
{
	SetState(eSTATE_MOLE::IDLE);
}



/* mole 자체 스케쥴링 */
//void Mole::ActionSchedule(float scheduleTime)
//{
//	this->schedule(schedule_selector(Mole::CallbackSchedule), (scheduleTime + showDelayTime));
//}
//
//void Mole::CallbackSchedule(float time)
//{
//	if (GetState() == eSTATE_MOLE::IDLE)
//	{
//		ActionShow();
//	}
//}
