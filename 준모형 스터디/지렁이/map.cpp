#include "map.h"

CMap::CMap()
{
	for(int i = 0; i < XAREA; i++)
	{
		for(int j = 0; j < YAREA; j++)
		{
			if(i == 0 || j == 0 || i == (XAREA - 1) || j == (YAREA - 1))
				nMap[i][j] = 1;
			else
				nMap[i][j] = 0;
		}
	}
}

void CMap::StartPage()
{
	cout << "StartPage" << endl 
		<< "Press any key to start" << endl;
}

void CMap::GamePage()
{
	system("cls");

	for(int i = 0; i < XAREA; i++)
	{
		for(int j = 0; j < YAREA; j++)
		{
			if(nMap[i][j] == 1)
				cout << "#";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void CMap::VictoryPage()
{
//	system("cls");

	cout << "VictoryPage" << endl;

	exit(0);
}

void CMap::GameoverPage()
{
	system("cls");

	cout << "GameoverPage" << endl;
}