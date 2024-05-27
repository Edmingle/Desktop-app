#ifndef _zoom_sinks_wrap_class_h_
#define _zoom_sinks_wrap_class_h_
#include "zoom_node_common_include.h"
#include "zoom_singleton_wrap_class.h"

class ZNativeSDKAuthWrapSink
{
public:
	/// \brief Authentication result callback.
	/// \param authResult Authentication result value.  For more details, see \link ZNAuthResult \endlink enum.
	virtual void onAuthenticationReturn(ZNAuthResult authResult)
	{
		if (ZoomNodeSinkHelper::GetInst().onAuthenticationReturn.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_authresult = v8::Integer::New(isolate, (int32_t)authResult);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_authresult };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onAuthenticationReturn);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Logout result callback.
	virtual void onLogout()
	{
		if (ZoomNodeSinkHelper::GetInst().onLogout.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onLogout);
		fn->Call(context, global, 0, NULL);
	}
	/// \brief Zoom identity has expired, please re-login or generate a new zoom access token.
	virtual void onZoomIdentityExpired()
	{
		if (ZoomNodeSinkHelper::GetInst().onZoomIdentityExpired.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onZoomIdentityExpired);
		fn->Call(context, global, 0, NULL);
	}
	virtual void onZoomAuthIdentityExpired()
	{
		if (ZoomNodeSinkHelper::GetInst().onZoomAuthIdentityExpired.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onZoomAuthIdentityExpired);
		fn->Call(context, global, 0, NULL);
	}
	virtual void onLoginReturnWithReason(ZNLOGINSTATUS ret, ZNLoginFailReason reason)
	{
		if (ZoomNodeSinkHelper::GetInst().onLoginReturnWithReason.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_loginstatus = v8::Integer::New(isolate, (int32_t)ret);
		v8::Local<v8::Integer> v8_loginfailreason = v8::Integer::New(isolate, (int32_t)reason);

		int argc = 2;
		v8::Local<v8::Value> argv[2] = { v8_loginstatus, v8_loginfailreason };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onLoginReturnWithReason);
		fn->Call(context, global, argc, argv);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingWrapSink
{
public:
	/// \brief Meeting status changed callback.
	/// \param status The value of meeting. For more details, see \link ZNMeetingStatus \endlink.
	/// \param iResult Detailed reasons for special meeting status.
	///If the status is ZNMEETING_STATUS_FAILED, the value of iResult is one of those listed in \link ZNMeetingFailCode \endlink enum. 
	///If the status is ZNMEETING_STATUS_ENDED, the value of iResult is one of those listed in \link ZNMeetingEndReason \endlink enum.
	virtual void onMeetingStatusChanged(ZNMeetingStatus meetingStatus, int iResult)
	{
		if (ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer > v8_meeting_status = v8::Integer::New(isolate, (int32_t)meetingStatus);
		v8::Local<v8::Integer > v8_result = v8::Integer::New(isolate, (int32_t)iResult);
		int argc = 2;
		v8::Local<v8::Value> argv[2] = { v8_meeting_status, v8_result };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged);

		fn->Call(context, global, argc, argv);
	}
	virtual void onMeetingStatisticsWarningNotification(ZNStatisticsWarningType type)
	{
		if (ZoomNodeSinkHelper::GetInst().onMeetingStatisticsWarningNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer > v8_type = v8::Integer::New(isolate, (int32_t)type);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_type };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onMeetingStatisticsWarningNotification);

		fn->Call(context, global, argc, argv);
	}
	virtual void onMeetingParameterNotification(ZNMeetingParameter parameter)
	{
		if (ZoomNodeSinkHelper::GetInst().onMeetingParameterNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();


		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "meetingType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)parameter.meeting_type));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isViewOnly", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, parameter.is_view_only));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isAutoRecordingLocal", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, parameter.is_auto_recording_local));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isAutoRecordingCloud", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, parameter.is_auto_recording_cloud));
		node->Set(context, v8::String::NewFromUtf8(isolate, "meetingNumber", v8::NewStringType::kInternalized).ToLocalChecked(), v8::BigInt::NewFromUnsigned(isolate, parameter.meeting_number));
		node->Set(context, v8::String::NewFromUtf8(isolate, "meetingTopic", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(parameter.meeting_topic).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "meetingHost", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(parameter.meeting_host).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onMeetingParameterNotification);

		fn->Call(context, global, argc, argv);
	}
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingUICtrlWrapSink
{
public:
	/// \brief Callback event to click the INVITE button.
	/// \param [out] bHandled True indicates to show the user's own custom dialog interface. Default value: FALSE.
	/// \remarks If the value of bHandled is not set to TRUE, the default interface will pop up. 
	virtual void onInviteBtnClicked(bool& bHandled)
	{
		if (ZoomNodeSinkHelper::GetInst().onInviteBtnClicked.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean > v8_bHandled = v8::Boolean::New(isolate, bHandled);

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_bHandled };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onInviteBtnClicked);
		v8::MaybeLocal<v8::Value> bReturnedValue = fn->Call(context, global, argc, argv);
#ifdef USING_V8_NEW_STRING
		bHandled = bReturnedValue.ToLocalChecked()->BooleanValue(isolate);
#else
		bHandled = bReturnedValue.ToLocalChecked()->BooleanValue();
#endif 
	}

	virtual void onStartShareBtnClicked()
	{
		if (ZoomNodeSinkHelper::GetInst().onStartShareBtnClicked.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onStartShareBtnClicked);

		fn->Call(context, global, 0, NULL);
	}
	virtual void onEndMeetingBtnClicked()
	{
		if (ZoomNodeSinkHelper::GetInst().onEndMeetingBtnClicked.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onEndMeetingBtnClicked);

		fn->Call(context, global, 0, NULL);
	}
	virtual void onParticipantListBtnClicked()
	{
		if (ZoomNodeSinkHelper::GetInst().onParticipantListBtnClicked.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onParticipantListBtnClicked);

		fn->Call(context, global, 0, NULL);
	}
	virtual void onCustomLiveStreamMenuClicked()
	{
		if (ZoomNodeSinkHelper::GetInst().onCustomLiveStreamMenuClicked.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onCustomLiveStreamMenuClicked);

		fn->Call(context, global, 0, NULL);
	}
	virtual void onZoomInviteDialogFailed()
	{
		if (ZoomNodeSinkHelper::GetInst().onZoomInviteDialogFailed.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onZoomInviteDialogFailed);

		fn->Call(context, global, 0, NULL);
	}
	virtual void onCCBTNClicked()
	{
		if (ZoomNodeSinkHelper::GetInst().onCCBTNClicked.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onCCBTNClicked);

		fn->Call(context, global, 0, NULL);
	}
	virtual void onAudioBtnClicked(ZNAudioBtnClickedCallbackInfo info)
	{
		if (ZoomNodeSinkHelper::GetInst().onAudioBtnClicked.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer > v8_audio_clicked_action = v8::Integer::New(isolate, (int32_t)info.audio_clicked_action);
		v8::Local<v8::Integer > v8_userid_MuteUnmute = v8::Integer::New(isolate, (uint32_t)info.userid_MuteUnmute);

		int argc = 2;
		v8::Local<v8::Value> argv[2] = { v8_audio_clicked_action, v8_userid_MuteUnmute };

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onAudioBtnClicked);

		fn->Call(context, global, argc, argv);
	}
	virtual void onAudioMenuBtnClicked()
	{
		if (ZoomNodeSinkHelper::GetInst().onAudioMenuBtnClicked.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onAudioMenuBtnClicked);

		fn->Call(context, global, 0, NULL);
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingAudioWrapSink
{
public:
	/// \brief User's audio status changed callback.
	/// \param lstAudioStatusChange List of the user information with audio status changed. The list will be emptied once the function calls end. 
	///For more user audio status infomation, see \link ZNAudioStatus \endlink enum.
	virtual void onUserAudioStatusChange(ZNList<ZNUserAudioStatus> lstAudioStatusChange, ZoomSTRING strAudioStatusList)
	{

		if (ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange.IsEmpty())
		{
			return;
		}


		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < lstAudioStatusChange.size(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(context, v8::String::NewFromUtf8(isolate, "userid", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)lstAudioStatusChange[i].userId));
			node->Set(context, v8::String::NewFromUtf8(isolate, "audioStauts", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)lstAudioStatusChange[i].audioStauts));
			nodes->Set(context, i, node);
		}
		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange);

		fn->Call(context, global, argc, argv);
	}
	/// \brief The callback event that users whose audio is active changed.
	/// \param lstActiveAudio List to store the ID of user whose audio is active.
	virtual void onUserActiveAudioChange(ZNList<unsigned int > lstActiveAudio)
	{

		if (ZoomNodeSinkHelper::GetInst().onUserActiveAudioChange.IsEmpty())
		{
			return;
		}

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < lstActiveAudio.size(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(context, v8::String::NewFromUtf8(isolate, "userid", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)lstActiveAudio[i]));
			nodes->Set(context, i, node);
		}
		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserActiveAudioChange);

		fn->Call(context, global, argc, argv);
	}
};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZNativeSDKMeetingVideoWrapSink
{
public:
	/// \brief Callback event of the user video status changes.
	/// \param userId The user ID whose video status changes
	/// \param status New video status. For more details, see \link ZNVideoStatus \endlink enum.
	virtual void onUserVideoStatusChange(unsigned int userId, ZNVideoStatus status)
	{
		if (ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange.IsEmpty())
		{
			return;
		}

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "userId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)userId));
		node->Set(context, v8::String::NewFromUtf8(isolate, "videoStatus", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)status));

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback event of the active speaker video user changes. 
	/// \param userid The ID of user who becomes the new active speaker.
	virtual void onActiveSpeakerVideoUserChanged(unsigned int userId)
	{
		if (ZoomNodeSinkHelper::GetInst().onActiveSpeakerVideoUserChanged.IsEmpty())
		{
			return;
		}
		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();
		v8::Local<v8::Integer> zn_userid = v8::Integer::New(isolate, (int32_t)userId);

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { zn_userid };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onActiveSpeakerVideoUserChanged);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback event of the active video user changes. 
	/// \param userid The ID of user who becomes the new active speaker.
	virtual void onActiveVideoUserChanged(unsigned int userId)
	{
		if (ZoomNodeSinkHelper::GetInst().onActiveVideoUserChanged.IsEmpty())
		{
			return;
		}
		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();
		v8::Local<v8::Integer> zn_userid = v8::Integer::New(isolate, (int32_t)userId);

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { zn_userid };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onActiveVideoUserChanged);

		fn->Call(context, global, argc, argv);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingShareWrapSink
{
public:
	/// \brief Callback event of the changed sharing status. 
	/// \param status The values of sharing status. For more details, see \link ZNShareStatus \endlink enum.
	/// \param userId Sharer ID. 
	/// \remarks The userId changes according to the status value. When the status value is the ZN_Sharing_Self_Send_Begin or ZN_Sharing_Self_Send_End, the userId is the user own ID. Otherwise, the value of userId is the sharer ID.
	virtual void onSharingStatus(ZNShareStatus status, unsigned int userId)
	{
		if (ZoomNodeSinkHelper::GetInst().onSharingStatus.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();


		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "userId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)userId));
		node->Set(context, v8::String::NewFromUtf8(isolate, "ShareStatus", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)status));

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onSharingStatus);

		fn->Call(context, global, argc, argv);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingParticipantsWrapSink
{
public:
	/// \brief Callback event of notification of users who are in the meeting.
	/// \param lstUserID List of the user ID. 
	/// \param strUserList List of user in json format. This function is currently invalid, hereby only for reservations.
	virtual void onUserJoin(ZNList<unsigned int> lstUserID, ZoomSTRING strUserList)
	{

		if (ZoomNodeSinkHelper::GetInst().onUserJoin.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < lstUserID.size(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(context, v8::String::NewFromUtf8(isolate, "userid", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)lstUserID[i]));
			nodes->Set(context, i, node);
		}
		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserJoin);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback event of notification of user who leaves the meeting.
	/// \param lstUserID List of the user ID who leaves the meeting.
	/// \param strUserList List of the user in json format. This function is currently invalid, hereby only for reservations.
	virtual void onUserLeft(ZNList<unsigned int> lstUserID, ZoomSTRING strUserList)
	{

		if (ZoomNodeSinkHelper::GetInst().onUserLeft.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < lstUserID.size(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(context, v8::String::NewFromUtf8(isolate, "userid", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)lstUserID[i]));
			nodes->Set(context, i, node);
		}
		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserLeft);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback event of notification of the new host. 
	/// \param userId Specify the ID of the new host.
	virtual void onHostChangeNotification(unsigned int userId)
	{

		if (ZoomNodeSinkHelper::GetInst().onHostChangeNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_userid = v8::Integer::New(isolate, (int32_t)userId);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_userid };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onHostChangeNotification);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback event that lets participants request that the host starts cloud recording.
	/// \param bAllow True allow. If false, disallow.
	virtual void onAllowParticipantsRequestCloudRecording(bool bAllow)
	{
		if (ZoomNodeSinkHelper::GetInst().onAllowParticipantsRequestCloudRecording.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean> v8_bAllow = v8::Boolean::New(isolate, bAllow);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_bAllow };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onAllowParticipantsRequestCloudRecording);

		fn->Call(context, global, argc, argv);
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingH323WrapSink
{
public:
	/// \brief Callback event when the calling status of H.323 device changes.
	/// \param status H.323 device calling out status value. For more details, see \link ZNH323CalloutStatus \endlink enum.
	virtual void onH323CalloutStatusNotify(ZNH323CalloutStatus status)
	{
		if (ZoomNodeSinkHelper::GetInst().onH323CalloutStatusNotify.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_h323CalloutStatus = v8::Integer::New(isolate, (int32_t)status);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_h323CalloutStatus };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onH323CalloutStatusNotify);

		fn->Call(context, global, argc, argv);
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingConfigWrapFreemeetingSink
{
public:
	/// \brief The callback of upgrading the free meeting.
	/// \param type Type of upgrading the free meeting, see \link ZNFreeMeetingNeedUpgradeType \endlink enum.
	/// \param gift_url Upgrade the free meeting by the gift link. When and only when the value of type is ZN_FreeMeetingNeedUpgradeType_BY_GIFTURL, this parameter is meaningful.
	virtual void onFreeMeetingNeedToUpgrade(ZNFreeMeetingNeedUpgradeType type, ZoomSTRING gift_url)
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingNeedToUpgrade.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "giftUrl", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(gift_url).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "freeMeetingNeedUpgradeType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)type));

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingNeedToUpgrade);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback function of starting to upgrade the free meeting by the gift link.
	virtual void onFreeMeetingUpgradeToGiftFreeTrialStart()
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStart.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStart);

		fn->Call(context, global, 0, NULL);
	}
	/// \brief Callback function of ending upgrade the free meeting by the gift link.
	virtual void onFreeMeetingUpgradeToGiftFreeTrialStop()
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStop.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStop);

		fn->Call(context, global, 0, NULL);
	}
	/// \brief Callback function of free meting upgrades successfully.
	virtual void onFreeMeetingUpgradeToProMeeting()
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToProMeeting.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToProMeeting);

		fn->Call(context, global, 0, NULL);
	}
	virtual void onInputMeetingPasswordAndScreenNameNotification()
	{
		if (ZoomNodeSinkHelper::GetInst().onInputMeetingPasswordAndScreenNameNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onInputMeetingPasswordAndScreenNameNotification);

		fn->Call(context, global, 0, NULL);
	}
	virtual void onAirPlayInstructionWndNotification(bool bShow, ZoomSTRING airhostName)
	{
		if (ZoomNodeSinkHelper::GetInst().onAirPlayInstructionWndNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean> zn_bShow = v8::Boolean::New(isolate, bShow);
		v8::Local<v8::String> zn_airhostName = v8::String::NewFromUtf8(isolate, zs2s(airhostName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();

		int argc = 2;
		v8::Local<v8::Value> argv[2] = { zn_bShow, zn_airhostName };

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onAirPlayInstructionWndNotification);

		fn->Call(context, global, argc, argv);
	}
	
	virtual void onWebinarNeedRegisterNotification()
	{
		if (ZoomNodeSinkHelper::GetInst().onWebinarNeedRegisterNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onWebinarNeedRegisterNotification);

		fn->Call(context, global, 0, NULL);
	}
	
	virtual void onEndOtherMeetingToJoinMeetingNotification()
	{
		if (ZoomNodeSinkHelper::GetInst().onEndOtherMeetingToJoinMeetingNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onEndOtherMeetingToJoinMeetingNotification);

		fn->Call(context, global, 0, NULL);
	}
	virtual void onFreeMeetingRemainTime(unsigned int leftTime)
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingRemainTime.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_leftTime = v8::Integer::New(isolate, (int32_t)leftTime);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_leftTime };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingRemainTime);

		fn->Call(context, global, argc, argv);
	}
	virtual void onFreeMeetingRemainTimeStopCountDown()
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingRemainTimeStopCountDown.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingRemainTimeStopCountDown);

		fn->Call(context, global, 0, NULL);
	}
	virtual void onWebinarNeedInputScreenName()
	{
		if (ZoomNodeSinkHelper::GetInst().onWebinarNeedInputScreenName.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onWebinarNeedInputScreenName);

		fn->Call(context, global, 0, NULL);
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKDirectShareHelperWrapSink
{
public:
	/// \brief The callback event will be triggered if the status of direct sharing changes.
	/// \param status Specifies the status of direct sharing. For more details, see \link ZNDirectShareStatus \endlink enum.
	///When the value of status is ZN_DirectShare_Need_MeetingID_Or_PairingCode or ZN_DirectShare_WrongMeetingID_Or_SharingKey, 
	///the SDK user must set the value of the _paring_code or _meeting_number via the functions TryWithPairingCode or TryWithMeetingNumber to start direct sharing.
	virtual void OnDirectShareStatusUpdate(ZNDirectShareStatus status)
	{
		if (ZoomNodeSinkHelper::GetInst().OnDirectShareStatusUpdate.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();


		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "DirectShareStatus", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)status));

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().OnDirectShareStatusUpdate);

		fn->Call(context, global, argc, argv);


	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKSMSHelperWrapSink
{
public:
	virtual void onNeedRealNameAuthMeetingNotification(ZNList<ZNZoomRealNameAuthCountryInfo> support_country_list, ZoomSTRING privacy_url)
	{
		if (ZoomNodeSinkHelper::GetInst().onNeedRealNameAuthMeetingNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> zn_support_country_list = v8::Array::New(isolate);
		for (unsigned int i = 0; i < support_country_list.size(); ++i)
		{
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(context, v8::String::NewFromUtf8(isolate, "countryCode", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(support_country_list[i].countryCode).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
			node->Set(context, v8::String::NewFromUtf8(isolate, "countryID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(support_country_list[i].countryID).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
			node->Set(context, v8::String::NewFromUtf8(isolate, "countryName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(support_country_list[i].countryName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
			zn_support_country_list->Set(context, i, node);
		}
		
		v8::Local<v8::String> zn_privacy_url = v8::String::NewFromUtf8(isolate, zs2s(privacy_url).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();

		int argc = 2;
		v8::Local<v8::Value> argv[2] = { zn_support_country_list, zn_privacy_url };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onNeedRealNameAuthMeetingNotification);

		fn->Call(context, global, argc, argv);
	}
	virtual void onRetrieveSMSVerificationCodeResultNotification(ZNSMSVerificationCodeErr result)
	{
		if (ZoomNodeSinkHelper::GetInst().onRetrieveSMSVerificationCodeResultNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> zn_smsVerificationCodeErr = v8::Integer::New(isolate, (int32_t)result);

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { zn_smsVerificationCodeErr };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onRetrieveSMSVerificationCodeResultNotification);

		fn->Call(context, global, argc, argv);
	}
	virtual void onVerifySMSVerificationCodeResultNotification(ZNSMSVerificationCodeErr result)
	{
		if (ZoomNodeSinkHelper::GetInst().onVerifySMSVerificationCodeResultNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> zn_smsVerificationCodeErr = v8::Integer::New(isolate, (int32_t)result);

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { zn_smsVerificationCodeErr };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onVerifySMSVerificationCodeResultNotification);

		fn->Call(context, global, argc, argv);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKAudioSettingContextWrapSink
{
public:
	/// \brief Callback event if the SDK detects that the computer mic devices have been changed.
	/// \param newMicList The new list of all mic devices plugged into the computer.
	virtual void onComputerMicDeviceChanged(ZNList<ZNMicInfo> newMicList)
	{
		if (ZoomNodeSinkHelper::GetInst().onComputerMicDeviceChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < newMicList.size(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(context, v8::String::NewFromUtf8(isolate, "deviceId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(newMicList[i].deviceId).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
			node->Set(context, v8::String::NewFromUtf8(isolate, "deviceName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(newMicList[i].deviceName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
			node->Set(context, v8::String::NewFromUtf8(isolate, "isSelected", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, newMicList[i].isSelectedDevice));
			nodes->Set(context, i, node);
		}

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onComputerMicDeviceChanged);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback event if the SDK detects that the computer speaker devices have been changed.
	/// \param newSpeakerList The new list of all speaker devices plugged into the computer. 
	virtual void onComputerSpeakerDeviceChanged(ZNList<ZNSpeakerInfo> newSpeakerList)
	{
		if (ZoomNodeSinkHelper::GetInst().onComputerSpeakerDeviceChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < newSpeakerList.size(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(context, v8::String::NewFromUtf8(isolate, "deviceId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(newSpeakerList[i].deviceId).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
			node->Set(context, v8::String::NewFromUtf8(isolate, "deviceName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(newSpeakerList[i].deviceName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
			node->Set(context, v8::String::NewFromUtf8(isolate, "isSelected", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, newSpeakerList[i].isSelectedDevice));
			nodes->Set(context, i, node);
		}

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onComputerSpeakerDeviceChanged);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Notify the user that a microphone device is selected.
	/// \param deviceId Specify a device to be selected.
	/// \param deviceName Specify the device name assigned by deviceId.
	virtual void onDefaultMicDeviceChanged(ZoomSTRING deviceId, ZoomSTRING deviceName)
	{
		if (ZoomNodeSinkHelper::GetInst().onDefaultMicDeviceChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::String> zn_deviceId = v8::String::NewFromUtf8(isolate, zs2s(deviceId).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
		v8::Local<v8::String> zn_deviceName = v8::String::NewFromUtf8(isolate, zs2s(deviceName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();

		int argc = 2;
		v8::Local<v8::Value> argv[2] = { zn_deviceId, zn_deviceName };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onDefaultMicDeviceChanged);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Notify the user that a speaker device is selected.
	/// \param deviceId Specify a device to be selected.
	/// \param deviceName Specify the device name assigned by deviceId.
	virtual void onDefaultSpeakerDeviceChanged(ZoomSTRING deviceId, ZoomSTRING deviceName)
	{
		if (ZoomNodeSinkHelper::GetInst().onDefaultSpeakerDeviceChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::String> zn_deviceId = v8::String::NewFromUtf8(isolate, zs2s(deviceId).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
		v8::Local<v8::String> zn_deviceName = v8::String::NewFromUtf8(isolate, zs2s(deviceName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();

		int argc = 2;
		v8::Local<v8::Value> argv[2] = { zn_deviceId, zn_deviceName };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onDefaultSpeakerDeviceChanged);

		fn->Call(context, global, argc, argv);
	}

};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKVideoSettingContextWrapSink
{
public:
	virtual void onComputerCamDeviceChanged(ZNList<ZNCameraInfo> newCameraList)
	{
		if (ZoomNodeSinkHelper::GetInst().onComputerCamDeviceChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < newCameraList.size(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(context, v8::String::NewFromUtf8(isolate, "deviceId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(newCameraList[i].deviceId).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
			node->Set(context, v8::String::NewFromUtf8(isolate, "deviceName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(newCameraList[i].deviceName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
			node->Set(context, v8::String::NewFromUtf8(isolate, "isSelected", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, newCameraList[i].isSelectedDevice));
			nodes->Set(context, i, node);
		}

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onComputerCamDeviceChanged);

		fn->Call(context, global, argc, argv);
	}
	virtual void onDefaultCamDeviceChanged(ZoomSTRING deviceId, ZoomSTRING deviceName)
	{
		if (ZoomNodeSinkHelper::GetInst().onDefaultCamDeviceChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::String> zn_deviceId = v8::String::NewFromUtf8(isolate, zs2s(deviceId).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
		v8::Local<v8::String> zn_deviceName = v8::String::NewFromUtf8(isolate, zs2s(deviceName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();

		int argc = 2;
		v8::Local<v8::Value> argv[2] = { zn_deviceId, zn_deviceName };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onDefaultCamDeviceChanged);

		fn->Call(context, global, argc, argv);
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKRecordingSettingContextWrapSink
{
public:
	void onCloudRecordingStorageInfo(signed long long storage_total_size, signed long long storage_used_size, bool allow_exceed_storage)
	{
		if (ZoomNodeSinkHelper::GetInst().onCloudRecordingStorageInfo.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> zn_storageTotalSize = v8::Integer::New(isolate, (int64_t)storage_total_size);
		v8::Local<v8::Integer> zn_storageUsedSize = v8::Integer::New(isolate, (int64_t)storage_used_size);
		v8::Local<v8::Boolean> zn_allowExceedStorage = v8::Boolean::New(isolate, allow_exceed_storage);


		int argc = 3;
		v8::Local<v8::Value> argv[3] = { zn_storageTotalSize, zn_storageUsedSize, zn_allowExceedStorage };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onCloudRecordingStorageInfo);

		fn->Call(context, global, argc, argv);
	}

};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingRecordingWrapSink
{
public:

	virtual void onRecording2MP4Done(bool bsuccess, int iResult, ZoomSTRING szPath)
	{
		if (ZoomNodeSinkHelper::GetInst().onRecording2MP4Done.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean> v8_bsuccess = v8::Boolean::New(isolate, bsuccess);
		v8::Local<v8::Integer > v8_result = v8::Integer::New(isolate, (int32_t)iResult);
		v8::Local<v8::String> v8_szPath = v8::String::NewFromUtf8(isolate, zs2s(szPath).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();

		int argc = 3;
		v8::Local<v8::Value> argv[3] = { v8_bsuccess, v8_result, v8_szPath };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onRecording2MP4Done);

		fn->Call(context, global, argc, argv);
	}

	virtual void onRecording2MP4Processing(int iPercentage)
	{
		if (ZoomNodeSinkHelper::GetInst().onRecording2MP4Processing.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer > v8_iPercentage = v8::Integer::New(isolate, (int32_t)iPercentage);

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_iPercentage };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onRecording2MP4Processing);

		fn->Call(context, global, argc, argv);
	}

	virtual void onRecordingStatus(ZNRecordingStatus status)
	{
		if (ZoomNodeSinkHelper::GetInst().onRecordingStatus.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_recordingStatus = v8::Integer::New(isolate, (int32_t)status);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_recordingStatus };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onRecordingStatus);

		fn->Call(context, global, argc, argv);
	}
	virtual void onCloudRecordingStatus(ZNRecordingStatus status)
	{
		if (ZoomNodeSinkHelper::GetInst().onCloudRecordingStatus.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_recordingStatus = v8::Integer::New(isolate, (int32_t)status);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_recordingStatus };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onCloudRecordingStatus);

		fn->Call(context, global, argc, argv);
	}

	virtual void onRecordPrivilegeChanged(bool bCanRec)
	{
		if (ZoomNodeSinkHelper::GetInst().onRecordPrivilegeChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean> v8_bCanRec = v8::Boolean::New(isolate, bCanRec);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_bCanRec };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onRecordPrivilegeChanged);

		fn->Call(context, global, argc, argv);
	}

	virtual void onCloudRecordingStorageFull(time_t gracePeriodDate)
	{
		if (ZoomNodeSinkHelper::GetInst().onCloudRecordingStorageFull.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_gracePeriodDate = v8::Integer::New(isolate, (int64_t)gracePeriodDate);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_gracePeriodDate };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onCloudRecordingStorageFull);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback event for when the host responds to a cloud recording permission request.
	/// \param status Value of request host to start cloud recording response status. For more details, see \link RequestStartCloudRecordingStatus \endlink enum.
	virtual void onRequestCloudRecordingResponse(ZNRequestStartCloudRecordingStatus status)
	{
		if (ZoomNodeSinkHelper::GetInst().onRequestCloudRecordingResponse.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_status = v8::Integer::New(isolate, (int32_t)status);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_status };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onRequestCloudRecordingResponse);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback event received only by the host when a user requests to start cloud recording.
	/// \param handler A pointer to the IRequestStartCloudRecordingHandler. For more details, see \link IRequestStartCloudRecordingHandler \endlink.
	virtual void onStartCloudRecordingRequested()
	{
		if (ZoomNodeSinkHelper::GetInst().onStartCloudRecordingRequested.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onStartCloudRecordingRequested);

		fn->Call(context, global, 0, NULL);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingLiveStreamWrapSink
{
public:
	virtual void onLiveStreamStatusChange(ZNLiveStreamStatus status)
	{

		if (ZoomNodeSinkHelper::GetInst().onLiveStreamStatusChange.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_status = v8::Integer::New(isolate, (int32_t)status);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_status };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onLiveStreamStatusChange);

		fn->Call(context, global, argc, argv);
	}
	virtual void onRawLiveStreamPrivilegeChanged(bool bHasPrivilege)
	{
		if (ZoomNodeSinkHelper::GetInst().onRawLiveStreamPrivilegeChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean> v8_bHasPrivilege = v8::Boolean::New(isolate, bHasPrivilege);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_bHasPrivilege };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onRawLiveStreamPrivilegeChanged);

		fn->Call(context, global, argc, argv);
	}
	virtual void onUserRawLiveStreamPrivilegeChanged(unsigned int userid, bool bHasPrivilege)
	{
		if (ZoomNodeSinkHelper::GetInst().onUserRawLiveStreamPrivilegeChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean> v8_bHasPrivilege = v8::Boolean::New(isolate, bHasPrivilege);
		v8::Local<v8::Integer > v8_userid = v8::Integer::NewFromUnsigned(isolate, userid);

		int argc = 2;
		v8::Local<v8::Value> argv[3] = { v8_bHasPrivilege, v8_userid };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserRawLiveStreamPrivilegeChanged);

		fn->Call(context, global, argc, argv);
	}
	virtual void onRawLiveStreamPrivilegeRequested()
	{
		if (ZoomNodeSinkHelper::GetInst().onRawLiveStreamPrivilegeRequested.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onRawLiveStreamPrivilegeRequested);

		fn->Call(context, global, 0, NULL);
	}
	virtual void onUserRawLiveStreamingStatusChanged(ZNList<ZNRawLiveStreamInfo> LivingList)
	{
		if (ZoomNodeSinkHelper::GetInst().onUserRawLiveStreamingStatusChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < LivingList.size(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(context, v8::String::NewFromUtf8(isolate, "broadcastUrl", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(LivingList[i].broadcastUrl).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
			node->Set(context, v8::String::NewFromUtf8(isolate, "userId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::NewFromUnsigned(isolate, LivingList[i].userId));
			nodes->Set(context, i, node);
		}

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserRawLiveStreamingStatusChanged);

		fn->Call(context, global, argc, argv);
	}
	virtual void onRawLiveStreamPrivilegeRequestTimeout()
	{
		if (ZoomNodeSinkHelper::GetInst().onRawLiveStreamPrivilegeRequestTimeout.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onRawLiveStreamPrivilegeRequestTimeout);

		fn->Call(context, global, 0, NULL);
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingReminderWrapSink
{
public:
	/// \brief Callback event of the reminder dialog show.
	/// \param content The detail content in the reminder dialog. For more details, see \link IMeetingReminderContent \endlink enum.
	virtual void onReminderNotify(ZNMeetingReminderContent reminderContent)
	{
		if (ZoomNodeSinkHelper::GetInst().onReminderNotify.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();


		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "type", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)reminderContent.type));

		node->Set(context, v8::String::NewFromUtf8(isolate, "title", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(reminderContent.title).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "content", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(reminderContent.content).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "is_blocking", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, reminderContent.is_blocking));

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onReminderNotify);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback event of the enable reminder dialog show.
	/// \param content The detail content in the reminder dialog. For more details, see \link IMeetingEnableReminderHandler \endlink enum.
	/// \param handle A pointer to the IMeetingReminderHandler. For more details, see \link IMeetingEnableReminderHandler \endlink.
	virtual void onEnableReminderNotify(ZNMeetingReminderContent reminderContent)
	{
		if (ZoomNodeSinkHelper::GetInst().onEnableReminderNotify.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();


		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "type", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)reminderContent.type));

		node->Set(context, v8::String::NewFromUtf8(isolate, "title", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(reminderContent.title).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "content", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(reminderContent.content).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "is_blocking", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, reminderContent.is_blocking));

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onEnableReminderNotify);

		fn->Call(context, global, argc, argv);
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingChatWrapSink
{
public:
	virtual void onChatMsgNotifcation(ZNChatMsgInfo chatMsg, ZoomSTRING content)
	{
		if (ZoomNodeSinkHelper::GetInst().onChatMsgNotifcation.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "messageID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(chatMsg.messageID).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "senderUserId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::NewFromUnsigned(isolate, chatMsg.senderUserId));
		node->Set(context, v8::String::NewFromUtf8(isolate, "senderDisplayName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(chatMsg.senderDisplayName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "receiverUserId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::NewFromUnsigned(isolate, chatMsg.receiverUserId));
		node->Set(context, v8::String::NewFromUtf8(isolate, "receiverDisplayName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(chatMsg.receiverDisplayName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "content", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(chatMsg.content).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "timeStamp", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, chatMsg.timeStamp));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isChatToAll", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, chatMsg.isChatToAll));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isChatToAllPanelist", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, chatMsg.isChatToAllPanelist));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isChatToWaitingroom", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, chatMsg.isChatToWaitingroom));
		node->Set(context, v8::String::NewFromUtf8(isolate, "chatMessageType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, chatMsg.chatMessageType));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isComment", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, chatMsg.isComment));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isThread", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, chatMsg.isThread));
		node->Set(context, v8::String::NewFromUtf8(isolate, "threadID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(chatMsg.threadID).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());

		v8::Local<v8::Array> styleNodes = v8::Array::New(isolate);
		v8::Local<v8::Array> offsetNodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < chatMsg.textStyleItemList.size(); ++i)
		{
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> item = v8::Object::New(isolate);
			item->Set(context, v8::String::NewFromUtf8(isolate, "textStyle", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, chatMsg.textStyleItemList[i].textStyle));
			styleNodes->Set(context, i, item);

			v8::Local<v8::Array> offsetItemNodes = v8::Array::New(isolate);
			std::vector<ZNRichTextStyleOffset> textStyleOffsetList = chatMsg.textStyleItemList[i].textStyleOffsetList;
			for (unsigned int j = 0; j < textStyleOffsetList.size(); ++j) 
			{
				v8::HandleScope scope(isolate);
				v8::Local<v8::Object> item = v8::Object::New(isolate);
				item->Set(context, v8::String::NewFromUtf8(isolate, "positionStart", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, textStyleOffsetList[j].positionStart));
				item->Set(context, v8::String::NewFromUtf8(isolate, "positionEnd", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, textStyleOffsetList[j].positionEnd));
				item->Set(context, v8::String::NewFromUtf8(isolate, "reserve", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(textStyleOffsetList[j].reserve).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
				offsetItemNodes->Set(context, j, item);
			}
			offsetNodes->Set(context, i, offsetItemNodes);
		}
		
		v8::Local<v8::String> v8_content = v8::String::NewFromUtf8(isolate, zs2s(content).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();

		int argc = 4;
		v8::Local<v8::Value> argv[4] = { node, styleNodes, offsetNodes, v8_content };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onChatMsgNotifcation);

		fn->Call(context, global, argc, argv);
	}
	virtual void onChatStatusChangedNotification(ZNChatStatus zn_chatStatus)
	{
		if (ZoomNodeSinkHelper::GetInst().onChatStatusChangedNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);

		node->Set(context, v8::String::NewFromUtf8(isolate, "is_chat_off", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chatStatus.is_chat_off));
		node->Set(context, v8::String::NewFromUtf8(isolate, "is_webinar_attendee", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chatStatus.is_webinar_attendee));
		node->Set(context, v8::String::NewFromUtf8(isolate, "is_webinar_meeting", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chatStatus.is_webinar_meeting));
		if (zn_chatStatus.is_webinar_meeting) {
			if (zn_chatStatus.is_webinar_attendee) {
				node->Set(context, v8::String::NewFromUtf8(isolate, "can_chat", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chatStatus.ut.webinar_attendee_status.can_chat));
				node->Set(context, v8::String::NewFromUtf8(isolate, "can_chat_to_all_panellist_and_attendee", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chatStatus.ut.webinar_attendee_status.can_chat_to_all_panellist_and_attendee));
				node->Set(context, v8::String::NewFromUtf8(isolate, "can_chat_to_all_panellist", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chatStatus.ut.webinar_attendee_status.can_chat_to_all_panellist));
			} else {
				node->Set(context, v8::String::NewFromUtf8(isolate, "can_chat_to_all_panellist", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chatStatus.ut.webinar_other_status.can_chat_to_all_panellist));
				node->Set(context, v8::String::NewFromUtf8(isolate, "can_chat_to_all_panellist_and_attendee", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chatStatus.ut.webinar_other_status.can_chat_to_all_panellist_and_attendee));
				node->Set(context, v8::String::NewFromUtf8(isolate, "can_chat_to_individual", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chatStatus.ut.webinar_other_status.can_chat_to_individual));
			}
		} else {
			node->Set(context, v8::String::NewFromUtf8(isolate, "can_chat", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chatStatus.ut.normal_meeting_status.can_chat));
			node->Set(context, v8::String::NewFromUtf8(isolate, "can_chat_to_all", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chatStatus.ut.normal_meeting_status.can_chat_to_all));
			node->Set(context, v8::String::NewFromUtf8(isolate, "can_chat_to_individual", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chatStatus.ut.normal_meeting_status.can_chat_to_individual));
			node->Set(context, v8::String::NewFromUtf8(isolate, "is_only_can_chat_to_host", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chatStatus.ut.normal_meeting_status.is_only_can_chat_to_host));
		}

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onChatStatusChangedNotification);

		fn->Call(context, global, argc, argv);
	}
	virtual void onChatMsgDeleteNotification(ZoomSTRING msgID, ZNSDKChatMessageDeleteType deleteBy)
	{
		if (ZoomNodeSinkHelper::GetInst().onChatMsgDeleteNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::String> v8_msgID = v8::String::NewFromUtf8(isolate, zs2s(msgID).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
		v8::Local<v8::Integer> v8_deleteBy = v8::Integer::New(isolate, (int32_t)deleteBy);
		int argc = 2;
		v8::Local<v8::Value> argv[2] = { v8_msgID, v8_deleteBy };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onChatMsgDeleteNotification);

		fn->Call(context, global, argc, argv);
	}
	virtual void onShareMeetingChatStatusChanged(bool isStart)
	{
		if (ZoomNodeSinkHelper::GetInst().onShareMeetingChatStatusChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean> v8_isStart = v8::Boolean::New(isolate, isStart);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_isStart };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onShareMeetingChatStatusChanged);

		fn->Call(context, global, argc, argv);
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingWaitingRoomWrapSink
{
public:
	virtual void onWaitingRoomUserJoin(unsigned int userID)
	{
		if (ZoomNodeSinkHelper::GetInst().onWaitingRoomUserJoin.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer > v8_userID = v8::Integer::NewFromUnsigned(isolate, userID);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_userID };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onWaitingRoomUserJoin);

		fn->Call(context, global, argc, argv);
	}
	virtual void onWaitingRoomUserLeft(unsigned int userID)
	{
		if (ZoomNodeSinkHelper::GetInst().onWaitingRoomUserLeft.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer > v8_userID = v8::Integer::NewFromUnsigned(isolate, userID);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_userID };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onWaitingRoomUserLeft);

		fn->Call(context, global, argc, argv);
	}
	virtual void onWaitingRoomPresetAudioStatusChanged(bool bAudioCanTurnOn)
	{
		if (ZoomNodeSinkHelper::GetInst().onWaitingRoomPresetAudioStatusChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean> v8_bAudioCanTurnOn = v8::Boolean::New(isolate, bAudioCanTurnOn);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_bAudioCanTurnOn };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onWaitingRoomPresetAudioStatusChanged);

		fn->Call(context, global, argc, argv);
	}
	virtual void onWaitingRoomPresetVideoStatusChanged(bool bVideoCanTurnOn)
	{
		if (ZoomNodeSinkHelper::GetInst().onWaitingRoomPresetVideoStatusChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean> v8_bVideoCanTurnOn = v8::Boolean::New(isolate, bVideoCanTurnOn);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_bVideoCanTurnOn };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onWaitingRoomPresetVideoStatusChanged);

		fn->Call(context, global, argc, argv);
	}
	virtual void onCustomWaitingRoomDataUpdated(ZNCustomWaitingRoomData bData)
	{
		if (ZoomNodeSinkHelper::GetInst().onCustomWaitingRoomDataUpdated.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Object> node = v8::Object::New(isolate);

		node->Set(context, v8::String::NewFromUtf8(isolate, "title", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(bData.title).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "description", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(bData.description).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "logo_path", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(bData.logo_path).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "video_path", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(bData.video_path).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "image_path", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(bData.image_path).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "type", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::NewFromUnsigned(isolate, bData.type));
		node->Set(context, v8::String::NewFromUtf8(isolate, "status", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::NewFromUnsigned(isolate, bData.status));

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onCustomWaitingRoomDataUpdated);

		fn->Call(context, global, argc, argv);
	}
	virtual void onWaitingRoomUserNameChanged(unsigned int userID, ZoomSTRING userName)
	{
		if (ZoomNodeSinkHelper::GetInst().onWaitingRoomUserNameChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer > v8_userID = v8::Integer::NewFromUnsigned(isolate, userID);
		v8::Local<v8::String> v8_userName = v8::String::NewFromUtf8(isolate, zs2s(userName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
		int argc = 2;
		v8::Local<v8::Value> argv[2] = { v8_userID, v8_userName };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onWaitingRoomUserNameChanged);

		fn->Call(context, global, argc, argv);
	}
	virtual void onWaitingRoomEntranceEnabled(bool bIsEnabled)
	{
		if (ZoomNodeSinkHelper::GetInst().onWaitingRoomEntranceEnabled.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean> v8_bIsEnabled = v8::Boolean::New(isolate, bIsEnabled);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_bIsEnabled };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onWaitingRoomEntranceEnabled);

		fn->Call(context, global, argc, argv);
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingSmartSummaryWrapSink
{
public:
	virtual void onSmartSummaryStatusChange(bool isStarted)
	{
		if (ZoomNodeSinkHelper::GetInst().onSmartSummaryStatusChange.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean> v8_isStarted = v8::Boolean::New(isolate, isStarted);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_isStarted };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onSmartSummaryStatusChange);

		fn->Call(context, global, argc, argv);
	}
	virtual void onSmartSummaryPrivilegeRequested(unsigned int senderId)
	{
		if (ZoomNodeSinkHelper::GetInst().onSmartSummaryPrivilegeRequested.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer > v8_senderId = v8::Integer::NewFromUnsigned(isolate, senderId);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_senderId };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onSmartSummaryPrivilegeRequested);

		fn->Call(context, global, argc, argv);
	}
	virtual void onSmartSummaryStartReqResponse(bool timeout, bool decline)
	{
		if (ZoomNodeSinkHelper::GetInst().onSmartSummaryStartReqResponse.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean> v8_timeout = v8::Boolean::New(isolate, timeout);
		v8::Local<v8::Boolean> v8_decline = v8::Boolean::New(isolate, decline);
		int argc = 2;
		v8::Local<v8::Value> argv[2] = { v8_timeout, v8_decline };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onSmartSummaryStartReqResponse);

		fn->Call(context, global, argc, argv);
	}
	virtual void onEnableSmartSummary()
	{
		if (ZoomNodeSinkHelper::GetInst().onEnableSmartSummary.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onEnableSmartSummary);

		fn->Call(context, global, 0, NULL);
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZoomNodeSinkWrapMgr
{
public:
	//auth_service_cb	
	ZNativeSDKAuthWrapSink m_authServiceWrapSink;

	//meeting_service_cb
	ZNativeSDKMeetingWrapSink m_meetingServiceWrapSink;

	//meeting_ui_ctrl_cb
	ZNativeSDKMeetingUICtrlWrapSink m_meetingUICtrlWrapSink;

	//meeting_audio_ctrl_cb
	ZNativeSDKMeetingAudioWrapSink m_meetingAudioCtrlWrapSink;
	
	//meeting_video_ctrl_cb
	ZNativeSDKMeetingVideoWrapSink m_meetingVideoWrapSink;

	//meeting_recording_ctrl_cb
	ZNativeSDKMeetingRecordingWrapSink m_meetingRecordingWrapSink;

	//meeting_share_ctrl_cb
	ZNativeSDKMeetingShareWrapSink m_meetingShareWrapSink;

	//meeting_participants_ctrl_cb
	ZNativeSDKMeetingParticipantsWrapSink m_meetingParticipantsWrapSink;

	//meeting_h323_ctrl_cb
	ZNativeSDKMeetingH323WrapSink m_meetingH323WrapSink;

	//meeting_config_ctrl_cb
	ZNativeSDKMeetingConfigWrapFreemeetingSink m_meetingConfigWrapFreeMeetingSink;

	//direct_share_helper_cb
	ZNativeSDKDirectShareHelperWrapSink m_directShareHelperWrapSink;

	//sms_helper_cb
	ZNativeSDKSMSHelperWrapSink m_smsHelperWrapSink;

	//audio_setting_context_cb
	ZNativeSDKAudioSettingContextWrapSink m_audioSettingContextWrapSink;

	//video_setting_context_cb
	ZNativeSDKVideoSettingContextWrapSink m_videoSettingContextWrapSink;

	//recording_setting_context_cb
	ZNativeSDKRecordingSettingContextWrapSink m_recordingSettingContextWrapSink;

	//meeting_live_stream_ctrl_cb
	ZNativeSDKMeetingLiveStreamWrapSink m_meetingLiveStreamWrapSink;

	//meeting_reminder_ctrl_cb
	ZNativeSDKMeetingReminderWrapSink m_meetingReminderWrapSink;

	//meeting_chat_ctrl_cb
	ZNativeSDKMeetingChatWrapSink m_meetingChatWrapSink;

	//meeting_waiting_room_ctrl_cb
	ZNativeSDKMeetingWaitingRoomWrapSink m_meetingWaitingRoomWrapSink;

	//meeting_smart_summary_ctrl_cb
	ZNativeSDKMeetingSmartSummaryWrapSink m_meetingSmartSummaryWrapSink;

	static ZoomNodeSinkWrapMgr& GetInst()
	{
		static ZoomNodeSinkWrapMgr inst;
		return inst;
	}
	~ZoomNodeSinkWrapMgr() {}
private:
	ZoomNodeSinkWrapMgr() {}
};
#endif // !_zoom_sinks_wrap_class_h_
