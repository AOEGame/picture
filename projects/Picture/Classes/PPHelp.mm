
#include "PPHelp.h"

void PPHelp::userImages()
{
	UIActionSheet *sheet;
	
	//是否支持相机
	bool isCamera = [UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera];
	if (isCamera) {
		sheet = [[UIActionSheet alloc] initWithTitle:@"选择图" delegate:self cancelButtonTitle:nil destructiveButtonTitle:@"取消" otherButtonTitles:@"拍照", ,@"从相册",nil];
	}
}