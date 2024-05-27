//
//  IZMMTWhiteboardMgr.h
//  VideoUIBridge
//
//  Created by Devl on 2022/11/28.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, ZMCannotWBShareReason)
{
    ZM_CANNOT_WB_SHARE_REASON_NONE,
    ZM_CANNOT_WB_SHARE_REASON_DISABLED,
    ZM_CANNOT_WB_SHARE_REASON_HOST_DISABLED,
    ZM_CANNOT_WB_SHARE_REASON_HOST_ONLY,
    ZM_CANNOT_WB_SHARE_REASON_OTHER_WB_SHARING,
    ZM_CANNOT_WB_SHARE_REASON_CANNOT_CREATE,
    ZM_CANNOT_WB_SHARE_REASON_HAVE_SHARE_FROM_MAINSESSION,
    ZM_CANNOT_WB_SHARE_REASON_OTHER_SHARE_SHARING,
    ZM_CANNOT_WB_SHARE_REASON_OTHER_ZDOC_SHARING,
    ZM_CANNOT_WB_SHARE_REASON_PROCTORING_MODE,
    ZM_CANNOT_WB_SHARE_REASON_NEED_GRAB_WB,
    ZM_CANNOT_WB_SHARE_REASON_NEED_GRAB_MY_SHARE,
    ZM_CANNOT_WB_SHARE_REASON_NEED_GRAB_OTHER_SHARE,
    ZM_CANNOT_WB_SHARE_REASON_NEED_GRAB_MY_ZDOC,
    ZM_CANNOT_WB_SHARE_REASON_NEED_GRAB_OTHER_ZDOC,
};

NS_ASSUME_NONNULL_BEGIN

@class ZMMTWhiteboardDashboard;
@class ZMMTWhiteboardViewController;
@class ZMMTWBCanvasWebView;

@protocol IZMMTWhiteboardMgr <ZMRoutableObject>

@property (nonatomic, readonly) ZMMTWhiteboardDashboard *dashboard;
@property (nonatomic, readonly) ZMMTWBCanvasWebView *canvasWebView;
- (void)createCanvasWebView;

- (ZMMTWhiteboardViewController*)newViewControllerWithType:(ZMMTType)type;

- (BOOL)isPresentingWhiteboard;
- (BOOL)isViewingWhiteboard;
- (BOOL)isInWhiteboardMode;

- (BOOL)isReceivingWhiteboard;
- (BOOL)isAnyoneInWhiteboardMode;
- (BOOL)isWhiteboardSettingLocked;
- (int)viewRole;

- (NSUInteger)viewableWhiteboardCount;
- (NSString *)viewableWhiteboardId;
- (ZMUser *)viewableWhiteboardUser;

- (BOOL)isAllowShareWhiteboard;
- (void)setAllowShareWhiteboard:(BOOL)allowed;

- (void)showAllStatusWnd;
- (void)hideAllStatusWnd;
- (void)showWhiteboardSetting;
- (void)showDashboard;
- (void)closeDashboard;

- (void)startShareWhiteboard:(nullable NSString *)docId templateId:(nullable NSString*)templatedId;
- (void)stopShareWhiteboard;
- (void)stopAllWhiteboards;
- (BOOL)canStartWB:(ZMCannotWBShareReason *)reason;

//Native Sink
- (void)onDocumentStatusChanged:(NSString*)docId status:(int)status;
- (void)onActiveSourceChanged:(NSString*)docId userID:(ZMUserID)userID;
- (void)onPresenterChanged:(NSString*)docId userID:(ZMUserID)userID;
- (void)onShareRoleChanged:(NSString*)docId role:(int)role;
- (void)onDocumentDeleted:(NSString*)docTitle;
- (void)onStartShare;
- (void)onStopShare;
//Web Sink
- (void)onWebWBEvent:(int)event docId:(NSString*)docId userID:(ZMUserID)userID;

- (BOOL)shouldShowButtonOnToolBar;

- (BOOL)initiatingAllowed;
- (BOOL)redirectingEnabled;

//There are 2 callers:
//One caller is the share selecting window
//Another trigger is the toolbar at the bottom of the meeting window
- (void)initiateAWhiteboard:(BOOL)triggeredByShareSelectingWindow
needShowBack2ClassicWBToast:(BOOL)needShowBack2ClassicWBToast;
@end

@protocol IZMMTWhiteboardStatusProtocol <NSObject>

- (void)onPermissionChanged;

@end

NS_ASSUME_NONNULL_END
