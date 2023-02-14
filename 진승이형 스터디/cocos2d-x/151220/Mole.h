#ifndef __MOLE_H__
#define __MOLE_H__

#include "cocos2d.h"

class CCMole : public cocos2d::CCSprite
{
private:
	CCSprite* m_pMoleImage;

public:
	CCMole();
	~CCMole();

	static CCMole* moleWithTexture( cocos2d::CCTexture2D* moleTexture );	

	void moleChangeTexture( void );

};

#endif