#include "stdafx.h"
#include "EndScene.h"

CEndScene::CEndScene()
{
	Init();
}

CEndScene::~CEndScene()
{
	Release();
}

void CEndScene::Init()
{
	cout << "EndScene을 생성합니다." << endl;
}

void CEndScene::Render()
{

}

void CEndScene::Update()
{

}

void CEndScene::Release()
{
	cout << "EndScene을 소멸합니다." << endl
		<< "5초간 대기합니다." << endl;
	Sleep( 5000 );
}

