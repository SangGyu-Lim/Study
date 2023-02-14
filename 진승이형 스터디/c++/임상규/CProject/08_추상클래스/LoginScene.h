#ifndef __LOGIN_SCENE_H__
#define __LOGIN_SCENE_H__
#include "Scene.h"

class CLoginScene : public CScene
{
private:


protected:


public:
	//	생성자
	CLoginScene();
	//	소멸자
	~CLoginScene();

	//	초기화
	void init();
	//	렌더
	void render();
	//	업데이트
	void update();
	//	해제
	void release();
};
#endif