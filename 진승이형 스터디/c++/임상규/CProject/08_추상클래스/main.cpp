// 08_추상클래스.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Scene.h"
#include "MainScene.h"
#include "LoginScene.h"
#include "GameScene.h"
#include "EndScene.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("08_추상클래스\n");

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

