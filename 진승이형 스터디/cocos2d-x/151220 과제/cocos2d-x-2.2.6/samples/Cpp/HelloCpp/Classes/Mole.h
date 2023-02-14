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

	//	�ʱ�ȭ
	static CCMole* moleWithTexture( cocos2d::CCTexture2D* moleTexture );

	//	�̹��� ����
	void moleChangeTexture( void );

	//	���� ��ȯ �� ����
	inline int getMoleStatus( void )				{ return m_MoleStatus; }
	inline void setMoleStatus( int moleStatus )	{ m_MoleStatus = moleStatus; }

};

#endif


/*
Mole Class Design

Need List
1.	Status Enum											�Ϸ�
2.	Funtion( private, public )
3.	Member( private, public )
4.	Inheritance( CCSprite or CCMenuItemSprite )

�ʿ��� function�� param���� ����

*/