#include "player.h"

CPlayer::CPlayer()
{
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < 2; j++)
			nPlayerarea[i][j] = 0;
}

int CPlayer::CrashCheck()
{
	if(cp_cMap.nMap[nPlayerarea[0][0]][nPlayerarea[0][1]] == 1)
		return 1;
	if(cp_cMap.nMap[nPlayerarea[0][0]][nPlayerarea[0][1]] == 2)
		return 2;
	else
		return 0;
}