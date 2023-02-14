#include "Mole.h"
#include "AppMacros.h"
USING_NS_CC;

CCMole::CCMole()
	: m_MoleStatus( MOLE_STATUS_HIDE )
{
	
}

CCMole::~CCMole()
{

}

CCMole* CCMole::moleWithTexture( CCTexture2D* moleTexture )
{
	CCMole* pMole = new CCMole();
	pMole->initWithTexture( moleTexture );
	pMole->autorelease();	
	
	return pMole;
}

void CCMole::moleChangeTexture( void )
{
	this->setTexture( CCTextureCache::sharedTextureCache()->addImage( "mole_stand.png" ) );
}
