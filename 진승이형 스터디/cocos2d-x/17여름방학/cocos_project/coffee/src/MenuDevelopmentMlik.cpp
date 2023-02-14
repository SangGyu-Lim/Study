#include "MenuDevelopmentMlik.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"

USING_NS_CC;
using namespace cocos2d::ui;

Sprite* MenuDevelopmentMlik::createSprite()
{
	return MenuDevelopmentMlik::create();
}

bool MenuDevelopmentMlik::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	prevRadioIndex = 0;

	InitMenuDevelopmentMlik();


	return true;
}

void MenuDevelopmentMlik::InitMenuDevelopmentMlik()
{
	auto background = Sprite::create("BackgroundCoffeeMachineMain.png");
	if (background == NULL)
		return;
	this->setDisplayFrame(background->getDisplayFrame());

	this->setPosition(Vec2(background->getContentSize().width * 0.5f,
		background->getContentSize().height * 0.5f));

	auto milk = Sprite::create("MenuDevelopmentTitleMilk.png");
	if (milk == NULL)
		return;
	milk->setAnchorPoint(Vec2(0.0f, 0.5f));
	milk->setPosition(Vec2(background->getContentSize().width * 0.05f,
		background->getContentSize().height * 0.7f));
	this->addChild(milk/*, eDEPTH_ORDER_MD_NAME_SYRUP::SPRITE_UI*/);


	auto milkRadioGroup = RadioButtonGroup::create();

	for (int i = 0; i < 4; ++i)
	{
		float vectorX = (i + 1) % 2;
		float vectorY = i / 2;

		char beanRadioNormalName[256] = { '\0', };
		sprintf(beanRadioNormalName, "MilkRadioNormal%d.png", i);
		char beanRadioSelectedName[256] = { '\0', };
		sprintf(beanRadioSelectedName, "MilkRadioSelected%d.png", i);

		auto beanRadio = RadioButton::create(beanRadioNormalName, beanRadioSelectedName);
		beanRadio->setAnchorPoint(Vec2(vectorX, vectorY));
		beanRadio->setPosition(Vec2(background->getContentSize().width * 0.5f,
			background->getContentSize().height * 0.3f));

		this->addChild(beanRadio);

		milkRadioGroup->addRadioButton(beanRadio);
	}

	milkRadioGroup->addEventListener(CC_CALLBACK_2(MenuDevelopmentMlik::CallbackRadioButtonGroup, this));
	milkRadioGroup->setTag(eINDEX_MD_MILK::TAG_PAGE_VIEW_MILK);
	this->addChild(milkRadioGroup);
}

void MenuDevelopmentMlik::CallbackRadioButtonGroup(RadioButton* pRadioButton, int index)
{
	CCLOG("CallbackRadioButtonGroup >> %d", index);

	if (index != eINDEX_MD_MILK::BASIC)
	{
		// 구매한 재료
		if (GameManager::GetInstance()->IsMenuDevelopmentByIndex(GameManager::ePRODUCT_TYPE_INDEX::PRODUCT_TYPE_INDEX_MAX + index - 1))
		{
			prevRadioIndex = index;
			GameManager::GetInstance()->SetCoffeeMenu(GameManager::eMD_SELECTED_COFFEE_MENU_TYPE::SELECTED_MILK, index);
		}
		else
		{
			auto beanRadioGroup = dynamic_cast<RadioButtonGroup*>(this->getChildByTag(eINDEX_MD_MILK::TAG_PAGE_VIEW_MILK));
			beanRadioGroup->setSelectedButton(prevRadioIndex);

			GameManager::GetInstance()->CallMenuDevelopmentNeedLabel();
		}

	}
	else if (index != prevRadioIndex)
	{
		prevRadioIndex = index;
	}
}