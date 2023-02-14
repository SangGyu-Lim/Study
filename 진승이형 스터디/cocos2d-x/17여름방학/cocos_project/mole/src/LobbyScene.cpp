#include "LobbyScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"

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

	InitTitle();
	InitButton();

	return true;
}

void Lobby::InitTitle()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Label* labelTitle = Label::createWithTTF("Lobby Title", "fonts/Marker Felt.ttf", 40);
	labelTitle->setAnchorPoint(Vec2(0.5f, 1.0f));
	labelTitle->setPosition(Vec2(origin.x + visibleSize.width * 0.5f,
		origin.y + visibleSize.height - labelTitle->getContentSize().height));
	this->addChild(labelTitle, 0);
}

void Lobby::InitButton()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto buttonNextScene = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_0(Lobby::CallbackNextScene, this));
	buttonNextScene->setPosition(Vec2(origin.x + visibleSize.width * 0.5f,
		origin.y + visibleSize.height * 0.5f));
	buttonNextScene->setScale(2.0f, 2.0f);

	auto menu = Menu::create(buttonNextScene, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
}

void Lobby::CallbackNextScene()
{
	auto scene = Game::createScene();

	Director::getInstance()->pushScene(scene);
	//Director::getInstance()->replaceScene(scene);
}