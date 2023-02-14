#include "TopLayer.h"
#include "SimpleAudioEngine.h"
#include "UserManager.h"

USING_NS_CC;

LayerColor* TopLayer::createLayer()
{
	TopLayer* layer = TopLayer::create();

	return layer;
}

bool TopLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 0, 255)))
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->ignoreAnchorPointForPosition(false);
	this->setAnchorPoint(Vec2(0.0f, 1.0f));
	this->setPosition(Vec2(0.0f, origin.y + visibleSize.height));

	InitTopMenu();

	return true;
}

void TopLayer::InitTopMenu()
{
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("BackgroundTop.png");
	if (background == NULL)
		return;

	this->setContentSize(background->getContentSize());
	background->setAnchorPoint(Vec2::ZERO);
	background->setPosition(Vec2::ZERO);
	this->addChild(background, eDEPTH_ORDER_TOP::SPRITE_BACKGROUND);

	Sprite* clock = Sprite::create("Clock.png");
	if (clock == NULL)
		return;
	clock->setAnchorPoint(Vec2(0.0f, 0.5f));
	clock->setPosition(Vec2(origin.x + this->getContentSize().width * 0.1f,
		origin.y + this->getContentSize().height * 0.7f));
	this->addChild(clock, eDEPTH_ORDER_TOP::SPRITE_UI);

	char survivalDayName[256] = { '\0', };
	sprintf(survivalDayName, " '%d' 일 생존중....", UserManager::GetInstance()->GetSurvivalDay());
	survivalDay = LabelTTF::create(survivalDayName, "fonts/HamChoRong_BaTang.ttf", 24);
	if (survivalDay == NULL)
		return;
	survivalDay->setAnchorPoint(Vec2(0.0f, 0.5f));
	survivalDay->setColor(Color3B::WHITE);
	survivalDay->setPosition(Vec2(clock->getPosition().x + clock->getContentSize().width,
		clock->getPosition().y));
	this->addChild(survivalDay, eDEPTH_ORDER_TOP::LABEL);

	Sprite* money = Sprite::create("Money.png");
	if (money == NULL)
		return;
	money->setAnchorPoint(Vec2(0.0f, 0.5f));
	money->setPosition(Vec2(origin.x + this->getContentSize().width * 0.1f,
		origin.y + this->getContentSize().height * 0.3f));
	this->addChild(money, eDEPTH_ORDER_TOP::SPRITE_UI);

	char capitalName[256] = { '\0', };
	//sprintf(capitalName, "자본금 x %d", UserManager::GetInstance()->GetGold());
	sprintf(capitalName, " '%d' 일 생존중....", UserManager::GetInstance()->GetSurvivalDay());
	//capital = LabelTTF::create(capitalName, "fonts/HamChoRong_BaTang.ttf", 24);
	capital = Label::createWithTTF(capitalName, "fonts/HamChoRong_BaTang.ttf", 24);
	if (capital == NULL)
		return;
	capital->setAnchorPoint(Vec2(0.0f, 0.5f));
	capital->setColor(Color3B::YELLOW);
	capital->setPosition(Vec2(money->getPosition().x + money->getContentSize().width,
		money->getPosition().y));
	this->addChild(capital, eDEPTH_ORDER_TOP::LABEL);
	

}


void TopLayer::SetSurvivalDayLabel()
{	
	char survivalDayName[256] = { '\0', };
	sprintf(survivalDayName, " '%d' 일 생존중....", UserManager::GetInstance()->GetSurvivalDay());
	survivalDay->setString(survivalDayName);
}

void TopLayer::SetGoldLabel()
{
	char capitalName[256] = { '\0', };
	sprintf(capitalName, "자본금 x %d", UserManager::GetInstance()->GetGold());
	capital->setString(capitalName);
}