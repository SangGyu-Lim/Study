#include "stdafx.h"
#include "JUtil.h"

//< ��ǥ�� x ��  y�� �̵���Ų��( Ŀ���� ��ǥ )
void setPosition( int x , int y)
{
	COORD		pos = { x, y };
	//< ������ �ڵ鿡 , ������ ��ġ�� �̵��Ѵ�.
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), pos);
}
//< ���� ���콺Ŀ���� x��ǥ�� ��´�.
int	getPositionX( void )
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ) ,&csbi );

	return csbi.dwCursorPosition.X;
}
//< ���� ���콺Ŀ���� y��ǥ�� ��´�.
int getPositionY( void )
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ) ,&csbi );

	return csbi.dwCursorPosition.Y;
}

//< �ؽ�Ʈ ���� ����
void setTextcolor( unsigned short color )
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color  );
}

//< Ŀ�� �����
void setCursor( void )
{
	HANDLE hConsole; // �ܼ� �ڵ�
	CONSOLE_CURSOR_INFO ConsoleCursor; // �ܼ�Ŀ�� ���� ����ü

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ڵ��� ���ϰ�

	ConsoleCursor.bVisible = FALSE; // true ���� , false �Ⱥ���
	ConsoleCursor.dwSize = 1; // Ŀ�� ������

	SetConsoleCursorInfo(hConsole , &ConsoleCursor); // ����
}