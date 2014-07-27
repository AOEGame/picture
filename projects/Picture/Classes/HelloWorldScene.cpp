#include "HelloWorldScene.h"

#include "PPHead.h"

USING_NS_CC;

static CCScene *m_sc = NULL;

const int PP_BUTTON_LAST_ITEM = 1;
const int PP_BUTTON_BACK_ITEM = 2;

const int PP_BUTTON_RESTART_ITEM = 3;

const int PP_BUTTON_REBACK_ITEM = 4;

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
    
//    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
//    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();


//    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
//                                        "CloseNormal.png",
//                                        "CloseSelected.png",
//                                        this,
//                                        menu_selector(HelloWorld::menuCloseCallback));
//    
//	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
//                                origin.y + pCloseItem->getContentSize().height/2));
//
//    // create menu, it's an autorelease object
//    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
//    pMenu->setPosition(CCPointZero);
//    this->addChild(pMenu, 1);

   
//	PPLabel *label = PPLabel::create(PP_FONT_NAME, 18);
//	label->setString("Helvetica");
//	label->setPosition(ccp(160, 160));
//	addChild(label);
	
    CCSprite *bg = CCSprite::create("009.jpg");
    bg->setAnchorPoint(ccp(0, 0));
    bg->setPosition(ccp(0, 0));
    this->addChild(bg, -1);
    
    this->initSprite();
	this->initGame();
    return true;
}

void HelloWorld::draw()
{
//	CCSize size = CCDirector::sharedDirector()->getWinSize();
//	ccDrawSolidRect(ccp(0, 0), ccp(size.width, size.height), ccc4f(1.0f, 1.0f, 1.0f, 1.0f));
}

void HelloWorld::initSprite()
{
    const char * fileName = "haizeiwang.jpg";
    float w = 60.0f;
    int n = 4;
	m_pCenter = PPCenterSprite::createWithFilename(fileName, w, n);
	
	m_pCenter->setAnchorPoint(ccp(0.5, 0));
	m_pCenter->setPosition(ccp(160, 100));
	addChild(m_pCenter);
    
    m_pDefault = PPCenterSprite::create(fileName, CCRectMake(0, 0, w * n, w * n));
    m_pDefault->setScale(0.4);
    m_pDefault->setPosition(ccp(90, 400));
    addChild(m_pDefault);
    
    float oX = ((n * n - 1) % n) * w;
    float oY = int((n * n - 1) / n) * w;
    
    PPSprite *iSprite = PPSprite::createWithRect(fileName, cocos2d::CCRectMake(oX, oY, w, w));
    
    lastItem = CCMenuItemSprite::create(iSprite, NULL, this, menu_selector(HelloWorld::buttonTouched));
    lastItem->setAnchorPoint(ccp(0, 0));
    lastItemPos = ccp(160 - iSprite->getContentSize().width * (n / 2 - n + 1) , 100 - iSprite->getContentSize().width);
    lastItem->setPosition(lastItemPos);
    lastItem->setTag(PP_BUTTON_LAST_ITEM);
    lastItem->setEnabled(true);
    
    
    CCSprite *iSprite2 = CCSprite::create("rectangle_blue.png");
    PPLabel *label1 = PPLabel::create(PP_FONT_NAME, 13);
    label1->setString("回到菜单");
    label1->setColor(ccBLACK);
    label1->setPosition(ccp(iSprite2->getContentSize().width / 2, iSprite2->getContentSize().height / 2));
    iSprite2->addChild(label1);
    
    CCMenuItemSprite *item2 =  CCMenuItemSprite::create(iSprite2, NULL, this, menu_selector(HelloWorld::buttonTouched));
    item2->setTag(PP_BUTTON_BACK_ITEM);
    item2->setPosition(ccp(240, 400));
    
    m_pMenu = CCMenu::create(lastItem, item2, NULL);
    m_pMenu->setPosition(CCPointZero);
    addChild(m_pMenu);
}

void HelloWorld::initGame()
{
    m_pCenter->setCanTouch(true);
    m_pMenu->setEnabled(true);
    
    for (int i = 0; i < 100; i++) {
        srand(int(time(0)) + rand());
        
        int tem = rand() % 4;
        if (tem == 0) {
            m_pCenter->moveLeft(false);
        }else if (tem == 1){
            m_pCenter->moveDown(false);
        }else if (tem == 2){
            m_pCenter->moveRight(false);
        }else if (tem == 3){
            m_pCenter->moveOn(false);
        }
    }
}

void HelloWorld::buttonTouched(cocos2d::CCObject *obj)
{
    CCMenuItem *item = dynamic_cast<CCMenuItem *>(obj);
    int tag = item->getTag();
    if (tag == PP_BUTTON_LAST_ITEM) {
        if (m_pCenter->isEmptyAtLast()) {
            
            if (m_pCenter->isWin()) {
                m_pCenter->setCanTouch(false);
                
                CCMoveBy *ac1 = CCMoveBy::create(0.07, ccp(0, lastItem->getNormalImage()->getContentSize().height));
                CCCallFunc *ac2 = CCCallFunc::create(this, callfunc_selector(HelloWorld::showWin));
                lastItem->runAction(CCSequence::create(ac1, ac2, NULL));
            }else{
                showWin(false);
            }
        }
    }else if (tag == PP_BUTTON_BACK_ITEM){
        MenuLayer *layer = MenuLayer::create();
        CCScene *scene = HelloWorld::scene();
        scene->addChild(layer);
        m_pCenter->setCanTouch(false);
        m_pCenter = NULL;
        this->removeAllChildren();
        this->removeFromParent();
    }else if (tag == PP_BUTTON_RESTART_ITEM){
        if (m_pRt) {
            m_pRt->removeFromParent();
            m_pRt = NULL;
        }
        if (m_pInfo) {
            m_pInfo->removeFromParent();
            m_pInfo = NULL;
        }
        
        if (m_pWinMenu) {
            m_pWinMenu->setEnabled(false);
            m_pWinMenu->removeFromParent();
            m_pWinMenu = false;
        }
        
        m_pMenu->setEnabled(true);
        
        lastItem->setPosition(lastItemPos);
        initGame();
    }else if (tag == PP_BUTTON_REBACK_ITEM){
        if (m_pRt) {
            m_pRt->removeFromParent();
            m_pRt = NULL;
        }
        
        if (m_pWinMenu) {
            m_pWinMenu->setEnabled(false);
            m_pWinMenu->removeFromParent();
            m_pWinMenu = false;
        }
        if (m_pInfo) {
            m_pInfo->removeFromParent();
            m_pInfo = NULL;
        }
        
         m_pMenu->setEnabled(true);
    }
}

void HelloWorld::showWin(bool b)
{
    CCLOG("cccccccccccccccccccc");
    
    m_pMenu->setEnabled(false);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    m_pRt = CCRenderTexture::create(size.width, size.height);
    m_pRt->beginWithClear(0, 0, 0, 0.7);
    m_pRt->end();
    m_pRt->setPosition(ccp(size.width / 2, size.height / 2));
    addChild(m_pRt, 10);
    
    
    m_pInfo = CCLabelTTF::create("", PP_FONT_NAME, 18, CCSizeMake(250, 200), kCCTextAlignmentCenter);
    m_pInfo->setPosition(CCPoint(160, 330));
    this->addChild(m_pInfo, 11);
    if (b) {
        m_pInfo->setString("恭喜您完成拼图！！");
        m_pInfo->setColor(ccGREEN);
    }else{
        m_pInfo->setString("您的拼图有误，请仔细检查拼图每块图片！！");
        m_pInfo->setColor(ccRED);
    }
    
    
    CCSprite *sp1 = CCSprite::create("rectangle_blue.png");
    PPLabel *label1 = PPLabel::create(PP_FONT_NAME, 13);
    label1->setString("回到菜单");
    label1->setColor(ccBLACK);
    label1->setPosition(ccp(sp1->getContentSize().width / 2, sp1->getContentSize().height / 2));
    sp1->addChild(label1);
    
    CCMenuItemSprite *item1 =  CCMenuItemSprite::create (sp1, NULL, this, menu_selector(HelloWorld::buttonTouched));
    item1->setTag(PP_BUTTON_BACK_ITEM);
    item1->setPosition(ccp(160, 290));
    
    CCSprite *sp2 = CCSprite::create("rectangle_blue.png");
    PPLabel *label2 = PPLabel::create(PP_FONT_NAME, 13);
    label2->setString("重新开始");
    label2->setColor(ccBLACK);
    label2->setPosition(ccp(sp2->getContentSize().width / 2, sp2->getContentSize().height / 2));
    sp2->addChild(label2);
    
    CCMenuItemSprite *item2 = CCMenuItemSprite::create(sp2, NULL, this, menu_selector(HelloWorld::buttonTouched));
    item2->setTag(PP_BUTTON_RESTART_ITEM);
    item2->setPosition(ccp(160, 200));
    
    if (b) {
        m_pWinMenu = CCMenu::create(item1, item2, NULL);
        m_pWinMenu->setPosition(CCPointZero);
        this->addChild(m_pWinMenu, 11);
    }else{
        CCSprite *sp3 = CCSprite::create("rectangle_blue.png");
        PPLabel *label3 = PPLabel::create(PP_FONT_NAME, 13);
        label3->setString("回到游戏");
        label3->setColor(ccBLACK);
        label3->setPosition(ccp(sp3->getContentSize().width / 2, sp3->getContentSize().height / 2));
        sp3->addChild(label3);
        
        CCMenuItemSprite *item3 = CCMenuItemSprite::create(sp3, NULL, this, menu_selector(HelloWorld::buttonTouched));
        item3->setTag(PP_BUTTON_REBACK_ITEM);
        item3->setPosition(ccp(160, 110));
        
        m_pWinMenu = CCMenu::create(item1, item2, item3, NULL);
        m_pWinMenu->setPosition(CCPointZero);
        this->addChild(m_pWinMenu, 11);
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
