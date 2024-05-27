//
//  ZMMTCCHelper.h
//  VideoUIBridge
//
//  Created by martin.yu on 10/25/22.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

#ifdef __cplusplus
class ICmmUser;
#endif

#ifdef __cplusplus
extern "C" {
#endif
ZMConfSession *ZMMTCCGetCurrentConfSession(void);
#ifdef __cplusplus
}
#endif

@interface ZMMTCCHelper : ZMBaseHelper

- (BOOL)hasClosedCaption;
- (BOOL)hasManualTranscription; // ZOOM-322516
- (BOOL)isManualCaptionEnabled;
- (BOOL)isAICMultipleLanguageEnabled; //ZOOM-612520
- (BOOL)allowHostToAssignCCEditor; // ZOOM-322516
- (BOOL)is3rdPartCCServerAvailable;
- (nullable NSString *)getClosedCaptionGatewayURL;
- (BOOL)hasLiveTranscription;
- (BOOL)isLiveTranscriptionEnabled;

- (BOOL)canShowCCButton;
- (BOOL)isSaveCCFeatureOn; //ZOOM-469179
- (BOOL)canSaveClosedCaption; //ZOOM-40173
- (BOOL)canShowChangeLanguageTip; //ZOOM-612520
- (BOOL)saveCaptions;
- (nullable NSString *)getCurrentRecPath;

- (BOOL)isClosedCaptionLegalNoticeAvailable;

- (BOOL)grabCCEditorRole;
- (BOOL)isCCEditorAssigned;
- (BOOL)isCCEditor;
#ifdef __cplusplus
- (nullable ICmmUser *)getClosedCaptionEditorUser;
#endif

// ZOOM-268562
- (BOOL)canViewFullTranscript;

// ZOOM-283768
- (BOOL)isMultiLanguageTranscriptionEnabled;
- (BOOL)canAssignCCEditor;

// ZOOM-319811
- (BOOL)isLTTTextLiveTranslationEnabled;

// ZOOM-423983
- (BOOL)isMMRSupportTemporarilyDisableLTTCaptions;
- (void)temporarilyDisableCaptions:(BOOL)bDisable;
- (BOOL)isCaptionsTemporarilyDisabled;

// ZOOM-423978
- (BOOL)needSetSpeakingLanguageForSubscription:(BOOL)bEnableTranslation;
- (BOOL)needApplyForAllWhenChangingSpeakingLanguage;
- (BOOL)isLTTTextTranslationStarted;

// ZOOM-439505
- (BOOL)isCaptionsStartedWhenRestricted;

// ZOOM-524794
- (BOOL)isAllowShowCaptions;
- (BOOL)isAllowRequestCaptions;
- (BOOL)sendStartLTTRequest:(BOOL)bEnableTranslation;
- (BOOL)approveStartLTTRequest;

// ZOOM-561362
- (BOOL)isSupportLockCaptionLanguage;
- (BOOL)hostLockSpeakingLanguage:(BOOL)locked;
- (BOOL)isSpeakingLanguageLockedByHost;

- (BOOL)isShowOriginalAndTranslatedTextEnabled;
- (void)enableShowOriginalAndTranslatedText:(BOOL)bEnabled;

- (void)enableManualCaptionerAutomaticallyIfNeeded;
- (void)enableOrDisableManualCaptioner:(BOOL)bEnabled;

// ZOOM-578268
- (void)setShowCaptionsConfOption:(BOOL)isOn;
- (BOOL)getShowCaptionsConfOption;

- (BOOL)isTextSubscriptionOn;

- (BOOL)setMeetingSpeakingLanguageWithLID:(int)languageID;
- (BOOL)setMeetingSpeakingLanguageForAllWithLID:(int)languageID;
- (BOOL)setTextTranslationLanguageWithLID:(int)languageID;
- (BOOL)setRSGWSpeakingLanguage:(int)languageID;

- (BOOL)enableSpeakingLanguageDetect:(BOOL)bEnable;

// ZOOM-614238
- (NSString *)convertLanguageIDToLetterLangCode:(int)languageID;
- (BOOL)isNormalASRLIDEnabled;
- (BOOL)isHQASRLIDEnabled;

// ZOOM-630080
- (BOOL)hasTranslationFreeTrial;
- (BOOL)canShowFreeTrialTip;
- (void)increaseFreeTrialTipShowCount;
- (BOOL)isLastChanceToShowTrialTip;
- (void)getFreeTrialTipTitle:(NSString *_Nonnull *_Nonnull)outTitle
                 description:(NSString *_Nonnull *_Nonnull)outDescription;
- (BOOL)requestToTryTranslatedCaption;
- (BOOL)isTextTranslationFreeTrialEnabled;
- (BOOL)hasTranslationUpsellLink;
- (nullable NSString *)translationUpsellLink;

- (BOOL)needPromptCaptionsDisclaimer;
- (void)agreeCaptionsDisclaimer:(BOOL)bAgree;
- (BOOL)needShowTipsForCaptions;

@end

NS_ASSUME_NONNULL_END
