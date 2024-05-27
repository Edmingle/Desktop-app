//
//  ZMRecordHelper.h
//  VideoUI
//
//  Created by geno.chen on 2021/11/13.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZMRecordHelper : ZMBaseHelper

#pragma mark - API for both local recording and CMR

/**
 * This API also have two functions:
 * If CanStartCMR() && IsCMRInProgress() && bStopCMR is true, will try to stop CMR
 * If local record is running, it will also try to stop local record
 * New user should use new API StopLocalRecord() or StopCMR() to instead
 */
- (BOOL)stopRecord:(BOOL)stopCMR;
/** Equal to IsLocalRecordingInProgress() || IsCMRInProgress() */
- (BOOL)isRecordingInProgress;
/**
 * Is someone is recording the meeting by local record or CMR
 * if only CMR is recording and CRM is connecting or paused, it will return false
 * if only one user is local recording, and the local recording is paused, it will return false
 */
- (BOOL)theMeetingisBeingRecording;
- (BOOL)needPromptRecordingDisclaimer;
- (void)agreeContinueRecording;
- (void)disagreeContinueRecording;
- (BOOL)isMyRecordIndicatorAvailable;
- (BOOL)isMeetingHasLocalRecording;

#pragma mark - API only for local recording
- (BOOL)startLocalRecord:(NSString *)recordPath videoList:(PSSB_MC_DATA_BLOCK_RECORDING_SELECTTED_USERS)videoList;
- (BOOL)stopLocalRecord;
- (BOOL)pauseLocalRecord;
- (BOOL)resumeLocalRecord;
- (CMM_RECORD_STATUS)getLocalRecordStatus;
/** Equal to GetLocalRecordStatus() == CMM_RECORD_STATUS_START */
- (BOOL)isLocalRecordStarted;
/** Equal to GetLocalRecordStatus() == CMM_RECORD_STATUS_PAUSE */
- (BOOL)isLocalRecordPaused;
/** Equal to GetLocalRecordStatus() == CMM_RECORD_STATUS_STOP */
- (BOOL)isLocalRecordStoped;

- (BOOL)canStartLocalRecord;
- (BOOL)setImmersiveSceneInfo:(SSB_MC_DATA_BLOCK_RECORDING_IMMERSIVE_INFO)info;
/** Equal to GetLocalRecordStatus() == CMM_RECORD_STATUS_START || GetLocalRecordStatus() == CMM_RECORD_STATUS_PAUSE */
- (BOOL)isLocalRecordingInProgress;
/** save the active video user ID, seems not used any more */
- (BOOL)setActiveVideo:(ZMUserID)userID;
- (ZMUserID)getActiveVideo;
- (BOOL)setRecordRootPath:(NSString *)path;
- (NSString *)getCurrentRecPath;
- (BOOL)setRecordContentList:(PSSB_MC_DATA_BLOCK_RECORDING_SELECTTED_USERS)videoList;
- (BOOL)setScreenResolution:(NSUInteger)resolution;
- (BOOL)isShowNameInLocalRecordEnabled;

#pragma mark - API only for CMR
- (BOOL)startCMR;
- (BOOL)stopCMR;
- (BOOL)pauseCMR;
- (BOOL)resumeCMR;
- (CMM_RECORD_STATUS)getCMRStatus;
/** Equal to GetCMRStatus() == CMM_RECORD_STATUS_START */
- (BOOL)isCMRStarted;
/** Equal to GetCMRStatus() == CMM_RECORD_STATUS_PAUSE */
- (BOOL)isCMRPaused;
/** Equal to GetCMRStatus() == CMM_RECORD_STATUS_STOP */
- (BOOL)isCMRStoped;
/**
 * Check if I have the privilege to control CMR
 * Note: New user should use CanControlCMR() to instead this function
 */
- (BOOL)canStartCMR;
/** Check if can Start/Pause/Resume/Stop CMR */
- (BOOL)canControlCMR;
/**
 * For history compatible issue, this function have two conditions: I can control CMR and the status of CMR is not stop
 * Equal to CanStartCMR() && (GetCMRStatus() == CMM_RECORD_STATUS_CONNECTING ||  GetCMRStatus() == CMM_RECORD_STATUS_START || GetCMRStatus() == CMM_RECORD_STATUS_PAUSE)
 * Note: New user should use GetCMRStatus() and CanControlCMR() to instead this function
 */
- (BOOL)isCMRInProgress;
/** Equal to GetCMRStatus() == CMM_RECORD_STATUS_CONNECTING */
- (BOOL)isCMRInConnecting;

/** Is meeting recording by CMR, equal to GetCMRStatus() == CMM_RECORD_STATUS_START || GetCMRStatus() == CMM_RECORD_STATUS_PAUSE */
- (BOOL)recordingMeetingOnCloud;

- (void)updateUserNameDataForLoacalRecord:(const CmmRecordUserNameData&)data;
- (void)updateUserAvatarForLocalRecord:(const SSB_MC_DATA_BLOCK_RECORD_USER_AVATAR &)data;
- (void)updateBacksplashForLoacalRecord:(const SSB_MC_DATA_BLOCK_BACK_SPLASH_PIC&)info;

@end


@interface ZMRecordHelper (OthersAPI)

- (void)setRecordPath:(NSString *)recordPath;
- (BOOL)isCMRReminderEnabled;
/** Only show recording indicator to who is being recorded, others who won’t be recorded cannot see the recording indicator. */
- (BOOL)isHostOnlyCMREnabled;
- (BOOL)isAutoCMRForbidManualStop;
- (BOOL)needPromptStartRecordingDisclaimer;
- (BOOL)canCMRUpgrade;
- (nullable NSURL *)getRecordingManagementURL;
- (BOOL)isPlayRecordVoiceNoti;
- (BOOL)isRecordDisabled;
- (BOOL)isLocalRecordDisabled;
- (BOOL)isSupportLocalRecordSecuritySettings;
- (BOOL)isRequestLocalRecordPermissionEnabled;
- (BOOL)isStartLocalRecordingDisabled;
- (BOOL)isRequestLocalRecordingPermissionDisabled;
- (BOOL)isRecordOperationDisabled;

//ZOOM-340709
- (BOOL)isKiwiRecordingEnable;
- (BOOL)getSalesRecordingAnalytics;
- (void)setSalesRecordingAnalytics;
- (void)setSalesRecordingAnalytics:(BOOL)isOn;
- (BOOL)isUseOldZRAEnabled;

#pragma mark - combination
- (BOOL)isRecordingPaused;
- (BOOL)canStartRecording;
- (BOOL)canStopRecording;
- (BOOL)canPauseRecording;
- (BOOL)canResumeRecording;

//MARK: Smart recording
//bit
- (BOOL)isSmartRecordingEntranceEnabled;
- (BOOL)isSmartRecordingEnable;
- (BOOL)isSmartRecordingLocked;
- (BOOL)isAudioTranscriptRecordingEnabled;
- (BOOL)isAudioTranscriptRecordingLocked;
- (CHANGE_WEB_SETTING_STRATEGY)getSmartRecordingEnableStrategy;

//util
- (BOOL)isCMRWithSmartRecordingEnabled;
- (BOOL)canEnableSmartRecording;
- (BOOL)canEnableSmartRecordingInMeeting;
- (BOOL)canRequestEnableSmartRecording;
- (BOOL)isMeetingSupportCMR;
- (BOOL)canRequestStartCMR;
- (BOOL)hasSupportEnableSmartRecordingAdmin;
- (NSString *)getSmartRecordingSettingLink;

- (BOOL)isSupportRequestCMRControl;
- (void)setAllowRequestHostStartCMRStatus:(BOOL)state;
- (BOOL)isAllowRequestHostStartCMR;
- (BOOL)isAllowRequestHostStartCMRLocked;
- (BOOL)isHostInLocalRecord;
- (BOOL)isHostSupportRequestStartCMR;

@end

NS_ASSUME_NONNULL_END
