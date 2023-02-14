#include "MainLayer.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"

USING_NS_CC;

LayerColor* MainLayer::createLayer()
{
	MainLayer* layer = MainLayer::create();

	return layer;
}

bool MainLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 255, 0, 255)))
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

	InitMain();


	InitLoadingBar();

	//InitTouchEvent();


	return true;
}



const int animationMaxCount = 6;
void MainLayer::InitMain()
{
	auto background = Sprite::create("BackgroundMain.png");
	if (background == NULL)
		return;
	background->setAnchorPoint(Vec2::ZERO);
	background->setPosition(Vec2::ZERO);
	this->addChild(background, eDEPTH_ORDER_LOBBY::SPRITE_BACKGROUND);

	auto coffeeMachineItem = MenuItemImage::create("CoffeeMachineNormal.png", "CoffeeMachineNormal.png", "CoffeeMachineDisabled.png",
		CC_CALLBACK_1(MainLayer::CallbackCoffeeMachine, this));
	if (coffeeMachineItem == NULL)
		return;
	coffeeMachineItem->setAnchorPoint(Vec2(0.0f, 1.0f));
	coffeeMachineItem->setPosition(Vec2(coffeeMachineItem->getContentSize().width * 0.07f,
		this->getContentSize().height - coffeeMachineItem->getContentSize().height * 0.5f));
	coffeeMachineItem->setZOrder(eDEPTH_ORDER_LOBBY::MENU_ITEM_FRONT);
	coffeeMachineItem->setTag(eTAG_LOBBY::MENU_ITEM_COFFEE_MACHINE);

	auto shopItem = MenuItemImage::create("ShopNormal.png", "ShopNormal.png", "ShopDisabled.png"
		, CC_CALLBACK_1(MainLayer::CallbackShop, this));
	if (shopItem == NULL)
		return;
	shopItem->setAnchorPoint(Vec2(1.0f, 1.0f));
	shopItem->setPosition(Vec2(this->getContentSize().width - shopItem->getContentSize().width * 0.1f,
		this->getContentSize().height - shopItem->getContentSize().height * 0.55f));
	shopItem->setZOrder(eDEPTH_ORDER_LOBBY::MENU_ITEM_FRONT);
	shopItem->setTag(eTAG_LOBBY::MENU_ITEM_SHOP);

	auto counterItem = MenuItemImage::create("Counter.png", "Counter.png",
		CC_CALLBACK_1(MainLayer::CallbackCounter, this));
	if (counterItem == NULL)
		return;
	counterItem->setAnchorPoint(Vec2(0.5f, 1.0f));
	counterItem->setPosition(Vec2(this->getContentSize().width * 0.5f,
		this->getContentSize().height - counterItem->getContentSize().height * 0.6f));
	counterItem->setZOrder(eDEPTH_ORDER_LOBBY::MENU_ITEM_BACK);

	auto mainMenu = Menu::create(coffeeMachineItem, shopItem, counterItem, NULL);
	mainMenu->setPosition(Vec2::ZERO);
	this->addChild(mainMenu, eDEPTH_ORDER_LOBBY::MENU, eTAG_LOBBY::MENU_MAIN);

	Sprite* leftTable = Sprite::create("LeftTable.png");
	if (leftTable == NULL)
		return;
	leftTable->setAnchorPoint(Vec2(0.0f, 1.0f));
	leftTable->setPosition(Vec2(leftTable->getContentSize().width * 0.5f,
		this->getContentSize().height * 0.55f));
	this->addChild(leftTable, eDEPTH_ORDER_LOBBY::SPRITE_UI);

	Sprite* rightTable = Sprite::create("RightTable.png");
	if (rightTable == NULL)
		return;
	rightTable->setAnchorPoint(Vec2(1.0f, 1.0f));
	rightTable->setPosition(Vec2(this->getContentSize().width - leftTable->getContentSize().width * 0.2f,
		this->getContentSize().height * 0.55f));
	this->addChild(rightTable, eDEPTH_ORDER_LOBBY::SPRITE_UI);



	
	CallCustomer();







}


void MainLayer::InitLoadingBar()
{
	Sprite* shopLoadingBackgroundImage = Sprite::create("BackgroundLoadingBar.png");
	if (shopLoadingBackgroundImage == NULL)
		return;
	shopLoadingBackgroundImage->setPosition(Vec2(this->getContentSize().width - shopLoadingBackgroundImage->getContentSize().height * 2.0f,
		this->getContentSize().height - shopLoadingBackgroundImage->getContentSize().width * 1.75f));
	shopLoadingBackgroundImage->setRotation(270);
	shopLoadingBackgroundImage->setTag(eTAG_LOBBY::SPRITE_SHOP_BACKGROUND);
	shopLoadingBackgroundImage->setVisible(false);
	this->addChild(shopLoadingBackgroundImage, eDEPTH_ORDER_LOBBY::SPRITE_UI);

	Sprite* shopLoadingImage = Sprite::create("LoadingBar.png");
	if (shopLoadingImage == NULL)
		return;
	auto shopLoadingBar = ProgressTimer::create(shopLoadingImage);
	if (shopLoadingBar == NULL)
		return;
	shopLoadingBar->setPosition(shopLoadingBackgroundImage->getPosition());
	shopLoadingBar->setRotation(270);
	shopLoadingBar->setPercentage(0.0f);
	shopLoadingBar->setType(ProgressTimerType::BAR);
	shopLoadingBar->setMidpoint(Vec2(0.0f, 0.5f));
	shopLoadingBar->setBarChangeRate(Vec2(1.0f, 0.0f));
	shopLoadingBar->setTag(eTAG_LOBBY::PROGRESS_TIMER_SHOP_LOADING_BAR);
	shopLoadingBar->setVisible(false);
	this->addChild(shopLoadingBar, eDEPTH_ORDER_LOBBY::PROGRESS_TIMER);


	Sprite* coffeeMachineLoadingBackgroundImage = Sprite::create("BackgroundLoadingBar.png");
	if (coffeeMachineLoadingBackgroundImage == NULL)
		return;
	coffeeMachineLoadingBackgroundImage->setPosition(Vec2(coffeeMachineLoadingBackgroundImage->getContentSize().width * 1.4f,
		this->getContentSize().height - coffeeMachineLoadingBackgroundImage->getContentSize().width * 1.75f));
	coffeeMachineLoadingBackgroundImage->setRotation(270);
	coffeeMachineLoadingBackgroundImage->setTag(eTAG_LOBBY::SPRITE_COFFEE_MACHINE_BACKGROUND);
	coffeeMachineLoadingBackgroundImage->setVisible(false);
	this->addChild(coffeeMachineLoadingBackgroundImage, eDEPTH_ORDER_LOBBY::SPRITE_UI);

	Sprite* coffeeMachineLoadingImage = Sprite::create("LoadingBar.png");
	if (coffeeMachineLoadingImage == NULL)
		return;
	auto coffeeMachineLoadingBar = ProgressTimer::create(coffeeMachineLoadingImage);
	if (coffeeMachineLoadingBar == NULL)
		return;
	coffeeMachineLoadingBar->setPosition(coffeeMachineLoadingBackgroundImage->getPosition());
	coffeeMachineLoadingBar->setRotation(270);
	coffeeMachineLoadingBar->setPercentage(0.0f);
	coffeeMachineLoadingBar->setType(ProgressTimerType::BAR);
	coffeeMachineLoadingBar->setMidpoint(Vec2(0.0f, 0.5f));
	coffeeMachineLoadingBar->setBarChangeRate(Vec2(1.0f, 0.0f));
	coffeeMachineLoadingBar->setTag(eTAG_LOBBY::PROGRESS_TIMER_COFFEE_MACHINE_LOADING_BAR);
	coffeeMachineLoadingBar->setVisible(false);
	this->addChild(coffeeMachineLoadingBar, eDEPTH_ORDER_LOBBY::PROGRESS_TIMER);


}

void MainLayer::InitTouchEvent()
{
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(false);

	listener->onTouchBegan = CC_CALLBACK_2(MainLayer::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}





bool MainLayer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	CCLOG("touch");
	return true;
}







void MainLayer::CallbackCoffeeMachine(Ref* pSender)
{
	GameManager::GetInstance()->CallLayer(GameManager::eLAYER_INDEX::COFFEE_MACHINE);
}

void MainLayer::CallbackShop(Ref* pSender)
{
	GameManager::GetInstance()->CallLayer(GameManager::eLAYER_INDEX::SHOP);
}

void MainLayer::CallbackCounter(Ref* pSender)
{
	GameManager::GetInstance()->CallLayer(GameManager::eLAYER_INDEX::COUNTER);
}

void MainLayer::CallShopBuyProduct(int index)
{
	auto mainMenu = dynamic_cast<Menu*>(this->getChildByTag(eTAG_LOBBY::MENU_MAIN));
	if (mainMenu == NULL)
		return;
	auto shopItem = dynamic_cast<MenuItemImage*>(mainMenu->getChildByTag(eTAG_LOBBY::MENU_ITEM_SHOP));
	if (shopItem == NULL)
		return;
	shopItem->setEnabled(false);

	auto shopLoadingBackgroundImage = dynamic_cast<Sprite*>(this->getChildByTag(eTAG_LOBBY::SPRITE_SHOP_BACKGROUND));
	if (shopLoadingBackgroundImage == NULL)
		return;
	shopLoadingBackgroundImage->setVisible(true);

	auto shopLoadingBar = dynamic_cast<ProgressTimer*>(this->getChildByTag(eTAG_LOBBY::PROGRESS_TIMER_SHOP_LOADING_BAR));
	if (shopLoadingBar == NULL)
		return;
	shopLoadingBar->setVisible(true);
	shopLoadingBar->setPercentage(0.0f);

	auto shopLoadingAction = ProgressFromTo::create(10, 0, 100);
	if (shopLoadingAction == NULL)
		return;

	CallFunc* completeCallback = CallFunc::create(CC_CALLBACK_0(MainLayer::CallbackCompleteShopBuyProduct, this, index));
	if (completeCallback == NULL)
		return;

	Sequence* seq = Sequence::create(shopLoadingAction, completeCallback, NULL);
	if (seq == NULL)
		return;

	shopLoadingBar->runAction(seq);


}

void MainLayer::CallbackCompleteShopBuyProduct(int index)
{
	auto mainMenu = dynamic_cast<Menu*>(this->getChildByTag(eTAG_LOBBY::MENU_MAIN));
	if (mainMenu == NULL)
		return;
	auto shopItem = dynamic_cast<MenuItemImage*>(mainMenu->getChildByTag(eTAG_LOBBY::MENU_ITEM_SHOP));
	if (shopItem == NULL)
		return;
	shopItem->setEnabled(true);

	auto shopLoadingBackgroundImage = dynamic_cast<Sprite*>(this->getChildByTag(eTAG_LOBBY::SPRITE_SHOP_BACKGROUND));
	if (shopLoadingBackgroundImage == NULL)
		return;
	shopLoadingBackgroundImage->setVisible(false);

	auto shopLoadingBar = dynamic_cast<ProgressTimer*>(this->getChildByTag(eTAG_LOBBY::PROGRESS_TIMER_SHOP_LOADING_BAR));
	if (shopLoadingBar == NULL)
		return;
	shopLoadingBar->setVisible(false);

	GameManager::GetInstance()->CompleteMenuDevelopment(index);
}

void MainLayer::CallCoffeeMachineBuyMenuDevelopment()
{
	auto mainMenu = dynamic_cast<Menu*>(this->getChildByTag(eTAG_LOBBY::MENU_MAIN));
	if (mainMenu == NULL)
		return;
	auto coffeeMachineItem = dynamic_cast<MenuItemImage*>(mainMenu->getChildByTag(eTAG_LOBBY::MENU_ITEM_COFFEE_MACHINE));
	if (coffeeMachineItem == NULL)
		return;
	coffeeMachineItem->setEnabled(false);

	auto coffeeMachineLoadingBackgroundImage = dynamic_cast<Sprite*>(this->getChildByTag(eTAG_LOBBY::SPRITE_COFFEE_MACHINE_BACKGROUND));
	if (coffeeMachineLoadingBackgroundImage == NULL)
		return;
	coffeeMachineLoadingBackgroundImage->setVisible(true);

	auto coffeeMachineLoadingBar = dynamic_cast<ProgressTimer*>(this->getChildByTag(eTAG_LOBBY::PROGRESS_TIMER_COFFEE_MACHINE_LOADING_BAR));
	if (coffeeMachineLoadingBar == NULL)
		return;
	coffeeMachineLoadingBar->setVisible(true);
	coffeeMachineLoadingBar->setPercentage(0.0f);

	auto shopLoadingAction = ProgressFromTo::create(10, 0, 100);
	if (shopLoadingAction == NULL)
		return;

	CallFunc* completeCallback = CallFunc::create(CC_CALLBACK_0(MainLayer::CallbackCompleteCoffeeMachineBuyMenuDevelopment, this));
	if (completeCallback == NULL)
		return;

	Sequence* seq = Sequence::create(shopLoadingAction, completeCallback, NULL);
	if (seq == NULL)
		return;

	coffeeMachineLoadingBar->runAction(seq);
}

void MainLayer::CallbackCompleteCoffeeMachineBuyMenuDevelopment()
{
	auto mainMenu = dynamic_cast<Menu*>(this->getChildByTag(eTAG_LOBBY::MENU_MAIN));
	if (mainMenu == NULL)
		return;
	auto coffeeMachineItem = dynamic_cast<MenuItemImage*>(mainMenu->getChildByTag(eTAG_LOBBY::MENU_ITEM_COFFEE_MACHINE));
	if (coffeeMachineItem == NULL)
		return;
	coffeeMachineItem->setEnabled(true);

	auto coffeeMachineLoadingBackgroundImage = dynamic_cast<Sprite*>(this->getChildByTag(eTAG_LOBBY::SPRITE_COFFEE_MACHINE_BACKGROUND));
	if (coffeeMachineLoadingBackgroundImage == NULL)
		return;
	coffeeMachineLoadingBackgroundImage->setVisible(false);

	auto coffeeMachineLoadingBar = dynamic_cast<ProgressTimer*>(this->getChildByTag(eTAG_LOBBY::PROGRESS_TIMER_COFFEE_MACHINE_LOADING_BAR));
	if (coffeeMachineLoadingBar == NULL)
		return;
	coffeeMachineLoadingBar->setVisible(false);

	GameManager::GetInstance()->CompleteMenu();
}

void MainLayer::CallCustomer()
{
	
	SetCustomerAnimation();
	CallBackCustomerMoveToCounter();
	
	
}

void MainLayer::SetCustomerAnimation()
{
	animationSprite = Sprite::create("RunAnimation_0.png");
	if (animationSprite == NULL)
		return;

	auto anim = Animation::create();
	if (anim == NULL)
		return;

	for (int i = 0; i < animationMaxCount; ++i)
	{
		char animationFileName[256] = { '\0', };
		sprintf(animationFileName, "RunAnimation_%d.png", i);
		anim->addSpriteFrameWithFileName(animationFileName);
	}
	anim->setLoops(-1);
	anim->setDelayPerUnit(0.1f);

	animationSprite->setPosition(Vec2(this->getContentSize().width,
		this->getContentSize().height * 0.3f));
	animationSprite->setScale(1.5f);
	
	animationSprite->runAction(Animate::create(anim));
	this->addChild(animationSprite, eDEPTH_ORDER_LOBBY::SPRITE_CUSTOMER);
}

const float customerMoveTime = 0.5f;
void MainLayer::CallBackCustomerMoveToCounter()
{
	animationSprite->setScaleX(animationSprite->getScaleX() * -1);

	auto move1 = MoveTo::create(customerMoveTime, Vec2(this->getContentSize().width * 0.5f,
		this->getContentSize().height * 0.3f));
	auto move2 = MoveTo::create(customerMoveTime, Vec2(this->getContentSize().width * 0.5f,
		this->getContentSize().height * 0.6f));
	CallFunc* callback = CallFunc::create(CC_CALLBACK_0(MainLayer::CallBackCustomerMoveToHome, this));

	//DelayTime* delay1 = DelayTime::create(dieDelayTime1);
	//CallFunc* callback1 = CallFunc::create(CC_CALLBACK_0(Mole::CallbackSetDieImage, this));
	//DelayTime* delay2 = DelayTime::create(dieDelayTime1);
	//MoveBy* move = MoveBy::create(1, Vec2(0.0f, -(this->getContentSize().height * 2 / 3)));

	//auto rotate = RotateBy::create()
	//CallFunc* callback2 = CallFunc::create(CC_CALLBACK_0(Mole::CallbackDie, this));

	Sequence* seq = Sequence::create(move1, move2, callback, NULL);
	animationSprite->runAction(seq);
}

void MainLayer::CallBackCustomerMoveToHome()
{
	animationSprite->setScaleX(animationSprite->getScaleX() * -1);
	animationSprite->setPositionX(this->getContentSize().width * 0.4f);

	auto move1 = MoveTo::create(customerMoveTime, Vec2(this->getContentSize().width * 0.4f,
		this->getContentSize().height * 0.3f));
	auto move2 = MoveTo::create(customerMoveTime, Vec2(this->getContentSize().width,
		this->getContentSize().height * 0.3f));
	CallFunc* callback = CallFunc::create(CC_CALLBACK_0(MainLayer::CallBackCustomerMoveToCounter, this));

	//DelayTime* delay1 = DelayTime::create(dieDelayTime1);
	//CallFunc* callback1 = CallFunc::create(CC_CALLBACK_0(Mole::CallbackSetDieImage, this));
	//DelayTime* delay2 = DelayTime::create(dieDelayTime1);
	//MoveBy* move = MoveBy::create(1, Vec2(0.0f, -(this->getContentSize().height * 2 / 3)));

	//auto rotate = RotateBy::create()
	//CallFunc* callback2 = CallFunc::create(CC_CALLBACK_0(Mole::CallbackDie, this));

	Sequence* seq = Sequence::create(move1, move2, callback, NULL);
	animationSprite->runAction(seq);
}