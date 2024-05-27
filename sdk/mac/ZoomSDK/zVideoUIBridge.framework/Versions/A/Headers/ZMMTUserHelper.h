//
//  ZMMTUserHelper.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/7/11.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/NSMutableArray+ZMUserHelper.h>
NS_ASSUME_NONNULL_BEGIN

@class ZMUser;
@class ZMMTNameTag;

ZMUser* ZMDefaultUserMap(CmmUInt32 userid);
ZMUser* ZMBackstageUserMap(CmmUInt32 userid);
ZMUser* ZMBOMasterUserMap(CmmUInt32 userid);
ZMUser* ZMConfInstUserMap(CmmUInt32 userid, NSString *identifier);

@interface ZMUserHelper : ZMBaseHelper

+ (ZMUserHelper*)sharedHelper;

- (int)getAllUserCount;
- (NSInteger)getAllUserCount:(int&)outHost coHost:(int&)outCoHost waiting:(int&)outWaiting tempTalk:(int&)outTempTalk;//ZOOM-15291
- (NSInteger)getUserCountWithFilter:(ZMUserExcludeFilter)filter;
- (NSInteger)getUserCount:(const std::vector<zm::UserConstraint>&)vecConstraint;
- (BOOL)isSameUser:(ZMUserID)userA with:(ZMUserID)userB;
- (BOOL)isSignLanguageInterpreterAllowedToTalkByCmmUser:(ICmmUser*)inCmmUser; //ZOOM-330475
- (BOOL)userVideoCanMuteByHostWithUser:(ZMUser *)theUser;
- (BOOL)userVideoCanUnmuteByHostWithUser:(ZMUser *)theUser;
- (BOOL)amIHost;
- (BOOL)amICoHost;
- (BOOL)amIHostCoHost;
- (BOOL)amIBOModerator;
- (BOOL)amIOriginalHost;
- (BOOL)amIMasterConfHost;
- (BOOL)amIInterpreter;
- (BOOL)amISignLanguageInterpreter;
- (BOOL)isMySelfForUserId:(ZMUserID)inUserId;
- (BOOL)isMySelfForUniqueJoinIndex:(CmmUInt32)uniqueJoinIndex;
- (ZMUserID)getMyUserId;
- (NSString *)getMyUserGUID;
- (CmmUInt32)getMyUniqueJoinIndex;
- (nullable ZMUser *)getMyzmUser;
- (nullable ZMUser *)getZmHostUser;
- (nullable ZMUser *)getMasterZmHostUser;
- (long long)getMyAttendeeId;
- (nullable ICmmUser*)getMySelf;
- (nullable ICmmUser*)getMasterMySelf;
- (nullable ICmmUser*)getHostUser;
- (nullable ICmmUser*)getMasterOriginalHostUser;
- (nullable ICmmUser*)getLoginUserByEmail:(NSString *)email;
- (nullable NSArray <ZMUser *> *)getUserByUserEmail:(NSString *)email;
- (nullable ICmmUser*)getCmmUserByUserName:(NSString *)userName;
- (nullable NSString*)getUserNameByCmmUser:(ICmmUser*)inCmmUser;
- (NSString*)getUserPronounByCmmUser:(ICmmUser*)inCmmUser;//ZOOM-273485
- (NSString*)getUserNameById:(ZMUserID)inUserId;
- (NSString*)getUserPronounById:(ZMUserID)inUserId; //ZOOM-273485
- (NSString*)getLeftUserNameById:(int)inUserId;
- (nullable NSImage*)getAvatarByCmmUser:(ICmmUser*)inCmmUser;

//webinar attend info
- (nullable IZoomQABuddy*)getWebinarUserByUserId:(int)inUserId;
- (nullable IZoomQABuddy*)getWebinarUserByJid:(NSString*)inJid;
- (nullable IZoomQABuddy*)getWebinarUserByGuid:(NSString*)inGuid;
- (nullable IZoomQABuddy*)getMyWebinarUser;
- (NSString*)getWebinarUserNameByJid:(NSString*)inJid;
- (nullable NSArray<ZMUser*>*)getFilterBuddyListByKey:(NSString*)keyWord;
- (NSUInteger)getAttendeeCount;

- (NSUInteger)getRaiseHandUserCount;
- (NSUInteger)getPanelistRaiseHandUserCount;
- (int)getWebinarAttendeeRaiseHandUserCount;
- (nullable NSArray<ZMUser*>*)getOrderPanelistRaiseHandUserArray;
- (nullable NSString*)getTheOnlyRaiseHandUserName;
- (int)getPureTelephoneUserCount;

- (nullable NSArray<ZMUser*>*)getSupportAutoShareUserArray;
- (nullable NSArray<ZMUser*>*)getSupportAutoRebootUserArray;
- (BOOL)isSendingShareUserSupportAutoShare;
- (BOOL)isSendingShareUserSupportAutoReboot;
- (int)getNodeIdByUserId:(int)inUserId;
- (int)getPeerUserId;

- (nullable NSMutableArray<ZMUser*>*)getWaitingUsersArray;
- (nullable NSMutableArray<ZMUser*>*)getWaitingUsersArrayWithoutLeaving;
- (NSInteger)getWaitingUserCount;
- (int)getUserCountWithoutWaiting;
- (int)getFirstWaitingUserId;
- (BOOL)isUserSendingShareByUserId:(int)inUserId;

- (BOOL)isGuestFeatureEnable;
- (BOOL)isGuestByUser:(ZMUser *)theUser;
//ZOOM-21795
- (nullable ZMUser *)getPureComputerAudioSharingUser;
- (BOOL)isPureComputerAudioSharingByUserID:(int)inUserId;//ZOOM-41522

- (BOOL)isLinkedInSwitchOn;//ZOOM-35020
- (nullable NSURL*)getLinkedInURLByUserID:(int)inUserId;//ZOOM-35020

- (BOOL)hasUserInSilenceMode;//ZOOM-46301

//ZOOM-115938
- (BOOL)hasPureCallInUser;
- (BOOL)hasNoAudioClientUser;
- (nullable NSArray*)getUsersCanMergeToUser:(ZMUser *)user;

//ZOOM-276920
/// When invitee has no conf user id use email to get ConfInviteeItem struct
- (nullable NS_ZOOM_DATA::ConfInviteeItem *)getConfInviteeItemByCUID:(NSString *)confuserId orByEmail:(NSString *)email;
/// Return yes, if invitee joined current meeting / in waiting room/ in break room
/// Return no, if invitee never joined, left meeting
- (BOOL)isInviteeInMeeting:(NS_ZOOM_DATA::ConfInviteeItem *) inviteeItem;//ZOOM-276920

- (BOOL)canIRenameUserWithUser:(ZMUser *)theUser;

- (BOOL)isVideoMergedOnSharingDocWithUserId:(ZMUserID)inUserId;
- (BOOL)isSharingDocWithUser:(ZMUser *)inUser;
- (BOOL)isSharingDesktopWithUser:(ZMUser *)inUser;
- (BOOL)isSharingWithUser:(ZMUser *)inUser;
- (BOOL)isVideoMergedOnSharingDocForMyself;//ZOOM-184354

- (BOOL)canIRemoveUser:(ZMUser *)theUser;//ZOOM-177544

- (nullable NSArray*)getAllHostCoHostUserIds;//ZOOM-271443
- (nullable NSArray<ZMUser *> *)getAllHostCoHostUserArray;
- (NSArray*)getMultiStreamGroupUsersForUser:(ZMUser*)zmUser;
- (nullable NSArray*)getChildrenForUser:(ZMUser*)zmUser;
- (nullable NSArray*)getMultiStreamChildrenForUser:(ZMUser*)zmUser;
- (nullable ZMUser*)getParentUserForUser:(ZMUser*)zmUser;
- (BOOL)hasChildrenForUser:(ZMUser*)zmUser;
- (BOOL)isAvailableParentUser:(ZMUser*)zmUser;
- (BOOL)hasMultiStreamChildrenForUser:(ZMUser*)zmUser;
- (BOOL)hasSmartGalleryChildrenForUser:(ZMUser*)zmUser;

- (nullable ZMUser *)getZmUserByUserId:(ZMUserID)userID;
- (nullable ZMUser *)getE2EELeaderUser;

// before confReady
- (nullable ZMMTNameTag *)getMyNameTag;

- (NSInteger)legalParticipantCount;
- (NSInteger)legalAttendeCount;

- (nullable ICmmUserList*)getCmmUserList;
- (nullable ICmmUserList*)getMasterCmmUserList;

- (nullable ICmmUser*)getCmmUserByGUID:(NSString*)GUID;
- (nullable ICmmUser*)getCmmLeftUserByGUID:(NSString*)GUID;
- (nullable ICmmUser*)getMasterCmmUserByGUID:(NSString*)GUID;

- (nullable ICmmUser*)getCmmUserById:(ZMUserID)inUserId;
- (nullable ICmmUser*)getCmmUserByUUID:(ZMUUID)UUID;
- (nullable ICmmUser*)getCmmUserByUniqueJoinIndex:(CmmUInt32)uniqueJoinIndex;
- (nullable ICmmUser*)getLeftUserById:(ZMUserID)inUserId;
- (nullable ICmmUser*)getCmmLeftUserByUUID:(ZMUUID)UUID;

- (nullable ICmmUser*)getMasterUserById:(ZMUserID)userId;
- (nullable ICmmUser*)getMasterCmmUserByUUID:(ZMUUID)UUID;
- (nullable ICmmUser*)getMasterCmmUserByUniqueJoinIndex:(CmmUInt32)uniqueJoinIndex;
- (nullable ICmmUser*)getMasterCmmLeftUserById:(ZMUserID)userId;
- (nullable ICmmUser*)getMasterCmmLeftUserByUUID:(ZMUUID)UUID;

- (BOOL)canIAdmitOthersWhenNoHost;
- (BOOL)isSupportWaitingAdmit;
//ZOOM-570490
- (BOOL)isMeetingAccountAdmin;
- (BOOL)isSupportEnableSummaryWorkflow;
- (BOOL)isSupportStartSummaryWorkflow;
- (BOOL)hasSupportEnableSummaryAdminInMeeting;
- (BOOL)hasSupportStartSummaryUserInMeeting;

//ZOOM-576025
- (BOOL)isSupportEnableQueryWorkflow;
- (BOOL)isSupportStartQueryWorkflow;
- (BOOL)hasSupportEnableQueryAdmin;
- (BOOL)hasSupportStartQueryUserInMeeting;

- (BOOL)isSupportControlAICompanion;
- (BOOL)hasSupportControlAICompanionHostCoHost;

//ZOOM-10609
- (BOOL)isEnableParticipantID;

//jeffery add
- (nullable ICmmUser*)getCmmUserByConfUserId:(NSString*)ZoomId;

- (nullable NSArray<ZMUser *>*)getPSLivedUsersArray;
- (BOOL)isUserPSLived:(ZMUser *)zmUser;
- (BOOL)isUserPSLivedWithShare:(ZMUser*)zmUser;
- (nullable NSString *)getUserEmail:(ZMUser *)zmUser;
- (BOOL)isPSProducerWithUser:(ZMUser *)zmUser;
- (BOOL)isInGreenRoomWithUser:(ZMUser *)zmUser;
- (BOOL)isEnterSubWithUser:(ZMUser *)zmUser;

- (BOOL)hasCoHostUserInMeeting;
@end

NS_ASSUME_NONNULL_END
