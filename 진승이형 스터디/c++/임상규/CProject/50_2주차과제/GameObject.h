#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

class CGameObject
{
private:	


protected:
	int m_CurrentX, m_CurrentY;


public:
	//	������
	CGameObject();
	//	�Ҹ���
	~CGameObject();

	//	��ġ ����
	inline void SetPositionX( int x )	{ m_CurrentX = x; }
	inline void SetPositionY( int y )	{ m_CurrentY = y; }
	//	��ġ ��ȯ
	inline int GetPositionX()			{ return m_CurrentX; }
	inline int GetPositionY()			{ return m_CurrentY; }
};

#endif