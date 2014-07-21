
#ifndef __Picture__MenuLayer__
#define __Picture__MenuLayer__

#include <iostream>

#include "cocos2d.h"

class MenuLayer : public cocos2d::CCLayer
{
public:
    MenuLayer();
    ~MenuLayer();
    
    virtual bool init();
    
    CREATE_FUNC(MenuLayer);
    
    void buttonClicked(cocos2d::CCObject *obj);
    
};

#endif /* defined(__Picture__MenuLayer__) */
