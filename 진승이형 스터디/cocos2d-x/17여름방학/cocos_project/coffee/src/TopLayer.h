#ifndef __TOP_LAYER_H__
#define __TOP_LAYER_H__

#include "cocos2d.h"

class TopLayer : public cocos2d::LayerColor
{
public:

	enum eDEPTH_ORDER_TOP
	{
		SPRITE_BACKGROUND = 0,
		SPRITE_UI,
		LABEL
	};


	static cocos2d::LayerColor* createLayer();

	virtual bool init();

	CREATE_FUNC(TopLayer);

	void InitTopMenu();

	cocos2d::LabelTTF* survivalDay;
	cocos2d::Label* capital;

	void SetSurvivalDayLabel();
	void SetGoldLabel();
	
};

#endif // !__TOP_LAYER_H__
