#ifndef __LOBBY_SCENE_H__
#define __LOBBY_SCENE_H__

#include "cocos2d.h"

class Lobby : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	// init
	virtual bool init();

	void InitTitle();
	void InitButton();

	void CallbackNextScene();

	

	CREATE_FUNC(Lobby);

};
#endif // !__LOBBY_SCENE_H__
