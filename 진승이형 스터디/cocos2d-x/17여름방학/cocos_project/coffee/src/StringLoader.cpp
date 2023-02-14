#include "StringLoader.h"
#include "cocos2d.h"
#include <locale.h>

USING_NS_CC;

StringLoader::StringLoader()
{
	setlocale(LC_ALL, "");
}

StringLoader::~StringLoader()
{
	ReleaseData();
}

void StringLoader::ReleaseData()
{
	ReleaseData(DATA_TYPE_MENU);
}

WORD StringLoader::GetSize(eDATA_TYPE pDataType)
{
	return stringData[pDataType].size();
}

void StringLoader::ReleaseData(eDATA_TYPE pDataType)
{
	stringData[pDataType].clear();
}

void StringLoader::LoadData()
{
	LoadData(DATA_TYPE_MENU);
}

bool StringLoader::LoadData(eDATA_TYPE pDataType)
{
	bool loadResult = false;

	switch (pDataType)
	{
	case DATA_TYPE_MENU:
	{
		if (LoadMenuString() == DATA_LOAD_COMPLETE)
			loadResult = true;
	}
	break;
	}

	return loadResult;
}

const char* StringLoader::GetData(eDATA_TYPE pDataType, WORD pIndex)
{
	stringData[pDataType];

	CONST_ITERATOR_STRING_DATA iter = stringData[pDataType].begin();
	for (; iter != stringData[pDataType].end(); ++iter)
	{
		if (iter->first == pIndex)
		{
			return iter->second.c_str();
		}
	}

	return NULL;
}

const char* StringLoader::GetByLocation(eDATA_TYPE pDataType, WORD pLocation)
{
	if (0 < pLocation || pLocation <= stringData[pDataType].size())
	{
		CONST_ITERATOR_STRING_DATA iter = stringData[pDataType].begin();
		advance(iter, pLocation - 1);
		if (iter != stringData[pDataType].end())
			return iter->second.c_str();
	}

	return NULL;
}

BYTE StringLoader::LoadMenuString()
{
	tinyxml2::XMLDocument xmlDocument;
	tinyxml2::XMLNode* node;

	std::string xml = FileUtils::getInstance()->getStringFromFile(STRING_FILENAME_MENU);
	size_t size = xml.size();
	tinyxml2::XMLError error = xmlDocument.Parse(xml.c_str(), size);
	if (error != tinyxml2::XMLError::XML_SUCCESS)
	{
		return DATA_LOAD_ERROR_READ;
	}
	node = xmlDocument.FirstChildElement("ROOT");
	tinyxml2::XMLElement* element = node->FirstChildElement("STRING");
	tinyxml2::XMLElement* data = element->FirstChildElement("DATA");

	while (data != NULL)
	{
		int index = 0;
		data->QueryAttribute("index", &index);
		std::string text = data->GetText();
		tinyxml2::XMLVisitor d;
		stringData[DATA_TYPE_MENU].insert(PAIR_STRING_DATA(index, text));
		data = data->NextSiblingElement();
	}

	return DATA_LOAD_COMPLETE;
}
