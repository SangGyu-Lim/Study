#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

class CGameObject
{
private:	


protected:
	int m_CurrentX, m_CurrentY;


public:
	//	생성자
	CGameObject();
	//	소멸자
	~CGameObject();

	//	위치 설정
	inline void SetPositionX( int x )	{ m_CurrentX = x; }
	inline void SetPositionY( int y )	{ m_CurrentY = y; }
	//	위치 반환
	inline int GetPositionX()			{ return m_CurrentX; }
	inline int GetPositionY()			{ return m_CurrentY; }
};

#endif