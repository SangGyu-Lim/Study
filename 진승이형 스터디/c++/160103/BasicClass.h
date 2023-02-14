//	BasicClass(구조체 변수)
#ifndef __BASIC_CLASS_H__
#define __BASIC_CLASS_H__

class CStudent
{
private:
	typedef struct _sStudent
	{
		int StudentNumber;
		int Grade;
		char* Name;
	} STUDENT, *LPSTUDENT;

	LPSTUDENT m_Student;

protected:

public:
	CStudent();
	~CStudent();

	inline int		getStudentNumber()	{	return m_Student->StudentNumber;	}
	inline int		getGrade()			{	return m_Student->Grade;	}
	inline char*	getName()			{	return m_Student->Name;	}

	inline void	setStudentNumber( int StudentNumber )	{	this->m_Student->StudentNumber = StudentNumber;	}
	inline void	setGrade( int Grade )					{	this->m_Student->Grade = Grade;	}
	inline void	setName( char* Name )					{	this->m_Student->Name = Name;	}

	void init();
	void release();

};

#endif























/*
//	BasicClass(맴버 함수)
#ifndef __BASIC_CLASS_H__
#define __BASIC_CLASS_H__

class CBasicClass
{
private:
	int m_Num;
	int m_Sum;

protected:

public:
	CBasicClass();
	~CBasicClass();

	inline void setNum( int num )	{	m_Num = num;	}

	inline int getSum()				{	return m_Sum;	}

	void squareNum();

};

#endif
*/













/*
//	BasicClass(맴버 변수)
#ifndef __BASIC_CLASS_H__
#define __BASIC_CLASS_H__

class CBasicClass
{
private:
	static int m_Count;
	const float m_Pi;
	int m_PrivateCount;

protected:

public:
	CBasicClass();
	~CBasicClass();

	inline int getCount()			{	return m_Count;	}	
	inline int getPrivateCount()	{	return m_PrivateCount;	}
	inline float getPi()			{	return m_Pi;	}

};

#endif
*/