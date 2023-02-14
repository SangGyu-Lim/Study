#ifndef __LOGIN_MANAGER_H__
#define __LOGIN_MANAGER_H__
#include "ConstantDefine.h"

class CLoginManager
{
private:
	
	typedef struct sMember
	{
		char Id[ MAX ];
		char Password[ MAX ];
	}MEMBER, *LPMEMBER;

	LPDATA_HEADER m_pDataHeader;
	LPMEMBER m_pMember;
	
public:	

	CLoginManager();
	~CLoginManager();

	void Init();
	void Update();
	void Release();

	int CheckFile( char* p_filename );

	int LoginCompare( char* p_id, char* p_password, char* p_filename );
	int JoinMembershipCompare( char* p_id, char* p_password );

	int SaveMembership( char* p_id, char* p_password );	

protected:

};

#endif