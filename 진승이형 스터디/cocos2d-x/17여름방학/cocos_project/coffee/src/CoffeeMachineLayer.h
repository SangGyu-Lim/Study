#ifndef __COFFEE_MACHINE_LAYER_H__
#define __COFFEE_MACHINE_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "MenuDevelopmentNameSyrup.h"
#include "MenuDevelopmentCoffeeBean.h"
#include "MenuDevelopmentIce.h"
#include "MenuDevelopmentMlik.h"
#include "MenuDevelopmentSalePrice.h"
#include "MenuDevelopmentComprehensive.h"

#define MD_MAX_LABEL_COUNT	5



class CoffeeMachineLayer : public cocos2d::LayerColor
{
public:

	enum eDEPTH_ORDER_COFFEE_MACHINE
	{
		LABEL = 20,
		PAGE_VIEW,
		SPRITE_BACKGROUND,
		SPRITE_UI,
		MENU,
		MENU_ITEM

	};

	enum eINDEX_PAGE_COFFEE_MACHINE
	{
		PAGE_MD_NAME_SYRUP = 0,
		PAGE_MD_COFFEE_BEAN,
		PAGE_MD_MILK,
		PAGE_MD_ICE,
		PAGE_MD_SALE_PRICE,
		PAGE_MD_COMPREHENSIVE,
		PAGE_MD_MAX,
		TAG_PAGE_VIEW_COFFEE_MACHINE = 300
	};

	static cocos2d::LayerColor* createLayer();
	
	// init
	virtual bool init();

	MenuDevelopmentNameSyrup*		menuDevelopmentNameSyrup;
	MenuDevelopmentCoffeeBean*		menuDevelopmentCoffeeBean;
	MenuDevelopmentIce*				menuDevelopmentIce;
	MenuDevelopmentMlik*			menuDevelopmentMlik;
	MenuDevelopmentSalePrice*		menuDevelopmentSalePrice;
	MenuDevelopmentComprehensive*	menuDevelopmentComprehensive;

	cocos2d::LabelTTF* menuDevelopmentNeedLabel[MD_MAX_LABEL_COUNT];
	int currentLabelCount = 0;
	int makePrice = 0;

	void InitCoffeeMachine();
	void InitMenuDevelopment();

	CREATE_FUNC(CoffeeMachineLayer);

	// touch event
	cocos2d::EventListenerTouchOneByOne* listener;

	void InitTouchEvent();
	virtual bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);

	void CallCoffeeMachine();
	void CallMDNeedLabel();
	void MDNeedLabelRunAction(int index);
	void CallbackMDNeedLabelActiveFalse(int index);

	void CoffeeMachineClose();

	// call back	
	void CallbackCoffeeMachineClose(cocos2d::Ref* pSender);
	void CallbackLeftArrow(cocos2d::Ref* pSender);
	void CallbackRightArrow(cocos2d::Ref* pSender);

	void CallbackBuyMenuDevelopment();

	void SetMenuDevelopmentComprehensive();

	char* GetCoffeeBeanStringByIndex(int labelStringIndex);
	char* GetMlikStringByIndex(int labelStringIndex);
	char* GetIceStringByIndex(int labelStringIndex);
	
	int GetMenuDevelopmentPrice();
	

};

#endif // !__COFFEE_MACHINE_LAYER_H__
