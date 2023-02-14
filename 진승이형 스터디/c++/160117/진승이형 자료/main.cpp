#include <iostream>
#include <stdlib.h>
#include "BasicClass.h"
using namespace std;

int main()
{
	BasicClass basicClass;

	while( 1 )
	{
		bool isExit = false;
		int inputNumber = 0;
		cout << "1. 학생입력" << endl;
		cout << "2. 정보삭제" << endl;
		cout << "3. 정보수정" << endl;
		cout << "0. 종료" << endl;
		cin >> inputNumber;

		switch( inputNumber )
		{
		case 0:
			{
				cout << "종료합니다" << endl;
				isExit = true;
			}
			break;
		case 1:
			{
				if( basicClass.InsertStudentInfo() )
				{
					cout << "학생 입력이 완료 되었습니다" << endl;
				}
				else
				{
					cout << "학생 정보 입력 에러" << endl;
				}
			}
			break;
		case 2:
			{

			}
			break;
		case 3:
			{

			}
			break;
		}
		// 종료 체크
		if( isExit )
		{
			break;
		}
		cout << "메뉴로 돌아갈래? (아무키입력)" << endl;
		system( "pause" );
		system( "cls" );
	}
	system( "pause" );

	return 0;
}