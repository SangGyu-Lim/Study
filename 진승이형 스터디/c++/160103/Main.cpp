//	BasicClass(구조체 변수)
#include <iostream>
#include <Windows.h>
#include "BasicClass.h"

using namespace std;

void main()
{
	CStudent Student;

	int StudentNumber;
	int Grade;
	char Name[256];

	cin >> StudentNumber;
	cin >> Grade;
	cin >> Name;

	Student.setStudentNumber( StudentNumber );
	Student.setGrade( Grade );
	Student.setName( Name );

	cout << Student.getStudentNumber() << endl
		<< Student.getGrade() << endl
		<< Student.getName() << endl;

	Sleep( 1500 );
}





















/*
//	BasicClass(맴버 함수)
#include <iostream>
#include <Windows.h>
#include "BasicClass.h"

using namespace std;

void main()
{
	CBasicClass BasicClass;
	int Num;

	cin >> Num;

	BasicClass.setNum( Num );
	BasicClass.squareNum();
	cout << BasicClass.getSum() << endl;

	Sleep( 1500 );
}
*/









/*
//	BasicClass(맴버 변수)
#include <iostream>
#include <Windows.h>
#include "BasicClass.h"

using namespace std;

void main()
{
	int num;

	cin >> num;

	CBasicClass* pBasicClass = new CBasicClass[num];

	for( int i = 0; i < num; i++ )
	{
		cout << pBasicClass[i].getPrivateCount() << endl
			<< pBasicClass[i].getPi() << endl;
	}

	delete[] pBasicClass;

	Sleep( 3000 );

}
*/