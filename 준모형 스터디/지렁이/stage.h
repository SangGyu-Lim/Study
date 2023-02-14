#include <iostream>

#include "consol.h"
#include "map.h"

using namespace std;

#define TAIL 10

class CStage
{
public:
	int nLife;
	int nTail;
	int nTime;
	int nStagecount;
	int nFood[1][2];

	CMap cs_cMap;

public:
	CStage();
	~CStage() {}

public:
	void GameoverCheck();
	void NextStageCheck();
	
};