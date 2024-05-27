#include "zoom_node_meeting_live_stream_ctrl.h"


ZoomNodeMeetingLiveStreamCtrlWrap::ZoomNodeMeetingLiveStreamCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingLiveStreamWrapSink);
}

ZoomNodeMeetingLiveStreamCtrlWrap::~ZoomNodeMeetingLiveStreamCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().SetSink(NULL);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::CanStartLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().CanStartLiveStream();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::StartLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::StartLiveStreamParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::StartLiveStreamParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_livestreamhandle())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int64_t _itemHandle = proto_params.livestreamhandle();
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().StartLiveStream(_itemHandle);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::StartLiveStreamWithSteamingURL(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::StartLiveStreamWithSteamingURLParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::StartLiveStreamWithSteamingURLParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_broadcasturl() ||
			!proto_params.has_streamingkey() ||
			!proto_params.has_streamingurl()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING zn_broadCastURL = s2zs(proto_params.broadcasturl());
		ZoomSTRING zn_streamKey= s2zs(proto_params.streamingkey());
		ZoomSTRING zn_streamURL = s2zs(proto_params.streamingurl());
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().StartLiveStreamWithSteamingURL(zn_streamURL, zn_streamKey, zn_broadCastURL);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::StopLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().StopLiveStream();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::GetSupportLiveStreamItems(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNList<int64_t> zn_itemHandleLst = _g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().GetSupportLiveStreamItems();

	v8::HandleScope scope(isolate);
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_itemHandleLst.size(); ++i) 
	{
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "deviceId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::BigInt::New(isolate, zn_itemHandleLst[i]));
		nodes->Set(context, i, node);
	}

	args.GetReturnValue().Set(nodes);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::GetCurrentLiveStreamStatus(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNLiveStreamStatus status = _g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().GetCurrentLiveStreamStatus();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)status);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::StopRawLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().StopRawLiveStream();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::GetLiveStreamItemInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::GetLiveStreamItemInfoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::GetLiveStreamItemInfoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_livestreamhandle())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int64_t zn_itemHandle = proto_params.livestreamhandle();
		ZNLiveStreamItemInfo zn_info = _g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().GetLiveStreamItemInfo(zn_itemHandle);
		node->Set(context, v8::String::NewFromUtf8(isolate, "liveStreamURL", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_info.liveStreamURL).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "liveStreamURLDescription", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_info.liveStreamURLDescription).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		
	} while (false);

	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	args.GetReturnValue().Set(node);
}

void ZoomNodeMeetingLiveStreamCtrlWrap::IsRawLiveStreamSupported(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bSupport = _g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().IsRawLiveStreamSupported();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bSupport);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::CanStartRawLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().CanStartRawLiveStream();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::RemoveRawLiveStreamPrivilege(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::RemoveRawLiveStreamPrivilegeParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RemoveRawLiveStreamPrivilegeParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int zn_userid = proto_params.userid();
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().RemoveRawLiveStreamPrivilege(zn_userid);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::GetRawLiveStreamingInfoList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNList<ZNRawLiveStreamInfo> zn_Lst = _g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().GetRawLiveStreamingInfoList();

	v8::HandleScope scope(isolate);
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_Lst.size(); ++i) 
	{
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "userId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::NewFromUnsigned(isolate, zn_Lst[i].userId));
		node->Set(context, v8::String::NewFromUtf8(isolate, "broadcastUrl", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_Lst[i].broadcastUrl).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		nodes->Set(context, i, node);
	}

	args.GetReturnValue().Set(nodes);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::GetRawLiveStreamPrivilegeUserList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNList<unsigned int> zn_Lst = _g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().GetRawLiveStreamPrivilegeUserList();

	v8::HandleScope scope(isolate);
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_Lst.size(); ++i) 
	{
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "userId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::NewFromUnsigned(isolate, zn_Lst[i]));
		nodes->Set(context, i, node);
	}

	args.GetReturnValue().Set(nodes);
}


void ZoomNodeMeetingLiveStreamCtrlWrap::SetOnLiveStreamStatusChangeCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onLiveStreamStatusChange.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onLiveStreamStatusChange = cb;

	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::SetOnRawLiveStreamPrivilegeChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onRawLiveStreamPrivilegeChanged.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onRawLiveStreamPrivilegeChanged = cb;

	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::SetOnRawLiveStreamPrivilegeRequestedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onRawLiveStreamPrivilegeRequested.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onRawLiveStreamPrivilegeRequested = cb;

	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::SetOnRawLiveStreamPrivilegeRequestTimeoutCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onRawLiveStreamPrivilegeRequestTimeout.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onRawLiveStreamPrivilegeRequestTimeout = cb;

	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::SetOnUserRawLiveStreamingStatusChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onUserRawLiveStreamingStatusChanged.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onUserRawLiveStreamingStatusChanged = cb;

	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingLiveStreamCtrlWrap::SetOnUserRawLiveStreamPrivilegeChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onUserRawLiveStreamPrivilegeChanged.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onUserRawLiveStreamPrivilegeChanged = cb;

	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap()
{
	
}

ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::~ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap()
{
	
}
void ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::GetRequestId(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING requestID = _g_native_wrap.GetMeetingServiceWrap().GetRequestRawLiveStreamPrivilegeHandler().GetRequestId();
	v8::Local<v8::String> ret = v8::String::NewFromUtf8(isolate, zs2s(requestID).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(ret);
}
void ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::GetRequesterId(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	unsigned int reqUserID = _g_native_wrap.GetMeetingServiceWrap().GetRequestRawLiveStreamPrivilegeHandler().GetRequesterId();
	v8::Local<v8::Integer> ret = v8::Integer::NewFromUnsigned(isolate, reqUserID);
	args.GetReturnValue().Set(ret);
}
void ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::GrantRawLiveStreamPrivilege(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	err = _g_native_wrap.GetMeetingServiceWrap().GetRequestRawLiveStreamPrivilegeHandler().GrantRawLiveStreamPrivilege();
	v8::Local<v8::Integer> ret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(ret);
}
void ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::DenyRawLiveStreamPrivilege(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	err = _g_native_wrap.GetMeetingServiceWrap().GetRequestRawLiveStreamPrivilegeHandler().DenyRawLiveStreamPrivilege();
	v8::Local<v8::Integer> ret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(ret);
}
void ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::GetRequesterName(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING requestUserName = _g_native_wrap.GetMeetingServiceWrap().GetRequestRawLiveStreamPrivilegeHandler().GetRequesterName();
	v8::Local<v8::String> ret = v8::String::NewFromUtf8(isolate, zs2s(requestUserName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(ret);
}
void ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::GetBroadcastUrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING broadcaseUrl = _g_native_wrap.GetMeetingServiceWrap().GetRequestRawLiveStreamPrivilegeHandler().GetBroadcastUrl();
	v8::Local<v8::String> ret = v8::String::NewFromUtf8(isolate, zs2s(broadcaseUrl).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(ret);
}

