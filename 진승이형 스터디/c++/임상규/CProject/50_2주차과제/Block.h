#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "GameObject.h"

class CBlock : public CGameObject
{
private:


protected:


public:
	//	������
	CBlock();
	CBlock(int x, int y);
	//	�Ҹ���
	~CBlock();

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