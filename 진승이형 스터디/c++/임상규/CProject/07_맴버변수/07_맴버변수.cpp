// 07_맴버변수.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Manager.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("07_맴버변수\n");

	CManager manager;	

	//cout << manager.GetCurrentState() << endl;
	manager.PrintCurrentState();

	manager.SetCurrentState( SCENE_STATE::SCENE_GAME );

	//cout << manager.GetCurrentState() << endl;
	manager.PrintCurrentState();

	return 0;
}

