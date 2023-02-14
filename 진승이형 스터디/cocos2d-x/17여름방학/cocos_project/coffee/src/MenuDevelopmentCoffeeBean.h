#ifndef __MENU_DEVELOPMENT_COFFEE_BEAN_H__
#define __MENU_DEVELOPMENT_COFFEE_BEAN_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class MenuDevelopmentCoffeeBean : public cocos2d::Sprite
{

private:
	int prevRadioIndex;

public:

	enum eINDEX_MD_COFFEE_BEAN
	{
		BASIC = 0,
		TAG_RADIO_GROUP_COFFEE_MACHINE = 350
	};

	static cocos2d::Sprite* createSprite();

	virtual bool init();

	void InitMenuDevelopmentCoffeeBean();

	CREATE_FUNC(MenuDevelopmentCoffeeBean);

	
	void CallbackRadioButtonGroup(cocos2d::ui::RadioButton* pRadioButton, int index);
};

#endif // __MENU_DEVELOPMENT_COFFEE_BEAN_H__
