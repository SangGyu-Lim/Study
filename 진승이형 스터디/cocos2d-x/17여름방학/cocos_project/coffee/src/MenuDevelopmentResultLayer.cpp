#include "MenuDevelopmentResultLayer.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"
#include "Define.h"
#include "DataFileManager.h"

USING_NS_CC;
using namespace cocos2d::ui;

LayerColor* MenuDevelopmentResultLayer::createLayer()
{
	MenuDevelopmentResultLayer* layer = MenuDevelopmentResultLayer::create();

	return layer;
}

bool MenuDevelopmentResultLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 128)))
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->ignoreAnchorPointForPosition(false);
	this->setAnchorPoint(Vec2(0.5f, 0.5f));
	this->setPosition(Vec2(origin.x + visibleSize.width * 0.5f,
		origin.y + visibleSize.height * 0.5f));
	this->setContentSize(visibleSize);


	InitMenuDevelopmentResultLayer();
	InitTouchEvent();

	return true;
}

void MenuDevelopmentResultLayer::InitMenuDevelopmentResultLayer()
{
	auto background = Sprite::create("BackgroundCoffeeMachineResult.png");
	if (background == NULL)
		return;
	background->setAnchorPoint(Vec2(0.5f, 0.5f));
	background->setPosition(Vec2(this->getContentSize().width * 0.5f,
		this->getContentSize().height * 0.55f));
	this->addChild(background, eDEPTH_ORDER_MD_RESULT::SPRITE_BACKGROUND);

	auto coffeeName = Sprite::create("MenuDevelopmentTitleName.png");
	if (coffeeName == NULL)
		return;
	coffeeName->setAnchorPoint(Vec2(0.0f, 0.5f));
	coffeeName->setPosition(Vec2(this->getContentSize().width * 0.05f,
		this->getContentSize().height * 0.7f));
	this->addChild(coffeeName, eDEPTH_ORDER_MD_RESULT::SPRITE_UI);

	auto labelCoffeeName = LabelTTF::create("no coffee name", "fonts/NanumGothic.ttf", 40);
	if (labelCoffeeName == NULL)
		return;
	labelCoffeeName->setAnchorPoint(Vec2(0.0f, 0.5f));
	labelCoffeeName->setColor(Color3B::BLACK);
	labelCoffeeName->setPosition(Vec2(this->getContentSize().width * 0.15f,
		this->getContentSize().height * 0.6f));
	labelCoffeeName->setTag(eTAG_MD_RESULT::LABEL_COFFEE_NAME);
	this->addChild(labelCoffeeName, eDEPTH_ORDER_MD_RESULT::LABEL);
	//GameManager::GetInstance()->GetCoffeeMenu();

	auto popularity = Sprite::create("MenuDevelopmentTitlePopularity.png");
	if (popularity == NULL)
		return;
	popularity->setAnchorPoint(Vec2(0.0f, 0.5f));
	popularity->setPosition(Vec2(this->getContentSize().width * 0.05f,
		this->getContentSize().height * 0.43f));
	this->addChild(popularity, eDEPTH_ORDER_MD_RESULT::SPRITE_UI);

	auto labelPopularity = LabelTTF::create("0%", "fonts/NanumGothic.ttf", 50);
	if (labelPopularity == NULL)
		return;
	labelPopularity->setAnchorPoint(Vec2(0.0f, 0.5f));
	labelPopularity->setColor(Color3B::BLUE);
	labelPopularity->setPosition(Vec2(popularity->getContentSize().width,
		this->getContentSize().height * 0.435f));
	labelPopularity->setTag(eTAG_MD_RESULT::LABEL_POPULARITY);
	this->addChild(labelPopularity, eDEPTH_ORDER_MD_RESULT::LABEL);

	//MenuDevelopmentTitlePopularity
	auto closeItem = MenuItemImage::create("MDResultNormal.png", "MDResultSelected.png",
		CC_CALLBACK_1(MenuDevelopmentResultLayer::CallbackMenuDevelopmentResultClose, this));
	if (closeItem == NULL)
		return;
	closeItem->setAnchorPoint(Vec2(0.5f, 0.5f));
	closeItem->setPosition(Vec2(this->getContentSize().width * 0.5f,
		this->getContentSize().height * 0.27f));
	closeItem->setZOrder(eDEPTH_ORDER_MD_RESULT::MENU_ITEM);

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, eDEPTH_ORDER_MD_RESULT::MENU);


}

void MenuDevelopmentResultLayer::InitTouchEvent()
{
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	listener = EventListenerTouchOneByOne::create();
	if (listener == NULL)
		return;
	listener->setSwallowTouches(false);
	listener->onTouchBegan = CC_CALLBACK_2(MenuDevelopmentResultLayer::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool MenuDevelopmentResultLayer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	CCLOG("MenuDevelopmentResultLayer onTouchBegan");
	return true;
}

void MenuDevelopmentResultLayer::CallMenuDevelopmentResult()
{
	listener->setSwallowTouches(true);
	this->setVisible(true);	

	char* coffeeName = GameManager::GetInstance()->GetCoffeeMenu().name;
	auto labelCoffeeName = dynamic_cast<LabelTTF*>(this->getChildByTag(eTAG_MD_RESULT::LABEL_COFFEE_NAME));
	if (labelCoffeeName == NULL)
		return;
	labelCoffeeName->setString(coffeeName);
	
}

float MenuDevelopmentResultLayer::GetMenuDevelopmentPopularity()
{	
	SELECTED_COFFEE_MENU coffeeMenu = GameManager::GetInstance()->GetCoffeeMenu();

	float sum = 0;
	int index = 0;
			
	if(coffeeMenu.Syrup > BEST_POPULARITY_SYRUP)
	{
		sum += (coffeeMenu.Syrup * RATE_POPULARITY_SYRUP);
		sum -= ((coffeeMenu.Syrup - BEST_POPULARITY_SYRUP) * RATE_POPULARITY_SYRUP);
	}
	else
	{
		sum += (coffeeMenu.Syrup * RATE_POPULARITY_SYRUP);
	}

	if (coffeeMenu.CoffeeBean == 0)
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_BASIC_COFFEE_BEAN;
	else
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_COFFEE_BEAN + coffeeMenu.CoffeeBean - 1;
	sum += DataFileManager::GetInstance()->GetMenuData(index)->popularity;

	if (coffeeMenu.Milk == 0)
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_BASIC_MILK;
	else
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_MILK + coffeeMenu.Milk - 1;
	sum += DataFileManager::GetInstance()->GetMenuData(index)->popularity;

	if (coffeeMenu.Ice == 0)
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_BASIC_ICE;
	else
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_ICE + coffeeMenu.Ice - 1;
	sum += DataFileManager::GetInstance()->GetMenuData(index)->popularity;

	return sum;
}

void MenuDevelopmentResultLayer::CallbackMenuDevelopmentResultClose(Ref* pSender)
{
	listener->setSwallowTouches(false);
	this->setVisible(false);


}