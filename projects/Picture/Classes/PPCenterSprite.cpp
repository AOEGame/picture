
#include "PPCenterSprite.h"
#include "PPSprite.h"

PPCenterSprite::PPCenterSprite()
	: emptyPos(cocos2d::CCPointZero)
	, startPos(cocos2d::CCPointZero)
	, m_pArray(NULL)
{
}

PPCenterSprite::~PPCenterSprite()
{
	CC_SAFE_RELEASE_NULL(m_pArray);
}

PPCenterSprite* PPCenterSprite::createWithFilename(const char *fileName, float w, int num)
{
	PPCenterSprite *pRet = new PPCenterSprite();
	if (pRet && pRet->initWithFileName(fileName, w, num)) {
		pRet->autorelease();
		return pRet;
	}else{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

bool PPCenterSprite::initWithFileName(const char *fileName, float w, int num)
{
	if (!CCSprite::init()) {
		return false;
	}
	m_pName = fileName;
	pWidth = w;
	pNum = num;
	
	float width = (pWidth + 1) * pNum;
	
	this->setContentSize(cocos2d::CCSizeMake(width, width));
	
	m_pArray = cocos2d::CCArray::create();
	m_pArray->retain();
	
	for (int i = 1; i <= pNum * pNum; i++) {
		
		float oX = ((i - 1) % pNum ) * pWidth;
		float oY = int((i - 1) / pNum) * pWidth;
		
        PPSprite *sp1  = PPSprite::createWithRect(fileName, cocos2d::CCRectMake(oX, oY, pWidth, pWidth));
		cocos2d::CCPoint pos = ccp(((i - 1) % pNum) * sp1->getContentSize().width, width - (int((i - 1) / pNum) * sp1->getContentSize().height));
		m_pSpriteWidth = sp1->getContentSize().width;
        sp1->setPosition(pos);
		sp1->setPos(pos);
        this->addChild(sp1);
		if (i == pNum * pNum) {
			emptyPos = pos;
			sp1->setVisible(false);
			break;
		}
		
		m_pArray->addObject(sp1);
    }
	
	cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
	
	return true;
}

bool PPCenterSprite::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	cocos2d::CCPoint pos = this->getParent()->convertTouchToNodeSpace(pTouch);
	if (this->boundingBox().containsPoint(pos)) {
		startPos = convertTouchToNodeSpace(pTouch);
		return true;
	}
	
	return false;
}

void PPCenterSprite::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	cocos2d::CCPoint pos = convertTouchToNodeSpace(pTouch);
	
	CCLOG("%1.0f－－－－%1.0f",fabsf(pos.x - startPos.x), fabsf(pos.y - startPos.y));
	
	if (fabsf(pos.x - startPos.x) > fabsf(pos.y - startPos.y)  && fabsf(pos.x - startPos.x) > 10.0f) {
		//		x轴方向
		if (pos.x - startPos.x > 0 && emptyPos.x >= 0) {
			float x = emptyPos.x - m_pSpriteWidth;
			for (int i = 0; i < m_pArray->count(); i++) {
				PPSprite *sprite = (PPSprite *)m_pArray->objectAtIndex(i);
				if (sprite->getPosition().equals(ccp(x, emptyPos.y))) {
					emptyPos = sprite->getPosition();
					sprite->runAction(cocos2d::CCMoveTo::create(0.1, ccp(x += m_pSpriteWidth, emptyPos.y)));
					break;
				}
			}
		}else if (pos.x - startPos.x < 0 && emptyPos.x < pWidth * pNum){
			
			float x = emptyPos.x + m_pSpriteWidth;
			for (int i = 0; i < m_pArray->count(); i++) {
				PPSprite *sprite = (PPSprite *)m_pArray->objectAtIndex(i);
				if (sprite->getPosition().equals(ccp(x, emptyPos.y))) {
					sprite->runAction(cocos2d::CCMoveTo::create(0.1, ccp(x -= m_pSpriteWidth, emptyPos.y)));
					break;
				}
			}
		}
		
	}else if(fabsf(pos.x - startPos.x) <= fabsf(pos.y - startPos.y)  && fabsf(pos.y - startPos.y) > 10.0f){
		//   y轴方向
		
	}
}

void PPCenterSprite::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{

}












