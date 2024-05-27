//
//  ZMMessageDraftHelper.h
//  zChatUI
//
//  Created by kevin.li on 10/10/19.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ZoomKit/ZMToastCoordinator.h>

#import <zChatComponent/ZMIMCommonDefine.h>
#import <zChatComponent/ZMFileEntity.h>

@class ZMIMMessageDraft;

#ifdef __cplusplus
static constexpr NSUInteger kZMMessageDraftProtocol_saveDelay = 6;
#else
static const NSUInteger kZMMessageDraftProtocol_saveDelay = 6;
#endif // __cplusplus

@interface ZMDraftEventInfo : NSObject

@property (nonatomic, assign) NSUInteger error;
@property (nonatomic, assign) BOOL isEcho;
@property (nonnull, nonatomic, retain) NSString *sessionID;
@property (nullable, nonatomic, retain) NSString *threadID;
@property (nonnull, nonatomic, retain) NSString *draftID;
@property (nonatomic, assign) BOOL isArchival;
@property (nonatomic, assign) BOOL isLoadEvent;

@end

NSString * _Nonnull const kIM_DraftsStartScheduledEdit = @"kIM_DraftsStartSheduledEdit";

NSString *_Nonnull const kIM_DraftsSetActiveViewController = @"kIM_DraftsSetViewController";

NSString *_Nonnull const kIM_DraftsViewControllerID = @"kIM_DraftsViewController";
NSString *_Nonnull const kIM_ScheduledViewControllerID = @"kIM_ScheduledViewController";

NSString *_Nonnull const kZMMessageDraftHelperNext90WarnDefaultsKey = @"kZMDMT90pNextWarnDate";
NSString *_Nonnull const kZMMessageDraftHelperNext95WarnDefaultsKey = @"kZMDMT95pNextWarnDate";

typedef void(^ZMDraftEventCompletionHandler)(ZMDraftEventInfo *_Nonnull event);
typedef void(^ZMDraftConnectionStateCompletionHandler)(NSInteger err);
typedef void(^ZMDraftCountUpdateCompletionHandler)();

@protocol ZMMessageDraftHelperToastDelegate <NSObject>

- (void)showToast:(nonnull NSString *)toast withType:(ZMToastType)type header:(nullable NSString *)header
           target:(nullable id)target action:(nullable SEL)action actionText:(nullable NSString *)actionText
          context:(nullable id)context image:(nullable NSImage *)image;

- (void)showAttributedToast:(nonnull NSAttributedString *)toast withType:(ZMToastType)type header:(nullable NSString *)header
           target:(nullable id)target action:(nullable SEL)action actionText:(nullable NSString *)actionText
          context:(nullable id)context image:(nullable NSImage *)image;

- (void)openDraftsTab;
- (void)openScheduledTab;

@end

@protocol ZMMessageDraftProtocol <NSObject>

// util

+ (BOOL)isDraftsTabEnabled;
+ (BOOL)isScheduledMessagesEnabled;
- (NSUInteger)draftCount;
- (NSUInteger)scheduledMessageCount;
- (BOOL)isDraftLoadingDone;

// drafts

- (nonnull NSArray<ZMIMMessageDraft *> *)getAllDrafts;

- (nullable ZMIMMessageDraft *)draftForDraftID:(nonnull NSString *)draftID;

- (nonnull NSArray<ZMIMMessageDraft *> *)draftsForSession:(nonnull NSString *)sessionID;
- (nonnull NSArray<ZMIMMessageDraft *> *)activeDraftsForSession:(nonnull NSString *)sessionID;
- (nullable ZMIMMessageDraft *)activeDraftForSession:(nonnull NSString *)sessionID;
- (nullable ZMIMMessageDraft *)activeDraftForSession:(nonnull NSString *)sessionID thread:(nullable NSString *)threadID;

- (BOOL)setActiveDraft:(nullable ZMIMMessageDraft *)draft;

- (BOOL)archiveActiveDraftForSession:(nonnull NSString *)sessionID;
- (BOOL)archiveActiveDraftForSession:(nonnull NSString *)sessionID thread:(nullable NSString *)threadID;

- (BOOL)saveActiveDraft:(nonnull ZMIMMessageDraft *)draft forceCloudSync:(BOOL)forceCloudSync;
- (BOOL)saveActiveDraft:(nullable NSAttributedString *)draft sessionID:(nonnull NSString *)sessionID fileList:(nullable NSArray<ZMFileEntity *> *)fileList forceCloudSync:(BOOL)forceCloudSync;
- (BOOL)saveActiveDraft:(nullable NSAttributedString *)draft sessionID:(nonnull NSString *)sessionID threadID:(nullable NSString *)threadID threadServerTime:(unsigned long long)threadServerTime fileList:(nullable NSArray<ZMFileEntity *> *)fileList forceCloudSync:(BOOL)forceCloudSync;

- (BOOL)saveDraft:(nonnull ZMIMMessageDraft *)draft forceCloudSync:(BOOL)forceCloudSync;

- (BOOL)eraseActiveDraftForSession:(nonnull NSString *)sessionID threadID:(nullable NSString *)threadID;
- (BOOL)eraseActiveDraftWithDraftID:(nonnull NSString *)draftID;

- (BOOL)sendDraft:(nonnull ZMIMMessageDraft *)draft fromView:(NSView *_Nonnull)view;

- (BOOL)eraseDraftByID:(nonnull NSString *)draftID;
- (BOOL)eraseDraft:(nonnull ZMIMMessageDraft *)draft;
- (BOOL)eraseDrafts:(nonnull NSArray<ZMIMMessageDraft *> *)drafts;

// scheduled messages

- (nonnull NSArray<ZMIMMessageDraft *> *)getAllScheduledMessages;

- (nullable ZMIMMessageDraft *)scheduledMessageForID:(nonnull NSString *)draftID;
- (nonnull NSArray<ZMIMMessageDraft *> *)scheduledMessagesForSession:(nonnull NSString *)sessionID;

- (BOOL)scheduleDraft:(nonnull NSString *)draftID date:(nonnull NSDate *)date;
- (BOOL)cancelScheduledMessage:(nonnull NSString *)draftID;

- (BOOL)updateScheduledMessage:(nonnull ZMIMMessageDraft *)draft;
- (BOOL)updateScheduledMessage:(nonnull ZMIMMessageDraft *)draft
                     showToast:(BOOL)showToast;

- (BOOL)eraseScheduledMessage:(nonnull NSString *)draftID;

// callbacks

- (void)addDraftDeletionListener:(nonnull id)target
                      completion:(nonnull ZMDraftEventCompletionHandler)completionHandler;
- (void)removeDraftDeletionListener:(nonnull id)target;

- (void)addDraftAdditionListener:(nonnull id)target
                      completion:(nonnull ZMDraftEventCompletionHandler)completionHandler;
- (void)removeDraftAdditionListener:(nonnull id)target;

- (void)addDraftUpdateListener:(nonnull id)target
                    completion:(nonnull ZMDraftEventCompletionHandler)completionHandler;
- (void)removeDraftUpdateListener:(nonnull id)target;

- (void)addConnectionStateListener:(nonnull id)target
                        completion:(nonnull ZMDraftConnectionStateCompletionHandler)completionHandler;
- (void)removeConnectionStateListener:(nonnull id)target;

- (void)addDraftCountUpdateListener:(nonnull id)target
                         completion:(nonnull ZMDraftCountUpdateCompletionHandler)completionHandler;
- (void)removeDraftCountUpdateListener:(nonnull id)target;

- (void)addScheduledDeletionListener:(nonnull id)target
                          completion:(nonnull ZMDraftEventCompletionHandler)completionHandler;
- (void)removeScheduledDeletionListener:(nonnull id)target;

- (void)addScheduledAdditionListener:(nonnull id)target
                          completion:(nonnull ZMDraftEventCompletionHandler)completionHandler;
- (void)removeScheduledAdditionListener:(nonnull id)target;

- (void)addScheduledUpdateListener:(nonnull id)target
                        completion:(nonnull ZMDraftEventCompletionHandler)completionHandler;
- (void)removeScheduledUpdateListener:(nonnull id)target;


- (void)onConnectionStateChange:(int)err;

- (BOOL)isDraftPendingOperation:(nonnull NSString *)draftID;

@end


@interface ZMIMMessageDraft : NSObject

// NOTE: all int64_t timestamps are in *milliseconds* since epoch.

@property (nonatomic, copy, nullable)   NSAttributedString *draft;
@property (nonatomic, retain, nullable) NSArray<ZMFileEntity*> *fileList;
@property (nonatomic, copy, nullable)   NSArray<ZMMessageFontInfo*>  *fontStyleInfoList;
@property (nonatomic, assign) int64_t createdTime;
@property (nonatomic, assign) int64_t lastEditedTime;
@property (nonatomic, retain, nonnull)  NSString *sessionID;
@property (nonatomic, retain, nullable) NSString *threadID;
@property (nonatomic, assign) int64_t threadServerTime;
@property (nonatomic, assign) int64_t scheduledTime;

@property (nonatomic, retain, nonnull) NSString  *draftID;
@property (assign) BOOL isActive;
@property (assign) BOOL didFailSync;

@property (readonly) BOOL isScheduledMessage;

/* Draft display format, like "Hello. (x Files)", "Hello*********..." */
@property (nonatomic, readonly, copy, nullable) NSString *draftDesp;

- (nullable NSAttributedString *)attributedDraftDesp;

- (BOOL)hasDraft;
- (nullable NSString *)plaintextDraft;
- (nullable NSString *)plaintextDraftWithQuotes;

// does NOT add quotes by default. To add quotes, use +plaintextDraftForDraft:fontStyleInfo:addQuotes:.
+ (nullable NSString *)plaintextDraftForDraft:(nonnull NSAttributedString *)draft
                                fontStyleInfo:(nullable NSArray<ZMMessageFontInfo *> *)fontStyleInfoList;
+ (nullable NSString *)plaintextDraftForDraft:(nonnull NSAttributedString *)draft
                                fontStyleInfo:(nullable NSArray<ZMMessageFontInfo *> *)fontStyleInfoList
                                    addQuotes:(BOOL)addQuotes;


/// Plain text with custom emojis. So it has to use attributed string.
- (nullable NSAttributedString *)plainAttributedTextDraft;
/// Plain text with custom emojis. So it has to use attributed string.
- (nullable NSAttributedString *)plainAttributedTextDraftWithQuotes;

/// Plain text with custom emojis. So it has to use attributed string.
+ (nullable NSAttributedString *)plainAttributedTextDraftForDraft:(nonnull NSAttributedString *)draft
                                                    fontStyleInfo:(nullable NSArray<ZMMessageFontInfo *> *)fontStyleInfoList;
/// Plain text with custom emojis. So it has to use attributed string.
+ (nullable NSAttributedString *)plainAttributedTextDraftForDraft:(nonnull NSAttributedString *)draft
                                                    fontStyleInfo:(nullable NSArray<ZMMessageFontInfo *> *)fontStyleInfoList
                                                        addQuotes:(BOOL)addQuotes;


- (nonnull NSString *)getRecipientName;
- (BOOL)hasValidRecipient;
- (BOOL)isInE2EESession;

- (int64_t)getLastEditedTime;
- (int64_t)getScheduledTime;

@end

@interface ZMMessageDraftHelper : NSObject <ZMMessageDraftProtocol>

@property (nullable, weak) id<ZMMessageDraftHelperToastDelegate> toastDelegate;

+ (instancetype _Nonnull)sharedInstance;
// to be called at log out - invalidates the request cache and all other session-specific information.
// callback subscriptions are left unmodified.
- (void)invalidate;

+ (BOOL)hasReplyDraftWithChannelID:(NSString * _Nonnull)channelID threadID:(NSString * _Nullable)threadID;

@end
