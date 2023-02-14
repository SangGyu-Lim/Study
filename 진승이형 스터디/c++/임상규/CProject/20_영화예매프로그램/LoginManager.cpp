#include "LoginManager.h"
#include "ConstantDefine.h"

CLoginManager::CLoginManager()
	: m_pMember( NULL )
	, m_pDataHeader( NULL )
{
	Init();
}

CLoginManager::~CLoginManager()
{
	Release();
}

void CLoginManager::Init()
{
	m_pDataHeader = new DATA_HEADER;
}

void CLoginManager::Update()
{

}

void CLoginManager::Release()
{
	if( m_pMember )
	{
		delete[] m_pMember;
		m_pMember = NULL;
	}

	if( m_pDataHeader )
	{
		delete[] m_pDataHeader;
		m_pDataHeader = NULL;
	}
}

int CLoginManager::CheckFile( char* p_filename )
{
	FILE* fp = NULL;

	fp = fopen( p_filename, "rb" );

	if( fp == NULL )
		return eErrorState::eERROR_FILE_OPEN;

	if( !fp )
	{
		fp = fopen( p_filename, "wb" );

		if( fp == NULL )
			return eErrorState::eERROR_FILE_OPEN;

		if ( !fp )
			return eErrorState::eERROR_FILE_MAKE;

		if( !strcmp( p_filename, "user.lim" ) )
		{
			m_pDataHeader->DataType = eDataType::eDATA_TYPE_USER;
			m_pDataHeader->DataCount = 0;
		}
		else if( !strcmp( p_filename, "admin.lim" ) )
		{
			m_pDataHeader->DataType = eDataType::eDATA_TYPE_ADMIN;
			m_pDataHeader->DataCount = 0;
		}

		fwrite( m_pDataHeader, sizeof( DATA_HEADER ), 1, fp );
	}

	fclose( fp );

	return eErrorState::eERROR_NONE;
}

int CLoginManager::LoginCompare( char* p_id, char* p_password, char* p_filename )
{
	int ErrorState = CheckFile( p_filename );
	if( ErrorState != eErrorState::eERROR_NONE )
	{
		return ErrorState;
	}

	m_pMember = new MEMBER;

	FILE* fp = NULL;

	fp = fopen( p_filename, "rb");

	if( fp == NULL )
		return eErrorState::eERROR_FILE_OPEN;

	fread( m_pDataHeader, sizeof( DATA_HEADER ), 1, fp );
	if( strcmp( p_filename, "user.lim" ) && ( m_pDataHeader->DataType != eDataType::eDATA_TYPE_USER ) )
		return eErrorState::eERROR_WRONG_FILE;
	else if( strcmp( p_filename, "admin.lim" ) && ( m_pDataHeader->DataType != eDataType::eDATA_TYPE_ADMIN ) )
		return eErrorState::eERROR_WRONG_FILE;

	for( int i = 0; i < m_pDataHeader->DataCount; i++ )
	{
		fread( m_pMember, sizeof( MEMBER ), 1, fp );

		if( !strcmp( p_id, m_pMember->Id ) && !strcmp( p_password, m_pMember->Password ) )
		{
			if( fp )
				fclose( fp );

			return eErrorState::eERROR_NONE;
		}
		else if( !strcmp( p_id, m_pMember->Id ) )
		{
			if( fp )
				fclose( fp );

			return eErrorState::eERROR_WRONG_PASSWORD;
		}
	}

	if( fp )
		fclose( fp );

	if( m_pMember )
	{
		delete[] m_pMember;
		m_pMember = NULL;
	}

	return eErrorState::eERROR_NO_ID;
}

int CLoginManager::JoinMembershipCompare( char* p_id, char* p_password )
{
	int ErrorState = CheckFile( "user.lim" );
	if( ErrorState != eErrorState::eERROR_NONE )
	{
		return ErrorState;
	}	

	FILE* fp = NULL;

	fp = fopen( "user.lim", "rb" );	

	if( fp == NULL )
		return eErrorState::eERROR_FILE_OPEN;

	fread( m_pDataHeader, sizeof( DATA_HEADER ), 1, fp );
	if( m_pDataHeader->DataType != eDataType::eDATA_TYPE_USER )
		return eErrorState::eERROR_WRONG_FILE;

	m_pMember = new MEMBER[ m_pDataHeader->DataCount ];

	fread( m_pMember, sizeof( MEMBER ) * m_pDataHeader->DataCount, 1, fp );

	for( int i = 0; i < m_pDataHeader->DataCount; i++ )
	{
		if( !strcmp( p_id, m_pMember[ i ].Id ) )
		{
			if (fp)
				fclose(fp);

			return eErrorState::eERROR_DUPLICATED_ID;
		}
	}	

	if( fp )
		fclose( fp );

	ErrorState = SaveMembership( p_id, p_password );
	if( ErrorState != eErrorState::eERROR_NONE )
	{
		return ErrorState;
	}

	return eErrorState::eERROR_NONE;
}

int CLoginManager::SaveMembership( char* p_id, char* p_password )
{
	LPMEMBER TempMember = new MEMBER[ m_pDataHeader->DataCount ];
	memcpy( TempMember, m_pMember, sizeof(MEMBER) * m_pDataHeader->DataCount );

	m_pDataHeader->DataType = eDataType::eDATA_TYPE_USER;
	m_pDataHeader->DataCount++;

	if( m_pMember )
	{
		delete[] m_pMember;
		m_pMember = NULL;
	}

	m_pMember = new MEMBER[ m_pDataHeader->DataCount ];
	memcpy( m_pMember, TempMember, sizeof( MEMBER ) * ( m_pDataHeader->DataCount - 1 ) );
	sprintf( m_pMember[ m_pDataHeader->DataCount - 1 ].Id, "%s", p_id );
	sprintf( m_pMember[ m_pDataHeader->DataCount - 1 ].Password, "%s", p_password );

	FILE* fp = NULL;

	fp = fopen( "user.lim", "wb" );
	if( fp == NULL )
		return eErrorState::eERROR_FILE_OPEN;

	fwrite( m_pDataHeader, sizeof( DATA_HEADER ), 1, fp );
	fwrite( m_pMember, sizeof( MEMBER ) * m_pDataHeader->DataCount, 1, fp );

	if( fp )
		fclose( fp );

	cout << "Complete to join membership!" << endl;
}