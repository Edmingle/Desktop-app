//
//  ZMDeepLinkProtocol.h
//  zChatComponent
//
//  Created by Groot Ding on 2022/7/19.
//

#ifndef ZMDeepLinkProtocol_h
#define ZMDeepLinkProtocol_h

#import <zChatComponent/ZMIMCommonDefine.h>
#include <zPTApp/SaasBeePTAppInterface.h>
#include <zChatComponent/ZMDeepLinkEntity.h>

@class ZMMessageAdapter;

@interface ZMUniversalDeepLinkInfo : NSObject

@property (nonatomic) ZMUniversalDeepLinkType linkType;
@property (nonatomic, nullable, retain) NSString *messageID;
@property (nonatomic, nullable, retain) NSString *sessionID;

@end

@protocol ZMDeepLinkProtocol <NSObject>

@optional

- (BOOL)isDeepLink:(NSString *_Nonnull)url sessionId:(NSString *_Nullable)sessionId;

- (void)openLink:(NSString* _Nonnull)url sessionId:(NSString *_Nullable)sessionId;

- (ZMUniversalDeepLinkType)getDeepLinkType:(NSString *_Nonnull)url sessionId:(NSString *_Nullable)sessionId;
- (ZMUniversalDeepLinkInfo *_Nullable)getLinkInfo:(NSString *_Nonnull)forLink sessionId:(NSString *_Nullable)sessionId;

- (BOOL)isDeepLinkEnabledForPhase:(NS_ZOOM_MESSAGER::IDeepLinkV2Manager::FeaturePhase)phase;
- (BOOL)isDeepLinkEnabledForSessionID:(NSString *_Nonnull)sessionID messageID:(NSString *_Nullable)messageID serverTime:(long long)serverTime;

- (ZMDeepLinkEntity *_Nullable)getEntity:(NSString *_Nonnull)forLink sessionId:(NSString *_Nullable)sessionId;

- (void)makeLinkFromMessageAdapter:(ZMMessageAdapter *_Nonnull)adapter
                          callback:(void(^_Nullable)(NSString *_Nonnull, NSUInteger))callback;

- (void)approveJoinRequest:(ZMMessageAdapter *_Nonnull)message
            resultCallback:(void (^_Nullable)(UInt32 xmppResult,
                                              UInt32 joinBlockReason))resultCallback;

- (void)declineJoinRequest:(ZMMessageAdapter *_Nonnull)message
            resultCallback:(void (^_Nullable)(UInt32 xmppResult))resultCallback;

- (void)openMessage:(nonnull NSString *)messageID sessionID:(nonnull NSString *)sessionID serverTime:(unsigned long long)serverTime;
- (void)openSession:(nonnull NSString *)sessionID;

@end

#ifndef ZMShareDeepLinkProtocol
#define ZMShareDeepLinkProtocol (id <ZMDeepLinkProtocol>)ZMSharedFor(ZMDeepLinkProtocol)
#endif


#endif /* ZMDeepLinkProtocol_h */
