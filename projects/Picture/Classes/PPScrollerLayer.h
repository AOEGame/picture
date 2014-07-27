
#ifndef __Picture__PPScrollerLayer__
#define __Picture__PPScrollerLayer__

#include <iostream>

#include "cocos2d.h";
#include "cocos-ext.h";

using namespace cocos2d;
using namespace extension;

class PPScrollerLayer :public cocos2d::CCLayer, public CCScrollViewDelegate
{
public:
    virtual bool init();
//    CREATE_FUNC(PPScrollerLayer);
    
    virtual void scrollViewDidScroll(CCScrollView * view);
    
};

#endif /* defined(__Picture__PPScrollerLayer__) */
