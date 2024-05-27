//
//  ZMGIFImageView.h
//  zChatUI
//
//  Created by groot.ding on 2019/8/15.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMGIFImageView : NSControl

@property (nullable,nonatomic,retain) NSImage*image;

//if wants play gif you should set image path
@property (nonatomic,copy,nullable) NSString *imagePath;

@property (nonatomic,assign) CGSize imageMaxSize;

@property (nonatomic,assign) BOOL animates;

@property (nullable, nonatomic, copy) CALayerContentsGravity contentsGravity;

@property (nonatomic,assign) CGFloat cornerRadius;
@property (nonatomic,assign) CGFloat borderWidth;
@property (nullable, nonatomic, strong) NSColor *borderColor;

@property (nullable, nonatomic,retain) NSColor *backgroundColor;
@property (nonatomic,assign) BOOL needBecomeKeyView;
@property (nonatomic,assign) BOOL keepLastFrameImage;

@property (nonatomic,assign) CGAffineTransform affineTransform;

@property (nonatomic,assign) SEL firstResponseChanged;

-(void)stopPlayGIF;

@end

NS_ASSUME_NONNULL_END
