#include "stdafx.h"
#include "Manager.h"

CManager::CManager()
	: m_currentState( SCENE_MAIN )
{
	cout << "생성자" << endl
		<< "현재 상태 : " << m_currentState << endl;
}

CManager::~CManager()
{
	cout << "소멸자" << endl;
}

int CManager::GetCurrentState()
{
	return m_currentState;
}

void CManager::SetCurrentState( SCENE_STATE currentState )
{
	m_currentState = currentState;
}

void CManager::PrintCurrentState()
{
	switch( m_currentState )
	{
	case SCENE_STATE::SCENE_MAIN:
		{
			cout << "현재상태 : SCENE_MAIN 입니다." << endl;
		} break;		

	case SCENE_STATE::SCENE_LOGIN:
		{
			cout << "현재상태 : SCENE_LOGIN 입니다." << endl;
		} break;		

	case SCENE_STATE::SCENE_GAME:
		{
			cout << "현재상태 : SCENE_GAME 입니다." << endl;
		} break;	

	case SCENE_STATE::SCENE_END:
		{
			cout << "현재상태 : SCENE_END 입니다." << endl;
		} break;		
	}		
}
