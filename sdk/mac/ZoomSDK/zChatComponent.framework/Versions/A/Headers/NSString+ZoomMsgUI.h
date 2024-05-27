//
//  NSString+ZoomMsgUI.h
//  ZoomMsgUI
//
//  Created by Groot Ding on 2022/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ZoomMsgUI)

- (NSString *)replaceTWFlagEmojiIfNeed;

- (NSString *)rectifyInvaildCharInFileName;

- (BOOL)checkFileNameBlock;

- (BOOL)isDeeplink;

@end

@interface NSMutableString (ZoomMsgUI)
- (void)mutableReplaceTWFlagEmojiIfNeeded;
@end

NS_ASSUME_NONNULL_END
