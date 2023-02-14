#ifndef __MENU_DEVELOPMENT_MLIK_H__
#define __MENU_DEVELOPMENT_MLIK_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class MenuDevelopmentMlik : public cocos2d::Sprite
{

private:
	int prevRadioIndex;

public:

	enum eINDEX_MD_MILK
	{
		BASIC = 0,
		TAG_PAGE_VIEW_MILK = 400
	};

	static cocos2d::Sprite* createSprite();

	virtual bool init();

	void InitMenuDevelopmentMlik();

	CREATE_FUNC(MenuDevelopmentMlik);


	void CallbackRadioButtonGroup(cocos2d::ui::RadioButton* pRadioButton, int index);
};

#endif // __MENU_DEVELOPMENT_MLIK_H__
