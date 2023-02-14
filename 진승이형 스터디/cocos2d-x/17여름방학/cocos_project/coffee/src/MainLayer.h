#ifndef __MAIN_LAYER_H__
#define __MAIN_LAYER_H__

#include "cocos2d.h"

class MainLayer : public cocos2d::LayerColor
{
public:

	enum eDEPTH_ORDER_LOBBY
	{
		SPRITE_BACKGROUND = 0,
		LAYER_BACKGROUND,
		SPRITE_UI,
		PROGRESS_TIMER,
		MENU,
		MENU_ITEM_BACK,
		MENU_ITEM_FRONT,
		SPRITE_CUSTOMER,
		LAYER_POPUP		
	};

	enum  eTAG_LOBBY
	{
		MENU_MAIN = 0,
		MENU_ITEM_SHOP,
		SPRITE_SHOP_BACKGROUND,		
		PROGRESS_TIMER_SHOP_LOADING_BAR,
		MENU_ITEM_COFFEE_MACHINE,
		SPRITE_COFFEE_MACHINE_BACKGROUND,
		PROGRESS_TIMER_COFFEE_MACHINE_LOADING_BAR,
	};

	static cocos2d::LayerColor* createLayer();

	

	virtual bool init();

	CREATE_FUNC(MainLayer);

	// init
	void InitMain();
	void InitLoadingBar();

	void InitTouchEvent();

	virtual bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);

	// button callback
	void CallbackCoffeeMachine(cocos2d::Ref* pSender);
	void CallbackShop(cocos2d::Ref* pSender);
	void CallbackCounter(cocos2d::Ref* pSender);

	void CallShopBuyProduct(int index);
	void CallbackCompleteShopBuyProduct(int index);
	void CallCoffeeMachineBuyMenuDevelopment();
	void CallbackCompleteCoffeeMachineBuyMenuDevelopment();

	//public delegate void cald();

	cocos2d::Sprite* animationSprite;

	void CallCustomer();
	void SetCustomerAnimation();
	void CallBackCustomerMoveToCounter();
	void CallBackCustomerMoveToHome();

};

#endif // !__MAIN_LAYER_H__
