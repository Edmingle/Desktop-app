//
//  IZMRecordMgr.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/11/13.
//

#ifndef IZMRecordMgr_h
#define IZMRecordMgr_h

@protocol IZMRecordMgr <NSObject>

@optional
- (void)updateBacksplashIfNeeds;
- (void)setNeedUpdateRecordContent:(BOOL)needUpdate;

- (void)confirmToStartCMR;
- (void)confirmToStartLocalRecord;
- (void)startCloudRecording;
- (void)checkDocsAndWhiteboardCapture;

//MARK: Smart Recording

- (void)startCMRWithAICompanion;
- (void)onCMRSettingOptionChanged;
- (void)requestCMR;
- (void)requestLocalRecord;
- (void)requestEnableSmartRecording;
- (void)onRequestCMREnableStatusChanged;
- (void)onSmartRecordingStatusChanged;

//callback
- (void)onStartCMRRequestReceived:(NSString *)reqID sender:(ZMUserID)senderId;
- (void)onStartCMRRequestResponseReceived:(BOOL)bTimeOut decline:(BOOL)bDecline;
- (void)onEnableSmartRecordingResult:(BOOL)succ error:(long long)error_code;

@end


#endif /* IZMRecordMgr_h */
