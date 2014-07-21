#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();
	
	virtual void draw();

    static cocos2d::CCScene* scene();

    void menuCloseCallback(CCObject* pSender);
    
    CREATE_FUNC(HelloWorld);
    
    void initSprite();
private:
    cocos2d::CCSprite *m_pDefault;
};

#endif // __HELLOWORLD_SCENE_H__
