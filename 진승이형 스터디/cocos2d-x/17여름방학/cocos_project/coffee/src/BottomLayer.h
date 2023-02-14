#ifndef __BOTTOM_LAYER_H__
#define __BOTTOM_LAYER_H__

#include "cocos2d.h"
#include "network\HttpClient.h"
#pragma execution_character_set("utf-8")


class BottomLayer : public cocos2d::LayerColor
{
public:
	enum eDEPTH_ORDER_BOTTOM
	{
		SPRITE_BACKGROUND = 0,
		SPRITE_UI,
		MENU,
		MENU_ITEM
	};

	static cocos2d::LayerColor* createLayer();

	virtual bool init();

	CREATE_FUNC(BottomLayer);

	void InitBottomMenu();

	// button callback
	void CallbackPublicRelations(cocos2d::Ref* pSender);
	void CallbackCloseGame(cocos2d::Ref* pSender);

	void CallNetwork();
	void CallbackNetworkRequest(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response);
};

#endif // !__BOTTOM_LAYER_H__
