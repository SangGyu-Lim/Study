#ifndef _JUTIL_H__
#define _JUTIL_H__

//< 조합으로 만들어낸 색상
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

//< 좌표를 x 와  y로 이동시킨다( 커서의 좌표 )
void	setPosition( int x , int y);

//< 현재 마우스커서의 x좌표를 얻는다.
int		getPositionX( void );

//< 현재 마우스커서의 y좌표를 얻는다.
int		getPositionY( void );

//< 텍스트 색상 변경
void	setTextcolor( unsigned short color );

//< 커서 지우기
void	setCursor( void );

#endif