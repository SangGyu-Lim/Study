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
		//이름
		char studentName[30];
		//학번
		int studentNumber;
		//학년
		STUDENT_GRADE studentGrade;
		//학과
		DEPARTMENT_CODE studentClass;
		//연락처
		char studentPhoneNumber[30];
	}STUDENT, *LPSTUDENT;

	typedef struct sGrade{
		//학번
		int studentNumber;
		//학수번호
		int subjectNumber;
		//성적
		int subjectGrade;
	}GRADE, *LPGRADE;

	typedef struct sSubject{
		//학수번호
		int subjectNumber;
		//과목명
		char subjectTitle[30];
		//담당교수
		char professor[30];
	}SUBJECT, *LPSUBJECT;

	typedef struct sClass{
		//학과명
		DEPARTMENT_CODE className;
		//학과코드
		int classCode;
		//학과장
		char dean[30];
		//전화번호
		char classPhoneNumber[30];
		//과사무실
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