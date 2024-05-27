//
//  ZMGroupProtocol.h
//  ZoomMsgUI
//
//  Created by Groot Ding on 2022/5/18.
//

#ifndef ZMGroupProtocal_h
#define ZMGroupProtocal_h

NS_ASSUME_NONNULL_BEGIN

typedef void(^ZMChannelListenCompletion)(NSString * channelId,id param);
typedef void(^ZMChannelOperateCompletion)(NSString * channelId, NSError* error,id param);
typedef void(^ZMChannelSearchCompletion)(NSString * key, NSError* error,NSArray *channels);

@class ZMSessionGroupAdapter;
@class ZMChannelEditInfo;
@class ZMGroupInviteConsentRequestInfo;

typedef NS_ENUM(NSInteger, ZMLeaveChannelReason)
{
    ZMLeaveChannelSelfQuit,
    ZMLeaveChannelSelfDisband,
    ZMLeaveChannelAdminDelete,
    ZMLeaveChannelAdminKickout,
};

/**
 channel operate event call back,like : create channel, modify channel name
 */
@protocol ZMChannelOperateListen <NSObject>

- (void)addListenChannelCreateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelJoinByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelDeleteByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelInfoUpdateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelMembersRemoveByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelMembersAddedByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelAssignAdminByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelInfoDescUpdateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelNameUpdateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelOptionUpdateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelPendingUserUpdateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenClassificationUpdateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenMioLicenseUpdatedByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenGroupExternalUsersReceivedByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenGroupGiphyEnabledChangedByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenArchivedStatusUpdateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)addListenChannelEmailAddressCreateByTarget:(id)target completion:(ZMChannelListenCompletion)completion;

- (void)removeAllListenByTarget:(id)target;

@end

@protocol ZMGroupOperateProtocol <NSObject>

- (NSString *)createMUC:(NSString *)name memberJids:(NSArray*)jids isRestrictHistoryMessages:(BOOL)isRestrictHistoryMessages completion:(ZMChannelOperateCompletion)completion;

- (NSString *)createMUC:(NSString *)name memberJids:(NSArray*)jids memberEmails:(NSArray*)emails isRestrictHistoryMessages:(BOOL)isRestrictHistoryMessages extraRoomFlags:(int)roomFlags completion:(ZMChannelOperateCompletion)completion;

@end

@protocol ZMChannelOperateCallback <NSObject>

- (void)didCreateGroup:(unsigned int)result owner:(NSString*)actionOwner groupID:(NSString*)groupID time:(NSDate*)time requestID:(NSString*)requestID param:(NSDictionary *)param;

- (void)didModifyGroup:(unsigned int)result editInfo:(ZMChannelEditInfo *)editInfo;

- (void)didModifyGroupName:(unsigned int)result owner:(NSString*)actionOwner groupID:(NSString*)groupID newName:(NSString*)newName time:(NSDate*)time;

- (void)didModifyGroupFlag:(unsigned int)result owner:(NSString*)actionOwner groupID:(NSString*)groupID flag:(NSInteger)flag time:(NSDate*)time;

- (void)didLeaveGroup:(unsigned int)result owner:(NSString*)actionOwner groupID:(NSString*)groupID time:(NSDate*)time name:(NSString*)name isChannel:(BOOL)isChannel isEventChannel:(BOOL)isEventChannel;

- (void)didAddGroupMember:(unsigned int)result owner:(NSString*)actionOwner groupID:(NSString*)groupID buddyJids:(NSArray <NSString *> *)buddyJids notAllowBuddyJids:(NSArray <NSString *> *)notAllowBuddyJids time:(NSDate*)time maxAllow:(NSInteger)maxAllowNumber requestId:(NSString *)requestId isChatInvite:(BOOL)isChatInvite;

- (void)didRemoveGroupMember:(unsigned int)result owner:(NSString*)actionOwner groupID:(NSString*)groupID buddies:(NSArray*)buddies time:(NSDate*)time;

- (void)didChannelInfoUpdate:(NSString*)channelId;

- (void)didChannelClassificationUpdate;

- (void)didSearchPublicChannel:(unsigned int)result count:(int)count fromIndex:(int)index;

- (void)didJoinPublicChannel:(unsigned int)result channelId:(NSString*)channelId;

- (void)didAssignChannelOwner:(unsigned int)result channelId:(NSString*)channelId buddyIds:(NSArray <NSString *> *)buddyIds;

- (void)didUnassignChannelAdmins:(unsigned int)result channelId:(NSString*)channelId buddyIds:(NSArray <NSString *> *)buddyIds;

- (void)didAssignChannelAdmins:(unsigned int)result channelId:(NSString*)channelId buddyIds:(NSArray <NSString *> *)buddyIds;

- (void)didDisbandChannel:(unsigned int)result channelId:(NSString*)channelId;

- (void)didPendingUserUpdated:(NSString*)channelId;

- (void)didGroupExternalUsersReceived:(NSArray<NSString *> *)userJids groupID:(NSString *)groupID requestID:(NSString *)requestID isCropped:(BOOL)isCropped;

- (void)didMioLicenseUpdated:(BOOL)enabled;

- (void)didReceiveInviteConsentRequest:(nonnull ZMGroupInviteConsentRequestInfo *)info;
- (void)didRejectInviteConsentRequest:(nonnull NSString *)sessionID;

- (void)didChannelArchivedChanged:(NSString *)channelId isArchived:(BOOL)isArchived;

- (void)didChannelEmailaddressCreated:(NSString *)channelId param:(NSDictionary *)param;

- (void)removeInviteConsentRequest:(nonnull NSString *)sessionID;
@end


@protocol ZMGroupProtocol <ZMChannelOperateListen,ZMGroupOperateProtocol>

- (nullable ZMSessionGroupAdapter *)getChannelById:(nonnull NSString *)channelId;

- (nullable ZMSessionGroupAdapter *)getChannelById:(nonnull NSString *)channelId refersh:(BOOL)refersh;

- (nullable ZMSessionGroupAdapter*)getChannelAtIndex:(NSUInteger)index;

- (NSUInteger)getAllChannelCount;

- (BOOL)isGroupID:(NSString*)groupID;

- (BOOL)isGroupChatSession:(NSString *)sessionId;

- (BOOL)isChannel:(NSString *)groupId;

- (BOOL)amIInGroup:(nonnull NSString*)groupID;

- (void)refreshMembersByChannelIds:(nonnull NSArray <NSString *> *)channelIds;

- (BOOL)checkAmIOwnerInChannel:(nonnull NSString *)channelId;

- (BOOL)checkAmIAdminInChannel:(nonnull NSString *)channelId;

- (BOOL)checkOwner:(NSString *)jid inChannel:(NSString *)channelId;

- (BOOL)amIAnnouncerInChannel:(NSString *)channelId;

- (BOOL)amIReplyOnlyInChannel:(NSString *)channelId;

- (BOOL)checkMute:(nonnull NSString *)channelId;

- (BOOL)checkChannelNameExists:(nonnull NSString *)name channelId:(nullable NSString *)channelId spaceId: (nullable NSString *)spaceId;

- (BOOL)checkIfAdminsExceedLimitInChannel:(nonnull NSString *)channelId;

- (BOOL)checkIsPMCDisableChat:(nonnull NSString *)channelId;

- (NSArray <ZMSessionGroupAdapter *> *)getAllChannels;
- (NSArray <ZMSessionGroupAdapter *> *)getAllChannelsWithoutMUC;

- (nullable NSString *)fetchGroupExternalUsers:(nonnull NSString *)groupId;

- (nullable NSString*)fetchPreviewGroupInfoWithGroupId:(nonnull NSString*)groupId fetchMemberCount:(NSInteger)fetchMemberCount;

- (BOOL)deletePreviewGroup:(nonnull NSString*)groupId;

- (BOOL)deleteAllPreviewGroups;

- (BOOL)isArchiveChannelEnabled;

- (BOOL)isArchivedChannel:(NSString*)sessionId;

- (BOOL)unArchiveChannelWithSessionId:(NSString *)sessionId;

- (BOOL)archiveChannelWithSessionId:(NSString *)sessionId;

@end

#ifndef ZMShareGroupProtocol
#define ZMShareGroupProtocol (id <ZMGroupProtocol>)ZMSharedFor(ZMGroupProtocol)
#endif

#endif /* ZMGroupProtocal_h */

NS_ASSUME_NONNULL_END
