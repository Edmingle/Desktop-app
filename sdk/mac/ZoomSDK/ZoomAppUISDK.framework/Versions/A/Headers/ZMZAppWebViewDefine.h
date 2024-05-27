//
//  ZMZAppWebViewDefine.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/12/4.
//

#ifndef ZMZAppWebViewDefine_h
#define ZMZAppWebViewDefine_h
#import <ZoomUnit/ZoomUnit.h>
#import <ZoomUnit/ZPZAppAdapter.h>
#import <zUnifyWebView/ZMUnifyWebViewProtocol.h>
#import <zUnifyWebView/ZMUnifyWebViewDefine.h>
#import <zUnifyWebView/ZMUnifyWebView.h>

extern NSUInteger const MAX_JS_PARAM_LENGTH; // ZOOM-273773
extern NSString *const kWebScriptHandlerName;
extern NSString *const kWebKitCookieSharedFolderPrefix;
extern NSString *const kWebKitCookiePTFolderPrefix;
extern NSString *const kWebKitCookieConfFolderPrefix;
extern NSString *const kWebKitCookieChatAppFolderPrefix;
extern NSString *const kWebKitCookiePhoneFolderPrefix;
extern NSString *const kWebKitCookieLabsFolderPrefix;
extern NSString *const kCallbackMethod;
extern NSString *const kCallbackKeyData;
extern NSString *const kWebViewEmptyURL;
extern NSString *const kWebViewSrcDocURL;
extern NSString *const kWebViewErrorURL;
extern NSString *const kErrorLog;
extern NSString *const kCSPErrorLog;
extern NSString *const kNavErrorLog;
extern NSString *const kConfIdSchemePrefix;

#define NSStringMultiline(...) [[NSString alloc] initWithCString:#__VA_ARGS__ encoding:NSUTF8StringEncoding]
#define CustomAppOnGetContextError ZM_GET_NSERROR(@"kAppOnGetContextError", 0, @"App context is invalid")
#define CustomAppOnDomainCheckError ZM_GET_NSERROR(@"kAppOnDomainCheckError", 0, @"App On Domain Check Error")

@protocol ZMAppWebViewInstance <ZMUnifyWebViewInstance>

/// Get the home URL string of a webView, the home URL which means loaded from the `loadURL:withRequestHeaders:` method
- (NSString *)getHomeURLStr;

/// Get the configed content size of self
- (NSSize)getUnifyWebConfiguredSize;

/// Get the appId related with self
- (NSString *)getInstanceAppId;

/// Modify appType
/// - Parameter appType: new appType
- (void)transitToNewAppType:(NSInteger)appType;

/// Get the app location with self
- (ZMAppLocation)getAppLocation;
@end

typedef NS_ENUM(NSInteger, ZMOpenChatAppSrc) {
    ZMOpenChatAppByDefault = 0,
    ZMOpenChatAppByShortcutInMessage,
    ZMOpenChatAppByShortcutInCompose,
    ZMOpenChatAppByActionInBotMessage,
    ZMOpenChatAppBySlashCommand,
    ZMOpenChatAppByDocumentPreview,
    ZMOpenChatAppByShortcutInThread,
};

@class ZMRegisterJSApiParam;
@protocol ZMAppJSHandlerProtocol <NSObject>
- (void)onRegisterJSApiCalledWithReqId:(NSString *)reqId apiParam:(ZMRegisterJSApiParam *)params;
@end

typedef NS_ENUM(NSInteger, ZMAppMessageFunction) {
    ZMAppMessageFunction_None = 0,
    ZMAppMessageFunction_UploadDumpFile = 1,
    ZMAppMessageFunction_OpenApp = 2,
    ZMAppMessageFunction_CloseApp = 3,
    ZMAppMessageFunction_BulletReady = 4,
    ZMAppMessageFunction_MousePenetrate = 5,
    ZMAppMessageFunction_JumpMessage = 6,
};

typedef NS_ENUM(NSInteger, ZMAppMessageEvent) {
    ZMAppMessageEvent_None = 0,
    ZMAppMessageEvent_OnDumpFileUploaded = 1,
    ZMAppMessageEvent_RecieveMessageFromOtherApp = 2,
    ZMAppMessageEvent_OpenApp = 3,
    ZMAppMessageEvent_CloseApp = 4,
};

@protocol ZMAppMessageHandlerProtocol <NSObject>
- (void)onAppMessageRecevied:(NSString *)jscallId funcName:(ZMAppMessageFunction)funcName argsJason:(NSString *)args webViewId:(NSString *)webViewId;
@end

@interface ZMRegisterJSApiParam : NSObject

@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *currentURL;
@property (nonatomic, copy) NSString *webViewId;
@property (nonatomic, assign) ZMAppType appType;
@property (nonatomic, copy) NSString *jsCallId;
@property (nonatomic, copy) NSString *moduleName;
@property (nonatomic, copy) NSString *funcName;
@property (nonatomic, copy) NSString *argsJson;
@property (nonatomic, assign) BOOL isAppConnectedAfterMeeting;
@property (nonatomic, assign) BOOL bPopup;
@end

@interface ZMRegisterJSApiResult : NSObject

@property (nonatomic, assign) NSInteger errorCode;
@property (nonatomic, copy) NSString *resultData;
@property (nonatomic, copy) NSString *errorMsg;

@end

@interface ZMZAppWebViewConfiguration : ZMUnifyWebViewConfiguration

@property (nonatomic, assign) ZMAppType appType;
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, assign) BOOL sharedStorage;
@property (nonatomic, assign) BOOL isLauncherApp;
@property (nonatomic, assign) BOOL usedForAuthorize;
@property (nonatomic, assign) ZMAppLocation appLocation;

- (BOOL)isSameDataStoreIdentify:(ZMZAppWebViewConfiguration *)config;

- (BOOL)isZoomApps;
- (BOOL)isThirdPartApps;
- (BOOL)isInternalApps;
- (BOOL)isSideCar;
- (BOOL)isOnZoom;
- (BOOL)isVCard;
- (BOOL)isActivivtyCenter;
- (BOOL)isSearchApp;
- (BOOL)isSpotsApp;

@end

@interface ZMAppContextParam : NSObject
@property (nonatomic, copy) NSString *targetURL;
@property (nonatomic, copy) NSString *meetingNumber;
@property (nonatomic, assign) ZAppOpenAppPurpose openPurpose;
@property (nonatomic, assign) ZMOpenChatAppSrc openSrc;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *sessionId;
@property (nonatomic, copy) NSString *messageId;
@property (nonatomic, copy) NSString *threadId;
@property (nonatomic, copy) NSString *actionId;
@property (nonatomic, assign) BOOL isInternalApp;
@property (nonatomic, copy) NSString *allowedDomainListStr;
@property (nonatomic, assign) NSInteger featureOptions;
@property (nonatomic, copy) NSString *smsSessionInfo;
@property (nonatomic, copy) NSString *appResourceHashRoute;
@property (nonatomic, copy) NSString *ccQueueId;
@end

#endif /* ZMZAppWebViewDefine_h */
