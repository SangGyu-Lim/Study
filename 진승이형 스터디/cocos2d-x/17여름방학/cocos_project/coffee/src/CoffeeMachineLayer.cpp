#include "CoffeeMachineLayer.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"
#include "UserManager.h"
#include "DataFileManager.h"
#include "Define.h"

USING_NS_CC;
using namespace cocos2d::ui;

LayerColor* CoffeeMachineLayer::createLayer()
{
	CoffeeMachineLayer* layer = CoffeeMachineLayer::create();

	return layer;
}

bool CoffeeMachineLayer::init()
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

	InitMenuDevelopment();
	InitCoffeeMachine();
	InitTouchEvent();

	return true;
}

void CoffeeMachineLayer::InitCoffeeMachine()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();	

	auto pageView = PageView::create();
	if (pageView == NULL)
		return;
	pageView->setTouchEnabled(true);
	pageView->setAnchorPoint(Vec2(0.5f, 0.5f));
	pageView->setPosition(Vec2(this->getContentSize().width * 0.5f,
		this->getContentSize().height * 0.6f));
	pageView->setContentSize(menuDevelopmentNameSyrup->getContentSize());
	pageView->setTag(eINDEX_PAGE_COFFEE_MACHINE::TAG_PAGE_VIEW_COFFEE_MACHINE);
	pageView->setFocusEnabled(true);
	this->addChild(pageView, eDEPTH_ORDER_COFFEE_MACHINE::PAGE_VIEW);
	
	auto layout = Layout::create();
	if (layout == NULL)
		return;
	layout->addChild(menuDevelopmentNameSyrup);
	
	auto layout1 = Layout::create();
	if (layout1 == NULL)
		return;
	layout1->addChild(menuDevelopmentCoffeeBean);

	auto layout2 = Layout::create();
	if (layout2 == NULL)
		return;
	layout2->addChild(menuDevelopmentMlik);

	auto layout3 = Layout::create();
	if (layout3 == NULL)
		return;
	layout3->addChild(menuDevelopmentIce);

	auto layout4 = Layout::create();
	if (layout4 == NULL)
		return;
	layout4->addChild(menuDevelopmentSalePrice);

	auto layout5 = Layout::create();
	if (layout5 == NULL)
		return;
	layout5->addChild(menuDevelopmentComprehensive);

	pageView->addPage(layout);
	pageView->insertPage(layout1, eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_COFFEE_BEAN);
	pageView->insertPage(layout2, eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_MILK);
	pageView->insertPage(layout3, eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_ICE);
	pageView->insertPage(layout4, eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_SALE_PRICE);
	pageView->insertPage(layout5, eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_COMPREHENSIVE);

	auto backgroundBottom = Sprite::create("BackgroundCoffeeMachineBottom.png");
	if (backgroundBottom == NULL)
		return;
	backgroundBottom->setAnchorPoint(Vec2(0.5f, 1.0f));
	backgroundBottom->setPosition(Vec2(pageView->getPosition().x,
		pageView->getPosition().y - pageView->getContentSize().height * 0.5f));
	this->addChild(backgroundBottom, eDEPTH_ORDER_COFFEE_MACHINE::SPRITE_BACKGROUND);

	auto closeItem = MenuItemImage::create("LayerCloseNormal.png", "LayerCloseSelected.png",
		CC_CALLBACK_1(CoffeeMachineLayer::CallbackCoffeeMachineClose, this));
	if (closeItem == NULL)
		return;
	closeItem->setAnchorPoint(Vec2(1.0f, 1.0f));
	closeItem->setPosition(Vec2(this->getContentSize().width,
		this->getContentSize().height * 0.5f + pageView->getContentSize().height * 0.58f));
	closeItem->setZOrder(eDEPTH_ORDER_COFFEE_MACHINE::MENU_ITEM);

	auto leftArrowItem = MenuItemImage::create("CoffeeMachineLeftArrowNormal.png", "CoffeeMachineLeftArrowSelected.png",
		CC_CALLBACK_1(CoffeeMachineLayer::CallbackLeftArrow, this));
	if (leftArrowItem == NULL)
		return;
	leftArrowItem->setAnchorPoint(Vec2(1.0f, 1.0f));
	leftArrowItem->setPosition(Vec2(backgroundBottom->getPosition().x - leftArrowItem->getContentSize().width,
		backgroundBottom->getPosition().y - leftArrowItem->getContentSize().height * 0.1f));
	leftArrowItem->setZOrder(eDEPTH_ORDER_COFFEE_MACHINE::MENU_ITEM);

	auto rightArrowItem = MenuItemImage::create("CoffeeMachineRightArrowNormal.png", "CoffeeMachineRightArrowSelected.png",
		CC_CALLBACK_1(CoffeeMachineLayer::CallbackRightArrow, this));
	if (rightArrowItem == NULL)
		return;
	rightArrowItem->setAnchorPoint(Vec2(0.0f, 1.0f));
	rightArrowItem->setPosition(Vec2(backgroundBottom->getPosition().x + rightArrowItem->getContentSize().width,
		backgroundBottom->getPosition().y - rightArrowItem->getContentSize().height * 0.1f));
	rightArrowItem->setZOrder(eDEPTH_ORDER_COFFEE_MACHINE::MENU_ITEM);

	auto mainMenu = Menu::create(closeItem, leftArrowItem, rightArrowItem, NULL);
	mainMenu->setPosition(Vec2::ZERO);
	this->addChild(mainMenu, eDEPTH_ORDER_COFFEE_MACHINE::MENU);

	for (int i = 0; i < MD_MAX_LABEL_COUNT; ++i)
	{
		char beanRadioNormalName[256] = { '\0', };
		sprintf(beanRadioNormalName, "%d 재료 구입이 필요합니다...", i);

		menuDevelopmentNeedLabel[i] = LabelTTF::create(beanRadioNormalName, DATA_FILENAME_FONT, 35);
		if (menuDevelopmentNeedLabel[i] == NULL)
			return;
		menuDevelopmentNeedLabel[i]->setAnchorPoint(Vec2(1.0f, 0.0f));
		menuDevelopmentNeedLabel[i]->setColor(Color3B::BLACK);
		menuDevelopmentNeedLabel[i]->setPosition(Vec2(this->getContentSize().width,			
			menuDevelopmentNeedLabel[i]->getContentSize().height));
		menuDevelopmentNeedLabel[i]->setVisible(false);
		this->addChild(menuDevelopmentNeedLabel[i], eDEPTH_ORDER_COFFEE_MACHINE::LABEL);
	}

	currentLabelCount = 0;

}

void CoffeeMachineLayer::InitMenuDevelopment()
{
	menuDevelopmentNameSyrup = dynamic_cast<MenuDevelopmentNameSyrup*>(MenuDevelopmentNameSyrup::createSprite());
	if (menuDevelopmentNameSyrup == NULL)
		return;

	menuDevelopmentCoffeeBean = dynamic_cast<MenuDevelopmentCoffeeBean*>(MenuDevelopmentCoffeeBean::createSprite());
	if (menuDevelopmentCoffeeBean == NULL)
		return;

	menuDevelopmentMlik = dynamic_cast<MenuDevelopmentMlik*>(MenuDevelopmentMlik::createSprite());
	if (menuDevelopmentMlik == NULL)
		return;

	menuDevelopmentIce = dynamic_cast<MenuDevelopmentIce*>(MenuDevelopmentIce::createSprite());
	if (menuDevelopmentIce == NULL)
		return;	

	menuDevelopmentSalePrice = dynamic_cast<MenuDevelopmentSalePrice*>(MenuDevelopmentSalePrice::createSprite());
	if (menuDevelopmentSalePrice == NULL)
		return;

	menuDevelopmentComprehensive = dynamic_cast<MenuDevelopmentComprehensive*>(MenuDevelopmentComprehensive::createSprite());
	if (menuDevelopmentComprehensive == NULL)
		return;
	

}

void CoffeeMachineLayer::InitTouchEvent()
{
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	listener = EventListenerTouchOneByOne::create();
	if (listener == NULL)
		return;
	listener->setSwallowTouches(false);
	listener->onTouchBegan = CC_CALLBACK_2(CoffeeMachineLayer::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool CoffeeMachineLayer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	CCLOG("CoffeeMachineLayer onTouchBegan");
	return true;
}

void CoffeeMachineLayer::CallCoffeeMachine()
{
	PageView* pageView = dynamic_cast<PageView*>(this->getChildByTag(eINDEX_PAGE_COFFEE_MACHINE::TAG_PAGE_VIEW_COFFEE_MACHINE));
	pageView->setCurPageIndex(eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_NAME_SYRUP);

	listener->setSwallowTouches(true);
	this->setVisible(true);
}

void CoffeeMachineLayer::CallMDNeedLabel()
{
	
	for (int i = 0; i < MD_MAX_LABEL_COUNT; ++i)
	{
		bool isVisibleLabel = menuDevelopmentNeedLabel[i]->isVisible();

		menuDevelopmentNeedLabel[i]->setOpacity(255);

		if (isVisibleLabel)
		{
			menuDevelopmentNeedLabel[i]->stopAllActions();

			if (menuDevelopmentNeedLabel[i]->getPosition().y > menuDevelopmentNeedLabel[i]->getContentSize().height * 4.0f)
			{		
				CallbackMDNeedLabelActiveFalse(i);				
			}
			else
			{
				MDNeedLabelRunAction(i);
			}
			
		}
		else
		{			
			++currentLabelCount;

			menuDevelopmentNeedLabel[i]->setVisible(true);			
			/*if(i == 0)
				menuDevelopmentNeedLabel[i]->setPosition(Vec2(this->getContentSize().width, 0.0f));				
			else
				menuDevelopmentNeedLabel[i]->setPosition(Vec2(this->getContentSize().width, 
					menuDevelopmentNeedLabel[i - 1]->getPosition().y - menuDevelopmentNeedLabel[i]->getContentSize().height));*/

			menuDevelopmentNeedLabel[i]->setPosition(Vec2(this->getContentSize().width, 0.0f));

			if (i != 0)
			{
				if (menuDevelopmentNeedLabel[i - 1]->getPosition().y < menuDevelopmentNeedLabel[i]->getContentSize().height)
				{
					menuDevelopmentNeedLabel[i]->setPosition(Vec2(this->getContentSize().width,
						menuDevelopmentNeedLabel[i - 1]->getPosition().y - menuDevelopmentNeedLabel[i]->getContentSize().height));
				}
			}

			MDNeedLabelRunAction(i);			

			if((i + 1) >= currentLabelCount)
				return;
		}		
		
	}
}

void CoffeeMachineLayer::MDNeedLabelRunAction(int index)
{
	MoveBy* move = MoveBy::create(0.5f, Vec2(0.0f, menuDevelopmentNeedLabel[index]->getContentSize().height * 1.5f));
	DelayTime* delay = DelayTime::create(1.0f);
	FadeOut* fadeOut = FadeOut::create(0.5f);
	CallFunc* callback = CallFunc::create(CC_CALLBACK_0(CoffeeMachineLayer::CallbackMDNeedLabelActiveFalse, this, index));
	Sequence* seq = Sequence::create(move, delay, fadeOut, callback, NULL);
	menuDevelopmentNeedLabel[index]->runAction(seq);
}

void CoffeeMachineLayer::CallbackMDNeedLabelActiveFalse(int index)
{
	//menuDevelopmentNeedLabel[index]->stopAllActions();
	
	--currentLabelCount;
	menuDevelopmentNeedLabel[index]->setVisible(false);
	
}

void CoffeeMachineLayer::CoffeeMachineClose()
{
	listener->setSwallowTouches(false);
	this->setVisible(false);
}

void CoffeeMachineLayer::CallbackCoffeeMachineClose(Ref* pSender)
{
	CoffeeMachineClose();
}

void CoffeeMachineLayer::CallbackLeftArrow(Ref* pSender)
{
	PageView* pageView = dynamic_cast<PageView*>(this->getChildByTag(eINDEX_PAGE_COFFEE_MACHINE::TAG_PAGE_VIEW_COFFEE_MACHINE));
	if (pageView == NULL)
		return;
	int index = pageView->getCurrentPageIndex();

	if (index >= eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_MAX)
		index = eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_MAX - 1;

	--index;
	if (index < eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_NAME_SYRUP)
		return;

	pageView->scrollToPage(index);
}

void CoffeeMachineLayer::CallbackRightArrow(Ref* pSender)
{
	PageView* pageView = dynamic_cast<PageView*>(this->getChildByTag(eINDEX_PAGE_COFFEE_MACHINE::TAG_PAGE_VIEW_COFFEE_MACHINE));
	if (pageView == NULL)
		return;
	int index = pageView->getCurrentPageIndex();

	if (index < eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_NAME_SYRUP)
		index = eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_NAME_SYRUP;

	++index;
	if (index == eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_SALE_PRICE)
	{
		makePrice = GetMenuDevelopmentPrice();
		menuDevelopmentSalePrice->SetBasicSalePrice(makePrice / RATE_SALE_PRICE);
	}
	else if (index == eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_COMPREHENSIVE)
	{
		SetMenuDevelopmentComprehensive();
	}
	else if(index == eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_MAX)
	{ 
		
		char makePriceString[256] = { '\0', };
		sprintf(makePriceString, "%s \n(비용 : %d) \n메뉴 개발하시겠습니까?", GameManager::GetInstance()->GetCoffeeMenu().name, makePrice);
		GameManager::GetInstance()->CallPopUpLayer(GameManager::ePOP_UP_TYPE::TWO_BUTTON, "메뉴 개발", makePriceString, CC_CALLBACK_0(CoffeeMachineLayer::CallbackBuyMenuDevelopment, this));
	}
	else if (index > eINDEX_PAGE_COFFEE_MACHINE::PAGE_MD_MAX)
		return;

	pageView->scrollToPage(index);

}

void CoffeeMachineLayer::CallbackBuyMenuDevelopment()
{
	CCLOG("CallbackBuyMenuDevelopment");
	// 잔액 부족
	bool isGold = UserManager::GetInstance()->IsEnoughGold(makePrice);
	if (!isGold)
	{
		GameManager::GetInstance()->CallPopUpLayer(GameManager::ePOP_UP_TYPE::ONE_BUTTON, "잔액 부족", "Show Me\nThe Money???");
		return;
	}

	CoffeeMachineClose();
	UserManager::GetInstance()->MinusGold(makePrice);
	GameManager::GetInstance()->CallCoffeeMachineBuyMenuDevelopment();
}

void CoffeeMachineLayer::SetMenuDevelopmentComprehensive()
{
	SELECTED_COFFEE_MENU coffeeMenu = GameManager::GetInstance()->GetCoffeeMenu();

	menuDevelopmentComprehensive->SetMenuDevelopmentComprehensive(
		coffeeMenu.name,
		coffeeMenu.Syrup,
		GetCoffeeBeanStringByIndex(coffeeMenu.CoffeeBean),
		GetMlikStringByIndex(coffeeMenu.Milk),
		GetIceStringByIndex(coffeeMenu.Ice)
		);

}


char* CoffeeMachineLayer::GetCoffeeBeanStringByIndex(int labelStringIndex)
{
	int index;
	if (labelStringIndex == 0)
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_BASIC_COFFEE_BEAN;
	else
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_COFFEE_BEAN + labelStringIndex - 1;

	//	return DataFileManager::GetInstance()->GetMenuData(index)->name;

	char* str = const_cast<char*>(DataFileManager::GetInstance()->GetString(DATA_TYPE_MENU, index));
	return str;
}

char* CoffeeMachineLayer::GetMlikStringByIndex(int labelStringIndex)
{
	int index;
	if (labelStringIndex == 0)
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_BASIC_MILK;
	else
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_MILK + labelStringIndex - 1;

	//return DataFileManager::GetInstance()->GetMenuData(index)->name;
	char* str = const_cast<char*>(DataFileManager::GetInstance()->GetString(DATA_TYPE_MENU, index));
	return str;
}

char* CoffeeMachineLayer::GetIceStringByIndex(int labelStringIndex)
{
	int index;
	if (labelStringIndex == 0)
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_BASIC_ICE;
	else
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_ICE + labelStringIndex - 1;

	
	//return DataFileManager::GetInstance()->GetMenuData(index)->name;
	char* str = const_cast<char*>(DataFileManager::GetInstance()->GetString(DATA_TYPE_MENU, index));
	return str;
}




int CoffeeMachineLayer::GetMenuDevelopmentPrice()
{
	SELECTED_COFFEE_MENU coffeeMenu = GameManager::GetInstance()->GetCoffeeMenu();
	int sum = 0;
	int index = 0;
		
	sum += (coffeeMenu.Syrup * MAKE_PRICE_SYRUP);
	
	if(coffeeMenu.CoffeeBean == 0)
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_BASIC_COFFEE_BEAN;
	else
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_COFFEE_BEAN + coffeeMenu.CoffeeBean - 1;	
	sum += DataFileManager::GetInstance()->GetMenuData(index)->makePrice;

	if (coffeeMenu.Milk == 0)
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_BASIC_MILK;
	else
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_MILK + coffeeMenu.Milk - 1;
	sum += DataFileManager::GetInstance()->GetMenuData(index)->makePrice;

	if (coffeeMenu.Ice == 0)
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_BASIC_ICE;
	else
		index = eDATA_FILE_REFERENCE_INDEX::DATA_FILE_MENU_ICE + coffeeMenu.Ice - 1;
	sum += DataFileManager::GetInstance()->GetMenuData(index)->makePrice;
	
	return sum;
}