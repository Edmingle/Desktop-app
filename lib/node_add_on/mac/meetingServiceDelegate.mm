

#import "meetingServiceDelegate.h"
#include "zoom_node_addon.h"
#include "sdk_native_error.h"
extern ZNativeSDKWrap _g_native_wrap;

@interface meetingServiceDelegate()
@property(nonatomic,retain)ZoomSDKRetrieveSMSVerificationCodeController *retriveController;
@property(nonatomic,retain)ZoomSDKVerifySMSVerificationCodeController *verifyCintroller;
@property(nonatomic,retain)ZoomSDKWebinarRegisterHelper *webinarRegisterHelper;
@property(nonatomic,retain)ZoomSDKJoinMeetingHelper *joinMeetingHelper;
@property(nonatomic,retain)ZoomSDKWebinarInputScreenNameHandler *webinarInputScreenNameHandler;
@end

@implementation meetingServiceDelegate

+(meetingServiceDelegate *)share
{
    static meetingServiceDelegate *delegate = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
        delegate = [[meetingServiceDelegate alloc]init];
    });
    return delegate;
}

#pragma mark meeting delegate
- (void)onMeetingStatusChange:(ZoomSDKMeetingStatus)state meetingError:(ZoomSDKMeetingError)error EndReason:(EndMeetingReason)reason
{
    nativeErrorTypeHelp help;
    ZNMeetingStatus status = help.ZNSDKMeetingStatus(state);
    int  result = 0;
    if (error == ZoomSDKMeetingError_None) {
        result = help.ZNSDKMeetingEndReason(reason);
    }else{
        result = help.ZNSDKMeetingFailCode(error);
    }
    _g_native_wrap.GetMeetingServiceWrap().onMeetingStatusChanged(status, result);
}

- (void)onFreeMeetingNeedToUpgrade:(FreeMeetingNeedUpgradeType)type giftUpgradeURL:(NSString *)giftURL
{
    nativeErrorTypeHelp help;
    ZNFreeMeetingNeedUpgradeType  ZN_type = help.ZoomSDKFreeMeetingNeedUpgradeType(type);
    NSString *url = nil;
    if (giftURL == nil) {
        url = @"";
    }else{
        url = giftURL;
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().onFreeMeetingNeedToUpgrade(ZN_type, url.UTF8String);
}

- (void)onFreeMeetingUpgradeToGiftFreeTrialStop
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().onFreeMeetingUpgradeToGiftFreeTrialStop();
}

- (void)onFreeMeetingUpgradeToGiftFreeTrialStart
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().onFreeMeetingUpgradeToGiftFreeTrialStart();
}

- (void)onFreeMeetingUpgradedToProMeeting
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().onFreeMeetingUpgradeToProMeeting();
}

-(void)onSharingStatus:(ZoomSDKShareStatus)status User:(unsigned int)userID
{
    nativeErrorTypeHelp help;
    ZNShareStatus shareStatus = help.ZNSDKShareStatus(status);
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingShareCtrl().onSharingStatus(shareStatus, userID);
}

- (void)onMeetingStatisticWarning:(StatisticWarningType)type
{
    nativeErrorTypeHelp help;
    ZNStatisticsWarningType warningType = help.ZNStatisticsWarningTypeMap(type);
    _g_native_wrap.GetMeetingServiceWrap().onMeetingStatisticsWarningNotification(warningType);
}

- (void)onMeetingParameterNotification:(ZoomSDKMeetingParameter *)meetingParameter
{
    ZNMeetingParameter param;
    nativeErrorTypeHelp help;
    MeetingType type = meetingParameter.meetingType;
    param.meeting_type = help.ZNSDKMeetingType(type);
    param.is_view_only = meetingParameter.isViewOnly;
    param.is_auto_recording_local = meetingParameter.isAutoRecordingLocal;
    param.is_auto_recording_cloud = meetingParameter.isAutoRecordingCloud;
    param.meeting_number = meetingParameter.meetingNumber;
    param.meeting_topic = (meetingParameter.meetingTopic?meetingParameter.meetingTopic.UTF8String:"");
    param.meeting_host = (meetingParameter.meetingHost?meetingParameter.meetingHost.UTF8String:"");
    _g_native_wrap.GetMeetingServiceWrap().onMeetingParameterNotification(param);
}

#pragma mark meeting ui delegate
- (void)onToolbarInviteButtonClick
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool  isInvite = false;
    if (service && config) {
        isInvite = [config disableToolbarInviteButtonClickOriginAction];
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onInviteBtnClicked(isInvite);
}

-(void)onToolbarShareButtonClick
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onStartShareBtnClicked();
}

-(void)onParticipantButtonClicked
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onParticipantListBtnClicked();
}

-(void)onCustomLiveButtonClicked
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onCustomLiveStreamMenuClicked();
}

-(void)onNeedShowLeaveMeetingWindow
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onEndMeetingBtnClicked();
}

-(void)onAudioButtonClicked:(unsigned int)userid audioSession:(ZoomSDKAudioActionInfo)info
{
    nativeErrorTypeHelp help;
    ZNAudioCallbackActionInfo Actioninfo = help.ZNSDKAudioCallbackAction(info);
    ZNAudioBtnClickedCallbackInfo callbackInfo;
    callbackInfo.userid_MuteUnmute = userid;
    callbackInfo.audio_clicked_action = Actioninfo;
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onAudioBtnClicked(callbackInfo);
}

-(void)onAudioSettingMenuButtonClicked
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onAudioMenuBtnClicked();
}

-(void)onCloseCaptionButtonClick
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onCCBTNClicked();
}
#pragma mark meeting action controller
- (void)onVideoStatusChange:(BOOL)videoOn UserID:(unsigned int)userID
{
    ZNVideoStatus videoStatus = ZN_Video_OFF;
    if (videoOn == YES) {
        videoStatus = ZN_Video_ON;
    }else{
        videoStatus = ZN_Video_OFF;
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().onUserVideoStatusChange(userID, videoStatus);
}

-(void)onActiveVideoUserChanged:(unsigned int)userID
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().onActiveVideoUserChanged(userID);
}

-(void)onActiveSpeakerVideoUserChanged:(unsigned int)userID
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().onActiveSpeakerVideoUserChanged(userID);
}

-(void)onUserAudioStatusChange:(NSArray *)userAudioStatusArray
{
    if (!userAudioStatusArray || userAudioStatusArray.count == 0) {
        return;
    }
    ZNList<ZNUserAudioStatus> userAudioStatusList;
    nativeErrorTypeHelp help_typeChange;
    ZNUserAudioStatus userAudioInfo;
    for (ZoomSDKUserAudioStatus *key in userAudioStatusArray) {
        unsigned int USERID = [key getUserID];
        ZoomSDKAudioStatus status = [key getStatus];
        ZNAudioStatus  znStatus = help_typeChange.ZNSDKUserAudioStatus(status);
        userAudioInfo.audioStauts = znStatus;
        userAudioInfo.userId = USERID;
        userAudioStatusList.push_back(userAudioInfo);
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().onUserAudioStatusChange(userAudioStatusList, "");
    
}

-(void)onUserActiveAudioChange:(NSArray *)useridArray
{
    ZNList<unsigned int> list;
    for (NSNumber *num in useridArray) {
        unsigned int userid = [num unsignedIntValue];
        list.push_back(userid);
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().onUserActiveAudioChange(list);
}

-(void)onUserLeft:(NSArray *)array
{
    if (!array || array.count == 0) {
        return;
    }
    ZNList<unsigned int> list;
    for (NSNumber *num in array) {
        unsigned int userid = [num unsignedIntValue];
        list.push_back(userid);
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingParticipantsCtrl().onUserLeft(list, "");
}

-(void)onUserJoin:(NSArray *)array
{
    if (!array || array.count == 0) {
        return;
    }
    ZNList<unsigned int> list;
    for (NSNumber *num in array) {
        unsigned int userid = [num unsignedIntValue];
        list.push_back(userid);
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingParticipantsCtrl().onUserJoin(list, "");
}

-(void)onHostChange:(unsigned int)userID
{
 _g_native_wrap.GetMeetingServiceWrap().GetMeetingParticipantsCtrl().onHostChangeNotification(userID);
}

-(void)onAllowParticipantsRequestCloudRecording:(bool)allow
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingParticipantsCtrl().onAllowParticipantsRequestCloudRecording(allow);
}

//h323
-(void)onCalloutStatusReceived:(H323CalloutStatus)calloutStatus
{
    nativeErrorTypeHelp help_typeChange;
    ZNH323CalloutStatus status = help_typeChange.ZoomSDKH323Status(calloutStatus);
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().onH323CalloutStatusNotify(status);
}

#pragma mark  sms
-(void)onNeedRealNameAuthMeetingWithSupportCountryList:(NSArray *)supportCountryList withPrivacyURL:(NSString *)privacyURL withRetrieveSMSVerificationCodeHandler:(ZoomSDKRetrieveSMSVerificationCodeController *)handler
{
    self.retriveController = handler;
    ZNList<ZNZoomRealNameAuthCountryInfo> infoList;
    for (ZoomSDKRealNameAuthCountryInfo *info in supportCountryList) {
        ZNZoomRealNameAuthCountryInfo countryInfo;
        countryInfo.countryCode = [info getCountryCode].UTF8String;
        countryInfo.countryID = [info getCountryID].UTF8String;
        countryInfo.countryName = [info getCountryName].UTF8String;
        infoList.push_back(countryInfo);
    }
    _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().onNeedRealNameAuthMeetingNotification(infoList, privacyURL.UTF8String);
}

-(void)onRetrieveSMSVerificationCodeResult:(ZoomSDKSMSVerificationCodeError)result withVerifySMSVerificationCodeHandle:(ZoomSDKVerifySMSVerificationCodeController *)handler
{
    self.verifyCintroller = handler;
    nativeErrorTypeHelp help;
    ZNSMSVerificationCodeErr ret = help.ZNSDKSMSVerificationCodeError(result);
    _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().onRetrieveSMSVerificationCodeResultNotification(ret);
}

-(void)onVerifySMSVerificationCodeResult:(ZoomSDKSMSVerificationCodeError)reuslt
{
    nativeErrorTypeHelp help;
    ZNSMSVerificationCodeErr ret = help.ZNSDKSMSVerificationCodeError(reuslt);
    _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().onVerifySMSVerificationCodeResultNotification(ret);
}

-(ZoomSDKVerifySMSVerificationCodeController *)getVerifyCintroller
{
    return  self.verifyCintroller;
}

-(ZoomSDKRetrieveSMSVerificationCodeController *)getRetriveController
{
    return self.retriveController;
}

-(BOOL)getResendRetriveController
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return NO;
    }
    ZoomSDKRealNameAuthenticationController *controller = [service getRealNameController];
    if (!controller) {
        return NO;
    }
    self.retriveController = [controller resendSMSVerificationCodeController];
    if (self.retriveController) {
        return YES;
    }
    return NO;
}

-(BOOL)getReVerifyCintroller
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return NO;
    }
    ZoomSDKRealNameAuthenticationController *controller = [service getRealNameController];
    if (!controller) {
        return NO;
    }
    self.verifyCintroller = [controller reVerifySMSVerificationCodeController];
    if (self.verifyCintroller) {
        return YES;
    }
    return NO;
}

-(ZoomSDKError)onWebinarNeedRegisterResponse:(ZoomSDKWebinarRegisterHelper *)webinarRegisterHelper
{
    self.webinarRegisterHelper = webinarRegisterHelper;
}

-(ZoomSDKWebinarRegisterHelper *)getWebinarRegisterHelper
{
    return self.webinarRegisterHelper;
}

-(void)onWebinarNeedInputScreenName:(ZoomSDKWebinarInputScreenNameHandler*)handler
{
    self.webinarInputScreenNameHandler = handler;
}

-(ZoomSDKWebinarInputScreenNameHandler *)getWebinarInputScreenNameHandler
{
    return self.webinarInputScreenNameHandler;
}

-(void)onJoinMeetingResponse:(ZoomSDKJoinMeetingHelper *)joinMeetingHelper
{
    self.joinMeetingHelper = joinMeetingHelper;
}

-(ZoomSDKJoinMeetingHelper *)getJoinMeetingHelper
{
    return self.joinMeetingHelper;
}

-(void)cleanUp
{
    if (_verifyCintroller) {
        [_verifyCintroller release];
        _verifyCintroller = nil;
    }
    
    if (_retriveController) {
        [_retriveController release];
        _retriveController = nil;
    }
    if (_webinarRegisterHelper) {
        [_webinarRegisterHelper release];
        _webinarRegisterHelper = nil;
    }
    if (_joinMeetingHelper) {
        [_joinMeetingHelper release];
        _joinMeetingHelper = nil;
    }
    if (_webinarInputScreenNameHandler) {
        [_webinarInputScreenNameHandler release];
        _webinarInputScreenNameHandler = nil;
    }
}

-(void)dealloc
{
    [self cleanUp];
    [super dealloc];
}

-(void)onRecord2MP4Done:(BOOL)success Path:(NSString *)recordPath
{
    ZoomSTRING path = "";
    if (recordPath) 
        path = [recordPath UTF8String];
    
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().onRecording2MP4Done(success, 0, path);
}

-(void)onRecord2MP4Progressing:(int)percentage
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().onRecording2MP4Processing(percentage);
}

- (void)onRecordStatus:(ZoomSDKRecordingStatus)status
{
    nativeErrorTypeHelp help;
    ZNRecordingStatus znStatus = help.ZNRecordingStatusChange(status);
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().onRecordingStatus(znStatus);
}

-(void)onRecordPrivilegeChange:(BOOL)canRec
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().onRecordPrivilegeChanged(canRec);
}

-(void)onCloudRecordingStatus:(ZoomSDKRecordingStatus)status
{
    nativeErrorTypeHelp help;
    ZNRecordingStatus znStatus = help.ZNRecordingStatusChange(status);
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().onCloudRecordingStatus(znStatus);
}

-(void)onCloudRecordingStorageFull:(time_t)gracePeriodDate
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().onCloudRecordingStorageFull(gracePeriodDate);
}

-(void)onChatStatusChangedNotification:(ZoomSDKChatStatus *)chatStatus
{
    ZNChatStatus zn_chat_status;
    zn_chat_status.is_chat_off = !chatStatus.isSupportChat;
    zn_chat_status.is_webinar_attendee = chatStatus.isWebinarAttendee;
    zn_chat_status.is_webinar_meeting = chatStatus.isWebinarMeeting;
    if (chatStatus.isWebinarMeeting)
    {
        if (chatStatus.isWebinarAttendee) 
        {
            zn_chat_status.ut.webinar_attendee_status.can_chat = chatStatus.getWebinarAttendeePrivilege.canChat;
            zn_chat_status.ut.webinar_attendee_status.can_chat_to_all_panellist_and_attendee = chatStatus.getWebinarAttendeePrivilege.canChatToAllPanellistAndAttendee;
            zn_chat_status.ut.webinar_attendee_status.can_chat_to_all_panellist = chatStatus.getWebinarAttendeePrivilege.canChatToAllPanellist;
        } else {
            zn_chat_status.ut.webinar_other_status.can_chat_to_all_panellist = chatStatus.getWebinarPanelistPrivilege.canChatToAllPanellist;
            zn_chat_status.ut.webinar_other_status.can_chat_to_all_panellist_and_attendee = chatStatus.getWebinarPanelistPrivilege.canChatToAllPanellistAndAttendee;
            zn_chat_status.ut.webinar_other_status.can_chat_to_individual = chatStatus.getWebinarPanelistPrivilege.canChatToIndividual;
        }
    } else {
        zn_chat_status.ut.normal_meeting_status.can_chat = chatStatus.getNormalMeetingPrivilege.canChat;
        zn_chat_status.ut.normal_meeting_status.can_chat_to_all = chatStatus.getNormalMeetingPrivilege.canChatToAll;
        zn_chat_status.ut.normal_meeting_status.can_chat_to_individual = chatStatus.getNormalMeetingPrivilege.canChatToIndividual;
        zn_chat_status.ut.normal_meeting_status.is_only_can_chat_to_host = chatStatus.getNormalMeetingPrivilege.isOnlyCanChatToHost;
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().onChatStatusChangedNotification(zn_chat_status);
}

-(void)onChatMsgDeleteNotification:(NSString*)msgID messageDeleteType:(ZoomSDKChatMessageDeleteType)deleteBy
{
    ZoomSTRING zn_msgID = "";
    if (msgID) 
        zn_msgID = [msgID UTF8String];
    
    nativeErrorTypeHelp help;
    ZNSDKChatMessageDeleteType zn_deleteBy = help.ZNSDKChatMessageDeleteTypeMap(deleteBy);
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().onChatMsgDeleteNotification(zn_msgID, zn_deleteBy);
}

-(void)onShareMeetingChatStatusChanged:(BOOL)isStart
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().onShareMeetingChatStatusChanged(isStart);
}

@end

@implementation meetingServiceChatDelegate

-(void)onChatMessageNotification:(ZoomSDKChatInfo*)chatInfo
{
    ZoomSTRING zn_content = "";
    ZNChatMsgInfo zn_chat_msg_info;

    ZoomSTRING zn_messageID;
    NSString *messageID = [chatInfo getMessageID];
    if (messageID)
        zn_messageID = [messageID UTF8String];
    zn_chat_msg_info.messageID = zn_messageID;
    zn_chat_msg_info.senderUserId = [chatInfo getSenderUserID];

    ZoomSTRING zn_senderDisplayName;
    NSString *senderDisplayName = [chatInfo getSenderDisplayName];
    if (senderDisplayName)
        zn_senderDisplayName = [senderDisplayName UTF8String];
    zn_chat_msg_info.senderDisplayName = zn_senderDisplayName;
    zn_chat_msg_info.receiverUserId = [chatInfo getReceiverUserID];

    ZoomSTRING zn_receiverDisplayName;
    NSString *receiverDisplayName = [chatInfo getReceiverDisplayName];
    if (receiverDisplayName)
        zn_receiverDisplayName = [receiverDisplayName UTF8String];
    zn_chat_msg_info.receiverDisplayName = zn_receiverDisplayName;

    ZoomSTRING zn_msgContent;
    NSString *msgContent = [chatInfo getMsgContent];
    if (msgContent)
        zn_msgContent = [msgContent UTF8String];
    zn_chat_msg_info.content = zn_msgContent;
    zn_chat_msg_info.timeStamp = [chatInfo getTimeStamp];
    zn_chat_msg_info.isChatToWaitingroom = chatInfo.isChatToWaitingRoom;

    nativeErrorTypeHelp Help_type;
    ZoomSDKChatMessageType chatMessageType = [chatInfo getChatMessageType];
    ZNSDKChatMessageType zn_chatMessageType = Help_type.ZNSDKChatMessageTypeMap(chatMessageType);
    zn_chat_msg_info.chatMessageType = zn_chatMessageType;

    if (chatMessageType == ZoomSDKChatMessageType_To_All)
        zn_chat_msg_info.isChatToAll = true;

    if (chatMessageType == ZoomSDKChatMessageType_To_All_Panelist)
        zn_chat_msg_info.isChatToAllPanelist = true;

    zn_chat_msg_info.isComment = chatInfo.isComment;
    zn_chat_msg_info.isThread = chatInfo.isThread;

    ZoomSTRING zn_threadID;
    NSString *threadID = [chatInfo getThreadID];
    if (threadID)
        zn_threadID = [threadID UTF8String];
    zn_chat_msg_info.threadID = zn_threadID;
    NSArray<ZoomSDKRichTextStyleItem *> * plstRichTextStyleItem = [chatInfo getTextStyleItemList];
    ZNList<ZNRichTextStyleItem> text_style_item_list;
    for (ZoomSDKRichTextStyleItem *pRichTextStyleItem in plstRichTextStyleItem)
    {
        ZNRichTextStyleItem zn_rich_text_style_item;
        if (pRichTextStyleItem)
        {
            zn_rich_text_style_item.textStyle = (ZNRichTextStyle)pRichTextStyleItem.textStyle;
            NSArray<ZoomSDKRichTextStyleOffset *> * plstTextStyleOffset = pRichTextStyleItem.getTextStyleOffsetList;
            ZNList<ZNRichTextStyleOffset> rich_text_style_offset_list;
            for (ZoomSDKRichTextStyleOffset *pTextStyleOffset in plstTextStyleOffset)
            {
                ZNRichTextStyleOffset zn_rich_text_style_offset;
                if (pTextStyleOffset)
                {
                    zn_rich_text_style_offset.positionStart = pTextStyleOffset.positionStart;
                    zn_rich_text_style_offset.positionEnd = pTextStyleOffset.positionEnd;

                    ZoomSTRING zn_reserve;
                    NSString *reserve = pTextStyleOffset.reserve;
                    if (reserve)
                        zn_reserve = [reserve UTF8String];
                    zn_rich_text_style_offset.reserve = zn_reserve;
                }
                rich_text_style_offset_list.push_back(zn_rich_text_style_offset);
            }
            zn_rich_text_style_item.textStyleOffsetList = rich_text_style_offset_list;
        }
        text_style_item_list.push_back(zn_rich_text_style_item);
    }
    zn_chat_msg_info.textStyleItemList = text_style_item_list;
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().onChatMsgNotifcation(zn_chat_msg_info, zn_content);
}

@end

@implementation meetingServiceRecordDelegate
+(meetingServiceRecordDelegate *)share
{
    static meetingServiceRecordDelegate *delegate = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        delegate = [[meetingServiceRecordDelegate alloc] init];
    });
    return delegate;
}

-(instancetype)init
{
    self = [super init];
    if (self) {
        _cloudRecordingHandler = nil;
        return self;
    }
    return nil;
}

-(void)dealloc
{
    if(_cloudRecordingHandler)
    {
        _cloudRecordingHandler = nil;
    }
    [super dealloc];
}

#pragma mark smart summary delegate

-(void)onRequestCloudRecordingResponse:(ZoomSDKRequestStartCloudRecordingStatus)status
{
    nativeErrorTypeHelp help;
    ZNRequestStartCloudRecordingStatus znStatus = help.ZNRequestStartCloudRecordingStatusMap(status);
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().onRequestCloudRecordingResponse(znStatus);
}

-(void)onStartCloudRecordingRequested:(ZoomSDKRequestStartCloudRecordingHandler *)handler
{
    self.cloudRecordingHandler = handler;
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().onStartCloudRecordingRequested();
}

@end

@implementation meetingServiceWaitingRoomDelegate
+(meetingServiceWaitingRoomDelegate *)share
{
    static meetingServiceWaitingRoomDelegate *delegate = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        delegate = [[meetingServiceWaitingRoomDelegate alloc] init];
    });
    return delegate;
}

-(instancetype)init
{
    self = [super init];
    if (self) {
        _waitingRoomHandler = nil;
        return self;
    }
    return nil;
}

-(void)dealloc
{
    if(_waitingRoomHandler)
    {
        _waitingRoomHandler = nil;
    }
    [super dealloc];
}

#pragma mark waiting room delegate

-(void)onUserJoinWaitingRoom:(unsigned int)userid
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().onWaitingRoomUserJoin(userid);
}

-(void)onUserLeftWaitingRoom:(unsigned int)userid
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().onWaitingRoomUserLeft(userid);
}

-(void)onWaitingRoomPresetAudioStatusChanged:(BOOL)audioCanTurnOn
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().onWaitingRoomPresetAudioStatusChanged(audioCanTurnOn);
}

-(void)onWaitingRoomPresetVideoStatusChanged:(BOOL)videoCanTurnOn
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().onWaitingRoomPresetVideoStatusChanged(videoCanTurnOn);
}

-(void)onCustomWaitingRoomDataUpdated:(ZoomSDKCustomWaitingRoomData*)bData handle:(ZoomSDKWaitingRoomDataDownloadHandler*)handle
{
    self.waitingRoomHandler = handle;
    ZNCustomWaitingRoomData zn_custom_waiting_room_data;

    ZoomSTRING zn_title;
    NSString *title = bData.title;
    if (title)
        zn_title = [title UTF8String];
    zn_custom_waiting_room_data.title = zn_title;

    ZoomSTRING zn_description;
    NSString *dataDescription = bData.dataDescription;
    if (dataDescription)
        zn_description = [dataDescription UTF8String];
    zn_custom_waiting_room_data.description = zn_description;

    ZoomSTRING zn_logo_path;
    NSString *logoPath = bData.logoPath;
    if (logoPath)
        zn_logo_path = [logoPath UTF8String];
    zn_custom_waiting_room_data.logo_path = zn_logo_path;

    ZoomSTRING zn_video_path;
    NSString *videoPath = bData.videoPath;
    if (videoPath)
        zn_video_path = [videoPath UTF8String];
    zn_custom_waiting_room_data.video_path = zn_video_path;

    ZoomSTRING zn_image_path;
    NSString *imagePath = bData.imagePath;
    if (imagePath)
        zn_image_path = [imagePath UTF8String];
    zn_custom_waiting_room_data.image_path = zn_image_path;

    nativeErrorTypeHelp Help_type;
    ZoomSDKWaitingRoomLayoutType type = bData.type;
    ZNWaitingRoomLayoutType zn_type = Help_type.ZNWaitingRoomLayoutTypeMap(type);
    zn_custom_waiting_room_data.type = zn_type;

    ZoomSDKCustomWaitingRoomDataStatus status = bData.status;
    ZNCustomWaitingRoomDataStatus zn_status = Help_type.ZNCustomWaitingRoomDataStatusMap(status);
    zn_custom_waiting_room_data.status = zn_status;
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().onCustomWaitingRoomDataUpdated(zn_custom_waiting_room_data);
}

-(void)onWaitingRoomUserNameChanged:(unsigned int)userID userName:(NSString *)userName
{
    ZoomSTRING zn_userName = "";
    if (userName) 
        zn_userName = [userName UTF8String];
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().onWaitingRoomUserNameChanged(userID, zn_userName);
}

-(void)onWaitingRoomEntranceEnabled:(BOOL)enabled
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().onWaitingRoomEntranceEnabled(enabled);
}

@end

@implementation meetingServiceSmartSummaryDelegate
+(meetingServiceSmartSummaryDelegate *)share
{
    static meetingServiceSmartSummaryDelegate *delegate = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        delegate = [[meetingServiceSmartSummaryDelegate alloc] init];
    });
    return delegate;
}

-(instancetype)init
{
    self = [super init];
    if (self) {
        _smartSummaryHandler = nil;
        return self;
    }
    return nil;
}

-(void)dealloc
{
    if(_smartSummaryHandler)
    {
        _smartSummaryHandler = nil;
    }
    [super dealloc];
}

#pragma mark smart summary delegate

-(void)onSmartSummaryStatusChanged:(BOOL)isStart
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingSmartSummaryCtrl().onSmartSummaryStatusChange(isStart);
}

-(void)onSmartSummaryPrivilegeRequested:(unsigned int)senderID requestHandler:(ZoomSDKMeetingSmartSummaryPrivilegeHandler*)handler
{
    self.smartSummaryHandler = handler;
    
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingSmartSummaryCtrl().onSmartSummaryPrivilegeRequested(senderID);
}

-(void)onSmartSummaryStartReqResponse:(BOOL)timeout isDecline:(BOOL)decline
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingSmartSummaryCtrl().onSmartSummaryStartReqResponse(timeout, decline);
}

-(void)onEnableSmartSummary
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingSmartSummaryCtrl().onEnableSmartSummary();
}

@end