#include "stdafx.h"
#include "Block.h"
#include "JUtil.h"

CBlock::CBlock()
{
	Init();
}

CBlock::CBlock(int x, int y)
{
	m_CurrentX = x;
	m_CurrentY = y;
	setPosition( m_CurrentX, m_CurrentY );
	Render();
}

CBlock::~CBlock()
{

}

void CBlock::Init()
{
	m_CurrentX = MAX_X;
	m_CurrentY = MINIMUM;
	setPosition( m_CurrentX, m_CurrentY );
	Render();
}

void CBlock::Render()
{
	cout << "*";
}

void CBlock::Update()
{
	if( m_CurrentX < MINIMUM)
		m_CurrentX = MAX_X;
	setPosition( m_CurrentX--, m_CurrentY );
	Render();
}

void CBlock::Release()
{

}
