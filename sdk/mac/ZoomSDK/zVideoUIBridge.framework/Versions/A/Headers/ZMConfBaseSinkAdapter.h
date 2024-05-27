//
//  ZMConfBaseSinkAdapter.h
//  VideoUI
//
//  Created by Francis Zhuo on 2/22/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMUser.h>
#import <zVideoUIBridge/ZMMTRosterList.h>
NS_ASSUME_NONNULL_BEGIN

@class ZMConfSession;
@interface ZMConfBaseSinkAdapter : NSObject
@property (nonatomic, weak) ZMConfSession* confSession;
@property (assign) BOOL isLeavingMeeting;

+ (instancetype)adapterWithSession:(ZMConfSession*)confSession;

- (void)registerPolicyObserver;

- (ZMUser*)userWithID:(ZMUserID)userID;
@end

@interface ZMConfBaseSinkAdapter (User)
- (BOOL)onUserStatusChanged:(USER_CMD)cmd userID:(CMM_USERID)userID;
- (BOOL)onBatchUserStatusChanged:(USER_CMD)cmd list:(CmmUserChangeStatus*_Nullable*_Nullable)list number:(CmmUInt32)num;
- (void)onMyRosterCompleted;

//for overwriting
- (BOOL)onUserStatusChanged:(USER_CMD)cmd user:(ZMUser*)zmUser userID:(CMM_USERID)userID;

- (BOOL)onAudioStatusChanged:(CmmUserChangeStatus*_Nullable*_Nullable)list number:(CmmUInt32)num;
- (BOOL)onRosterChanged:(CmmUserChangeStatus*_Nullable*_Nullable)list number:(CmmUInt32)num;
- (BOOL)onKBRosterChanged:(CmmUserChangeStatus*_Nullable*_Nullable)list number:(CmmUInt32)num;
@end

@interface ZMConfBaseSinkAdapter (ConfStatus)
- (void)onConfReady:(CmmUInt32)result;

- (BOOL)onConfStatusChanged:(const CONF_STATUS)eStatus;
- (BOOL)onConfStatusChanged:(CONF_CMD)cmd params:(CmmUInt32)ret;

#pragma mark -
- (void)notifyGetSpotAppid:(NSString*)appid;

#pragma mark -
- (void)onAudioObjCreated;
- (void)onVideoObjCreated;
- (void)onShareObjCreated;
- (void)onRecordObjCreated;
- (void)onLTTObjCreated;
@end

@interface ZMConfBaseSinkAdapter (Device)

- (BOOL)onDeviceStatusChanged:(DEVICE_CMD)cmd ret:(CmmUInt32)ret handle:(CmmUInt32)handle;
- (BOOL)showMyAudioLevel:(CmmUInt32)level handle:(CmmUInt32)handle isMic:(CmmBool)isMic;
- (BOOL)onVolumeChange:(CmmUInt32)vol isMic:(CmmBool)isMic;
- (void)onAudioDeviceSpecialInfoChange:(SSB_MC_DEVICE_SPECIAL_INFO)special_info deviceInfo:(CmmAudioDeviceBriefInfo)adbi;
- (void)onUltraSoundDetect_PairCode:(CmmBool)is_timeout code:(const CAString&)pair_code;
- (void)OnDeviceStatelessButtonDown:(const CString&)device_id;

#pragma mark - ICmmConfUIAPI
- (void)onMyVideoDeviceRunStarted:(void*)hWnd type:(CMM_MY_VIDEO_RUN_TYPE)eRunType device:(PMediaDevice)pDeviceInfo;
- (void)onMyCameraCaptureSizeRatioChanged:(const CString&)cameraID fWidth2Height:(float)fWidth2Height;
@end

@interface ZMConfBaseSinkAdapter (Share)

- (void)onShareCaptureStatusChanged:(SSB_MC_AS_SPECIAL_MSG)msg
                             reason:(SSB_MC_AS_CAPTURING_STATUS)reason
                               data:(DWORD)data;
- (void)onShareAnnotationStatusChanged:(SSB_MC_ANNOTATION_NOTIFICATION)msg
                                  data:(DWORD)data;
- (void)onShareAnnotationStatusChanged:(SSB_MC_ANNOTATION_NOTIFICATION)msg
                            renderView:(void *)renderView
                                  data:(DWORD)data;
- (void)onRemoteSupportRequestReceived:(CMM_USERID)nUserFrom
                               cmdType:(SUPPORT_CMD_TYPE)cmdType;
- (void)onRemoteSupportResponseReceived:(CMM_USERID)nUserFrom
                                cmdType:(SUPPORT_CMD_TYPE)cmdType
                              bApproved:(CmmBool)bApproved;
- (void)onOnRemoteSupportNotificationReceived:(CMM_USERID)nUserFrom
                                      cmdType:(SUPPORT_NOTIFICATION_TYPE)cmdType;

- (void)onShareRenderEventWithType:(RENDER_EVENT_TYPE)type
                       shareRender:(ICmmShareView *)shareRender
                              data:(void *)data
                              size:(int32_t)size;
- (void)onProctoringModeContextChanged:(CmmProctoringModeContext)old_context new_context:(CmmProctoringModeContext)new_context;
@end

@interface ZMConfBaseSinkAdapter (ClosedCaption)
- (BOOL)onClosedCaptionMessageReceived:(const CString&)msgID
                               content:(const CString&)content
                                  time:(const Cmm::CTime&)timer;
- (BOOL)onRealtimeClosedCaptionMessageReceived:(const CString&)content;
- (BOOL)onLiveTranscriptionClosedCaptionMessageReceived:(const CString&)msgID
                                                   type:(CmmClosedCaption::CCOperationType)type;
- (void)onStartLiveTranscriptRequestReceived:(CMM_USERID)nUserFrom bAnonymous:(CmmBool)bAnonymous;

- (void)onAvailableFreeTrialInfoReceived:(BOOL)bSuccess;
@end

@interface ZMConfBaseSinkAdapter (VideoOrder)
- (void)onGalleryVideoOrderSaved:(BOOL)ret;
- (void)onGalleryVideoOrderLoaded:(const CString&)data;
- (void)onDynamicLayoutChanged;
@end

@interface ZMConfBaseSinkAdapter (VideoRender)
- (void)onVideoRenderEventWithType:(RENDER_EVENT_TYPE)type
                       videoRender:(ICmmVideoRender *)videoRender
                              data:(void *)data
                              size:(int32_t)size;
@end

@interface ZMConfBaseSinkAdapter (Chat)
- (void)onChatMessageReceived:(const CString&)msgID;
- (void)onChatSendFile:(const CString&)msgID result:(CmmUInt32)result;
- (void)onChatFileProgress:(const CString&)msgID ratio:(CmmUInt32)ratio completeSize:(CmmUInt32)size speed:(CmmUInt32)bitPerSecond;
- (void)onChatFileStateChange:(const CString&)msgID;
- (void)OnChatShareFileInMeetingChat:(const ShareFileInMeetingChatParam_s&)shareFileInfo;
- (void)OnChatGetPublicDownloadLink:(const CString&)messageID result:(CmmUInt32)result;
- (void)OnChatMessageDeleted:(const CString&)msgId deleteBy:(CHAT_DELETE_BY)deleteBy;
@end

@interface ZMConfBaseSinkAdapter (Policy)
- (void)policyUpdated:(zpref::zPolicyId)policy;
@end

@interface ZMConfBaseSinkAdapter (Invite)
- (void)onMeetingCallReplyInfo:(const MeetingCallReplyInfo&)info;
@end

@interface ZMConfBaseSinkAdapter (Immersive)
- (void)onVideoLayoutDownload:(const CString&)layoutID xmlPath:(const CString&)xmlPath retCode:(CmmUInt32)retCode progress:(CmmUInt32)progress;
@end

@interface ZMConfBaseSinkAdapter (CameraControl)
- (void)onControllableCameraAdded:(CMM_USERID)userID;
- (void)onControllableCameraRemoved:(CMM_USERID)userID;
- (void)onCameraControlGroupAdded:(CMM_USERID)userID error:(FECCGroupAddmemberError)error;
- (void)onCameraControlGroupRemoved:(CMM_USERID)userID success:(CmmBool)success;
@end

@interface ZMConfBaseSinkAdapter (Simulive)
- (void)onSimuliveWebinarAutoReplyStatusChanged:(CmmBool)autoReply replyText:(const CString&)replyText;
- (void)onSimuliveMasterVideoPlayerChanged:(CmmUInt32)originalUJID nowUJID:(CmmUInt32)nowUJID;
@end

@interface ZMConfBaseSinkAdapter (ZoomIQ)
- (void)onQueryRequestResponseReceived:(CmmBool)is_timeout response:(const CmmQueryRequestResponse&)response;
- (void)onReceiveRequestToEnableSummaryMsg:(CMM_USERID)senderId;
- (void)onReceiveRequestToStartSummaryMsg:(const CString&)reqId senderId:(CMM_USERID)senderId;
- (void)onReceiveStartSummaryRspMsg:(CmmBool)bTimeOut decline:(CmmBool)decline;

- (void)onSummaryFeatureOnStatusChanged:(CmmBool)summaryEnabled;

- (void)onReceiveRequestToEnableQueriesMsg:(CMM_USERID)senderId;
- (void)onReceiveRequestToStartQueriesMsg:(const CString&)reqId senderId:(CMM_USERID)senderId;
- (void)onReceiveStartQueryResponseMsg:(CmmBool)agree timeout:(CmmBool)timeout;
- (void)onQuerySwitchStatusChanged:(CmmBool)enable;

- (void)onReceiveSwitchAICResponseMsg:(CmmBool)timeout agree:(CmmBool)agree switchAction:(NSInteger)switchAction;
- (void)onReceiveSwitchAICRequestMsg:(const CString&)reqId senderId:(CMM_USERID)senderId aicOption:(CmmInt64)aicOption switchAction:(NSInteger)switchAction;

@end

@interface ZMConfBaseSinkAdapter (Companion)
- (void)onLeaveCompanionModeReqReceived:(CMM_USERID)senderId;
- (void)onLeaveCompanionModeRspReceived:(CMM_USERID)senderId agree:(CmmBool)agree;
@end

@interface ZMConfBaseSinkAdapter (Reaction)
- (void)onEmojiReactionReceived:(CMM_USERID)senderId emojiContent:(const CString&)emoji_content;
- (void)onEmojiReactionReceived:(CMM_USERID)senderId reactionType:(CmmEmojiReactionType)type reactionSkinTone:(CmmEmojiReactionSkinTone)skin;
- (void)onEmojiReactionReceivedInWebinar:(const EmojiContentMap &)emoji_contents;

@end

@interface ZMConfBaseSinkAdapter (MultipleCMA)
- (void)onCMARegionStatusChanged:(const CString&)region status:(archive_gw_status)status;
@end

@interface ZMConfBaseSinkAdapter (CMR)
- (void)onEnableSmartRecordingResult:(CmmBool)succ error:(CmmInt64)error_code;
- (void)onStartCMRRequestReceived:(const CString&)reqID sender:(CMM_USERID)senderId;
- (void)onStartCMRRequestResponseReceived:(CmmBool)bTimeOut decline:(CmmBool)bDecline;
@end

@interface ZMConfBaseSinkAdapter (GalleryPlus)
- (void)onGalleryPlusWallpaperChanged:(CMM_USERID)sender_id wallpaperID:(const CString&)wallpaper_id;
- (void)onGalleryPlusTransparencyChanged:(CMM_USERID)sender_id transparency:(NSInteger)transparency;

@end

NS_ASSUME_NONNULL_END
