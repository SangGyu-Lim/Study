#include "stdafx.h"
#include "Player.h"
#include "JUtil.h"

CPlayer::CPlayer()
{
	Init();
}

CPlayer::~CPlayer()
{
	
}

void CPlayer::Init()
{	
	m_CurrentX = m_CurrentY = MINIMUM;
	setPosition( m_CurrentX, m_CurrentY );
	Render();
}

void CPlayer::Render()
{
	cout << "бс";
}

void CPlayer::Update()
{
	system("cls");
	if( m_CurrentY != MINIMUM )
		m_CurrentY--;
	setPosition( m_CurrentX, m_CurrentY );
	Render();
}

void CPlayer::Release()
{

}
