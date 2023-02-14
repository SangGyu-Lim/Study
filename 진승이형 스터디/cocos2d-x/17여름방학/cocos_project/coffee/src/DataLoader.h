#ifndef __DATA_LOADER_H__
#define __DATA_LOADER_H__

#include "Define.h"

class DataLoader
{
private:
	MAP_MENU_DATA		menuData;

public:
	DataLoader();
	~DataLoader();

	void LoadData();
	void ReleaseData();
	WORD GetSize(eDATA_TYPE pDataType);
	void* GetData(eDATA_TYPE pDataType, WORD pIndex);
	void* GetByLocation(eDATA_TYPE pDataType, WORD pLocation);

private:
	bool LoadData(eDATA_TYPE pDataType);
	void ReleaseData(eDATA_TYPE pDataType);
	BYTE LoadMenuData();
	
};

#endif // !__DATA_LOADER_H__
