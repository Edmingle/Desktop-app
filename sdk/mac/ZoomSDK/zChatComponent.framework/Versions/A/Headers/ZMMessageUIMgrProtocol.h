//
//  ZMMessageUIMgrProtocol.h
//  zChatComponent
//
//  Created by Kevin Li on 2022/8/5.
//

#ifndef ZMMessageUIMgrProtocol_h
#define ZMMessageUIMgrProtocol_h

@class ZMFileEntity, ZMMessageAdapter, ZPZAppHeader, ZMChatAppShortcutInfo, ZMChatAppContext;
@protocol ZMMessageUIMgrProtocol

- (void)tryToCreateDocWithType:(NSInteger)type sessionID:(nullable NSString*)sessionID threadID:(nullable NSString*)threadID nodeID:(nullable NSString*)nodeID;
- (BOOL)tryToShareWithMessage:(nullable ZMMessageAdapter *)message;
- (void)uploadLocalSharePointFileInSession:(nullable NSString*)sessionID threadID:(nullable NSString*)threadID nodeID:(nullable NSString*)nodeID;
- (void)didGetRootNodeInfoWithSessionID:(nullable NSString*)sessionID rootNodeID:(nullable NSString*)nodeID requestID:(nullable NSString*)requestID;

- (nullable NSWindow *)mainIMResponsibleWindow;

- (BOOL)isChatWindow:(nonnull NSWindow *)window;

- (nullable NSView *)chatTabView;

- (void)checkSessionForEmitterFeature:(nonnull NSString *)sessionId onView:(nonnull NSView *)onView;
- (void)removeEmitterWith:(nonnull NSString*)sessionId;
- (void)removeAllHitEmitter;

- (void)showFileSharePannelByFileItem:(nonnull ZMFileEntity *)fileItem sessionID:(nullable NSString*)sessionID onWindow:(nonnull NSWindow*)inWindow;

- (void)showFileSharePannelBySessionID:(nonnull NSString*)sessionID andMsgID:(nonnull NSString*)MsgId onWindow:(nonnull NSWindow*)inWindow;

- (void)showDisbandChannelPanel:(nonnull NSString *)channelId onWindow:(nullable NSWindow*)inWindow;

- (void)showEvent:(nonnull NSString *)meetingId meetingTopic:(nullable NSString *)meetingTopic meetingNumber:(long long)meetingNumber rect:(NSRect)rect positioningView:(nonnull NSView *)positioningView preferredEdge:(NSRectEdge)preferredEdge;

@end


#ifndef ZMShareMessageUIMgrProtocol
#define ZMShareMessageUIMgrProtocol (id <ZMMessageUIMgrProtocol>)ZMSharedFor(ZMMessageUIMgrProtocol)
#endif

#endif /* ZMMessageUIMgrProtocol_h */
