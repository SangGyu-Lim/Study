#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__
#include "Scene.h"

class CMainScene : public CScene
{
private:


protected:


public:
	//	������
	CMainScene();
	//	�Ҹ���
	~CMainScene();

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