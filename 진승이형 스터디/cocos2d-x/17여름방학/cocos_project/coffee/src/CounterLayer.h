#ifndef __COUNTER_LAYER_H__
#define __COUNTER_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class CounterLayer : public cocos2d::LayerColor
{
public:

	enum eDEPTH_ORDER_COUNTER
	{
		PAGE_VIEW = 0,
		SPRITE_BACKGROUND,
		SPRITE_UI,
		MENU,
		MENU_ITEM
	};

	enum eINDEX_PAGE_COUNTER
	{
		PAGE_MONTH = 0,
		PAGE_TOTAL,
		TAG_PAGE_VIEW_COUNTER = 250
	};

	static cocos2d::LayerColor* createLayer();

	
	// init
	virtual bool init();

	void InitCounter();
	
	CREATE_FUNC(CounterLayer);

	// touch event
	cocos2d::EventListenerTouchOneByOne* listener;

	void InitTouchEvent();
	virtual bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);

	void CallCounter();

	// call back
	void CallbackLeftArrow(cocos2d::Ref* pSender);
	void CallbackRightArrow(cocos2d::Ref* pSender);
	void CallbackCounterClose(cocos2d::Ref* pSender);
	
};

#endif // !__COUNTER_LAYER_H__
