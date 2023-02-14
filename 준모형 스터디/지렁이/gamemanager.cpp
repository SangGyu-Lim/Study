#include "gamemanager.h"

CGameManager::CGameManager()
{
	key = 0;
	cPlayer.nPlayerarea[0][0] = 10;
	cPlayer.nPlayerarea[0][1] = 10;

	PlayercurTime = 0;
	Playertime = 0;
	FoodcurTime = 0;
	Foodtime = 0;

	test= 0;
	testPT.x = 0;
	testPT.y = 0;
}

void CGameManager::Manager()
{
	cPlayer.cp_cMap.GamePage();
	StageInformationPrint();
	GetPlayerxy(FALSE);

	while(TRUE)
	{
		if(kbhit())
		{
			key = getch();

			switch(key)
			{
			case UP:
				{
					while(TRUE)
					{
						if(PlayerRender())
						{
							cStage.nTime--;
							StageInformationPrint();
							GetPlayerxy(UP);
							DrawPlayer();
						}
						if(FoodRender())
							Food();

						if(kbhit() || (cPlayer.CrashCheck() == 1) || (cStage.nTime == 0))
							break;
						if(cPlayer.CrashCheck() == 2)
						{
					
							Food();

							test++;
						//	cPlayer.cp_cMap.nMap[pt.x][pt.y] = 0;
							cStage.nTail--;
							if(cStage.nTail <= -10000)
							{
								StageInformationPrint();
								cStage.NextStageCheck();
							}
								

							
							Food();
						}
						
					}
				} break;
			case LEFT:
				{
					while(TRUE)
					{
						if(PlayerRender())
						{
							cStage.nTime--;
							StageInformationPrint();
							GetPlayerxy(LEFT);
							DrawPlayer();
						}
						if(FoodRender())
							Food();

						if(kbhit() || (cPlayer.CrashCheck() == 1) || (cStage.nTime == 0))
							break;
						if(cPlayer.CrashCheck() == 2)
						{
					
							Food();

							test++;
						//	cPlayer.cp_cMap.nMap[pt.x][pt.y] = 0;
							cStage.nTail--;
							if(cStage.nTail <= -10000)
							{
								StageInformationPrint();
								cStage.NextStageCheck();
							}
							
							Food();
						}

						
					}					
				} break;
			case RIGHT:
				{
					while(TRUE)
					{
						if(PlayerRender())
						{
							cStage.nTime--;
							StageInformationPrint();
							GetPlayerxy(RIGHT);
							DrawPlayer();
						}
						if(FoodRender())
							Food();

						if(kbhit() || (cPlayer.CrashCheck() == 1) || (cStage.nTime == 0))
							break;
						if(cPlayer.CrashCheck() == 2)
						{
			
							Food();

							test++;

						//	cPlayer.cp_cMap.nMap[pt.x][pt.y] = 0;
							cStage.nTail--;
							if(cStage.nTail <= -10000)
							{
								StageInformationPrint();
								cStage.NextStageCheck();
							}
							
							Food();


						}
						

					}	
				} break;
			case DOWN:
				{
					while(TRUE)
					{
						if(PlayerRender())
						{
							cStage.nTime--;
							StageInformationPrint();
							GetPlayerxy(DOWN);
							DrawPlayer();
						}
						if(FoodRender())
							Food();

						if(kbhit() || (cPlayer.CrashCheck() == 1) || (cStage.nTime == 0))
							break;
						if(cPlayer.CrashCheck() == 2)
						{


							Food();

							test++;
						//	cPlayer.cp_cMap.nMap[pt.x][pt.y] = 0;
							cStage.nTail--;
							if(cStage.nTail <= -10000)
							{
								StageInformationPrint();
								cStage.NextStageCheck();
							}
							
							Food();
						}

						

					}						
				} break;
			}
		}

		if((cPlayer.CrashCheck() == 1) || (cStage.nTime == 0))
		{
			cStage.GameoverCheck();

			cPlayer.nPlayerarea[0][0] = 10;
			cPlayer.nPlayerarea[0][1] = 10;

			break;
		}
	}
}

void CGameManager::GetPlayerxy(int index)
{	
	
	cPlayer.nPlayerarea[10][0] = cPlayer.nPlayerarea[TAIL - cStage.nTail][0];
	cPlayer.nPlayerarea[10][1] = cPlayer.nPlayerarea[TAIL - cStage.nTail][1];
	
	for(int i = TAIL - cStage.nTail; i >= 1; i--)
	{
		cPlayer.nPlayerarea[i][0] = cPlayer.nPlayerarea[i - 1][0];
		cPlayer.nPlayerarea[i][1] = cPlayer.nPlayerarea[i - 1][1];		
	}
	
	switch (index)
	{
	case UP:
		{
			cPlayer.nPlayerarea[0][1]--;
		} break;
	case LEFT:
		{
			cPlayer.nPlayerarea[0][0]--;
		} break;
	case RIGHT:
		{
			cPlayer.nPlayerarea[0][0]++;
		} break;
	case DOWN:
		{
			cPlayer.nPlayerarea[0][1]++;
		} break;
	default:
		break;
	}		
}

void CGameManager::DrawPlayer()
{
	
	pt.x = cPlayer.nPlayerarea[10][0];
	pt.y = cPlayer.nPlayerarea[10][1];
	
	for(int i = 0; i <= TAIL - cStage.nTail; i++)
	{	
		gotoxy(pt);
		cout << " ";

		pt.x = cPlayer.nPlayerarea[i][0];
		pt.y = cPlayer.nPlayerarea[i][1];		
	}

	for(int i = 0; i <= TAIL - cStage.nTail; i++)
	{	

		pt.x = cPlayer.nPlayerarea[i][0];
		pt.y = cPlayer.nPlayerarea[i][1];

		gotoxy(pt);
		cout << "*";
	}

}

int CGameManager::PlayerRender()
{
	PlayercurTime = GetTickCount();

	if(PlayercurTime - Playertime >= PDELAY)
		Playertime = PlayercurTime;
	else 
		return 0;
}

void CGameManager::StageInformationPrint()
{
	pt.x = 25;
	pt.y = 4;
	gotoxy(pt);
	cout << "Life : " << cStage.nLife;

	pt.y = 6;
	gotoxy(pt);
	//cout << "Tail : " << cStage.nTail;
	printf("Tail : %d / %d / %d / %d",cStage.nTail, test, testPT.x, testPT.y);

	pt.y = 8;
	gotoxy(pt);
	//cout << "Time : " << cStage.nTime;
	printf("Time : %2d",cStage.nTime);

	pt.y = 10;
	gotoxy(pt);
	cout << "Stage Count : " << cStage.nStagecount;

	pt.x = cPlayer.nPlayerarea[0][0];
	pt.y = cPlayer.nPlayerarea[0][1];
}

void CGameManager::Food()
{
	if(cPlayer.CrashCheck() == 2)
	{
		testPT = pt;
		cPlayer.cp_cMap.nMap[cPlayer.nPlayerarea[0][0]][cPlayer.nPlayerarea[0][1]] = 0;
		Foodtime = FoodcurTime;
	}
	else
	{
		pt.x = cStage.nFood[0][0];
		pt.y = cStage.nFood[0][1];

		gotoxy(pt);

		cPlayer.cp_cMap.nMap[pt.x][pt.y] = 0;
		cout << " ";

		srand(GetTickCount());

		cStage.nFood[0][0] = rand() % 18 + 1;
		cStage.nFood[0][1] = rand() % 18 + 1;

		pt.x = cStage.nFood[0][0];
		pt.y = cStage.nFood[0][1];

		gotoxy(pt);

		cPlayer.cp_cMap.nMap[pt.x][pt.y] = 2;
		cout << "@";
	}	
}

int CGameManager::FoodRender()
{
	FoodcurTime = GetTickCount();

	if(FoodcurTime - Foodtime >= FDELAY)
		Foodtime = FoodcurTime;
	else 
		return 0;
}