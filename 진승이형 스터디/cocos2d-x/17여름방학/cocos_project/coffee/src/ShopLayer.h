#ifndef __SHOP_LAYER_H__
#define __SHOP_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#define PRODUCT_TYPE 3
#define PRODUCT_COUNT 3

class ShopLayer : public cocos2d::LayerColor
{
public:

	enum eDEPTH_ORDER_SHOP
	{
		PAGE_VIEW = 0,
		SPRITE_BACKGROUND,
		SPRITE_UI,
		MENU,
		MENU_ITEM
	};

	enum eTAG_PRODUCT
	{
		COFFEE_BEAN_NORMAL = 100,
		COFFEE_BEAN_RARE,
		COFFEE_BEAN_HIDDEN,
		MILK_NORMAL,
		MILK_RARE,
		MILK_HIDDEN,
		ICE_NORMAL,
		ICE_RARE,
		ICE_HIDDEN
	};

	enum eINDEX_PAGE_SHOP
	{
		PAGE_COFFEE_BEAN = 0,
		PAGE_MILK,
		PAGE_ICE,
		TAG_PAGE_VIEW_SHOP = 150
	};

	static cocos2d::LayerColor* createLayer();

	cocos2d::Sprite* productSprite[PRODUCT_TYPE];

	int buyProductTag;

	// init
	virtual bool init();
	void InitShopMenu();
	void InitProduct(int index, cocos2d::Vec2 spritePosition);

	CREATE_FUNC(ShopLayer);

	void CallShopMenu(/*const cocos2d::ccMenuCallback& callback*/);
	void CallShopMenutest(const cocos2d::ccMenuCallback& callback);

	void ShopClose();

	// touch event
	cocos2d::EventListenerTouchOneByOne* listener;

	void InitTouchEvent();
	virtual bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);

	// button callback
	void CallbackShopClose(cocos2d::Ref* pSender);
	void CallbackBuyConfirm(cocos2d::Ref* pSender);
	void CallbackBuyProduct();
	void CallbackLeftArrow(cocos2d::Ref* pSender);
	void CallbackRightArrow(cocos2d::Ref* pSender);

	// exception handling
};

#endif // !__SHOP_LAYER_H__
