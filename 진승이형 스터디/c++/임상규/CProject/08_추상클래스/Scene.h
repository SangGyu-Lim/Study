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
	virtual void init() = 0;
	//	����
	virtual void render() = 0;
	//	������Ʈ
	virtual void update() = 0;
	//	����
	virtual void release() = 0;


};

#endif