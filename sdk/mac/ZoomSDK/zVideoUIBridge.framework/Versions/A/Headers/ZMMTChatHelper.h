//
//  ZMMTChatHelper.h
//  VideoUIBridge
//
//  Created by Cain Zhou on 2022/11/8.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/ZMUIConstants.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUser;

#ifdef __cplusplus
class IZoomChatInWebinar;
class ICmmUser;
#endif

#ifdef __cplusplus
extern "C" {
#endif
ZMConfSession *ZMMTChatGetCurrentSession(void);
#ifdef __cplusplus
}
#endif

typedef NS_ENUM(NSUInteger, ZMTDLPResultType)
{
    ZMTDLPResultType_NotSet = 0,
    ZMTDLPResultType_NeedConfirm,
    ZMTDLPResultType_Block,
};

@interface ZMMTChatHelper : ZMBaseHelper

#ifdef __cplusplus
- (nullable IZoomChatInWebinar *)fetchWebinarChatComponent;
- (PANELIST_CHAT_PRIVILEGE)fetchPanelistChatPrivilege;
#endif
- (uint8_t)fetchAttendeeChatPrivilege;
- (BOOL)isWebinarChatSettingEnabled;

//chat permission
- (BOOL)isPrivateOff;
- (BOOL)isChatDisabledByInfoBarrier;
- (BOOL)isChatOff;
- (BOOL)isChatDisabledByServer;
- (NSInteger)getChatDisabledReasons;
- (BOOL)isChatDisabledByArchive;
- (BOOL)isChatDisabledByDLP;
- (BOOL)isChatDisabledByRegulatedUserJoinE2EEMeeting;

// save chat
- (BOOL)hasSaveChatPrivilege; // show up the save chat item
- (BOOL)enableSaveChat; // enable to click the save chat item
- (BOOL)isSaveChatOff;

// user
- (BOOL)isUserInSilentMode:(long)uid;
- (BOOL)isGuestByUser:(ZMUser *)zmUser; // the condition is not connected with the guest web setting, which is different from `zmUserHelper`
- (int)fetchWebinarChattedAttendeeCount;
#ifdef __cplusplus
- (BOOL)isValidChatUser:(ICmmUser *)user;
#endif

// copy chat
- (BOOL)hasCopyChatPrivilege;
- (BOOL)isCopyChatEnabled;

// share chat
- (BOOL)shouldShowShareMeetingChat;

// delete chat
- (BOOL)hasDeleteChatPrivilege:(NSString *)messageId;
- (void)deleteMessage:(NSString *)messageId;
- (BOOL)isDeleteChatEnabled;

// Chat Etiquette Tool
- (ZMTDLPResultType)checkDLPPolicyWithContent:(NSString *)content;

// message
- (int)fetchMessageCount;
- (nullable NSString *)fetchMessageIDByIndex:(int)index isNotification:(BOOL *)isNotification;
#ifdef __cplusplus
- (nullable CmmChat::ICmmChatMessageItem *)fetchMessageByID:(NSString *)messageId;
#endif
- (void)notifyUnreadMessageCount:(int)num;

// tip of legal notice: who can see your messages
- (BOOL)isNoticeAvailable;
- (BOOL)isCMRNoticeAvailable;
- (BOOL)isLocalRecordingNoticeAvailable;

// file
- (BOOL)isFileTransferEnabled;
- (BOOL)needPromotePotentialSecurityIssueDialog:(NSString *)messageId needShowCheck:(BOOL *)needShow;
- (BOOL)needPromotePotentialSecurityIssueDialog:(NSString*)fileName senderGuid:(NSString*)senderGuid senderJid:(NSString*)senderJid needShowCheck:(BOOL *)needShowCheck;

#ifdef __cplusplus
- (BOOL)IsDropBoxInMeetingOn:(FileIntegrationOperation)op;
- (ssb_xmpp::XmppError)uploadFile:(NSString *)filePath
     toUser:(long)userID
chatMsgType:(ChatMsgType)msgType;
- (ssb_xmpp::XmppError)downloadFile:(NSString *)filePath
  messageID:(NSString *)msgID;
- (BOOL)shareFileIntegrationTo:(long)receiveID
                       content:(const ShareFileInMeetingChatParam_s &)fileInfo
                   chatMsgType:(ChatMsgType)msgType;
#endif
- (BOOL)filePause:(NSString *)msgID;
- (BOOL)fileResume:(NSString *)msgID;
- (BOOL)fileCancel:(NSString *)msgID;
- (uint64_t)fetchFileTransferLimitSize; // Can be 0 if sdk makes some error.
- (unsigned long long)fetchMaxFileSize; // if `fetchFileTransferLimitSize` is 0, will return `512M`.
- (BOOL)isFileSizeFailed:(unsigned long long)size;
- (BOOL)isFileTypeBlocked:(NSString *)path;
- (BOOL)isFileTransferDisabledByInfoBarrier;
- (BOOL)isFileDisabledByInfoBarrier; // with `isFileTransferDisabledByInfoBarrier` || `isChatDisabledByInfoBarrier`

// webinar
- (void)updateChattedAttendees;
- (void)changeAttendeeChatPrivilege:(NSInteger)privilege;
- (void)changePanelistChatPriviledge:(NSInteger)privilege;

// window
- (BOOL)isPopupChatWindowEnabled;
- (void)setPopupChatWindowEnable:(BOOL)enable;

/* send messages for meeting & webinar
   params:
     - to user group: `receiverId` is `0`;
   ZOOM-46301: to silent users;
 */
#ifdef __cplusplus
- (BOOL)sendMessage:(NSString *)content to:(long)receiverId chatMsgType:(ChatMsgType)msgType;
- (BOOL)isSilentModeMessageType:(ChatMsgType)type;
- (SHARE_MEETING_CHAT_STATUS)shareMeetingChatStatus;
- (ShareMeetingChatToSessionData)shareMeetingChatSessionData;
- (BOOL)checkIfMeBelondsToSession;
#endif

// new chat & pmc
- (nullable NSString *)getContentMsgByMsgID:(NSString *)msgID;
- (BOOL)isPMCNewExperienceEnabled;
- (BOOL)isPMCForBackendEnabled;
- (NSString *)fetchNewChatSessionId;
- (NSString *)sessionID;  //Zoom Meeting ChannelID

- (void)showInFinder;

- (BOOL)isChatDisabled;
- (BOOL)isChatDisabledByHost;
- (BOOL)isChatDisabledByConfig;
- (BOOL)isCopyDisabled;
- (BOOL)isEditDisabled;
- (NSString*)disableDetail;

- (BOOL)isChatDisabledBySecurity;
- (void)setChatDisabledBySecurity:(BOOL)bDisabled;

- (BOOL)isDisableHyperLinkEnabled;
- (BOOL)chechIfZoomInternalNavigateURL:(NSURL *)url;
- (BOOL)checkAndHandleZoomInternalNavigateURLAction:(NSURL *)url;

- (BOOL)canChatWithWR;
- (BOOL)canChatWithWRUser;
- (BOOL)canChatInWR;

- (BOOL)canChatWithGR;

- (BOOL)restrictChat2UserId:(long)userId; //can select send to ZOOM-587410

- (BOOL)canSendChat2UserId:(long)userId;
- (BOOL)canSendChat2UserGuid:(NSString*)guid msgType:(NSInteger)msgType;

- (BOOL)canSendFile2UserId:(long)userId;
- (BOOL)canSendFileIntegration2UserId:(long)userId;

- (void)notifyPT2ShareMeetingChatData;
- (void)notifyPT2EditMeetingChatData;

- (NSString *)getChatTitle;
- (void)getLegalTitle:(NSString* _Nonnull* _Nonnull)title detail:(NSString* _Nonnull* _Nonnull)detail;

//MARK: - Sub Chat
- (BOOL)isSubChatEnabled;
- (BOOL)isSubChatAllowed;
- (BOOL)isSubChatForSession:(NSString*)sessionID;
- (BOOL)isMainChatForSession:(NSString*)sessionID;
- (BOOL)isChatAllowedForSession:(NSString*)sessionID;
- (NSInteger)unreadCountForSession:(NSString*)sessionID;
- (NSInteger)unreadCountForAll;

- (uint32_t)createSubChatGroup:(nullable NSString*)groupName userArray:(NSArray<ZMUser*>*)userArray;
- (BOOL)deleteSubChatGroup:(NSString *)groupID;
- (BOOL)modifySubChatGroup:(NSString *)groupID groupName:(NSString*)groupName;
- (BOOL)addSubChatGroupMembers:(NSString *)groupID userArray:(NSArray<ZMUser*>*)userArray;
- (BOOL)removeSubChatGroupMembers:(NSString *)groupID userArray:(NSArray<NSNumber*>*)userJIDArray;
- (BOOL)leaveSubChatGroup:(NSString*)groupID;
#ifdef __cplusplus
- (BOOL)getSubChatGroupList:(SubChatGroupList&)groupList;
- (BOOL)GetSubChatGroupById:(NSString*)groupID groupInfo:(CmmSubChatGroupInfo&)groupInfo;
#endif

- (NSString*)sessionIDForGroupID:(NSString*)groupID;
- (NSString*)groupIDForSessionID:(NSString*)sessionID;

@end

NS_ASSUME_NONNULL_END
