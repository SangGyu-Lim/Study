#include "stdafx.h"
#include "LoginScene.h"

CLoginScene::CLoginScene()
{
	Init();
}

CLoginScene::~CLoginScene()
{
	Release();
}

void CLoginScene::Init()
{
	cout << "LoginScene을 생성합니다." << endl;
}

void CLoginScene::Render()
{

}

void CLoginScene::Update()
{

}

void CLoginScene::Release()
{
	cout << "LoginScene을 소멸합니다." << endl
		<< "5초간 대기합니다." << endl;
	Sleep( 5000 );
}

