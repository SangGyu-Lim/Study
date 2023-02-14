#include "LoginScene.h"
#include "SimpleAudioEngine.h"
#include "LobbyScene.h"

USING_NS_CC;

Scene* Login::createScene()
{
	return Login::create();
}

bool Login::init()
{
	if (!Scene::init())
	{
		return false;
	}

	InitTitle();
	InitButton();

	return true;
}

void Login::InitTitle()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Label* labelTitle = Label::createWithTTF("Login Title", "fonts/Marker Felt.ttf", 40);
	labelTitle->setAnchorPoint(Vec2(0.5f, 1.0f));
	labelTitle->setPosition(Vec2(origin.x + visibleSize.width * 0.5f,
		origin.y + visibleSize.height - labelTitle->getContentSize().height));
	this->addChild(labelTitle, 0);
}

void Login::InitButton()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto buttonNextScene = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_0(Login::CallbackNextScene, this));
	buttonNextScene->setPosition(Vec2(origin.x + visibleSize.width * 0.5f,
		origin.y + visibleSize.height * 0.5f));
	buttonNextScene->setScale(2.0f, 2.0f);

	auto menu = Menu::create(buttonNextScene, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
}

void Login::CallbackNextScene()
{
	auto scene = Lobby::createScene();

	Director::getInstance()->replaceScene(scene);

}
