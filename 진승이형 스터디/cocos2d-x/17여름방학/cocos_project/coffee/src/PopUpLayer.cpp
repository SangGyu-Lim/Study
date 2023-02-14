#include "PopUpLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace cocos2d::ui;

LayerColor* PopUpLayer::createLayer()
{
	PopUpLayer* layer = PopUpLayer::create();

	return layer;
}

bool PopUpLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 192)))
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

	InitPopUp();
	InitTouchEvent();

	return true;
}

void PopUpLayer::InitPopUp()
{
	auto background = Sprite::create("BackgroundPopUp.png");
	if (background == NULL)
		return;
	background->setAnchorPoint(Vec2(0.5f, 0.5f));
	background->setPosition(Vec2(this->getContentSize().width * 0.5f,
		this->getContentSize().height * 0.5f));
	this->addChild(background, eDEPTH_ORDER_POP_UP::SPRITE_BACKGROUND);

	auto okItem = MenuItemImage::create("PopUpOKNormal.png", "PopUpOKSelected.png",
		CC_CALLBACK_1(PopUpLayer::CallbackOK, this));
	if (okItem == NULL)
		return;
	okItem->setAnchorPoint(Vec2(0.0f, 1.0f));
	okItem->setPosition(Vec2(background->getPosition().x + okItem->getContentSize().width * 0.1f,
		background->getPosition().y - okItem->getContentSize().height));
	okItem->setZOrder(eDEPTH_ORDER_POP_UP::MENU_ITEM);

	auto noItem = MenuItemImage::create("PopUpNONormal.png", "PopUpNOSelected.png",
		CC_CALLBACK_1(PopUpLayer::CallbackNO, this));
	if (noItem == NULL)
		return;
	noItem->setAnchorPoint(Vec2(1.0f, 1.0f));
	noItem->setPosition(Vec2(background->getPosition().x - noItem->getContentSize().width * 0.1f,
		background->getPosition().y - noItem->getContentSize().height));
	noItem->setZOrder(eDEPTH_ORDER_POP_UP::MENU_ITEM);

	auto twoButtonMenu = Menu::create(okItem, noItem, NULL);
	twoButtonMenu->setTag(eTAG_POP_UP::MENU_TWO_BUTTON);
	twoButtonMenu->setVisible(false);
	twoButtonMenu->setPosition(Vec2::ZERO);
	this->addChild(twoButtonMenu, eDEPTH_ORDER_POP_UP::MENU);

	auto closeItem = MenuItemImage::create("PopUpOKNormal.png", "PopUpOKSelected.png",
		CC_CALLBACK_1(PopUpLayer::CallbackNO, this));
	if (closeItem == NULL)
		return;
	closeItem->setAnchorPoint(Vec2(0.5f, 1.0f));
	closeItem->setPosition(Vec2(background->getPosition().x - closeItem->getContentSize().width * 0.1f,
		background->getPosition().y - closeItem->getContentSize().height));
	closeItem->setZOrder(eDEPTH_ORDER_POP_UP::MENU_ITEM);

	auto oneButtonMenu = Menu::create(closeItem, NULL);
	oneButtonMenu->setTag(eTAG_POP_UP::MENU_ONE_BUTTON);
	oneButtonMenu->setVisible(false);
	oneButtonMenu->setPosition(Vec2::ZERO);
	this->addChild(oneButtonMenu, eDEPTH_ORDER_POP_UP::MENU);

	auto title = LabelTTF::create("None Title", "fonts/NanumGothic.ttf", 35);
	if (title == NULL)
		return;
	title->setAnchorPoint(Vec2(0.0f, 1.0f));
	title->setColor(Color3B::BLACK);
	title->setPosition(Vec2(background->getPosition().x - noItem->getContentSize().width * 1.1f,
		background->getPosition().y + background->getContentSize().height * 0.45f));
	title->setTag(eTAG_POP_UP::LABEL_TITLE);
	this->addChild(title, eDEPTH_ORDER_POP_UP::LABEL);

	auto content = LabelTTF::create("None Content", "fonts/NanumGothic.ttf", 35);
	if (content == NULL)
		return;
	content->setAnchorPoint(Vec2(0.5f, 0.5f));
	content->setColor(Color3B::BLACK);
	content->setPosition(Vec2(background->getPosition().x,
		background->getPosition().y));
	content->setTag(eTAG_POP_UP::LABEL_CONTENT);
	this->addChild(content, eDEPTH_ORDER_POP_UP::LABEL);

	/*auto label = Label::createWithTTF("Hello World", "A Damn Mess.ttf", 62,
		Size(300, 200), TextHAlignment::CENTER, TextVAlignment::CENTER);*/


}



void PopUpLayer::InitTouchEvent()
{
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	listener = EventListenerTouchOneByOne::create();
	if (listener == NULL)
		return;
	listener->setSwallowTouches(false);
	listener->onTouchBegan = CC_CALLBACK_2(PopUpLayer::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}


bool PopUpLayer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	CCLOG("PopUpLayer onTouchBegan");
	return true;
}

void PopUpLayer::CallPopUpOneButton(char* titleString, char* contentString)
{
	auto menu = dynamic_cast<Menu*>(this->getChildByTag(eTAG_POP_UP::MENU_ONE_BUTTON));
	if (menu == NULL)
		return;


	listener->setSwallowTouches(true);
	this->setVisible(true);
	menu->setVisible(true);

	SetPopUpLabel(titleString, contentString);

}

void PopUpLayer::CallPopUpTwoButton(char* titleString, char* contentString, const ccMenuCallback& callbackOKButton)
{
	
	auto menu = dynamic_cast<Menu*>(this->getChildByTag(eTAG_POP_UP::MENU_TWO_BUTTON));
	if (menu == NULL)
		return;

	listener->setSwallowTouches(true);
	this->setVisible(true);
	menu->setVisible(true);

	SetPopUpLabel(titleString, contentString);

	if (callbackOKButton == NULL)
		return;

	_callbackOKButton = callbackOKButton;
}

void PopUpLayer::ClosePopUp()
{
	listener->setSwallowTouches(false);
	this->setVisible(false);
	
	//_callbackOKButton = NULL;

	auto twoButtonMenu = dynamic_cast<Menu*>(this->getChildByTag(eTAG_POP_UP::MENU_TWO_BUTTON));
	if (twoButtonMenu != NULL && twoButtonMenu->isVisible())
		twoButtonMenu->setVisible(false);	

	auto oneButtonMenu = dynamic_cast<Menu*>(this->getChildByTag(eTAG_POP_UP::MENU_ONE_BUTTON));
	if (oneButtonMenu != NULL && oneButtonMenu->isVisible())
		oneButtonMenu->setVisible(false);

}

void PopUpLayer::SetPopUpLabel(char* titleString, char* contentString)
{
	auto labelTitle = dynamic_cast<LabelTTF*>(this->getChildByTag(eTAG_POP_UP::LABEL_TITLE));
	if (labelTitle == NULL)
		return;
	labelTitle->setString(titleString);

	auto labelContent = dynamic_cast<LabelTTF*>(this->getChildByTag(eTAG_POP_UP::LABEL_CONTENT));
	if (labelContent == NULL)
		return;
	labelContent->setString(contentString);
}




void PopUpLayer::CallbackOK(Ref* pSender)
{
	if (_callbackOKButton == NULL)
		return;	

	ClosePopUp();

	_callbackOKButton(this);
}

void PopUpLayer::CallbackNO(Ref* pSender)
{
	ClosePopUp();
}