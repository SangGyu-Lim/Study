#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "Scene.h"

class CGameScene : public CScene
{
private:


protected:


public:
	//	생성자
	CGameScene();
	//	소멸자
	~CGameScene();

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