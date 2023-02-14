// 04_패딩비트.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

//	기존 패딩 바이트는 구조체에서 가장 큰 변수
#pragma pack(push, 1)	//	구조체 패딩 바이트 변경
#pragma pack(pop)		//	구조체 패딩 바이트 복구

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

