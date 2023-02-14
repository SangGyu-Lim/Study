#include "MenuDevelopmentCoffeeBean.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"

USING_NS_CC;
using namespace cocos2d::ui;

Sprite* MenuDevelopmentCoffeeBean::createSprite()
{
	return MenuDevelopmentCoffeeBean::create();
}

bool MenuDevelopmentCoffeeBean::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	
	prevRadioIndex = 0;
	InitMenuDevelopmentCoffeeBean();
	
	return true;
}


void MenuDevelopmentCoffeeBean::InitMenuDevelopmentCoffeeBean()
{
	auto background = Sprite::create("BackgroundCoffeeMachineMain.png");
	if (background == NULL)
		return;
	this->setDisplayFrame(background->getDisplayFrame());

	this->setPosition(Vec2(background->getContentSize().width * 0.5f,
		background->getContentSize().height * 0.5f));

	auto coffeeBean = Sprite::create("MenuDevelopmentTitleCoffeeBean.png");
	if (coffeeBean == NULL)
		return;
	coffeeBean->setAnchorPoint(Vec2(0.0f, 0.5f));
	coffeeBean->setPosition(Vec2(background->getContentSize().width * 0.05f,
		background->getContentSize().height * 0.7f));
	this->addChild(coffeeBean/*, eDEPTH_ORDER_MD_NAME_SYRUP::SPRITE_UI*/);

	auto beanRadioGroup = RadioButtonGroup::create();

	for (int i = 0; i < 4; ++i)
	{
		float vectorX = (i + 1) % 2;
		float vectorY = i / 2;

		char beanRadioNormalName[256] = { '\0', };
		sprintf(beanRadioNormalName, "CoffeeBeanRadioNormal%d.png", i);
		char beanRadioSelectedName[256] = { '\0', };
		sprintf(beanRadioSelectedName, "CoffeeBeanRadioSelected%d.png", i);

		auto beanRadio = RadioButton::create(beanRadioNormalName, beanRadioSelectedName);
		beanRadio->setAnchorPoint(Vec2(vectorX, vectorY));
		beanRadio->setPosition(Vec2(background->getContentSize().width * 0.5f,
			background->getContentSize().height * 0.3f));

		this->addChild(beanRadio);

		beanRadioGroup->addRadioButton(beanRadio);
	}
	
	beanRadioGroup->addEventListener(CC_CALLBACK_2(MenuDevelopmentCoffeeBean::CallbackRadioButtonGroup, this));
	beanRadioGroup->setTag(eINDEX_MD_COFFEE_BEAN::TAG_RADIO_GROUP_COFFEE_MACHINE);
	this->addChild(beanRadioGroup);
}



void MenuDevelopmentCoffeeBean::CallbackRadioButtonGroup(RadioButton* pRadioButton, int index)
{
	CCLOG("CallbackRadioButtonGroup >> %d", index);

	if (index != eINDEX_MD_COFFEE_BEAN::BASIC)
	{
		// 구매한 재료
		if (GameManager::GetInstance()->IsMenuDevelopmentByIndex(index - 1))
		{
			prevRadioIndex = index;
			GameManager::GetInstance()->SetCoffeeMenu(GameManager::eMD_SELECTED_COFFEE_MENU_TYPE::SELECTED_COFFEE_BEAN, index);
			
		}
		else
		{
			auto beanRadioGroup = dynamic_cast<RadioButtonGroup*>(this->getChildByTag(eINDEX_MD_COFFEE_BEAN::TAG_RADIO_GROUP_COFFEE_MACHINE));
			beanRadioGroup->setSelectedButton(prevRadioIndex);

			GameManager::GetInstance()->CallMenuDevelopmentNeedLabel();
		}

		
		/*auto beanRadio = dynamic_cast<RadioButton*>(beanRadioGroup->getRadioButtonByIndex(0));
		pRadioButton->setSelected(false);
		beanRadio->setSelected(true);*/
	}
	else if (index != prevRadioIndex)
	{
		prevRadioIndex = index;
	}
}