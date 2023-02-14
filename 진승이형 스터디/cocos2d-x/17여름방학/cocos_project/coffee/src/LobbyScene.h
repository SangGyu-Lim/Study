#ifndef __LOBBY_SCENE_H__
#define __LOBBY_SCENE_H__

#include "cocos2d.h"
#include "MainLayer.h"
#include "TopLayer.h"
#include "BottomLayer.h"
#include "ShopLayer.h"
#include "CounterLayer.h"
#include "CoffeeMachineLayer.h"
#include "PopUpLayer.h"
#include "MenuDevelopmentResultLayer.h"

class Lobby : public cocos2d::Scene
{
public:

	enum eDEPTH_ORDER_LOBBY
	{
		SPRITE_BACKGROUND = 0,
		LAYER_BACKGROUND_BACK,
		LAYER_BACKGROUND_FRONT,
		SPRITE_UI,
		PROGRESS_TIMER,
		MENU,
		MENU_ITEM_BACK,
		MENU_ITEM_FRONT,
		LAYER_POPUP_BACK,
		LAYER_POPUP_FRONT,
		TUTORIAL
	};


	static cocos2d::Scene* createScene();
	
	// layer
	MainLayer* mainLayer;
	TopLayer* topLayer;
	BottomLayer* bottomLayer;
	ShopLayer* shopLayer;
	CounterLayer* counterLayer;
	CoffeeMachineLayer* coffeeMachineLayer;
	PopUpLayer* popUpLayer;
	MenuDevelopmentResultLayer* menuDevelopmentResultLayer;

	virtual bool init();

	CREATE_FUNC(Lobby);

	// init
	void InitSingleton();
	void InitLayer();
	void InitMainLayer();
	void InitTopLayer();
	void InitBottomLayer();
	void InitShopLayer();
	void InitCounterLayer();
	void InitCoffeeMachineLayer();
	void InitPopUpLayer();
	void InitMenuDevelopmentResultLayer();

	void InitTouchEvent();

	virtual bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
		
	bool isMenuDevelopment = false;

	/* scene 스케쥴링 */
	long survivalDayTimer;
	
	

	void InitTimer();
	virtual void update(float f);
	long GetTime();

	// tutorial
	bool doTutorial = false;
	bool endTutorial = false;

	void StartTutorial();
	void EndTutorial();

	// call layer
	void CallShop();
	void CallCounter();
	void CallCoffeeMachine();
	void CallPopUpOneButton(char* titleString, char* contentString);
	void CallPopUpTwoButton(char* titleString, char* contentString, const cocos2d::ccMenuCallback& callbackOKButton);
	void CallShopBuyProduct(int index);
	void CallCoffeeMachineBuyMenuDevelopment();
	
	void CallCoffeeMachineMDNeedLabel();
	void CallAddMenu();

	
	void test();
	//public delegate void cald();

};

#endif // !__LOBBY_SCENE_H__
