// 07_�ɹ�����.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Manager.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("07_�ɹ�����\n");

	CManager manager;	

	//cout << manager.GetCurrentState() << endl;
	manager.PrintCurrentState();

	manager.SetCurrentState( SCENE_STATE::SCENE_GAME );

	//cout << manager.GetCurrentState() << endl;
	manager.PrintCurrentState();

	return 0;
}

