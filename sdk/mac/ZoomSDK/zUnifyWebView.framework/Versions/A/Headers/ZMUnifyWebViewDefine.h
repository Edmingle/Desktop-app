//
//  ZMUnifyWebViewDefine.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/11/28.
//

#ifndef ZMUnifyWebViewDefine_h
#define ZMUnifyWebViewDefine_h

#import <WebKit/WebKit.h>

extern NSString *const kWebKitDeveloperExtrasEnabled;
extern NSString *const kWebKitCachePath;
extern NSString *const kWebKitDataPath;
extern NSString *const kBlobScheme;

typedef NS_OPTIONS(NSUInteger, ZMWebCaptureDevices) {
    ZMWebCaptureDeviceMicrophone = 1 << 0,
    ZMWebCaptureDeviceCamera = 1 << 1,
    ZMWebCaptureDeviceDisplay = 1 << 2,
};

typedef NS_ENUM(NSInteger, ZMWebDisplayCapturePermissionDecision) {
    ZMWebDisplayCapturePermissionDecisionDeny,
    ZMWebDisplayCapturePermissionDecisionScreenPrompt,
    ZMWebDisplayCapturePermissionDecisionWindowPrompt,
};

typedef NS_ENUM(NSInteger, ZMWebProcessTerminationReason) {
    ZMWebProcessTerminationReasonUnknown = -1,
    ZMWebProcessTerminationReasonExceededMemoryLimit,
    ZMWebProcessTerminationReasonExceededCPULimit,
    ZMWebProcessTerminationReasonRequestedByClient,
    ZMWebProcessTerminationReasonCrash,
};

typedef NS_ENUM(NSInteger, ZMUnifyWebViewModule) {
    ZMUnifyWebViewModule_Default = -1,
    ZMUnifyWebViewModule_Apps = 0,
    ZMUnifyWebViewModule_CCI,
    ZMUnifyWebViewModule_Mail,
    ZMUnifyWebViewModule_Simulive,
    ZMUnifyWebViewModule_Clips,
    ZMUnifyWebViewModule_Whiteboard,
    ZMUnifyWebViewModule_Calendar,
    ZMUnifyWebViewModule_Doc,
    ZMUnifyWebViewModule_Notes,
    ZMUnifyWebViewModule_Space,
    ZMUnifyWebViewModule_WorkFlow,
    ZMUnifyWebViewModule_Hub,
};

typedef NS_ENUM(NSInteger, ZMContextMenuItemTag) {
    kZMContextMenuItemTagNoAction = 0,
    kZMContextMenuItemTagOpenLinkInNewWindow,
    kZMContextMenuItemTagDownloadLinkToDisk,
    kZMContextMenuItemTagCopyLinkToClipboard,
    kZMContextMenuItemTagOpenImageInNewWindow,
    kZMContextMenuItemTagDownloadImageToDisk,
    kZMContextMenuItemTagCopyImageToClipboard,
    kZMContextMenuItemTagOpenFrameInNewWindow,
    kZMContextMenuItemTagCopy,
    kZMContextMenuItemTagGoBack,
    kZMContextMenuItemTagGoForward,
    kZMContextMenuItemTagStop,
    kZMContextMenuItemTagReload,
    kZMContextMenuItemTagCut,
    kZMContextMenuItemTagPaste,
    kZMContextMenuItemTagSpellingGuess,
    kZMContextMenuItemTagNoGuessesFound,
    kZMContextMenuItemTagIgnoreSpelling,
    kZMContextMenuItemTagLearnSpelling,
    kZMContextMenuItemTagOther,
    kZMContextMenuItemTagSearchInSpotlight,
    kZMContextMenuItemTagSearchWeb,
    kZMContextMenuItemTagLookUpInDictionary,
    kZMContextMenuItemTagOpenWithDefaultApplication,
    kZMContextMenuItemTagPDFActualSize,
    kZMContextMenuItemTagPDFZoomIn,
    kZMContextMenuItemTagPDFZoomOut,
    kZMContextMenuItemTagPDFAutoSize,
    kZMContextMenuItemTagPDFSinglePage,
    kZMContextMenuItemTagPDFFacingPages,
    kZMContextMenuItemTagPDFContinuous,
    kZMContextMenuItemTagPDFNextPage,
    kZMContextMenuItemTagPDFPreviousPage,
    kZMContextMenuItemTagOpenLink,
    kZMContextMenuItemTagIgnoreGrammar,
    kZMContextMenuItemTagSpellingMenu,
    kZMContextMenuItemTagShowSpellingPanel,
    kZMContextMenuItemTagCheckSpelling,
    kZMContextMenuItemTagCheckSpellingWhileTyping,
    kZMContextMenuItemTagCheckGrammarWithSpelling,
    kZMContextMenuItemTagFontMenu,
    kZMContextMenuItemTagShowFonts,
    kZMContextMenuItemTagBold,
    kZMContextMenuItemTagItalic,
    kZMContextMenuItemTagUnderline,
    kZMContextMenuItemTagOutline,
    kZMContextMenuItemTagStyles,
    kZMContextMenuItemTagShowColors,
    kZMContextMenuItemTagSpeechMenu,
    kZMContextMenuItemTagStartSpeaking,
    kZMContextMenuItemTagStopSpeaking,
    kZMContextMenuItemTagWritingDirectionMenu,
    kZMContextMenuItemTagDefaultDirection,
    kZMContextMenuItemTagLeftToRight,
    kZMContextMenuItemTagRightToLeft,
    kZMContextMenuItemTagPDFSinglePageScrolling,
    kZMContextMenuItemTagPDFFacingPagesScrolling,
    kZMContextMenuItemTagInspectElement,
    kZMContextMenuItemTagTextDirectionMenu,
    kZMContextMenuItemTagTextDirectionDefault,
    kZMContextMenuItemTagTextDirectionLeftToRight,
    kZMContextMenuItemTagTextDirectionRightToLeft,
    kZMContextMenuItemTagCorrectSpellingAutomatically,
    kZMContextMenuItemTagSubstitutionsMenu,
    kZMContextMenuItemTagShowSubstitutions,
    kZMContextMenuItemTagSmartCopyPaste,
    kZMContextMenuItemTagSmartQuotes,
    kZMContextMenuItemTagSmartDashes,
    kZMContextMenuItemTagSmartLinks,
    kZMContextMenuItemTagTextReplacement,
    kZMContextMenuItemTagTransformationsMenu,
    kZMContextMenuItemTagMakeUpperCase,
    kZMContextMenuItemTagMakeLowerCase,
    kZMContextMenuItemTagCapitalize,
    kZMContextMenuItemTagChangeBack,
    kZMContextMenuItemTagOpenMediaInNewWindow,
    kZMContextMenuItemTagDownloadMediaToDisk,
    kZMContextMenuItemTagCopyMediaLinkToClipboard,
    kZMContextMenuItemTagToggleMediaControls,
    kZMContextMenuItemTagToggleMediaLoop,
    kZMContextMenuItemTagEnterVideoFullscreen,
    kZMContextMenuItemTagMediaPlayPause,
    kZMContextMenuItemTagMediaMute,
    kZMContextMenuItemTagDictationAlternative,
    kZMContextMenuItemTagPlayAllAnimations,
    kZMContextMenuItemTagPauseAllAnimations,
    kZMContextMenuItemTagPlayAnimation,
    kZMContextMenuItemTagPauseAnimation,
    kZMContextMenuItemTagCopyImageUrlToClipboard,
    kZMContextMenuItemTagSelectAll,
    kZMContextMenuItemTagOpenLinkInThisWindow,
    kZMContextMenuItemTagToggleVideoFullscreen,
    kZMContextMenuItemTagShareMenu,
    kZMContextMenuItemTagToggleVideoEnhancedFullscreen,
    kZMContextMenuItemTagAddHighlightToCurrentQuickNote,
    kZMContextMenuItemTagAddHighlightToNewQuickNote,
    kZMContextMenuItemTagRevealImage,
    kZMContextMenuItemTagTranslate,
    kZMContextMenuItemTagCopyCroppedImage,
    kZMContextMenuItemBaseApplicationTag = 10000,
};

API_AVAILABLE(macos(10.11))
@interface WKWebsiteDataStore (UnifyWebView)
- (void)clearWebCache:(void (^)(void))completionHandler;
@end

@protocol ZMUnifyWebViewURLSchemeHandlerProtocol <NSObject>

- (id<WKURLSchemeHandler>)urlSchemeHandler;
- (NSString *)urlSchemeName;

@end

/// UnifyWebViewConfiguration
/// asyncClipboardEnabled  Default YES;
/// mediaDevicesEnabled Default YES;
@interface ZMUnifyWebViewConfiguration : NSObject

@property (nonatomic, assign) ZMUnifyWebViewModule moduleType;
@property (nonatomic, copy) NSString *processDisplayName;
@property (nonatomic, assign) BOOL asyncClipboardEnabled;
@property (nonatomic, assign) BOOL fullScreenEnabled;
@property (nonatomic, assign) BOOL mediaDevicesEnabled;
@property (nonatomic, assign) BOOL tabFocusesLinksEnabled;
@property (nonatomic, assign) BOOL checkJSMessageEnabled;
@property (nonatomic, strong) WKWebsiteDataStore *websiteDataStore;
@property (nonatomic, strong) NSArray<id<ZMUnifyWebViewURLSchemeHandlerProtocol>> *handlerArray;

- (NSString *)dataStoreIdentity;

@end

#endif /* ZMUnifyWebViewDefine_h */
