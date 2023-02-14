#ifndef __CONSTANT_DEFINE_H__
#define __CONSTANT_DEFINE_H__

#include <iostream>

using namespace std;

#define MAX 256

enum eErrorState
{
	eERROR_FILE_MAKE,
	eERROR_FILE_OPEN,
	eERROR_WRONG_FILE,
	eERROR_WRONG_PASSWORD,
	eERROR_NO_ID,
	eERROR_DUPLICATED_ID,
	eERROR_MENU_SELECT,	
	eERROR_NONE
};

enum eDataType
{
	eDATA_TYPE_USER,
	eDATA_TYPE_ADMIN,
	eDATA_TYPE_MOVIE_LIST
};

typedef struct sDataHeader
{
	int DataType;
	int DataCount;
}DATA_HEADER, *LPDATA_HEADER;

typedef struct sMovieList
{
	int Index;
	char Name[ MAX ];
	char StartTime[ MAX ];
	char EndTime[ MAX ];
}MOVIE_LIST, *LPMOVIE_LIST;

#endif 