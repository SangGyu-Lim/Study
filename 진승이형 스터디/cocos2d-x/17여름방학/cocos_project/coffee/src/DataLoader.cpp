#include "DataLoader.h"
#include "cocos2d.h"
//#include "FileUtil.h"

USING_NS_CC;

DataLoader::DataLoader()
{

}

DataLoader::~DataLoader()
{
	ReleaseData();
}

void DataLoader::ReleaseData()
{
	ReleaseData(DATA_TYPE_MENU);
}

WORD DataLoader::GetSize(eDATA_TYPE pDataType)
{
	switch (pDataType)
	{
	case DATA_TYPE_MENU:
	{
		return (WORD)menuData.size();
	}
	break;
	}
	return 0;
}

void DataLoader::ReleaseData(eDATA_TYPE pDataType)
{
	switch (pDataType)
	{
	case DATA_TYPE_MENU:
	{
		ITERATOR_MENU_DATA iter = menuData.begin();
		for (; iter != menuData.end(); ++iter)
		{
			if (iter->second)
			{
				delete iter->second;
				iter->second = NULL;
			}
		}
	}
	break;
	default:
		break;
	}
}

void DataLoader::LoadData()
{
	LoadData(DATA_TYPE_MENU);
}

bool DataLoader::LoadData(eDATA_TYPE pDataType)
{
	bool loadResult = false;

	switch (pDataType)
	{
	case DATA_TYPE_MENU:
	{
		if (LoadMenuData() == DATA_LOAD_COMPLETE)
			loadResult = true;
	}
	break;
	}

	return loadResult;
}

void* DataLoader::GetData(eDATA_TYPE pDataType, WORD pIndex)
{
	switch (pDataType)
	{
	case DATA_TYPE_MENU:
	{
		ITERATOR_MENU_DATA iter = menuData.find(pIndex);
		if (iter != menuData.end())
			return iter->second;
	}
	break;
	}

	return NULL;
}

void* DataLoader::GetByLocation(eDATA_TYPE pDataType, WORD pLocation)
{
	switch (pDataType)
	{
	case DATA_TYPE_MENU:
	{
		if (0 < pLocation || pLocation <= menuData.size())
		{
			ITERATOR_MENU_DATA iter = menuData.begin();
			advance(iter, pLocation - 1);
			if (iter != menuData.end())
				return iter->second;
		}
	}
	break;
	}

	return NULL;
}

BYTE DataLoader::LoadMenuData()
{
	ReleaseData(DATA_TYPE_MENU);

	ssize_t size;
	const char* loadData;
	
	
	loadData = reinterpret_cast<char*>(FileUtils::getInstance()->getFileData(DATA_FILENAME_MENU, "rb", &size));
	//loadData = reinterpret_cast<char*>(FileUtil::createUtil()->getFileData(DATA_FILENAME_MENU, "rb", &size));
	//FileUtils::getInstance().get
	CCLOG("LoadMenuData >> data : %s", loadData);

	if (loadData == NULL)
	{
		return DATA_LOAD_ERROR_OPEN;
	}

	DATA_HEADER dataHeader;
	//if (fread_s(&dataHeader, sizeof(DATA_HEADER), sizeof(DATA_HEADER), 1, loadData) == 0)
	if(size == 0)
	{
		return DATA_LOAD_ERROR_READ;
	}

	UINT readPosition = 0;
	memcpy(&dataHeader, loadData, sizeof(DATA_HEADER));
	readPosition += sizeof(DATA_HEADER);
	if (dataHeader.dataType != DATA_TYPE_MENU)
	{
		return DATA_LOAD_ERROR_TYPE;
	}

	for (int i = 0; i < dataHeader.dataCount; ++i)
	{
		LPMENU_DATA tempData = new MENU_DATA;
		memcpy(tempData, loadData + readPosition, sizeof(MENU_DATA));
		readPosition += sizeof(MENU_DATA);
		menuData.insert(PAIR_MENU_DATA(tempData->index, tempData));
	}
	//CCString

	return DATA_LOAD_COMPLETE;
}
