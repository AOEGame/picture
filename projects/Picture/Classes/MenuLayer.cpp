
#include "MenuLayer.h"
#include "PPConfig.h"
#include "HelloWorldScene.h"

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


bool MenuLayer::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSprite *sp1 = CCSprite::create("Icon-114.png");
    CCMenuItemSprite *item1 =  CCMenuItemSprite::create (sp1, NULL, this, menu_selector(MenuLayer::buttonClicked));
    item1->setTag(PP_MENU_TAG_START);
    item1->setPosition(ccp(160, 300));
    
    CCSprite *sp2 = CCSprite::create("Icon-114.png");
    CCMenuItemSprite *item2 = CCMenuItemSprite::create(sp2, NULL, this, menu_selector(MenuLayer::buttonClicked));
    item2->setTag(PP_MENU_TAG_SOUND);
    item2->setPosition(ccp(160, 200));
    
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

