#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "network\HttpClient.h"


class HelloWorld : public cocos2d::Scene//, cocos2d::Layer
{
public:
	enum eIMAGE_TAG {
		NORMAL = 0,
		SUZY = 1
	};

	enum eARROW_TAG{
		UP = 10,
		DOWN = 11,
		LEFT = 12,
		RIGHT = 13
	};

    static cocos2d::Scene* createScene();

	bool isShowSuzy = true;

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void CallbackShowSuzy(cocos2d::Ref* pSender);
    
	// button click
	void OnClickArrow(cocos2d::Ref* pSender);

	// touch event
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void CallNetwork();
	void CallbackNetworkRequest(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response);
};

#endif // __HELLOWORLD_SCENE_H__
