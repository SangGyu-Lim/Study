#ifndef __CONTROL_H__
#define __CONTROL_H__
#include "GameObject.h"

class CControl
{
private:
	

protected:


public:
	//	������
	CControl();
	//	�Ҹ���
	~CControl();

	//	������Ʈ
	bool MoveGameObject( CGameObject *pGameObject );
};

#endif