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
	
    this->initSprite();
	
    return true;
}

void HelloWorld::draw()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	ccDrawSolidRect(ccp(0, 0), ccp(size.width, size.height), ccc4f(1.0f, 1.0f, 1.0f, 1.0f));
}

void HelloWorld::initSprite()
{
    const char * fileName = "Default.png";
//    float width = 50;
//    float padding = 70;
//    
//    for (int i = 1; i <= 16; i++) {
//        PPSprite *sp1  = PPSprite::createWithRect(fileName, CCRectMake(((i - 1) % 4 ) * width, int((i - 1) / 4) * width, width, width));
//        sp1->setAnchorPoint(ccp(0.5, 0.5));
//        sp1->setPosition(ccp(padding + 0.5f * sp1->getContentSize().width + ((i - 1) % 4) * sp1->getContentSize().width, 400 - (padding + 0.5f * sp1->getContentSize().height + int((i - 1) / 4) * sp1->getContentSize().height)));
//        addChild(sp1);
//    }
	
	PPCenterSprite *pSprite = PPCenterSprite::createWithFilename(fileName, 50.0f, 4);
	
	pSprite->setAnchorPoint(ccp(0.5, 0.5));
	pSprite->setPosition(ccp(160, 300));
	addChild(pSprite);
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
