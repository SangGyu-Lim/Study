#include <iostream>

#include "map.h"

using namespace std;

#define MAX	10

class CPlayer
{
public:
	int nPlayerarea[MAX][2];
	CMap cp_cMap;

public:
	CPlayer();
	~CPlayer()	{}

public:
	int CrashCheck();
};