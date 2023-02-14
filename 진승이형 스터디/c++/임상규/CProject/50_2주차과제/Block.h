#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "GameObject.h"

class CBlock : public CGameObject
{
private:


protected:


public:
	//	생성자
	CBlock();
	CBlock(int x, int y);
	//	소멸자
	~CBlock();

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