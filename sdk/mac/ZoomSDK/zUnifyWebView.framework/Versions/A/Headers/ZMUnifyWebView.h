//
//  ZMUnifyWebView.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/11/28.
//

#import <WebKit/WebKit.h>
#import "ZMUnifyWebViewProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZMUnifyWebView : WKWebView <ZMUnifyWebViewInstance>

@property (nonatomic, weak) id<ZMUnifyWebViewInstanceDelegate> unifyDelegate;
@property (nonatomic, readonly) NSString *webViewID;
@property (nonatomic, strong) ZMUnifyWebViewConfiguration *unifyConfig;

+ (instancetype)unifyWebViewWithConfig:(ZMUnifyWebViewConfiguration *)config;
+ (WKWebViewConfiguration *)wkConfigurationWith:(ZMUnifyWebViewConfiguration *)unifyConfig;

- (void)prepareForUnifyWebView;
- (void)prepareForDestroy;
- (void)userContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message;
- (BOOL)isJSCallSrcURLInvalid:(NSURL *)srcURL;

@end

NS_ASSUME_NONNULL_END
