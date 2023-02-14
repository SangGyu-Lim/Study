#include "MenuDevelopmentNameSyrup.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"

USING_NS_CC;
using namespace cocos2d::ui;

Sprite* MenuDevelopmentNameSyrup::createSprite()
{
	return MenuDevelopmentNameSyrup::create();
}

bool MenuDevelopmentNameSyrup::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	/*auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->setAnchorPoint(Vec2(0.5f, 0.5f));
	this->setPosition(Vec2(origin.x + visibleSize.width * 0.5f,
		origin.y + visibleSize.height * 0.35f));*/

	InitMenuDevelopmentNameSyrup();

	return true;
}

void MenuDevelopmentNameSyrup::InitMenuDevelopmentNameSyrup()
{
	
	auto background = Sprite::create("BackgroundCoffeeMachineMain.png");
	if (background == NULL)
		return;
	this->setDisplayFrame(background->getDisplayFrame());

	this->setPosition(Vec2(background->getContentSize().width * 0.5f,
		background->getContentSize().height * 0.5f));

	auto coffeeName = Sprite::create("MenuDevelopmentTitleName.png");
	if (coffeeName == NULL)
		return;
	coffeeName->setAnchorPoint(Vec2(0.0f, 0.5f));
	coffeeName->setPosition(Vec2(background->getContentSize().width * 0.05f,
		background->getContentSize().height * 0.7f));
	this->addChild(coffeeName, eDEPTH_ORDER_MD_NAME_SYRUP::SPRITE_UI);

	auto editBoxCoffeeName = EditBox::create(Size(430, 99), "BackgroundEditBox.png");
	editBoxCoffeeName->setPlaceHolder("input here 한글 테스트");
	editBoxCoffeeName->setPlaceholderFontColor(Color3B::BLACK);
	editBoxCoffeeName->setPlaceholderFont("Resources/fonts/arial.ttf", 30);
	editBoxCoffeeName->setFontColor(Color3B::BLACK);
	editBoxCoffeeName->setFont("Resources/fonts/arial.ttf", 30);
	editBoxCoffeeName->setMaxLength(10);
	editBoxCoffeeName->setAnchorPoint(Vec2(0.0f, 0.5f));
	editBoxCoffeeName->setPosition(Vec2(background->getContentSize().width * 0.1f,
		background->getContentSize().height * 0.5f));
	//editBoxCoffeeName.addeven
	editBoxCoffeeName->setDelegate(this);
	this->addChild(editBoxCoffeeName, eDEPTH_ORDER_MD_NAME_SYRUP::EDIT_BOX);

	auto coffeeSyrup = Sprite::create("MenuDevelopmentTitleSyrup.png");
	if (coffeeSyrup == NULL)
		return;
	coffeeSyrup->setAnchorPoint(Vec2(0.0f, 0.5f));
	coffeeSyrup->setPosition(Vec2(background->getContentSize().width * 0.05f,
		background->getContentSize().height * 0.3f));
	this->addChild(coffeeSyrup, eDEPTH_ORDER_MD_NAME_SYRUP::SPRITE_UI);

	labelSyrupAmount = LabelTTF::create("0ml", "fonts/NanumGothic.ttf", 40);
	if (labelSyrupAmount == NULL)
		return;
	labelSyrupAmount->setAnchorPoint(Vec2(0.0f, 0.5f));
	labelSyrupAmount->setColor(Color3B::MAGENTA);
	labelSyrupAmount->setPosition(Vec2(coffeeSyrup->getContentSize().width,
		background->getContentSize().height * 0.3f));
	this->addChild(labelSyrupAmount, eDEPTH_ORDER_MD_NAME_SYRUP::LABEL);

	auto syrupSliderBar = Slider::create();
	syrupSliderBar->loadBarTexture("BackgroundSliderBar.png");
	syrupSliderBar->loadSlidBallTextureNormal("SliderBall.png");
	syrupSliderBar->loadProgressBarTexture("SliderBar.png");
	syrupSliderBar->setAnchorPoint(Vec2(0.0f, 0.5f));
	syrupSliderBar->setPosition(Vec2(background->getContentSize().width * 0.15f,
		background->getContentSize().height * 0.15f));
	syrupSliderBar->addEventListener(CC_CALLBACK_2(MenuDevelopmentNameSyrup::CallbackSlider, this));
	this->addChild(syrupSliderBar, eDEPTH_ORDER_MD_NAME_SYRUP::SLIDER);
	
}

void MenuDevelopmentNameSyrup::editBoxReturn(EditBox* editBox)
{
	const char* coffeeName = editBox->getText();
	GameManager::GetInstance()->SetCoffeeName(coffeeName);
}


void MenuDevelopmentNameSyrup::CallbackSlider(Ref* pSender, Slider::EventType type)
{
	if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
	{
		auto syrupSliderBar = dynamic_cast<Slider*>(pSender);
		int percent = syrupSliderBar->getPercent();

		char changeSyrupAmount[256] = { '\0', };
		sprintf(changeSyrupAmount, "%dml", percent);
		labelSyrupAmount->setString(changeSyrupAmount);

		GameManager::GetInstance()->SetCoffeeMenu(GameManager::eMD_SELECTED_COFFEE_MENU_TYPE::SELECTED_SYRUP, percent);
	}
}