#ifndef __END_SCENE_H__
#define __END_SCENE_H__
#include "Scene.h"

class CEndScene : public CScene
{
private:


protected:


public:
	//	������
	CEndScene();
	//	�Ҹ���
	~CEndScene();

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