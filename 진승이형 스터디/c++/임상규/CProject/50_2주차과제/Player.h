#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "GameObject.h"

class CPlayer : public CGameObject
{
private:


protected:


public:
	//	������
	CPlayer();
	//	�Ҹ���
	~CPlayer();

	//	�ʱ�ȭ
	void Init();
	//	����
	void Render();
	//	������Ʈ
	void Update();
	//	����
	void Release();
};
#endif