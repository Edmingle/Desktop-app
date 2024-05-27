//
//  ZMFocusedTargetDimmingView.h
//  ZoomKit
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

/// Focuses a specific view by dimming all the other views in the same window.
@interface ZMFocusedTargetDimmingView : NSView
/// Creates a new ZMFocusedTargetDimmingView that dims everything in the window except for target.
/// The dimming view is added to the view hierarchy.
+ (instancetype)zmFocusedTargetDimmingViewFocusingOn:(NSView*)target;
/// Creates a new ZMFocusedTargetDimmingView that dims the entirety of target.
/// The dimming view is added to the view hierarchy.
+ (instancetype)zmDimmingViewCovering:(NSView*)target;
- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
