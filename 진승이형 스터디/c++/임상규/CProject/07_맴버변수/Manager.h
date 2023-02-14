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
	//	생성자
	CManager();
	//	소멸자
	~CManager();

	//	m_currentState Get, Set 함수
	int GetCurrentState();
	void SetCurrentState( SCENE_STATE currentState );

	//	m_currentState 상태 출력
	void PrintCurrentState();


};

#endif