#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace cocos2d::network;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::CallbackShowSuzy, this));
    
    /*closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));*/
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + visibleSize.height - closeItem->getContentSize().height / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);


	// my code
	MenuItemImage* upImage = MenuItemImage::create("Up.png", "Up.png", CC_CALLBACK_1(HelloWorld::OnClickArrow, this));
	upImage->setPosition(Vec2(origin.x + visibleSize.width - upImage->getContentSize().width * 2,
		origin.y + upImage->getContentSize().height * 2));
	upImage->setTag(eARROW_TAG::UP);

	MenuItemImage* downImage = MenuItemImage::create("Down.png", "Down.png", CC_CALLBACK_1(HelloWorld::OnClickArrow, this));
	downImage->setPosition(Vec2(origin.x + visibleSize.width - downImage->getContentSize().width * 2,
		origin.y + downImage->getContentSize().height));
	downImage->setTag(eARROW_TAG::DOWN);

	MenuItemImage* leftImage = MenuItemImage::create("Left.png", "Left.png", CC_CALLBACK_1(HelloWorld::OnClickArrow, this));
	leftImage->setPosition(Vec2(origin.x + visibleSize.width - leftImage->getContentSize().width * 3,
		origin.y + leftImage->getContentSize().height));
	leftImage->setTag(eARROW_TAG::LEFT);

	MenuItemImage* rightImage = MenuItemImage::create("Right.png", "Right.png", CC_CALLBACK_1(HelloWorld::OnClickArrow, this));
	rightImage->setPosition(Vec2(origin.x + visibleSize.width - rightImage->getContentSize().width,
		origin.y + rightImage->getContentSize().height));
	rightImage->setTag(eARROW_TAG::RIGHT);

	Menu* arrowMenu = Menu::create(upImage, downImage, leftImage, rightImage, NULL);
	arrowMenu->setPosition(Vec2::ZERO);
	this->addChild(arrowMenu, 1);
    
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);	
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);



    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
}

void HelloWorld::CallbackShowSuzy(cocos2d::Ref* pSender)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	if (isShowSuzy)
	{
		auto sprite = Sprite::create("suzy.png");
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		sprite->setScale(0.5f, 0.5f);
		this->addChild(sprite, 1, eIMAGE_TAG::SUZY);

		isShowSuzy = false;
	}
	else
	{
		//auto sprite = this->getChildByTag(1991);
		this->removeChildByTag(eIMAGE_TAG::SUZY);

		isShowSuzy = true;
	}
	

	//this->add
}

void HelloWorld::OnClickArrow(cocos2d::Ref* pSender)
{
	MenuItemImage* arrowBtn = dynamic_cast<MenuItemImage*>(pSender);
	if (arrowBtn == NULL)
		return;

	Sprite* suzyImage = dynamic_cast<Sprite*>(this->getChildByTag(eIMAGE_TAG::SUZY));
	if (suzyImage == NULL)
		return;

	Vec2 imagePosition = suzyImage->getPosition();

	switch (arrowBtn->getTag())
	{
	case eARROW_TAG::UP:
	{
		CallNetwork();
		/*imagePosition.x = 0;
		imagePosition.y = (suzyImage->getPositionY() / 4);*/
		
	} break;

	case eARROW_TAG::DOWN:
	{
		imagePosition.x = 0;
		imagePosition.y = -(suzyImage->getPositionY() / 4);
	} break;

	case eARROW_TAG::LEFT:
	{
		imagePosition.x = -(suzyImage->getPositionX() / 4);
		imagePosition.y = 0;
	} break;

	case eARROW_TAG::RIGHT:
	{
		imagePosition.x = (suzyImage->getPositionX() / 4);
		imagePosition.y = 0;
	} break;
	default:
		break;
	}

	MoveBy* move = MoveBy::create(1, imagePosition);
	suzyImage->runAction(move);
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	Sprite* suzyImage = dynamic_cast<Sprite*>(this->getChildByTag(eIMAGE_TAG::SUZY));
	if (suzyImage == NULL)
		return false;

	Vec2 imagePosition = touch->getLocation();

	MoveTo* move = MoveTo::create(1, imagePosition);
	suzyImage->runAction(move);
	return true;
}


void HelloWorld::CallNetwork()
{
	HttpRequest* req = new HttpRequest();

	char url[256] = { '\0', };
	sprintf(url, "http://localhost:3000/?score=100");

	req->setUrl(url);
	req->setRequestType(HttpRequest::Type::POST);
	req->setResponseCallback(this, httpresponse_selector(HelloWorld::CallbackNetworkRequest));
	req->setTag("Get test");

	HttpClient::getInstance()->send(req);
	req->release();
}


void HelloWorld::CallbackNetworkRequest(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response)
{
	std::vector<char>* responseData = response->getResponseData();
	char totalScoreStr[256] = { '\0', };

	for (int i = 0; i < responseData->size(); ++i)
	{
		sprintf(totalScoreStr, "%s%c", totalScoreStr, responseData->at(i));
	}

	/*UpdateTotalScore(totalScoreStr);
	UpdateGameOver();*/
}