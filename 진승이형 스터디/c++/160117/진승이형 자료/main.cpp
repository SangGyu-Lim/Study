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
		cout << "1. �л��Է�" << endl;
		cout << "2. ��������" << endl;
		cout << "3. ��������" << endl;
		cout << "0. ����" << endl;
		cin >> inputNumber;

		switch( inputNumber )
		{
		case 0:
			{
				cout << "�����մϴ�" << endl;
				isExit = true;
			}
			break;
		case 1:
			{
				if( basicClass.InsertStudentInfo() )
				{
					cout << "�л� �Է��� �Ϸ� �Ǿ����ϴ�" << endl;
				}
				else
				{
					cout << "�л� ���� �Է� ����" << endl;
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
		// ���� üũ
		if( isExit )
		{
			break;
		}
		cout << "�޴��� ���ư���? (�ƹ�Ű�Է�)" << endl;
		system( "pause" );
		system( "cls" );
	}
	system( "pause" );

	return 0;
}