#include "Header_include.h"
#include "sdk_native_error.h"
#include "meeting_smart_summary_wrap_core.h"
#include "meeting_service_wrap_core.h"
#import "meetingServiceDelegate.h"
ZMeetingSmartSummaryWrap &ZMeetingServiceWrap::GetMeetingSmartSummaryCtrl()
{
    return m_meeting_smart_summary_ctrl;
}
ZMeetingSmartSummaryWrap::ZMeetingSmartSummaryWrap()
{
   m_pSink = 0;
}

ZMeetingSmartSummaryWrap::~ZMeetingSmartSummaryWrap()
{
    m_pSink = 0;
    [[[ZoomSDK sharedSDK] getMeetingSmartSummaryController] setDelegate:nil];
}

void ZMeetingSmartSummaryWrap::Init()
{

}
void ZMeetingSmartSummaryWrap::Uninit()
{
    
}

void ZMeetingSmartSummaryWrap::SetSink(ZNativeSDKMeetingSmartSummaryWrapSink *pSink)
{
    [[[ZoomSDK sharedSDK] getMeetingSmartSummaryController] setDelegate:[meetingServiceSmartSummaryDelegate share]];
    m_pSink= pSink;
}

bool ZMeetingSmartSummaryWrap::IsSmartSummarySupported()
{
    ZoomSDKMeetingSmartSummaryController *smartSummaryController = [[ZoomSDK sharedSDK] getMeetingSmartSummaryController];
    if (!smartSummaryController)
        return false;
    
    return [smartSummaryController isSmartSummarySupported];
}

bool ZMeetingSmartSummaryWrap::IsSmartSummaryEnabled()
{
    ZoomSDKMeetingSmartSummaryController *smartSummaryController = [[ZoomSDK sharedSDK] getMeetingSmartSummaryController];
    if (!smartSummaryController)
        return false;
    
    return [smartSummaryController isSmartSummaryEnabled];
}

ZNSDKError ZMeetingSmartSummaryWrap::CanEnableSmartSummaryFeature()
{
    ZoomSDKMeetingSmartSummaryController *smartSummaryController = [[ZoomSDK sharedSDK] getMeetingSmartSummaryController];
    if (!smartSummaryController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [smartSummaryController canEnableSmartSummaryFeature];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingSmartSummaryWrap::EnableSmartSummaryFeature()
{
    ZoomSDKMeetingSmartSummaryController *smartSummaryController = [[ZoomSDK sharedSDK] getMeetingSmartSummaryController];
    if (!smartSummaryController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [smartSummaryController enableSmartSummaryFeature];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingSmartSummaryWrap::CanStartSmartSummary()
{
    ZoomSDKMeetingSmartSummaryController *smartSummaryController = [[ZoomSDK sharedSDK] getMeetingSmartSummaryController];
    if (!smartSummaryController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [smartSummaryController canStartSmartSummary];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingSmartSummaryWrap::StartSmartSummary()
{
    ZoomSDKMeetingSmartSummaryController *smartSummaryController = [[ZoomSDK sharedSDK] getMeetingSmartSummaryController];
    if (!smartSummaryController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [smartSummaryController startSmartSummary];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingSmartSummaryWrap::StopSmartSummary()
{
    ZoomSDKMeetingSmartSummaryController *smartSummaryController = [[ZoomSDK sharedSDK] getMeetingSmartSummaryController];
    if (!smartSummaryController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [smartSummaryController stopSmartSummary];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

bool ZMeetingSmartSummaryWrap::IsSmartSummaryStarted()
{
    ZoomSDKMeetingSmartSummaryController *smartSummaryController = [[ZoomSDK sharedSDK] getMeetingSmartSummaryController];
    if (!smartSummaryController)
        return false;

    return [smartSummaryController isSmartSummaryStarted];
}

ZNSDKError ZMeetingSmartSummaryWrap::CanRequestEnableSmartSummaryFeature()
{
    ZoomSDKMeetingSmartSummaryController *smartSummaryController = [[ZoomSDK sharedSDK] getMeetingSmartSummaryController];
    if (!smartSummaryController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [smartSummaryController canRequestEnableSmartSummaryFeature];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingSmartSummaryWrap::RequestEnableSmartSummaryFeature()
{
    ZoomSDKMeetingSmartSummaryController *smartSummaryController = [[ZoomSDK sharedSDK] getMeetingSmartSummaryController];
    if (!smartSummaryController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [smartSummaryController requestEnableSmartSummaryFeature];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingSmartSummaryWrap::CanRequestStartSmartSummary()
{
    ZoomSDKMeetingSmartSummaryController *smartSummaryController = [[ZoomSDK sharedSDK] getMeetingSmartSummaryController];
    if (!smartSummaryController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [smartSummaryController canRequestStartSmartSummary];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingSmartSummaryWrap::RequestStartSmartSummary()
{
    ZoomSDKMeetingSmartSummaryController *smartSummaryController = [[ZoomSDK sharedSDK] getMeetingSmartSummaryController];
    if (!smartSummaryController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [smartSummaryController requestStartSmartSummary];
    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingSmartSummaryWrap::Accept()
{
    ZoomSDKMeetingSmartSummaryPrivilegeHandler *handler = [meetingServiceSmartSummaryDelegate share].smartSummaryHandler;
    if (handler) {
        ZoomSDKError ret = [handler accept];
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_WRONG_USEAGE;
}

ZNSDKError ZMeetingSmartSummaryWrap::Decline()
{
    ZoomSDKMeetingSmartSummaryPrivilegeHandler *handler = [meetingServiceSmartSummaryDelegate share].smartSummaryHandler;
    if (handler) {
        ZoomSDKError ret = [handler decline];
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_WRONG_USEAGE;
}

ZNSDKError ZMeetingSmartSummaryWrap::Ignore()
{
    ZoomSDKMeetingSmartSummaryPrivilegeHandler *handler = [meetingServiceSmartSummaryDelegate share].smartSummaryHandler;
    if (handler) {
        ZoomSDKError ret = [handler ignore];
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_WRONG_USEAGE;
}

//callback
void ZMeetingSmartSummaryWrap::onSmartSummaryStatusChange(bool isStarted)
{
    if (m_pSink) {
        m_pSink->onSmartSummaryStatusChange(isStarted);
    }
}

void ZMeetingSmartSummaryWrap::onSmartSummaryPrivilegeRequested(unsigned int senderId)
{
    if (m_pSink) {
        m_pSink->onSmartSummaryPrivilegeRequested(senderId);
    }
}

void ZMeetingSmartSummaryWrap::onSmartSummaryStartReqResponse(bool timeout, bool decline)
{
    if (m_pSink) {
        m_pSink->onSmartSummaryStartReqResponse(timeout, decline);
    }
}

void ZMeetingSmartSummaryWrap::onEnableSmartSummary()
{
    if (m_pSink) {
        m_pSink->onEnableSmartSummary();
    }
}