//
//  ZMGroupedElementOnlyImageButton.h
//  ChatUI
//
//  Created by simon shang on 2021/12/1.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <ZoomKit/ZMIMOnlyImageButton.h>
#import <ZoomKit/ZMGroupedAccessibilityView.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMGroupedElementOnlyImageButton : ZMIMOnlyImageButton <ZMGroupedAccessibilityElement>

@end

NS_ASSUME_NONNULL_END
