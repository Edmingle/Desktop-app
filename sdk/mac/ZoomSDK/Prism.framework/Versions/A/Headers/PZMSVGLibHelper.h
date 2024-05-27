//
//  ZMSVGLibHelper.h
//  SVGTools
//
//  Created by Jed Zheng on 12/12/2019.
//  Copyright © 2019 jed. All rights reserved.
//

#import <AppKit/AppKit.h>

NS_ASSUME_NONNULL_BEGIN
@class PZMSvgElement;
@interface PZMSVGLibHelper : NSObject
+ (NSImage* _Nullable)exportImageWithPath:(NSString *)path;
+ (NSImage* _Nullable)exportImageWithElement:(PZMSvgElement *)element;
+ (NSImage* _Nullable)exportImageWithElement:(PZMSvgElement *)element scale:(CGFloat)scale;
@end

@interface NSColor (Utilities)

+ (NSColor *)hexColorWithString:(NSString *)hex;

@end

NS_ASSUME_NONNULL_END
