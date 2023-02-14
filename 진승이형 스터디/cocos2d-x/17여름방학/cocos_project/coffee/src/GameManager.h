#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "cocos2d.h"
#include "Singleton.h"

typedef struct
{
	int CoffeeBean;
	int Syrup;
	int Milk;
	int Ice;
	int SalePrice;
	char name[32];
}SELECTED_COFFEE_MENU, *LPSELECTED_COFFEE_MENU;

class GameManager// : public Singleton<GameManager>
{
public:
	static GameManager* GetInstance();	
	static void destroy();

private:

	static GameManager* m_instance;	

	GameManager(GameManager const&) {};
	GameManager& operator=(GameManager const&) {};

	GameManager() { m_instance = static_cast <GameManager*> (this); }
	~GameManager() {  };

public:


	enum eLAYER_INDEX
	{
		MAIN = 0,
		TOP,
		BOTTOM,
		SHOP,
		COUNTER,
		COFFEE_MACHINE
	};

	enum ePRODUCT_TYPE_INDEX
	{
		COFFEE_BEAN = 0,
		MILK,
		ICE,
		PRODUCT_TYPE_INDEX_MAX
	};

	enum ePRODUCT_GRADE_INDEX
	{
		NORMAL = 0,
		RARE,
		HIDDEN,
		PRODUCT_GRADE_INDEX_MAX
	};

	enum eMD_SELECTED_COFFEE_MENU_TYPE
	{
		SELECTED_COFFEE_BEAN = 0,
		SELECTED_SYRUP,
		SELECTED_MILK,
		SELECTED_ICE,
		SELECTED_SALE_PRICE
	};

	enum ePOP_UP_TYPE
	{
		ONE_BUTTON = 0,
		TWO_BUTTON
	};

private:
	SELECTED_COFFEE_MENU coffeeMenu;

	bool isMenuDevelopment[PRODUCT_TYPE_INDEX_MAX][PRODUCT_GRADE_INDEX_MAX];
	int currentMenuCount;

public:
	
	void InitGameManager();

	void CallLayer(eLAYER_INDEX index);
	void CallPopUpLayer(ePOP_UP_TYPE index, char* titleString, char* contentString, const cocos2d::ccMenuCallback& callbackOKButton = NULL);
	
	void CallShopBuyProduct(int index);
	void CompleteMenuDevelopment(int index);

	void CallCoffeeMachineBuyMenuDevelopment();
	void CompleteMenu();

	void InitIsMenuDevelopment();	
	bool IsMenuDevelopmentByIndex(int index);
	void CallMenuDevelopmentNeedLabel();

	void InitCoffee();
	void SetCoffeeName(const char* coffeeName);
	void SetCoffeeMenu(eMD_SELECTED_COFFEE_MENU_TYPE typeIndex, int selectedMenu);
	SELECTED_COFFEE_MENU GetCoffeeMenu();

	inline int GetCurrentMenuCount() { return currentMenuCount; }

	void testAndroidCallbackString(std::string str);
	void test();

};

#endif // !__GAME_MANAGER_H__
