// 05_파일입출력.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

typedef struct fileopencloseA
{
	int a;
	char b;
}A;

typedef struct fileopencloseB
{
	int n;
	A a;
}B;

int _tmain(int argc, _TCHAR* argv[])
{	
	/*
	FILE *fp = NULL;
	fp = fopen("test.sjce", "wb");

	A a;
	a.a = 10;
	a.b = 20;

	B b;
	b.n = 100;
	b.a = a;


	fprintf(fp, "%d, %d, %d, %d, %d\n",a.a, a.b, b.n, b.a.a, b.a.b);

	system("pause");

	return 0;
	*/
}

