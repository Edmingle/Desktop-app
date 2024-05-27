//
//  NSFont+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSFont (ZoomKit)

/**
 If can't create font by particularly name, will return system font by given size
 @return no null font
 */
+ (NSFont *)nonullFontWithName:(nullable NSString *)fontName size:(CGFloat)fontSize;


/**
  If can't create font by particularly bold name, will return system bold font by given size

 @return no null font
 */
+ (NSFont *)nonullBoldFontWithName:(nullable NSString *)fontName size:(CGFloat)fontSize;

+ (NSFont *)zmSystemFontOfSize:(CGFloat)fontSize;
+ (NSFont *)zmBoldSystemFontOfSize:(CGFloat)fontSize;

+ (NSFont *)zmMonospacedDigitFontOfSize:(CGFloat)fontSize;
+ (NSFont *)zmBoldMonospacedDigitFontOfSize:(CGFloat)fontSize;

+ (NSFont *)mediumSystemFontOfSize:(CGFloat)fontSize;
+ (NSFont *)lightSystemFontOfSize:(CGFloat)fontSize;
+ (NSFont *)ultralightSystemFontOfSize:(CGFloat)fontSize;

@end
NS_ASSUME_NONNULL_END
