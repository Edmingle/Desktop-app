//
//  ZMChatAppViewController.h
//  ChatUI
//
//  Created by Zoro.Fu on 2022/8/24.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <ZoomKit/ZoomKit.h>

@class ZMChatAppContext, ZMChatAppViewController, ZMChatAppComposeMessageInfo;
NS_ASSUME_NONNULL_BEGIN

@protocol ZMChatAppDelegate <NSObject>

- (void)chatAppReceivedCloseAction:(ZMChatAppViewController *)vc;

@optional

- (void)chatApp:(ZMChatAppViewController *)vc editCompose:(ZMChatAppComposeMessageInfo *)composeInfo;
- (void)chatApp:(ZMChatAppViewController *)vc didChangeSize:(NSSize)size;

@end

@interface ZMChatAppViewController : ZMBaseViewController

@property (nonatomic, readonly) ZMChatAppContext *chatAppContext;

@property (nonatomic, readonly) NSString *chatAppId;

@property (nonatomic, weak) id<ZMChatAppDelegate> delegate;

- (instancetype)initWithChatAppContext:(ZMChatAppContext *)context;

- (void)relayoutUIAfterDockOut;

- (void)relaunchWebView;

- (void)updateWithChatAppContext:(ZMChatAppContext *)context;

- (void)setCloseButtonHidden:(BOOL)isHidden;

@end

NS_ASSUME_NONNULL_END
