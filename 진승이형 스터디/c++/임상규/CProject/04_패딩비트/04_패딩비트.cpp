// 04_�е���Ʈ.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

//	���� �е� ����Ʈ�� ����ü���� ���� ū ����
#pragma pack(push, 1)	//	����ü �е� ����Ʈ ����
#pragma pack(pop)		//	����ü �е� ����Ʈ ����

typedef struct paddingbitA
{
	int a;
	double b;
	char c;
	int d;
	short e;
}A;

typedef struct paddingbitB
{
	double b;
	int a;	
	int d;
	char c;	
	short e;
}B;

int _tmain(int argc, _TCHAR* argv[])
{	
	printf("struct paddingbitA size : %d\n", sizeof(A));
	printf("struct paddingbitB size : %d\n", sizeof(B));
	system("pause");

	return 0;
}

