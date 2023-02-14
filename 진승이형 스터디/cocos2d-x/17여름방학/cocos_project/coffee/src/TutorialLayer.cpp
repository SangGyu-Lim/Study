#include "TutorialLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

LayerColor* TutorialLayer::createLayer()
{
	TutorialLayer* layer = TutorialLayer::create();

	return layer;
}

bool TutorialLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
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

	InitTutorial();
	InitTouchEvent();

	currentTutorial = 0;
	return true;
}

const int tutorialMaxCount = 7;
void TutorialLayer::InitTutorial()
{
	MenuItemImage* item[tutorialMaxCount];
	for (int i = 0; i < tutorialMaxCount; ++i)
	{
		char spriteTutorial[256] = { '\0', };
		sprintf(spriteTutorial, "Tutorial_%d.png", i);

		item[i] = MenuItemImage::create(spriteTutorial, spriteTutorial,
			CC_CALLBACK_1(TutorialLayer::CallbackTutorial, this));
		if (item[i] == NULL)
			return;
		item[i]->setAnchorPoint(Vec2(0.5f, 0.5f));
		item[i]->setPosition(Vec2(this->getContentSize().width * 0.5f,
			this->getContentSize().height * 0.5f));
		item[i]->setVisible(false);
		item[i]->setTag(eTAG_TUTORIAL::BEGIN + i);
		item[i]->setZOrder(eDEPTH_ORDER_TUTORIAL::MENU_ITEM_TUTORIAL);
	}	

	auto itemMenu = Menu::create(item[0], item[1], item[2], item[3], item[4], item[5], item[6], NULL);
	itemMenu->setTag(eTAG_TUTORIAL::TUTORIAL_MENU_ITEM);
	itemMenu->setPosition(Vec2::ZERO);

	this->addChild(itemMenu, eDEPTH_ORDER_TUTORIAL::MENU);
	auto tutorialSkipItem = MenuItemImage::create("TutorialSkip.png", "TutorialSkip.png",
		CC_CALLBACK_1(TutorialLayer::CallbackTutorialSkip, this));
	if (tutorialSkipItem == NULL)
		return;
	tutorialSkipItem->setAnchorPoint(Vec2(1.0f, 1.0f));
	tutorialSkipItem->setPosition(Vec2(this->getContentSize().width * 0.95f,
		this->getContentSize().height * 0.95f));
	tutorialSkipItem->setZOrder(eDEPTH_ORDER_TUTORIAL::MENU_ITEM_SKIP);

	auto skipMenu = Menu::create(tutorialSkipItem, NULL);
	skipMenu->setPosition(Vec2::ZERO);
	this->addChild(skipMenu, eDEPTH_ORDER_TUTORIAL::MENU_SKIP);
}


void TutorialLayer::StartTutorial(const ccMenuCallback& callbackTutorialEnd)
{
	if (callbackTutorialEnd == NULL)
		return;
	_callbackTutorialEnd = callbackTutorialEnd;

	NextTutorial();
}

void TutorialLayer::NextTutorial()
{
	if (currentTutorial == tutorialMaxCount)
	{
		listener->setSwallowTouches(false);
		this->setVisible(false);

		_callbackTutorialEnd(this);
	}
	else
	{
		auto menu = dynamic_cast<Menu*>(this->getChildByTag(eTAG_TUTORIAL::TUTORIAL_MENU_ITEM));
		if (menu == NULL)
			return;

		int index = 1;

		if (currentTutorial == 0)
			index = 0;

		auto currentItem = dynamic_cast<MenuItemImage*>(menu->getChildByTag(eTAG_TUTORIAL::BEGIN + currentTutorial - index));
		if (currentItem == NULL)
			return;

		auto nextItem = dynamic_cast<MenuItemImage*>(menu->getChildByTag(eTAG_TUTORIAL::BEGIN + currentTutorial));
		if (nextItem == NULL)
			return;

		currentItem->setVisible(false);
		nextItem->setVisible(true);
	}
	
	
}



void TutorialLayer::InitTouchEvent()
{
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	listener = EventListenerTouchOneByOne::create();
	if (listener == NULL)
		return;
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(TutorialLayer::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}


bool TutorialLayer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	CCLOG("TutorialLayer onTouchBegan");
	return true;
}



void TutorialLayer::CallbackTutorial(Ref* pSender)
{
	++currentTutorial;

	NextTutorial();
}

void TutorialLayer::CallbackTutorialSkip(cocos2d::Ref* pSender)
{
	currentTutorial = tutorialMaxCount;

	NextTutorial();
}