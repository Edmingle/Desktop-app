//
//  ZMRichFormatParagraphStyle.h
//  ChatUI
//
//  Created by Yong Zhou on 9/8/21.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMRichFormatParagraphStyle : NSMutableParagraphStyle

@property (nonatomic, assign) BOOL isBulletFormat;
@property (nonatomic, assign) BOOL isNumberListFormat;
@property (nonatomic, assign) BOOL isIndentFormat;
@property (nonatomic, assign) BOOL isQuoteFormat;
@property (nonatomic, assign) BOOL isQuoteBegin;
@property (nonatomic, assign) BOOL isQuoteEnd;
@property (nonatomic, assign) BOOL isHeadingFormat;

+ (ZMRichFormatParagraphStyle *)zm_mutableCopywithParagraphStyle:(NSParagraphStyle*)mStyle NS_RETURNS_RETAINED;
+ (ZMRichFormatParagraphStyle *)zm_defaultParagraphStyle;

@end

NS_ASSUME_NONNULL_END
