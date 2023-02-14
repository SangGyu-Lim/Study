//	BasicClass(구조체 함수)
#include <iostream>
#include "BasicClass.h"

using namespace std;

CStudent::CStudent()
	: m_Student( NULL )
{
	init();
}

CStudent::~CStudent()
{
	release();
}

void CStudent::init()
{
	m_Student = new STUDENT;
}

void CStudent::release()
{
	if( m_Student )
	{
		delete m_Student;
	}
}



















/*
//	BasicClass(맴버 함수)
#include <iostream>
#include "BasicClass.h"

using namespace std;

CBasicClass::CBasicClass()
	: m_Num( 0 )
	, m_Sum( 0 )
{

}

CBasicClass::~CBasicClass()
{

}

void CBasicClass::squareNum()
{
	m_Sum = m_Num * m_Num;
}
*/














/*
//	BasicClass(맴버 변수)
#include <iostream>
#include "BasicClass.h"

using namespace std;

int CBasicClass::m_Count = 0;

CBasicClass::CBasicClass()
	: m_Pi( 3.14f )
	, m_PrivateCount( m_Count )
{
	cout << "생성자입니다." << endl;
	m_Count++;
}

CBasicClass::~CBasicClass()
{
	cout << "소멸자입니다." << endl;
}
*/