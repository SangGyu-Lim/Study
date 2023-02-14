#include <iostream>
using namespace std;
#include "BasicClass.h"

CBasicClass::CBasicClass()
	:mStudentInfo(NULL),
	mStudentCount( 0 )
{
	//Init();
}

CBasicClass::~CBasicClass()
{
	Release();
}

//void CBasicClass::Init()
//{
//	mStudentInfo = new STUDENT;
//}

void CBasicClass::Release()
{
	for( int i = 0; i < mStudentCount; i++ )
	{
		delete &mStudentInfo[ i ];
	}
}

bool CBasicClass::insertStudentInfo()
{
	addStudentInfo();
	if (mStudentInfo)
	{
		int temp;

		cout << "�̸� : ";
		cin >> mStudentInfo[mStudentCount-1].studentName;

		cout << "�й� : ";
		cin >> mStudentInfo[mStudentCount-1].studentNumber;

		cout << "�г� : ";
		cin >> temp;
		inputStudentGrade( mStudentCount-1, temp );

		cout << "�а� : ";
		cin >> temp;
		inputDepartmentCode( mStudentCount-1, temp );

		cout << "����ó : ";
		cin >> mStudentInfo[mStudentCount-1].studentPhoneNumber;
	}

	return true;
}

void CBasicClass::deleteStudentInfo( int pStudentNumber )
{
	int tempIndex = 0;	
	if ( mStudentCount != 0 && mStudentCount != 1 )
	{
		LPSTUDENT tempStudent = new STUDENT[mStudentCount-1];
		for (int i = 0; i < mStudentCount; i++)
		{
			if ( mStudentInfo[i].studentNumber == pStudentNumber )
			{
				continue;
			}
			memcpy( &tempStudent[tempIndex], &mStudentInfo[i], sizeof(STUDENT) );
			tempIndex++;
		}
		delete[] mStudentInfo;
		mStudentCount--;

		mStudentInfo = new STUDENT[mStudentCount-1];
		for (int i = 0; i < mStudentCount; i++)
		{
			memcpy(&mStudentInfo[i], &tempStudent[i], sizeof(STUDENT) );
		}
		
		delete[] tempStudent;
	}
	if ( mStudentCount == 1 )
	{
		mStudentInfo = NULL;
		delete mStudentInfo;
	}	
}

void CBasicClass::modifyStudentInfo( int pStudentNumber )
{
	int choiceMenu;
	int temp;
	int isExit = false;
	for (int i = 0; i < mStudentCount; i++)
	{
		if (mStudentInfo[i].studentNumber = pStudentNumber)
		{
			cout << "� ������ �����Ͻðڽ��ϱ�?" << endl;
			cout << "1.�̸�" << endl << "2.�г�" << endl << "3.�а�" << endl << "4.����ó" << endl << "5.����(�й� ����)" << endl;
			cin >> choiceMenu;

			switch(choiceMenu)
			{
			case 1:
				{
					cout << "������ �̸��� �Է��ϼ��� : ";
					cin >> mStudentInfo[i].studentName;
				}break;
			case 2:
				{
					cout << "������ �г��� �Է��ϼ��� : ";
					cin >> temp;
					inputStudentGrade( i, temp );
				}
			case 3:
				{
					cout << "������ �а��� �Է��ϼ��� : ";
					cin >> temp;
					inputDepartmentCode( i, temp );
				}
			case 4:
				{
					cout << "������ ����ó�� �Է��ϼ��� : ";
					cin >> mStudentInfo[i].studentPhoneNumber;
				}break;
			case 5:
				{
					cout << "������ �̸��� �Է��ϼ��� : ";
					cin >> mStudentInfo[i].studentName;
					cout << "������ �г��� �Է��ϼ��� : ";
					cin >> temp;
					inputStudentGrade( i, temp );
					cout << "������ �а��� �Է��ϼ��� : ";
					cin >> temp;
					inputDepartmentCode( i, temp );
					cout << "������ ����ó�� �Է��ϼ��� : ";
					cin >> mStudentInfo[i].studentPhoneNumber;
				}break;
			default:
				break;
			}
			break;
		}
		if (isExit)
		{
			break;
		}
	}
}


bool CBasicClass::inputStudentGrade( int pStudentIndex, int pStudentGrade )
{
	if ( 0<=pStudentGrade && pStudentGrade < eMAX_STUDENT_GRADE )
	{
		switch(pStudentGrade)
		{
		case eFIRST_GRADE : 
			{
				mStudentInfo[pStudentIndex].studentGrade = eFIRST_GRADE;
			}
			break;

		case eSECOND_GRADE : 
			{
				mStudentInfo[pStudentIndex].studentGrade = eSECOND_GRADE;
			}
			break;

		case eTHIRD_GRADE : 
			{
				mStudentInfo[pStudentIndex].studentGrade = eTHIRD_GRADE;
			}
			break;

		case eFOURTH_GRADE : 
			{
				mStudentInfo[pStudentIndex].studentGrade = eFOURTH_GRADE;
			}
			break;
		}
	}
	else
	{
		cout<< "�߸��� �г� �Է��Դϴ�." << endl;
		return false;
	}
	return true;
}

bool CBasicClass::inputDepartmentCode( int pStudentIndex, int pDepartmentCode )
{
	if ( 0<=pDepartmentCode && pDepartmentCode < eMAX_DEPARTMENT_CODE )
	{
		switch(pDepartmentCode)
		{
		case eCOMPUTER_ENGINEERING : 
			{
				mStudentInfo[pStudentIndex].studentClass = eCOMPUTER_ENGINEERING;
			}
			break;

		case eICEngineering : 
			{
				mStudentInfo[pStudentIndex].studentClass = eICEngineering;
			}
			break;

		case eDIGITAL_CONTENTS : 
			{
				mStudentInfo[pStudentIndex].studentClass = eDIGITAL_CONTENTS;
			}
			break;

		case eInformation_Protection : 
			{
				mStudentInfo[pStudentIndex].studentClass = eInformation_Protection;
			}
			break;
		}
	}
	else
	{
		cout<< "�߸��� �а� �Է��Դϴ�." << endl;
		return false;
	}
	return true;
}

void CBasicClass::addStudentInfo()
{
	if ( mStudentCount == 0 )
	{
		mStudentInfo = new STUDENT;
		mStudentCount++;
	}
	else
	{
		LPSTUDENT tempStudent = new STUDENT[mStudentCount];
		for (int i = 0; i < mStudentCount; i++)
		{
			memcpy( &tempStudent[i], &mStudentInfo[i], sizeof(STUDENT) );
		}
		delete[] mStudentInfo;

		mStudentInfo = new STUDENT[mStudentCount + 1];
		for (int i = 0; i < mStudentCount; i++)
		{
			memcpy(&mStudentInfo[i], &tempStudent[i], sizeof(STUDENT) );
		}
		mStudentCount++;
		delete[] tempStudent;
	}
}

CBasicClass::LPSTUDENT CBasicClass::getStudentInfo( int pStudentCOunt )
{
	return &mStudentInfo[pStudentCOunt];
}

