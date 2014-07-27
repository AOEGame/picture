#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PPCenterSprite.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();
	
	virtual void draw();

    static cocos2d::CCScene* scene();

    void menuCloseCallback(CCObject* pSender);
    
    CREATE_FUNC(HelloWorld);
    
    void initSprite();
    void buttonTouched(cocos2d::CCObject *obj);
    
    void showWin(bool b = true);
    
    void initGame();
    
private:
    cocos2d::CCSprite *m_pDefault;
    cocos2d::CCMenuItemSprite *lastItem;
    
    PPCenterSprite *m_pCenter;
    
    cocos2d::CCMenu *m_pMenu;
    
    cocos2d::CCMenu *m_pWinMenu;
    
    cocos2d::CCRenderTexture *m_pRt;
    
    cocos2d::CCPoint lastItemPos;
    
    cocos2d::CCLabelTTF *m_pInfo;
};

#endif // __HELLOWORLD_SCENE_H__
