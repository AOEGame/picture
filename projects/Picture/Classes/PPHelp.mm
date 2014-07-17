
#include "PPHelp.h"

#import "PPImagePicker.h"

void PPHelp::userImages()
{
	PPImagePicker *picker = [PPImagePicker sharedImagePicker];
	[picker showImages];
}