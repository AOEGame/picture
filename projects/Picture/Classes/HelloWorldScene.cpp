#include "HelloWorldScene.h"

#include "PPHead.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();


    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

   
//	PPLabel *label = PPLabel::create(PP_FONT_NAME, 18);
//	label->setString("Helvetica");
//	label->setPosition(ccp(160, 160));
//	addChild(label);
	
    initSprite();
	
    return true;
}

void HelloWorld::initSprite()
{
    const char * fileName = "Default.png";
    float width = 60;
    float padding = 70;
    
    for (int i = 1; i <= 9; i++) {
        CCSprite *sp1  = CCSprite::create(fileName, CCRectMake(((i - 1) % 3 ) * width, int((i - 1) / 3) * width, width, width));
        sp1->setAnchorPoint(ccp(0.5, 0.5));
        sp1->setPosition(ccp(padding + 0.5f * width + ((i - 1) % 3) * (width + 1), 400 - (padding + 0.5f * width + int((i - 1) / 3) * (width + 1))));
        addChild(sp1);
    }
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	PPHelp::userImages();
	
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
//	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//#else
//    CCDirector::sharedDirector()->end();
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//#endif
}
