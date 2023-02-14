#ifndef __LOGIN_SCENE_H__
#define __LOGIN_SCENE_H__

#include "cocos2d.h"

class Login : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	// init
	virtual bool init();

	void InitTitle();
	void InitButton();

	void CallbackNextScene();

	CREATE_FUNC(Login);

};
#endif // !__LOGIN_SCENE_H__
