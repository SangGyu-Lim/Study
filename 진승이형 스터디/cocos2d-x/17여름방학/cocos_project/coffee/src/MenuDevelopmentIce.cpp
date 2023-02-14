#include "MenuDevelopmentIce.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"

USING_NS_CC;
using namespace cocos2d::ui;

Sprite* MenuDevelopmentIce::createSprite()
{
	return MenuDevelopmentIce::create();
}

bool MenuDevelopmentIce::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	prevRadioIndex = 0;

	InitMenuDevelopmentIce();


	return true;
}

void MenuDevelopmentIce::InitMenuDevelopmentIce()
{
	auto background = Sprite::create("BackgroundCoffeeMachineMain.png");
	if (background == NULL)
		return;
	this->setDisplayFrame(background->getDisplayFrame());

	this->setPosition(Vec2(background->getContentSize().width * 0.5f,
		background->getContentSize().height * 0.5f));

	auto ice = Sprite::create("MenuDevelopmentTitleIce.png");
	if (ice == NULL)
		return;
	ice->setAnchorPoint(Vec2(0.0f, 0.5f));
	ice->setPosition(Vec2(background->getContentSize().width * 0.05f,
		background->getContentSize().height * 0.7f));
	this->addChild(ice/*, eDEPTH_ORDER_MD_NAME_SYRUP::SPRITE_UI*/);

	auto iceRadioGroup = RadioButtonGroup::create();

	for (int i = 0; i < 4; ++i)
	{
		float vectorX = (i + 1) % 2;
		float vectorY = i / 2;
		
		char beanRadioNormalName[256] = { '\0', };
		sprintf(beanRadioNormalName, "IceRadioNormal%d.png", i);
		char beanRadioSelectedName[256] = { '\0', };
		sprintf(beanRadioSelectedName, "IceRadioSelected%d.png", i);

		auto beanRadio = RadioButton::create(beanRadioNormalName, beanRadioSelectedName);
		beanRadio->setAnchorPoint(Vec2(vectorX, vectorY));
		beanRadio->setPosition(Vec2(background->getContentSize().width * 0.5f,
			background->getContentSize().height * 0.3f));

		this->addChild(beanRadio);

		iceRadioGroup->addRadioButton(beanRadio);
	}

	iceRadioGroup->addEventListener(CC_CALLBACK_2(MenuDevelopmentIce::CallbackRadioButtonGroup, this));
	iceRadioGroup->setTag(eINDEX_MD_ICE::TAG_PAGE_VIEW_ICE);
	this->addChild(iceRadioGroup);

}


void MenuDevelopmentIce::CallbackRadioButtonGroup(RadioButton* pRadioButton, int index)
{
	CCLOG("CallbackRadioButtonGroup >> %d", index);

	if (index != eINDEX_MD_ICE::BASIC)
	{
		// 구매한 재료
		if (GameManager::GetInstance()->IsMenuDevelopmentByIndex(GameManager::ePRODUCT_TYPE_INDEX::PRODUCT_TYPE_INDEX_MAX * 2 + index - 1))
		{
			prevRadioIndex = index;
			GameManager::GetInstance()->SetCoffeeMenu(GameManager::eMD_SELECTED_COFFEE_MENU_TYPE::SELECTED_ICE, index);
		}
		else
		{
			auto beanRadioGroup = dynamic_cast<RadioButtonGroup*>(this->getChildByTag(eINDEX_MD_ICE::TAG_PAGE_VIEW_ICE));
			beanRadioGroup->setSelectedButton(prevRadioIndex);

			GameManager::GetInstance()->CallMenuDevelopmentNeedLabel();
			
		}

	}
	else if (index != prevRadioIndex)
	{
		prevRadioIndex = index;
	}
}