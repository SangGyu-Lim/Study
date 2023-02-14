#ifndef __SCENE_STATE_H__
#define __SCENE_STATE_H__
#include "Scene.h"

enum SCENE_STATE
{
	SCENE_STATE_LOGIN,
	SCENE_STATE_MAIN,	
	SCENE_STATE_GAME,
	SCENE_STATE_END,
	END_OF_SCENE_STATE
};

class CSceneState
{
private:
	SCENE_STATE m_SceneState;
	CScene *m_pScene;

protected:


public:
	//	생성자
	CSceneState();
	//	소멸자
	~CSceneState();

	//	초기화
	void Init();
	//	렌더
	void Render();
	//	업데이트
	void Update();
	//	해제
	void Release();

	//	상태설정
	void SceneStateChange( CScene *pState );
	inline void SetSceneState( SCENE_STATE SceneState )	{ m_SceneState = SceneState; }
	//	상태반환
	inline int GetSceneState()							{ return m_SceneState; }
};

#endif