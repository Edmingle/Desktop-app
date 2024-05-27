//
//  NSWindow+ZmmtKit.h
//  VideoUI
//
//  Created by Francis Zhuo on 11/28/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSWindow (ZmmtKit)
- (nullable NSView*)getTitleView:(NSString*)title;
- (void)zm_windowStartLiveResize;
- (void)zm_windowEndLiveResize;

@property (class, readonly) CGFloat defaultTitlebarHeight;
- (CGFloat)getTitlebarHeight;

@property (assign) BOOL inToggleFullscreen;
@property (readonly,assign) BOOL isTitlebarFloating;
@property (readonly,assign) BOOL isTitlebarVisible;
- (void)showTitlebar;
/**
 if main window displayed, will display in the center of main window
 else if sending share, will display in the center of fitbar screen
 */
- (void)zmmtCenter;
@end
NS_ASSUME_NONNULL_END
