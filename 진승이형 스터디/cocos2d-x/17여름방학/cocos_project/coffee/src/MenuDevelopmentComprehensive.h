#ifndef __MENU_DEVELOPMENT_COMPREHENSIVE_H__
#define __MENU_DEVELOPMENT_COMPREHENSIVE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#define FILE_DATA_BASIC	9

class MenuDevelopmentComprehensive : public cocos2d::Sprite
{

private:
	

public:

	enum eTAG_COMPREHENSIVE
	{
		COFFEE_NAME = 500,
		SYRUP,
		COFFEE_BEAN,
		MILK,
		ICE
	};

	


	static cocos2d::Sprite* createSprite();

	virtual bool init();
	
	void InitMenuDevelopmentComprehensive();

	CREATE_FUNC(MenuDevelopmentComprehensive);

	void SetMenuDevelopmentComprehensive(char* coffeeNameString, int syrupAmount, char* coffeeBeanString, char* milkString, char* IceString);

};

#endif // __MENU_DEVELOPMENT_COMPREHENSIVE_H__
