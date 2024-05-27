//
//  ZMUnifyWebViewProtocol.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/11/28.
//

#import <Foundation/Foundation.h>
#import "ZMUnifyWebViewDefine.h"
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMUnifyWebViewInstance;

@protocol ZMUnifyWebViewHelper <NSObject>

@optional
- (BOOL)isJSCallSrcURLInvalid:(NSURL *)srcURL;
- (void)showEmojiWindow:(BOOL)show rect:(NSRect)rect positionView:(NSView *)view type:(NSString *)type;
- (NSString *)languageCode;

@end

@protocol ZMUnifyWebViewInstanceDelegate <NSObject>

@optional

/// Invoked when call `window.close()`
/// - Parameter instance: unifyWebView
- (void)unifyWebViewDidClose:(id<ZMUnifyWebViewInstance>)instance;

/// unifyWebView did decide Policy, will be invoked when the WKWebView in the webView container invoke the `unifyWebView:decidePolicyForNavigationAction:`
/// - Parameters:
///   - instance: unifyWebView
///   - url: url the navigation URL
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance decidePolicyForNavigationAction:(NSURL *)url;

/// unifyWebView decide policy for navigation action, will be invoked when the WKWebView in the webView container invoke the `unifyWebView:decidePolicyForNavigationAction:decisionHandler:`
/// - Parameters:
///   - instance: unifyWebView
///   - navigationAction: navigationAction object
///   - decisionHandler: completion handler
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance
decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction
                decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler API_AVAILABLE(macos(10.10));

- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance
getContextMenuFromProposedMenu:(NSMenu *)menu
                    forElement:(id)element
                      userInfo:(id<NSSecureCoding>)userInfo
             completionHandler:(void (^)(NSMenu *))completionHandler;
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance
decidePolicyForNavigationResponse:(WKNavigationResponse *)navigationResponse
                  decisionHandler:(void (^)(WKNavigationResponsePolicy))decisionHandler;

/// unifyWebView did start navigation, will be invoked when the WKWebView in the unifyWebView container invoke the `unifyWebView:didStartProvisionalNavigation:`
/// - Parameters:
///   - instance: unifyWebView
///   - url: the navigation URL
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance didStartNavigationWithURL:(NSURL *)url;

/// unifyWebView did commit navigation, will be invoked when the WKWebView in the webView container invoke the `unifyWebView:didCommitNavigation:`
/// - Parameters:
///   - instance: unifyWebView
///   - url: the navigation URL
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance didCommitNavigationWithURL:(NSURL *)url;

/// unifyWebView did finish navigation, will be invoked when the WKWebView in the unifyWebView container invoke the `unifyWebView:didFinishNavigation:`
/// - Parameters:
///   - instance: unifyWebView
///   - url: the navigation URL
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance didFinishNavigationWithURL:(NSURL *)url;

/// unifyWebView did failed navigation, will be invoked when the WKWebView in the unifyWebView container invoke the `unifyWebView:didFailNavigation:withError:` and `unifyWebView:didFailProvisionalNavigation:withError:`
/// - Parameters:
///   - instance: unifyWebView
///   - url: the navigation URL
///   - error: the navigation failed error
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance didFailedNavigationWithURL:(NSURL *)url Error:(NSError *)error;

/// unifyWebView content process did terminate, will be invoked when the WKWebView in the unifyWebView container invoke the `_webView:webContentProcessDidTerminateWithReason:` or `webViewWebContentProcessDidTerminate`, for OS version before macOS 10.14,
/// - Parameters:
///   - instance: unifyWebView
///   - reason: the error code describe the reason
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance webContentProcessDidTerminateWithReason:(ZMWebProcessTerminationReason)reason;

/// unifyWebView rendering progress did change, will be invoked when the WKWebView in the unifyWebView container invoke the `_webView:renderingProgressDidChange:` which is a private method defined in `WKNavigtionDelegatePrivate`
/// - Parameters:
///   - instance: unifyWebView
///   - progressEvents: the rendering progress which is defined in `_WKRenderingProgressEvents.h` of the `WebKit`
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance renderingProgressDidChange:(NSUInteger)progressEvents;

/// unifyWebView request media authorization for devices, will be invoked when the WKWebView in the unifyWebView container invoke the `_webView:requestUserMediaAuthorizationForDevices:url:mainFrameURL:decisionHandler:` which is a private method defined in `WKUIDelegatePrivate`
/// - Parameters:
///   - instance: unifyWebView
///   - devices: microphone, camera or display
///   - url: the current URL
///   - mainFrameURL: the URL of main frame
///   - decisionHandler: the decisionHandler
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance
requestUserMediaAuthorizationForDevices:(NSUInteger)devices
                                    url:(NSURL *)url
                           mainFrameURL:(NSURL *)mainFrameURL
                        decisionHandler:(void (^)(BOOL authorized))decisionHandler;

/// unifyWebView check user media Permission for URL, will be invoked when the WKWebView in the unifyWebView container invoke the `_webView:checkUserMediaPermissionForURL:mainFrameURL: frameIdentifier:decisionHandler:` which is a private method defined in `WKUIDelegatePrivate`
/// - Parameters:
///   - instance: unifyWebView
///   - url: the current URL
///   - mainFrameURL: the URL of main frame
///   - frameIdentifier: the identity of frame
///   - decisionHandler: the decisionHandler
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance
checkUserMediaPermissionForURL:(NSURL *)url
                  mainFrameURL:(NSURL *)mainFrameURL
               frameIdentifier:(NSUInteger)frameIdentifier
               decisionHandler:(void (^)(NSString *salt, BOOL authorized))decisionHandler;
- (void)webViewDidReceiveForceRefreshEvent:(id<ZMUnifyWebViewInstance>)instance;

/// unifyWebView loading status changed, will be invoked when the keyPath `loading` of the WKWebView in the unifyWebView container changed
/// - Parameters:
///   - instance: unifyWebView
///   - isLoading: the webView is loading or not
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance loadingStatusDidChanged:(BOOL)isLoading;

/// unifyWebView URL changed, will be invoked when the keyPath `URL` of the WKWebView in the unifyWebView container changed
/// - Parameters:
///   - instance: unifyWebView
///   - oldURL: the oldURL of the webView
///   - newURL: the newURL of the webView
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance urlDidChanged:(NSURL *)oldURL newURL:(NSURL *)newURL;

- (BOOL)unifyWebView:(id<ZMUnifyWebViewInstance>)instance shouldIgnoreScriptMessage:(WKScriptMessage *)message;

- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance didReceiveCustomScriptMessage:(WKScriptMessage *)message;

- (BOOL)shouldRefreshHeader:(id<ZMUnifyWebViewInstance>)instance;

/// Whether to set download delegate
/// - Parameter instance: unifyWebView
- (BOOL)canPreformDownload:(id<ZMUnifyWebViewInstance>)instance;

/// unifyWebView check whether allow download file with a filename
/// - Parameters:
///   - instance: unifyWebView
///   - download: download object, WKDownload on macOS 11.3 and above, _WKDownload on macOS before 11.3
///   - fileName: file suggested name
- (BOOL)unifyWebView:(id<ZMUnifyWebViewInstance>)instance shouldAllowDownload:(id)download withFileName:(NSString *)fileName;

/// unifyWebView destination folder for download
/// - Parameters:
///   - instance: unifyWebView
///   - download: download object, WKDownload on macOS 11.3 and above, _WKDownload on macOS before 11.3
///   - completionHandler: callback block with expected folder path
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance decideDestinationForDownload:(id)download comletionHandler:(void (^)(NSURL *destinationFolder))completionHandler;

/// Invoked when click the reload in WebView Context Menu
/// - Parameter instance: unifyWebView
- (void)webViewDidClickReloadItemInContextMenu:(id<ZMUnifyWebViewInstance>)instance;

/// unifyWebView check user media Permission for URL on macOS 13.0 and above, will be invoked when the WKWebView in the unifyWebView container invoke the `_webView: requestDisplayCapturePermissionForOrigin:initiatedByFrame:withSystemAudio:decisionHandler:` which is a private method defined in `WKUIDelegatePrivate`
/// - Parameters:
///   - instance: unifyWebView
///   - securityOrigin: origin of this permission request
///   - frame: frame info
///   - withSystemAudio: whether share with audio
///   - decisionHandler: the decisionHandler
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance requestDisplayCapturePermissionForOrigin:(WKSecurityOrigin *)securityOrigin initiatedByFrame:(WKFrameInfo *)frame withSystemAudio:(BOOL)withSystemAudio decisionHandler:(void (^)(ZMWebDisplayCapturePermissionDecision decision))decisionHandler;

/// unifyWebView dragged by mouse event, will be invoked when drag the unifyWebView
/// - Parameters:
///   - instance: unifyWebView
///   - event: the mouse drag event
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance onMouseDraggedEvent:(NSEvent *)event;

/// Mouse event entered into unifyWebView,  will be invoked when enter to the unifyWebView
/// - Parameters:
///   - instance: unifyWebView
///   - event: the mouse enter event
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance onMouseEnterEvent:(NSEvent *)event;

/// Mouse event exited out of unifyWebView,  will be invoked when exit out of unifyWebView
/// - Parameters:
///   - instance: unifyWebView
///   - event: the mouse exited event
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance onMouseExitedEvent:(NSEvent *)event;

/// Mouse event moved in unifyWebView,  will be invoked when move in the unifyWebView
/// - Parameters:
///   - instance: unifyWebView
///   - event: the mouse moved event
- (void)unifyWebView:(id<ZMUnifyWebViewInstance>)instance onMouseMovedEvent:(NSEvent *)event;

/// Mouse event up in unifyWebView,  will be invoked when click in the unifyWebView
/// - Parameters:
///   - instance: unifyWebView
///   - event: the mouse up event
- (BOOL)unifyWebView:(id<ZMUnifyWebViewInstance>)instance onMouseUpEvent:(NSEvent *)event;

/// Customize cursor style in unifyWebView
/// - Parameter instance: unifyWebView
- (void)resetCursorRects:(id<ZMUnifyWebViewInstance>)instance;

///  should unifywebview's decidePolicyForNavigationResponse skip owasp check
/// - Parameters:
///   - instance: unifyWebView
///   - srcURL: url
- (BOOL)unifyWebView:(id<ZMUnifyWebViewInstance>)instance shouldSkipOWASPCheck:(NSURL *)srcURL;

- (id<ZMUnifyWebViewInstance>)unifyWebView:(id<ZMUnifyWebViewInstance>)instance createWebViewWithConfiguration:(WKWebViewConfiguration *)configuration forNavigationAction:(WKNavigationAction *)navigationAction windowFeatures:(WKWindowFeatures *)windowFeatures;

@end

@protocol ZMUnifyWebViewInstance <NSObject>


/// Set the implementation object of the ZMUnifyWebViewInstanceDelegate protocol
/// - Parameter delegate: the implementation object of the ZMUnifyWebViewInstanceDelegate protocol
- (void)configDelegate:(id<ZMUnifyWebViewInstanceDelegate>)delegate;

/// Load a specific URL string for self with optional request headers
/// - Parameters:
///   - urlStr: url string to be loaded
///   - headers: headers you may add in the HTTP request
- (void)loadURL:(NSString *)urlStr withRequestHeaders:(nullable NSDictionary *)headers;

/// Load file url for self
/// - Parameters:
///   - fileString: file path string
///   - folderString: folder path string
- (void)loadFileURL:(NSString *)fileString folderPath:(NSString *)folderString;

/// Inject javascript for self
/// - Parameters:
///   - javaScriptString: javaScriptString to be injected
///   - mainFrameOnly: main frame only or both main frame and iframes
- (void)injectJavaScript:(NSString *)javaScriptString mainFrameOnly:(BOOL)mainFrameOnly;

/// Run a javascript string in self
/// - Parameters:
///   - javaScriptString: javascript string
///   - completionHandler:  the completionHandler which contains the javascript result or the error
- (void)runJavaScript:(NSString *)javaScriptString completionHandler:(void (^)(id, NSError *error))completionHandler;

/// Get the current URL string of self
- (NSString *)currentURLStr;

/// Get the webviewID string of self
- (NSString *)webViewInstanceID;

/// set a specific cookie for self
/// - Parameters:
///   - cookie: the cookie object to be setted
///   - completionHandler: completion handler
- (void)configCookie:(NSHTTPCookie *)cookie completionHandler:(nullable void (^)(void))completionHandler;

/// Get cookies from a unifyWebView's webSiteDataStore, this is for OnZoom only and available macOS 10.13 and above
/// - Parameter completionHandler: completion handler
- (void)getAllCookies:(void (^)(NSArray<NSHTTPCookie *> *))completionHandler;

/// delete a specific cookie for self
/// - Parameters:
///   - cookie: the cookie object to be delete
///   - completionHandler: completion handler
- (void)deleteCookie:(NSHTTPCookie *)cookie completionHandler:(void (^)(void))completionHandler;

/// Set customUserAgent
/// - Parameter customUserAgent: new value for customUserAgent
- (void)configCustomUserAgent:(NSString *)customUserAgent;

/// Get userAgent
- (NSString *)getUserAgentStr;

/// Whether to set the background color
/// - Parameter drawsBackground: Whether to set the background color
- (void)enableDrawsBackground:(BOOL)drawsBackground;

/// Set the background color for self
/// - Parameter color: background color to be set
- (void)configBackgroundColor:(NSColor *)color;

/// reload the WebView
- (void)reloadWebView;

/// Get the last loaded failed URL of self, used for refresh only
- (NSString *)getRefreshURLStr;

/// Get the webView loading status
- (BOOL)getWebViewLoadingStatus;

/// Stop audio/video play for self
/// - Parameter completeHandler: completionHandler with the media stop script running result
- (void)stopMediaPlay:(void (^)(id, NSError *))completeHandler;

/// Stop the loading process of self
- (void)stopLoadingWebView;

/// Whether to allow setting transparent background
/// - Parameter enabled: Whether to allow setting transparent background
- (void)enableDrawsTransparentBackground:(BOOL)enabled;

/// inject service worker script for unifyWebView
- (void)injectServiceWorkerScriptForUnifyWebView;

/// inject common script for unifyWebView
- (void)injectCommonScriptForUnifyWebView;

/// remove all user's script
- (void)removeAllUserScript;

/// Whether to allow checking for spelling errors
/// - Parameter enable: Whether to allow checking for spelling errors
- (void)setSpellCheckEnable:(BOOL)enable;

/// clear unifywebview cache
/// - Parameter completionHandler: completion handler
- (void)clearUnifyWebCache:(void (^)(void))completionHandler;

/// Disable disable timer throttling for self when working in background
/// - Parameter enabled: enable will make timer throttling for self working in background, default YES
- (void)setTimersThrottlingEnabled:(BOOL)enabled;

/// Check whether a webView has sound
/// - Parameter completeHandler: completionHandler with the check sound script running result
- (void)checkHasSound:(void (^)(BOOL, NSError *))completeHandler;

/// Set the `magnification` of  self
/// - Parameter magnification: the magbification value
- (void)configMagnification:(CGFloat)magnification;

/// Get the content size of self
/// - Parameter completeHandler: completionHandler with the get content size script running result
- (void)getHTMLContentSize:(void (^)(id, NSError *))completeHandler;

/// get unifywebview datastore identity
- (NSString *)getUnifyDataStoreIdentity;

/// Take a snapshot for self available >= 10.13
/// - Parameters:
///   - snapshotWidth: the width of the snapshot want to be set
///   - completionHandler:  completionHandler after the snapshot of webview be done
- (void)takeSnapshot:(CGFloat)snapshotWidth completionHandler:(void (^)(NSImage *snapshotImage, NSError *error))completionHandler;

///  get unifywebview title
- (NSString *)getUnifyTitleStr;

// For Content Rules
- (void)setAllowDomainList:(NSArray<NSString *> *)allowedDomains customSchemes:(NSArray<NSString *>*)customSchemes completeHandler:(void (^)(void))completeHandler;
- (void)setLocalHostFilterDomain:(NSArray<NSString *>  *)localAllowedDomains  customSchemes:(NSArray<NSString *>*)customSchemes completeHandler:(void (^)(void))completeHandler;
- (void)removeAllContentRuleList:(void (^)(void))completeHandler;
- (void)addContentRuleList:(WKContentRuleList *)contentList completeHandler:(void (^)(void))completeHandler API_AVAILABLE(macos(10.13));

// For Custom Handler
- (void)addScriptMessageHandler:(id<WKScriptMessageHandler>)scriptMessageHandler name:(NSString *)name;
- (void)removeScriptMessageHandler:(NSString *)name;

- (BOOL)receiveCommonScriptMessage:(NSString *)scirptMessage;

- (NSView *)getContainerViewElement;
- (BOOL)isJSCallSrcURLInvalid:(NSURL *)srcURL;

@end

NS_ASSUME_NONNULL_END
