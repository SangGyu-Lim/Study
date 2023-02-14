#ifndef __TUTORIAL_LAYER_H__
#define __TUTORIAL_LAYER_H__

#include "cocos2d.h"

class TutorialLayer : public cocos2d::LayerColor
{
public:

	enum eDEPTH_ORDER_TUTORIAL
	{
		MENU = 0,
		MENU_ITEM_TUTORIAL,
		MENU_SKIP,
		MENU_ITEM_SKIP

	};
	enum eTAG_TUTORIAL
	{
		BEGIN = 700,
		TOP,
		BOTTOM,
		COFFEE_MACHINE,
		SHOP,
		COUNTER,
		END,
		TUTORIAL_MENU_ITEM
	};


	static cocos2d::LayerColor* createLayer();

	// init
	virtual bool init();
	void InitTutorial();
	void StartTutorial(const cocos2d::ccMenuCallback& callbackTutorialEnd);
	void NextTutorial();

	int currentTutorial = 0;

	CREATE_FUNC(TutorialLayer);

	// touch event
	cocos2d::EventListenerTouchOneByOne* listener;

	cocos2d::ccMenuCallback _callbackTutorialEnd;

	void InitTouchEvent();
	virtual bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);

	// callback
	void CallbackTutorial(cocos2d::Ref* pSender);
	void CallbackTutorialSkip(cocos2d::Ref* pSender);

};

#endif // !__TUTORIAL_LAYER_H__
