#ifndef __DATA_FILE_MANAGER_H__
#define __DATA_FILE_MANAGER_H__

#include "DataLoader.h"
#include "StringLoader.h"

class DataFileManager
{
	DataLoader		dataLoader;
	StringLoader	stringLoader;

public:
	static DataFileManager* GetInstance();
	static void destroy();

private:

	static DataFileManager* m_instance;

	DataFileManager() { m_instance = static_cast <DataFileManager*> (this); }
	~DataFileManager() {}

public:

	void InitDataFileManager();
	void DataFileLoad();
	void ReleaseData();

	inline	WORD				GetSize(eDATA_TYPE pDataType) { return dataLoader.GetSize(pDataType); }

	inline	LPMENU_DATA		GetMenuData(WORD pIndex) { return (LPMENU_DATA)dataLoader.GetData(DATA_TYPE_MENU, pIndex); }
	inline	LPMENU_DATA		GetMenuDataLocation(WORD pLocation) { return (LPMENU_DATA)dataLoader.GetByLocation(DATA_TYPE_MENU, pLocation); }

	inline	const char*			GetString(eDATA_TYPE pDataType, WORD pIndex) { return stringLoader.GetData(pDataType, pIndex); }
};

#endif // !__DATA_FILE_MANAGER_H__
