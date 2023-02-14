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
	//	������
	CSceneState();
	//	�Ҹ���
	~CSceneState();

	//	�ʱ�ȭ
	void Init();
	//	����
	void Render();
	//	������Ʈ
	void Update();
	//	����
	void Release();

	//	���¼���
	void SceneStateChange( CScene *pState );
	inline void SetSceneState( SCENE_STATE SceneState )	{ m_SceneState = SceneState; }
	//	���¹�ȯ
	inline int GetSceneState()							{ return m_SceneState; }
};

#endif