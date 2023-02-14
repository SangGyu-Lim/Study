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
		cout << "\t 메뉴를 선택하세요 " << endl;
		cout << "\t 1.학생정보 추가" << endl;
		cout << "\t 2.학생정보 삭제" << endl;
		cout << "\t 3.학생정보 수정" << endl;
		cout << "\t 4.학생 전체 출력" << endl;
		cout << "\t 0.종료" << endl;
		cout << "\t ";
		cin>>temp;

		switch ( temp )
		{
		case 1:{
			basicClass.insertStudentInfo();
			   }break;
		case 2:{
			int delStudentNum;
			cout << "삭제할 학번을 입력하세요 :";
			cin >> delStudentNum;
			basicClass.deleteStudentInfo( delStudentNum );
			   }break;
		case 3:{
			int modStudentNum;
			cout << "수정할 학번을 입력하세요 :";
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
				cout << "등록된 학생이 없습니다."<< endl;
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