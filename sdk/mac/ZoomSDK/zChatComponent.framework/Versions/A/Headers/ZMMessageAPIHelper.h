//
//  ZMMessageAPIHelper.h
//  zChatComponent
//
//  Created by Kevin Li on 2022/8/4.
//

#import <Foundation/Foundation.h>
#import <dataModule/zDataConstants.h>
#import <zChatComponent/ZMIMCommonDefine.h>
#import <zChatComponent/ZMIMDataInfo.h>

NS_ASSUME_NONNULL_BEGIN


@class ZMChannelMemberSearchFilter;


@interface ZMAtEventTelemetryData : NSObject

@property (nonatomic, copy) NSString* jid;
@property (nonatomic, assign) NSInteger index;

@end


@interface ZMMessageAPIHelper : NSObject

+ (ZoomIMPresence)getMyPresence;
+ (ZoomIMPresenceStatus)getMyPresenceStatus;

+ (void)joinMeetingWithMessageID:(NSString * _Nullable)messageID sessionID:(NSString * _Nullable)sessionID;
+ (BOOL)isSharePointEnabledInChannel:(nullable NSString*)groupID;
+ (ZMFileStorageType)currentFileStorageType;
+ (NSInteger)getSessionFileSotrageType:(nonnull NSString*)sessionID;
+ (E2EChatOption)getMyE2EOption:(nullable NSString *)sessionID;
+ (BOOL)isWhiteboardURL:(nonnull NSString*)url sessionID:(nullable NSString*)sessionID;
+ (BOOL)searchMessageFileDisable;

// ZOOM-628330 describes what are considered as internal links.
// Currently, internal links should include:
//  - Join meeting link
//  - Deeplinks such as "Link to chat message"
//  - Whiteboard links
+ (BOOL)isZoomInternalURL:(nonnull NSString *)URLString sessionID:(nullable NSString *)sessionID;

+ (BOOL)isMessageAtChannelAllowPreview:(nonnull NSString*)sessionId withMessageID:(nonnull NSString*)messageID groupID:(nonnull NSString*)groupID;

+ (BOOL)isSessionExistByID:(nonnull NSString*)sessionID ;

+ (BOOL)sendButtonCommand:(NSDictionary*)info;
+ (BOOL)sendSelectCommand:(NSDictionary*)info;
+ (BOOL)sendTimePickerCommand:(NSDictionary *)info;
+ (BOOL)sendDatePickerCommand:(NSDictionary *)info;
+ (BOOL)sendRadioButtonCommand:(NSDictionary *)info;
+ (BOOL)sendCheckboxCommand:(NSDictionary *)info;
+ (BOOL)sendSmartScheduleButtonCommand:(NSDictionary *)info;
+ (BOOL)sendCloseAlertCommand:(NSDictionary *)info;
+ (BOOL)sendTextAreaCommand:(NSDictionary *)info;

+ (BOOL)isLargeChannelForMemberListOptimization:(NSString*)sessionId;
+ (NSString*)searchChannelMember:(ZMChannelMemberSearchFilter*)searchFilter;

+ (nullable NSArray<NSString*>*)sortChannelMemberSearchResult:(nonnull NSString*)sessionId threadId:(nullable NSString*)threadId keyword:(nullable NSString*)keyword jidArray:(nonnull NSArray<NSString*>*)jidArray hasMore:(nullable BOOL*)hasmore;

+ (nullable NSString*)searchChannelByKeyword:(nonnull NSString*)keyword;

+ (nullable NSString*)searchChannelByKeyword:(nonnull NSString*)keyword channelFilter:(ZMChannelSearchFilter*)channelFilter;

+ (nullable NSString*)getMarketplaceURLForMioSupport; //ZOOM-386910

+ (BOOL)isEnableImprovedMentionSortLogic:(NSString *)sessionId;
+ (void)sendAtEventTelemetryWithList:(nullable NSArray*)list type:(ZMMessageSrcType)srcType;
+ (nullable NSArray*)getAtMentionSortedListForSessionID:(nullable NSString*)sessionID threadID:(nullable NSString*)threadID key:(nullable NSString*)key hasMore:(nullable BOOL*)hasmore;

+ (BOOL)isEnableOutOfOffice;

+ (BOOL)isInOfflineMode;

+ (BOOL)isEnablePersonalContactEdition;

+ (BOOL)joinHuddleByURL:(NSString *)huddleUrl;
@end

NS_ASSUME_NONNULL_END
