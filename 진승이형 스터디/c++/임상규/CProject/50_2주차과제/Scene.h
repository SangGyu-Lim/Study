#ifndef __SCENE_H__
#define __SCENE_H__

class CScene
{
private:


protected:


public:
	//	������
	CScene();
	//	�Ҹ���
	virtual ~CScene();

	//	�ʱ�ȭ
	virtual void Init() = 0;
	//	����
	virtual void Render() = 0;
	//	������Ʈ
	virtual void Update() = 0;
	//	����
	virtual void Release() = 0;


};

#endif