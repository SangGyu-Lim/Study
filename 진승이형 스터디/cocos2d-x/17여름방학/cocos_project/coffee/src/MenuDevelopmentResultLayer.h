#ifndef __MENU_DEVELOPMENT_RESULT_LAYER_H__
#define __MENU_DEVELOPMENT_RESULT_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class MenuDevelopmentResultLayer : public cocos2d::LayerColor
{
public:
	
	enum eDEPTH_ORDER_MD_RESULT
	{
		SPRITE_BACKGROUND = 0,
		SPRITE_UI,
		LABEL,
		MENU,
		MENU_ITEM
	};

	enum eTAG_MD_RESULT
	{
		LABEL_COFFEE_NAME = 650,
		LABEL_POPULARITY
	};

	static cocos2d::LayerColor* createLayer();


	// init
	virtual bool init();

	void InitMenuDevelopmentResultLayer();

	CREATE_FUNC(MenuDevelopmentResultLayer);

	// touch event
	cocos2d::EventListenerTouchOneByOne* listener;

	void InitTouchEvent();
	virtual bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);

	void CallMenuDevelopmentResult();
	float GetMenuDevelopmentPopularity();

	// call back
	void CallbackMenuDevelopmentResultClose(cocos2d::Ref* pSender);

};

#endif // !__MENU_DEVELOPMENT_RESULT_LAYER_H__
