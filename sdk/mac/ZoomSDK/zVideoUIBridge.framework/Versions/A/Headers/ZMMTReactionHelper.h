//
//  ZMMTReactionHelper.h
//  VideoUIBridge
//
//  Created by Vinson Wang on 2023/8/14.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTReactionHelper : ZMBaseHelper

- (BOOL)isUseAllEmojis;

- (BOOL)isFeedbackEnabled;

- (BOOL)isEmojiReactionEnabled;

- (BOOL)canSendDynamicEmojis;

- (BOOL)isDynamicEmojiEnabled;

- (BOOL)isEmojiAudibleReactionEnabled;

- (BOOL)isSupportSkinTone;

// type: CMM_NONVERBAL_FEEDBACK
- (NSUInteger)feedbackCountWithType:(int)type;

- (NSUInteger)raiseHandCount;

- (BOOL)canClearAllFeedback;

- (BOOL)isWebinarEmojiReactionEnabled;

- (void)SetAllowWebinarEmojiReaction:(BOOL)allow;

- (BOOL)isAllowWebinarEmojiReactionEnabled;

- (BOOL)isShowMyReactionOnToolbarEnabled;

- (BOOL)isHandGestureCaptureEnabledOfLocalSetting;

- (BOOL)isHandGestureCaptureEnableOfWebSettingAndLocalSupport;

- (BOOL)isMeetingAnimatedReactionsAvaiable;

- (BOOL)isMeetingAnimatedReactionsEnable;

- (BOOL)isLottieEnable;

// [ZOOM-426408] Raise Hand Improvements
- (BOOL)isRaiseHandImprovementsAvaiable;

- (BOOL)isRaiseHandButtonSeparatedFromReactions;

- (BOOL)isPlayChimeWhenRaiseHand;

- (void)setIsPlayChimeWhenRaiseHand:(BOOL)isPlayChime;

@end

NS_ASSUME_NONNULL_END
