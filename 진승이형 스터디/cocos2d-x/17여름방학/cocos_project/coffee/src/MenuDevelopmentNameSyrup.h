#ifndef __MENU_DEVELOPMENT_NAME_SYRUP_H__
#define __MENU_DEVELOPMENT_NAME_SYRUP_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class MenuDevelopmentNameSyrup : public cocos2d::Sprite, cocos2d::ui::EditBoxDelegate
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

	cocos2d::LabelTTF* labelSyrupAmount;

	void InitMenuDevelopmentNameSyrup();

	CREATE_FUNC(MenuDevelopmentNameSyrup);

	/*void editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox);
	void editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox);
	void editBoxTextChanged(cocos2d::ui::EditBox* editBox, const std::string& text);*/
	void editBoxReturn(cocos2d::ui::EditBox* editBox);

	void CallbackSlider(cocos2d::Ref* pSender, cocos2d::ui::Slider::EventType type);
};

#endif // __MENU_DEVELOPMENT_NAME_SYRUP_H__
