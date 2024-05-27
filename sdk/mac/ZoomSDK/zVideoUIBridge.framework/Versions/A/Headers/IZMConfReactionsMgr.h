//
//  IZMConfReactionsMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/13/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMConfReactionsMgr_h
#define IZMConfReactionsMgr_h

NS_ASSUME_NONNULL_BEGIN

@class ZMUser, ZMConfReactionsMenuItem, ZMMTEmojiMenuItem, ZMSysEmojiMgr, ZMMTReactionsBarrageViewController;

typedef NS_ENUM(NSUInteger, ZMWebinarEmojiReactionType) {
    ZMWebinarEmojiReactionTypeFull,
    ZMWebinarEmojiReactionTypeCompact,
    ZMWebinarEmojiReactionTypeHidden
};

typedef NS_ENUM(NSUInteger, ZMReactionGestureType) {
    ZMReactionGestureTypeNone = 0,
    ZMReactionGestureTypeThumbsup = 1,
    ZMReactionGestureTypeHand = 2,
};

@protocol IZMConfReactionsMgr <ZMRoutableObject>

- (ZMSysEmojiMgr *)sysEmojiMgr;
- (NSDictionary *)webinarEmojisDic;
- (ZMWebinarEmojiReactionType)webinarReactionType;
- (ZMReactionGestureType)reactionGestureType;

- (ZMMTReactionsBarrageViewController *)newViewControllerWithType:(ZMMTType)type;

/** user emoji reaction changed callback */
- (void)onEmojiReactionReceived:(ZMUser *)user emoji:(NSString *)emoji;

- (nullable NSImage *)reactionImageWithUser:(ZMUser *)user size:(CGFloat)size desc:(NSString *_Nullable *_Nullable)desc;
- (nullable NSImage *)feedbackImageWithUser:(ZMUser *)user size:(CGFloat)size desc:(NSString *_Nullable *_Nullable)desc;
- (nullable NSImage *)feedbackIconWithUser:(ZMUser *)user size:(CGFloat)size desc:(NSString *_Nullable *_Nullable)desc;
/** draw a emoji to image */
- (nullable NSImage *)emojiImageWithString:(NSString *)string size:(CGFloat)size desc:(NSString *_Nullable *_Nullable)desc;
/** draw a single feedback image type: CMM_NONVERBAL_FEEDBACK */
- (nullable NSImage *)feedbackIconWithType:(int)type size:(CGFloat)size desc:(NSString *_Nullable *_Nullable)desc;


- (ZMConfReactionsMenuItem *)getReactionsMenuItem;
- (ZMMTEmojiMenuItem *)getReactionsMoreEmojiMenuItem;
/** get local skin tone reaction emojis */
- (NSArray <NSDictionary *>*)localSkinToneEmojis;
- (NSArray <NSDictionary *>*)localSkinToneDynamicEmojis;
/** get local skin tone for raise hand emoji */
- (nullable NSString *)localSkinToneRaiseHand;
/** get raise hand emoji for skin tone */
- (BOOL)isDynamicEmojiMoreMenu;
/** get floating emoji more menu flag */
#ifdef __cplusplus
- (nullable NSString *)raiseHandEmojiWithSkinTone:(CmmEmojiReactionSkinTone)skinTone;
#endif

- (void)eventTrackingWithSubEvent:(int)subEvent;

- (nullable NSString *)reactionForUser:(ZMUser *)user;

- (void)interpreterInfoChanged;
// reactions in webinar
- (void)onEmojiReactionReceivedInWebinar:(NSDictionary *)reactionsDic confSession:(ZMConfSession *)confSession ;
- (void)updateReactionViewWithType:(ZMWebinarEmojiReactionType)type;

// reaction gesture
- (void)receiveHandGestureWithType:(NSInteger)type;
- (void)onReactionAwareness:(BOOL)isEnable;
- (BOOL)isInstalledForAomhost;
- (void)toggleHandGestureSetting;

//Lottie
- (nullable NSString *)lottieAnimationNameForUser:(ZMUser *)user;
- (nullable NSString *)lottieAnimationNameForReaction:(NSString *)reaction;

// [ZOOM-426408] Raise Hand Improvements
- (void)activeAudioChanged;


@end

NS_ASSUME_NONNULL_END

#endif /* IZMConfReactionsMgr_h */
