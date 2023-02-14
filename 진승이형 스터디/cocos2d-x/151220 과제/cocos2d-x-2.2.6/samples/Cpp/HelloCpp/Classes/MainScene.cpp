#include "MainScene.h"
#include "AppMacros.h"
USING_NS_CC;

cocos2d::CCScene* CCMainScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	CCMainScene *layer = CCMainScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool CCMainScene::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}

	this->setTouchEnabled( true );
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCLabelTTF* pLabel[MOLE_MAX_NUM];
	
	for( int i = 0; i < MOLE_MAX_NUM; i++)
	{		
		char str[50];

		m_pMole[i] = CCMole::moleWithTexture( 
			CCTextureCache::sharedTextureCache()->addImage( "mole_stand.png" ) );

		if( m_pMole[i] )
		{
			m_pMole[i]->setPosition( ccp( 
				MARGINX * ( i % 3 ) + FIRSTMOLEPOSITIONX, 
				MARGINY * ( i % 2 ) + FIRSTMOLEPOSITIONY ) );
			m_pMole[i]->setScale( 4.0f );
			this->addChild( m_pMole[i] );		
		}

		
		sprintf( str, "x : %.0f / y : %.0f\nx : %.0f / y : %.0f",
			m_pMole[i]->getPositionX(), m_pMole[i]->getPositionY() );

		//	ÁÂÇ¥ test
		pLabel[i] = CCLabelTTF::create( str, "Arial", 10 );
		if( pLabel[i] )
		{			
			pLabel[i]->setPosition( ccp(
				m_pMole[i]->getPositionX(),
				m_pMole[i]->getPositionY() - 4 * ( m_pMole[i]->getContentSize().height / 2 ) ) );
			this->addChild( pLabel[i] );
		}
	}

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"game_end_normal.png",
		"game_end_click.png",
		this,
		menu_selector( CCMainScene::menuCloseCallback ) );		

	if( pCloseItem )
	{
		pCloseItem->setScale( 1.7f );
		pCloseItem->setPosition( ccp( 
			visibleSize.width - pCloseItem->getContentSize().width,
			pCloseItem->getContentSize().height ) );

		CCMenu* pMenu = CCMenu::create( pCloseItem, NULL );

		if( pMenu )
		{
			pMenu->setPosition( CCPointZero );
			this->addChild( pMenu );
		}		
	}

	return true;

}

void CCMainScene::menuCloseCallback( CCObject* pSender )
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
#endif
}

bool CCMainScene::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{	
	//CCPoint point = CCDirector::sharedDirector()->convertToGL( pTouch->getLocation(). );
	char str[50];
	//sprintf( str, "x : %.0f / y : %.0f", point.x, point.y );
	sprintf( str, "x : %.0f / y : %.0f", pTouch->getLocation().x, pTouch->getLocation().y );
	CCMessageBox( str, "test" );

	/*
	pGirl->setScale( 0.5f );
	pGirl->setPosition( pTouch->getLocation() );
	this->addChild( pGirl );
	
	for( int i = 0; i < MOLE_MAX_NUM; i++)
		if( pTouch->getLocation() == m_pMole[i]->getPosition() )
			break;
	*/
	return true;
}

void CCMainScene::registerWithTouchDispatcher( void )
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate( this, 0, true );
}