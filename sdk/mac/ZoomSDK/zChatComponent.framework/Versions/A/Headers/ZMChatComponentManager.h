//
//  ZMChatComponentManager.h
//  zChatComponent
//
//  Created by groot.ding on 7/27/23.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMLoginProtocol.h>

NS_ASSUME_NONNULL_BEGIN


@interface ZMChatComponentManager : NSObject <ZMLoginProtocol>

+ (ZMChatComponentManager*)shareInstance;

- (BOOL)isLogin;

- (void)setLastManualInputHeight:(CGFloat)height sessionId:(NSString *)sessionId;

- (CGFloat)getLastManualInputHeightBySessionId:(NSString *)sessionId;

@end

NS_ASSUME_NONNULL_END
