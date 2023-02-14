#include "stdafx.h"
#include "JUtil.h"

//< 좌표를 x 와  y로 이동시킨다( 커서의 좌표 )
void setPosition( int x , int y)
{
	COORD		pos = { x, y };
	//< 정해진 핸들에 , 정해진 위치로 이동한다.
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), pos);
}
//< 현재 마우스커서의 x좌표를 얻는다.
int	getPositionX( void )
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ) ,&csbi );

	return csbi.dwCursorPosition.X;
}
//< 현재 마우스커서의 y좌표를 얻는다.
int getPositionY( void )
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ) ,&csbi );

	return csbi.dwCursorPosition.Y;
}

//< 텍스트 색상 변경
void setTextcolor( unsigned short color )
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color  );
}

//< 커서 지우기
void setCursor( void )
{
	HANDLE hConsole; // 콘솔 핸들
	CONSOLE_CURSOR_INFO ConsoleCursor; // 콘솔커서 정보 구조체

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 핸들을 구하고

	ConsoleCursor.bVisible = FALSE; // true 보임 , false 안보임
	ConsoleCursor.dwSize = 1; // 커서 사이즈

	SetConsoleCursorInfo(hConsole , &ConsoleCursor); // 설정
}