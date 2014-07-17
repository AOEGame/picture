//
//  PPImagePicker.h
//  Picture
//
//  Created by sifengbo on 14年7月16日.
//
//

#import <Foundation/Foundation.h>

@interface PPImagePicker : NSObject <UIActionSheetDelegate,UINavigationControllerDelegate, UIImagePickerControllerDelegate>

+ (id)sharedImagePicker;

- (void)showImages;

@end
