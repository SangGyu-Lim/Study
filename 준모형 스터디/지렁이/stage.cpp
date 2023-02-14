#include "stage.h"

CStage::CStage()
{
	nLife = 3;
	nTail = TAIL;
	nTime = 100;
	nStagecount = 1;
	for(int i = 0; i < 2; i++)
		nFood[0][i] = 0;
}

void CStage::GameoverCheck()
{
	nLife--;

	if(nLife == 0)
		cs_cMap.GameoverPage();
	else if(nTime == 0)
		nTime = 100;
}

void CStage::NextStageCheck()
{
	cs_cMap.VictoryPage();
}