#include "BottomLayer.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"
#include "UserManager.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#endif



USING_NS_CC;

using namespace cocos2d::network;

LayerColor* BottomLayer::createLayer()
{
	BottomLayer* layer = BottomLayer::create();

	return layer;
}

bool BottomLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 0, 255, 255)))
	{
		return false;
	}

	this->ignoreAnchorPointForPosition(false);
	this->setAnchorPoint(Vec2::ZERO);
	this->setPosition(Vec2::ZERO);

	InitBottomMenu();

	return true;
}

void BottomLayer::InitBottomMenu()
{
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("BackgroundBottom.png");
	if (background == NULL)
		return;

	this->setContentSize(background->getContentSize());
	background->setAnchorPoint(Vec2::ZERO);
	background->setPosition(Vec2::ZERO);
	this->addChild(background, eDEPTH_ORDER_BOTTOM::SPRITE_BACKGROUND);

	auto publicRelationsItem = MenuItemImage::create("BottomMenuNormal0.png", "BottomMenuSelected0.png",
		CC_CALLBACK_1(BottomLayer::CallbackPublicRelations, this));
	if (publicRelationsItem == NULL)
		return;
	publicRelationsItem->setAnchorPoint(Vec2(0.0f, 0.5f));
	publicRelationsItem->setPosition(Vec2(origin.x + publicRelationsItem->getContentSize().width * 0.1f,
		origin.y + this->getContentSize().height * 0.5f));
	publicRelationsItem->setZOrder(eDEPTH_ORDER_BOTTOM::MENU_ITEM);

	auto closeGameItem = MenuItemImage::create("BottomMenuNormal1.png", "BottomMenuSelected1.png",
		CC_CALLBACK_1(BottomLayer::CallbackCloseGame, this));
	if (closeGameItem == NULL)
		return;
	closeGameItem->setAnchorPoint(Vec2(1.0f, 0.5f));
	closeGameItem->setPosition(Vec2(origin.x + this->getContentSize().width - closeGameItem->getContentSize().width * 0.1f,
		origin.y + this->getContentSize().height * 0.5f));
	closeGameItem->setZOrder(eDEPTH_ORDER_BOTTOM::MENU_ITEM);

	// create menu, it's an autorelease object
	auto bottomMenu = Menu::create(publicRelationsItem, closeGameItem, NULL);
	if (bottomMenu == NULL)
		return;
	bottomMenu->setPosition(Vec2::ZERO);
	this->addChild(bottomMenu, eDEPTH_ORDER_BOTTOM::MENU);



}

void BottomLayer::CallbackPublicRelations(Ref* pSender)
{
	int b;
	b = 5;
	GameManager::GetInstance()->test();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;
	if(JniHelper::getMethodInfo(t,
	"org/cocos2dx/cpp/AppActivity",
	"CallJavaFunction",
	"()V"))
	{
		t.env->CallStaticVoidMethod(t.classID, t.methodID);
	}

#endif


}

void BottomLayer::CallbackCloseGame(Ref* pSender)
{
	
	//Singleton<GameManager>::destroy();
	GameManager::destroy();
	UserManager::destroy();
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

}


void BottomLayer::CallNetwork()
{
	HttpRequest* req = new HttpRequest();

	char url[256] = { '\0', };
	sprintf(url, "http://localhost:3000/?score=100");

	req->setUrl(url);
	req->setRequestType(HttpRequest::Type::POST);
	req->setResponseCallback(this, httpresponse_selector(BottomLayer::CallbackNetworkRequest));
	/*char tempStr[] = "limsganggds";
	req->setRequestData(tempStr, sizeof(tempStr));*/
	req->setTag("Get test");

	HttpClient::getInstance()->send(req);
	req->release();
}


void BottomLayer::CallbackNetworkRequest(HttpClient *sender, HttpResponse *response)
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