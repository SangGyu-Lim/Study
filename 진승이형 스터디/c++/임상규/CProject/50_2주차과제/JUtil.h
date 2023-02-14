#ifndef _JUTIL_H__
#define _JUTIL_H__

//< �������� ���� ����
#define RED         (FOREGROUND_RED | FOREGROUND_INTENSITY)
#define BLUE        (FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define PINK        (RED | BLUE)
#define WHITE       (RED | GREEN | BLUE)
#define GREEN       (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define YELLOW      (RED | GREEN)
#define SKYBLUE     (GREEN | BLUE)  
#define BLACK		0x0000

#define RED_BG      (BACKGROUND_RED | BACKGROUND_INTENSITY) 
#define BLUE_BG     (BACKGROUND_BLUE | BACKGROUND_INTENSITY) 
#define PINK_BG     (RED_BG | BLUE_BG) 
#define WHITE_BG    (RED_BG | GREEN_BG | BLUE_BG) 
#define GREEN_BG    (BACKGROUND_GREEN | BACKGROUND_INTENSITY) 
#define YELLOW_BG   (RED_BG | GREEN_BG) 
#define SKYBLUE_BG  (GREEN_BG | BLUE_BG) 

//< ��ǥ�� x ��  y�� �̵���Ų��( Ŀ���� ��ǥ )
void	setPosition( int x , int y);

//< ���� ���콺Ŀ���� x��ǥ�� ��´�.
int		getPositionX( void );

//< ���� ���콺Ŀ���� y��ǥ�� ��´�.
int		getPositionY( void );

//< �ؽ�Ʈ ���� ����
void	setTextcolor( unsigned short color );

//< Ŀ�� �����
void	setCursor( void );

#endif