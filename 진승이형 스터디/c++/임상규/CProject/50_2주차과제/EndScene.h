#ifndef __END_SCENE_H__
#define __END_SCENE_H__
#include "Scene.h"

class CEndScene : public CScene
{
private:


protected:


public:
	//	생성자
	CEndScene();
	//	소멸자
	~CEndScene();

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