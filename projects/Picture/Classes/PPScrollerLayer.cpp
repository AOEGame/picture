

#include "PPScrollerLayer.h"

bool PPScrollerLayer::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
//    CCSize size = CCDirector::sharedDirector()->getWinSize();
//    
//    CCLayer *container = CCLayer::create();
    
    
    return true;
    
}

void PPScrollerLayer::scrollViewDidScroll(CCScrollView *view)
{

}
