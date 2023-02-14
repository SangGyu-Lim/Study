#include "Mole.h"
#include "AppMacros.h"
USING_NS_CC;

CCMole::CCMole()	
{
	
}

CCMole::~CCMole()
{

}

CCMole* CCMole::moleWithTexture( CCTexture2D* moleTexture )
{
	CCMole* pMole = new CCMole();
	//pMole->initWithSpriteFrameName( "mole_normal.png" );
	pMole->initWithTexture( moleTexture );
	pMole->autorelease();	
	
	return pMole;
}

void CCMole::moleChangeTexture( void )
{
	this->setTexture( CCTextureCache::sharedTextureCache()->addImage( "mole_stand.png" ) );
}
