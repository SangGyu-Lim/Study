// 08_�߻�Ŭ����.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Scene.h"
#include "MainScene.h"
#include "LoginScene.h"
#include "GameScene.h"
#include "EndScene.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("08_�߻�Ŭ����\n");

	CScene *pMainScene = new CMainScene();
	CScene *pLoginScene = new CLoginScene();
	CScene *pGameScene = new CGameScene();
	CScene *pEndScene = new CEndScene();
		
	delete pMainScene;
	delete pLoginScene;
	delete pGameScene;
	delete pEndScene;

	return 0;
}

