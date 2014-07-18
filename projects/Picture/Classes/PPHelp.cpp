
#include "PPHelp.h"
#include "PPHead.h"
#include "cocos2d.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
void PPHelp::userImages()
{
	cocos2d::CCLog("XXXXXXXXXXXX");
	NTJava::callStaticVoidMethod(BB_JNI_PACKAGE_NAME,"showImageDialog","");
}
#endif
