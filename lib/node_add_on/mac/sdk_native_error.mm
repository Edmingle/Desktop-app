


#include "sdk_native_error.h"

nativeErrorTypeHelp::nativeErrorTypeHelp()
{
    
}
nativeErrorTypeHelp::~nativeErrorTypeHelp()
{
    
}
#pragma mark  zoom error
ZNSDKError nativeErrorTypeHelp::ZoomSDKErrorType(ZoomSDKError &error)
{
    ZNSDKError ret = ZNSDKERR_UNKNOWN;
    switch (error) {
        case ZoomSDKError_Success:
            ret = ZNSDKERR_SUCCESS;
            break;
        case ZoomSDKError_Failed:
            ret = ZNSDKERR_MEMORY_FAILED;
            break;
        case ZoomSDKError_UnKnow:
            ret = ZNSDKERR_UNKNOWN;
            break;
        case ZoomSDKError_Uninit:
            ret = ZNSDKERR_UNINITIALIZE;
            break;
        case ZoomSDKError_ServiceFailed:
            ret = ZNSDKERR_SERVICE_FAILED;
            break;
        case ZoomSDKError_WrongUsage:
            ret = ZNSDKERR_WRONG_USEAGE;
            break;
        case ZoomSDKError_InvalidPrameter:
            ret = ZNSDKERR_INVALID_PARAMETER;
            break;
        case ZoomSDKError_NoPermission:
            ret = ZNSDKERR_NO_PERMISSION;
            break;
        case ZoomSDKError_NoRecordingInProgress:
            ret = ZNSDKERR_NORECORDINGINPROCESS;
            break;
        case ZoomSDKError_TooFrequentCall:
            ret = ZNSDKERR_TOO_FREQUENT_CALL;
            break;
            
        case ZoomSDKError_ModuleLoadFail:
            ret = ZNSDKERR_MODULE_LOAD_FAILED;
            break;
        case ZoomSDKError_NoVideoDeviceFound:
            ret = ZNSDKERR_NO_VIDEODEVICE_ISFOUND;
            break;
        case ZoomSDKError_NeedUserConfirmRecordDisclaimer:
            ret = ZNSDKERR_NEED_USER_CONFIRM_RECORD_DISCLAIMER;
            break;
        default:
            break;
    }
    return ret;
}

#pragma mark  auth error
ZNAuthResult nativeErrorTypeHelp::ZoomSDKAuthErrorTpye(ZoomSDKAuthError &error)
{
    ZNAuthResult ret = ZNAUTHRET_UNKNOWN;
    switch (error) {
        case ZoomSDKAuthError_Success:
            ret = ZNAUTHRET_SUCCESS;
            break;
        case ZoomSDKAuthError_KeyOrSecretWrong:
            ret = ZNAUTHRET_KEYORSECRETWRONG;
            break;
        case ZoomSDKAuthError_AccountNotSupport:
            ret = ZNAUTHRET_ACCOUNTNOTSUPPORT;
            break;
        case ZoomSDKAuthError_AccountNotEnableSDK:
            ret = ZNAUTHRET_ACCOUNTNOTENABLESDK;
            break;
        case ZoomSDKAuthError_Unknown:
            ret = ZNAUTHRET_UNKNOWN;
            break;
        case ZoomSDKAuthError_Timeout:
            ret = ZNAUTHRET_OVERTIME;
            break;
        case ZoomSDKAuthError_NetworkIssue:
            ret = ZNAUTHRET_NETWORKISSUE;
            break;
        case ZoomSDKAuthError_Client_Incompatible:
            ret = ZNAUTHRET_CLIENT_INCOMPATIBLE;
            break;
        case ZoomSDKAuthError_JwtTokenWrong:
            ret = ZNAUTHRET_JWTTOKENWRONG;
            break;
        case ZoomSDKAuthError_KeyOrSecretEmpty:
            ret = ZNAUTHRET_KEYORSECRETEMPTY;
            break;
        case ZoomSDKAuthError_LimitExceededException:
            ret = ZNAUTHRET_LIMIT_EXCEEDED_EXCEPTION;
            break;
        default:
            break;
    }
    return ret;
}

#pragma mark  login status
ZNLOGINSTATUS nativeErrorTypeHelp::ZoomSDKLoginStatusType(ZoomSDKLoginStatus &status)
{
    ZNLOGINSTATUS ret = ZNLOGIN_IDLE;
    switch (status) {
        case ZoomSDKLoginStatus_Idle:
            ret = ZNLOGIN_IDLE;
            break;
        case ZoomSDKLoginStatus_Success:
            ret = ZNLOGIN_SUCCESS;
            break;
        case ZoomSDKLoginStatus_Failed:
            ret = ZNLOGIN_FAILED;
            break;
        case ZoomSDKLoginStatus_Processing:
            ret = ZNLOGIN_PROCESSING;
            break;
        default:
            break;
    }
    return ret;
}
#pragma mark user type
ZNSDKUserType nativeErrorTypeHelp::ZoomSDKUserTypeChange(ZoomSDKUserType &type)
{
    ZNSDKUserType ret = ZNSDK_UT_NORMALUSER;
    switch (type) {
        case ZoomSDKUserType_ZoomUser:
            ret = ZNSDK_UT_NORMALUSER;
            break;
        case ZoomSDKUserType_WithoutLogin:
            ret = ZNSDK_UT_WITHOUT_LOGIN;
            break;
        default:
            break;
    }
    return ret;
}

ZoomSDKUserType nativeErrorTypeHelp::ZNSDKUserTypeChange(ZNSDKUserType &type)
{
    ZoomSDKUserType ret = ZoomSDKUserType_WithoutLogin;
    switch (type) {
        case ZNSDK_UT_WITHOUT_LOGIN:
            ret = ZoomSDKUserType_WithoutLogin;
            break;
        case ZNSDK_UT_NORMALUSER:
            ret = ZoomSDKUserType_ZoomUser;
            break;
        default:
            break;
    }
    return ret;
}

SDKUserType  nativeErrorTypeHelp::SDKUserTypeChange(ZNZoomUserType &type)
{
    SDKUserType ret = SDKUserType_Unknown;
    switch (type) {
        case ZNZoomUserType_APIUSER:
            ret = SDKUserType_APIUser;
            break;
        case ZNZoomUserType_EMAIL_LOGIN:
            ret = SDKUserType_EmailLogin;
            break;
        case ZNZoomUserType_FACEBOOK:
            ret = SDKUserType_FaceBook;
            break;
        case ZNZoomUserType_GoogleOAuth:
            ret = SDKUserType_GoogleOAuth;
            break;
        case ZNZoomUserType_SSO:
            ret = SDKUserType_SSO;
            break;
        case ZNZoomUserType_Unknown:
            ret = SDKUserType_Unknown;
            break;
        default:
            break;
    }
    return ret;
}

LeaveMeetingCmd nativeErrorTypeHelp::ZoomSDKLeaveMeetingCmd(ZNLeaveMeetingCmd &cmd)
{
    LeaveMeetingCmd ret = LeaveMeetingCmd_End;
    switch (cmd) {
        case ZNLEAVE_MEETING:
            ret = LeaveMeetingCmd_Leave;
            break;
        case ZNEND_MEETING:
            ret = LeaveMeetingCmd_End;
            break;
        default:
            break;
    }
    return ret;
}

#pragma mark meeting status
ZNMeetingStatus  nativeErrorTypeHelp::ZNSDKMeetingStatus(ZoomSDKMeetingStatus &status)
{
    ZNMeetingStatus ret = ZNMEETING_STATUS_IDLE;
    switch (status) {
        case ZoomSDKMeetingStatus_Idle:
            ret = ZNMEETING_STATUS_IDLE;
            break;
        case ZoomSDKMeetingStatus_Connecting:
            ret = ZNMEETING_STATUS_CONNECTING;
            break;
        case ZoomSDKMeetingStatus_WaitingForHost:
            ret = ZNMEETING_STATUS_WAITINGFORHOST;
            break;
        case ZoomSDKMeetingStatus_InMeeting:
            ret = ZNMEETING_STATUS_INMEETING;
            break;
        case ZoomSDKMeetingStatus_Disconnecting:
            ret = ZNMEETING_STATUS_DISCONNECTING;
            break;
        case ZoomSDKMeetingStatus_Reconnecting:
            ret = ZNMEETING_STATUS_RECONNECTING;
            break;
        case ZoomSDKMeetingStatus_Failed:
            ret = ZNMEETING_STATUS_FAILED;
            break;
        case ZoomSDKMeetingStatus_Ended:
            ret = ZNMEETING_STATUS_ENDED;
            break;
        case ZoomSDKMeetingStatus_AudioReady:
            ret = ZNMEETING_STATUS_AUDIO_READY;
            break;
        case ZoomSDKMeetingStatus_OtherMeetingInProgress:
            ret = ZNMEETING_STATUS_OTHER_MEETING_INPROGRESS;
            break;
        case ZoomSDKMeetingStatus_InWaitingRoom:
            ret = ZNMEETING_STATUS_IN_WAITING_ROOM;
            break;
        case ZoomSDKMeetingStatus_Webinar_Promote:
            ret = ZNMEETING_STATUS_WEBINAR_PROMOTE;
            break;
        case ZoomSDKMeetingStatus_Webinar_Depromote:
            ret = ZNMEETING_STATUS_WEBINAR_DEPROMOTE;
            break;
        default:
            break;
    }
    return ret;
}

ZoomSDKMeetingStatus nativeErrorTypeHelp::ZoomSDKMeetingStatusC(ZNMeetingStatus &status)
{
    ZoomSDKMeetingStatus ret = ZoomSDKMeetingStatus_Idle;
    switch (status) {
        case ZNMEETING_STATUS_IDLE:
            ret = ZoomSDKMeetingStatus_Idle;
            break;
        case ZNMEETING_STATUS_CONNECTING:
            ret = ZoomSDKMeetingStatus_Connecting;
            break;
        case ZNMEETING_STATUS_WAITINGFORHOST:
            ret = ZoomSDKMeetingStatus_WaitingForHost;
            break;
        case ZNMEETING_STATUS_INMEETING:
            ret = ZoomSDKMeetingStatus_InMeeting;
            break;
        case ZNMEETING_STATUS_DISCONNECTING:
            ret = ZoomSDKMeetingStatus_Disconnecting;
            break;
        case ZNMEETING_STATUS_RECONNECTING:
            ret = ZoomSDKMeetingStatus_Reconnecting;
            break;
        case ZNMEETING_STATUS_FAILED:
            ret = ZoomSDKMeetingStatus_Failed;
            break;
        case ZNMEETING_STATUS_ENDED:
            ret = ZoomSDKMeetingStatus_Ended;
            break;
        case ZNMEETING_STATUS_AUDIO_READY:
            ret = ZoomSDKMeetingStatus_AudioReady;
            break;
        case ZNMEETING_STATUS_OTHER_MEETING_INPROGRESS:
            ret = ZoomSDKMeetingStatus_OtherMeetingInProgress;
            break;
        case ZNMEETING_STATUS_IN_WAITING_ROOM:
            ret = ZoomSDKMeetingStatus_InWaitingRoom;
            break;
        case ZNMEETING_STATUS_WEBINAR_PROMOTE:
            ret = ZoomSDKMeetingStatus_Webinar_Promote;
            break;
        case ZNMEETING_STATUS_WEBINAR_DEPROMOTE:
            ret = ZoomSDKMeetingStatus_Webinar_Depromote;
            break;
        default:
            break;
    }
    return ret;
}
#pragma mark lanaguage
static NSString* const kZMFollowSystemIdentify = @"follow system language";
NSString *nativeErrorTypeHelp::ZNSDKLanaguageChange(ZNSDK_LANGUAGE_ID &lanaguageid)
{
    NSString *ret = kZMFollowSystemIdentify;
    switch (lanaguageid) {
        case ZNLANGUAGE_Unknow:
            ret = kZMFollowSystemIdentify;
            break;
        case ZNLANGUAGE_English:
            ret = @"en";
            break;
        case ZNLANGUAGE_Chinese_Simplified:
            ret = @"zh-Hans";
            break;
        case ZNLANGUAGE_Chinese_Traditional:
            ret = @"zh-Hant";
            break;
        case ZNLANGUAGE_Japanese:
            ret = @"ja";
            break;
        case ZNLANGUAGE_Spanish:
            ret = @"es";
            break;
        case ZNLANGUAGE_German:
            ret = @"de";
            break;
        case ZNLANGUAGE_French:
            ret = @"fr";
            break;
        case ZNLANGUAGE_Portuguese:
            ret = @"pt-PT";
            break;
        case ZNLANGUAGE_Russian:
            ret = @"ru";
            break;
        case ZNLANGUAGE_Korean:
            ret = @"ko-KR";
            break;
        case ZNLANGUAGE_Vietnamese:
            ret = @"vi";
            break;
        case ZNLANGUAGE_Italian:
            ret = @"it";
            break;
        case ZNLANGUAGE_Polish:
            ret = @"pl";
            break;
        case ZNLANGUAGE_Turkish:
            ret = @"tr";
            break;
        case ZNLANGUAGE_Indonesian:
            ret = @"id";
            break;
        case ZNLANGUAGE_Dutch:
            ret = @"nl";
            break;
        default:
            break;
    }
    return ret;
}

ZNMeetingType nativeErrorTypeHelp::ZNSDKMeetingType(MeetingType &type)
{
    ZNMeetingType ret = ZNMEETING_TYPE_NONE;
    switch (type) {
        case MeetingType_None:
            ret = ZNMEETING_TYPE_NONE;
            break;
        case MeetingType_Normal:
            ret = ZNMEETING_TYPE_NORMAL;
            break;
        case MeetingType_BreakoutRoom:
            ret = ZNMEETING_TYPE_BREAKOUTROOM;
            break;
        case MeetingType_Webinar:
            ret = ZNMEETING_TYPE_WEBINAR;
            break;
        default:
            break;
    }
    return ret;
}

ZNConnectionQuality nativeErrorTypeHelp::ZNSDKConnectionQuatity(ZoomSDKConnectionQuality &quatity)
{
    ZNConnectionQuality ret = ZNConn_Quality_Unknow;
    switch (quatity) {
        case ZoomSDKConnectionQuality_Unknow:
            ret = ZNConn_Quality_Unknow;
            break;
        case ZoomSDKConnectionQuality_VeryBad:
            ret = ZNConn_Quality_Very_Bad;
            break;
        case ZoomSDKConnectionQuality_Bad:
            ret = ZNConn_Quality_Bad;
            break;
        case ZoomSDKConnectionQuality_NotGood:
            ret = ZNConn_Quality_Not_Good;
            break;
        case ZoomSDKConnectionQuality_Normal:
            ret = ZNConn_Quality_Normal;
            break;
        case ZoomSDKConnectionQuality_Good:
            ret = ZNConn_Quality_Good;
            break;
        case ZoomSDKConnectionQuality_Excellent:
            ret = ZNConn_Quality_Excellent;
            break;
        default:
            break;
    }
    return ret;
}

#pragma mark screenViewType
ZNSDKViewType nativeErrorTypeHelp::ZNSDKViewTypeC(ScreenType &type)
{
    ZNSDKViewType ret = ZNSDK_FIRST_VIEW;
    switch (type) {
        case ScreenType_First:
            ret = ZNSDK_FIRST_VIEW;
            break;
        case ScreenType_Second:
            ret = ZNSDK_SECOND_VIEW;
        default:
            break;
    }
    return ret;
}

ScreenType nativeErrorTypeHelp::ZoomSDKScreenViewType(ZNSDKViewType &type)
{
    ScreenType ret = ScreenType_First;
    switch (type) {
        case ZNSDK_FIRST_VIEW:
            ret = ScreenType_First;
            break;
        case ZNSDK_SECOND_VIEW:
            ret = ScreenType_Second;
            break;
        default:
            break;
    }
    return ret;
}

AnnotationToolType nativeErrorTypeHelp::ZoomSDKAnnotationToolType(ZNAnnotationToolType &type)
{
    AnnotationToolType ret = AnnotationToolType_None;
    switch (type) {
        case ZN_ANNOTOOL_NONE_DRAWING:
            ret = AnnotationToolType_None;
            break;
        case ZN_ANNOTOOL_PEN:
            ret = AnnotationToolType_Pen;
            break;
        case ZN_ANNOTOOL_HIGHLIGHTER:
            ret = AnnotationToolType_HighLighter;
            break;
        case ZN_ANNOTOOL_AUTO_LINE:
            ret = AnnotationToolType_AutoLine;
            break;
        case ZN_ANNOTOOL_AUTO_RECTANGLE:
            ret = AnnotationToolType_AutoRectangle;
            break;
        case ZN_ANNOTOOL_AUTO_ELLIPSE:
            ret = AnnotationToolType_AutoEllipse;
            break;
        case ZN_ANNOTOOL_AUTO_ARROW:
            ret = AnnotationToolType_AutoArrow;
            break;
        case ZN_ANNOTOOL_AUTO_RECTANGLE_FILL:
            ret = AnnotationToolType_AutoRectangleFill;
            break;
        case ZN_ANNOTOOL_AUTO_ELLIPSE_FILL:
            ret = AnnotationToolType_AutoEllipseFill;
            break;
        case ZN_ANNOTOOL_SPOTLIGHT:
            ret = AnnotationToolType_SpotLight;
            break;
        case ZN_ANNOTOOL_ARROW:
            ret = AnnotationToolType_Arrow;
            break;
        case ZN_ANNOTOOL_ERASER:
            ret = AnnotationToolType_ERASER;
            break;
        default:
            break;
    }
    return ret;
}

AnnotationClearType nativeErrorTypeHelp::ZoomSDKAnnotationClearType(ZNAnnotationClearType &type)
{
    AnnotationClearType ret = AnnotationClearType_Self;
    switch (type) {
        case ZN_ANNOCLEAR_ALL:
            ret =  AnnotationClearType_All;
            break;
        case ZN_ANNOCLEAR_SELF:
            ret = AnnotationClearType_Self;
            break;
        case ZN_ANNOCLEAR_OTHER:
            ret = AnnotationClearType_Other;
            break;
        default:
            break;
    }
    return ret;
}

ZoomSDKMeetingFeatureEnableOption nativeErrorTypeHelp::FeatureEnableOptionMap(ZNFeatureEnableOption &option)
{
    ZoomSDKMeetingFeatureEnableOption meeting_enable_option = ZoomSDKMeetingFeatureEnableOption_None;
    switch (option) {
        case ZNEnableOption_None:
            meeting_enable_option = ZoomSDKMeetingFeatureEnableOption_None;
            break;
        case ZNEnableOption_Once:
            meeting_enable_option = ZoomSDKMeetingFeatureEnableOption_Once;
            break;
        case ZNEnableOption_Always:
            meeting_enable_option = ZoomSDKMeetingFeatureEnableOption_Always;
            break;
        default:
            break;
    }
    return meeting_enable_option;
}


ZNAudioStatus nativeErrorTypeHelp::ZNSDKUserAudioStatus(ZoomSDKAudioStatus &status)
{
    ZNAudioStatus ret = ZN_Audio_None;
    switch (status) {
        case ZoomSDKAudioStatus_None:
            ret = ZN_Audio_None;
            break;
        case ZoomSDKAudioStatus_Muted:
            ret = ZN_Audio_Muted;
            break;
        case ZoomSDKAudioStatus_UnMuted:
            ret = ZN_Audio_UnMuted;
            break;
        case ZoomSDKAudioStatus_MutedByHost:
            ret = ZN_Audio_Muted_ByHost;
            break;
        case ZoomSDKAudioStatus_UnMutedByHost:
            ret = ZN_Audio_UnMuted_ByHost;
            break;
        case ZoomSDKAudioStatus_MutedAllByHost:
            ret = ZN_Audio_MutedAll_ByHost;
            break;
        case ZoomSDKAudioStatus_UnMutedAllByHost:
            ret = ZN_Audio_UnMutedAll_ByHost;
            break;
        default:
            break;
    }
    return ret;
}


H323DeviceType nativeErrorTypeHelp::ZoomSDKH323DeviceType(ZNH323DeviceType &type)
{
    H323DeviceType ret = H323DeviceType_Unknown;
    switch (type) {
        case ZN_H323DeviceType_Unknown:
            ret = H323DeviceType_Unknown;
            break;
        case ZN_H323DeviceType_SIP:
            ret = H323DeviceType_SIP;
            break;
        case ZN_H323DeviceType_H323:
            ret = H323DeviceType_H323;
            break;
            
        default:
            break;
    }
    return ret;
}

ZNH323DeviceType nativeErrorTypeHelp::ZNSDKH323DeviceType(H323DeviceType &type)
{
    ZNH323DeviceType ret = ZN_H323DeviceType_Unknown;
    switch (type) {
        case H323DeviceType_Unknown:
            ret = ZN_H323DeviceType_Unknown;
            break;
        case H323DeviceType_SIP:
            ret = ZN_H323DeviceType_SIP;
            break;
        case H323DeviceType_H323:
            ret = ZN_H323DeviceType_H323;
            break;
        default:
            break;
    }
    return ret;
}

ZNH323CalloutStatus nativeErrorTypeHelp::ZoomSDKH323Status(H323CalloutStatus &status)
{
    ZNH323CalloutStatus ret = ZN_H323Callout_Unknown;
    switch (status) {
        case H323CalloutStatus_Unknown:
            ret = ZN_H323Callout_Unknown;
            break;
        case H323CalloutStatus_Success:
            ret = ZN_H323Callout_Success;
            break;
        case H323CalloutStatus_Ring:
            ret = ZN_H323Callout_Ring;
            break;
        case H323CalloutStatus_Timeout:
            ret = ZN_H323Callout_Timeout;
            break;
        case H323CalloutStatus_Failed:
            ret = ZN_H323Callout_Failed;
            break;
        case H323CalloutStatus_Busy:
            ret = ZN_H323Callout_Busy;
            break;
        case H323CalloutStatus_Decline:
            ret = ZN_H323Callout_Decline;
            break;
        default:
            break;
    }
    return ret;
}



ZNFreeMeetingNeedUpgradeType nativeErrorTypeHelp::ZoomSDKFreeMeetingNeedUpgradeType(FreeMeetingNeedUpgradeType &type)
{
    ZNFreeMeetingNeedUpgradeType ret = ZN_FreeMeetingNeedUpgradeType_NONE;
    switch (type) {
        case FreeMeetingNeedUpgradeType_NONE:
            ret = ZN_FreeMeetingNeedUpgradeType_NONE;
            break;
        case FreeMeetingNeedUpgradeType_BY_ADMIN:
            ret = ZN_FreeMeetingNeedUpgradeType_BY_ADMIN;
            break;
        case FreeMeetingNeedUpgradeType_BY_GIFTURL:
            ret = ZN_FreeMeetingNeedUpgradeType_BY_GIFTURL;
            break;
        default:
            break;
    }
    return ret;
}

ZNPremeetingAPIResult nativeErrorTypeHelp::ZNSDKPreMeetingError(ZoomSDKPremeetingError &error)
{
    ZNPremeetingAPIResult ret = ZN_PREMETAPIRET_UNKNOW;
    switch (error) {
        case ZoomSDKPremeetingError_Success:
            ret = ZN_PREMETAPIRET_SUCCESS;
            break;
        case ZoomSDKPremeetingError_Failed:
            ret = ZN_PREMETAPIRET_FAILED;
            break;
        case ZoomSDKPremeetingError_TimeOut:
            ret = ZN_PREMETAPIRET_TIMEOUT;
            break;
        case ZoomSDKPremeetingError_Unknown:
            ret = ZN_PREMETAPIRET_UNKNOW;
            break;
        default:
            break;
    }
    return ret;
}

ZNDirectShareStatus nativeErrorTypeHelp::ZNSDKDirectShareStatus(DirectShareStatus &status)
{
    ZNDirectShareStatus ret = ZN_DirectShare_Unknown;
    switch (status) {
        case DirectShareStatus_None:
            ret = ZN_DirectShare_Unknown;
            break;
        case DirectShareStatus_Connecting:
            ret = ZN_DirectShare_Connecting;
            break;
        case DirectShareStatus_InProgress:
            ret = ZN_DirectShare_In_Direct_Share_Mode;
            break;
        case DirectShareStatus_Ended:
            ret = ZN_DirectShare_Ended;
            break;
        case DirectShareStatus_NeedMeetingIDOrSharingKey:
            ret = ZN_DirectShare_Need_MeetingID_Or_PairingCode;
            break;
        case DirectShareStatus_WrongMeetingIDOrSharingKey:
            ret = ZN_DirectShare_WrongMeetingID_Or_SharingKey;
            break;
        case DirectShareStatus_NetworkError:
            ret = ZN_DirectShare_NetWork_Error;
            break;
        case DirectShareStatus_Unknow:
            ret = ZN_DirectShare_Unknown;
            break;
        case DirectShareStatus_NeedInputNewPairingCode:
            ret = ZN_DirectShare_InputNewParingCode;
            break;
        case DirectShareStatus_Prepared:
            ret = ZN_DirectShare_Prepared;
            break;

        default:
            break;
    }
    return ret;
}

ZNShareStatus nativeErrorTypeHelp::ZNSDKShareStatus(ZoomSDKShareStatus &status)
{
    ZNShareStatus ret = ZN_Sharing_None;
    switch (status) {
        case ZoomSDKShareStatus_None:
            ret = ZN_Sharing_None;
            break;
        case ZoomSDKShareStatus_SelfBegin:
            ret = ZN_Sharing_Self_Send_Begin;
            break;
        case ZoomSDKShareStatus_SelfEnd:
            ret = ZN_Sharing_Self_Send_End;
            break;
        case ZoomSDKShareStatus_OtherBegin:
            ret = ZN_Sharing_Other_Share_Begin;
            break;
        case ZoomSDKShareStatus_OtherEnd:
            ret = ZN_Sharing_Other_Share_End;
            break;
        case ZoomSDKShareStatus_ViewOther:
            ret = ZN_Sharing_View_Other_Sharing;
            break;
        case ZoomSDKShareStatus_Pause:
            ret = ZN_Sharing_Pause;
            break;
        case ZoomSDKShareStatus_Resume:
            ret = ZN_Sharing_Resume;
            break;
        case ZoomSDKShareStatus_ContentTypeChange:
            ret = ZN_Sharing_ContentTypeChange;
            break;
        case ZoomSDKShareStatus_SelfStartAudioShare:
            ret = ZN_Sharing_SelfStartAudioShare;
            break;
        case ZoomSDKShareStatus_SelfStopAudioShare:
            ret = ZN_Sharing_SelfStopAudioShare;
            break;
        case ZoomSDKShareStatus_OtherStartAudioShare:
            ret = ZN_Sharing_OtherStartAudioShare;
            break;
        case ZoomSDKShareStatus_OtherStopAudioShare:
            ret = ZN_Sharing_OtherStopAudioShare;
            break;
        default:
            break;
    }
    return ret;
}

ZNUserRole nativeErrorTypeHelp::ZNSDKUserRole(UserRole &role)
{
    ZNUserRole ret = ZN_USERROLE_NONE;
    switch (role) {
        case UserRole_None:
            ret = ZN_USERROLE_NONE;
            break;
        case UserRole_Host:
            ret = ZN_USERROLE_HOST;
            break;
        case UserRole_CoHost:
            ret = ZN_USERROLE_COHOST;
            break;
        case UserRole_Attendee:
            ret = ZN_USERROLE_ATTENDEE;
            break;
        case UserRole_Panelist:
            ret = ZN_USERROLE_PANELIST;
            break;
        case UserRole_BreakoutRoom_Moderator:
            ret = ZN_USERROLE_BREAKOUTROOM_MODERATOR;
            break;
        default:
            break;
    }
    return ret;
}

ZNMeetingEndReason  nativeErrorTypeHelp::ZNSDKMeetingEndReason(EndMeetingReason &reason)
{
    ZNMeetingEndReason ret = ZNEndMeetingReason_None;
    switch (reason) {
        case EndMeetingReason_None:
            ret = ZNEndMeetingReason_None;
            break;
        case EndMeetingReason_KickByHost:
            ret = ZNEndMeetingReason_KickByHost;
            break;
        case EndMeetingReason_EndByHost:
            ret = ZNEndMeetingReason_EndByHost;
            break;
        case EndMeetingReason_JBHTimeOut:
            ret = ZNEndMeetingReason_JBHTimeOut;
            break;
        case EndMeetingReason_NoAttendee:
            ret = ZNEndMeetingReason_NoAttendee;
            break;
        case EndMeetingReason_HostStartAnotherMeeting:
            ret = ZNEndMeetingReason_HostStartAnotherMeeting;
            break;
        case EndMeetingReason_FreeMeetingTimeOut:
            ret = ZNEndMeetingReason_FreeMeetingTimeOut;
            break;
        case EndMeetingReason_NetworkBroken:
            ret = ZNEndMeetingReason_NetworkBroken;
            break;
        default:
            break;
    }
    return ret;
}

ZNMeetingFailCode  nativeErrorTypeHelp::ZNSDKMeetingFailCode(ZoomSDKMeetingError &error)
{
    ZNMeetingFailCode ret = ZNMEETING_SUCCESS;
    switch (error) {
        case ZoomSDKMeetingError_Success:
            ret = ZNMEETING_SUCCESS;
            break;
        case ZoomSDKMeetingError_NetworkUnavailable:
            ret = ZNMEETING_FAIL_NETWORK_ERR;
            break;
        case ZoomSDKMeetingError_ReconnectFailed:
            ret =  ZNMEETING_FAIL_RECONNECT_ERR;
            break;
        case ZoomSDKMeetingError_MMRError:
            ret = ZNMEETING_FAIL_MMR_ERR;
            break;
        case ZoomSDKMeetingError_PasswordError:
            ret = ZNMEETING_FAIL_PASSWORD_ERR;
            break;
        case ZoomSDKMeetingError_SessionError:
            ret = ZNMEETING_FAIL_SESSION_ERR;
            break;
        case ZoomSDKMeetingError_MeetingOver:
            ret = ZNMEETING_FAIL_MEETING_OVER;
            break;
        case ZoomSDKMeetingError_MeetingNotStart:
            ret = ZNMEETING_FAIL_MEETING_NOT_START;
            break;
        case ZoomSDKMeetingError_MeetingNotExist:
            ret = ZNMEETING_FAIL_MEETING_NOT_EXIST;
            break;
        case ZoomSDKMeetingError_UserFull:
            ret = ZNMEETING_FAIL_MEETING_USER_FULL;
            break;
        case ZoomSDKMeetingError_ClientIncompatible:
            ret = ZNMEETING_FAIL_CLIENT_INCOMPATIBLE;
            break;
        case ZoomSDKMeetingError_NoMMR:
            ret = ZNMEETING_FAIL_NO_MMR;
            break;
        case ZoomSDKMeetingError_MeetingLocked:
            ret = ZNMEETING_FAIL_CONFLOCKED;
            break;
        case ZoomSDKMeetingError_MeetingRestricted:
            ret = ZNMEETING_FAIL_MEETING_RESTRICTED;
            break;
        case ZoomSDKMeetingError_MeetingJBHRestricted:
            ret = ZNMEETING_FAIL_MEETING_RESTRICTED_JBH;
            break;
        case ZoomSDKMeetingError_EmitWebRequestFailed:
            ret = ZNMEETING_FAIL_CANNOT_EMIT_WEBREQUEST;
            break;
        case ZoomSDKMeetingError_StartTokenExpired:
            ret = ZNMEETING_FAIL_CANNOT_START_TOKENEXPIRE;
            break;
        case ZoomSDKMeetingError_VideoSessionError:
            ret = ZNSESSION_VIDEO_ERR;
            break;
        case ZoomSDKMeetingError_AudioAutoStartError:
            ret = ZNSESSION_AUDIO_AUTOSTARTERR;
            break;
        case ZoomSDKMeetingError_RegisterWebinarFull:
            ret = ZNMEETING_FAIL_REGISTERWEBINAR_FULL;
            break;
        case ZoomSDKMeetingError_RegisterWebinarHostRegister:
            ret = ZNMEETING_FAIL_REGISTERWEBINAR_HOSTREGISTER;
            break;
        case ZoomSDKMeetingError_RegisterWebinarPanelistRegister:
            ret = ZNMEETING_FAIL_REGISTERWEBINAR_PANELISTREGISTER;
            break;
        case ZoomSDKMeetingError_RegisterWebinarDeniedEmail:
            ret = ZNMEETING_FAIL_REGISTERWEBINAR_DENIED_EMAIL;
            break;
        case ZoomSDKMeetingError_RegisterWebinarEnforceLogin:
            ret = ZNMEETING_FAIL_ENFORCE_LOGIN;
            break;
        case ZoomSDKMeetingError_ZCCertificateChanged:
            ret = ZNCONF_FAIL_ZC_CERTIFICATE_CHANGED;
            break;
        case ZoomSDKMeetingError_ConfigFileWriteFailed:
            ret = ZNMEETING_FAIL_WRITE_CONFIG_FILE;
            break;
        case ZoomSDKMeetingError_RemovedByHost:
            ret = ZNCONF_FAIL_REMOVED_BY_HOST;
            break;
        case ZoomSDKMeetingError_Unknown:
            ret = ZNMEETING_SUCCESS;
            break;
        case ZoomSDKMeetingError_None:
            ret = ZNMEETING_SUCCESS;
            break;
        case ZoomSDKMeetingError_vanityNotExist:
            ret = ZNCONF_FAIL_VANITY_NOT_EXIST;
            break;
        case ZoomSDKMeetingError_joinWebinarWithSameEmail:
            ret = ZNCONF_FAIL_JOIN_WEBINAR_WITHSAMEEMAIL;
            break;
        case ZoomSDKMeetingError_disallowHostMeeting:
            ret = ZNCONF_FAIL_DISALLOW_HOST_MEETING;
            break;
        case ZoomSDKMeetingError_forbidToJoinInternalMeeting:
            ret = ZNMEETING_FAIL_FORBID_TO_JOIN_INTERNAL_MEETING;
            break;
        case ZoomSDKMeetingError_HostDisallowOutsideUserJoin:
            ret = ZNMEETING_FAIL_HOST_DISALLOW_OUTSIDE_USER_JOIN;
            break;
        case ZoomSDKMeetingError_UnableToJoinExternalMeeting:
            ret = ZNMEETING_FAIL_UNABLE_TO_JOIN_EXTERNAL_MEETING;
            break;
        case ZoomSDKMeetingError_BlockedByAccountAdmin:
            ret = ZNMEETING_FAIL_BLOCKED_BY_ACCOUNT_ADMIN;
            break;
        case ZoomSDKMeetingError_NeedSigninForPrivateMeeting:
            ret = ZNMEETING_FAIL_NEED_SIGN_IN_FOR_PRIVATE_MEETING;
            break;
        case ZoomSDKMeetingError_AppPrivilegeTokenError:
            ret = ZNMEETING_FAIL_APP_PRIVILEGE_TOKEN_ERROR;
            break;
        case ZoomSDKMeetingError_JmakUserEmailNotMatch:
            ret = ZNMEETING_FAIL_JMAK_USER_EMAIL_NOT_MATCH;
            break;
        default:
            break;
    }
    return ret;
}

ZoomSDKLocale nativeErrorTypeHelp::ZNSDKAPPLocalType(ZNSDK_APP_Locale &local)
{
    ZoomSDKLocale applocal = ZoomSDKLocale_Def;
    switch (local) {
        case ZNSDK_APP_Locale_CN:
            applocal = ZoomSDKLocale_CN;
            break;
        case ZNSDK_APP_Locale_Default:
            applocal = ZoomSDKLocale_Def;
            break;
        default:
            break;
    }
    return applocal;
}

ZNSMSVerificationCodeErr nativeErrorTypeHelp::ZNSDKSMSVerificationCodeError(ZoomSDKSMSVerificationCodeError &code)
{
    ZNSMSVerificationCodeErr ret = ZNSMSVerificationCodeErr_Unknown;
    switch (code) {
        case ZoomSDKSMSError_Unkunow:
            ret = ZNSMSVerificationCodeErr_Unknown;
            break;
        case ZoomSDKSMSError_Success:
            ret = ZNSMSVerificationCodeErr_Success;
            break;
        case ZoomSDKSMSError_Retrieve_SendSMSFailed:
            ret = ZNSMSVerificationCodeErr_Retrieve_SendSMSFailed;
            break;
        case ZoomSDKSMSError_Retrieve_InvalidPhoneNum:
            ret = ZNSMSVerificationCodeErr_Retrieve_InvalidPhoneNum;
            break;
        case ZoomSDKSMSError_Retrieve_PhoneNumAlreadyBound:
            ret = ZNSMSVerificationCodeErr_Retrieve_PhoneNumAlreadyBound;
            break;
        case ZoomSDKSMSError_Retrieve_PhoneNumSendTooFrequent:
            ret = ZNSMSVerificationCodeErr_Retrieve_PhoneNumSendTooFrequent;
            break;
        case ZoomSDKSMSError_Verify_CodeIncorrect:
            ret = ZNSMSVerificationCodeErr_Verify_CodeIncorrect;
            break;
        case ZoomSDKSMSError_Verify_CodeExpired:
            ret = ZNSMSVerificationCodeErr_Verify_CodeExpired;
            break;
        case ZoomSDKSMSError_Verify_UnknownError:
            ret = ZNSMSVerificationCodeErr_Verify_UnknownError;
            break;
        default:
            break;
    }
    return ret;
}

ZNAudioCallbackActionInfo nativeErrorTypeHelp::ZNSDKAudioCallbackAction(ZoomSDKAudioActionInfo &info)
{
    ZNAudioCallbackActionInfo ret = ZNACTION_INFO_NONE;
    switch (info) {
        case ZoomSDKAudioActionInfo_none:
            ret = ZNACTION_INFO_NONE;
            break;
        case ZoomSDKAudioActionInfo_needJoinVoip:
            ret = ZNACTION_INFO_NEED_JOIN_VOIP;
            break;
        case ZoomSDKAudioActionInfo_muteOrUnmenuAudio:
            ret = ZNACTION_INFO_MUTE_UNMUTE_AUDIO;
            break;
        case ZoomSDKAudioActionInfo_noAudioDeviceConnected:
            ret = ZNACTION_INFO_CHOOSE_AUDIO_DEVICE_NOAUDIODEVICECONNECTTED;
            break;
        case ZoomSDKAudioActionInfo_computerAudioDeviceError:
            ret = ZNACTION_INFO_CHOOSE_AUDIO_DEVICE_COMPUTERAUDIODEVICEERROR;
            break;
        default:
            break;
    }
    return ret;
}

ZNWebinarNeedRegisterType nativeErrorTypeHelp::ZNSDKWebinarNeedRegisterType(WebinarRegisterType &type)
{
    ZNWebinarNeedRegisterType ret = ZNWebinarReg_NONE;
    switch (type) {
        case WebinarRegisterType_None:
            ret = ZNWebinarReg_NONE;
            break;
        case WebinarRegisterType_URL:
            ret = ZNWebinarReg_By_Register_Url;
            break;
        case WebinarRegisterType_Email:
            ret = ZNWebinarReg_By_Email_and_DisplayName;
            break;
        default:
            break;
    }
    return ret;
}

ZNRequiredInfoType nativeErrorTypeHelp::ZNSDKRequiredInfoType(JoinMeetingReqInfoType &type)
{
    ZNRequiredInfoType ret = ZNREQUIRED_INFO_TYPE_NONE;
    switch (type) {
        case JoinMeetingReqInfoType_None:
            ret = ZNREQUIRED_INFO_TYPE_NONE;
            break;
        case JoinMeetingReqInfoType_Password:
            ret = ZNREQUIRED_INFO_TYPE_Password;
            break;
        case JoinMeetingReqInfoType_Password_Wrong:
            ret = ZNREQUIRED_INFO_TYPE_Password4WrongPassword;
            break;
        default:
            break;
    }
    return ret;
}


ZNRecordingStatus nativeErrorTypeHelp::ZNRecordingStatusChange(ZoomSDKRecordingStatus &status)
{
    ZNRecordingStatus ZNStatus = ZNRecording_Stop;
    switch (status) {
        case ZoomSDKRecordingStatus_Stop:
            ZNStatus = ZNRecording_Stop;
            break;
        case ZoomSDKRecordingStatus_Pause:
            ZNStatus = ZNRecording_Pause;
            break;
        case ZoomSDKRecordingStatus_DiskFull:
            ZNStatus = ZNRecording_DiskFull;
            break;
        case ZoomSDKRecordingStatus_Start:
            ZNStatus = ZNRecording_Start;
            break;
        default:
            break;
    }
    return ZNStatus;
}

ZNRequestStartCloudRecordingStatus nativeErrorTypeHelp::ZNRequestStartCloudRecordingStatusMap(ZoomSDKRequestStartCloudRecordingStatus &status)
{
    ZNRequestStartCloudRecordingStatus zn_status = ZNRequestStartCloudRecording_Granted;
    switch (status) {
        case ZoomSDKRequestStartCloudRecordingStatus_Granted:
            zn_status = ZNRequestStartCloudRecording_Granted;
            break;
        case ZoomSDKRequestStartCloudRecordingStatus_Denied:
            zn_status = ZNRequestStartCloudRecording_Denied;
            break;
        case ZoomSDKRequestStartCloudRecordingStatus_TimedOut:
            zn_status = ZNRequestStartCloudRecording_TimedOut;
            break;
        default:
            break;
    }
    return zn_status;
}

ZNLoginFailReason nativeErrorTypeHelp::ZNLoginFailReasonMap(ZoomSDKLoginFailReason &reason)
{
    ZNLoginFailReason failReason = ZNLoginFail_None;
    switch(reason){
        case ZoomSDKLoginFailReason_None:
            failReason = ZNLoginFail_None;
            break;
        case ZoomSDKLoginFailReason_EmailLoginDisabled:
            failReason = ZNLoginFail_EmailLoginDisable;
            break;
        case ZoomSDKLoginFailReason_UserNotExist:
            failReason = ZNLoginFail_UserNotExist;
            break;
        case ZoomSDKLoginFailReason_WrongPassword:
            failReason = ZNLoginFail_WrongPassword;
            break;
        case ZoomSDKLoginFailReason_AccountLocked:
            failReason = ZNLoginFail_AccountLocked;
            break;
        case ZoomSDKLoginFailReason_SDKNeedUpdate:
            failReason = ZNLoginFail_SDKNeedUpdate;
            break;
        case ZoomSDKLoginFailReason_TooManyFailedAttempts:
            failReason = ZNLoginFail_TooManyFailedAttempts;
            break;
        case ZoomSDKLoginFailReason_SMSCodeError:
            failReason = ZNLoginFail_SMSCodeError;
            break;
        case ZoomSDKLoginFailReason_SMSCodeExpired:
            failReason = ZNLoginFail_SMSCodeExpired;
            break;
        case ZoomSDKLoginFailReason_PhoneNumberFormatInValid:
            failReason = ZNLoginFail_PhoneNumberFormatInValid;
            break;
        case ZoomSDKLoginFailReason_LoginTokenInvalid:
            failReason = ZNLoginFail_LoginTokenInvalid;
            break;
        case ZoomSDKLoginFailReason_Other_Issue:
            failReason = ZNLoginFail_OtherIssue;
            break;
        default:
            failReason = ZNLoginFail_OtherIssue;
            break;
    }
    return failReason;
}

ZNStatisticsWarningType nativeErrorTypeHelp::ZNStatisticsWarningTypeMap(StatisticWarningType &type)
{
    ZNStatisticsWarningType warningType = ZNStatistics_Warning_None;
    switch (type) {
        case StatisticWarningType_None:
            warningType = ZNStatistics_Warning_None;
            break;
        case StatisticWarningType_NetworkBad:
            warningType = ZNStatistics_Warning_Network_Quality_Bad;
            break;
        case StatisticWarningType_CPUHigh:
        case StatisticWarningType_SystemBusy:
            warningType = ZNStatistics_Warning_Busy_System;
            break;
        default:
            break;
    }
    return warningType;
}

ZNAudioShareMode nativeErrorTypeHelp::ZNAudioShareModeMap(ZoomSDKAudioShareMode &mode)
{
    ZNAudioShareMode shareMode = ZNAudioShareMode_Mono;
    switch (mode) {
        case ZoomSDKAudioShareMode_Mono:
            shareMode = ZNAudioShareMode_Mono;
            break;
        case ZoomSDKAudioShareMode_Stereo:
            shareMode = ZNAudioShareMode_Stereo;
            break;
            
        default:
            break;
    }
    return shareMode;
}

ZoomSDKAudioShareMode nativeErrorTypeHelp::ZoomSDKAudioShareModeMap(ZNAudioShareMode &mode)
{
    ZoomSDKAudioShareMode shareMode = ZoomSDKAudioShareMode_Mono;
    switch (mode) {
        case ZNAudioShareMode_Mono:
            shareMode = ZoomSDKAudioShareMode_Mono;
            break;
        case ZNAudioShareMode_Stereo:
            shareMode = ZoomSDKAudioShareMode_Stereo;
            break;
            
        default:
            break;
    }
    return shareMode;
}

ZNLiveStreamStatus nativeErrorTypeHelp::ZNLiveStreamStatusMap(LiveStreamStatus &status)
{
    ZNLiveStreamStatus liveStreamStatus = ZN_LiveStreamStatus_None;
    switch (status) {
        case LiveStreamStatus_None:
            liveStreamStatus = ZN_LiveStreamStatus_None;
            break;
        case LiveStreamStatus_InProgress:
            liveStreamStatus = ZN_LiveStreamStatus_InProgress;
            break;
        case LiveStreamStatus_Connecting:
            liveStreamStatus = ZN_LiveStreamStatus_Connecting;
            break;
        case LiveStreamStatus_StartFailedTimeout:
            liveStreamStatus = ZN_LiveStreamStatus_Start_Failed_Timeout;
            break;
        case LiveStreamStatus_StartFailed:
            liveStreamStatus = ZN_LiveStreamStatus_Start_Failed;
            break;
        case LiveStreamStatus_Ended:
            liveStreamStatus = ZN_LiveStreamStatus_Ended;
            break;
        default:
            break;
    }
    return liveStreamStatus;
}

ZNMeetingReminderType nativeErrorTypeHelp::ZNReminderTypeMap(ZoomSDKReminderType &type)
{
    ZNMeetingReminderType reminder_type = ZNTYPE_LOGIN_REQUIRED;
    switch (type) {
        case ZoomSDKReminderType_LoginRequired:
            reminder_type = ZNTYPE_LOGIN_REQUIRED;
            break;
        case ZoomSDKReminderType_StartOrJoinMeeting:
            reminder_type = ZNTYPE_START_OR_JOIN_MEETING;
            break;
        case ZoomSDKReminderType_RecordReminder:
            reminder_type = ZNTYPE_RECORD_REMINDER;
            break;
        case ZoomSDKReminderType_LiveStreamDisclaimer:
            reminder_type = ZNTYPE_LIVE_STREAM_DISCLAIMER;
            break;
        case ZoomSDKReminderType_ArchiveDisclaimer:
            reminder_type = ZNTYPE_ARCHIVE_DISCLAIMER;
            break;
        case ZoomSDKReminderType_WebinarAsPanelistJoin:
            reminder_type = ZNTYPE_WEBINAR_AS_PANELIST_JOIN;
            break;
        case ZoomSDKReminderType_TermsService:
            reminder_type = ZNTYPE_TERMS_OF_SERVICE;
            break;
        case ZoomSDKReminderType_SmartSummaryDisclaimer:
            reminder_type = ZNTYPE_SMART_SUMMARY_DISCLAIMER;
            break;
        case ZoomSDKReminderType_SmartSummaryEnableRequestReminder:
            reminder_type = ZNTYPE_SMART_SUMMARY_ENABLE_REQUEST_REMINDER;
            break;
        case ZoomSDKReminderType_QueryDisclaimer:
            reminder_type = ZNTYPE_QUERY_DISCLAIMER;
            break;
        case ZoomSDKReminderType_QueryEnableRequestReminder:
            reminder_type = ZNTYPE_QUERY_ENABLE_REQUEST_REMINDER;
            break;
        case ZoomSDKReminderType_EnableSmartSummaryReminder:
            reminder_type = ZNTYPE_ENABLE_SMART_SUMMARY_REMINDER;
            break;
        case ZoomSDKReminderType_WebinarAttendeePromoteReminder:
            reminder_type = ZNTYPE_WEBINAR_ATTENDEE_PROMOTE_REMINDER;
            break;
        case ZoomSDKReminderType_JoinMeetingPrivateModeReminder:
            reminder_type = ZNTYPE_JOIN_PRIVATE_MODE_MEETING_REMINDER;
            break;
        case ZoomSDKReminderType_SmartRecordingEnableRequestReminder:
            reminder_type = ZNTYPE_SMART_RECORDING_ENABLE_REQUEST_REMINDER;
            break;
        case ZoomSDKReminderType_EnableSmartRecordingReminder:
            reminder_type = ZNTYPE_ENABLE_SMART_RECORDING_REMINDER;
            break;
        case ZoomSDKReminderType_AICompanionPlusDisclaimer:
            reminder_type = ZNTYPE_AI_COMPANION_PLUS_DISCLAIMER;
            break;
        default:
            break;
    }
    return reminder_type;
}

ZoomSDKChatPriviledgeType nativeErrorTypeHelp::ZoomSDKChatPriviledgeTypeMap(ZNSDKChatPrivilege &privilege)
{
    ZoomSDKChatPriviledgeType ret = ZoomSDKChatPriviledgeType_To_Everyone;
    switch (privilege) {
        case ZNSDK_CHAT_PRIVILEGE_ALL:
            ret = ZoomSDKChatPriviledgeType_To_Everyone;
            break;
        case ZNSDK_CHAT_PRIVILEGE_ALL_PANELIST:
            ret = ZoomSDKChatPriviledgeType_To_All_Panelist;
            break;
        case ZNSDK_CHAT_PRIVILEGE_HOST:
            ret = ZoomSDKChatPriviledgeType_To_Host;
            break;
        case ZNSDK_CHAT_PRIVILEGE_DISABLE_ATTENDEE_CHAT:
            ret = ZoomSDKChatPriviledgeType_Disable_Attendee_Chat;
            break;
        case ZNSDK_CHAT_PRIVILEGE_HOST_PUBLIC:
            ret = ZoomSDKChatPriviledgeType_Host_Public;
            break;
        default:
            break;
    }
    return ret;
}

ZoomSDKChatMessageType nativeErrorTypeHelp::ZoomSDKChatMessageTypeMap(ZNSDKChatMessageType &type)
{
    ZoomSDKChatMessageType ret = ZoomSDKChatMessageType_To_None;
    switch (type) {
        case ZNSDKChatMessageType_To_None:
            ret = ZoomSDKChatMessageType_To_None;
            break;
        case ZNSDKChatMessageType_To_All:
            ret = ZoomSDKChatMessageType_To_All;
            break;
        case ZNSDKChatMessageType_To_All_Panelist:
            ret = ZoomSDKChatMessageType_To_All_Panelist;
            break;
        case ZNSDKChatMessageType_To_Individual_Panelist:
            ret = ZoomSDKChatMessageType_To_Individual_Panelist;
            break;
        case ZNSDKChatMessageType_To_Individual:
            ret = ZoomSDKChatMessageType_To_Individual;
            break;
        case ZNSDKChatMessageType_To_WaitingRoomUsers:
            ret = ZoomSDKChatMessageType_To_WaitingRoomUsers;
            break;
        default:
            break;
    }
    return ret;
}

ZNSDKChatMessageType nativeErrorTypeHelp::ZNSDKChatMessageTypeMap(ZoomSDKChatMessageType &type)
{
    ZNSDKChatMessageType ret = ZNSDKChatMessageType_To_None;
    switch (type) {
        case ZoomSDKChatMessageType_To_None:
            ret = ZNSDKChatMessageType_To_None;
            break;
        case ZoomSDKChatMessageType_To_All:
            ret = ZNSDKChatMessageType_To_All;
            break;
        case ZoomSDKChatMessageType_To_All_Panelist:
            ret = ZNSDKChatMessageType_To_All_Panelist;
            break;
        case ZoomSDKChatMessageType_To_Individual_Panelist:
            ret = ZNSDKChatMessageType_To_Individual_Panelist;
            break;
        case ZoomSDKChatMessageType_To_Individual:
            ret = ZNSDKChatMessageType_To_Individual;
            break;
        case ZoomSDKChatMessageType_To_WaitingRoomUsers:
            ret = ZNSDKChatMessageType_To_WaitingRoomUsers;
            break;
        default:
            break;
    }
    return ret;
}

ZNSDKChatMessageDeleteType nativeErrorTypeHelp::ZNSDKChatMessageDeleteTypeMap(ZoomSDKChatMessageDeleteType &type)
{
    ZNSDKChatMessageDeleteType ret = ZNSDK_CHAT_DELETE_BY_NONE;
    switch (type) {
        case ZoomSDK_Chat_Delete_By_None:
            ret = ZNSDK_CHAT_DELETE_BY_NONE;
            break;
        case ZoomSDK_Chat_Delete_By_Self:
            ret = ZNSDK_CHAT_DELETE_BY_SELF;
            break;
        case ZoomSDK_Chat_Delete_By_Host:
            ret = ZNSDK_CHAT_DELETE_BY_HOST;
            break;
        case ZoomSDK_Chat_Delete_By_Dlp:
            ret = ZNSDK_CHAT_DELETE_BY_DLP;
            break;
        default:
            break;
    }
    return ret;
}

ZNAudioType nativeErrorTypeHelp::ZNAudioTypeMap(ZoomSDKAudioType &type)
{
    ZNAudioType ret = ZN_AUDIOTYPE_NONE;
    switch (type) {
        case ZoomSDKAudioType_None:
            ret = ZN_AUDIOTYPE_NONE;
            break;
        case ZoomSDKAudioType_Voip:
            ret = ZN_AUDIOTYPE_VOIP;
            break;
        case ZoomSDKAudioType_Phone:
            ret = ZN_AUDIOTYPE_PHONE;
            break;
        case ZoomSDKAudioType_Unknow:
            ret = ZN_AUDIOTYPE_UNKNOW;
            break;
        default:
            break;
    }
    return ret;
}

ZNSDKEmojiFeedbackType nativeErrorTypeHelp::ZNSDKEmojiFeedbackTypeMap(ZoomSDKEmojiFeedbackType &type)
{
    ZNSDKEmojiFeedbackType ret = ZNSDKEmojiFeedbackType_None;
    switch (type) {
        case ZoomSDKEmojiFeedbackType_None:
            ret = ZNSDKEmojiFeedbackType_None;
            break;
        case ZoomSDKEmojiFeedbackType_Yes:
            ret = ZNSDKEmojiFeedbackType_Yes;
            break;
        case ZoomSDKEmojiFeedbackType_No:
            ret = ZNSDKEmojiFeedbackType_No;
            break;
        case ZoomSDKEmojiFeedbackType_SpeedUp:
            ret = ZNSDKEmojiFeedbackType_SpeedUp;
            break;
        case ZoomSDKEmojiFeedbackType_SlowDown:
            ret = ZNSDKEmojiFeedbackType_SlowDown;
            break;
        case ZoomSDKEmojiFeedbackType_Away:
            ret = ZNSDKEmojiFeedbackType_Away;
            break;
        default:
            break;
    }
    return ret;
}

ZNWaitingRoomLayoutType nativeErrorTypeHelp::ZNWaitingRoomLayoutTypeMap(ZoomSDKWaitingRoomLayoutType &type)
{
    ZNWaitingRoomLayoutType ret = ZNWaitingRoomLayoutType_Default;
    switch (type) {
        case ZoomSDKWaitingRoomLayoutType_Default:
            ret = ZNWaitingRoomLayoutType_Default;
            break;
        case ZoomSDKWaitingRoomLayoutType_Logo:
            ret = ZNWaitingRoomLayoutType_Logo;
            break;
        case ZoomSDKWaitingRoomLayoutType_Video:
            ret = ZNWaitingRoomLayoutType_Video;
            break;
        default:
            break;
    }
    return ret;
}

ZNCustomWaitingRoomDataStatus nativeErrorTypeHelp::ZNCustomWaitingRoomDataStatusMap(ZoomSDKCustomWaitingRoomDataStatus &status)
{
    ZNCustomWaitingRoomDataStatus ret = ZNCustomWaitingRoomDataStatus_Init;
    switch (status) {
        case ZoomSDKCustomWaitingRoomDataStatus_Init:
            ret = ZNCustomWaitingRoomDataStatus_Init;
            break;
        case ZoomSDKCustomWaitingRoomDataStatus_Downloading:
            ret = ZNCustomWaitingRoomDataStatus_Downloading;
            break;
        case ZoomSDKCustomWaitingRoomDataStatus_Download_OK:
            ret = ZNCustomWaitingRoomDataStatus_Download_OK;
            break;
        case ZoomSDKCustomWaitingRoomDataStatus_Download_Failed:
            ret = ZNCustomWaitingRoomDataStatus_Download_Failed;
            break;
        default:
            break;
        }
    return ret;
}