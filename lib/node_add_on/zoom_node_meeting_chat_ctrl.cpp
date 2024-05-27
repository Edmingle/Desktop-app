#include "zoom_node_meeting_chat_ctrl.h"

ZoomNodeMeetingChatCtrlWrap::ZoomNodeMeetingChatCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingChatWrapSink);
}

ZoomNodeMeetingChatCtrlWrap::~ZoomNodeMeetingChatCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().SetSink(NULL);
}
void ZoomNodeMeetingChatCtrlWrap::GetChatStatus(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNChatStatus zn_chatStatus;
	zn_chatStatus = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().GetChatStatus();

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

	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingChatCtrlWrap::SetParticipantsChatPrivilege(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetParticipantsChatPrivilegeParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetParticipantsChatPrivilegeParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_privilege())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNSDKChatPrivilege _zn_privilege = (ZNSDKChatPrivilege)proto_params.privilege();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().SetParticipantsChatPrivilege(_zn_privilege);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::IsMeetingChatLegalNoticeAvailable(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().IsMeetingChatLegalNoticeAvailable();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::getChatLegalNoticesPrompt(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING zn_chatLegalNoticesPrompt = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().getChatLegalNoticesPrompt();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(zn_chatLegalNoticesPrompt).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::getChatLegalNoticesExplained(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING zn_chatLegalNoticesExplained = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().getChatLegalNoticesExplained();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(zn_chatLegalNoticesExplained).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::IsShareMeetingChatLegalNoticeAvailable(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().IsShareMeetingChatLegalNoticeAvailable();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::GetShareMeetingChatStartedLegalNoticeContent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING zn_chatStartedLegalNoticeContent = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().GetShareMeetingChatStartedLegalNoticeContent();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(zn_chatStartedLegalNoticeContent).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::GetShareMeetingChatStoppedLegalNoticeContent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING zn_chatStoppedLegalNoticeContent = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().GetShareMeetingChatStoppedLegalNoticeContent();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(zn_chatStoppedLegalNoticeContent).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::IsChatMessageCanBeDeleted(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = false;
	do
	{
		com::electron::sdk::proto::ChatMessageIDParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ChatMessageIDParams >(args, proto_params))
		{
			zn_bIs = false;
			break;
		}
		if (!proto_params.has_msgid())
		{
			zn_bIs = false;
			break;
		}
		ZoomSTRING _zn_msgID;
		_zn_msgID = s2zs(proto_params.msgid());

		zn_bIs = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().IsChatMessageCanBeDeleted(_zn_msgID);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::DeleteChatMessage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ChatMessageIDParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ChatMessageIDParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_msgid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _zn_msgID;
		_zn_msgID = s2zs(proto_params.msgid());

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().DeleteChatMessage(_zn_msgID);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::GetAllChatMessageID(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNList<ZoomSTRING> zn_msgID_lst;
	zn_msgID_lst = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().GetAllChatMessageID();

	v8::Local<v8::Array> chat_message_nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_msgID_lst.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "msgID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_msgID_lst[i]).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		chat_message_nodes->Set(context, i, node);
	}
	args.GetReturnValue().Set(chat_message_nodes);
}
void ZoomNodeMeetingChatCtrlWrap::GetChatMessageById(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNChatMsgInfo zn_chat_msg_info;
	v8::HandleScope scope(isolate);
	v8::Local<v8::Array> chat_message_nodes = v8::Array::New(isolate);
	do
	{
		com::electron::sdk::proto::ChatMessageIDParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ChatMessageIDParams >(args, proto_params))
		{
			break;
		}
		if (!proto_params.has_msgid())
		{
			break;
		}
		ZoomSTRING _zn_msgID;
		_zn_msgID = s2zs(proto_params.msgid());

		zn_chat_msg_info = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().GetChatMessageById(_zn_msgID);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "messageID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_chat_msg_info.messageID).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "senderUserId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_chat_msg_info.senderUserId));
		node->Set(context, v8::String::NewFromUtf8(isolate, "senderDisplayName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_chat_msg_info.senderDisplayName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "receiverUserId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_chat_msg_info.receiverUserId));
		node->Set(context, v8::String::NewFromUtf8(isolate, "receiverDisplayName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_chat_msg_info.receiverDisplayName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "content", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_chat_msg_info.content).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "timeStamp", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_chat_msg_info.timeStamp));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isChatToAll", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chat_msg_info.isChatToAll));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isChatToAllPanelist", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chat_msg_info.isChatToAllPanelist));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isChatToWaitingroom", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chat_msg_info.isChatToWaitingroom));
		node->Set(context, v8::String::NewFromUtf8(isolate, "chatMessageType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_chat_msg_info.chatMessageType));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isComment", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chat_msg_info.isComment));
		node->Set(context, v8::String::NewFromUtf8(isolate, "isThread", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_chat_msg_info.isThread));
		node->Set(context, v8::String::NewFromUtf8(isolate, "threadID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_chat_msg_info.threadID).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		chat_message_nodes->Set(context, 0, node);

		v8::Local<v8::Array> styleNodes = v8::Array::New(isolate);
		v8::Local<v8::Array> offsetNodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < zn_chat_msg_info.textStyleItemList.size(); ++i)
		{
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> item = v8::Object::New(isolate);
			item->Set(context, v8::String::NewFromUtf8(isolate, "textStyle", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_chat_msg_info.textStyleItemList[i].textStyle));
			styleNodes->Set(context, i, item);

			v8::Local<v8::Array> offsetItemNodes = v8::Array::New(isolate);
			std::vector<ZNRichTextStyleOffset> textStyleOffsetList = zn_chat_msg_info.textStyleItemList[i].textStyleOffsetList;
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

		chat_message_nodes->Set(context, 1, styleNodes);
		chat_message_nodes->Set(context, 2, offsetNodes);
	} while (false);
	
	args.GetReturnValue().Set(chat_message_nodes);
}
void ZoomNodeMeetingChatCtrlWrap::SetChatMessageBuilder(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetChatMessageBuilderParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetChatMessageBuilderParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_content() ||
			!proto_params.has_receiver() ||
			!proto_params.has_type()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		ZoomSTRING _zn_content;
		_zn_content = s2zs(proto_params.content());

		int _receiver = proto_params.receiver();

		ZoomSTRING _zn_threadId;
		if (proto_params.has_threadid())
		{
			_zn_threadId = s2zs(proto_params.threadid());
		}

		ZNSDKChatMessageType _zn_type = (ZNSDKChatMessageType)proto_params.type();
		
		int _positionStart = 0;
		if (proto_params.has_positionstart())
		{
			_positionStart = proto_params.positionstart();
		}
		int _positionEnd = 0;
		if (proto_params.has_positionend())
		{
			_positionEnd = proto_params.positionend();
		}

		bool _b_clearStyles = false;
		if (proto_params.has_bclearstyles())
		{
			convertBool(proto_params.bclearstyles(), _b_clearStyles);
		}
		bool _b_clear = false;
		if (proto_params.has_bclear())
		{
			convertBool(proto_params.bclear(), _b_clear);
		}

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().SetChatMessageBuilder(_zn_content, _receiver, _zn_threadId, _zn_type, _positionStart, _positionEnd, _b_clearStyles, _b_clear);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::SendLastBuildChatMsgTo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().SendLastBuildChatMsgTo();
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::SetOnChatMsgNotifcationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onChatMsgNotifcation.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onChatMsgNotifcation = cb;

	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::SetOnChatStatusChangedNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onChatStatusChangedNotification.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onChatStatusChangedNotification = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::SetOnChatMsgDeleteNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onChatMsgDeleteNotification.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onChatMsgDeleteNotification = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingChatCtrlWrap::SetOnShareMeetingChatStatusChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onShareMeetingChatStatusChanged.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onShareMeetingChatStatusChanged = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}