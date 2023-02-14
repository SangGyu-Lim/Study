#ifndef __BASIC_CLASS_H__
#define __BASIC_CLASS_H__

class CBasicClass
{
	enum STUDENT_GRADE{
		eFIRST_GRADE,
		eSECOND_GRADE,
		eTHIRD_GRADE,
		eFOURTH_GRADE,
		eMAX_STUDENT_GRADE
	};

	enum DEPARTMENT_CODE{
		eCOMPUTER_ENGINEERING,
		eICEngineering,
		eDIGITAL_CONTENTS,
		eInformation_Protection,
		eMAX_DEPARTMENT_CODE
	};

private:
	typedef struct sStudent{
		//�̸�
		char studentName[30];
		//�й�
		int studentNumber;
		//�г�
		STUDENT_GRADE studentGrade;
		//�а�
		DEPARTMENT_CODE studentClass;
		//����ó
		char studentPhoneNumber[30];
	}STUDENT, *LPSTUDENT;

	typedef struct sGrade{
		//�й�
		int studentNumber;
		//�м���ȣ
		int subjectNumber;
		//����
		int subjectGrade;
	}GRADE, *LPGRADE;

	typedef struct sSubject{
		//�м���ȣ
		int subjectNumber;
		//�����
		char subjectTitle[30];
		//��米��
		char professor[30];
	}SUBJECT, *LPSUBJECT;

	typedef struct sClass{
		//�а���
		DEPARTMENT_CODE className;
		//�а��ڵ�
		int classCode;
		//�а���
		char dean[30];
		//��ȭ��ȣ
		char classPhoneNumber[30];
		//���繫��
		char classOffice[30];
	}CLASS, *LPCLASS;
private:
	LPSTUDENT mStudentInfo;
	int mStudentCount;
protected:
public:
	CBasicClass();
	~CBasicClass();
	//void Init();
	void Release();
	bool insertStudentInfo();
	void deleteStudentInfo( int pStudentNumber );
	void modifyStudentInfo( int pStudentNumber );
	LPSTUDENT getStudentInfo( int pStudentCOunt );
	inline char*	 getStudentName()		{	return mStudentInfo->studentName;	}
	bool inputStudentGrade( int pStudentIndex, int pStudentGrade );
	bool inputDepartmentCode( int pStudentIndex, int pDepartmentCode );
	void addStudentInfo();
	inline int getStudentCount()			{	return mStudentCount;				}
};

#endif