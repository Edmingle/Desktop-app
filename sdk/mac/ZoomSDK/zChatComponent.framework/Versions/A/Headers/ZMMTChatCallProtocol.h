//
//  ZMMTChatCallProtocol.h
//  zChatComponent
//
//  Created by Devl on 1/24/24.
//

#ifndef ZMMTChatCallProtocol_h
#define ZMMTChatCallProtocol_h

NS_ASSUME_NONNULL_BEGIN

@class ZMBuddyAdapter;
@class ZMMTBuddyModel;
@protocol ZMMTChatCallProtocol <ZMRoutableObject>

- (BOOL)mtChatCanChat:(NSString*)sessionID;
- (BOOL)mtChatCanSendFile;
- (BOOL)mtChatAmIHostCohost;
- (BOOL)mtChatInSilentMode;
- (BOOL)mtChatIsTeamChatEnabled;
- (BOOL)mtChatNeedShowEveryone:(NSString*)sessionID;

- (BOOL)mtChatCheckError:(NSString*)sessionID threadID:(NSString*)threadID;
- (BOOL)mtChatCanSendTo:(NSString*)guid inSession:(NSString*)sessionID msgType:(NSInteger)msgType;
- (void)mtChatSelectChatTo:(NSDictionary*)info;

- (BOOL)mtChatCheckFileSizeFailed:(unsigned long long)size;
- (BOOL)mtChatCheckFileTypeFailed:(NSString*)path;
- (unsigned long long)mtChatGetMaxFileSize;

- (NSInteger)mtChatGetSendMsgType;
- (NSString*)mtChatGetSendUserID;
- (NSString*)mtChatGetAccountID;
- (NSString*)mtChatGetCurrentSessionID;
- (NSWindow*)mtChatGetMainWindow;

- (NSInteger)mtChatGetPlistCount:(NSString*)sessionID;
- (NSString*)mtChatGetSendUserID:(NSString*)sessionID threadID:(NSString*)threadID;
- (NSInteger)mtChatGetSendMsgType:(NSString*)sessionID threadID:(NSString*)threadID;
- (NSInteger)mtChatGetMsgNodeID:(NSString*)sessionID threadID:(NSString*)threadID;

- (NSImage*)mtChatGetAvatarByInfo:(ZMMTBuddyModel *)buddy msgType:(NSInteger)msgType;
- (NSImage*)mtChatGetAvatarByJID:(NSString*)jid name:(NSString*)name msgType:(NSInteger)msgType;
- (NSImage*)mtChatGetMyAvatar;

#ifdef __cplusplus
- (std::set<CString>)mtChatGetUserList:(NSString*)sessionID;
#endif

- (void)mtChatLoadChatDBReady;
- (void)mtChatLoadChatDataReady;

- (void)mtChatShowDeletedByDlpAlert;

@end

NS_ASSUME_NONNULL_END

#endif /* ZMMTChatCallProtocol_h */
