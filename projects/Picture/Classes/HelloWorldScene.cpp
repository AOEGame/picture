#include "HelloWorldScene.h"

#include "PPHead.h"

USING_NS_CC;

static CCScene *m_sc = NULL;


CCScene* HelloWorld::scene()
{
    if (!m_sc) {
        m_sc = CCScene::create();
    }
    return m_sc;
}


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
    const char * fileName = "girl01.png";
	PPCenterSprite *pSprite = PPCenterSprite::createWithFilename(fileName, 60.0f, 4);
	
	pSprite->setAnchorPoint(ccp(0.5, 0.5));
	pSprite->setPosition(ccp(160, 200));
	addChild(pSprite);
    
    m_pDefault = PPCenterSprite::create(fileName, CCRectMake(0, 0, 60 * 4, 60*4));
    m_pDefault->setScale(0.5);
    m_pDefault->setPosition(ccp(90, 400));
    addChild(m_pDefault);
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
