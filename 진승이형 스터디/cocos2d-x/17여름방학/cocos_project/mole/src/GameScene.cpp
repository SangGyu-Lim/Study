#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace cocos2d::network;

Scene* Game::createScene()
{
	return Game::create();
}

#pragma region Init

bool Game::init()
{
	if (!Scene::init())
	{
		return false;
	}

	InitBackground();
	InitMole();
	InitLabel();
	InitTimer();
	InitHammer();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(Game::onTouchBegan, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	/* scene 스케쥴링 */
	this->scheduleUpdate();

	score = 0;
	isTimeout = false;

	return true;
}

const float frontBackgroundDistance[3] = { 0.0f, 122.0f, 252.0f };
void Game::InitBackground()
{
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* spriteBackground = Sprite::create("bg.png");
	if (spriteBackground == NULL)
		return;
	spriteBackground->setAnchorPoint(Vec2(0.0f, 0.0f));
	spriteBackground->setPosition(Vec2(origin.x, origin.y));
	this->addChild(spriteBackground, 0);

	for (int i = 0; i < 3; ++i)
	{
		char frontBackgroundName[256] = { '\0', };
		sprintf(frontBackgroundName, "bg_layer_%d.png", i);
		Sprite* spriteFrontBackground = Sprite::create(frontBackgroundName);
		if (spriteFrontBackground == NULL)
			return;

		spriteFrontBackground->setAnchorPoint(Vec2(0.0f, 0.0f));
		spriteFrontBackground->setPosition(Vec2(origin.x, origin.y + frontBackgroundDistance[i]));
		this->addChild(spriteFrontBackground, 6 - 2 * i);

	}
	
}

void Game::InitMole()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	for (int i = 0; i < MOLE_MAX_COUNT; ++i)
	{
		mole[i] = dynamic_cast<Mole*>(Mole::createSprite());
		if (mole[i] == NULL)
			return;

		mole[i]->setAnchorPoint(Vec2(0.0f, 0.0f));
		mole[i]->setPosition(visibleSize.width / 3 * (i % 3), visibleSize.height / 5.7f * (i / 3));
		mole[i]->SetHidePosition(Vec2( visibleSize.width / 3 * (i % 3), visibleSize.height / 5.7f * (i / 3)));
		
		/* mole 자체 스케쥴링 */
		//float randomScheduleTime = RandomHelper::random_real<float>(0.5f, 3.5f);
		//mole[i]->ActionSchedule(randomScheduleTime);

		this->addChild(mole[i], 5 - 2 * (i / 3));

	}
	
}

void Game::InitLabel()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Label* labelPlayTime = Label::createWithTTF("10.0", "fonts/Marker Felt.ttf", 40);
	labelPlayTime->setAnchorPoint(Vec2(0.5f, 1.0f));
	labelPlayTime->setPosition(Vec2(origin.x + visibleSize.width * 0.47f,
		origin.y + visibleSize.height - labelPlayTime->getContentSize().height));
	this->addChild(labelPlayTime, 8, eTAG_LABEL::PLAY_TIME);

	Label* labelScore = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 40);
	labelScore->setAnchorPoint(Vec2(1.0f, 1.0f));
	labelScore->setPosition(Vec2(origin.x + visibleSize.width * 0.95f,
		origin.y + visibleSize.height - labelScore->getContentSize().height));
	this->addChild(labelScore, 8, eTAG_LABEL::SCORE);

	Label* labelGameOver = Label::createWithTTF("Game Over", "fonts/Marker Felt.ttf", 60);
	labelGameOver->setAnchorPoint(Vec2(0.5f, 0.5f));
	labelGameOver->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	labelGameOver->setColor(Color3B::BLACK);
	labelGameOver->setOpacity(0);
	this->addChild(labelGameOver, 8, eTAG_LABEL::GAME_OVER);

	Label* labelTotalScore = Label::createWithTTF("1000", "fonts/Marker Felt.ttf", 60);
	labelTotalScore->setAnchorPoint(Vec2(0.5f, 1.0f));
	labelTotalScore->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2 - 2 * labelTotalScore->getContentSize().height));
	labelTotalScore->setColor(Color3B::BLACK);
	labelTotalScore->setOpacity(0);
	this->addChild(labelTotalScore, 8, eTAG_LABEL::TOTAL_SCORE);
}

void Game::InitTimer()
{
	moleShowTimer = GetTime();
	playTimeTimer = GetTime();

	realPlayTime = 10.0f;

}

void Game::InitHammer()
{
	Sprite* spriteHammer0 = Sprite::create("attack_0.png");
	if (spriteHammer0 == NULL)
		return;
	spriteHammer0->setAnchorPoint(Vec2(0.0f, 0.0f));
	spriteHammer0->setPosition(Vec2(0.0f, 0.0f));
	spriteHammer0->setVisible(false);
	this->addChild(spriteHammer0, 7, eTAG_SPRITE::HAMMER_ATTACK_0);

	Sprite* spriteHammer1 = Sprite::create("attack_1.png");
	if (spriteHammer1 == NULL)
		return;
	spriteHammer1->setAnchorPoint(Vec2(0.0f, 0.0f));
	spriteHammer1->setPosition(Vec2(0.0f, 0.0f));
	spriteHammer1->setVisible(false);
	this->addChild(spriteHammer1, 7, eTAG_SPRITE::HAMMER_ATTACK_1);

	Sprite* spriteHammer2 = Sprite::create("attack_2.png");
	if (spriteHammer2 == NULL)
		return;
	spriteHammer2->setAnchorPoint(Vec2(0.0f, 0.0f));
	spriteHammer2->setPosition(Vec2(0.0f, 0.0f));
	spriteHammer2->setVisible(false);
	this->addChild(spriteHammer2, 7, eTAG_SPRITE::HAMMER_ATTACK_2);
}

#pragma endregion

#pragma region ScheduleUpdate

/* scene 스케쥴링 */
const int moleShowReferenceTime = 800;	// 0.8초
const int playReferenceTime = 10000;	// 10초
void Game::update(float f)
{
	// 게임 시간 체크
	if (!isTimeout)
	{
		long currentTime = GetTime();

		// mole 출현
		if ((currentTime - moleShowTimer) >= moleShowReferenceTime)
		{
			int index = rand() % MOLE_MAX_COUNT;
			moleShowTimer = GetTime();

			if (mole[index]->GetState() == Mole::eSTATE_MOLE::IDLE)
			{
				mole[index]->ActionShow();
			}
		}

		// 게임 시간 체크
		if (realPlayTime > 0)
		{
			realPlayTime = playReferenceTime - (currentTime - playTimeTimer);
			float tempTime = realPlayTime / 1000.0f;

			UpdateTimer(tempTime);
		}
		else if (realPlayTime <= 0)
		{
			UpdateTimer(0.0f);

			isTimeout = true;

			CallNetwork(score);
		}
	}
	
}

#pragma endregion

bool Game::onTouchBegan(Touch* touch, Event* event)
{
	Vec2 touchLocation = touch->getLocation();

	for (int i = 0; i < MOLE_MAX_COUNT; ++i)
	{
		Rect moleRect = mole[i]->boundingBox();

		if (moleRect.containsPoint(touchLocation))
		{

			if (mole[i]->GetState() == Mole::eSTATE_MOLE::SHOW)
			{
				UpdateScore();
				UpdateHammmer(mole[i]->getPosition());
				mole[i]->ActionDie();
				break;
			}
		}
	}

	return true;
}

long Game::GetTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

#pragma region LocalUpdate

const int referenceScore = 100;
void Game::UpdateScore()
{
	DelayTime* delay = DelayTime::create(0.1f);
	this->runAction(delay);

	score += referenceScore;

	char tempStr[256] = { '\0', };
	sprintf(tempStr, "%d", score);

	Label* labelScore = dynamic_cast<Label*>(this->getChildByTag(eTAG_LABEL::SCORE));
	labelScore->setString(tempStr);
}

void Game::UpdateTimer(float time)
{
	char tempStr[256] = { '\0', };
	sprintf(tempStr, "%.1f", time);

	Label* labelPlayTime = dynamic_cast<Label*>(this->getChildByTag(eTAG_LABEL::PLAY_TIME));
	labelPlayTime->setString(tempStr);
}

void Game::UpdateHammmer(Vec2 molePosition)
{
	Sprite* spriteHammer = dynamic_cast<Sprite*>(this->getChildByTag(eTAG_SPRITE::HAMMER_ATTACK_0));

	Vec2 attackPosition;
	attackPosition.x = molePosition.x + spriteHammer->getContentSize().width / 6;
	attackPosition.y = molePosition.y + spriteHammer->getContentSize().height / 3;
	
	spriteHammer->setPosition(attackPosition);
	spriteHammer->setVisible(true);

	DelayTime* delay1 = DelayTime::create(0.1f);
	CallFunc* callback1 = CallFunc::create(CC_CALLBACK_0(Game::CallbackChangeHammerImage, this, eTAG_SPRITE::HAMMER_ATTACK_0, eTAG_SPRITE::HAMMER_ATTACK_1));
	DelayTime* delay2 = DelayTime::create(0.05f);
	CallFunc* callback2 = CallFunc::create(CC_CALLBACK_0(Game::CallbackChangeHammerImage, this, eTAG_SPRITE::HAMMER_ATTACK_1, eTAG_SPRITE::HAMMER_ATTACK_2));
	DelayTime* delay3 = DelayTime::create(0.35f);
	CallFunc* callback3 = CallFunc::create(CC_CALLBACK_0(Game::CallbackHammerEnd, this));

	Sequence* seq = Sequence::create(delay1, callback1, delay2, callback2, delay3, callback3, NULL);
	this->runAction(seq);
	
}

void Game::UpdateGameOver()
{
	CallFunc* callback1 = CallFunc::create(CC_CALLBACK_0(Game::CallbackFadeInGameOver, this));
	DelayTime* delay = DelayTime::create(3.0f);
	CallFunc* callback2 = CallFunc::create(CC_CALLBACK_0(Game::CallbackChangeScene, this));
	
	Sequence* seq = Sequence::create(callback1, delay, callback2, NULL);
	this->runAction(seq);
}

void Game::UpdateTotalScore(char* totalScoreStr)
{
	Label* labelTotalScore = dynamic_cast<Label*>(this->getChildByTag(eTAG_LABEL::TOTAL_SCORE));
	labelTotalScore->setString(totalScoreStr);
}

#pragma endregion

#pragma region Callback

void Game::CallbackChangeHammerImage(int prevImageTag, int nextImageTag)
{
	Sprite* spritePrevHammer = dynamic_cast<Sprite*>(this->getChildByTag(prevImageTag));
	if (spritePrevHammer == NULL)
		return;
	Sprite* spriteNextHammer = dynamic_cast<Sprite*>(this->getChildByTag(nextImageTag));
	if (spriteNextHammer == NULL)
		return;

	spriteNextHammer->setPosition(spritePrevHammer->getPosition());

	spritePrevHammer->setVisible(false);
	spriteNextHammer->setVisible(true);
}

void Game::CallbackHammerEnd()
{
	DelayTime* delay1 = DelayTime::create(0.05f);
	CallFunc* callback1 = CallFunc::create(CC_CALLBACK_0(Game::CallbackChangeHammerImage, this, eTAG_SPRITE::HAMMER_ATTACK_2, eTAG_SPRITE::HAMMER_ATTACK_1));
	DelayTime* delay2 = DelayTime::create(0.1f);
	CallFunc* callback2 = CallFunc::create(CC_CALLBACK_0(Game::CallbackChangeHammerImage, this, eTAG_SPRITE::HAMMER_ATTACK_1, eTAG_SPRITE::HAMMER_ATTACK_0));

	Sequence* seq = Sequence::create(delay1, callback1, delay2, callback2, NULL);
	this->runAction(seq);
	

	/*Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* spriteMole = Sprite::create(imageName);
	if (spriteMole == NULL)
		return;
	spriteMole->setPosition(Vec2::ZERO);
	this->setDisplayFrame(spriteMole->getDisplayFrame());*/
}

void Game::CallbackFadeInGameOver()
{
	Label* labelGameOver = dynamic_cast<Label*>(this->getChildByTag(eTAG_LABEL::GAME_OVER));
	Label* labelTotalScore = dynamic_cast<Label*>(this->getChildByTag(eTAG_LABEL::TOTAL_SCORE));

	FadeIn* labelFadeInGameOver = FadeIn::create(1.0f);
	FadeIn* labelFadeInTotalScore = FadeIn::create(1.0f);

	labelGameOver->runAction(labelFadeInGameOver);
	labelTotalScore->runAction(labelFadeInTotalScore);
}

void Game::CallbackChangeScene()
{
	Director::getInstance()->popScene();
}

#pragma endregion

#pragma region Network

void Game::CallNetwork(int resultScore)
{
	HttpRequest* request = new HttpRequest();

	char url[256] = { '\0', };
	sprintf(url, "http://localhost:3000/?score=%d", resultScore);

	request->setUrl(url);
	request->setRequestType(HttpRequest::Type::POST);
	request->setResponseCallback(this, httpresponse_selector(Game::CallbackNetworkRequest));
	request->setTag("Get test");

	HttpClient::getInstance()->send(request);
	request->release();
}

void Game::CallbackNetworkRequest(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response)
{
	std::vector<char>* responseData = response->getResponseData();
	char totalScoreStr[256] = { '\0', };

	for (int i = 0; i < responseData->size(); ++i)
	{
		sprintf(totalScoreStr, "%s%c", totalScoreStr, responseData->at(i));
	}

	UpdateTotalScore(totalScoreStr);
	UpdateGameOver();
}

#pragma endregion
