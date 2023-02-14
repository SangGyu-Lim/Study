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
	void Init();
	//	렌더
	void Render();
	//	업데이트
	void Update();
	//	해제
	void Release();
};
#endif