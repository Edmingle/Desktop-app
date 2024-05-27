//
//  ZMChatFilePreviewManager.h
//  zChatUI
//
//  Created by groot.ding on 3/10/20.
//  Copyright © 2020 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMChatMsgItemInfo;
@class ZMFileEntity;

const long long ZMImagePreviewMaxBit = 8 <<20;

@interface ZMChatFilePreviewManager : NSObject

@property (nonatomic,assign) BOOL shouldMouseUpOutsizeClosePreview;

@property (readonly) NSString *sessionId;

@property (readonly) NSWindow *window;

+ (instancetype)sharedInstance;

+ (void)releaseInstance;

- (void)openFilePreviewByItems:(NSArray <ZMFileEntity *> *)fileItems sessionId:(NSString *)sessionId currentIndex:(NSInteger)currentIndex  window:(nullable NSWindow *)window;

- (void)openFilePreviewByItems:(NSArray <ZMFileEntity *> *)fileItems sessionId:(NSString *)sessionId currentIndex:(NSInteger)currentIndex  window:(nullable NSWindow *)window isDockOut:(BOOL)isDockout;

- (void)openDocumentPreviewByItem:(ZMFileEntity *)fileItem sessionId:(NSString *)sessionId threadId:(NSString *)threadId window:(NSWindow *)window isDockOut:(BOOL)isDockout;

- (void)trans2DockoutWindow;

- (void)dismiss;

- (void)dismissIfInMainWindow;

- (BOOL)isShow;

- (BOOL)isDockOut;

- (BOOL)isDisplayImage;

- (void)rotateLeft;
- (void)rotateRight;
@end

NS_ASSUME_NONNULL_END
