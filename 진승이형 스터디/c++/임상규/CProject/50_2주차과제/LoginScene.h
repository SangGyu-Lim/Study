#ifndef __LOGIN_SCENE_H__
#define __LOGIN_SCENE_H__
#include "Scene.h"

class CLoginScene : public CScene
{
private:


protected:


public:
	//	������
	CLoginScene();
	//	�Ҹ���
	~CLoginScene();

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