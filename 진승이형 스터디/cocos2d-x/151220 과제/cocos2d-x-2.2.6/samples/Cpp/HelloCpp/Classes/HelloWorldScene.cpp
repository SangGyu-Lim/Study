#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "MainScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	HelloWorld *layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);	

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}
	this->setTouchEnabled( true );
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object

	//	게임 종료 버튼 생성
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"game_end_normal.png",
		"game_end_click.png",
		this,
		menu_selector( HelloWorld::menuCloseCallback ) );

	if( pCloseItem )
	{
		pCloseItem->setScale( 1.7f );
		pCloseItem->setPosition( ccp( visibleSize.width - pCloseItem->getContentSize().width , pCloseItem->getContentSize().height ) );

		CCMenu* pMenu = CCMenu::create( pCloseItem, NULL );

		if( pMenu )
		{
			pMenu->setPosition( CCPointZero );
			this->addChild( pMenu );
		}		
	}


	// create menu, it's an autorelease object


	//	게임 시작 버튼 생성
	CCMenuItemImage* pChangeMainSceneBtn = CCMenuItemImage::create(
		"game_start_normal.png",
		"game_start_click.png",
		this,
		menu_selector( HelloWorld::changeMainScene ) );

	if( pChangeMainSceneBtn )
	{
		pChangeMainSceneBtn->setPosition( ccp( visibleSize.width / 2, visibleSize.height / 2 ) );
		pChangeMainSceneBtn->setScale( 2.5f );

		CCMenu* pChangeSceneMenu = CCMenu::create(pChangeMainSceneBtn, NULL);

		if( pChangeMainSceneBtn )
		{
			pChangeSceneMenu->setPosition( 0, 0 );
			this->addChild( pChangeSceneMenu );
		}		
	}

	//	타이틀 이미지
	CCSprite* pTitleImage = CCSprite::create( "game_title.png" );
	pTitleImage->setScale( 3.0f );
	pTitleImage->setPosition( ccp( visibleSize.width / 2, visibleSize.height - 3 * pTitleImage->getContentSize().height ) );
	this->addChild( pTitleImage );




















	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label
	/*
	CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);

	// position the label on the center of the screen
	pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
	origin.y + visibleSize.height - pLabel->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(pLabel, 1);

	// add "HelloWorld" splash screen"
	CCSprite* pSprite = CCSprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(pSprite, 0);
	*/

	//CCTouchDelegate* 

	/*
	CCSprite* pGirl = CCSprite::create("hyun.jpg");
	CCMenuItemImage* pButton = CCMenuItemImage::create( "won.png", "hyun.jpg", this, menu_selector(HelloWorld::callfunc));

	pButton->setPosition( ccp(100, 100));
	CCMenu* pMenu1 = CCMenu::create(pButton, NULL);
	pMenu1->setPosition(0, 0);
	this->addChild(pMenu1);
	//CCActionInterval* pGirlMove = CCMoveBy::create(1.0f, ccp(0, 0));
	//CCActionInterval* pGirlMove = CCMoveBy::create(1.0f, ccp(visibleSize.width / 2, visibleSize.height / 2));

	if(pGirl)
	{
	pGirl->setScale(0.5f);
	pGirl->setOpacity( 0 );
	pGirl->setPosition( ccp(visibleSize.width / 2, visibleSize.height / 2));
	//pGirl->setPosition( ccp(0, 0));
	//pGirl->runAction( CCMoveBy::create( 1.0f, ccp( 100, 100 ) ) );
	pGirl->runAction( CCSequence::create(
	CCFadeIn::create( 1.0f ),
	CCDelayTime::create( 0.2f ),
	CCMoveBy::create( 3.0f, ccp( 100, 100 ) ),
	CCJumpBy::create( 2.0f, ccp( 10, 10 ), 50, 1 ),
	CCSpawn::create( CCMoveTo::create( 2.0f, ccp( 200, 200 ) ), CCBlink::create( 2.0f, 5 ), NULL ),
	CCFadeOut::create( 1.0f ),
	//CCCallFunc::create( this, callfunc_selector(HelloWorld::callfunc) ), 
	NULL ) );
	this->addChild(pGirl);




	}
	*/
	return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
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

void HelloWorld::changeMainScene( CCObject* pSender )
{
	CCScene *pNextScene = CCMainScene::scene();

	CCDirector::sharedDirector()->replaceScene( pNextScene );
}

bool HelloWorld::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{
	CCSprite *pGirl = CCSprite::create( "hyun.jpg" );

	if(pGirl)
	{
		pGirl->setScale( 0.5f );
		pGirl->setPosition( pTouch->getLocation() );
		this->addChild( pGirl );
	}

	return true;
}

void HelloWorld::registerWithTouchDispatcher( void )
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate( this, 0, true );
}
