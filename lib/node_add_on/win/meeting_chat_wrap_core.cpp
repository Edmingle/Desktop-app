#include "meeting_chat_wrap_core.h"
#include "sdk_wrap.h"
#include "meeting_service_components_wrap/meeting_chat_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"

extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;
ZOOM_SDK_NAMESPACE::IChatMsgInfo* lastBuildChatMsg;

ZMeetingChatWrap::ZMeetingChatWrap()
{
	SDKEventWrapMgr::GetInst().m_meetingChatCtrlEvent.SetOwner(this);
	m_pSink = 0;
}
ZMeetingChatWrap::~ZMeetingChatWrap()
{
	Uninit();
	m_pSink = 0;
	SDKEventWrapMgr::GetInst().m_meetingChatCtrlEvent.SetOwner(NULL);
}
void ZMeetingChatWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().SetEvent(&SDKEventWrapMgr::GetInst().m_meetingChatCtrlEvent);
}
void ZMeetingChatWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().Uninit_Wrap();
}
void ZMeetingChatWrap::SetSink(ZNativeSDKMeetingChatWrapSink* pSink)
{
	m_pSink = pSink;
}
ZNChatStatus ZMeetingChatWrap::GetChatStatus()
{
	ZNChatStatus zn_chat_status;
	const ZOOM_SDK_NAMESPACE::ChatStatus* status = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().GetChatStatus();
	if (status)
	{
		zn_chat_status.is_chat_off = status->is_chat_off;
		zn_chat_status.is_webinar_attendee = status->is_webinar_attendee;
		zn_chat_status.is_webinar_meeting = status->is_webinar_meeting;
		if (status->is_webinar_meeting)
		{
			if (status->is_webinar_attendee) 
			{
				zn_chat_status.ut.webinar_attendee_status.can_chat = status->ut.webinar_attendee_status.can_chat;
				zn_chat_status.ut.webinar_attendee_status.can_chat_to_all_panellist_and_attendee = status->ut.webinar_attendee_status.can_chat_to_all_panellist_and_attendee;
				zn_chat_status.ut.webinar_attendee_status.can_chat_to_all_panellist = status->ut.webinar_attendee_status.can_chat_to_all_panellist;
			} else {
				zn_chat_status.ut.webinar_other_status.can_chat_to_all_panellist = status->ut.webinar_other_status.can_chat_to_all_panellist;
				zn_chat_status.ut.webinar_other_status.can_chat_to_all_panellist_and_attendee = status->ut.webinar_other_status.can_chat_to_all_panellist_and_attendee;
				zn_chat_status.ut.webinar_other_status.can_chat_to_individual = status->ut.webinar_other_status.can_chat_to_individual;
			}
		} else {
			zn_chat_status.ut.normal_meeting_status.can_chat = status->ut.normal_meeting_status.can_chat;
			zn_chat_status.ut.normal_meeting_status.can_chat_to_all = status->ut.normal_meeting_status.can_chat_to_all;
			zn_chat_status.ut.normal_meeting_status.can_chat_to_individual = status->ut.normal_meeting_status.can_chat_to_individual;
			zn_chat_status.ut.normal_meeting_status.is_only_can_chat_to_host = status->ut.normal_meeting_status.is_only_can_chat_to_host;
		}
	} 
	return zn_chat_status;
}
ZNSDKError ZMeetingChatWrap::SetParticipantsChatPrivilege(ZNSDKChatPrivilege privilege)
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().SetParticipantsChatPrivilege(Map2WrapDefine(privilege));
	return Map2WrapDefine(sdkerr);
}
bool ZMeetingChatWrap::IsMeetingChatLegalNoticeAvailable()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().IsMeetingChatLegalNoticeAvailable();
}
ZoomSTRING ZMeetingChatWrap::getChatLegalNoticesPrompt()
{
	const zchar_t* prompt = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().getChatLegalNoticesPrompt();
	ZoomSTRING zn_prompt;
	if (prompt)
	{
		zn_prompt = prompt;
	}
	return zn_prompt;
}
ZoomSTRING ZMeetingChatWrap::getChatLegalNoticesExplained()
{
	const zchar_t* explained = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().getChatLegalNoticesExplained();
	ZoomSTRING zn_explained;
	if (explained)
	{
		zn_explained = explained;
	}
	return zn_explained;
}
bool ZMeetingChatWrap::IsShareMeetingChatLegalNoticeAvailable()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().IsShareMeetingChatLegalNoticeAvailable();
}
ZoomSTRING ZMeetingChatWrap::GetShareMeetingChatStartedLegalNoticeContent()
{
	const zchar_t* content = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().GetShareMeetingChatStartedLegalNoticeContent();
	ZoomSTRING zn_content;
	if (content)
	{
		zn_content = content;
	}
	return zn_content;
}
ZoomSTRING ZMeetingChatWrap::GetShareMeetingChatStoppedLegalNoticeContent()
{
	const zchar_t* content = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().GetShareMeetingChatStoppedLegalNoticeContent();
	ZoomSTRING zn_content;
	if (content)
	{
		zn_content = content;
	}
	return zn_content;
}
bool ZMeetingChatWrap::IsChatMessageCanBeDeleted(ZoomSTRING msgID)
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().IsChatMessageCanBeDeleted(msgID.c_str());
}
ZNSDKError ZMeetingChatWrap::DeleteChatMessage(ZoomSTRING msgID)
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().DeleteChatMessage(msgID.c_str());
	return Map2WrapDefine(sdkerr);
}
ZNList<ZoomSTRING> ZMeetingChatWrap::GetAllChatMessageID()
{
	ZNList<ZoomSTRING> chat_message_list;
	ZOOM_SDK_NAMESPACE::IList<const zchar_t*>* lstChatMessage = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().GetAllChatMessageID();
	if (NULL == lstChatMessage)
		return chat_message_list;
	for (int i = 0; i < lstChatMessage->GetCount(); ++i)
	{
		ZoomSTRING zn_chat_message;
		zn_chat_message = lstChatMessage->GetItem(i);
		chat_message_list.push_back(zn_chat_message);
	}
	return chat_message_list;
}
ZNChatMsgInfo ZMeetingChatWrap::GetChatMessageById(ZoomSTRING msgID)
{
	ZNChatMsgInfo zn_chat_msg_info;
	ZOOM_SDK_NAMESPACE::IChatMsgInfo* chatMsg = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().GetChatMessageById(msgID.c_str());
	if (chatMsg)
	{
		zn_chat_msg_info.messageID = chatMsg->GetMessageID();
		zn_chat_msg_info.senderUserId = chatMsg->GetSenderUserId();
		zn_chat_msg_info.senderDisplayName = chatMsg->GetSenderDisplayName();
		zn_chat_msg_info.receiverUserId = chatMsg->GetReceiverUserId();
		zn_chat_msg_info.receiverDisplayName = chatMsg->GetReceiverDisplayName();
		zn_chat_msg_info.content = chatMsg->GetContent();
		zn_chat_msg_info.timeStamp = chatMsg->GetTimeStamp();
		zn_chat_msg_info.isChatToAll = chatMsg->IsChatToAll();
		zn_chat_msg_info.isChatToAllPanelist = chatMsg->IsChatToAllPanelist();
		zn_chat_msg_info.isChatToWaitingroom = chatMsg->IsChatToWaitingroom();
		zn_chat_msg_info.chatMessageType = Map2WrapDefine(chatMsg->GetChatMessageType());
		zn_chat_msg_info.isComment = chatMsg->IsComment();
		zn_chat_msg_info.isThread = chatMsg->IsThread();
		zn_chat_msg_info.threadID = chatMsg->GetThreadID();
		ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IRichTextStyleItem*>* plstRichTextStyleItem = chatMsg->GetTextStyleItemList();
		ZNList<ZNRichTextStyleItem> text_style_item_list;
		for (int i = 0; i < plstRichTextStyleItem->GetCount(); ++i)
		{
			ZOOM_SDK_NAMESPACE::IRichTextStyleItem* pRichTextStyleItem = plstRichTextStyleItem->GetItem(i);
			ZNRichTextStyleItem zn_rich_text_style_item;
			if (pRichTextStyleItem)
			{
				zn_rich_text_style_item.textStyle = (ZNRichTextStyle)pRichTextStyleItem->GetTextStyle();
				ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IRichTextStyleOffset*>* plstTextStyleOffset = pRichTextStyleItem->GetTextStyleOffsetList();
				ZNList<ZNRichTextStyleOffset> rich_text_style_offset_list;
				for (int j = 0; j < plstTextStyleOffset->GetCount(); ++j)
				{
					ZOOM_SDK_NAMESPACE::IRichTextStyleOffset* pTextStyleOffset = plstTextStyleOffset->GetItem(j);
					ZNRichTextStyleOffset zn_rich_text_style_offset;
					if (pTextStyleOffset)
					{
						zn_rich_text_style_offset.positionStart = pTextStyleOffset->GetPositionStart();
						zn_rich_text_style_offset.positionEnd = pTextStyleOffset->GetPositionEnd();
						zn_rich_text_style_offset.reserve = pTextStyleOffset->GetReserve();
					}
					rich_text_style_offset_list.push_back(zn_rich_text_style_offset);
				}
				zn_rich_text_style_item.textStyleOffsetList = rich_text_style_offset_list;
			}
			text_style_item_list.push_back(zn_rich_text_style_item);
		}
		zn_chat_msg_info.textStyleItemList = text_style_item_list;
	}
	return zn_chat_msg_info;
}
ZNSDKError ZMeetingChatWrap::SetChatMessageBuilder(ZoomSTRING content, unsigned int receiver, ZoomSTRING threadId, ZNSDKChatMessageType type, unsigned int positionStart, unsigned int positionEnd, bool bClearStyles, bool bClear)
{
	lastBuildChatMsg = NULL;
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS;
	ZOOM_SDK_NAMESPACE::IChatMsgInfoBuilder* builder = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().GetChatMessageBuilder();
	if (!builder)
	{
		sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_INTERNAL_ERROR;
		return Map2WrapDefine(sdkerr);
	}
	builder->SetContent(content.c_str());
	builder->SetReceiver(receiver);
	builder->SetMessageType(Map2WrapDefine(type));
	if (threadId.empty())
	{
		builder->SetThreadId(threadId.c_str());
	}
	if (positionStart < positionEnd) {
		builder->SetQuotePosition(positionStart, positionEnd);
	}
	if (bClearStyles)
	{
		builder->ClearStyles();
	}
	if (bClear)
	{
		builder->Clear();
	}
	lastBuildChatMsg = builder->Build();
	return Map2WrapDefine(sdkerr);
}
ZNSDKError ZMeetingChatWrap::SendLastBuildChatMsgTo()
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS;
	if (lastBuildChatMsg)
	{
		sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingChatController().SendChatMsgTo(lastBuildChatMsg);
	} 
	else
	{
		sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
	}
	lastBuildChatMsg = NULL;
	return Map2WrapDefine(sdkerr);
}
void ZMeetingChatWrap::onChatMsgNotifcation(ZNChatMsgInfo chatMsg, ZoomSTRING content)
{
	if (m_pSink)
	{
		m_pSink->onChatMsgNotifcation(chatMsg, content.c_str());
	}
}
void ZMeetingChatWrap::onChatStatusChangedNotification(ZNChatStatus status)
{
	if (m_pSink)
	{
		m_pSink->onChatStatusChangedNotification(status);
	}
}
void ZMeetingChatWrap::onChatMsgDeleteNotification(ZoomSTRING msgID, ZNSDKChatMessageDeleteType deleteBy)
{
	if (m_pSink)
	{
		m_pSink->onChatMsgDeleteNotification(msgID.c_str(), deleteBy);
	}
}
void ZMeetingChatWrap::onShareMeetingChatStatusChanged(bool isStart)
{
	if (m_pSink)
	{
		m_pSink->onShareMeetingChatStatusChanged(isStart);
	}
}