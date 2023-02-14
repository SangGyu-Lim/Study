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
	void Init();
	//	렌더
	void Render();
	//	업데이트
	void Update();
	//	해제
	void Release();
};
#endif