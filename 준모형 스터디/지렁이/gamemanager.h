#include <iostream>

#include "map.h"
#include "consol.h"
#include "player.h"
#include "stage.h"
#include <conio.h>
#include <windows.h>

using namespace std;

#define UP		0x48
#define LEFT	0x4B
#define RIGHT	0x4D
#define DOWN	0x50
#define TRUE	1
#define FALSE	0
#define PDELAY	100
#define FDELAY	5000

class CGameManager
{
public:

	int test;
	UPOINT testPT;

	int key;
	UPOINT pt;
	CPlayer cPlayer;
	CStage cStage;

	DWORD PlayercurTime;
	DWORD Playertime;
	DWORD FoodcurTime;
	DWORD Foodtime;

public:
	CGameManager();
	~CGameManager()	{}

public:
	void Manager();
	void GetPlayerxy(int index);
	void StageInformationPrint();
	void Food();
	void DrawPlayer();

	int PlayerRender();
	int FoodRender();
};