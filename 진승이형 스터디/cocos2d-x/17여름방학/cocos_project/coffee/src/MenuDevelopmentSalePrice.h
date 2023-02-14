#ifndef __MENU_DEVELOPMENT_SALE_PRICE_H__
#define __MENU_DEVELOPMENT_SALE_PRICE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#define	RATE_SLIDER_PRICE	200

class MenuDevelopmentSalePrice : public cocos2d::Sprite
{
public:

	enum eDEPTH_ORDER_MD_NAME_SYRUP
	{
		SPRITE_UI = 0,
		LABEL,
		EDIT_BOX,
		SLIDER
	};


	static cocos2d::Sprite* createSprite();

	virtual bool init();

	cocos2d::LabelTTF* labelSalePrice;
	int basicSalePrice;

	void InitMenuDevelopmentSalePrice();

	CREATE_FUNC(MenuDevelopmentSalePrice);

	void SetBasicSalePrice(int price);
	
	void CallbackSlider(cocos2d::Ref* pSender, cocos2d::ui::Slider::EventType type);
};

#endif // __MENU_DEVELOPMENT_SALE_PRICE_H__
