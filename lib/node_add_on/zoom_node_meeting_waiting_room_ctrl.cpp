#include "zoom_node_meeting_waiting_room_ctrl.h"

ZoomNodeMeetingWaitingRoomCtrlWrap::ZoomNodeMeetingWaitingRoomCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingWaitingRoomWrapSink);
}

ZoomNodeMeetingWaitingRoomCtrlWrap::~ZoomNodeMeetingWaitingRoomCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().SetSink(NULL);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::IsSupportWaitingRoom(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().IsSupportWaitingRoom();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::IsWaitingRoomOnEntryFlagOn(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().IsWaitingRoomOnEntryFlagOn();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::EnableWaitingRoomOnEntry(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableWaitingRoomOnEntryParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableWaitingRoomOnEntryParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _b_enable = false;
		convertBool(proto_params.benable(), _b_enable);

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().EnableWaitingRoomOnEntry(_b_enable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::GetWaitingRoomList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNList<unsigned int> zn_waiting_room_lst;
	zn_waiting_room_lst = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().GetWaitingRoomList();

	v8::Local<v8::Array> waiting_room_nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_waiting_room_lst.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "userid", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_waiting_room_lst[i]));
		waiting_room_nodes->Set(context, i, node);
	}
	args.GetReturnValue().Set(waiting_room_nodes);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::GetWaitingRoomUserInfoByID(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	do
	{
		com::electron::sdk::proto::GetWaitingRoomUserInfoByIDParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::GetWaitingRoomUserInfoByIDParams >(args, proto_params))
		{
			break;
		}
		if (!proto_params.has_userid())
		{
			break;
		}
		ZNUserInfomation zn_userInfo;
		int _userid = proto_params.userid();
		zn_userInfo = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().GetWaitingRoomUserInfoByID(_userid);
 
		node->Set(context, v8::String::NewFromUtf8(isolate, "userName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_userInfo.userName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "isHost", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.isHost));
		node->Set(context, v8::String::NewFromUtf8(isolate, "userID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_userInfo.userID));
		node->Set(context, v8::String::NewFromUtf8(isolate, "avatarPath", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_userInfo.avatarPath).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "persistentId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_userInfo.persistentId).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "customerKey", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_userInfo.customerKey).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "isVideoOn", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.isVideoOn));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isAudioMuted", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.isAudioMuted));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isMySelf", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.isMySelf));
		node->Set(context, v8::String::NewFromUtf8(isolate, "userRole", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_userInfo.userRole));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isPurePhoneUser", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.isPurePhoneUser));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isTalking", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.isTalking));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isH323User", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.isH323User));
		node->Set(context, v8::String::NewFromUtf8(isolate, "webinarAttendeeStatus", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.webinarAttendeeStatus));
		node->Set(context, v8::String::NewFromUtf8(isolate, "localRecordingStatus", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_userInfo.localRecordingStatus));
		node->Set(context, v8::String::NewFromUtf8(isolate, "userInfoType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_userInfo.userInfoType));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isRawLiveStreaming", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.isRawLiveStreaming));
		node->Set(context, v8::String::NewFromUtf8(isolate, "hasRawLiveStreamPrivilege", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.HasRawLiveStreamPrivilege));
		node->Set(context, v8::String::NewFromUtf8(isolate, "hasCamera", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.hasCamera));
		node->Set(context, v8::String::NewFromUtf8(isolate, "audioJoinType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_userInfo.audioJoinType));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isRaiseHand", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.isRaiseHand));
		#if (!defined TARGET_OS_MAC)
		node->Set(context, v8::String::NewFromUtf8(isolate, "isInWaitingRoom", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.isInWaitingRoom));
		node->Set(context, v8::String::NewFromUtf8(isolate, "audioVoiceLevel", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_userInfo.audioVoiceLevel));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isClosedCaptionSender", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.isClosedCaptionSender));
		#endif
		node->Set(context, v8::String::NewFromUtf8(isolate, "isInterpreter", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.isInterpreter));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isSignLanguageInterpreter", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfo.isSignLanguageInterpreter));
		node->Set(context, v8::String::NewFromUtf8(isolate, "interpreterActiveLanguage", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_userInfo.interpreterActiveLanguage).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "emojiFeedbackType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_userInfo.emojiFeedbackType));

	} while (false);

	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::AdmitToMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::AdmitToMeetingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::AdmitToMeetingParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int _userid = proto_params.userid();
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().AdmitToMeeting(_userid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::AdmitAllToMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().AdmitAllToMeeting();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::PutInWaitingRoom(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::PutInWaitingRoomParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::PutInWaitingRoomParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int _userid = proto_params.userid();
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().PutInWaitingRoom(_userid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::IsAudioEnabledInWaitingRoom(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().IsAudioEnabledInWaitingRoom();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::IsVideoEnabledInWaitingRoom(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().IsVideoEnabledInWaitingRoom();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::RequestCustomWaitingRoomData(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().RequestCustomWaitingRoomData();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::CanRenameUser(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bCan = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().CanRenameUser();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bCan);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::RenameUser(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::RenameUserParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RenameUserParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid() ||
			!proto_params.has_newname()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _zn_newname;
		_zn_newname = s2zs(proto_params.newname());
		int _userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().RenameUser(_userid, _zn_newname);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::CanExpelUser(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bCan = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().CanExpelUser();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bCan);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::ExpelUser(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ExpelUserParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ExpelUserParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int _userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().ExpelUser(_userid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::Retry(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().Retry();
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::Ignore(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().Ignore();
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnWaitingRoomUserJoinCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())
		{
			ZoomNodeSinkHelper::GetInst().onWaitingRoomUserJoin.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onWaitingRoomUserJoin = cb;

	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnWaitingRoomUserLeftCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())
		{
			ZoomNodeSinkHelper::GetInst().onWaitingRoomUserLeft.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onWaitingRoomUserLeft = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnWaitingRoomPresetAudioStatusChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())
		{
			ZoomNodeSinkHelper::GetInst().onWaitingRoomPresetAudioStatusChanged.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onWaitingRoomPresetAudioStatusChanged = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnWaitingRoomPresetVideoStatusChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())
		{
			ZoomNodeSinkHelper::GetInst().onWaitingRoomPresetVideoStatusChanged.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onWaitingRoomPresetVideoStatusChanged = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnCustomWaitingRoomDataUpdatedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())
		{
			ZoomNodeSinkHelper::GetInst().onCustomWaitingRoomDataUpdated.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onCustomWaitingRoomDataUpdated = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnWaitingRoomUserNameChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())
		{
			ZoomNodeSinkHelper::GetInst().onWaitingRoomUserNameChanged.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onWaitingRoomUserNameChanged = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnWaitingRoomEntranceEnabledCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())
		{
			ZoomNodeSinkHelper::GetInst().onWaitingRoomEntranceEnabled.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onWaitingRoomEntranceEnabled = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}