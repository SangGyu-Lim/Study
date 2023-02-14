#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Mole.h"
#include "network\HttpClient.h"

#define MOLE_MAX_COUNT 9

class Game : public cocos2d::Scene
{
public:

	enum eTAG_LABEL
	{
		PLAY_TIME = 100,
		SCORE,
		GAME_OVER,
		TOTAL_SCORE
	};

	enum eTAG_SPRITE
	{
		HAMMER_ATTACK_0 = 200,
		HAMMER_ATTACK_1,
		HAMMER_ATTACK_2
	};

	static cocos2d::Scene* createScene();

	Mole* mole[MOLE_MAX_COUNT];

	// timer
	long moleShowTimer;
	long playTimeTimer;
	long realPlayTime;

	int score = 0;

	bool isTimeout = false;

	// init
	virtual bool init();
	
	/* scene 스케쥴링 */
	virtual void update(float f);
	
	void InitBackground();
	void InitMole();
	void InitLabel();
	void InitTimer();
	void InitHammer();

	// touch event
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	long GetTime();

	// 갱신
	void UpdateScore();
	void UpdateTimer(float time);
	void UpdateHammmer(cocos2d::Vec2 molePosition);
	void UpdateGameOver();
	void UpdateTotalScore(char* totalScoreStr);

	// call back
	void CallbackChangeHammerImage(int prevImageTag, int nextImageTag);
	void CallbackHammerEnd();
	void CallbackFadeInGameOver();
	void CallbackChangeScene();

	// network
	void CallNetwork(int resultScore);
	void CallbackNetworkRequest(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response);

	CREATE_FUNC(Game);
};

#endif // __GAME_SCENE_H__
