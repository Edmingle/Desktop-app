//
//  ZMChatSearchProtocol.h
//  zChatComponent
//
//  Created by Groot Ding on 2022/8/5.
//

#ifndef ZMChatSearchProtocol_h
#define ZMChatSearchProtocol_h

#import <ZoomKit/ZMCallbackImpl.h>
#import <zChatComponent/ZMIMCommonDefine.h>
#import <zChatComponent/ZMIMDataInfo.h>

@class ZMSearchBuddyParam;
@class ZMSessionGroupAdapter;
@class ZMSearchResultItem;

typedef NS_ENUM(NSUInteger, ZMGroupSearchType) {
    ZMGroupSearchTypeAll,
    ZMGroupSearchTypeMUC,
    ZMGroupSearchTypeGroup,
};

NS_ASSUME_NONNULL_BEGIN

@protocol ZMChatSearchProtocol <NSObject>

@optional

- (nullable NSString *)asyn_searchLocalContactsByKey:(nonnull NSString *)key fliter:(ZMLoacalContactSearchFilter)fliter callBack:(nonnull ZMCallbackBlock)callBack;

- (nullable NSString *)searchRemoteBuddy_V2:(nonnull NSString *)key searchParam:(nullable ZMSearchBuddyParam *)searchParam callBack:(nonnull ZMCallbackBlock)callBack;

- (BOOL)searchRemoteBuddy:(NSString *)key callBack:(void(^)(NSString *key,NSArray <ZMSearchResultItem *> * items,NSError *error))callBack;

- (NSArray <ZMSearchResultItem *> *)searchChannelMembersByKey:(NSString *)key channelId:(NSString *)channelId;

//if key is empty,will get recent groups
- (nullable NSArray <ZMSessionGroupAdapter *> *)searchGroupByKey:(nullable NSString *)key;

- (NSArray <ZMSearchResultItem *> *)recentChatAndStarredSessionItems;

- (NSArray <ZMSearchResultItem *> *)recentChatSessionItems;

- (NSArray <ZMSearchResultItem *> *)recentChatBuddiesItems;

- (NSArray <ZMSearchResultItem *> *)getLocalStrictSearchBuddies;

- (NSArray <ZMSearchResultItem *> *)channelMembersByChannelId:(NSString *)channelId sortExternalUsersToEnd:(BOOL)bSortExternalUsersToEnd;

- (void)removeSearchCallBackByKey:(nonnull NSString *)key;

- (BOOL)searchChannelMember:(nonnull NSString *)channelId keyword:(nonnull NSString *)keyword callBack:(void(^)(NSString *key, NSArray <ZMSearchResultItem *> * items, NSError *error))callBack;

- (void)didSearchChannelMember:(NSInteger)result searchResponse:(const ns_zoom_messager::ChannelMemberSearchResponse &)searchResponse reqId:(nullable NSString *)reqId;


- (BOOL)searchChannelByKeyword:(nullable NSString *)keyword callBack:(void(^)(NSString *key,NSArray <ZMSearchResultItem *> * items,NSError *error))callBack;

- (BOOL)searchChannelByKeyword:(nullable NSString *)keyword channelFilter: (ZMChannelSearchFilter *)channelFilter callBack:(void(^)(NSString *key,NSArray <ZMSearchResultItem *> * items,NSError *error))callBack;

- (void)didSearchChannelByKeyword:(nullable NSString *)keyword result:(NSInteger)result searchResponse:(const NS_ZOOM_MESSAGER::ChannelSearchResponse&)response reqId:(NSString *)reqId;

//ZOOM-423027
- (BOOL)queryIfUsersInChannelRequest:(nonnull NSString *)channelId jids:(nonnull NSArray<NSString*> *)jidArray callBack:(void(^)(NSString *key,NSArray <NSString *> * jidArray,NSError *error))callBack;
- (void)didQueryIfUsersInChannelRequest:(nonnull NSString *)reqId result:(NSInteger)result jids:(nonnull NSArray<NSString*> *)jidArray;

- (NSString *)searchGroupsByBuddies:(NSArray <NSString *> *)jids groupType:(NSInteger)type maxCount:(NSInteger)maxCount completion:(nonnull ZMCallbackBlock)completion;
- (void)didSearchGroupsByJids:(NSArray <NSString *> *)channelIds requestID:(NSString*)requestID;

//ZOOM-382630
- (void)disableInputContainerWhenSearchMUCs;
- (void)enableInputContainerWhenSearchMUCs;

- (BOOL)checkResults:(NSArray <ZMSearchResultItem *> *)results filter:(NSInteger)filter;

- (NSString *)getEventTrackingEventId;

- (NSString *)getEventTrackingSessionId;

@end


#ifndef ZMShareChatSearchProtocol
#define ZMShareChatSearchProtocol (id <ZMChatSearchProtocol>)ZMSharedFor(ZMChatSearchProtocol)
#endif

NS_ASSUME_NONNULL_END

#endif /* ZMChatSearchProtocol_h */
