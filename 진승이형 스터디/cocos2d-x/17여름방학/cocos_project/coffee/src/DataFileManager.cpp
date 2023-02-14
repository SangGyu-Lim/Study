#include "DataFileManager.h"

DataFileManager* DataFileManager::m_instance = 0;

DataFileManager* DataFileManager::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new DataFileManager();
	}

	return m_instance;
}

void DataFileManager::destroy()
{
	DataFileManager::GetInstance()->ReleaseData();

	delete m_instance;
	m_instance = 0;
}

void DataFileManager::InitDataFileManager()
{
	DataFileLoad();
}



void DataFileManager::DataFileLoad()
{
	dataLoader.LoadData();
	stringLoader.LoadData();
}

void DataFileManager::ReleaseData()
{
	dataLoader.ReleaseData();
	stringLoader.ReleaseData();
}
