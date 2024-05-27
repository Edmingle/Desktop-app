//
//  ZMChannelModule.h
//  zChatUI
//
//  Created by groot.ding on 2018/5/9.
//  Copyright © 2018年 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMChannelEditInfo.h>
#import <zChatComponent/ZMGroupProtocol.h>
#include "zPTApp/SaasBeePTAppInterface.h"
#import <zChatComponent/ZMAddExternalUserInfo.h>


@interface ZMAccountAdminWhoInviteExternalToGroupSettingInfo : NSObject

@property (nonatomic, assign) BOOL isInviteEXternalUserEnabled;
@property (nonatomic, assign) ZMAccountAdminWhoInviteExternalToGroupType whoCanInviteExternal;
@property (nonatomic, assign) BOOL isOrgMemberCanJoinExternalChatEnable;

@end

@class ZMChannelEditInfo;
@class ZMChannelInitInfo;

const NSInteger MAX_CHANNEL_ADMINS = 50;


@class ZMSessionGroupAdapter;
@class ZMSessionGroupProperty;
@class ZMChatClassificationInfo;

@interface ZMChannelModule : NSObject <ZMChannelOperateListen,ZMChannelOperateCallback,ZMGroupProtocol>

+ (instancetype)shareInstance;
+ (void)invalidate;

- (ZMSessionGroupAdapter *)getChannelById:(NSString *)channelId;

- (ZMSessionGroupAdapter *)getChannelById:(NSString *)channelId refersh:(BOOL)refersh;

- (BOOL)isSpotEnabledInChannel:(NSString*)channelID;

- (BOOL)isChatClassificationsEnable;
- (NSArray <ZMChatClassificationInfo *> *)getChatClassifications;
- (ZMChatClassificationInfo *)getClassificationByID:(NSString *)classificationId;

- (BOOL)checkBuddy:(NSString *)jid inChannel:(NSString *)channelId;
- (BOOL)checkAdmin:(NSString *)jid inChannel:(NSString *)channelId;
- (BOOL)checkAnnouncer:(NSString *)jid inChannel:(NSString *)channelId;

- (void)refreshMembersByChannelIds:(NSArray <NSString *> *)channelIds;

- (NSString *)createChannel:(ZMChannelInitInfo *)initInfo completion:(ZMChannelOperateCompletion)completion;

- (NSString *)createChannel:(NSString *)name memberJids:(NSArray*)jids groupIDs:(NSArray *)gids announcers:(NSArray *)announcers channelType:(NSInteger)channelType completion:(ZMChannelOperateCompletion)completion;

- (NSString *)createChannel:(NSString *)name memberJids:(NSArray*)jids memberEmails:(NSArray*)emails groupIDs:(NSArray *)gids announcers:(NSArray *)announcers channelType:(NSInteger)channelType classificationID:(NSString *)classificationID completion:(ZMChannelOperateCompletion)completion;

- (NSString*)convertToChannel:(NSString*)channelId channelName:(NSString*)name completion:(ZMChannelOperateCompletion)completion;

- (NSString *)modifyChannel:(NSString *)channelId property:(ZMSessionGroupProperty *)property completion:(ZMChannelOperateCompletion)completion;

- (NSString *)modifyChannelDes:(NSString *)des channelId:(NSString *)channelId completion:(ZMChannelOperateCompletion)completion;

- (NSString *)addChannelMembers:(NSArray <NSString * > *)jids groupIDs:(NSArray *)gids channelId:(NSString *)channelId completion:(ZMChannelOperateCompletion)completion;

- (NSString *)addChannelMembers:(NSArray <NSString * > *)jids membersEamil:(NSArray*)emails groupIDs:(NSArray *)gids channelId:(NSString *)channelId completion:(ZMChannelOperateCompletion)completion;

- (NSString *)removeChannelMembers:(NSArray <NSString * > *)jids channelId:(NSString *)channelId completion:(ZMChannelOperateCompletion)completion;

- (void)searchPublicChannelByKey:(NSString *)key completion:(ZMChannelSearchCompletion)completion;

- (NSString *)joinPublicChannel:(NSString *)channelId completion:(ZMChannelOperateCompletion)completion;

- (NSString *)assignChannelOwner:(NSString *)jid channelId:(NSString *)channelId completion:(ZMChannelOperateCompletion)completion;

- (NSString *)assignChannelOwnerV2:(NSString *)jids channelId:(NSString *)channelId completion:(ZMChannelOperateCompletion)completion;

- (NSString *)assignChannelAdmins:(NSArray <NSString *> *)jids channelId:(NSString *)channelId completion:(ZMChannelOperateCompletion)completion;

- (NSString *)unassignChannelAdmins:(NSArray <NSString *> *)jids channelId:(NSString *)channelId completion:(ZMChannelOperateCompletion)completion;

- (NSString *)disbandChannel:(NSString *)channelId completion:(ZMChannelOperateCompletion)completion;

- (NSString *)leaveChannel:(NSString *)channelId completion:(ZMChannelOperateCompletion)completion;

- (void)cancelRequestByKey:(NSString *)key;

/// Clears cached external setting data
- (void)webExternalSettingDidUpdate;
/// Seed value. Can be used to check if the current web external data is out of date.
- (NSInteger)webExternalSettingCacheSeed;
- (ZMAccountAdminWhoInviteExternalToGroupSettingInfo *)getWebSettingAccountAdminInviteExternalUsersSettingInfo;
/// Updates cached name for the channel.
- (void)sharedSpaceUpdateNameForGeneralChannel:(NSString*)channelId;

- (BOOL)isReallySameOrgWithChannelOwner:(NSString *)jid inChannel:(NSString *)channelId;
- (BOOL)isReallySameAccountWithChannelOwner:(NSString *)jid inChannel:(NSString *)channelId;
- (BOOL)isReallyNotSameAccountWithChannelOwner:(NSString *)jid inChannel:(NSString *)channelId;

@end
