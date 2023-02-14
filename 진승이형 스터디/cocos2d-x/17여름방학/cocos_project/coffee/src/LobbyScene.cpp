#include "LobbyScene.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"
#include "UserManager.h"
#include "DataFileManager.h"
#include "TutorialLayer.h"

USING_NS_CC;

Scene* Lobby::createScene()
{
	return Lobby::create();
}

bool Lobby::init()
{
	if (!Scene::init())
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

	InitSingleton();
	
	InitLayer();
	
	/* scene 스케쥴링 */
	InitTimer();
	this->scheduleUpdate();

	//InitTouchEvent();


	return true;
}

void Lobby::InitSingleton()
{
	DataFileManager::GetInstance()->InitDataFileManager();
	GameManager::GetInstance()->InitGameManager();
	UserManager::GetInstance()->InitUserManager();
}


void Lobby::InitLayer()
{
	InitMainLayer();
	InitTopLayer();
	InitBottomLayer();
	InitShopLayer();
	InitCounterLayer();
	InitCoffeeMachineLayer();
	InitPopUpLayer();
	InitMenuDevelopmentResultLayer();
}


void Lobby::InitMainLayer()
{
	mainLayer = dynamic_cast<MainLayer*>(MainLayer::createLayer());
	if (mainLayer == NULL)
		return;
	this->addChild(mainLayer, eDEPTH_ORDER_LOBBY::LAYER_BACKGROUND_BACK);
		
}

void Lobby::InitTopLayer()
{
	topLayer = dynamic_cast<TopLayer*>(TopLayer::createLayer());
	if (topLayer == NULL)
		return;
	this->addChild(topLayer, eDEPTH_ORDER_LOBBY::LAYER_BACKGROUND_FRONT);
}

void Lobby::InitBottomLayer()
{
	bottomLayer = dynamic_cast<BottomLayer*>(BottomLayer::createLayer());
	if (bottomLayer == NULL)
		return;
	this->addChild(bottomLayer, eDEPTH_ORDER_LOBBY::LAYER_BACKGROUND_FRONT);

}

void Lobby::InitShopLayer()
{
	shopLayer = dynamic_cast<ShopLayer*>(ShopLayer::createLayer());
	if (shopLayer == NULL)
		return;
	shopLayer->setVisible(false);
	this->addChild(shopLayer, eDEPTH_ORDER_LOBBY::LAYER_POPUP_BACK);
}

void Lobby::InitCounterLayer()
{
	counterLayer = dynamic_cast<CounterLayer*>(CounterLayer::createLayer());
	if (counterLayer == NULL)
		return;
	counterLayer->setVisible(false);
	this->addChild(counterLayer, eDEPTH_ORDER_LOBBY::LAYER_POPUP_BACK);
}

void Lobby::InitCoffeeMachineLayer()
{
	coffeeMachineLayer = dynamic_cast<CoffeeMachineLayer*>(CoffeeMachineLayer::createLayer());
	if (coffeeMachineLayer == NULL)
		return;
	coffeeMachineLayer->setVisible(false);
	this->addChild(coffeeMachineLayer, eDEPTH_ORDER_LOBBY::LAYER_POPUP_BACK);
}

void Lobby::InitPopUpLayer()
{
	popUpLayer = dynamic_cast<PopUpLayer*>(PopUpLayer::createLayer());
	if (popUpLayer == NULL)
		return;
	popUpLayer->setVisible(false);
	this->addChild(popUpLayer, eDEPTH_ORDER_LOBBY::LAYER_POPUP_FRONT);
}

void Lobby::InitMenuDevelopmentResultLayer()
{
	menuDevelopmentResultLayer = dynamic_cast<MenuDevelopmentResultLayer*>(MenuDevelopmentResultLayer::createLayer());
	if (menuDevelopmentResultLayer == NULL)
		return;
	menuDevelopmentResultLayer->setVisible(false);
	this->addChild(menuDevelopmentResultLayer, eDEPTH_ORDER_LOBBY::LAYER_POPUP_FRONT);
}




void Lobby::InitTouchEvent()
{
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(false);

	listener->onTouchBegan = CC_CALLBACK_2(Lobby::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//menu_selector()
	//delegate d;
	
}





bool Lobby::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	CCLOG("touch");
	return true;
}

void Lobby::InitTimer()
{
	survivalDayTimer = GetTime();
	

}

const int survivalDayReferenceTime = 1000;	// 5초
void Lobby::update(float f)
{

	// 튜토리얼 진행 완료
	if (endTutorial)
	{
		long currentTime = GetTime();

		// 생존일 계산
		if ((currentTime - survivalDayTimer) >= survivalDayReferenceTime)
		{
			UserManager::GetInstance()->AddSurvivalDay();
			topLayer->SetSurvivalDayLabel();
			survivalDayTimer = GetTime();
		}

		// 손님
		if (isMenuDevelopment)
		{

		}

		//// mole 출현
		//if ((currentTime - moleShowTimer) >= moleShowReferenceTime)
		//{
		//	int index = rand() % MOLE_MAX_COUNT;
		//	moleShowTimer = GetTime();

		//	if (mole[index]->GetState() == Mole::eSTATE_MOLE::IDLE)
		//	{
		//		mole[index]->ActionShow();
		//	}
		//}

		//// 게임 시간 체크
		//if (realPlayTime > 0)
		//{
		//	realPlayTime = playReferenceTime - (currentTime - playTimeTimer);
		//	float tempTime = realPlayTime / 1000.0f;

		//	UpdateTimer(tempTime);
		//}
		//else if (realPlayTime <= 0)
		//{
		//	UpdateTimer(0.0f);

		//	isTimeout = true;

		//	CallNetwork(score);
		//}
	}
	else if(!doTutorial)
	{
		StartTutorial();
	}
	

}

long Lobby::GetTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}


void Lobby::StartTutorial()
{
	doTutorial = true;

	TutorialLayer* tutorial = dynamic_cast<TutorialLayer*>(TutorialLayer::createLayer());
	if (tutorial == NULL)
		return;
	this->addChild(tutorial, eDEPTH_ORDER_LOBBY::TUTORIAL);

	tutorial->StartTutorial(CC_CALLBACK_0(Lobby::EndTutorial, this));
}

void Lobby::EndTutorial()
{
	endTutorial = true;

}







void Lobby::CallShop()
{
	shopLayer->CallShopMenu();
	//shopLayer->CallShopMenutest(CC_CALLBACK_0(Lobby::test, this));
}
//
//void Lobby::test()
//{
//	int a;
//	a = 5;
//}

void Lobby::CallCounter()
{
	counterLayer->CallCounter();
}

void Lobby::CallCoffeeMachine()
{
	coffeeMachineLayer->CallCoffeeMachine();
}

void Lobby::CallPopUpOneButton(char* titleString, char* contentString)
{
	popUpLayer->CallPopUpOneButton(titleString, contentString);
}

void Lobby::CallPopUpTwoButton(char* titleString, char* contentString, const ccMenuCallback& callbackOKButton)
{
	popUpLayer->CallPopUpTwoButton(titleString, contentString, callbackOKButton);
}

void Lobby::CallShopBuyProduct(int index)
{
	mainLayer->CallShopBuyProduct(index);
	topLayer->SetGoldLabel();
}

void Lobby::CallCoffeeMachineBuyMenuDevelopment()
{
	mainLayer->CallCoffeeMachineBuyMenuDevelopment();
	topLayer->SetGoldLabel();	
}


void Lobby::CallCoffeeMachineMDNeedLabel()
{
	coffeeMachineLayer->CallMDNeedLabel();
}

void Lobby::CallAddMenu()
{
	if (!isMenuDevelopment)
		isMenuDevelopment = true;

	// 메뉴 완료 팝업
	menuDevelopmentResultLayer->CallMenuDevelopmentResult();
	// 인기도
	//int prope = coffeeMachineLayer->CallCoffeeMachineBuyMenuDevelopment();
	// 메뉴 등록
}

void Lobby::test()
{
	menuDevelopmentResultLayer->CallMenuDevelopmentResult();
}