
#include "PPLabel.h"

PPLabel::PPLabel()
{
}

PPLabel::~PPLabel()
{

}

PPLabel* PPLabel::create(const char *fontName, float fontSize)
{
	PPLabel *pRet = new PPLabel();
	if (pRet && pRet->init(fontName, fontSize)) {
		pRet->autorelease();
		return pRet;
	}else{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

bool PPLabel::init(const char *fontName, float fontSize)
{
	if (!CCLabelTTF::initWithString("", fontName, fontSize)) {
		return false;
	}
	
	return true;
}