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
	cout << "LoginScene�� �����մϴ�." << endl;
}

void CLoginScene::Render()
{

}

void CLoginScene::Update()
{

}

void CLoginScene::Release()
{
	cout << "LoginScene�� �Ҹ��մϴ�." << endl
		<< "5�ʰ� ����մϴ�." << endl;
	Sleep( 5000 );
}

