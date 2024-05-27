#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZMeetingSmartSummaryWrap
{
public:
	ZMeetingSmartSummaryWrap();
	virtual ~ZMeetingSmartSummaryWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingSmartSummaryWrapSink* pSink);

	bool IsSmartSummarySupported();
	bool IsSmartSummaryEnabled();
	ZNSDKError CanEnableSmartSummaryFeature();
	ZNSDKError EnableSmartSummaryFeature();
	ZNSDKError CanStartSmartSummary();
	ZNSDKError StartSmartSummary();
	ZNSDKError StopSmartSummary();
	bool IsSmartSummaryStarted();
	ZNSDKError CanRequestEnableSmartSummaryFeature();
	ZNSDKError RequestEnableSmartSummaryFeature();
	ZNSDKError CanRequestStartSmartSummary();
	ZNSDKError RequestStartSmartSummary();

	ZNSDKError Accept();
	ZNSDKError Decline();
	ZNSDKError Ignore();

	//callback
	void onSmartSummaryStatusChange(bool isStarted);
	void onSmartSummaryPrivilegeRequested(unsigned int senderId);
	void onSmartSummaryStartReqResponse(bool timeout, bool decline);
	void onEnableSmartSummary();
	
private:
	ZNativeSDKMeetingSmartSummaryWrapSink* m_pSink;
};