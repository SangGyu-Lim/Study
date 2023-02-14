#include "MenuDevelopmentComprehensive.h"
#include "SimpleAudioEngine.h"
#include "Define.h"

USING_NS_CC;
using namespace cocos2d::ui;

Sprite* MenuDevelopmentComprehensive::createSprite()
{
	return MenuDevelopmentComprehensive::create();
}

bool MenuDevelopmentComprehensive::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	InitMenuDevelopmentComprehensive();

	return true;
}

void MenuDevelopmentComprehensive::InitMenuDevelopmentComprehensive()
{
	//string filePath = FileUtils::getInstance()->fullPathForFilename(DATA_FILENAME_FONT);
	
	

	auto background = Sprite::create("BackgroundCoffeeMachineComprehensive.png");
	if (background == NULL)
		return;
	this->setDisplayFrame(background->getDisplayFrame());

	this->setPosition(Vec2(background->getContentSize().width * 0.5f,
		background->getContentSize().height * 0.5f));

	for (int i = 0; i < 5; ++i)
	{
		char comprehensiveImageName[256] = { '\0', };
		sprintf(comprehensiveImageName, "ComprehensiveImage%d.png", i);

		auto comprehensiveImage = Sprite::create(comprehensiveImageName);
		if (comprehensiveImage == NULL)
			return;
		comprehensiveImage->setAnchorPoint(Vec2(1.0f, 0.5f));
		comprehensiveImage->setPosition(Vec2(comprehensiveImage->getContentSize().width * 1.3f,
			this->getContentSize().height - comprehensiveImage->getContentSize().height * 2.0f - comprehensiveImage->getContentSize().height * i));
		this->addChild(comprehensiveImage/*, eDEPTH_ORDER_SHOP::SPRITE_BACKGROUND*/);

		//auto comprehensiveLabel = LabelTTF::create(UTIL::UTF8("커피맛") , "fonts/HamChoRong_BaTang.ttf", 24);
		// 잠시
		auto comprehensiveLabel = LabelTTF::create("None Title", "fonts/NanumGothic.ttf", 24);
		if (comprehensiveLabel == NULL)
			return;
		comprehensiveLabel->setAnchorPoint(Vec2(0.0f, 0.5f));
		comprehensiveLabel->setColor(Color3B::BLACK);
		comprehensiveLabel->setPosition(Vec2(comprehensiveImage->getPosition().x + comprehensiveImage->getContentSize().width * 0.5f,
			comprehensiveImage->getPosition().y));
		comprehensiveLabel->setTag(eTAG_COMPREHENSIVE::COFFEE_NAME + i);
		this->addChild(comprehensiveLabel/*, eDEPTH_ORDER_TOP::LABEL*/);
	}

	//auto comprehensiveImage1 = Sprite::create("ComprehensiveImage4.png");
	//if (comprehensiveImage1 == NULL)
	//	return;
	//comprehensiveImage1->setAnchorPoint(Vec2(1.0f, 0.5f));
	//comprehensiveImage1->setPosition(Vec2(comprehensiveImage1->getContentSize().width * 1.3f,
	//	this->getContentSize().height - comprehensiveImage1->getContentSize().height * 2.0f - comprehensiveImage1->getContentSize().height * 4));
	//this->addChild(comprehensiveImage1/*, eDEPTH_ORDER_SHOP::SPRITE_BACKGROUND*/);

	//auto comprehensiveLabel1 = LabelTTF::create("None Title", "fonts/NanumGothic.ttf", 24);
	//if (comprehensiveLabel1 == NULL)
	//	return;
	//comprehensiveLabel1->setAnchorPoint(Vec2(0.0f, 0.5f));
	//comprehensiveLabel1->setColor(Color3B::BLACK);
	//comprehensiveLabel1->setPosition(Vec2(comprehensiveImage1->getPosition().x + comprehensiveImage1->getContentSize().width * 0.5f,
	//	comprehensiveImage1->getPosition().y));
	//comprehensiveLabel1->setTag(eTAG_COMPREHENSIVE::ICE);
	//this->addChild(comprehensiveLabel1/*, eDEPTH_ORDER_TOP::LABEL*/);

}

void MenuDevelopmentComprehensive::SetMenuDevelopmentComprehensive(char* coffeeNameString, int syrupAmount, char* coffeeBeanString, char* milkString, char* IceString)
{
	auto labelName = dynamic_cast<LabelTTF*>(this->getChildByTag(eTAG_COMPREHENSIVE::COFFEE_NAME));
	if (labelName == NULL)
		return;
	labelName->setString(coffeeNameString);

	//string

	auto labelSyrup = dynamic_cast<LabelTTF*>(this->getChildByTag(eTAG_COMPREHENSIVE::SYRUP));
	if (labelSyrup == NULL)
		return;
	char comprehensiveSyrupAmount[256] = { '\0', };
	sprintf(comprehensiveSyrupAmount, "%dml", syrupAmount);
	labelSyrup->setString(comprehensiveSyrupAmount);

	
	auto labelCoffeeBean = dynamic_cast<LabelTTF*>(this->getChildByTag(eTAG_COMPREHENSIVE::COFFEE_BEAN));
	if (labelCoffeeBean == NULL)
		return;
	labelCoffeeBean->setString(coffeeBeanString);

	//reinterpret_cast<const String*>(coffeeBeanString)
	auto labelMilk = dynamic_cast<LabelTTF*>(this->getChildByTag(eTAG_COMPREHENSIVE::MILK));
	if (labelMilk == NULL)
		return;
	labelMilk->setString(milkString);

	auto labelIce = dynamic_cast<LabelTTF*>(this->getChildByTag(eTAG_COMPREHENSIVE::ICE));
	if (labelIce == NULL)
		return;
	labelIce->setString(IceString);
}

