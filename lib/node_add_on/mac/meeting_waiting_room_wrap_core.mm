#include "Header_include.h"
#include "sdk_native_error.h"
#include "meeting_waiting_room_wrap_core.h"
#include "meeting_service_wrap_core.h"
#import "meetingServiceDelegate.h"
ZMeetingWaitingRoomWrap &ZMeetingServiceWrap::GetMeetingWaitingRoomCtrl()
{
    return m_meeting_waiting_room_ctrl;
}
ZMeetingWaitingRoomWrap::ZMeetingWaitingRoomWrap()
{
   m_pSink = 0;
}

ZMeetingWaitingRoomWrap::~ZMeetingWaitingRoomWrap()
{
    m_pSink = 0;
    [[[[ZoomSDK sharedSDK] getMeetingService] getWaitingRoomController] setDelegate:nil];
}

void ZMeetingWaitingRoomWrap::Init()
{

}
void ZMeetingWaitingRoomWrap::Uninit()
{
    
}

void ZMeetingWaitingRoomWrap::SetSink(ZNativeSDKMeetingWaitingRoomWrapSink *pSink)
{
    [[[[ZoomSDK sharedSDK] getMeetingService] getWaitingRoomController] setDelegate:[meetingServiceWaitingRoomDelegate share]];
    m_pSink= pSink;
}

bool ZMeetingWaitingRoomWrap::IsSupportWaitingRoom()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return false;
  
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return false;
    
    return [waitingRoomController isSupportWaitingRoom];
}

bool ZMeetingWaitingRoomWrap::IsWaitingRoomOnEntryFlagOn()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return false;
  
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return false;
    
    return [waitingRoomController isEnableWaitingRoomOnEntry];
}

ZNSDKError ZMeetingWaitingRoomWrap::EnableWaitingRoomOnEntry(bool enable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return ZNSDKERR_SERVICE_FAILED;
  
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [waitingRoomController enableWaitingRoomOnEntry:enable];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNList<unsigned int> ZMeetingWaitingRoomWrap::GetWaitingRoomList()
{
    ZNList<unsigned int> list;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return list;
    
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return list;

    NSArray *arr = [waitingRoomController getWaitRoomUserList];
    if (arr && arr.count > 0) {
        for (NSNumber* number in arr) {
            if(!number)
                continue;
            unsigned int userid = [number unsignedIntValue];
            list.push_back(userid);
        }
    }
    return list;
}
 
ZNUserInfomation ZMeetingWaitingRoomWrap::GetWaitingRoomUserInfoByID(unsigned int userid)
{
    ZNUserInfomation zn_userInfo;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return zn_userInfo;
  
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return zn_userInfo;

    ZoomSDKUserInfo* userInfo = [waitingRoomController getWaitingRoomUserInfo:userid];
    zn_userInfo.userInfoType = ZN_FAKE_USERINFO;
    if (userInfo)
    {
        NSString *userName = [userInfo getUserName];
        if (!userName) {
            userName = @"";
        }
        zn_userInfo.userName = userName.UTF8String;

        zn_userInfo.isHost = [userInfo isHost];
        zn_userInfo.userID = [userInfo getUserID];
        NSString *avatarPath = [userInfo getAvatarPath];
        if (!avatarPath) {
            avatarPath = @"";
        }
        zn_userInfo.avatarPath = [avatarPath UTF8String];

        NSString *persistentId = [userInfo getPersistentId];
        if (!persistentId) {
            persistentId = @"";
        }
        zn_userInfo.persistentId = [persistentId UTF8String];

        NSString *customerKey = [userInfo getCustomerKey];
        if (!customerKey) {
            customerKey = @"";
        }
        zn_userInfo.customerKey = [customerKey UTF8String];

        zn_userInfo.isVideoOn = [userInfo isVideoOn];

        ZoomSDKAudioStatus audioStatus = [userInfo getAudioStatus];
        if (audioStatus == ZoomSDKAudioStatus_Muted)
        {
            zn_userInfo.isAudioMuted = YES;
        } else {
            zn_userInfo.isAudioMuted = NO;
        }

        zn_userInfo.isMySelf = [userInfo isMySelf];

        nativeErrorTypeHelp Help_type;
        UserRole roles = [userInfo getUserRole];
        zn_userInfo.userRole = Help_type.ZNSDKUserRole(roles);

        zn_userInfo.isPurePhoneUser = [userInfo isPurePhoneUser];
        zn_userInfo.isTalking = [userInfo isTalking];
        zn_userInfo.isH323User = [userInfo isH323User];

        ZoomSDKWebinarAttendeeStatus *webinarStatus = [userInfo GetWebinarAttendeeStatus];
        if (webinarStatus)
        {
            zn_userInfo.webinarAttendeeStatus = webinarStatus.isAttendeeCanTalk;
        }

        ZoomSDKRecordingStatus recordingStatus = [userInfo getLocalRecordingStatus];
        zn_userInfo.localRecordingStatus = Help_type.ZNRecordingStatusChange(recordingStatus);

        zn_userInfo.userInfoType = ZN_REAL_USERINFO;
        zn_userInfo.isRawLiveStreaming = [userInfo isRawLiveStreaming];
        zn_userInfo.HasRawLiveStreamPrivilege = [userInfo hasRawLiveStreamPrivilege];
        zn_userInfo.hasCamera = [userInfo hasCamera];

        ZoomSDKAudioType audioType = [userInfo getAudioType];
        zn_userInfo.audioJoinType = Help_type.ZNAudioTypeMap(audioType);

        zn_userInfo.isRaiseHand = [userInfo isRaisingHand];
        zn_userInfo.isInterpreter = [userInfo isInterpreter];
        zn_userInfo.isSignLanguageInterpreter = [userInfo isSignLanguageInterpreter];

        NSString *interpreterActiveLanguage = [userInfo getInterpreterActiveLanguage];
        if (!interpreterActiveLanguage) {
            interpreterActiveLanguage = @"";
        }
        zn_userInfo.interpreterActiveLanguage = [interpreterActiveLanguage UTF8String];

        ZoomSDKEmojiFeedbackType emojiFeedbackType = [userInfo getEmojiFeedbackType];
        zn_userInfo.emojiFeedbackType = Help_type.ZNSDKEmojiFeedbackTypeMap(emojiFeedbackType);
    } 
    return zn_userInfo;
}

ZNSDKError ZMeetingWaitingRoomWrap::AdmitToMeeting(unsigned int userid)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return ZNSDKERR_SERVICE_FAILED;
  
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [waitingRoomController admitToMeeting:userid];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingWaitingRoomWrap::AdmitAllToMeeting()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return ZNSDKERR_SERVICE_FAILED;
    
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [waitingRoomController admitAllToMeeting];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingWaitingRoomWrap::PutInWaitingRoom(unsigned int userid)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return ZNSDKERR_SERVICE_FAILED;
    
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [waitingRoomController putIntoWaitingRoom:userid];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

bool ZMeetingWaitingRoomWrap::IsAudioEnabledInWaitingRoom()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return false;
  
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return false;

    return [waitingRoomController isAudioEnabledInWaitingRoom];
}

bool ZMeetingWaitingRoomWrap::IsVideoEnabledInWaitingRoom()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return false;
    
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return false;

    return [waitingRoomController isVideoEnabledInWaitingRoom];
}

ZNSDKError ZMeetingWaitingRoomWrap::RequestCustomWaitingRoomData()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return ZNSDKERR_SERVICE_FAILED;
    
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [waitingRoomController requestCustomWaitingRoomData];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

bool ZMeetingWaitingRoomWrap::CanRenameUser()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return false;
  
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return false;

    return [waitingRoomController canRenameUser];
}

ZNSDKError ZMeetingWaitingRoomWrap::RenameUser(unsigned userid, ZoomSTRING newName)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return ZNSDKERR_SERVICE_FAILED;
  
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return ZNSDKERR_SERVICE_FAILED;

    if (newName.empty())
    {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    NSString *userName = [NSString stringWithUTF8String:newName.c_str()];
    ZoomSDKError ret = [waitingRoomController renameUser:userid newUserName:userName];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

bool ZMeetingWaitingRoomWrap::CanExpelUser()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return false;
    
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return false;

    return [waitingRoomController canExpelUser];
}

ZNSDKError ZMeetingWaitingRoomWrap::ExpelUser(unsigned userid)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return ZNSDKERR_SERVICE_FAILED;
  
    ZoomSDKWaitingRoomController *waitingRoomController = [service getWaitingRoomController];
    if (!waitingRoomController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [waitingRoomController expelUser:userid];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingWaitingRoomWrap::Retry()
{
    ZoomSDKWaitingRoomDataDownloadHandler *handler = [meetingServiceWaitingRoomDelegate share].waitingRoomHandler;
    if (handler) {
        [handler retry];
        return ZNSDKERR_SUCCESS;
    }
    return ZNSDKERR_WRONG_USEAGE;
}

ZNSDKError ZMeetingWaitingRoomWrap::Ignore()
{
    ZoomSDKWaitingRoomDataDownloadHandler *handler = [meetingServiceWaitingRoomDelegate share].waitingRoomHandler;
    if (handler) {
        [handler ignore];
        return ZNSDKERR_SUCCESS;
    }
    return ZNSDKERR_WRONG_USEAGE;
}

//callback
void ZMeetingWaitingRoomWrap::onWaitingRoomUserJoin(unsigned int userid)
{
    if (m_pSink) {
        m_pSink->onWaitingRoomUserJoin(userid);
    }
}

void ZMeetingWaitingRoomWrap::onWaitingRoomUserLeft(unsigned int userid)
{
    if (m_pSink) {
        m_pSink->onWaitingRoomUserLeft(userid);
    }
}

void ZMeetingWaitingRoomWrap::onWaitingRoomPresetAudioStatusChanged(bool bAudioCanTurnOn)
{
    if (m_pSink) {
        m_pSink->onWaitingRoomPresetAudioStatusChanged(bAudioCanTurnOn);
    }
}

void ZMeetingWaitingRoomWrap::onWaitingRoomPresetVideoStatusChanged(bool bVideoCanTurnOn)
{
    if (m_pSink) {
        m_pSink->onWaitingRoomPresetVideoStatusChanged(bVideoCanTurnOn);
    }
}

void ZMeetingWaitingRoomWrap::onCustomWaitingRoomDataUpdated(ZNCustomWaitingRoomData bData)
{
    if (m_pSink) {
        m_pSink->onCustomWaitingRoomDataUpdated(bData);
    }
}

void ZMeetingWaitingRoomWrap::onWaitingRoomUserNameChanged(unsigned int userID, ZoomSTRING userName)
{
    if (m_pSink) {
        m_pSink->onWaitingRoomUserNameChanged(userID, userName.c_str());
    }
}

void ZMeetingWaitingRoomWrap::onWaitingRoomEntranceEnabled(bool bIsEnabled)
{
    if (m_pSink) {
        m_pSink->onWaitingRoomEntranceEnabled(bIsEnabled);
    }
}