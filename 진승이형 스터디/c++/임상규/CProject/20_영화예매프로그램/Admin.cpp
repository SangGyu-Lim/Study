#include "Admin.h"
//#include "ConstantDefine.h"

CAdmin::CAdmin()
	: m_pDataHeader( NULL )
	, m_pMovieList( NULL )
{
	Init();
}

CAdmin::~CAdmin()
{
	Release();
}

void CAdmin::Init()
{
	m_pDataHeader = new DATA_HEADER;
}

void CAdmin::Update()
{

}

void CAdmin::Release()
{

}

void CAdmin::MovieAdd()
{

}

void CAdmin::MovieDelete()
{

}

void CAdmin::MovieModify()
{

}

void CAdmin::MovieView()
{

}

int CAdmin::MovieDataLoad()
{
	char MembershipId[256];
	char MembershipPassword[256];	

	FILE* fp = NULL;

	fp = fopen( "movielist.lim", "rb" );			

	if( fp == NULL )
		return eERROR_FILE_OPEN;

	fseek( fp, 0, SEEK_END );
	int CurrentPoint = ftell( fp );
	rewind( fp );
	while( 1 )
	{
		if( CurrentPoint == ftell( fp ) )
			break;

		fscanf( fp, "id : %s password : %s\n", MembershipId, MembershipPassword );

/*		if( !strcmp( id, MembershipId ) )
		{
			if( fp )
				fclose( fp );

			return eDUPLICATED_ERROR;
		}*/
	}

	cout << "Complete to Join Membership!" << endl;

	if( fp )
		fclose( fp );

	return eERROR_NONE;
}

void CAdmin::MovieDataSave()
{

}

