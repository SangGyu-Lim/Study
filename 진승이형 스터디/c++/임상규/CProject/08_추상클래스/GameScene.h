#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "Scene.h"

class CGameScene : public CScene
{
private:


protected:


public:
	//	������
	CGameScene();
	//	�Ҹ���
	~CGameScene();

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