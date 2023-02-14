#include "GameManager.h"
#include "LobbyScene.h"

USING_NS_CC;

GameManager* GameManager::m_instance = 0;

GameManager* GameManager::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new GameManager();
	}

	return m_instance;
}
	
void GameManager::destroy()
{
	delete m_instance;
	m_instance = 0;
}

void GameManager::InitGameManager()
{
	currentMenuCount = 0;
	InitIsMenuDevelopment();
	InitCoffee();
}


void GameManager::CallLayer(eLAYER_INDEX index)
{
	auto scene = dynamic_cast<Lobby*>(Director::getInstance()->getRunningScene());
	if (scene == NULL)
		return;

	switch (index)
	{
	case GameManager::MAIN:
		break;
	case GameManager::TOP:
		break;
	case GameManager::BOTTOM:
		break;
	case GameManager::SHOP:
		scene->CallShop();
		break;
	case GameManager::COUNTER:
		scene->CallCounter();
		break;
	case GameManager::COFFEE_MACHINE:
		scene->CallCoffeeMachine();
		break;	
	default:
		break;
	}
}

void GameManager::CallPopUpLayer(ePOP_UP_TYPE index, char* titleString, char* contentString, const ccMenuCallback& callbackOKButton)
{
	auto scene = dynamic_cast<Lobby*>(Director::getInstance()->getRunningScene());
	if (scene == NULL)
		return;

	switch (index)
	{
	case GameManager::ONE_BUTTON:
		scene->CallPopUpOneButton(titleString, contentString);
		break;
	case GameManager::TWO_BUTTON:
		scene->CallPopUpTwoButton(titleString, contentString, callbackOKButton);
		break;
	default:
		break;
	}

	
}

void GameManager::CallShopBuyProduct(int index)
{
	auto scene = dynamic_cast<Lobby*>(Director::getInstance()->getRunningScene());
	if (scene == NULL)
		return;

	scene->CallShopBuyProduct(index);
}

void GameManager::CompleteMenuDevelopment(int index)
{
	int typeIndex = index / ePRODUCT_TYPE_INDEX::PRODUCT_TYPE_INDEX_MAX;
	if ((typeIndex < ePRODUCT_TYPE_INDEX::COFFEE_BEAN) || (typeIndex > ePRODUCT_TYPE_INDEX::ICE))
		return;

	int gradeIndex = index % ePRODUCT_GRADE_INDEX::PRODUCT_GRADE_INDEX_MAX;
	if ((gradeIndex < ePRODUCT_GRADE_INDEX::NORMAL) || (gradeIndex > ePRODUCT_GRADE_INDEX::HIDDEN))
		return;

	isMenuDevelopment[typeIndex][gradeIndex] = true;
}

void GameManager::CallCoffeeMachineBuyMenuDevelopment()
{
	auto scene = dynamic_cast<Lobby*>(Director::getInstance()->getRunningScene());
	if (scene == NULL)
		return;

	scene->CallCoffeeMachineBuyMenuDevelopment();
}

void GameManager::CompleteMenu()
{
	auto scene = dynamic_cast<Lobby*>(Director::getInstance()->getRunningScene());
	if (scene == NULL)
		return;

	++currentMenuCount;
	scene->CallAddMenu();
}




void GameManager::InitIsMenuDevelopment()
{
	for (int i = 0; i < ePRODUCT_TYPE_INDEX::PRODUCT_TYPE_INDEX_MAX; ++i)
	{
		for (int j = 0; j < ePRODUCT_GRADE_INDEX::PRODUCT_GRADE_INDEX_MAX; ++j)
		{
			isMenuDevelopment[i][j] = false;
		}
	}
}



bool GameManager::IsMenuDevelopmentByIndex(int index)
{
	int typeIndex = index / ePRODUCT_TYPE_INDEX::PRODUCT_TYPE_INDEX_MAX;
	if ((typeIndex < ePRODUCT_TYPE_INDEX::COFFEE_BEAN) || (typeIndex > ePRODUCT_TYPE_INDEX::ICE))
		return false;

	int gradeIndex = index % ePRODUCT_GRADE_INDEX::PRODUCT_GRADE_INDEX_MAX;
	if ((gradeIndex < ePRODUCT_GRADE_INDEX::NORMAL) || (gradeIndex > ePRODUCT_GRADE_INDEX::HIDDEN))
		return false;

	return isMenuDevelopment[typeIndex][gradeIndex];
}

void GameManager::CallMenuDevelopmentNeedLabel()
{
	auto scene = dynamic_cast<Lobby*>(Director::getInstance()->getRunningScene());
	if (scene == NULL)
		return;

	scene->CallCoffeeMachineMDNeedLabel();
}







void GameManager::InitCoffee()
{
	coffeeMenu.CoffeeBean = 0;
	coffeeMenu.Syrup = 0;
	coffeeMenu.Milk = 0;
	coffeeMenu.Ice = 0;
	coffeeMenu.SalePrice = 0;
	sprintf(coffeeMenu.name, "no coffee name");
}

void GameManager::SetCoffeeName(const char* coffeeName)
{
	char* name = const_cast<char*>(coffeeName);
	sprintf(coffeeMenu.name, "%s", name);
	
}

void GameManager::SetCoffeeMenu(eMD_SELECTED_COFFEE_MENU_TYPE typeIndex, int selectedMenu)
{

	switch (typeIndex)
	{
	case GameManager::SELECTED_COFFEE_BEAN:
		coffeeMenu.CoffeeBean = selectedMenu;
		break;
	case GameManager::SELECTED_SYRUP:
		coffeeMenu.Syrup = selectedMenu;
		break;
	case GameManager::SELECTED_MILK:
		coffeeMenu.Milk = selectedMenu;
		break;
	case GameManager::SELECTED_ICE:
		coffeeMenu.Ice = selectedMenu;
		break;
	case GameManager::SELECTED_SALE_PRICE:
		coffeeMenu.SalePrice = selectedMenu;
		break;
	default:
		break;
	}
}

SELECTED_COFFEE_MENU GameManager::GetCoffeeMenu()
{
	return coffeeMenu;
}



void GameManager::testAndroidCallbackString(std::string str)
{
	CCLOG("cocos2d >> testAndroidCallbackString >> %s", str.c_str());
	//CCLOG("cocos2d >> testAndroidCallbackString");
}

void GameManager::test()
{
	auto scene = dynamic_cast<Lobby*>(Director::getInstance()->getRunningScene());
	if (scene == NULL)
		return;

	scene->test();
}