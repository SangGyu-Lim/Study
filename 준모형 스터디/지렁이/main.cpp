#include "gamemanager.h"

void main()
{
	InitConsol();

	CGameManager cGameManager;

	cGameManager.cPlayer.cp_cMap.StartPage();
	cGameManager.key = getch();

	while(cGameManager.cStage.nLife > 0)
	{
		cGameManager.Manager();
		//cGameManager.Render();
	}



	/*
	GameManager::getInstance()->changeStage(intro);



	int m_state;
	Stage m_stage[10]

	introStage stage = new Stage();
	stage1 stage = new Stage()

	m_stage[0] = stage
	m_satge[1] = stage
	
	bool changeStage(int state)
	{
		if(m_state == state)
			return;

		
		m_stage[m_state].close();
		m_state = state;
		m_stage[m_state].open();


		
	}


	*/










}

