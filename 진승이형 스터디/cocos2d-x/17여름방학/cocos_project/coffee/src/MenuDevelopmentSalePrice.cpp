#include "MenuDevelopmentSalePrice.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"
#include "Define.h"

USING_NS_CC;
using namespace cocos2d::ui;

Sprite* MenuDevelopmentSalePrice::createSprite()
{
	return MenuDevelopmentSalePrice::create();
}

bool MenuDevelopmentSalePrice::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	

	InitMenuDevelopmentSalePrice();

	return true;
}

void MenuDevelopmentSalePrice::InitMenuDevelopmentSalePrice()
{

	//string filePath = FileUtils::getInstance()->fullPathForFilename(DATA_FILENAME_FONT);

	auto background = Sprite::create("BackgroundCoffeeMachineMain.png");
	if (background == NULL)
		return;
	this->setDisplayFrame(background->getDisplayFrame());

	this->setPosition(Vec2(background->getContentSize().width * 0.5f,
		background->getContentSize().height * 0.5f));


	

	auto salePrice = Sprite::create("MenuDevelopmentTitleSalePrice.png");
	if (salePrice == NULL)
		return;
	salePrice->setAnchorPoint(Vec2(0.0f, 0.5f));
	salePrice->setPosition(Vec2(background->getContentSize().width * 0.05f,
		background->getContentSize().height * 0.5f));
	this->addChild(salePrice, eDEPTH_ORDER_MD_NAME_SYRUP::SPRITE_UI);

	labelSalePrice = LabelTTF::create("0원", DATA_FILENAME_FONT, 40);
	if (labelSalePrice == NULL)
		return;
	labelSalePrice->setAnchorPoint(Vec2(0.0f, 0.5f));
	labelSalePrice->setColor(Color3B::MAGENTA);
	labelSalePrice->setPosition(Vec2(salePrice->getContentSize().width,
		background->getContentSize().height * 0.5f));
	this->addChild(labelSalePrice, eDEPTH_ORDER_MD_NAME_SYRUP::LABEL);

	auto priceSliderBar = Slider::create();
	priceSliderBar->loadBarTexture("BackgroundSliderBar.png");
	priceSliderBar->loadSlidBallTextureNormal("SliderBall.png");
	priceSliderBar->loadProgressBarTexture("SliderBar.png");
	priceSliderBar->setAnchorPoint(Vec2(0.0f, 0.5f));
	priceSliderBar->setPosition(Vec2(background->getContentSize().width * 0.15f,
		background->getContentSize().height * 0.3f));
	priceSliderBar->addEventListener(CC_CALLBACK_2(MenuDevelopmentSalePrice::CallbackSlider, this));
	this->addChild(priceSliderBar, eDEPTH_ORDER_MD_NAME_SYRUP::SLIDER);

}

void MenuDevelopmentSalePrice::SetBasicSalePrice(int price)
{
	basicSalePrice = -price;

	char changeSalePrice[256] = { '\0', };
	sprintf(changeSalePrice, "%d원", basicSalePrice);
	labelSalePrice->setString(changeSalePrice);
}



void MenuDevelopmentSalePrice::CallbackSlider(Ref* pSender, Slider::EventType type)
{
	if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
	{
		auto syrupSliderBar = dynamic_cast<Slider*>(pSender);
		int percent = syrupSliderBar->getPercent();
		int salePirce = (percent * RATE_SLIDER_PRICE) + basicSalePrice;

		char changeSalePrice[256] = { '\0', };
		sprintf(changeSalePrice, "%d원", salePirce);
		labelSalePrice->setString(changeSalePrice);

		GameManager::GetInstance()->SetCoffeeMenu(GameManager::eMD_SELECTED_COFFEE_MENU_TYPE::SELECTED_SALE_PRICE, salePirce);
	}
}