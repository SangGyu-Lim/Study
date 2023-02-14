#include "Entry.h"
#include "ConstantDefine.h"
#include "LoginManager.h"
#include "User.h"
#include "Admin.h"

CEntry::CEntry()
	: m_Menu( eCURRENT_STATE_NUM_OF_MIN )
	, m_pId( NULL )
	, m_pPassword( NULL )
{
	Init();
}

CEntry::~CEntry()
{
	Release();
}

void CEntry::Init()
{
	m_pId = new char[ MAX ];
	m_pPassword = new char[ MAX ];

	while( m_Menu != eCURRENT_STATE_EXIT )
	{
		SelectMenu();
		Update();
	}		
}

void CEntry::Update()
{
	switch( m_Menu )
	{
	case eCURRENT_STATE_USER_LOGIN:
		{
			CLoginManager UserLogin;
			int ErrorState = UserLogin.LoginCompare( m_pId, m_pPassword, "user.lim" );
			if( ErrorState == eErrorState::eERROR_NONE )
			{
				CUser User;
			}
			else
			{
				ErrorPrint( ErrorState );
			}
		} break;
	case eCURRENT_STATE_ADMIN_LOGIN:
		{
			CLoginManager AdminLogin;
			int ErrorState = AdminLogin.LoginCompare( m_pId, m_pPassword, "admin.lim" );
			if( ErrorState == eErrorState::eERROR_NONE )
			{
				CAdmin Admin;
			}
			else
			{
				ErrorPrint( ErrorState );
			}
		} break;
	case eCURRENT_STATE_JOIN_MEMBERSHIP:
		{
			CLoginManager JoinMembership;
			int ErrorState = JoinMembership.JoinMembershipCompare( m_pId, m_pPassword );
			if( ErrorState != eErrorState::eERROR_NONE )
			{
				ErrorPrint( ErrorState );
			}
		} break;
	case eCURRENT_STATE_EXIT:
		{
			cout << "System down. Bye" << endl;
		} break;
	}
}

void CEntry::Release()
{
	if( m_pId )
	{
		delete[] m_pId;
		m_pId = NULL;
	}
		
	if( m_pPassword )
	{
		delete[] m_pPassword;
		m_pPassword = NULL;
	}
}

void CEntry::SelectMenu()
{
	cout << "1. User Login" << endl
		<< "2. Admin Login" << endl
		<< "3. Join Membership" << endl
		<< "4. Exit" << endl
		<< "input : ";
	cin >> m_Menu;	

	if( m_Menu <= eCURRENT_STATE_NUM_OF_MIN || m_Menu >= eCURRENT_STATE_NUM_OF_MAX )
	{		
		ErrorPrint( eErrorState::eERROR_MENU_SELECT);
	}
	else
	{
		if( !( m_Menu == eCURRENT_STATE_EXIT ) )
		{
			InputIdPassword();
		}		
	}	
}

void CEntry::InputIdPassword()
{
	cout << "Input ID : ";
	cin >> m_pId;

	cout << "Input Password : ";
	cin >> m_pPassword;
}

void CEntry::ErrorPrint( int errorstate )
{
	switch( errorstate )
	{
	case eErrorState::eERROR_FILE_MAKE:
		{
			cout << "File error(File make)" << endl;
		} break;
	case eErrorState::eERROR_FILE_OPEN:
		{
			cout << "File error(File open)" << endl;
		} break;
	case eErrorState::eERROR_WRONG_FILE:
		{
			cout << "File error(Wrong file)" << endl;
		} break;
	case eErrorState::eERROR_WRONG_PASSWORD:
		{
			cout << "Login error(Wrong Password)" << endl;
		} break;
	case eErrorState::eERROR_NO_ID:
		{
			cout << "Login error(No Id)" << endl;
		} break;
	case eErrorState::eERROR_DUPLICATED_ID:
		{
			cout << "Login error(Duplicated Id)" << endl;
		} break;
	case eErrorState::eERROR_MENU_SELECT:
		{
			cout << "Wrong input error(Menu select)" << endl;
		} break;
	}
}