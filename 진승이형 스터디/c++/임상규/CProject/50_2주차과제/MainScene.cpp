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
	cout << "MainScene을 생성합니다." << endl;
}

void CMainScene::Render()
{

}

void CMainScene::Update()
{

}

void CMainScene::Release()
{
	cout << "MainScene을 소멸합니다." << endl
		<< "5초간 대기합니다." << endl;
	Sleep( 5000 );
}

