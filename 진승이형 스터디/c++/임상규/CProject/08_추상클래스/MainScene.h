#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__
#include "Scene.h"

class CMainScene : public CScene
{
private:


protected:


public:
	//	생성자
	CMainScene();
	//	소멸자
	~CMainScene();

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