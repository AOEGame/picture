
#include "MenuLayer.h"
#include "PPConfig.h"
#include "HelloWorldScene.h"
#include "PPLabel.h"

USING_NS_CC;

const int PP_MENU_TAG_START = 1;
const int PP_MENU_TAG_SOUND = 2;
const int PP_MENU_TAG_MORE = 3;

MenuLayer::MenuLayer()
{

}

MenuLayer::~MenuLayer()
{

}

void MenuLayer::draw()
{
//    CCSize size = CCDirector::sharedDirector()->getWinSize();
//	ccDrawSolidRect(ccp(0, 0), ccp(size.width, size.height), ccc4f(1.0f, 1.0f, 1.0f, 1.0f));
}

bool MenuLayer::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    CCLabelTTF *title = CCLabelTTF::create("精简拼图", PP_FONT_NAME, 34);
    title->setColor(ccRED);
    title->setAnchorPoint(ccp(0.5, 0.5));
    title->setPosition(ccp(160, 400));
    this->addChild(title, 1);
    
    CCLabelTTF *titleBg = CCLabelTTF::create("精简拼图", PP_FONT_NAME, 35);
    titleBg->setColor(ccBLACK);
    titleBg->setAnchorPoint(ccp(0.5, 0.5));
    titleBg->setPosition(ccp(160, 400));
    this->addChild(titleBg);
    
    CCSprite *bg = CCSprite::create("009.jpg");
    bg->setAnchorPoint(ccp(0, 0));
    bg->setPosition(ccp(0, 0));
    this->addChild(bg, -1);
    
    CCSprite *sp1 = CCSprite::create("rectangle_blue.png");
    PPLabel *label1 = PPLabel::create(PP_FONT_NAME, 13);
    label1->setString("开始游戏");
    label1->setColor(ccBLACK);
    label1->setPosition(ccp(sp1->getContentSize().width / 2, sp1->getContentSize().height / 2));
    sp1->addChild(label1);
    
    CCMenuItemSprite *item1 =  CCMenuItemSprite::create (sp1, NULL, this, menu_selector(MenuLayer::buttonClicked));
    item1->setTag(PP_MENU_TAG_START);
    item1->setPosition(ccp(160, 280));
    
    CCSprite *sp2 = CCSprite::create("rectangle_blue.png");
    PPLabel *label2 = PPLabel::create(PP_FONT_NAME, 13);
    label2->setString("玩法介绍");
    label2->setColor(ccBLACK);
    label2->setPosition(ccp(sp2->getContentSize().width / 2, sp2->getContentSize().height / 2));
    sp2->addChild(label2);
    
    CCMenuItemSprite *item2 = CCMenuItemSprite::create(sp2, NULL, this, menu_selector(MenuLayer::buttonClicked));
    item2->setTag(PP_MENU_TAG_SOUND);
    item2->setPosition(ccp(160, 180));
    
    CCMenu *menu = CCMenu::create(item1, item2, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    return true;
}
void MenuLayer::buttonClicked(cocos2d::CCObject *obj)
{
    CCMenuItemSprite *item = (CCMenuItemSprite *)obj;
    int tag = item->getTag();
    if(tag == PP_MENU_TAG_START){
        CCScene *scene = HelloWorld::scene();
        HelloWorld *layer = HelloWorld::create();
        layer->setTag(PP_HELLO_LAYER_TAG);
        scene->addChild(layer);
        this->removeFromParent();
    }
}

