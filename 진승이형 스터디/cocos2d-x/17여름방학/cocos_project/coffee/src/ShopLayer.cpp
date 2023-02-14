#include "ShopLayer.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"
#include "UserManager.h"
#include "DataFileManager.h"

USING_NS_CC;
using namespace cocos2d::ui;

LayerColor* ShopLayer::createLayer()
{
	ShopLayer* layer = ShopLayer::create();

	return layer;
}

bool ShopLayer::init()
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
	
	InitShopMenu();
	InitTouchEvent();

	return true;
}

void ShopLayer::InitShopMenu()
{
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto backgroundTop = Sprite::create("BackgroundShopTop.png");
	if (backgroundTop == NULL)
		return;
	backgroundTop->setAnchorPoint(Vec2(0.0f, 1.0f));
	backgroundTop->setPosition(Vec2(0.0f,
		this->getContentSize().height - backgroundTop->getContentSize().height));
	//backgroundTop->setVisible(false);
	this->addChild(backgroundTop, eDEPTH_ORDER_SHOP::SPRITE_BACKGROUND);

	auto pageView = PageView::create();
	if (pageView == NULL)
		return;
	pageView->setTouchEnabled(true);
	pageView->setAnchorPoint(Vec2(0.0f, 1.0f));
	pageView->setPosition(Vec2(0.0f,
		this->getContentSize().height - backgroundTop->getContentSize().height));
	//pageView->setPosition(backgroundTop->getPosition());

	for (int i = 0; i < PRODUCT_TYPE; ++i)
	{
		productSprite[i] = Sprite::create("BackgroundShopMain.png");
		if (productSprite[i] == NULL)
			return;
		productSprite[i]->setAnchorPoint(Vec2(0.0f, 1.0f));
		productSprite[i]->setPosition(Vec2(0.0f,
			this->getContentSize().height - backgroundTop->getContentSize().height * 3.0f));
		/*productSprite[i]->setPosition(Vec2(origin.x,
			origin.y + visibleSize.height - backgroundTop->getContentSize().height));*/
		/*productSprite[i]->setPosition(Vec2(pageView->getPosition().x,
			pageView->getPosition().y - backgroundTop->getContentSize().height));*/
		/*productSprite[i]->setPosition(Vec2(origin.x,
			origin.y + visibleSize.height - backgroundTop->getContentSize().height * 2.0f));*/
		//productSprite[i]->setPosition(Vec2::ZERO);
		//productSprite[i]->setVisible(false);
		//this->addChild(productSprite[i], eDEPTH_ORDER_SHOP::SPRITE_BACKGROUND_BACK);

		

		auto layout = Layout::create();
		//layout->setAnchorPoint(Vec2(0.0f, 1.0f));
		layout->setContentSize(Size(productSprite[i]->getContentSize().width,
			productSprite[i]->getContentSize().height));
		//layout->setPosition(Vec2(origin.x,
		//	origin.y + visibleSize.height/* - backgroundTop->getContentSize().height*/));
		layout->setPosition(Vec2(0.0f,
			this->getContentSize().height - backgroundTop->getContentSize().height));
		//layout->setZOrder(eDEPTH_ORDER_SHOP::LAYOUT);
		/*layout->setPosition(Vec2(pageView->getPosition().x,
			pageView->getPosition().y - backgroundTop->getContentSize().height));*/

		//productSprite[i]->setPosition(layout->getPosition());
		layout->addChild(productSprite[i]/*, eDEPTH_ORDER_SHOP::SPRITE_BACKGROUND_BACK*/);

		if (i == 0)
			pageView->addPage(layout);
		else
			pageView->insertPage(layout, i);

		InitProduct(i, productSprite[i]->getPosition());
	}
	pageView->setContentSize(Size(productSprite[0]->getContentSize().width,
		productSprite[0]->getContentSize().height));
	pageView->setTag(eINDEX_PAGE_SHOP::TAG_PAGE_VIEW_SHOP);
	pageView->setFocusEnabled(true);
	//pageView->setPosition(productSprite[0]->getPosition());
	
	//pageView.page

	this->addChild(pageView, eDEPTH_ORDER_SHOP::PAGE_VIEW);

	//productSprite[0]->setVisible(true);

	auto backgroundBottom = Sprite::create("BackgroundShopBottom.png");
	if (backgroundBottom == NULL)
		return;
	backgroundBottom->setAnchorPoint(Vec2(0.0f, 1.0f));
	//backgroundBottom->setVisible(false);
	backgroundBottom->setPosition(Vec2(pageView->getPosition().x,
		pageView->getPosition().y - pageView->getContentSize().height));
	this->addChild(backgroundBottom, eDEPTH_ORDER_SHOP::SPRITE_BACKGROUND);
	
	auto closeItem = MenuItemImage::create("LayerCloseNormal.png", "LayerCloseSelected.png",
		CC_CALLBACK_1(ShopLayer::CallbackShopClose, this));
	if (closeItem == NULL)
		return;
	closeItem->setAnchorPoint(Vec2(1.0f, 1.0f));
	closeItem->setPosition(Vec2(backgroundTop->getPosition().x + backgroundTop->getContentSize().width - closeItem->getContentSize().width * 0.2f,
		backgroundTop->getPosition().y - closeItem->getContentSize().height * 0.2f));
	closeItem->setZOrder(eDEPTH_ORDER_SHOP::MENU_ITEM);

	auto leftArrowItem = MenuItemImage::create("ShopLeftArrowNormal.png", "ShopLeftArrowSelected.png",
		CC_CALLBACK_1(ShopLayer::CallbackLeftArrow, this));
	if (leftArrowItem == NULL)
		return;
	leftArrowItem->setAnchorPoint(Vec2(0.0f, 1.0f));
	leftArrowItem->setPosition(Vec2(backgroundBottom->getPosition().x + leftArrowItem->getContentSize().width * 0.5f,
		backgroundBottom->getPosition().y));
	leftArrowItem->setZOrder(eDEPTH_ORDER_SHOP::MENU_ITEM);

	auto rightArrowItem = MenuItemImage::create("ShopRightArrowNormal.png", "ShopRightArrowSelected.png",
		CC_CALLBACK_1(ShopLayer::CallbackRightArrow, this));
	if (rightArrowItem == NULL)
		return;
	rightArrowItem->setAnchorPoint(Vec2(1.0f, 1.0f));
	rightArrowItem->setPosition(Vec2(backgroundBottom->getPosition().x + backgroundTop->getContentSize().width - rightArrowItem->getContentSize().width * 0.5f,
		backgroundBottom->getPosition().y));
	rightArrowItem->setZOrder(eDEPTH_ORDER_SHOP::MENU_ITEM);

	auto mainMenu = Menu::create(closeItem, leftArrowItem, rightArrowItem, NULL);
	mainMenu->setPosition(Vec2::ZERO);
	this->addChild(mainMenu, eDEPTH_ORDER_SHOP::MENU);

}

void ShopLayer::InitProduct(int index, Vec2 spritePosition)
{
	char productTitleName[256] = { '\0', };
	sprintf(productTitleName, "ShopTitle%d.png", index);
	Sprite* productTitle = Sprite::create(productTitleName);
	productTitle->setAnchorPoint(Vec2(0.0f, 1.0f));	
	productTitle->setPosition(spritePosition);
	productSprite[index]->addChild(productTitle, eDEPTH_ORDER_SHOP::SPRITE_UI);

	MenuItemImage* product[PRODUCT_COUNT];
	for (int i = 0; i < PRODUCT_COUNT; ++i)
	{
		char productNormalName[256] = { '\0', };
		sprintf(productNormalName, "ShopProductNormal%d%d.png", index, i);
		char productSelectedName[256] = { '\0', };
		sprintf(productSelectedName, "ShopProductSelected%d%d.png", index, i);

		product[i] = MenuItemImage::create(productNormalName, productSelectedName,
			CC_CALLBACK_1(ShopLayer::CallbackBuyConfirm, this));
		if (product[i] == NULL)
			return;
		product[i]->setAnchorPoint(Vec2(0.5f, 0.5f));
		product[i]->setPosition(Vec2(spritePosition.x + productSprite[index]->getContentSize().width * 0.5f,
			spritePosition.y - product[i]->getContentSize().height * (i + 1) * 1.8f));
		product[i]->setZOrder(eDEPTH_ORDER_SHOP::MENU_ITEM);
		product[i]->setTag(eTAG_PRODUCT::COFFEE_BEAN_NORMAL + index * 3 + i);
	}

	auto productMenu = Menu::create(product[0], product[1], product[2], NULL);
	productMenu->setPosition(Vec2::ZERO);
	productSprite[index]->addChild(productMenu, eDEPTH_ORDER_SHOP::MENU);
}






void ShopLayer::CallShopMenu(/*const ccMenuCallback& callback*/)
{
	listener->setSwallowTouches(true);
	this->setVisible(true);

	/*if (callback == NULL)
		return;
	_callback = callback;*/

}
//
//void ShopLayer::CallShopMenutest(const ccMenuCallback& callback)
//{
//
//	if (callback == NULL)
//	return;
//	callback(this);
//
//}

void ShopLayer::ShopClose()
{
	listener->setSwallowTouches(false);
	this->setVisible(false);
}




void ShopLayer::InitTouchEvent()
{
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	listener = EventListenerTouchOneByOne::create();
	if (listener == NULL)
		return;
	listener->setSwallowTouches(false);
	listener->onTouchBegan = CC_CALLBACK_2(ShopLayer::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}


bool ShopLayer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	CCLOG("ShopLayer onTouchBegan");
	return true;
}





void ShopLayer::CallbackShopClose(Ref* pSender)
{
	ShopClose();

	
}

void ShopLayer::CallbackBuyConfirm(Ref* pSender)
{
	MenuItemImage* product = dynamic_cast<MenuItemImage*>(pSender);
	if (product == NULL)
		return;
	
	buyProductTag = product->getTag();	

	GameManager::GetInstance()->CallPopUpLayer(GameManager::ePOP_UP_TYPE::TWO_BUTTON, "재료 구매", "menu\nbuy?", CC_CALLBACK_0(ShopLayer::CallbackBuyProduct, this));
	
}

void ShopLayer::CallbackBuyProduct()
{
	int index = buyProductTag % eTAG_PRODUCT::COFFEE_BEAN_NORMAL;

	// 잔액 확인
	if (DataFileManager::GetInstance()->GetMenuData(index) == nullptr || DataFileManager::GetInstance()->GetMenuData(index) == NULL)
	{
		CCLOG("NULL NULL NULL NULL NULL << ShopLayer CallbackBuyProduct() >> NULL NULL NULL NULL NULL");
	}
		int buyGold = DataFileManager::GetInstance()->GetMenuData(index)->buyPrice;
	CCLOG("---------Before << ShopLayer CallbackBuyProduct() >> buyPrice--------------------");
	bool isGold = UserManager::GetInstance()->IsEnoughGold(buyGold);
	if (!isGold)
	{
		GameManager::GetInstance()->CallPopUpLayer(GameManager::ePOP_UP_TYPE::ONE_BUTTON, "잔액 부족", "자본주의의 폐해~~~");
		return;
	}

	// 구매 여부 확인
	bool isBuy = GameManager::GetInstance()->IsMenuDevelopmentByIndex(index);
	if (isBuy)
	{
		GameManager::GetInstance()->CallPopUpLayer(GameManager::ePOP_UP_TYPE::ONE_BUTTON, "구매한 제품", "무소유\n책이나 사시길...");
		return;
	}


	ShopClose();
	UserManager::GetInstance()->MinusGold(buyGold);
	GameManager::GetInstance()->CallShopBuyProduct(index);
	

	
}

void ShopLayer::CallbackLeftArrow(Ref* pSender)
{
	PageView* pageView = dynamic_cast<PageView*>(this->getChildByTag(eINDEX_PAGE_SHOP::TAG_PAGE_VIEW_SHOP));
	if (pageView == NULL)
		return;
	int index = pageView->getCurrentPageIndex();

	if (index > eINDEX_PAGE_SHOP::PAGE_ICE)
		index = eINDEX_PAGE_SHOP::PAGE_ICE;

	--index;
	if (index < eINDEX_PAGE_SHOP::PAGE_COFFEE_BEAN)
		return;

	pageView->scrollToPage(index);
}

void ShopLayer::CallbackRightArrow(Ref* pSender)
{
	PageView* pageView = dynamic_cast<PageView*>(this->getChildByTag(eINDEX_PAGE_SHOP::TAG_PAGE_VIEW_SHOP));
	if (pageView == NULL)
		return;
	int index = pageView->getCurrentPageIndex();

	if (index < eINDEX_PAGE_SHOP::PAGE_COFFEE_BEAN)
		index = eINDEX_PAGE_SHOP::PAGE_COFFEE_BEAN;

	++index;
	if (index > eINDEX_PAGE_SHOP::PAGE_ICE)
		return;

	pageView->scrollToPage(index);
	
}