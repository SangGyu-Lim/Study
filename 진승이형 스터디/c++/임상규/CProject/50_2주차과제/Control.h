#ifndef __CONTROL_H__
#define __CONTROL_H__
#include "GameObject.h"

class CControl
{
private:
	

protected:


public:
	//	생성자
	CControl();
	//	소멸자
	~CControl();

	//	업데이트
	bool MoveGameObject( CGameObject *pGameObject );
};

#endif