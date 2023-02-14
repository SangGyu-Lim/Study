#ifndef __MOLE_H__
#define __MOLE_H__

#include "cocos2d.h"

#define MARGIN					10
#define FIRSTMOLEPOSITIONX	100
#define FIRSTMOLEPOSITIONY	130

class CCMole : public cocos2d::CCLayer
{
public:

	cocos2d::CCMenuItemImage* m_pMoleBtn[ 6 ];
	cocos2d::CCMenu* m_pMoleMenu[ 6 ];

	CCMole();
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// a selector callback
	void moleClick( CCObject* pSender );
	void randMoleAppear();

};

#endif