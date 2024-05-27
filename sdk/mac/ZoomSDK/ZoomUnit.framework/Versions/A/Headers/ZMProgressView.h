//
//  ZMProgressView.h
//  zChatUI
//
//  Created by javenlee on 2018/11/7.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>

@interface ZMProgressShapeLayer : CAShapeLayer

@property (nonatomic, retain) NSColor *tintColor;
@property (nonatomic, retain) NSColor *backColor;
@property (nonatomic, assign) float progress;
@property (nonatomic, assign) BOOL isNeedAnimate;
@property (nonatomic, copy) void(^progressFinish)(BOOL finish);

-(void)showProgress:(float)progress;

@end

@interface ZMProgressCircularRingShapeLayer : ZMProgressShapeLayer
@end

@interface ZMProgressView : NSView

@property (nonatomic, assign) float progress;
@property (nonatomic, assign) double doubleValue;

- (void)setProgressLayerClass:(Class)layerClass;
- (void)setProgress:(float)progress animated:(BOOL)animated;
- (void)setTintColor:(NSColor *)tintColor;
- (void)setBackColor:(NSColor *)backColor;// default "whiteColor"
- (void)setLineWidth:(CGFloat)lineWidth;// default 2

@end
