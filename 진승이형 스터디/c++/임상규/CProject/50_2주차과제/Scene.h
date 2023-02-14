#ifndef __SCENE_H__
#define __SCENE_H__

class CScene
{
private:


protected:


public:
	//	생성자
	CScene();
	//	소멸자
	virtual ~CScene();

	//	초기화
	virtual void Init() = 0;
	//	렌더
	virtual void Render() = 0;
	//	업데이트
	virtual void Update() = 0;
	//	해제
	virtual void Release() = 0;


};

#endif