#include <iostream>
#include "../../Self_Study/Classes/Define.h"
#include "tinyxml2.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

bool MenuData(char* pFileName)
{
	char* pStr = NULL;
	char tempStr[255];
	char xmlStr[4096];
	int row = 0;
	int dataCount = 0;

	LPMENU_DATA data = NULL;

	tinyxml2::XMLDocument xmlDocument;
	tinyxml2::XMLDeclaration* pDeclaration = xmlDocument.NewDeclaration();
	xmlDocument.LinkEndChild(pDeclaration);
	tinyxml2::XMLNode* xmlNode;
	xmlNode = xmlDocument.NewElement("ROOT");
	xmlDocument.LinkEndChild(xmlNode);
	tinyxml2::XMLElement* xmlElement = xmlDocument.NewElement("STRING");
	xmlNode->LinkEndChild(xmlElement);

	FILE* pFile;
	sprintf_s(tempStr, sizeof(tempStr), "%s.csv", pFileName);
	fopen_s(&pFile, tempStr, "rb");
	if (!pFile)
		return false;

	while (!feof(pFile))
	{
		pStr = fgets(tempStr, sizeof(tempStr), pFile);

		if (!pStr)
			break;

		if (row == 0)
		{
			sscanf_s(pStr, "%d\n", &dataCount);
			data = new MENU_DATA[dataCount];
		}
		else
		{
			sscanf_s(pStr, ",%d,%d,%d,%d,%d,%[^\r]s\r\n",
			//sscanf_s(pStr, ",%d,%d,%d,%d,%d\r\n",
				&data[row - 1].index,
				&data[row - 1].productType,
				&data[row - 1].buyPrice,
				&data[row - 1].makePrice,
				&data[row - 1].popularity,
				xmlStr,
				sizeof(xmlStr)
			);

			tinyxml2::XMLElement* xmlData = xmlDocument.NewElement("DATA");
			xmlData->SetAttribute("index", data[row - 1].index);

			xmlData->SetText(xmlStr);
			xmlElement->InsertEndChild(xmlData);
		}

		++row;
	}

	fclose(pFile);

	BYTE* totalData = NULL;
	UINT position = 0;
	UINT bufferSize = 0;
	DATA_HEADER dataHeader;

	FILE* saveData;
	sprintf_s(tempStr, sizeof(tempStr), "../../Self_Study/Resources/data/%s.data", pFileName);
	fopen_s(&saveData, tempStr, "wb");

	dataHeader.dataType = DATA_TYPE_MENU;
	dataHeader.dataCount = dataCount;

	bufferSize += sizeof(DATA_HEADER);
	bufferSize += sizeof(MENU_DATA) * dataCount;
	totalData = new BYTE[bufferSize];

	memcpy_s(totalData + position, sizeof(DATA_HEADER), &dataHeader, sizeof(DATA_HEADER));
	position += sizeof(DATA_HEADER);

	memcpy_s(totalData + position, sizeof(MENU_DATA) * dataCount, data, sizeof(MENU_DATA) * dataCount);

	fwrite(totalData, bufferSize, 1, saveData);
	fclose(saveData);

	sprintf_s(tempStr, sizeof(tempStr), "../../Self_Study/Resources/data/%s.xml", pFileName);
	xmlDocument.SaveFile(tempStr);

	if (totalData)
	{
		delete[] totalData;
		totalData = NULL;
	}

	if (data)
	{
		delete[] data;
		data = NULL;
	}

	return true;
}

int main()
{
	while (1)
	{
		cout << "1.menu data" << endl;
		cout << "0.end" << endl;

		int inputNumber;
		cin >> inputNumber;

		if (inputNumber == 0)
		{
			break;
		}

		bool result = false;
		switch (inputNumber)
		{
		case 1:
		{
			result = MenuData("menu");
		}
		break;
		}

		if (result)
		{
			cout << "Complete!!" << endl;
		}
		else
		{
			cout << "ERROR!" << endl;
		}
	}


	return 0;
}