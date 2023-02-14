#include "stdafx.h"
#include "GameScene.h"
#include "JUtil.h"

CGameScene::CGameScene()
	: m_pControl( NULL )
	, m_pPlayer( NULL )
	, m_pBlock( NULL )
	, m_CurrentTime( MINIMUM )
	, m_Time( MINIMUM )
{
	Init();
}

CGameScene::~CGameScene()
{
	Release();
}

void CGameScene::Init()
{
	setCursor();
	m_pControl = new CControl();
	m_pPlayer = new CPlayer();
	m_pBlock = new CBlock();
	m_pBlock1 = new CBlock( 20, 0 );
	m_pBlock2 = new CBlock( 21, 0 );
	m_pBlock3 = new CBlock( 11, 0 );
	Update();
}


void CGameScene::Render()
{
	m_pPlayer->Render();
	m_pBlock->Render();
}

void CGameScene::Update()
{
	while ( CrashCheck( m_pPlayer, m_pBlock ) 
		&& CrashCheck( m_pPlayer, m_pBlock1 ) 
		&& CrashCheck( m_pPlayer, m_pBlock2 ) 
		&& CrashCheck( m_pPlayer, m_pBlock3 ) )
	{
		if( m_pControl->MoveGameObject( m_pPlayer ) ) 
		{
			if( Delay() )
			{				
				m_pPlayer->Update();
				m_pBlock->Update();
				m_pBlock1->Update();
				m_pBlock2->Update();
				m_pBlock3->Update();
			}
		}
		else
			break;
	}
}

void CGameScene::Release()
{
	if( m_pControl )
	{		
		delete m_pControl;
	}

	if( m_pPlayer )
	{
		delete m_pPlayer;
	}

	if( m_pBlock )
	{
		delete m_pBlock;
	}

	if( m_pBlock1 )
	{
		delete m_pBlock1;
	}

	if( m_pBlock2 )
	{
		delete m_pBlock2;
	}

	if( m_pBlock3 )
	{
		m_pBlock3->Release();
		delete m_pBlock3;
	}
}

bool CGameScene::Delay()
{
	m_CurrentTime = GetTickCount();

	if(m_CurrentTime - m_Time >= DELAY)
		m_Time = m_CurrentTime;
	else
		return false;
}

bool CGameScene::CrashCheck( CPlayer *pPlayer, CBlock *pBlock )
{
	if( ( pPlayer->GetPositionX() == pBlock->GetPositionX() ) 
		&& ( pPlayer->GetPositionY() == pBlock->GetPositionY() ) )
		return false;
	else
		return true;
}
