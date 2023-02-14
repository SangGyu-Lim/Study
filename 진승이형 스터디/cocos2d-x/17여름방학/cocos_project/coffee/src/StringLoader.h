#ifndef __STRING_LOADER_H__
#define __STRING_LOADER_H__

#include "xml/tinyxml2.h"
#include "Define.h"

typedef map<WORD, std::string>				MAP_STRING_DATA;
typedef pair<WORD, std::string>				PAIR_STRING_DATA;
typedef MAP_STRING_DATA::iterator			ITERATOR_STRING_DATA;
typedef MAP_STRING_DATA::const_iterator		CONST_ITERATOR_STRING_DATA;

class StringLoader
{
private:
	MAP_STRING_DATA			stringData[DATA_TYPE_MAX];

public:
	StringLoader();
	~StringLoader();

	void LoadData();
	void ReleaseData();
	WORD GetSize(eDATA_TYPE pDataType);
	const char* GetData(eDATA_TYPE pDataType, WORD pIndex);
	const char* GetByLocation(eDATA_TYPE pDataType, WORD pLocation);

private:
	bool LoadData(eDATA_TYPE pDataType);
	void ReleaseData(eDATA_TYPE pDataType);

	BYTE LoadMenuString();
};

#endif // !__STRING_LOADER_H__
