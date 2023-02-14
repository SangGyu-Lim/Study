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
	//	������
	CGameScene();
	//	�Ҹ���
	~CGameScene();

	//	�ʱ�ȭ
	void Init();
	//	����
	void Render();
	//	������Ʈ
	void Update();
	//	����
	void Release();
	//	������
	bool Delay();
	//	�浹����
	bool CrashCheck( CPlayer *pPlayer, CBlock *pBlock );
};
#endif