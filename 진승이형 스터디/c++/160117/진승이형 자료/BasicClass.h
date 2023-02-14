#ifndef __BASICCLASS_H__
#define __BASICCLASS_H__

class BasicClass
{
private:
	enum eGrade
	{
		eGrade_1,
		eGrade_2,
		eGrade_3,
		eGrade_4,
		eMax_NumOf_Grade,
	};

	enum eDepartment
	{
		eDepartment_CE,
		eDepartment_ICE,
		eDepartment_DC,
		eDepartment_IP,
		eMax_NumOf_Department,
	};

	typedef struct sStudent
	{
		char name[256];
		int studentNum;
		eGrade grade;
		eDepartment department;
		char phoneNum[256];
	}STUDENT, *LPSTUDENT;

private:
	LPSTUDENT	m_StudentInfo;
	int			m_StudentCount;

protected:

public:
	BasicClass();
	~BasicClass();

	bool InsertStudentInfo();
	void AddStudentInfo();

	LPSTUDENT	GetStudentInfo( int p_StudentNumber );
	inline	int	GetStudentCount()			{	return m_StudentCount;				}
};

#endif