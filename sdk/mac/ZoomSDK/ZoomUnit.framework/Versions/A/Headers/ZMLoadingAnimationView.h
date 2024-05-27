//
//  ZMLoadingAnimationView.h
//  VideoUI
//
//  Created by Michael Lin on 2022/4/15.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <ZoomKit/ZoomKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMLoadingAnimationView : ZMBaseView

@property(retain, nonatomic, nullable) NSImageView *spinImageView;

- (instancetype)initWithFrame:(NSRect)frame loadingImage:(NSImage *)loadingImage;
- (void)startAnimation;
- (void)stopAnimation;

@end

NS_ASSUME_NONNULL_END
