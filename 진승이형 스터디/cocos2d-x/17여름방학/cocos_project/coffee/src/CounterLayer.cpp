#include "CounterLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace cocos2d::ui;

LayerColor* CounterLayer::createLayer()
{
	CounterLayer* layer = CounterLayer::create();

	return layer;
}

bool CounterLayer::init()
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


	InitCounter();
	InitTouchEvent();

	return true;
}

void CounterLayer::InitCounter()
{
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Size pageViewSize;

	auto pageView = PageView::create();
	if (pageView == NULL)
		return;
	pageView->setTouchEnabled(true);
	pageView->setAnchorPoint(Vec2(0.5f, 0.5f));
	pageView->setPosition(Vec2(this->getContentSize().width * 0.5f,
		this->getContentSize().height * 0.5f));

	auto leftArrowItem = MenuItemImage::create("CounterLeftArrowNormal.png", "CounterLeftArrowSelected.png",
		CC_CALLBACK_1(CounterLayer::CallbackLeftArrow, this));
	if (leftArrowItem == NULL)
		return;
	leftArrowItem->setAnchorPoint(Vec2(1.0f, 0.0f));
	leftArrowItem->setPosition(Vec2(pageView->getPosition().x - leftArrowItem->getContentSize().width,
		pageView->getPosition().y - leftArrowItem->getContentSize().height * 4.3f));
	leftArrowItem->setZOrder(eDEPTH_ORDER_COUNTER::MENU_ITEM);

	auto rightArrowItem = MenuItemImage::create("CounterRightArrowNormal.png", "CounterRightArrowSelected.png",
		CC_CALLBACK_1(CounterLayer::CallbackRightArrow, this));
	if (rightArrowItem == NULL)
		return;
	rightArrowItem->setAnchorPoint(Vec2(0.0f, 0.0f));
	rightArrowItem->setPosition(Vec2(pageView->getPosition().x + rightArrowItem->getContentSize().width,
		pageView->getPosition().y - rightArrowItem->getContentSize().height * 4.3f));
	rightArrowItem->setZOrder(eDEPTH_ORDER_COUNTER::MENU_ITEM);

	for (int i = 0; i < 2; ++i)
	{
		char counterTitleName[256] = { '\0', };
		sprintf(counterTitleName, "CounterTitle%d.png", i);
		auto counterTitle = Sprite::create(counterTitleName);
		if (counterTitle == NULL)
			return;
		counterTitle->setAnchorPoint(Vec2(0.5f, 0.5f));
		counterTitle->setPosition(Vec2(pageView->getPosition().x,
			pageView->getPosition().y + counterTitle->getContentSize().height * 1.3f));

		char guestCountName[256] = { '\0', };
		sprintf(guestCountName, "GuestCount%d.png", i);
		auto guestCount = Sprite::create(guestCountName);
		if (guestCount == NULL)
			return;
		guestCount->setAnchorPoint(Vec2(0.5f, 0.5f));
		guestCount->setPosition(Vec2(pageView->getPosition().x - guestCount->getContentSize().width * 0.25f,
			pageView->getPosition().y * 1.1f));

		char salesVolumeName[256] = { '\0', };
		sprintf(salesVolumeName, "SalesVolume%d.png", i);
		auto salesVolume = Sprite::create(salesVolumeName);
		if (salesVolume == NULL)
			return;
		salesVolume->setAnchorPoint(Vec2(0.5f, 0.5f));
		salesVolume->setPosition(Vec2(pageView->getPosition().x - salesVolume->getContentSize().width * 0.25f,
			pageView->getPosition().y * 0.8f));

		char imcomeName[256] = { '\0', };
		sprintf(imcomeName, "Imcome%d.png", i);
		auto imcome = Sprite::create(imcomeName);
		if (imcome == NULL)
			return;
		imcome->setAnchorPoint(Vec2(0.5f, 0.5f));
		imcome->setPosition(Vec2(pageView->getPosition().x - imcome->getContentSize().width * 0.25f,
			pageView->getPosition().y * 0.5f));

		auto background = Sprite::create("BackgroundCounterMain.png");
		if (background == NULL)
			return;
		background->setAnchorPoint(Vec2(0.5f, 0.5f));
		background->setPosition(Vec2(this->getContentSize().width * 0.5f,
			this->getContentSize().height * 0.5f - counterTitle->getContentSize().height));
		
		background->addChild(counterTitle, eDEPTH_ORDER_COUNTER::SPRITE_UI);
		background->addChild(guestCount, eDEPTH_ORDER_COUNTER::SPRITE_UI);
		background->addChild(salesVolume, eDEPTH_ORDER_COUNTER::SPRITE_UI);
		background->addChild(imcome, eDEPTH_ORDER_COUNTER::SPRITE_UI);

		pageViewSize = Size(background->getContentSize().width, background->getContentSize().height + counterTitle->getContentSize().height * 0.5f);

		auto layout = Layout::create();
		layout->setContentSize(pageViewSize);
		layout->setPosition(background->getPosition());
		layout->addChild(background);

		if (i == 0)
		{
			pageView->addPage(layout);

			auto rightMenu = Menu::create(rightArrowItem, NULL);
			rightMenu->setPosition(Vec2::ZERO);
			background->addChild(rightMenu, eDEPTH_ORDER_COUNTER::MENU);
		}
			
		else
		{
			pageView->insertPage(layout, i);

			auto leftMenu = Menu::create(leftArrowItem, NULL);
			leftMenu->setPosition(Vec2::ZERO);
			background->addChild(leftMenu, eDEPTH_ORDER_COUNTER::MENU);
		}
	}

	pageView->setContentSize(pageViewSize);
	pageView->setTag(eINDEX_PAGE_COUNTER::TAG_PAGE_VIEW_COUNTER);
	pageView->setFocusEnabled(true);
	this->addChild(pageView, eDEPTH_ORDER_COUNTER::PAGE_VIEW);

	auto closeItem = MenuItemImage::create("LayerCloseNormal.png", "LayerCloseSelected.png",
		CC_CALLBACK_1(CounterLayer::CallbackCounterClose, this));
	if (closeItem == NULL)
		return;
	closeItem->setAnchorPoint(Vec2(1.0f, 1.0f));
	closeItem->setPosition(Vec2(this->getContentSize().width - closeItem->getContentSize().width * 0.2f,
		pageView->getPosition().y + closeItem->getContentSize().height * 4.5f));
	closeItem->setZOrder(eDEPTH_ORDER_COUNTER::MENU_ITEM);

	auto closeMenu = Menu::create(closeItem, NULL);
	closeMenu->setPosition(Vec2::ZERO);
	this->addChild(closeMenu, eDEPTH_ORDER_COUNTER::MENU);
}

void CounterLayer::InitTouchEvent()
{
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	listener = EventListenerTouchOneByOne::create();
	if (listener == NULL)
		return;
	listener->setSwallowTouches(false);
	listener->onTouchBegan = CC_CALLBACK_2(CounterLayer::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool CounterLayer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	CCLOG("CounterLayer onTouchBegan");
	return true;
}

void CounterLayer::CallCounter()
{
	listener->setSwallowTouches(true);
	this->setVisible(true);
}

void CounterLayer::CallbackLeftArrow(Ref* pSender)
{
	PageView* pageView = dynamic_cast<PageView*>(this->getChildByTag(eINDEX_PAGE_COUNTER::TAG_PAGE_VIEW_COUNTER));
	if (pageView == NULL)
		return;
	int index = pageView->getCurrentPageIndex();

	if (index != eINDEX_PAGE_COUNTER::PAGE_TOTAL)
		return;

	pageView->scrollToPage(eINDEX_PAGE_COUNTER::PAGE_MONTH);
}

void CounterLayer::CallbackRightArrow(Ref* pSender)
{
	PageView* pageView = dynamic_cast<PageView*>(this->getChildByTag(eINDEX_PAGE_COUNTER::TAG_PAGE_VIEW_COUNTER));
	if (pageView == NULL)
		return;
	int index = pageView->getCurrentPageIndex();

	if (index < eINDEX_PAGE_COUNTER::PAGE_MONTH)
		index = eINDEX_PAGE_COUNTER::PAGE_MONTH;
		
	if (index != eINDEX_PAGE_COUNTER::PAGE_MONTH)
		return;

	pageView->scrollToPage(eINDEX_PAGE_COUNTER::PAGE_TOTAL);
}

void CounterLayer::CallbackCounterClose(Ref* pSender)
{
	listener->setSwallowTouches(false);
	this->setVisible(false);


}