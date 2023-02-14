#include "stdafx.h"
#include "Manager.h"

CManager::CManager()
	: m_currentState( SCENE_MAIN )
{
	cout << "������" << endl
		<< "���� ���� : " << m_currentState << endl;
}

CManager::~CManager()
{
	cout << "�Ҹ���" << endl;
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
			cout << "������� : SCENE_MAIN �Դϴ�." << endl;
		} break;		

	case SCENE_STATE::SCENE_LOGIN:
		{
			cout << "������� : SCENE_LOGIN �Դϴ�." << endl;
		} break;		

	case SCENE_STATE::SCENE_GAME:
		{
			cout << "������� : SCENE_GAME �Դϴ�." << endl;
		} break;	

	case SCENE_STATE::SCENE_END:
		{
			cout << "������� : SCENE_END �Դϴ�." << endl;
		} break;		
	}		
}
