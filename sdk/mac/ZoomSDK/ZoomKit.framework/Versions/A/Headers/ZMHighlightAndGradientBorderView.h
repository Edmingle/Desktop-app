//
//  ZMHighlightAndGradientBorderView.h
//  ZoomKit
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

/// Adds a gradient colored border and/or a highlight (which darkens outside the border) to a view.
/// Borders start at target's frame rect and end at target's frameRect inset by borderWidth, similar to CALayer.
@interface ZMHighlightAndGradientBorderView : NSView
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)roundRectBorderWithFrame:(NSRect)frame withCornerRadius:(CGFloat)radius
                             borderWidth:(CGFloat)width highlightColor:(NSColor* _Nullable)highlight;

// NOTE: addToTargetView functions add the ZMHighlightAndGradientBorderView into the view hierarchy during creation
+ (instancetype)addRoundRectBorderToTargetView:(NSView*)target withCornerRadius:(CGFloat)radius
                                   borderWidth:(CGFloat)width highlightColor:(NSColor* _Nullable)highlight;
/// xOutset and yOutset can be used to make the border extend beyond target's frame
+ (instancetype)addRoundRectBorderToTargetView:(NSView*)target withCornerRadius:(CGFloat)radius
                                   borderWidth:(CGFloat)width highlightColor:(NSColor* _Nullable)highlight
                                       xOutset:(CGFloat)xOutset yOutset:(CGFloat)yOutset;
/// @discussion The circle border is inset from max radius, so min radius == max radius - width. The circle border is centered on the target view
/// @note If the circle border's max radius extends beyond the target view's frame, the highlight will also extend beyond the target view's frame.
+ (instancetype)addCircleBorderToTargetView:(NSView*)target withMaxRadius:(CGFloat)radius
                                borderWidth:(CGFloat)width highlightColor:(NSColor* _Nullable)highlight;
@end

NS_ASSUME_NONNULL_END
