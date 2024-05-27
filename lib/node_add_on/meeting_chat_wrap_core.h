#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZMeetingChatWrap
{
public:
	ZMeetingChatWrap();
	virtual ~ZMeetingChatWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingChatWrapSink* pSink);

	ZNChatStatus GetChatStatus();
	ZNSDKError SetParticipantsChatPrivilege(ZNSDKChatPrivilege privilege);
	bool IsMeetingChatLegalNoticeAvailable();
	ZoomSTRING getChatLegalNoticesPrompt();
	ZoomSTRING getChatLegalNoticesExplained();
	bool IsShareMeetingChatLegalNoticeAvailable();
	ZoomSTRING GetShareMeetingChatStartedLegalNoticeContent();
	ZoomSTRING GetShareMeetingChatStoppedLegalNoticeContent();
	bool IsChatMessageCanBeDeleted(ZoomSTRING msgID);
	ZNSDKError DeleteChatMessage(ZoomSTRING msgID);
	ZNList<ZoomSTRING> GetAllChatMessageID();
	ZNChatMsgInfo GetChatMessageById(ZoomSTRING msgID);
	ZNSDKError SetChatMessageBuilder(ZoomSTRING content, unsigned int receiver, ZoomSTRING threadId, ZNSDKChatMessageType type, unsigned int positionStart, unsigned int positionEnd, bool bClearStyles, bool bClear);
	ZNSDKError SendLastBuildChatMsgTo();

	//callback
	void onChatMsgNotifcation(ZNChatMsgInfo chatMsg, ZoomSTRING content);
	void onChatStatusChangedNotification(ZNChatStatus status);
	void onChatMsgDeleteNotification(ZoomSTRING msgID, ZNSDKChatMessageDeleteType deleteBy);
	void onShareMeetingChatStatusChanged(bool isStart);
	
private:
	ZNativeSDKMeetingChatWrapSink* m_pSink;
};