#include "stdafx.h"
#include "SceneState.h"
#include "LoginScene.h"
#include "MainScene.h"
#include "GameScene.h"
#include "EndScene.h"

CSceneState::CSceneState()
	: m_SceneState( SCENE_STATE_LOGIN )
	, m_pScene( NULL )
{
	Init();
}

CSceneState::~CSceneState()
{
	Release();
}

void CSceneState::Init()
{
	Update();
}

void CSceneState::Render()
{

}

void CSceneState::Update()
{
	while( m_SceneState != END_OF_SCENE_STATE )
	{
		switch( m_SceneState )
		{
		case SCENE_STATE_LOGIN:
			{
				SceneStateChange( new CLoginScene );

				m_SceneState = SCENE_STATE_MAIN;
			} break;
		case SCENE_STATE_MAIN:
			{
				SceneStateChange( new CMainScene );

				m_SceneState = SCENE_STATE_GAME;
			} break;
		case SCENE_STATE_GAME:
			{
				SceneStateChange( new CGameScene );

				m_SceneState = SCENE_STATE_END;
			} break;
		case SCENE_STATE_END:
			{
				SceneStateChange( new CEndScene );

				m_SceneState = END_OF_SCENE_STATE;
			} break;		
		}
	}	
}

void CSceneState::Release()
{
	if( m_pScene )
	{
		delete m_pScene;
	}
}

void CSceneState::SceneStateChange( CScene *pState )
{
	Release();

	m_pScene = pState;
}

