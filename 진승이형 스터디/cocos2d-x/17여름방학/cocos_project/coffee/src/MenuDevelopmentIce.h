#ifndef __MENU_DEVELOPMENT_ICE_H__
#define __MENU_DEVELOPMENT_ICE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class MenuDevelopmentIce : public cocos2d::Sprite
{

private:
	int prevRadioIndex;

public:

	enum eINDEX_MD_ICE
	{
		BASIC = 0,
		TAG_PAGE_VIEW_ICE = 450
	};

	static cocos2d::Sprite* createSprite();

	virtual bool init();

	void InitMenuDevelopmentIce();

	CREATE_FUNC(MenuDevelopmentIce);


	void CallbackRadioButtonGroup(cocos2d::ui::RadioButton* pRadioButton, int index);
};

#endif // __MENU_DEVELOPMENT_ICE_H__
