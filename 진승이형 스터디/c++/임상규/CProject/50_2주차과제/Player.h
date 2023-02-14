#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "GameObject.h"

class CPlayer : public CGameObject
{
private:


protected:


public:
	//	생성자
	CPlayer();
	//	소멸자
	~CPlayer();

	//	초기화
	void Init();
	//	렌더
	void Render();
	//	업데이트
	void Update();
	//	해제
	void Release();
};
#endif