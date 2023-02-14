#ifndef __DEFINE_H__
#define __DEFINE_H__

#include <map>

using namespace std;

#define	MAKE_PRICE_SYRUP		2000
#define BEST_POPULARITY_SYRUP	35
#define RATE_POPULARITY_SYRUP	0.3
#define RATE_SALE_PRICE			40

#define		DATA_FILENAME_MENU		"data/menu.data"
#define		STRING_FILENAME_MENU	"data/menu.xml"
#define		DATA_FILENAME_FONT		"fonts/NanumGothic.ttf"

typedef unsigned int        UINT;
typedef unsigned char       BYTE;		// 255~ 1byte
typedef unsigned short      WORD;		// 65000~ 2byte



enum eDATA_TYPE
{
	DATA_TYPE_MENU = 0,
	DATA_TYPE_MAX
};

// Data FileLoader
enum eDATA_FILE_LOADER
{
	DATA_LOAD_COMPLETE = 0,
	DATA_LOAD_ERROR_OPEN,
	DATA_LOAD_ERROR_READ,
	DATA_LOAD_ERROR_TYPE,
};

enum eDATA_FILE_REFERENCE_INDEX
{
	DATA_FILE_MENU_COFFEE_BEAN = 0,
	DATA_FILE_MENU_MILK = 3,
	DATA_FILE_MENU_ICE = 6,
	DATA_FILE_MENU_BASIC_COFFEE_BEAN = 9,
	DATA_FILE_MENU_BASIC_MILK,
	DATA_FILE_MENU_BASIC_ICE,
};



// struct(Data)
typedef struct
{
	BYTE	dataType;
	WORD	dataCount;
}DATA_HEADER, *LPDATA_HEADER;

typedef struct
{
	WORD	index;
	WORD	productType;	// 0 : 기본, 1 : 구매해야되는 제품
	int		buyPrice;		// 제품 구매 가격
	int		makePrice;		// 제품 제작 가격
	int		popularity;		// 제품 제작시 인기도
	//char	name[32];		// name
}MENU_DATA, *LPMENU_DATA;


typedef map<WORD, LPMENU_DATA>					MAP_MENU_DATA;
typedef pair<WORD, LPMENU_DATA>					PAIR_MENU_DATA;
typedef MAP_MENU_DATA::iterator					ITERATOR_MENU_DATA;
typedef MAP_MENU_DATA::const_iterator			CONST_ITERATOR_MENU_DATA;

#endif // !__DEFINE_H__
