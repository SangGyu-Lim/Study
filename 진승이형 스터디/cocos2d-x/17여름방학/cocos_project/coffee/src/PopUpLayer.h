#ifndef __POP_UP_LAYER_H__
#define __POP_UP_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class PopUpLayer : public cocos2d::LayerColor
{
public:

	enum eDEPTH_ORDER_POP_UP
	{
		SPRITE_BACKGROUND = 0,
		LABEL,
		MENU,
		MENU_ITEM
	};

	enum eTAG_POP_UP
	{
		LABEL_TITLE = 600,
		LABEL_CONTENT,
		MENU_ONE_BUTTON,
		MENU_TWO_BUTTON,
	};

	static cocos2d::LayerColor* createLayer();
	
	// init
	virtual bool init();
	void InitPopUp();

	CREATE_FUNC(PopUpLayer);
	
	// touch event
	cocos2d::EventListenerTouchOneByOne* listener;

	cocos2d::ccMenuCallback _callbackOKButton;

	void InitTouchEvent();
	virtual bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);

	void CallPopUpOneButton(char* titleString, char* contentString);
	void CallPopUpTwoButton(char* titleString, char* contentString, const cocos2d::ccMenuCallback& callbackOKButton);
	void ClosePopUp();

	void SetPopUpLabel(char* titleString, char* contentString);

	// callback
	void CallbackOK(cocos2d::Ref* pSender);
	void CallbackNO(cocos2d::Ref* pSender);

};

#endif // !__POP_UP_LAYER_H__
