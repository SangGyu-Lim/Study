#ifndef __MOLE_H__
#define __MOLE_H__

#include "cocos2d.h"

enum
{
	MOLE_STATUS_HIDE,
	MOLE_STATUS_STAND,
	MOLE_STATUS_CLICK
};

class CCMole : public cocos2d::CCSprite
{
private:
	CCSprite* m_pMoleImage;
	int m_MoleStatus;

public:
	CCMole();
	~CCMole();

	//	초기화
	static CCMole* moleWithTexture( cocos2d::CCTexture2D* moleTexture );

	//	이미지 변경
	void moleChangeTexture( void );

	//	상태 반환 및 설정
	inline int getMoleStatus( void )				{ return m_MoleStatus; }
	inline void setMoleStatus( int moleStatus )	{ m_MoleStatus = moleStatus; }

};

#endif


/*
Mole Class Design

Need List
1.	Status Enum											완료
2.	Funtion( private, public )
3.	Member( private, public )
4.	Inheritance( CCSprite or CCMenuItemSprite )

필요한 function에 param까지 설계

*/