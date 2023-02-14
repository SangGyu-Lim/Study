#ifndef __MANAGER_H__
#define __MANAGER_H__

enum SCENE_STATE
{
	SCENE_MAIN,
	SCENE_LOGIN,
	SCENE_GAME,
	SCENE_END,
};

class CManager
{
private:
	int m_currentState;


protected:


public:
	//	������
	CManager();
	//	�Ҹ���
	~CManager();

	//	m_currentState Get, Set �Լ�
	int GetCurrentState();
	void SetCurrentState( SCENE_STATE currentState );

	//	m_currentState ���� ���
	void PrintCurrentState();


};

#endif