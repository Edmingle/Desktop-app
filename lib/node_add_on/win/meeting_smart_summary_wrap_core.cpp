#include "meeting_smart_summary_wrap_core.h"
#include "sdk_wrap.h"
#include "meeting_service_components_wrap/meeting_smart_summary_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"

extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;

ZMeetingSmartSummaryWrap::ZMeetingSmartSummaryWrap()
{
	SDKEventWrapMgr::GetInst().m_meetingSmartSummaryCtrlEvent.SetOwner(this);
	m_pSink = NULL;
}
ZMeetingSmartSummaryWrap::~ZMeetingSmartSummaryWrap()
{
	Uninit();
	m_pSink = NULL;
	SDKEventWrapMgr::GetInst().m_meetingSmartSummaryCtrlEvent.SetOwner(NULL);
}
void ZMeetingSmartSummaryWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().SetEvent(&SDKEventWrapMgr::GetInst().m_meetingSmartSummaryCtrlEvent);
}
void ZMeetingSmartSummaryWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().Uninit_Wrap();
}
void ZMeetingSmartSummaryWrap::SetSink(ZNativeSDKMeetingSmartSummaryWrapSink* pSink)
{
	m_pSink = pSink;
}
bool ZMeetingSmartSummaryWrap::IsSmartSummarySupported()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().IsSmartSummarySupported();
}
bool ZMeetingSmartSummaryWrap::IsSmartSummaryEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().IsSmartSummaryEnabled();
}
ZNSDKError ZMeetingSmartSummaryWrap::CanEnableSmartSummaryFeature()
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().CanEnableSmartSummaryFeature();
	return Map2WrapDefine(sdkerr);
}
ZNSDKError ZMeetingSmartSummaryWrap::EnableSmartSummaryFeature()
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().EnableSmartSummaryFeature();
	return Map2WrapDefine(sdkerr);
}
ZNSDKError ZMeetingSmartSummaryWrap::CanStartSmartSummary()
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().CanStartSmartSummary();
	return Map2WrapDefine(sdkerr);
}
ZNSDKError ZMeetingSmartSummaryWrap::StartSmartSummary()
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().StartSmartSummary();
	return Map2WrapDefine(sdkerr);
}
ZNSDKError ZMeetingSmartSummaryWrap::StopSmartSummary()
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().StopSmartSummary();
	return Map2WrapDefine(sdkerr);
}
bool ZMeetingSmartSummaryWrap::IsSmartSummaryStarted()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().IsSmartSummaryStarted();
}
ZNSDKError ZMeetingSmartSummaryWrap::CanRequestEnableSmartSummaryFeature()
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().CanRequestEnableSmartSummaryFeature();
	return Map2WrapDefine(sdkerr);
}
ZNSDKError ZMeetingSmartSummaryWrap::RequestEnableSmartSummaryFeature()
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().RequestEnableSmartSummaryFeature();
	return Map2WrapDefine(sdkerr);
}
ZNSDKError ZMeetingSmartSummaryWrap::CanRequestStartSmartSummary()
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().CanRequestStartSmartSummary();
	return Map2WrapDefine(sdkerr);
}
ZNSDKError ZMeetingSmartSummaryWrap::RequestStartSmartSummary()
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingSmartSummaryController().RequestStartSmartSummary();
	return Map2WrapDefine(sdkerr);
}
void ZMeetingSmartSummaryWrap::onSmartSummaryStatusChange(bool isStarted)
{
	if (m_pSink)
	{
		m_pSink->onSmartSummaryStatusChange(isStarted);
	}
}
void ZMeetingSmartSummaryWrap::onSmartSummaryPrivilegeRequested(unsigned int senderId)
{
	if (m_pSink)
	{
		m_pSink->onSmartSummaryPrivilegeRequested(senderId);
	}
}
void ZMeetingSmartSummaryWrap::onSmartSummaryStartReqResponse(bool timeout, bool decline)
{
	if (m_pSink)
	{
		m_pSink->onSmartSummaryStartReqResponse(timeout, decline);
	}
}
void ZMeetingSmartSummaryWrap::onEnableSmartSummary()
{
	if (m_pSink)
	{
		m_pSink->onEnableSmartSummary();
	}
}
ZNSDKError ZMeetingSmartSummaryWrap::Accept()
{
	return ZMeetingSmartSummaryHandler::GetInst().Accept();
}
ZNSDKError ZMeetingSmartSummaryWrap::Decline()
{
	return ZMeetingSmartSummaryHandler::GetInst().Decline();
}
ZNSDKError ZMeetingSmartSummaryWrap::Ignore()
{
	return ZMeetingSmartSummaryHandler::GetInst().Ignore();
}