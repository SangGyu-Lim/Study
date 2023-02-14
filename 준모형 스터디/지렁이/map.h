#ifndef _MAP_H_
#define _MAP_H_

#include <iostream>

using namespace std;

#define XAREA	20
#define YAREA	20

class CMap
{
public:
	int nMap[XAREA][YAREA];
	
public:
	CMap();
	~CMap()	{ }

public:
	void StartPage();
	void GamePage();
	void VictoryPage();
	void GameoverPage();

};

#endif