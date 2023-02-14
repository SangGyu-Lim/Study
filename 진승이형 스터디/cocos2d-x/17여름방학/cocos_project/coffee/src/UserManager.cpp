#include "UserManager.h"
#include "LobbyScene.h"

USING_NS_CC;

UserManager* UserManager::m_instance = 0;

UserManager* UserManager::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new UserManager();
	}

	return m_instance;
}

void UserManager::destroy()
{
	delete m_instance;
	m_instance = 0;
}

void UserManager::InitUserManager()
{
	InitUserInformation();
}


void UserManager::InitUserInformation()
{
	userInformation.Gold = 1000000;
	userInformation.SurvivalDay = 0;

	
}
