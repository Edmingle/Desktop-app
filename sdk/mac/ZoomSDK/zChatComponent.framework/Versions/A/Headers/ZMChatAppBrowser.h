//
//  ZMChatAppBrowser.h
//  ChatUI
//
//  Created by Zoro.Fu on 2022/8/24.
//

#include <zChatApp/IZoomMessenger.h>

NS_ASSUME_NONNULL_BEGIN

#define ZMZappOpenFromMessage @"shortcutInMessage"
#define ZMZappOpenFromCompose @"shortcutInCompose"
#define ZMZappOpenFromBotMessage @"actionInBotMessage"
#define ZMZappOpenFromSlashCommand @"slashCommand"
#define ZMZappOpenFromDocumentPreview @"documentPreview"
#define ZMZappOpenFromThread @"shortcutInThread"

typedef NS_ENUM(NSUInteger, ZMChatAppCloseReason) {
    ZMChatAppClose_Default,
    ZMChatAppClose_Auto,
    ZMChatAppClose_Force
};

typedef NS_ENUM(NSUInteger, ZMChatAppShortcutSessionType) {
    ZMChatAppShortcutSession_DM = 11,
    ZMChatAppShortcutSession_Channel = 12
};

@class  ZMChatAppContext, ZMChatAppViewController;

#ifdef ENABLE_ZAPP
@class ZMZAppWebViewService;
#endif

@protocol ZMChatAppActions <NSObject>

#ifdef ENABLE_ZAPP
- (ZMZAppWebViewService *)zAppWebViewService;
#endif

- (ZMChatAppViewController *_Nullable)openApp:(ZMChatAppContext *)appContext;

@end

@protocol ZMChatAppEvent <NSObject>

//- (void)onCloseApp:(NSString * _Nullable)reason;

- (NSString *_Nullable)getZappChannelLauncherUrlWithChannelId:(NSString *)sessionId;

- (void)updateAppViewController:(ZMChatAppViewController *)vc webViewId:(NSString *)webViewId;
- (void)removeAppViewControllerWithWebViewId:(NSString *)webViewId;

@end

@protocol ZMChatAppJSEvent <NSObject>

#ifdef ENABLE_ZAPP
- (void *)zappJSRegister;
- (void *)zappServiceHelper;
#endif

- (BOOL)checkActiveAppWithAppId:(NSString *)appId webViewId:(NSString *)webViewId;

- (NSDictionary *)getChatContextWithWebViewId:(NSString *)webViewId;

- (NSString *)getChatMessageWithSessionId:(NSString *)sessionId threadId:(NSString *)threadId messageId:(NSString *)messageId;

- (void)closeModal:(NSString *)webViewId;

- (void)webView:(NSString *)webViewId editCompose:(NSString *)message action:(NSString *)action range:(NSRange)range;

- (void)webView:(NSString *)webViewId appId:(NSString *)appId appendCardToCompose:(const CAString &)previewJson;

- (void)showAppList;

- (void)webView:(NSString *)webViewId sizeDidChanged:(NSSize)size;

- (void)setConfirmationOnDiscard:(BOOL)needConfirmation;

- (void)webView:(NSString *)webViewId setCloseButtonHidden:(BOOL)isHidden;

@end

@interface ZMChatAppBrowser : NSObject

@property (class, readonly) id<ZMChatAppActions> shared;

@property (class, readonly) id<ZMChatAppEvent> eventShared;

@property (class, readonly) id<ZMChatAppJSEvent> jsEventShared;

@end

NS_ASSUME_NONNULL_END
