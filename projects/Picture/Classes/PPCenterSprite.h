
#ifndef __Picture__PPCenterSprite__
#define __Picture__PPCenterSprite__

#include <iostream>
#include "cocos2d.h"

class PPCenterSprite : public cocos2d::CCSprite, public cocos2d::CCTouchDelegate
{
public:
	
	PPCenterSprite ();
	~PPCenterSprite ();
	
	
	//fileName 大图名字； w 小图宽度， num 一行的数量 比如3*3 的4*4的
	static PPCenterSprite *createWithFilename(const char* fileName, float w, int num);
	
	bool initWithFileName(const char* fileName, float w, int num);
	
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	
private:
	const char* m_pName;
	float pWidth; //单个长度
	int pNum; //一行数量
	
	
	
	cocos2d::CCArray *m_pArray;
	
	cocos2d::CCPoint startPos;
	
	cocos2d::CCPoint emptyPos;
};


#endif /* defined(__Picture__PPCenterSprite__) */
