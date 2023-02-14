#define _CONSOL_CPP_

#include "consol.h"
#include <windows.h>
#include <stdio.h>

HANDLE  hout;

void InitConsol(void)
{
	CONSOLE_CURSOR_INFO con;
	con.bVisible = FALSE;
	con.dwSize = 1;

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hout, &con);
}

void GotoZero()
{
	UPOINT pos;
	pos.x = 0;
	pos.y = 0;
	gotoxy( pos );
}

void ClearScreen(void)
{
	int i, j;
	UPOINT pos;

	for(i = 0; i < SCREEN_HEIGHT; i++)
	{
		for(j = 0; j < SCREEN_WIDTH; j++)
		{
			pos.x = j;
			pos.y = i;
			gotoxy(pos);
			printf(" ");
		}
	}
}

void gotoxy(UPOINT pos)
{
	COORD cpos;

	cpos.X = pos.x;
	cpos.Y = pos.y;

	SetConsoleCursorPosition(hout, cpos);
}


int GetRGB ( COLOR color )
{
	return (color.bIntensity << 3) + (color.bRed << 2) + (color.bGreen << 1) + (color.bBlue << 0);
}

int GetTextAttribute( int fore, int back )
{
	return (fore << 0) + (back << 4);
}


void SetConsoleColor( COLOR textcolor, COLOR bgcolor )
{
	int fore = GetRGB(textcolor);
	int back = GetRGB(bgcolor);
	int color = GetTextAttribute(fore,back);

	SetConsoleTextAttribute ( hout, color );
}

void ResetConsoleColor()
{
	COLOR textcolor = { 1, 1, 1, 1 };
	COLOR bgcolor = { 0, 0, 0, 0 };

	SetConsoleColor( textcolor, bgcolor );
}