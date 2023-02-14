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

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	
	for( int i = 0; i < MOLE_MAX_NUM; i++)
	{
		m_pMole[i] = CCMole::moleWithTexture( CCTextureCache::sharedTextureCache()->addImage( "mole_normal.png" ) );

		if( m_pMole[i] )
		{
			m_pMole[i]->setPosition( ccp( 
				MARGINX * ( i % 3 ) + FIRSTMOLEPOSITIONX, 
				MARGINY * ( i % 2 ) + FIRSTMOLEPOSITIONY ) );
			m_pMole[i]->setScale( 4.0f );
			this->addChild( m_pMole[i] );		
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

void CCMainScene::randMoleAppear()
{
	

	

}

