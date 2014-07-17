//
//  PPImagePicker.m
//  Picture
//
//  Created by sifengbo on 14年7月16日.
//
//

#import "PPImagePicker.h"

static PPImagePicker *picker = NULL;

@implementation PPImagePicker

+ (id) sharedImagePicker
{
	if (!picker) {
		picker = [[PPImagePicker alloc] init];
	}
	return picker;
}

- (void)showImages
{
	UIActionSheet *sheet;
	
	// 判断是否支持相机
	BOOL isCamera = [UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera];
	if (isCamera) {
		sheet = [[UIActionSheet alloc] initWithTitle:@"选择" delegate:self cancelButtonTitle:nil destructiveButtonTitle:@"取消" otherButtonTitles:@"拍照", @"从相册选择",nil];
	}else{
		 sheet = [[UIActionSheet alloc] initWithTitle:@"选择图像" delegate:self cancelButtonTitle:nil destructiveButtonTitle:@"取消" otherButtonTitles:@"从相册选择", nil];
	}
	
	sheet.tag = 255;
	
	[sheet showInView:[UIApplication sharedApplication].keyWindow];
	
}

#pragma mark - action sheet delegte
- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (actionSheet.tag == 255) {
        NSUInteger sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
			// 判断是否支持相机
        if([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera]) {
            switch (buttonIndex) {
                case 0:
                    return;
                case 1: //相机
                    sourceType = UIImagePickerControllerSourceTypeCamera;
                    break;
                case 2: //相册
                    sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
                    break;
            }
        }
        else {
            if (buttonIndex == 0) {
                return;
            } else {
                sourceType = UIImagePickerControllerSourceTypeSavedPhotosAlbum;
            }
        }
			// 跳转到相机或相册页面
        UIImagePickerController *imagePickerController = [[UIImagePickerController alloc] init];
        imagePickerController.delegate = self;
        imagePickerController.allowsEditing = YES;
        imagePickerController.sourceType = sourceType;
		
        [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:imagePickerController animated:YES completion:^{}];
    }
}

#pragma mark - image picker delegte
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info
{
//    [picker dismissViewControllerAnimated:YES completion:^{}];
//	
//    UIImage *image = [info UIImagePickerControllerOriginalImage];
//    userImageView.image = image;
//	
//    NSData *imageData = UIImageJPEGRepresentation(image, COMPRESSED_RATE);
//    UIImage *compressedImage = [UIImage imageWithData:imageData];
//	
//    [HttpRequestManager uploadImage:compressedImage httpClient:self.httpClient delegate:self];

	NSLog(@">>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	
}

@end
