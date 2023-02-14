#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "Scene.h"
#include "Control.h"
#include "Player.h"
#include "Block.h"

class CGameScene : public CScene
{
private:
	CControl *m_pControl;
	CPlayer *m_pPlayer;
	CBlock *m_pBlock;
	CBlock *m_pBlock1;
	CBlock *m_pBlock2;
	CBlock *m_pBlock3;
	DWORD m_CurrentTime;
	DWORD m_Time;

protected:


public:
	//	생성자
	CGameScene();
	//	소멸자
	~CGameScene();

	//	초기화
	void Init();
	//	렌더
	void Render();
	//	업데이트
	void Update();
	//	해제
	void Release();
	//	딜레이
	bool Delay();
	//	충돌여부
	bool CrashCheck( CPlayer *pPlayer, CBlock *pBlock );
};
#endif