#include <iostream>
#include "BasicClass.h"
using namespace std;

BasicClass::BasicClass()
	: m_StudentInfo( NULL )
	, m_StudentCount( 0 )
{

}

BasicClass::~BasicClass()
{
	if( m_StudentInfo )
	{
		delete[] m_StudentInfo;
	}
}

bool BasicClass::InsertStudentInfo()
{
	AddStudentInfo();
	if( m_StudentInfo )
	{
		int tempIndex = 0;

		cout << "학번 : ";
		cin >> m_StudentInfo[ m_StudentCount - 1 ].studentNum;

		cout << "이름 : ";
		cin >> m_StudentInfo[ m_StudentCount - 1 ].name;

		cout << "학년 : ";
		cin >> tempIndex;
		if( 0 <= tempIndex && tempIndex < eMax_NumOf_Grade )
		{
			switch( tempIndex )
			{
			case eGrade_1:
				{
					m_StudentInfo[ m_StudentCount - 1 ].grade = eGrade_1;
				}
				break;
			case eGrade_2:
				{
					m_StudentInfo[ m_StudentCount - 1 ].grade = eGrade_2;
				}
				break;
			case eGrade_3:
				{
					m_StudentInfo[ m_StudentCount - 1 ].grade = eGrade_3;
				}
				break;
			case eGrade_4:
				{
					m_StudentInfo[ m_StudentCount - 1 ].grade = eGrade_4;
				}
				break;
			}
		}
		else
		{
			cout << "잘못된 학년코드입니다" << endl;
			return false;
		}

		cout << "학과 : ";
		cin >> tempIndex;
		if( 0 <= tempIndex && tempIndex < eMax_NumOf_Department )
		{
			switch( tempIndex )
			{
			case eDepartment_CE:
				{
					m_StudentInfo[ m_StudentCount - 1 ].department = eDepartment_CE;
				}
				break;
			case eDepartment_ICE:
				{
					m_StudentInfo[ m_StudentCount - 1 ].department = eDepartment_ICE;
				}
				break;
			case eDepartment_DC:
				{
					m_StudentInfo[ m_StudentCount - 1 ].department = eDepartment_DC;
				}
				break;
			case eDepartment_IP:
				{
					m_StudentInfo[ m_StudentCount - 1 ].department = eDepartment_IP;
				}
				break;
			}
		}
		else
		{
			cout << "잘못된 학과코드입니다" << endl;
			return false;
		}

		cout << "연락처 :";
		cin >> m_StudentInfo[ m_StudentCount - 1 ].phoneNum;

		cout << m_StudentInfo[ m_StudentCount - 1 ].studentNum << endl;
		cout << m_StudentInfo[ m_StudentCount - 1 ].name << endl;
		cout << m_StudentInfo[ m_StudentCount - 1 ].grade << endl;
		cout << m_StudentInfo[ m_StudentCount - 1 ].department << endl;
		cout << m_StudentInfo[ m_StudentCount - 1 ].phoneNum << endl;
	}
	return true;
}

void BasicClass::AddStudentInfo()
{
	if( m_StudentCount == 0 )
	{
		m_StudentInfo = new STUDENT;
		m_StudentCount++;
	}
	else
	{
		LPSTUDENT tempStudent = new STUDENT[ m_StudentCount ];
		if( tempStudent )
		{
			// 기존꺼 복사
			for( int i = 0; i < m_StudentCount; i++ )
			{
				memcpy( &tempStudent[ i ], &m_StudentInfo[ i ], sizeof( STUDENT ) );
			}
			
			if( m_StudentInfo )
			{
				delete[] m_StudentInfo;
			}
			
// 
// 			if( m_StudentInfo )
// 			{
// 				delete[] m_StudentInfo;
// 			}

			m_StudentInfo = new STUDENT[ m_StudentCount + 1 ];
			if( m_StudentInfo )
			{
				for( int i = 0; i < m_StudentCount; i++ )
				{
					memcpy( &m_StudentInfo[ i ], &tempStudent[ i ], sizeof( STUDENT ) );
				}

				m_StudentCount++;
			}

			if( tempStudent )
			{
				delete[] tempStudent;
			}
		}
	}
}

BasicClass::LPSTUDENT BasicClass::GetStudentInfo( int p_StudentNumber )
{
	if( p_StudentNumber != 0 )
	{
		for( int i = 0; i < m_StudentCount; i++ )
		{
			if( m_StudentInfo[ i ].studentNum == p_StudentNumber )
			{
				return &m_StudentInfo[ i ];
			}
		}
	}
}
