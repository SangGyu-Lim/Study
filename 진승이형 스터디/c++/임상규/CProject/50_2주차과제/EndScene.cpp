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
	cout << "EndScene�� �����մϴ�." << endl;
}

void CEndScene::Render()
{

}

void CEndScene::Update()
{

}

void CEndScene::Release()
{
	cout << "EndScene�� �Ҹ��մϴ�." << endl
		<< "5�ʰ� ����մϴ�." << endl;
	Sleep( 5000 );
}

