#include "BasicClass.h"
#include <iostream>
using namespace std;

void main()
{
	CBasicClass basicClass;
	int temp;
	int isExit = false;

	while (true)
	{
		cout << "\t �޴��� �����ϼ��� " << endl;
		cout << "\t 1.�л����� �߰�" << endl;
		cout << "\t 2.�л����� ����" << endl;
		cout << "\t 3.�л����� ����" << endl;
		cout << "\t 4.�л� ��ü ���" << endl;
		cout << "\t 0.����" << endl;
		cout << "\t ";
		cin>>temp;

		switch ( temp )
		{
		case 1:{
			basicClass.insertStudentInfo();
			   }break;
		case 2:{
			int delStudentNum;
			cout << "������ �й��� �Է��ϼ��� :";
			cin >> delStudentNum;
			basicClass.deleteStudentInfo( delStudentNum );
			   }break;
		case 3:{
			int modStudentNum;
			cout << "������ �й��� �Է��ϼ��� :";
			cin >> modStudentNum;
			basicClass.modifyStudentInfo(modStudentNum);
			   }break;
		case 4:{
			if ( basicClass.getStudentCount()!=0 )
			{
				for (int i = 0; i < basicClass.getStudentCount(); i++)
				{
					cout << basicClass.getStudentInfo(i)->studentName << endl;
					cout << basicClass.getStudentInfo(i)->studentNumber << endl;
					cout << basicClass.getStudentInfo(i)->studentGrade << endl;
					cout << basicClass.getStudentInfo(i)->studentClass << endl;
					cout << basicClass.getStudentInfo(i)->studentPhoneNumber << endl;
				}
			}
			else
				cout << "��ϵ� �л��� �����ϴ�."<< endl;
			   }break;
		case 0:{
			isExit = true;
			   }
		}
		if (isExit)
		{
			break;
		}

	}
}