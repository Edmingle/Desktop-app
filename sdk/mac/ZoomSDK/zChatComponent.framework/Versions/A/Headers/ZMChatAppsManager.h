//
//  ZMChatAppsManager.h
//  zChatComponent
//
//  Created by Yong Zhou on 9/7/22.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMChatAppsEntity.h>

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const kNotificationComposeShortcutIconUpdated;
extern NSNotificationName const kNotificationComposeShortcutUpdated;
extern NSNotificationName const kNotificationThreadShortcutUpdated;

extern NSString * const ZMIMComposeShortcutIconUpdatedBotID;

@interface ZMChatAppsManager : NSObject

@property (nonatomic, retain, readonly) NSArray<ZMChatAppInfo*> *chatAppComposeShortcuts;
@property (nonatomic, retain, readonly) NSArray<ZMChatAppShortcutInfo*> *chatMessageShortcuts;
@property (nonatomic, retain, readonly) NSArray<ZMChatAppShortcutInfo*> *chatMessageSystemShortcuts;
@property (nonatomic, retain, readonly) NSDictionary<NSString *, ZMChatAppInfo *> *composeChatAppInfoMap;

+ (instancetype)sharedInstance;

/// will create a new ZMChatAppInfo instance and copy from cached object.
- (ZMChatAppInfo *__nullable)composeChatAppWithRobotJid:(NSString *)robotJid;

- (void)onComposeShortcutUpdated;

- (void)onComposeShortcutIconUpdatedWithID:(NSString *)botID;

- (void)onMessageShortcutUpdated;

- (void)onThreadShortcutUpdated;

+ (void)releaseInstance;

+ (BOOL)isAiFeatureEnabledForSession:(NSString *)sessionId;

- (NSArray<ZMChatAppInfo *> *)chatAppComposeShortcutsWithSessionId:(NSString *)sessionId;
- (NSArray<ZMChatAppShortcutInfo *> *)chatAppThreadShortcutsWithSessionId:(NSString *)sessionId;
- (NSArray<ZMChatAppShortcutInfo *> *)chatMessageShortcutsWithSessionId:(NSString *)sessionId;
- (NSArray<ZMChatAppShortcutInfo *> *)chatMessageSystemShortcutsWithSessionId:(NSString *)sessionId;

@end

NS_ASSUME_NONNULL_END
