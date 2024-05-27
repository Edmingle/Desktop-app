#ifndef _ZOOM_NODE_MEETING_SMART_SUMMARY_CTRL_H_
#define _ZOOM_NODE_MEETING_SMART_SUMMARY_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingSmartSummaryCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingSmartSummaryCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingSmartSummaryCtrlWrap >;
private:
	ZoomNodeMeetingSmartSummaryCtrlWrap();
	~ZoomNodeMeetingSmartSummaryCtrlWrap();
public:
	/// \brief Determine if current meeting support smart summary feature.
	/// \return True means the current meeting support smart summary feature, False means not supported.
	static void IsSmartSummarySupported(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Determine if smart summary feature is enabled in the meeting.
	/// \return True means smart summary feature is enabled.
	static void IsSmartSummaryEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Whether the current user can enable the smart summary feature for the account.
	/// \return If the function succeeds, the return value is SDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKError \endlink enum.
	static void CanEnableSmartSummaryFeature(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Enable the smart summary feature for the account.
	/// \return If the function succeeds, the return value is SDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKError \endlink enum.
	static void EnableSmartSummaryFeature(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Whether the current user is able to start smart summary.
	/// \return If the function succeeds, the return value is SDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKError \endlink enum.
	static void CanStartSmartSummary(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Start smart summary.
	/// \return If the function succeeds, the return value is SDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKError \endlink enum.
	static void StartSmartSummary(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Stop smart summary.
	/// \return If the function succeeds, the return value is SDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKError \endlink enum.
	static void StopSmartSummary(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Query whether smart summary is started.
	/// \return True means smart summary is started, false means not.
	static void IsSmartSummaryStarted(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Whether the current user can request the admin to enable the smart summary feature for the account.
	/// \return If the function succeeds, the return value is SDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKError \endlink enum.
	static void CanRequestEnableSmartSummaryFeature(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Request the admin to enable the smart summary feature for the account.
	/// \return If the function succeeds, the return value is SDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKError \endlink enum.
	static void RequestEnableSmartSummaryFeature(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Whether the current user can request host to start the smart summary for the current meeting.
	/// \return If the function succeeds, the return value is SDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKError \endlink enum.
	static void CanRequestStartSmartSummary(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Request the host to start the smart summary for the current meeting.
	/// \return If the function succeeds, the return value is SDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKError \endlink enum.
	static void RequestStartSmartSummary(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Agree the start smart summary request.
	/// \return If the function succeeds, the return value is SDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKError \endlink enum.
	static void Accept(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Decline the start smart summary request.
	/// \return If the function succeeds, the return value is SDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKError \endlink enum.
	static void Decline(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Ignore the start smart summary request.
	/// \return If the function succeeds, the return value is SDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKError \endlink enum.
	static void Ignore(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set notification smart summary status changes callback.
	/// \param 1. Callback event when smart summary status changes.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetOnSmartSummaryStatusChangeCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set notification user requests host to start smart summary callback.
	/// \param 1. Callback event when a user requests host to start smart summary.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetOnSmartSummaryPrivilegeRequestedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set host handle the smart summary request callback.
	/// \param 1. Callback event when the host handle the smart summary request.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetOnSmartSummaryStartReqResponseCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set notification user need to go to web to enable the smart summary feature callback.
	/// \param 1. Callback event when the user need to go to web to enable the smart summary feature.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetOnEnableSmartSummaryCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
void InitClassAttribute<ZoomNodeMeetingSmartSummaryCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingSmartSummaryCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSmartSummarySupported", ZoomNodeMeetingSmartSummaryCtrlWrap::IsSmartSummarySupported);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSmartSummaryEnabled", ZoomNodeMeetingSmartSummaryCtrlWrap::IsSmartSummaryEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanEnableSmartSummaryFeature", ZoomNodeMeetingSmartSummaryCtrlWrap::CanEnableSmartSummaryFeature);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableSmartSummaryFeature", ZoomNodeMeetingSmartSummaryCtrlWrap::EnableSmartSummaryFeature);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanStartSmartSummary", ZoomNodeMeetingSmartSummaryCtrlWrap::CanStartSmartSummary);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartSmartSummary", ZoomNodeMeetingSmartSummaryCtrlWrap::StartSmartSummary);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopSmartSummary", ZoomNodeMeetingSmartSummaryCtrlWrap::StopSmartSummary);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSmartSummaryStarted", ZoomNodeMeetingSmartSummaryCtrlWrap::IsSmartSummaryStarted);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanRequestEnableSmartSummaryFeature", ZoomNodeMeetingSmartSummaryCtrlWrap::CanRequestEnableSmartSummaryFeature);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RequestEnableSmartSummaryFeature", ZoomNodeMeetingSmartSummaryCtrlWrap::RequestEnableSmartSummaryFeature);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanRequestStartSmartSummary", ZoomNodeMeetingSmartSummaryCtrlWrap::CanRequestStartSmartSummary);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RequestStartSmartSummary", ZoomNodeMeetingSmartSummaryCtrlWrap::RequestStartSmartSummary);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Accept", ZoomNodeMeetingSmartSummaryCtrlWrap::Accept);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Decline", ZoomNodeMeetingSmartSummaryCtrlWrap::Decline);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Ignore", ZoomNodeMeetingSmartSummaryCtrlWrap::Ignore);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSmartSummaryStatusChangeCB", ZoomNodeMeetingSmartSummaryCtrlWrap::SetOnSmartSummaryStatusChangeCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSmartSummaryPrivilegeRequestedCB", ZoomNodeMeetingSmartSummaryCtrlWrap::SetOnSmartSummaryPrivilegeRequestedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSmartSummaryStartReqResponseCB", ZoomNodeMeetingSmartSummaryCtrlWrap::SetOnSmartSummaryStartReqResponseCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnEnableSmartSummaryCB", ZoomNodeMeetingSmartSummaryCtrlWrap::SetOnEnableSmartSummaryCB);
}
template<>
v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingSmartSummaryCtrlWrap >() {
	return &ZoomNodeMeetingSmartSummaryCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
