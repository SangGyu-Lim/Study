#ifndef _CONSOL_H_
#define _CONSOL_H_

#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 20

typedef struct tag_A
{
	int x;
	int y;
} UPOINT;


void InitConsol(void);
void ClearScreen(void);
void gotoxy(UPOINT pos);
void GotoZero();


typedef struct tag_B
{
	bool bIntensity;
	bool bRed; 
	bool bGreen;
	bool bBlue;
} COLOR;

int	GetRGB( COLOR color );
int GetTextAttribute( int fore, int back );

void SetConsoleColor( COLOR textcolor, COLOR bgcolor );
void ResetConsoleColor();


#endif

