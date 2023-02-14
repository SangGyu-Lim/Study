#include "Mole.h"
#include "AppMacros.h"
USING_NS_CC;

CCMole::CCMole()
{
	init();
}

bool CCMole::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}

	for( int i = 0; i < 6; i++ )
	{
		//	두더지 버튼 6개 생성
		m_pMoleBtn[ i ] = CCMenuItemImage::create(
			"mole_stand.png",
			"mole_click.png",
			"mole_normal.png",
			this,
			menu_selector( CCMole::moleClick ) );
		
		if( m_pMoleBtn[ i ] )
		{
			m_pMoleBtn[ i ]->setScale( 4.0f );
			m_pMoleBtn[ i ]->setEnabled( false );

			//	두더지 버튼을 컨트롤 할 메뉴 6개 생성
			m_pMoleMenu[ i ] = CCMenu::create( m_pMoleBtn[ i ], NULL );

			if( m_pMoleMenu[ i ] )
			{
				m_pMoleMenu[ i ]->setPosition( ccp( 0, 0 ) );
				//this->addChild( m_pMoleMenu[ i ] );
			}
		}
	}

	//	두더지 버튼 6개 위치 설정
	m_pMoleBtn[ 0 ]->setPosition( ccp( 
		FIRSTMOLEPOSITIONX, 
		FIRSTMOLEPOSITIONY ) );
	m_pMoleBtn[ 1 ]->setPosition( ccp( 
		m_pMoleBtn[ 0 ]->getPositionX() + MARGIN * m_pMoleBtn[ 0 ]->getContentSize().width, 
		FIRSTMOLEPOSITIONY ) );
	m_pMoleBtn[ 2 ]->setPosition( ccp( 
		m_pMoleBtn[ 1 ]->getPositionX() + MARGIN * m_pMoleBtn[ 1 ]->getContentSize().width, 
		FIRSTMOLEPOSITIONY ) );
	m_pMoleBtn[ 3 ]->setPosition( ccp( 
		FIRSTMOLEPOSITIONX, 
		m_pMoleBtn[ 0 ]->getPositionY() + MARGIN * m_pMoleBtn[ 0 ]->getContentSize().height ) );		
	m_pMoleBtn[ 4 ]->setPosition( ccp( 
		m_pMoleBtn[ 3 ]->getPositionX() + MARGIN * m_pMoleBtn[ 3 ]->getContentSize().width, 
		m_pMoleBtn[ 1 ]->getPositionY() + MARGIN * m_pMoleBtn[ 1 ]->getContentSize().height ) );		
	m_pMoleBtn[ 5 ]->setPosition( ccp( 
		m_pMoleBtn[ 4 ]->getPositionX() + MARGIN * m_pMoleBtn[ 4 ]->getContentSize().width, 
		m_pMoleBtn[ 2 ]->getPositionY() + MARGIN * m_pMoleBtn[ 2 ]->getContentSize().height ) );		









}

void CCMole::moleClick( CCObject* pSender )
{
	
}

void CCMole::randMoleAppear()
{




}



