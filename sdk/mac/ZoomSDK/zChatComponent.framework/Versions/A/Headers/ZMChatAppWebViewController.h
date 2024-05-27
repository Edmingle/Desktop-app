//
//  ZMChatAppWebViewController.h
//  ChatUI
//
//  Created by Zoro.Fu on 2022/8/24.
//

#import <Cocoa/Cocoa.h>
#ifdef ENABLE_ZAPP
#import <ZoomAppUISDK/ZoomAppUISDK.h>
#endif

@class ZMChatAppShortcutInfo, ZMZappContext, ZMChatAppWebViewController;
NS_ASSUME_NONNULL_BEGIN

@protocol ZMChatAppWebViewDataSource<NSObject>

/// appType: ZMAppType defined in ZoomAppUISDK
- (void)appContextWithAppId:(NSString *)appId appType:(NSInteger)appType completeHandler:(void (^)(ZMZappContext * _Nullable context, NSError * _Nullable error))completion;

@optional
- (NSDictionary *)launchRequestHeaderForApp:(ZMZappContext *)context;

@end

@protocol ZMChatAppWebViewDelegate<NSObject>

@optional
- (void)appWebViewController:(ZMChatAppWebViewController *)vc didFinishNavigationWithURL:(NSURL *)url;
- (void)appWebViewController:(ZMChatAppWebViewController *)vc didFailedNavigationWithURL:(NSURL *)url error:(NSError *)error;
- (void)appWebViewController:(ZMChatAppWebViewController *)vc loadingStatusDidChanged:(BOOL)isLoading;
- (void)appWebViewController:(ZMChatAppWebViewController *)vc webViewDidTerminateWithReason:(NSInteger)reason;

- (void)appWebViewController:(ZMChatAppWebViewController *)vc didDestroyWebView:(NSString *)webViewId;
- (void)appWebViewController:(ZMChatAppWebViewController *)vc didCreateWebView:(NSString *)webViewId;

@end

@interface ZMChatAppWebViewController : ZMBaseViewController

@property (nonatomic, weak) id<ZMChatAppWebViewDataSource> dataSource;
@property (nonatomic, weak) id<ZMChatAppWebViewDelegate> delegate;
#ifdef ENABLE_ZAPP
@property (nonatomic, assign) ZMOpenChatAppSrc openSrc;
@property(nonatomic, strong) NSView<ZMAppWebViewInstance> *zAppWebView;
#endif
/// appType: ZMAppType defined in ZoomAppUISDK
- (instancetype)initWithChatAppId:(NSString *)appId appType:(NSInteger)appType dataSource:(id<ZMChatAppWebViewDataSource>)dataSource delegate:(id<ZMChatAppWebViewDelegate>)delegate;

#ifdef ENABLE_ZAPP
- (instancetype)initWithWebViewConfiguration:(ZMZAppWebViewConfiguration *)config dataSource:(nonnull id<ZMChatAppWebViewDataSource>)dataSource;
- (void)cleanZApp;
#endif

- (instancetype)initWithChatAppId:(NSString *)appId
                          appType:(NSInteger)appType
                    isLauncherApp:(BOOL)isLauncherApp
                       dataSource:(id<ZMChatAppWebViewDataSource>)dataSource
                         delegate:(id<ZMChatAppWebViewDelegate>)delegate;


- (void)startLoad;

- (nullable NSString *)webViewId;

@end

NS_ASSUME_NONNULL_END
