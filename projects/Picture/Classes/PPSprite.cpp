
#include "PPSprite.h"

PPSprite::PPSprite()
	: tPos(cocos2d::CCPointZero)
{

}

PPSprite *PPSprite::createWithRect(const char *fileName, const cocos2d::CCRect &rect)
{
	PPSprite *pRet = new PPSprite();
	if (pRet && pRet->initWithRect(fileName, rect)) {
		pRet->autorelease();
		return pRet;
	}else{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

bool PPSprite::initWithRect(const char *fileName, const cocos2d::CCRect &rect)
{
	if (!CCSprite::init()) {
		return false;
	}
	
	this->setContentSize(cocos2d::CCSizeMake(rect.size.width + 1, rect.size.height + 1));
	
	cocos2d::CCRenderTexture *rt = cocos2d::CCRenderTexture::create(rect.size.width + 1, rect.size.height + 1);
	rt->beginWithClear(0, 0, 0, 1);
	rt->end();
	
	CCSprite *sp = CCSprite::createWithTexture(rt->getSprite()->getTexture());
	sp->setAnchorPoint(ccp(0.5, 0.5));
	sp->setPosition(ccp((rect.size.width + 1) / 2, (rect.size.height + 1) / 2));
	this->addChild(sp, -1);
	
	CCSprite *sp2 = CCSprite::create(fileName, rect);
	sp2->setAnchorPoint(ccp(0.5, 0.5));
	sp2->setPosition(ccp((rect.size.width + 1) / 2, (rect.size.height + 1) / 2));
	this->addChild(sp2, 0);
	
	return true;
}

void PPSprite::setPos(const cocos2d::CCPoint &pos)
{
	tPos = pos;
}