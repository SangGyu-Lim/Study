#include "stdafx.h"
#include "MainScene.h"

CMainScene::CMainScene()
{
	Init();
}

CMainScene::~CMainScene()
{
	Release();
}

void CMainScene::Init()
{
	cout << "MainScene�� �����մϴ�." << endl;
}

void CMainScene::Render()
{

}

void CMainScene::Update()
{

}

void CMainScene::Release()
{
	cout << "MainScene�� �Ҹ��մϴ�." << endl
		<< "5�ʰ� ����մϴ�." << endl;
	Sleep( 5000 );
}

