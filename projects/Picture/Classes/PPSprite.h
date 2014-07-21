

#ifndef __Picture__PPSprite__
#define __Picture__PPSprite__

#include <iostream>

#include "cocos2d.h"

class PPSprite : public cocos2d::CCSprite
{
public:
	PPSprite();
	~PPSprite(){};
	
	static PPSprite* createWithRect(const char* fileName, const cocos2d::CCRect &rect);
	
	bool initWithRect(const char* fileName, const cocos2d::CCRect &rect);
	
	cocos2d::CCPoint getPos(){
		return tPos;
	};
	
	void setPos(const cocos2d::CCPoint &pos);
	
private:
	
	cocos2d::CCPoint tPos;
	
};


#endif /* defined(__Picture__PPSprite__) */
