//
//  ZMChatAppsEntity.h
//  zChatComponent
//
//  Created by Yong Zhou on 8/29/22.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ZMAPPShortcutSourceType) {
    ZMAPPShortcutSourceType_InputBox = 0,
    ZMAPPShortcutSourceType_Message,
    ZMAPPShortcutSourceType_BotMessage,
    ZMAPPShortcutSourceType_Webhook,
    ZMAPPShortcutSourceType_Launcher,
    ZMAPPShortcutSourceType_DocumentPreview,
    ZMAPPShortcutSourceType_Thread,
};

typedef NS_ENUM(NSUInteger, ZMAPPShortcutGroupType) {
    ZMAPPShortcutGroupTypeNonSystem = 0,
    ZMAPPShortcutGroupTypeSystem = 1,
};

typedef NS_ENUM(NSUInteger, ZMChatSessionType)
{
    ZMChatSessionType_None = 0,
    ZMChatSessionType_1V1,
    ZMChatSessionType_Group, /* Channel, MUC */
    ZMSMSSessionType_1V1,
    ZMSMSSessionType_Group,
};

typedef NS_ENUM(NSUInteger, ZMAppLayoutType)
{
    ZMAppLayoutType_None = 0,
    ZMAppLayoutType_DocumentView,
    ZMAppLayoutType_DocumentView_PopOut,
};

typedef NS_ENUM(NSUInteger, ZMChatAppMessageEditAction)
{
    ZMChatAppMessageEditAction_None = 0,
    ZMChatAppMessageEditAction_Replace,
    ZMChatAppMessageEditAction_Append,
    ZMChatAppMessageEditAction_Insert,
};

typedef NS_ENUM(NSUInteger, ZMChatAppWebViewPosition) {
    ZMChatAppWebViewPositionDefault = 0,
    ZMChatAppWebViewPositionAboveInputBox,
    ZMChatAppWebViewPositionFollowMessage,
};

typedef NS_ENUM(NSUInteger, ZMChatAppTitleIcon) {
    ZMChatAppTitleIconNone = 0,
    ZMChatAppTitleIconFreeTrial,
};

NS_ASSUME_NONNULL_BEGIN

static NSString* const kAppCardInfo  = @"kAppCardInfo";
static NSString* const kDefaultAPPAXDesc  = @"App Card";

static NSString* const ZMChatAppShortcutAction_Dialog = @"dialog";
static NSString* const ZMChatAppShortcutAction_Command = @"command";
static NSString* const ZMChatAppShortcutAction_Tab = @"tab";
static NSString* const ZMChatAppShortcutAction_URL = @"url";

@class NSImage;

@interface ZMChatAppShortcutInfo : NSObject
/* The action from InputBox or Message menu */
@property (nonatomic, assign) ZMAPPShortcutSourceType sourceType;
@property (nonatomic, assign) ZMAPPShortcutGroupType groupType;
/* sessionID,messageID,threadID, locate which message the shortcut action is related */

@property (nonatomic, assign) ZMAppLayoutType layoutType;

@property (nonatomic, copy) NSString *messageHash; // message_hash
@property (nonatomic, copy) NSString *asyncID;     // bot_message_id

@property (nonatomic, copy) NSString *actionID;
@property (nonatomic, copy) NSString *zmAppID;
@property (nonatomic, copy) NSString *robotName;
@property (nonatomic, copy) NSString *robotJID;
/* shortcut name */
@property (nonatomic, copy) NSString *label;
@property (nonatomic, copy) NSString *icon;
@property (nonatomic, copy) NSString *iconPath;
/* the link to open a popup webview */
@property (nonatomic, copy) NSString *link;
/* the title of popup webview */
@property (nonatomic, copy) NSString *title;
/* hide the title of popup webview */
@property (nonatomic, assign) BOOL isHideTitle;
/* hide the app name and app icon of popup webview */
@property (nonatomic, assign) BOOL isHideApp;

@property (nonatomic, assign) BOOL isHideCloseBtn;
/* the width of popup webview */
@property (nonatomic, assign) int width;
/* the height of popup webview */
@property (nonatomic, assign) int height;

/* ZOOM-438509, dialog/command */
@property (nonatomic, copy) NSString *actionType;
/*ZOOM-680192 if actionType is equal to "appbridge", params for call HandleAppBridgeAction */
@property (nonatomic, copy) NSString *eventName;
@property (nonatomic, copy) NSString *tab;
@property (nonatomic, copy) NSString *url;

/* only for webhook */
@property (nonatomic, copy) NSString *triggerID;
@property (nonatomic, copy) NSString *actionFrom;

@property (nonatomic, assign) BOOL disabledForThreadWithoutReplies;
@property (nonatomic, assign) BOOL disabledForThreadWithReplies;
@property (nonatomic, assign) BOOL disabledForThreadReply;

@property (nonatomic, assign) BOOL isDisableInCMC;
@property (nonatomic, assign) BOOL isDisableInACE;

//ZOOM-524370
@property (nonatomic, assign) BOOL isInternalAppWithZapLaunch;
@property (nonatomic, copy) NSString *allowedDomains;

@property (nonatomic, assign) NSInteger appFeatures;

// ZOOM-560837
@property (nonatomic, assign) ZMChatAppWebViewPosition webViewPosition;
@property (nonatomic, assign) ZMChatAppTitleIcon titleIcon;
@property (nonatomic, assign) BOOL modalPopUp;
/// A Boolean value that indicates whether the app is presented in a
/// pop-up instead of a modal dialog.
@property (readonly, getter=isPopUpPresentation) BOOL popUpPresentation;

- (BOOL)isLauncherApp;

@end


@interface ZMChatAppInfo : NSObject

@property (nonatomic, copy) NSString *robotJID;
@property (nonatomic, copy) NSString *robotName;
@property (nonatomic, copy) NSString *robotIcon;
@property (nonatomic, copy) NSArray<ZMChatAppShortcutInfo*> *shortcuts;

@property (nonatomic, assign) BOOL isDisableAppInCMC;
@property (nonatomic, assign) BOOL isDisableAppInACE;

// ZOOM-560837
@property (nonatomic, assign) ZMChatAppWebViewPosition webViewPosition;

@end


@interface ZMChatAppMessagePreviewInfo : NSObject

@property (nonatomic, copy) NSString *threadID;
@property (nonatomic, copy) NSString *sessionID;
@property (nonatomic, copy) NSString *zoomAppID;
@property (nonatomic, copy) NSString *previewID;
@property (nonatomic, copy) NSImage *icon;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *desp;
@property (nonatomic, copy) NSString *appPayload;

@property (nonatomic, copy, readonly) NSString *accDescription;

@end

@interface ZMChatAppComposeMessageInfo : NSObject

@property (nonatomic, copy) NSString *zappId;
@property (nonatomic, copy) NSString *sessionId;
@property (nonatomic, copy) NSString *threadId;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, assign) ZMChatAppMessageEditAction action;
@property (nonatomic, assign) NSRange insertRange;
@property (nonatomic, assign, readonly) BOOL isReply;

@end


@interface ZMChatAppViewModel : NSObject

+ (instancetype)viewModelWithShortcutInfo:(ZMChatAppShortcutInfo *)shortcutInfo;

- (BOOL)isCloseButtonHidden;
- (BOOL)isTitleHidden;
- (BOOL)isAppNameHidden;

- (NSInteger)titleLineHeight;

- (NSInteger)nameLineHeight;

- (NSInteger)webViewTopMargin;

- (CGSize)webViewSize;

- (CGSize)windowSize;

- (NSEdgeInsets)contentMargin;

- (NSString *)windowAccessibilityLabel;

@end

@interface ZMChatAppContext : NSObject

@property (nonatomic, retain, readonly) ZMChatAppShortcutInfo *shortcutInfo;

@property (nonatomic, readonly) NSString *chatAppId;

@property (nonatomic, assign) ZMChatSessionType sessionType;
@property (nonatomic, copy, nullable) NSString *sessionID;
@property (nonatomic, copy, nullable) NSString *messageID;
@property (nonatomic, copy, nullable) NSString *threadID;

@property (nonatomic, weak) NSWindow *hostWindow;
@property (nonatomic, assign) NSRectCorner windowResizeCorner;

@property (nonatomic, copy, nullable) NSString *webViewId;

/// Draft
@property (nonatomic, copy, nullable) NSString *inputMessage;

@property (nonatomic, assign, getter=isMovableWindow) BOOL movableWindow;

/// auto close when resign first responder (click other windows of client)
@property (nonatomic, assign, getter=isAutoClose) BOOL autoClose;

@property (nonatomic,copy) NSString *smsInfo; //ZOOM-610954 for sms

+ (instancetype)contextWithShortcutInfo:(ZMChatAppShortcutInfo *)shortcutInfo;

- (NSImage *)shortcutIcon:(NSSize)size radius:(CGFloat)radius;

- (NSImage *)dialogTitleIcon;

@end

NS_ASSUME_NONNULL_END
