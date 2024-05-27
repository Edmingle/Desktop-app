//
//  ZMMessageAdapter.h
//  Zoom
//
//  Created by Deal Shao on 9/25/13.
//  Copyright (c) 2013 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomKit/zoom_client_conf.h>
#import <zChatComponent/ZMIMCommonDefine.h>
#import <zPTApp/SaasBeePTAppInterface.h>
#import <zChatApp/IZoomMessenger.h>

@class ZMPinMessageInfo;
@class ZMFileEntity;
@class ZMChatFileItem;
@class ZMScheduleMeetingInfo;
@class ZMShareEmailInfo;
@class ZMReminderMessageInfo;
@class ZMMTBuddyModel;
@class ZMMeetingChatCardEntity;
@class ZMChannelInviteRequestEntity;
@class ZMDeepLinkEntity;
@class ZMSharedSpaceOpenChannelInfo;

typedef NS_ENUM(NSUInteger, ZMZAppToastViewType);

typedef NS_ENUM(NSUInteger, ZMDisplayMsgTypeCheckResult) {
    ZMDisplayMsgTypeCheckResult_None = 0,
    ZMDisplayMsgTypeCheckResult_Checked = 1,
    ZMDisplayMsgTypeCheckResult_DisabledFileFromOthers = 2,
};


typedef NS_ENUM(NSUInteger, ZMMessageAdapterSenderType)
{
    ZMMessageAdapterSenderType_unknow = 0,
    ZMMessageAdapterSenderType_me,
    ZMMessageAdapterSenderType_other,
};

typedef NS_ENUM(NSUInteger, ZMCloudStoreState)
{
    ZMCloudStoreState_unknow = 0,
    ZMCloudStoreState_stored,
    ZMCloudStoreState_NotStored,
};

typedef NS_ENUM(NSUInteger, ZMThreadHasCommentType)
{
    ZMThreadHasCommentType_unknow = 0,
    ZMThreadHasCommentType_has,
    ZMThreadHasCommentType_no,
};

typedef NS_ENUM(NSUInteger, ZMPMCUnsupportMessageType)
{
    ZMPMCUnsupportMessageType_None, //supported message
    ZMPMCUnsupportMessageType_MeetChatToTeamChat, // message from Meet chat to Team chat，only support text message.
    ZMPMCUnsupportMessageType_TeamChatToMeetChat, // message from Team chat to Meet chat，only support text message.
    ZMPMCUnsupportMessageType_MeetChatToMeetChat, //message from Meet chat to Meet char，only support MessageType_JPG，MessageType_PNG，MessageType_GIF，MessageType_OtherFile，MessageType_ZappMessage，MessageType_MeetFileIntegration
};

typedef MessageState_CMKState ZMMessageCMKStatus;
typedef MessageErrorCode_CMK ZMMessageCMKErrorCode;


@interface ZMMessageFontRangeInfo : NSObject

@property (nonatomic,assign) NSRange range;
@property (nonatomic,copy,nonnull) NSString *value; //match _reserve1 in SDK data -> StyleOffset
@property (nonatomic,copy,nonnull) NSString *fileID;

@end

@interface ZMMessageFontInfo : NSObject

@property (nonatomic,assign) unsigned long long style;

@property (nonatomic, retain, readonly,nonnull) NSMutableArray<ZMMessageFontRangeInfo*>* rangeInfoArray;

- (void)addRangeInfo:(ZMMessageFontRangeInfo * _Nonnull)rangeInfo;

@end

@interface ZMMessageBackwardCompatibilityInfo : NSObject

@property (nonatomic,copy,nullable) NSString *content;
@property (nonatomic,copy,nullable) NSString *linkText;
@property (nonatomic,copy,nullable) NSString *link;
@property (nonatomic,assign)        ns_zoom_messager::BCLinkType linkType;
@end


@interface ZMMessageAdapter : NSObject

/**message ids**/
@property (nonatomic,copy,nonnull)      NSString *m_msgID;

@property (nonatomic,copy,nullable)     NSString *serverGuid;

@property (nonatomic,copy,nullable)     NSString * m_XMPPGuid;

@property (nonatomic,copy,nullable)     NSString *m_msgBody;

@property (nonatomic,copy,nullable)     NSString *sessionID;

@property (nonatomic,copy,nullable)     NSString *m_senderID;

@property (nonatomic,copy,nullable)     NSString *m_senderName;

@property (nonatomic,copy,nullable)     NSString *m_receiverID;

@property (nonatomic,copy,nullable)     NSString *threadID;

@property (nonatomic,copy,nullable)     NSString *m_giphyID;

@property (nonatomic,copy,nullable)     NSString *deleteThreadOperator;

/**message times**/

@property (nonatomic,assign)            unsigned long long threadServerTime;

@property (nonatomic,assign)            unsigned long long svrSideTime;

@property (nonatomic,assign)            unsigned long long prevMsgSvrSideTime;

@property (nonatomic,assign)            unsigned long long lastCommentTime;

@property (nonatomic,assign)            unsigned long long lastEmojiTime;

@property (nonatomic,assign)            unsigned long long internalTimeValue;

@property (nonatomic,readonly)          unsigned long long meetingMessageTime;

@property (nonatomic,retain,nullable)   NSDate *m_timeStamp;

@property (nonatomic,retain,nullable)   NSDate *editTime;

/**message type**/

@property (nonatomic,assign)            MessageType       m_msgType;

@property (nonatomic,assign)            ZMFileStorageType fileStorageType;

@property (nonatomic,readonly)          ZMPMCUnsupportMessageType PMCUnsupportMessageType;

@property (nonatomic,assign)            NSInteger filterType;

@property (nonatomic,assign)            BOOL isStickerMessage;

@property (nonatomic,assign)            BOOL isTempMessage;

@property (nonatomic,assign)            BOOL is3rdFileStorageMsg;

@property (nonatomic,assign)            BOOL isPMCSystemMsg;

@property (nonatomic,assign)            BOOL isSharedMessage;

@property (nonatomic,assign)            BOOL isSentByZoomRoom;

@property (nonatomic,readonly)          BOOL isMyNoteMessage;

@property (nonatomic,readonly)          BOOL isMeetingMessage;

@property (nonatomic,readonly)          BOOL isMeetingMessagePostByHost;

@property (nonatomic,readonly)          BOOL isSystemMessage;

@property (nonatomic,assign)            BOOL isMCCMessage; // ZOOM-377225 Flag, meeting chat card message

@property (nonatomic,readonly)          BOOL isMeetChatAceTrans;

@property (nonatomic,assign)            BOOL isCurrentMeetingMsg;

/**message status**/

@property (nonatomic,assign)            MessageState m_msgState;

@property (nonatomic,assign)            ZMCloudStoreState msgCloudStoreState;

@property (nonatomic,assign)            ZMCloudStoreState commentThreadCloudStoreState;

//e2e
@property (nonatomic,assign)            BOOL isE2EMessage;

@property (nonatomic,assign)            BOOL m_isPending;

@property (nonatomic,assign)            BOOL m_isSendingFailed;

@property (nonatomic,assign)            BOOL m_isHistorySyncMessage;

@property (nonatomic,assign)            BOOL m_isUnread;

@property (nonatomic,readonly)          BOOL isUnread;

@property (nonatomic,assign)            BOOL m_isOffline;

@property (nonatomic,assign)            BOOL isDeletedThread;

@property (nonatomic,assign)            BOOL isNotExistThread;

@property (nonatomic,assign)            BOOL isDeletedByChannelAdmin;

@property (nonatomic,assign)            BOOL isTimeout;

@property (nonatomic,assign)            BOOL m_isSupportedMessage;

@property (nonatomic,assign)            BOOL isNeedTriggerUpdate;

@property (nonatomic,assign)            BOOL isContainCommentFeature;

@property (nonatomic,assign)            BOOL isCouldReallySupport;

@property (nonatomic,assign)            BOOL isSaveInDatabase;

@property (nonatomic,assign)            BOOL isWaring;

@property (nonatomic,assign)            BOOL isBotMessageCanReply;

@property (nonatomic,assign)            BOOL hasReplyPending;

@property (nonatomic,assign)            BOOL isFollowedThread;

@property (nonatomic,readonly)          BOOL isSendOrReceived;

@property (nonatomic,readonly)          BOOL isSending;

@property (nonatomic,readonly)          BOOL isSendByMe;

@property (nonatomic,readonly)          BOOL isSendSuccessMessage;

@property (nonatomic,readonly)          BOOL isSendErrorMessage;

@property (nonatomic,readonly)          BOOL isSendFailMessage;

@property (nonatomic,readonly)          BOOL isMarkUnread;

@property (nonatomic,readonly)          BOOL isE2EDecodeFailed;

@property (nonatomic,readonly)          BOOL isE2EMessageDecoded;

@property (nonatomic,readonly)          BOOL hasReaction;

@property (nonatomic, readonly)         BOOL isSubCMCMessage;
@property (nonatomic, readonly)         BOOL isSubCMCBotMessage;

/** Some type of image (like .png, .jpg, or .jif) would be deleted from file-server and not sync with xmpp server, which can no longer be download anymore. This "isNotExistAtServerImage" serves as a flag of those invalid image. Those image-msg would convert to text-msg */
@property (nonatomic,assign)            BOOL isNotExistAtServerImage;

/**message reply**/
@property (nonatomic,assign)            BOOL isComment;

@property (nonatomic,assign)            BOOL isThread;

@property (nonatomic,assign)            BOOL hasComments;

@property (nonatomic,assign)            NSInteger iCommentsCount;

/**message mentioin**/
@property (nonatomic,assign)            BOOL m_atEveryone;

@property (nonatomic,assign)            BOOL m_atMe;

@property (nonatomic,assign)            BOOL m_atMentionGroup;

@property (nonatomic,retain,nullable)   NSMutableArray*   m_atList;

@property (nonatomic,retain,nullable)   NSMutableArray*   m_mentionInfoList;

/**message pin**/
@property (nonatomic,copy,nullable)     NSString *pinner;

@property (nonatomic,assign)            BOOL isTopPin;

/**message font style**/
@property (nonatomic,retain,nullable)   NSMutableArray*   m_fontStyleInfoList;

/**message image/file status**/
@property (nonatomic,readonly)          BOOL hasFile;

@property (nonatomic,assign)            BOOL m_isFileDownloaded;

@property (nonatomic,assign)            BOOL m_isPlayed;

@property (nonatomic,assign)            BOOL m_isPreviewPicDownloaded;

@property (nonatomic,assign)            BOOL m_isFileUploaded;

@property (nonatomic,assign)            NSUInteger m_uploadPercentage;
@property (nonatomic,assign)            NSUInteger m_uplaodBitsPerSecond;
@property (nonatomic,assign)            NSUInteger m_uploadTransferredSize;
@property (nonatomic,assign)            NSInteger  m_uploadErrorID;
@property (nonatomic,assign)            NSUInteger m_audioLength;
@property (nonatomic,assign)            NSUInteger m_videoLength;
@property (nonatomic,assign)            NSUInteger m_fileSize;

@property (nonatomic,copy,nullable)     NSString *m_picturePreviewPath;
@property (nonatomic,copy,nullable)     NSString *m_localFilePath;
@property (nonatomic,copy,nullable)     NSString *m_fileName;

@property (nonatomic,readonly)          NSArray <ZMChatFileItem *> * _Nullable allFiles;

@property (nonatomic,retain,nullable)   ZMFileEntity *fileModel;

/**message apps card**/
@property (nonatomic,assign)            BOOL isAppPreviewCardMsgWithNoTextAndFile;

@property (nonatomic,assign)            NSUInteger appPreviewCardCount;

@property (nonatomic,copy,nullable)     NSString *pinStringForAppPreviewCardMsg;

@property (nonatomic,retain,nullable)   ZMMeetingChatCardEntity *meetingChatModel;

/**link unfurling**/
@property (nonatomic,copy,nullable)     NSString *linkMessageID;
@property (nonatomic,copy,nullable)     NSString *linkURL;
@property (nonatomic,retain,nullable)   NSMutableArray *linkUnfurlingMessages;
@property (nonatomic,readonly)          BOOL isShortcutUnfurlingMsg;

/**zapps**/
@property (nonatomic,copy,nullable)     NSString *appId;//zapp
@property (nonatomic,copy,nullable)     NSString *zappName;
@property (nonatomic,copy,nullable)     NSString *iconPath;
@property (nonatomic,copy,nullable)     NSString *thumbnailPath;
@property (nonatomic,copy,nullable)     NSString *appUuid;

//zapp meeting chat
@property (nonatomic,retain,nullable)   ZMZAppConfShareInfo *zappShareInfo;
@property (nonatomic,copy,nullable)     NSString *appCompanyName;
@property (nonatomic,assign)            ZMZAppToastViewType   viewType;
@property (nonatomic,retain,nullable)   NSImage *betaIcon;
@property (nonatomic,assign)            BOOL isZappMessage;

// CMK Related
@property (nonatomic,assign)            ZMMessageCMKStatus CMKStatus;
@property (nonatomic,assign)            ZMMessageCMKErrorCode CMKErrorCode;
@property (nonatomic,readonly)          NSString * _Nullable CMKErrorCodeString;
@property (nonatomic,assign)            BOOL CMKUnavailableHistoryMessage;

/**meeting chat**/
//jeffery add for meeting chat
@property (nonatomic,assign)            BOOL needMeetingStyle;

@property (nonatomic,copy,nullable)     NSString *m_receiverName;

@property (nonatomic,assign)            NSInteger m_MeetingChatmsgType;

@property (nonatomic,copy,nullable)     NSString *m_receiverConfId;

@property (nonatomic,assign)            BOOL m_isSendToMe;

@property (nonatomic,copy,nullable)     NSString *m_meetingMsgId;

@property (nonatomic,assign)            BOOL enablePersistentChannel;

// If the message's sent in the meeting, the senderGuid will not be nil.
@property (nonatomic,copy,nullable)     NSString *senderGuid;

@property (nonatomic,assign)            BOOL needShowGuestLabel;

/**channel invite **/
@property (nonatomic, retain,nullable)  ZMChannelInviteRequestEntity *channelInviteRequest;

/**email info **/
@property (nonatomic,retain,nullable)   ZMShareEmailInfo *shareEmailInfo;

/**shared message **/
@property (nonatomic,copy,nullable)     NSString *sharedMessageNote;

/**schedule meeting info **/
@property (nonatomic,retain,nullable)   ZMScheduleMeetingInfo *scheduleMeetingInfo;

/// Parsed URLs in message body.
///
/// If you access this property when its value is not populated, the receiver will
/// load it in the calling thread and returns the resulting value.
@property (nonatomic, readonly, nullable) NSArray<NSString *> *parsedURLs;

/**backward compatibility**/
@property (nonatomic, retain,nullable) ZMMessageBackwardCompatibilityInfo *backwardCompatibilityInfo;

@property (nonatomic,retain,nullable)  ZMSharedSpaceOpenChannelInfo *shareSpaceOpenChannelInfo;

- (id _Nonnull )initWithMessage:(void *_Nonnull)zmMessage;

- (id _Nonnull )initWithMessage:(void *_Nonnull)zmMessage ignoreDeeplinks:(BOOL)ignoreDeeplinks;

- (void *_Nullable)messageExtention;
- (BOOL)isReminderMessage;
- (BOOL)supportsReminderMessage;
- (BOOL)isE2EMessageDecoded;
- (BOOL)isPicMessage;
- (BOOL)isVoiceMessge;
- (BOOL)isFileMessge;
- (BOOL)isGiphyMessage;
- (BOOL)isDisabledFileFromOthers;
- (BOOL)isHybridMessage;
- (BOOL)isCodeSnippetMessage;
- (BOOL)isHTMLCodeSinnpetBody;
- (BOOL)isRobotMessage;
- (BOOL)isCallMessage;
- (BOOL)isVideoMessage;
- (NS_ZOOM_MESSAGER::FileIntegrationType)fileIntegrationType;
- (void)update;
- (void)updateComments;
- (void)updatePinInfo;
- (BOOL)isNotOrderGroupSysmentMessage;
- (BOOL)isCountdownMeetingCard;
- (BOOL)isScheduleMeetingMessage;
- (NSString *_Nonnull)unsupportedText;
// meeting
- (ZMMTBuddyModel *_Nullable)senderMeetBuddyModel;
- (ZMMTBuddyModel *_Nullable)receiverMeetBuddyModel;
- (NSString *_Nullable)fetchMeetSenderName;
- (NSString *_Nullable)fetchMeetReceiverName;
//todo-
//- (BOOL)getFileIntegrationDetailWithFileIntegrations:(std::vector<NS_ZOOM_MESSAGER::FileIntegrationData>)fileIntegrations;
- (BOOL)isSupportMarkUnread;
- (ZMThreadHasCommentType)hasCommentsType;
- (BOOL)isNeedSyncComments;
//ZOOM-108962
- (BOOL)isBroadcastAnnouncement;
- (BOOL)isBroadcastAnnouncementReceiver;
//ZOOM-164281
/**Server verify, avoid customers to get around by renaming the extension to the account's approved file types */
- (BOOL)validateFailedOfApprovedFileInServer;
- (BOOL)isDirectShareScreenMessage;

- (BOOL)getFileIntegrationDetailWithFileIntegrations:(std::vector<NS_ZOOM_MESSAGER::FileIntegrationData>)fileIntegrations;

+ (ZMPinMessageInfo *_Nonnull)getPinMessageInfo:(const ns_zoom_messager::PinMessageInfo &)pinMsgInfo;

+ (ZMReminderMessageInfo *_Nonnull)getReminderMessageInfo:(const NS_ZOOM_MESSAGER::ReminderInfo &)reminderMsgInfo
     event:(const NS_ZOOM_MESSAGER::ReminderEvent)event;

// Compare senders and receivers between two messages to know if they are the same, when merging the cell header
+ (BOOL)isSameUserByAdapter:(ZMMessageAdapter *_Nonnull)firstAdapter comparedTo:(ZMMessageAdapter *_Nonnull)secondAdapter;


- (void)clearAccessoryDeepLinkList;

/*hybrid message*/
- (BOOL)onlyHasWhiteboardPreviewFlieList;
- (BOOL)hasAccessoryLists;
- (BOOL)hasAccessoryListsWithoutDeepLink;
- (BOOL)hasAccessoryListsWithoutWhiteboarePreview;
- (BOOL)hasAccessoryListsWithoutWhiteboardOrDeepLink;

- (NSArray<ZMFileEntity *> *_Nullable)getAccessoryWhiteboardPreviewList;
- (NSArray<ZMFileEntity *> *_Nullable)getAccessoryFileList;
- (NSArray<ZMFileEntity *> *_Nullable)getAccessoryImageList;
- (NSArray<ZMDeepLinkEntity *> *_Nullable)getAccessoryDeepLinkList;

/* combined with accessoryFileList & accessoryImageList, sorted with [ZMFileEntity positionIndex] */
- (NSArray<ZMFileEntity *> *_Nullable)getSortedAccessoryList;
- (NSArray<ZMFileEntity *> *_Nullable)getSortedAccessoryListWithoutWhiteboard;

/* RTF */
- (NSArray<ZMMessageFontInfo *> *_Nullable)getFontStyleInfoList;

@end



@interface ZMMessageMentionInfo : NSObject

@property (nonatomic,assign) NS_ZOOM_MESSAGER::MessageAtType mentionType;
@property (nonatomic,copy) NSString* _Nonnull messageID;
@property (nonatomic,assign) NSRange range;

- (id _Nonnull )initWithMessageMentionInfo:(NS_ZOOM_MESSAGER::MessageAtInfo *_Nonnull)messageMentionInfo;
@end
