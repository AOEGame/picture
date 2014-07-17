
#ifndef __Picture__PPLabel__
#define __Picture__PPLabel__

#include <iostream>
#include "cocos2d.h"

#include "PPConfig.h"

class PPLabel : public cocos2d::CCLabelTTF
{
public:
	PPLabel();
	virtual ~PPLabel();
	
	static PPLabel *create(const char *fontName, float fontSize);
	
	bool init(const char *fontName, float fontSize);
};

#endif /* defined(__Picture__PPLabel__) */
