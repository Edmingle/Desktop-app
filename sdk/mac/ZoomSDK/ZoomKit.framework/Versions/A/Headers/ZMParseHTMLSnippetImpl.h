//
//  ZMParseHTMLSnippetImpl.h
//  ZCommonUI
//
//  Created by groot.ding on 29/09/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <AppKit/AppKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMParseHTMLSnippetImpl : NSObject


+ (NSAttributedString *)parseHTMLSnippet:(nonnull NSString *)htmlString;

+ (nullable NSAttributedString *)parseHTMLSnippet:(NSString *)htmlString attachments:(nullable NSDictionary * )attachments;

@end

NS_ASSUME_NONNULL_END
