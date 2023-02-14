#ifndef __ENTRY_H__
#define __ENTRY_H__

class CEntry
{
private:	
	enum eCurrentState
	{
		eCURRENT_STATE_NUM_OF_MIN,
		eCURRENT_STATE_USER_LOGIN,
		eCURRENT_STATE_ADMIN_LOGIN,
		eCURRENT_STATE_JOIN_MEMBERSHIP,
		eCURRENT_STATE_EXIT,
		eCURRENT_STATE_NUM_OF_MAX
	};	

	int m_Menu;
	char* m_pId;
	char* m_pPassword;

public:
	CEntry();
	~CEntry();

	void Init();
	void Update();
	void Release();

	void SelectMenu();
	void InputIdPassword();
	void ErrorPrint( int errorstate );

protected:

};

#endif