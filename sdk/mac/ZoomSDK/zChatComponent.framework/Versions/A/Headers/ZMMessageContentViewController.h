//
//  ZMMessageContentViewController.h
//  ChatUI
//
//  Created by Groot Ding on 2022/4/7.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <ZoomKit/ZoomKit.h>
#import <zChatComponent/ZMChatMessageDataSource.h>
#import <zChatComponent/ZMMessageCellViewDelegate.h>
#import <zChatComponent/ZMMessageInputProtocol.h>
#import <zChatComponent/ZMIMListView.h>
#import <zChatComponent/ZMIMCommonDefine.h>

NS_ASSUME_NONNULL_BEGIN

#if __cplusplus
static constexpr float kZMMessageContentViewController_reminderStackViewOffset = -16.f;
#else
static const float kZMMessageContentViewController_reminderStackViewOffset = -16.f;
#endif

extern NSString *kIM_ChatSessionWillDisappear;

@class ZMChatMessageItemInfo;
@class ZMAddReplyMessageCellView;
@class ZMChatsNewMessageBubbleButton;
@class ZMInputTextView;
@class ZMIMMessageLayoutConfig;
@class ZMChatMsgItemInfo;
@class ZMBaseMessageCellView;
@class ZMChatsInputContainerViewCtrl;
@class ZMChatAppContext;
@class ZMIMMessageDraft;

/// UI Configs Model
/// Suggest adding UI configs instead of business params for generality
@interface ZMMessageContentViewControllerModel : NSObject

@property (nonatomic, copy) NSString *sessionId;
@property (nonatomic, assign) BOOL needLoadHistoryWhenInit; // Determine invoke `initMessages` when `viewDidLoad`
@property (nonatomic, assign) BOOL needKeepUnFold;

@end

@interface ZMMessageContentViewController : ZMBaseViewController
<
NSOutlineViewDelegate,
NSOutlineViewDataSource,
ZMTrackingScrollViewProtocol,
ZMChatMessageDataSource,
ZMChatMessageLoadDelegate,
ZMMessageCellViewDelegate,
ZMToastCoordinatorProvider,
ZMListViewDataSource,
ZMListViewDelegate
>

@property (nonatomic,retain) ZMIMListView *messagesOutlineView;

@property (nonatomic,retain) NSMutableArray *newAddedMarkUnreadMsgArray NS_RETURNS_NOT_RETAINED;

@property (nonatomic,copy) NSString *selfMarkReadMsgId;

@property (nonatomic,copy) NSString* sessionID;

@property (nonatomic,readonly) BOOL isVirtualSession;

@property (nonatomic,readonly) BOOL isMySelfSession;

@property (nonatomic,assign) BOOL needLoadMoreRecent;

@property (nonatomic,assign) BOOL isSyncDoneWhenInit;

@property (nonatomic,assign) BOOL shoudDecodeWhenSomeoneOnline;

@property (nonatomic,assign) BOOL shouldScrollToEnd;

@property (nonatomic,assign) BOOL isManualScroll;

@property (nonatomic,assign) BOOL isE2EEnabled;

@property (nonatomic,assign) NSInteger readedMsgTime;

@property (nonatomic,assign) BOOL jumpToBtnCanVisible;

@property (nonatomic,assign) BOOL isShowPinHightlight;

@property (nonatomic,assign) BOOL isNeedShowRemindButton;

@property (nonatomic,assign) BOOL isNeedShowLoadFail;

@property (nonatomic,copy) NSString *highlightBackgroundSearchMessageId;

@property (nonatomic,copy) NSString *highlightBubbleMessageId;

@property (nonatomic,assign) BOOL shouldCleanUnread;

@property (nonatomic,assign) BOOL automaticLoadMessageWhenOnline;

@property (nonatomic,retain) ZMStackView * reminderBtnStackViews;

@property (nonatomic,retain) ZMChatsNewMessageBubbleButton *reminderButton;

@property (nonatomic,retain) ZMChatsNewMessageBubbleButton *markUnreadReminderView;

@property (nonatomic, retain, nullable) ZMIMMessageLayoutConfig *layoutConfig;

// layoutManagerClass, works when tableView reloads, nullable (ZOOM-401850)
@property (nonatomic, assign) Class layoutManagerClass;

@property (nonatomic, copy) void (^updateUnreadMentionMe)(NSString *msgId);

@property (nonatomic, retain) id<ZMToastCoordinatorProtocol> toastCoordinator;

@property (nonatomic, retain) NSLayoutConstraint *scrollViewTopConstraint;
@property (nonatomic, retain) NSLayoutConstraint *scrollViewBottomConstraint;
@property (nonatomic, retain) NSLayoutConstraint *reminderStackViewBottomConstraint;

@property (nonatomic, readonly, assign) NSEdgeInsets scrollViewContentInsets;

@property (nonatomic,weak) ZMChatsInputContainerViewCtrl *inputViewCtrl;
@property (nonatomic, weak) ZMChatsInputContainerViewCtrl *inputViewCtrlForNewChats;

- (ZMInputTextView *)mainInputTextView;

// init methods
- (instancetype)initWithSessionID:(NSString*)sessionID;
- (instancetype)initWithModel:(ZMMessageContentViewControllerModel *)model;

- (ZMChatMessageDataSourceImpl *)dataSourceImpl;
- (ZMChatMessageDataSourceImpl *)getDataSourceBySessoinId:(NSString *)sessionId;

- (void)setupSubViews;
- (void)viewDidShow;

- (void)registerNotification;
- (void)updateUIForFontSizeRate:(NSInteger)sizeOffset;
- (void)onSessionActiveChanged:(BOOL)isActived;
- (void)updateMessageWhenActiveChanged:(BOOL)isActived;
- (void)resetCellHeight:(BOOL)fontSizeChanged;
- (void)cleanUpUnreadMessages;
- (void)cleanUpUnreadMessagesFromMenu:(BOOL)cleanTotal;
- (void)cleanUnreadCommentsForThread:(NSInteger)svrSideTime;
- (void)resetUnreadHint;
- (void)cleanAllMessages;
- (void)updateWhenBlockStatusChanged:(BOOL)isBlocked;
- (void)updateFromMessageCellViewWithNode:(NSTreeNode *)item;
- (void)updateMessageUIByNode:(NSTreeNode *)msgNode;
- (void)noteHeightOfRowsWithIndexesChangedWithoutAnimation:(NSIndexSet*)indexSet;
- (void)updateNames;
- (void)checkAutoScroll;
- (BOOL)isStartAtFirstUnread;
- (BOOL)needUnreadHint;
- (BOOL)needTimeChat;
- (BOOL)isDropMode;
- (BOOL)needDragFiles;
- (BOOL)needReloadHistoryMessages;
- (CGFloat)messageTopMargin;
- (NSString*)sessionName;
- (NSString*)sessionNameWithoutGroup;
- (NSInteger)getUnreadMessageCount;
- (NSInteger)getReadedMessageTime;
- (NSString *)mySelfJid;
- (void)onResendItem:(ZMChatMsgItemInfo*)item forCellView:(ZMBaseMessageCellView*)cellView;
- (void)checkReminderViewWhenReceiveMessage:(ZMMessageAdapter*)message;


- (BOOL)checkNeedUpdateBuddies:(NSArray<NSString *>*)jids;
- (BOOL)shouldJump2Message:(NSTreeNode *)msgNode;
- (BOOL)jumpToMessageID:(NSString*)messageId;
- (BOOL)jumpToMessageIfShowed:(ZMChatMessageItemInfo *)msgInfo;
- (BOOL)shouldJump2MessageOnBottom:(NSTreeNode *)msgNode;
- (void)jumpToUnreadHintMsg;
- (void)jumpToUnreadMessage;
- (void)jumpStartOfUnreadMessage;
- (void)scrollToEndOfDocument;

- (BOOL)updateMessageWithID:(NSString*)messageId;
- (BOOL)updateE2EMessageWithID:(NSString*)messageId;

- (void)selectMessageByNode:(NSTreeNode *)node;
- (void)beginEditMessageByNode:(NSTreeNode *)node;

//toast
- (void)showToast:(ZMToast*)toast;
- (void)removeToast:(ZMToast*)toast;

- (void)initMessages;

- (void)onMessageCountChanged;
- (BOOL)checkMessageUpdateIfNeedBySessionId:(NSString *)sessionId;
- (void)onMarkUnreadUpdate:(NSString *)sessionId messageIds:(NSArray <NSString *> *)messageIds;
- (void)resetMarkUnreadWhenViewDidShow;
- (void)schedule2CleanVisibleAreaMarkUnreadMsg;
- (void)markUnreadOrReadChanged;
- (NSArray*)getSortedMarkUnreadMessageArray:(BOOL)filterNewMarkUnread;

- (void)sessionUnreadCountReset:(BOOL)isFromOtherPlatform;

- (ZMAddReplyMessageCellView*)getReplyMessageCellViewForThreadID:(NSString*)threadID createIfNeed:(BOOL)createIfNeed;

- (void)loadMoreHistoryMessages;
- (void)loadMoreRecentMessages;
- (void)loadMoreCommentMessageByIds:(NSDictionary *)threadIds;
- (void)updateMessageCanloadMoreHistory;
- (void)updateMessageCanloadMoreRecent;
- (void)updateLoadMoreHistoryFinish;
- (void)updateLoadMoreRecentFinish;

- (void)cleanNoDropAllUnreadComments;

- (BOOL)requestNewPageAfterOnlineAgain;

- (void)tryToHighlightMessageBubble;
- (void)cancelHighlightMessageBubble:(NSString *)messageId;
- (BOOL)tryToHighlightBackground;

- (void)stashCurrentVisableScroll;
- (void)recoverLastVisableScroll;

- (void)setReminderButtonToVisible:(BOOL)isVisible;
- (void)setMarkUnreadReminderBtnVisible:(BOOL)isVisible;
- (void)scheduleCheckReminderButtonVisible;
- (BOOL)unread_isMainWindow;

- (void)scheduleDecodeVisableUndecodedMessages;

- (void)didUpdateUnreadMentionMeMessageByMsgId:(NSString *)msgId;

- (void)quoteMessage:(ZMMessageAdapter *)message; //jeffery add for meeting chat
- (BOOL)legalToEditMessageByMsgId:(NSString *)msgId;

- (void)hideAllMenu;
- (void)closeMessageAlerts;

- (void)markAllMsgRead;

- (void)updateTimedChatMessage;

- (void)viewFrameDidChange:(NSNotification*)notification;
- (void)resetVisibleCell;

- (void)invalidateScrollViewContentInsets;

- (void)switchMessageContentNormalType;

- (BOOL)jumpToSearch:(id)param;
- (BOOL)jumpToSearch:(id)param needHighlightBackground:(BOOL)needHighlightBackground;

- (BOOL)isShowLoadingIndicator;

- (void)startLoadingIndicator;

- (void)stopLoadingIndicator;

- (void)updateVisableBuddies:(NSArray<NSString *>*)jids;

- (void)editScheduledMessage:(nonnull ZMIMMessageDraft *)draft;
- (void)finishEditingScheduledMessage;

- (void)updateE2EStatus:(BOOL)isEnableE2E;
- (void)checkShowUserGuideInE2EChannelAfterSendHybridMsg;

- (BOOL)isLastMessageVisible;

- (BOOL)isScheduledMessageBannerShow;

// subclass override
- (void)onEditMessageCallback:(NSString *)msgId sessionId:(NSString *)sessionId error:(NSError *)error;

#pragma mark - Chat App
- (void)openChatApp:(ZMChatAppContext *)context referenceView:(nullable NSView *)view;

#pragma mark - tipview
- (void)closeTipView;
- (void)updateTipView;
- (void)showTipView:(ZMTipView_Type)type;
- (void)showBroadcastAnnouncementPlaceholderView:(ZMTipView_Type)type;

#pragma mark Smart Reply
- (void)requestComposeSmartReplyIfNeed;
- (void)hideComposeSmartReply;

- (void)onWindowResizing;

@end

NS_ASSUME_NONNULL_END
