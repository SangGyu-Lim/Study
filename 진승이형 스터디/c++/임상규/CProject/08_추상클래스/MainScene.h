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
	void init();
	//	����
	void render();
	//	������Ʈ
	void update();
	//	����
	void release();
};
#endif