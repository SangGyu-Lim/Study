#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "Mole.h"

#define MARGINX				140
#define MARGINY				100
#define FIRSTMOLEPOSITIONX	100
#define FIRSTMOLEPOSITIONY	130

enum
{
	MOLE_ONE,
	MOLE_TWO,
	MOLE_THREE,
	MOLE_FORE,
	MOLE_FIVE,
	MOLE_SIX,
	MOLE_MAX_NUM
};

class CCMainScene : public cocos2d::CCLayer
{
public:
	CCMole* m_pMole[MOLE_MAX_NUM];

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCloseCallback(CCObject* pSender);

	void registerWithTouchDispatcher(void);
	bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	// implement the "static node()" method manually
	CREATE_FUNC(CCMainScene);
};

#endif