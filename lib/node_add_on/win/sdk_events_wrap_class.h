#ifndef _sdk_events_wrap_class_h_
#define _sdk_events_wrap_class_h_
#include "sdk_wrap.h"
#include "zoom_native_to_wrap.h"
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_native_sdk_wrap_core.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZAuthServiceWrapEvent : public ZOOM_SDK_NAMESPACE::IAuthServiceEvent
{
public:
	void SetOwner(ZAuthServiceWrap* obj) { owner_ = obj; }
	virtual void onAuthenticationReturn(ZOOM_SDK_NAMESPACE::AuthResult ret) {
		if (owner_) {
			if (ZOOM_SDK_NAMESPACE::AUTHRET_SUCCESS == ret)
			{
				_g_native_wrap.GetMeetingServiceWrap().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingParticipantsCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingShareCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingLiveStreamCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingReminderCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingChatCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingWaitingRoomCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingSmartSummaryCtrl().Init();
				_g_native_wrap.GetSettingServiceWrap().Init();

			}
			owner_->onAuthenticationReturn(Map2WrapDefine(ret));

		}
	}
	virtual void onLogout() {
		if (owner_) {
			owner_->onLogout();
		}

	}
	virtual void onZoomIdentityExpired() {
		if (owner_) {
			owner_->onZoomIdentityExpired();
		}
	}
	virtual void onZoomAuthIdentityExpired() {
		if (owner_) {
			owner_->onZoomAuthIdentityExpired();
		}
	}
	virtual void onLoginReturnWithReason(ZOOM_SDK_NAMESPACE::LOGINSTATUS ret, ZOOM_SDK_NAMESPACE::IAccountInfo* pAccountInfo, ZOOM_SDK_NAMESPACE::LoginFailReason reason)
	{
		if (owner_)
		{
			if (ZOOM_SDK_NAMESPACE::LOGIN_SUCCESS == ret)
			{
				_g_native_wrap.GetAuthServiceWrap().GetDirectShareHelper().Init();
			}
			owner_->onLoginReturnWithReason(Map2WrapDefine(ret), Map2WrapDefine(reason));
		}
	}
	virtual void onNotificationServiceStatus(ZOOM_SDK_NAMESPACE::SDKNotificationServiceStatus status)
	{
	}
	virtual void onNotificationServiceStatus(ZOOM_SDK_NAMESPACE::SDKNotificationServiceStatus status, ZOOM_SDK_NAMESPACE::SDKNotificationServiceError error)
	{
	}
private:
	ZAuthServiceWrap* owner_;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingServiceWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingServiceEvent
{
public:
	void SetOwner(ZMeetingServiceWrap* obj) { owner_ = obj; }
	virtual void onMeetingStatusChanged(ZOOM_SDK_NAMESPACE::MeetingStatus status, int iResult)
	{
		if (owner_) {
			owner_->onMeetingStatusChanged(Map2WrapDefine(status), iResult);
		}
	}
	virtual void onMeetingStatisticsWarningNotification(ZOOM_SDK_NAMESPACE::StatisticsWarningType type)
	{
		if (owner_) {
			owner_->onMeetingStatisticsWarningNotification(Map2WrapDefine(type));
		}
	}
	virtual void onMeetingParameterNotification(const ZOOM_SDK_NAMESPACE::MeetingParameter* pMeetingParam)
	{
		if (owner_ && pMeetingParam) {
			ZNMeetingParameter zn_meeting_parameter;
			zn_meeting_parameter.is_auto_recording_cloud = pMeetingParam->is_auto_recording_cloud;
			zn_meeting_parameter.is_auto_recording_local = pMeetingParam->is_auto_recording_local;
			zn_meeting_parameter.is_view_only = pMeetingParam->is_view_only;
			if (pMeetingParam->meeting_host)
			{
				zn_meeting_parameter.meeting_host = pMeetingParam->meeting_host;
			}
			if (pMeetingParam->meeting_topic)
			{
				zn_meeting_parameter.meeting_topic = pMeetingParam->meeting_topic;
			}
			zn_meeting_parameter.meeting_number = pMeetingParam->meeting_number;
			zn_meeting_parameter.meeting_type = Map2WrapDefine(pMeetingParam->meeting_type);
			
			owner_->onMeetingParameterNotification(zn_meeting_parameter);
		}
	}
	virtual void onSuspendParticipantsActivities()
	{
	}
	virtual void onAICompanionActiveChangeNotice(bool bActive)
	{
	}
private:
	ZMeetingServiceWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingUIControllerWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingUIControllerEvent
{
public:
	void SetOwner(ZMeetingUICtrlWrap* obj) { owner_ = obj; }
	virtual void onInviteBtnClicked(bool& bHandled)
	{
		if (owner_) {
			owner_->onInviteBtnClicked(bHandled);
		}
	}
	virtual void onStartShareBtnClicked()
	{
		if (owner_)
		{
			owner_->onStartShareBtnClicked();
		}
	}
	virtual void onEndMeetingBtnClicked()
	{
		if (owner_)
		{
			owner_->onEndMeetingBtnClicked();
		}
	}
	virtual void onParticipantListBtnClicked()
	{
		if (owner_)
		{
			owner_->onParticipantListBtnClicked();
		}
	}
	virtual void onCustomLiveStreamMenuClicked()
	{
		if (owner_)
		{
			owner_->onCustomLiveStreamMenuClicked();
		}
	}
	virtual void onZoomInviteDialogFailed()
	{
		if (owner_)
		{
			owner_->onZoomInviteDialogFailed();
		}
	}
	virtual void onCCBTNClicked()
	{
		if (owner_)
		{
			owner_->onCCBTNClicked();
		}
	}
	virtual void onAudioBtnClicked(ZOOM_SDK_NAMESPACE::AudioBtnClickedCallbackInfo info)
	{
		if (owner_)
		{
			ZNAudioBtnClickedCallbackInfo zn_info;
			zn_info.userid_MuteUnmute = info.userid_MuteUnmute;
			zn_info.audio_clicked_action = Map2WrapDefine(info.audio_clicked_action);
			owner_->onAudioBtnClicked(zn_info);
		}
	}
	virtual void onAudioMenuBtnClicked()
	{
		if (owner_)
		{
			owner_->onAudioMenuBtnClicked();
		}
	}
	virtual void onBreakoutRoomBtnClicked()
	{
		if (owner_)
		{
			//fix me
		}
	}
private:
	ZMeetingUICtrlWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingAudioCtrlWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingAudioCtrlEvent
{
public:
	void SetOwner(ZMeetingAudioWrap* obj) { owner_ = obj; }
	virtual void onUserAudioStatusChange(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IUserAudioStatus* >* lstAudioStatusChange, const wchar_t* strAudioStatusList)
	{
		if (owner_) {
			if (NULL == strAudioStatusList && lstAudioStatusChange && lstAudioStatusChange->GetCount() > 0)
			{
				//
				ZNList<ZNUserAudioStatus> audio_status_list;
				ZoomSTRING zn_strAudioStatusList = L"";
				for (int i = 0; i < lstAudioStatusChange->GetCount(); ++i)
				{
					ZOOM_SDK_NAMESPACE::IUserAudioStatus* pAudioStatus = lstAudioStatusChange->GetItem(i);
					ZNUserAudioStatus userAudioStatus;
					if (pAudioStatus)
					{
						userAudioStatus.userId = pAudioStatus->GetUserId();
						userAudioStatus.audioStauts = Map2WrapDefine(pAudioStatus->GetStatus());
					}

					audio_status_list.push_back(userAudioStatus);
				}
				owner_->onUserAudioStatusChange(audio_status_list, zn_strAudioStatusList);
			}
		}
	}
	virtual void onUserActiveAudioChange(ZOOM_SDK_NAMESPACE::IList<unsigned int >* plstActiveAudio)
	{
		if (owner_) {
			if (plstActiveAudio && plstActiveAudio->GetCount() > 0)
			{
				//
				ZNList<unsigned int> active_audio_list;
				for (int i = 0; i < plstActiveAudio->GetCount(); ++i)
				{
					unsigned int userid = plstActiveAudio->GetItem(i);
					active_audio_list.push_back(userid);
				}
				owner_->onUserActiveAudioChange(active_audio_list);
			}
		}
	}
	virtual void onHostRequestStartAudio(ZOOM_SDK_NAMESPACE::IRequestStartAudioHandler* handler_)
	{

	}
	virtual void onJoin3rdPartyTelephonyAudio(const zchar_t* audioInfo)
	{

	}
private:
	ZMeetingAudioWrap* owner_;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingVideoCtrlWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingVideoCtrlEvent
{
public:
	void SetOwner(ZMeetingVideoWrap* obj) { owner_ = obj; }
	virtual void onUserVideoStatusChange(unsigned int userId, ZOOM_SDK_NAMESPACE::VideoStatus status)
	{
		if (owner_) {

			owner_->onUserVideoStatusChange(userId, Map2WrapDefine(status));
		}
	}
	virtual void onSpotlightVideoChangeNotification(bool bSpotlight, unsigned int userid)
	{
		//
	}
	virtual void onSpotlightedUserListChangeNotification(ZOOM_SDK_NAMESPACE::IList<unsigned int >* lstSpotlightedUserID)
	{
		//
	}
	virtual void onHostRequestStartVideo(ZOOM_SDK_NAMESPACE::IRequestStartVideoHandler* handler_)
	{

	}
	virtual void onActiveSpeakerVideoUserChanged(unsigned int userid)
	{
		if (owner_) {
			owner_->onActiveSpeakerVideoUserChanged(userid);
		}
	}
	virtual void onActiveVideoUserChanged(unsigned int userid)
	{
		if (owner_) {
			owner_->onActiveVideoUserChanged(userid);
		}
	}
	virtual void onHostVideoOrderUpdated(ZOOM_SDK_NAMESPACE::IList<unsigned int >* orderList)
	{

	}
	virtual void onFollowHostVideoOrderChanged(bool bFollow)
	{

	}
	virtual void onLocalVideoOrderUpdated(ZOOM_SDK_NAMESPACE::IList<unsigned int >* localOrderList)
	{
		
	}
	virtual void onUserVideoQualityChanged(ZOOM_SDK_NAMESPACE::VideoConnectionQuality quality, unsigned int userid)
	{
		
	}
	virtual void onVideoAlphaChannelStatusChanged(bool isAlphaModeOn)
	{

	}
private:
	ZMeetingVideoWrap* owner_;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZRequestStartCloudRecordingHandler
{
public:
	static ZRequestStartCloudRecordingHandler& GetInst()
	{
		static ZRequestStartCloudRecordingHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IRequestStartCloudRecordingHandler *handler)
	{
		m_pHandler = handler;
	}

	unsigned int GetRequesterId()
	{
		unsigned int zn_id;
		if (m_pHandler)
		{
			zn_id = m_pHandler->GetRequesterId();
		}
		return zn_id;
	}

	ZoomSTRING GetRequesterName()
	{
		ZoomSTRING zn_name;
		if (m_pHandler)
		{
			const zchar_t* name = m_pHandler->GetRequesterName();
			if (name)
			{
				zn_name = name;
			}
		}
		return zn_name;
	}

	ZNSDKError Start()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			err = m_pHandler->Start();
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError Deny(bool bDenyAll)
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			err = m_pHandler->Deny(bDenyAll);
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}
private:
	ZRequestStartCloudRecordingHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IRequestStartCloudRecordingHandler* m_pHandler;
};

class ZMeetingRecordingCtrlWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingRecordingCtrlEvent
{
public:
	void SetOwner(ZMeetingRecordingWrap* obj) { owner_ = obj; }
	virtual void onRecording2MP4Done(bool bsuccess, int iResult, const wchar_t* szPath)
	{
		if (owner_)
		{
			ZoomSTRING zn_szPath;
			if (szPath)
			{
				zn_szPath = szPath;
			}
			owner_->onRecording2MP4Done(bsuccess, iResult, zn_szPath);
		}
	}
	virtual void onRecording2MP4Processing(int iPercentage)
	{
		if (owner_)
		{
			owner_->onRecording2MP4Processing(iPercentage);
		}
	}
	virtual void onRecordingStatus(ZOOM_SDK_NAMESPACE::RecordingStatus status)
	{
		if (owner_)
		{
			owner_->onRecordingStatus(Map2WrapDefine(status));
		}
	}
	virtual void onCloudRecordingStatus(ZOOM_SDK_NAMESPACE::RecordingStatus status)
	{
		if (owner_)
		{
			owner_->onCloudRecordingStatus(Map2WrapDefine(status));
		}
	}
	virtual void onRecordPrivilegeChanged(bool bCanRec)
	{
		if (owner_)
		{
			owner_->onRecordPrivilegeChanged(bCanRec);
		}
	}
	virtual void onCustomizedLocalRecordingSourceNotification(ZOOM_SDK_NAMESPACE::ICustomizedLocalRecordingLayoutHelper* layout_helper)
	{
		
	}
	virtual void onLocalRecordingPrivilegeRequestStatus(ZOOM_SDK_NAMESPACE::RequestLocalRecordingStatus status)
	{
		
	}
	virtual void onRequestCloudRecordingResponse(ZOOM_SDK_NAMESPACE::RequestStartCloudRecordingStatus status)
	{
		if (owner_)
		{
			owner_->onRequestCloudRecordingResponse(Map2WrapDefine(status));
		}
	}
	virtual void onStartCloudRecordingRequested(ZOOM_SDK_NAMESPACE::IRequestStartCloudRecordingHandler* handler)
	{
		if (owner_)
		{
			ZRequestStartCloudRecordingHandler::GetInst().SetHandler(handler);
			owner_->onStartCloudRecordingRequested();
		}
	}
	virtual void onLocalRecordingPrivilegeRequested(ZOOM_SDK_NAMESPACE::IRequestLocalRecordingPrivilegeHandler* handler)
	{
		
	}
	virtual void onCloudRecordingStorageFull(time_t gracePeriodDate)
	{
		if (owner_)
		{
			owner_->onCloudRecordingStorageFull(gracePeriodDate);
		}
	}
private:
	ZMeetingRecordingWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingShareCtrlWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingShareCtrlEvent
{
public:
	void SetOwner(ZMeetingShareWrap* obj) { owner_ = obj; }
	virtual void onSharingStatus(ZOOM_SDK_NAMESPACE::SharingStatus status, unsigned int userId)
	{
		if (owner_) {

			owner_->onSharingStatus(Map2WrapDefine(status), userId);
		}

	}
	virtual void onLockShareStatus(bool bLocked)
	{

	}
	virtual void onShareContentNotification(ZOOM_SDK_NAMESPACE::ShareInfo& shareInfo)
	{

	}
	virtual void onMultiShareSwitchToSingleShareNeedConfirm(ZOOM_SDK_NAMESPACE::IShareSwitchMultiToSingleConfirmHandler* handler_)
	{

	}
	virtual void onShareSettingTypeChangedNotification(ZOOM_SDK_NAMESPACE::ShareSettingType type)
	{

	}
	virtual void onSharedVideoEnded()
	{

	}
	virtual void onVideoFileSharePlayError(ZOOM_SDK_NAMESPACE::ZoomSDKVideoFileSharePlayError error)
	{

	}
private:
	ZMeetingShareWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingParticipantsCtrlEvent : public ZOOM_SDK_NAMESPACE::IMeetingParticipantsCtrlEvent
{
public:
	void SetOwner(ZMeetingParticipantsWrap* obj) { owner_ = obj; }
	virtual void onUserJoin(ZOOM_SDK_NAMESPACE::IList<unsigned int >* lstUserID, const wchar_t* strUserList)
	{
		if (owner_ && lstUserID) {
			ZNList<unsigned int> userId_list;
			ZoomSTRING zn_strUserList = L"";
			if (strUserList)
				zn_strUserList = strUserList;
			for (int i = 0; i < lstUserID->GetCount(); ++i)
			{

				unsigned int zn_userid;

				zn_userid = lstUserID->GetItem(i);

				userId_list.push_back(zn_userid);
			}

			owner_->onUserJoin(userId_list, zn_strUserList);

		}
	}
	virtual void onUserLeft(ZOOM_SDK_NAMESPACE::IList<unsigned int >* lstUserID, const wchar_t* strUserList)
	{
		if (owner_ && lstUserID) {
			ZNList<unsigned int> userId_list;
			ZoomSTRING zn_strUserList = L"";
			if (strUserList)
				zn_strUserList = strUserList;
			for (int i = 0; i < lstUserID->GetCount(); ++i)
			{

				unsigned int zn_userid;

				zn_userid = lstUserID->GetItem(i);

				userId_list.push_back(zn_userid);
			}

			owner_->onUserLeft(userId_list, zn_strUserList);

		}
	}
	virtual void onHostChangeNotification(unsigned int userId)
	{
		if (owner_) {

			owner_->onHostChangeNotification(userId);

		}
	}
	virtual void onLowOrRaiseHandStatusChanged(bool bLow, unsigned int userid)
	{

	}
	virtual void onCoHostChangeNotification(unsigned int userId, bool isCoHost)
	{

	}
	virtual void onInvalidReclaimHostkey()
	{

	}
	virtual void onUserNamesChanged(ZOOM_SDK_NAMESPACE::IList<unsigned int>* lstUserID)
	{

	}
	virtual void onAllHandsLowered()
	{

	}
	virtual void onLocalRecordingStatusChanged(unsigned int user_id, ZOOM_SDK_NAMESPACE::RecordingStatus status)
	{

	}
	virtual void onAllowParticipantsRenameNotification(bool bAllow)
	{

	}
	virtual void onAllowParticipantsUnmuteSelfNotification(bool bAllow)
	{

	}
	virtual void onAllowParticipantsStartVideoNotification(bool bAllow)
	{

	}
	virtual void onAllowParticipantsShareWhiteBoardNotification(bool bAllow)
	{

	}
	virtual void onRequestLocalRecordingPrivilegeChanged(ZOOM_SDK_NAMESPACE::LocalRecordingRequestPrivilegeStatus status)
	{

	}
	virtual void onAllowParticipantsRequestCloudRecording(bool bAllow)
	{
		if (owner_)
		{
			owner_->onAllowParticipantsRequestCloudRecording(bAllow);
		}
	}
	virtual void onInMeetingUserAvatarPathUpdated(unsigned int userID)
	{

	}
	virtual void onParticipantProfilePictureStatusChange(bool bHidden)
	{
		
	}
	virtual void onFocusModeStateChanged(bool bEnabled)
	{

	}
	virtual void onFocusModeShareTypeChanged(ZOOM_SDK_NAMESPACE::FocusModeShareType type)
	{

	}
private:
	ZMeetingParticipantsWrap* owner_;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingH323CtrlWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingH323HelperEvent
{
public:
	void SetOwner(ZMeetingH323Wrap* obj) { owner_ = obj; }
	virtual void onCalloutStatusNotify(ZOOM_SDK_NAMESPACE::H323CalloutStatus status)
	{
		if (owner_) {
			owner_->onH323CalloutStatusNotify(Map2WrapDefine(status));
		}
	}
	virtual void onParingH323Result(ZOOM_SDK_NAMESPACE::H323ParingResult result, UINT64 meetingNumber)
	{
		//
	}
private:
	ZMeetingH323Wrap* owner_;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZMeetingPasswordAndScreenNameHandler
{
public:
	static ZMeetingPasswordAndScreenNameHandler& GetInst()
	{
		static ZMeetingPasswordAndScreenNameHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler *handler)
	{
		m_pHandler = handler;
	}

	ZNRequiredInfoType GetRequiredInfoType()
	{
		ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler::RequiredInfoType type = ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler::REQUIRED_INFO_TYPE_NONE;
		if (m_pHandler)
			type = m_pHandler->GetRequiredInfoType();
		return Map2WrapDefine(type);
	}

	bool InputMeetingPasswordAndScreenName(ZoomSTRING meetingPassword, ZoomSTRING screenName)
	{
		bool bret = false;
		if (m_pHandler)
			bret = m_pHandler->InputMeetingPasswordAndScreenName(meetingPassword.c_str(), screenName.c_str());
		m_pHandler = NULL;
		return bret;
	}
	bool InputMeetingIDAndScreenName(ZoomSTRING meetingID, ZoomSTRING screenName)
	{
		bool bret = false;
		if (m_pHandler)
			bret = m_pHandler->InputMeetingPasswordAndScreenName(meetingID.c_str(), screenName.c_str());
		m_pHandler = NULL;
		return bret;
	}
	bool InputMeetingScreenName(ZoomSTRING screenName)
	{
		bool bret = false;
		if (m_pHandler)
			bret = m_pHandler->InputMeetingScreenName(screenName.c_str());
		m_pHandler = NULL;
		return bret;
	}
	void Cancel()
	{
		if (m_pHandler)
			m_pHandler->Cancel();
		m_pHandler = NULL;
	}
private:
	ZMeetingPasswordAndScreenNameHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler* m_pHandler;
};
class ZWebinarNeedRegisterHandler
{
public:
	static ZWebinarNeedRegisterHandler& GetInst()
	{
		static ZWebinarNeedRegisterHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandler *handler)
	{
		m_pHandler = handler;
	}
	ZNWebinarNeedRegisterType GetWebinarNeedRegisterType()
	{
		ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandler::WebinarNeedRegisterType type = ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandler::WebinarReg_NONE;
		if (m_pHandler)
			type = m_pHandler->GetWebinarNeedRegisterType();
		return Map2WrapDefine(type);
	}
	ZoomSTRING GetWebinarRegisterUrl()
	{
		ZoomSTRING zn_url;
		if (m_pHandler)
		{
			ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByUrl* m_pURL = (ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByUrl*)m_pHandler;
			zn_url = m_pURL->GetWebinarRegisterUrl();
		}
		m_pHandler = NULL;
		return zn_url;
	}
	void Release()
	{
		if (m_pHandler)
		{
			ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByUrl* m_pURL = (ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByUrl*)m_pHandler;
			m_pURL->Release();
		}
		m_pHandler = NULL;
	}
	ZNSDKError InputWebinarRegisterEmailAndScreenName(ZoomSTRING email, ZoomSTRING screenName)
	{
		ZNSDKError zn_err = ZNSDKERR_UNKNOWN;
		if (m_pHandler)
		{
			ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByEmail* m_pURL = (ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByEmail*)m_pHandler;
			zn_err = Map2WrapDefine(m_pURL->InputWebinarRegisterEmailAndScreenName(email.c_str(), screenName.c_str()));
		}
		m_pHandler = NULL;
		return zn_err;
	}
	void Cancel()
	{
		if (m_pHandler)
		{
			ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByEmail* m_pURL = (ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByEmail*)m_pHandler;
			m_pURL->Cancel();
		}
		m_pHandler = NULL;
	}
private:
	ZWebinarNeedRegisterHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandler* m_pHandler;
};
class ZEndOtherMeetingToJoinMeetingHandler
{
public:
	static ZEndOtherMeetingToJoinMeetingHandler& GetInst()
	{
		static ZEndOtherMeetingToJoinMeetingHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IEndOtherMeetingToJoinMeetingHandler *handler)
	{
		m_pHandler = handler;
	}
	bool EndOtherMeeting()
	{
		bool bret = false;
		if (m_pHandler)
		{
			bret = m_pHandler->EndOtherMeeting();
		}
		m_pHandler = NULL;
		return bret;
	}
	void Cancel()
	{
		if (m_pHandler)
		{
			m_pHandler->Cancel();
		}
		m_pHandler = NULL;
	}
private:
	ZEndOtherMeetingToJoinMeetingHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IEndOtherMeetingToJoinMeetingHandler* m_pHandler;
};
class ZWebinarInputScreenNameHandler
{
public:
	static ZWebinarInputScreenNameHandler& GetInst()
	{
		static ZWebinarInputScreenNameHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IWebinarInputScreenNameHandler *handler)
	{
		m_pHandler = handler;
	}
	ZNSDKError InputName(ZoomSTRING screenName)
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			err = m_pHandler->InputName(screenName.c_str());
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}
	ZNSDKError Cancel()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			err = m_pHandler->Cancel();
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}
private:
	ZWebinarInputScreenNameHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IWebinarInputScreenNameHandler* m_pHandler;
};

class ZMeetingConfigCtrlWrapFreeMeetingEvent : public ZOOM_SDK_NAMESPACE::IMeetingConfigurationEvent
{
public:
	void SetOwner(ZMeetingConfigWrap* obj) { owner_ = obj; }
	virtual void onFreeMeetingRemainTime(unsigned int leftTime)
	{
		if (owner_) {
			owner_->onFreeMeetingRemainTime(leftTime);
		}
	}
	virtual void onFreeMeetingRemainTimeStopCountDown()
	{
		if (owner_) {
			owner_->onFreeMeetingRemainTimeStopCountDown();
		}
	}
	virtual void onFreeMeetingNeedToUpgrade(ZOOM_SDK_NAMESPACE::IMeetingConfigurationFreeMeetingEvent::FreeMeetingNeedUpgradeType type_, const wchar_t* gift_url)
	{
		if (owner_) {
			ZoomSTRING zn_gift_url = L"";
			if (gift_url)
			{
				zn_gift_url = gift_url;
			}
			owner_->onFreeMeetingNeedToUpgrade(Map2WrapDefine(type_), zn_gift_url);
		}
	}
	virtual void onFreeMeetingUpgradeToGiftFreeTrialStart()
	{
		if (owner_) {
			owner_->onFreeMeetingUpgradeToGiftFreeTrialStart();
		}
	}
	virtual void onFreeMeetingUpgradeToGiftFreeTrialStop()
	{
		if (owner_) {
			owner_->onFreeMeetingUpgradeToGiftFreeTrialStop();
		}
	}
	virtual void onFreeMeetingUpgradeToProMeeting()
	{
		if (owner_) {
			owner_->onFreeMeetingUpgradeToProMeeting();
		}
	}
	virtual void onInputMeetingPasswordAndScreenNameNotification(ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler* pHandler)
	{
		if (owner_ && pHandler) {
			ZMeetingPasswordAndScreenNameHandler::GetInst().SetHandler(pHandler);
			owner_->onInputMeetingPasswordAndScreenNameNotification();
		}
	}
	virtual void onAirPlayInstructionWndNotification(bool bShow, const wchar_t* airhostName)
	{
		if (owner_) {
			ZoomSTRING zn_airHostName = L"";
			if (airhostName)
			{
				zn_airHostName = airhostName;
			}
			owner_->onAirPlayInstructionWndNotification(bShow, zn_airHostName);
		}
	}
	virtual void onWebinarNeedRegisterNotification(ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandler* pHandler)
	{
		if (owner_ && pHandler) {
			ZWebinarNeedRegisterHandler::GetInst().SetHandler(pHandler);
			owner_->onWebinarNeedRegisterNotification();
		}
	}
	virtual void onEndOtherMeetingToJoinMeetingNotification(ZOOM_SDK_NAMESPACE::IEndOtherMeetingToJoinMeetingHandler* pHandler)
	{
		if (owner_ && pHandler) {
			ZEndOtherMeetingToJoinMeetingHandler::GetInst().SetHandler(pHandler);
			owner_->onEndOtherMeetingToJoinMeetingNotification();
		}
	}
	virtual void onWebinarNeedInputScreenName(ZOOM_SDK_NAMESPACE::IWebinarInputScreenNameHandler* pHandler)
	{
		if (owner_ && pHandler) {
			ZWebinarInputScreenNameHandler::GetInst().SetHandler(pHandler);
			owner_->onWebinarNeedInputScreenName();
		}
	}
private:
	ZMeetingConfigWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingReminderHandler
{
public:
	static ZMeetingReminderHandler& GetInst()
	{
		static ZMeetingReminderHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IMeetingReminderHandler *handler)
	{
		m_pHandler = handler;
	}

	ZNSDKError Ignore()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			m_pHandler->Ignore();
			err = ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS;
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError Accept()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			m_pHandler->Accept();
			err = ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS;
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError Decline()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			m_pHandler->Decline();
			err = ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS;
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}
private:
	ZMeetingReminderHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IMeetingReminderHandler* m_pHandler;
};

class ZMeetingEnableReminderHandler
{
public:
	static ZMeetingEnableReminderHandler& GetInst()
	{
		static ZMeetingEnableReminderHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IMeetingEnableReminderHandler *handler)
	{
		m_pHandler = handler;
	}

	ZNSDKError SetEnableOption(ZNFeatureEnableOption option)
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			err = m_pHandler->SetEnableOption(Map2WrapDefine(option));
		}
		return Map2WrapDefine(err);
	}

	ZNSDKError Start()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			err = m_pHandler->Start();
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError Decline(bool bDeclineAll)
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			err = m_pHandler->Decline(bDeclineAll);
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError Ignore()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			err = m_pHandler->Ignore();
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}
private:
	ZMeetingEnableReminderHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IMeetingEnableReminderHandler* m_pHandler;
};

class ZMeetingReminderCtrlEvent : public ZOOM_SDK_NAMESPACE::IMeetingReminderEvent
{
public:
	void SetOwner(ZMeetingReminderWrap* obj) { owner_ = obj; }
	virtual void onReminderNotify(ZOOM_SDK_NAMESPACE::IMeetingReminderContent* reminder, ZOOM_SDK_NAMESPACE::IMeetingReminderHandler* handle)
	{
		if (owner_ && reminder)
		{
			ZMeetingReminderHandler::GetInst().SetHandler(handle);

			ZNMeetingReminderContent zn_meeting_reminder;
			zn_meeting_reminder.title = reminder->GetTitle();
			zn_meeting_reminder.content = reminder->GetContent();
			zn_meeting_reminder.is_blocking = reminder->IsBlocking();
			zn_meeting_reminder.type = Map2WrapDefine(reminder->GetType());
			owner_->onReminderNotify(zn_meeting_reminder);
		}
	}
	virtual void onEnableReminderNotify(ZOOM_SDK_NAMESPACE::IMeetingReminderContent* reminder, ZOOM_SDK_NAMESPACE::IMeetingEnableReminderHandler* handle)
	{
		if (owner_ && reminder)
		{
			ZMeetingEnableReminderHandler::GetInst().SetHandler(handle);

			ZNMeetingReminderContent zn_meeting_reminder;
			zn_meeting_reminder.title = reminder->GetTitle();
			zn_meeting_reminder.content = reminder->GetContent();
			zn_meeting_reminder.is_blocking = reminder->IsBlocking();
			zn_meeting_reminder.type = Map2WrapDefine(reminder->GetType());
			owner_->onEnableReminderNotify(zn_meeting_reminder);
		}
	}
private:
	ZMeetingReminderWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingChatCtrlEvent : public ZOOM_SDK_NAMESPACE::IMeetingChatCtrlEvent
{
public:
	void SetOwner(ZMeetingChatWrap* obj) { owner_ = obj; }
	virtual void onChatMsgNotifcation(ZOOM_SDK_NAMESPACE::IChatMsgInfo* chatMsg, const zchar_t* content)
	{
		if (owner_) {
			ZoomSTRING zn_content;
			if (content)
			{
				zn_content = content;
			}
			ZNChatMsgInfo zn_chat_msg_info;
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
			owner_->onChatMsgNotifcation(zn_chat_msg_info, zn_content);
		}
	}
	virtual void onChatStatusChangedNotification(ZOOM_SDK_NAMESPACE::ChatStatus* status)
	{
		if (owner_) {
			ZNChatStatus zn_chat_status;
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
			owner_->onChatStatusChangedNotification(zn_chat_status);
		}
	}
	virtual void onChatMsgDeleteNotification(const zchar_t* msgID, ZOOM_SDK_NAMESPACE::SDKChatMessageDeleteType deleteBy)
	{
		if (owner_) {
			ZoomSTRING zn_msgID;
			if (msgID)
			{
				zn_msgID = msgID;
				owner_->onChatMsgDeleteNotification(zn_msgID, Map2WrapDefine(deleteBy));
			}
		}
	}
	virtual void onShareMeetingChatStatusChanged(bool isStart)
	{
		if (owner_) {
			owner_->onShareMeetingChatStatusChanged(isStart);
		}
	}
private:
	ZMeetingChatWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingWaitingRoomHandler
{
public:
	static ZMeetingWaitingRoomHandler& GetInst()
	{
		static ZMeetingWaitingRoomHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IWaitingRoomDataDownloadHandler *handler)
	{
		m_pHandler = handler;
	}

	ZNSDKError Retry()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			m_pHandler->Retry();
			err = ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS;
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError Ignore()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			m_pHandler->Ignore();
			err = ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS;
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}
private:
	ZMeetingWaitingRoomHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IWaitingRoomDataDownloadHandler* m_pHandler;
};

class ZMeetingWaitingRoomCtrlEvent : public ZOOM_SDK_NAMESPACE::IMeetingWaitingRoomEvent
{
public:
	void SetOwner(ZMeetingWaitingRoomWrap* obj) { owner_ = obj; }
	virtual void onWaitingRoomUserJoin(unsigned int userID)
	{
		if (owner_) {
			owner_->onWaitingRoomUserJoin(userID);
		}
	}
	virtual void onWaitingRoomUserLeft(unsigned int userID)
	{
		if (owner_) {
			owner_->onWaitingRoomUserLeft(userID);
		}
	}
	virtual void onWaitingRoomPresetAudioStatusChanged(bool bAudioCanTurnOn)
	{
		if (owner_) {
			owner_->onWaitingRoomPresetAudioStatusChanged(bAudioCanTurnOn);
		}
	}
	virtual void onWaitingRoomPresetVideoStatusChanged(bool bVideoCanTurnOn)
	{
		if (owner_) {
			owner_->onWaitingRoomPresetVideoStatusChanged(bVideoCanTurnOn);
		}
	}
	virtual void onCustomWaitingRoomDataUpdated(ZOOM_SDK_NAMESPACE::CustomWaitingRoomData& bData, ZOOM_SDK_NAMESPACE::IWaitingRoomDataDownloadHandler* bHandler)
	{
		if (owner_) {
			ZMeetingWaitingRoomHandler::GetInst().SetHandler(bHandler);

			ZNCustomWaitingRoomData zn_custom_waiting_room_data;
			zn_custom_waiting_room_data.title = bData.title;
			zn_custom_waiting_room_data.description = bData.description;
			zn_custom_waiting_room_data.logo_path = bData.logo_path;
			zn_custom_waiting_room_data.video_path = bData.video_path;
			zn_custom_waiting_room_data.image_path = bData.image_path;
			zn_custom_waiting_room_data.type = Map2WrapDefine(bData.type);
			zn_custom_waiting_room_data.status = Map2WrapDefine(bData.status);
			owner_->onCustomWaitingRoomDataUpdated(zn_custom_waiting_room_data);
		}
	}
	virtual void onWaitingRoomUserNameChanged(unsigned int userID, const zchar_t* userName)
	{
		if (owner_) {
			ZoomSTRING zn_userName;
			if (userName)
			{
				zn_userName = userName;
			}
			owner_->onWaitingRoomUserNameChanged(userID, zn_userName);
		}
	}
	virtual void onWaitingRoomEntranceEnabled(bool bIsEnabled)
	{
		if (owner_) {
			owner_->onWaitingRoomEntranceEnabled(bIsEnabled);
		}
	}
private:
	ZMeetingWaitingRoomWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingSmartSummaryHandler
{
public:
	static ZMeetingSmartSummaryHandler& GetInst()
	{
		static ZMeetingSmartSummaryHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::ISmartSummaryPrivilegeHandler *handler)
	{
		m_pHandler = handler;
	}

	ZNSDKError Accept()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			err = m_pHandler->Accept();
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError Decline()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			err = m_pHandler->Decline();
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError Ignore()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
		{
			err = m_pHandler->Ignore();
		}
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}
private:
	ZMeetingSmartSummaryHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::ISmartSummaryPrivilegeHandler* m_pHandler;
};

class ZMeetingSmartSummaryCtrlEvent : public ZOOM_SDK_NAMESPACE::IMeetingSmartSummaryControllerEvent
{
public:
	void SetOwner(ZMeetingSmartSummaryWrap* obj) { owner_ = obj; }
	virtual void onSmartSummaryStatusChange(bool isStarted)
	{
		if (owner_) {
			owner_->onSmartSummaryStatusChange(isStarted);
		}
	}
	virtual void onSmartSummaryPrivilegeRequested(unsigned int senderId, ZOOM_SDK_NAMESPACE::ISmartSummaryPrivilegeHandler* handler)
	{
		if (owner_) {
			ZMeetingSmartSummaryHandler::GetInst().SetHandler(handler);

			owner_->onSmartSummaryPrivilegeRequested(senderId);
		}
	}
	virtual void onSmartSummaryStartReqResponse(bool timeout, bool decline)
	{
		if (owner_) {
			owner_->onSmartSummaryStartReqResponse(timeout, decline);
		}
	}
	virtual void onEnableSmartSummary()
	{
		if (owner_) {
			owner_->onEnableSmartSummary();
		}
	}
private:
	ZMeetingSmartSummaryWrap* owner_;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZDirectShareViaMeetingIDOrPairingCodeHandler
{
public:
	static ZDirectShareViaMeetingIDOrPairingCodeHandler& GetInst()
	{
		static ZDirectShareViaMeetingIDOrPairingCodeHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IDirectShareViaMeetingIDOrPairingCodeHandler *handler)
	{
		m_pHandler = handler;
	}

	ZNSDKError TryWithMeetingNumber(unsigned long long meetingNumber)
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
			err = m_pHandler->TryWithMeetingNumber(meetingNumber);
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError TryWithPairingCode(ZoomSTRING paringCode)
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
			err = m_pHandler->TryWithPairingCode(paringCode.c_str());
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError Cancel()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
			err = m_pHandler->Cancel();
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}
private:
	ZDirectShareViaMeetingIDOrPairingCodeHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IDirectShareViaMeetingIDOrPairingCodeHandler* m_pHandler;
};

class ZDirectShareHelperWrapEvent : public ZOOM_SDK_NAMESPACE::IDirectShareServiceHelperEvent
{
public:
	void SetOwner(ZDirectShareHelperWrap* obj) { owner_ = obj; }
	virtual void OnDirectShareStatusUpdate(ZOOM_SDK_NAMESPACE::DirectShareStatus status, ZOOM_SDK_NAMESPACE::IDirectShareViaMeetingIDOrPairingCodeHandler* handler)
	{

		if (owner_) {

			if ((status == ZOOM_SDK_NAMESPACE::DirectShare_Need_MeetingID_Or_PairingCode) || (status == ZOOM_SDK_NAMESPACE::DirectShare_WrongMeetingID_Or_SharingKey))
			{
				ZDirectShareViaMeetingIDOrPairingCodeHandler::GetInst().SetHandler(handler);
			}
			owner_->OnDirectShareStatusUpdate(Map2WrapDefine(status));
		}
	}
	virtual void OnDirectShareSpecifyContent(ZOOM_SDK_NAMESPACE::IDirectShareSpecifyContentHandler* handler)
	{
	}
private:
	ZDirectShareHelperWrap* owner_;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZoomRetrieveSMSVerificationCodeHandler
{
public:
	static ZoomRetrieveSMSVerificationCodeHandler& GetInst()
	{
		static ZoomRetrieveSMSVerificationCodeHandler inst;
		return inst;
	}
	void SetHandler(IZoomRetrieveSMSVerificationCodeHandler* handler)
	{
		m_pHandler = handler;
	}
	bool Retrieve(const zTCHAR* country_code, const zTCHAR* phone_number)
	{
		bool b_ret = false;
		if (m_pHandler)
		{
			b_ret = m_pHandler->Retrieve(country_code, phone_number);
		}
		m_pHandler = NULL;
		return b_ret;
	}
	bool CancelAndLeaveMeeting()
	{
		bool b_ret = false;
		if (m_pHandler)
		{
			b_ret = m_pHandler->CancelAndLeaveMeeting();
		}
		m_pHandler = NULL;
		return b_ret;
	}
private:
	ZoomRetrieveSMSVerificationCodeHandler() :m_pHandler(NULL) {}
	IZoomRetrieveSMSVerificationCodeHandler* m_pHandler;
};
class ZoomVerifySMSVerificationCodeHandler
{
public:
	static ZoomVerifySMSVerificationCodeHandler& GetInst()
	{
		static ZoomVerifySMSVerificationCodeHandler inst;
		return inst;
	}
	void SetHandler(IZoomVerifySMSVerificationCodeHandler* handler)
	{
		m_pHandler = handler;
	}
	bool Verify(const zTCHAR* country_code, const zTCHAR* phone_number, const zTCHAR* verification_code)
	{
		bool b_ret = false;
		if (m_pHandler)
		{
			b_ret = m_pHandler->Verify(country_code, phone_number, verification_code);
		}
		m_pHandler = NULL;
		return b_ret;
	}
	bool CancelAndLeaveMeeting()
	{
		bool b_ret = false;
		if (m_pHandler)
		{
			b_ret = m_pHandler->CancelAndLeaveMeeting();
		}
		m_pHandler = NULL;
		return b_ret;
	}
private:
	ZoomVerifySMSVerificationCodeHandler() :m_pHandler(NULL) {}
	IZoomVerifySMSVerificationCodeHandler* m_pHandler;
};

class ZZoomRealNameAuthMeetingWrapEvent : public IZoomRealNameAuthMeetingEvent
{
public:
	void SetOwner(ZSDKSMSHelperWrap* obj) { owner_ = obj; }
	virtual void onNeedRealNameAuthMeetingNotification(IVector<IZoomRealNameAuthCountryInfo* >* support_country_list, const zTCHAR* privacy_url, IZoomRetrieveSMSVerificationCodeHandler* handler)
	{
		if (owner_ && support_country_list && handler)
		{
			ZoomRetrieveSMSVerificationCodeHandler::GetInst().SetHandler(handler);
			ZNList<ZNZoomRealNameAuthCountryInfo> SMSCountryInfo_list;
			for (int i = 0; i < support_country_list->GetCount(); ++i)
			{
				ZNZoomRealNameAuthCountryInfo countryInfo;
				IZoomRealNameAuthCountryInfo* temp_pCountryInfo = support_country_list->GetItem(i);
				if (temp_pCountryInfo)
				{
					countryInfo.countryID = (const wchar_t*)temp_pCountryInfo->GetCountryID();
					countryInfo.countryName = (const wchar_t*)temp_pCountryInfo->GetCountryName();
					countryInfo.countryCode = (const wchar_t*)temp_pCountryInfo->GetCountryCode();
				}
				SMSCountryInfo_list.push_back(countryInfo);
			}
			ZoomSTRING zn_privacy_url = L"";
			if (privacy_url)
			{
				zn_privacy_url = (const wchar_t*)privacy_url;
			}
			
			owner_->onNeedRealNameAuthMeetingNotification(SMSCountryInfo_list, zn_privacy_url);
		}
	}
	virtual void onRetrieveSMSVerificationCodeResultNotification(SMSVerificationCodeErr result, IZoomVerifySMSVerificationCodeHandler* handler)
	{
		if (owner_)
		{
			if (SMSVerificationCodeErr_Success == result)
			{
				ZoomVerifySMSVerificationCodeHandler::GetInst().SetHandler(handler);
			}
			owner_->onRetrieveSMSVerificationCodeResultNotification(Map2WrapDefine(result));
		}
	}
	virtual void onVerifySMSVerificationCodeResultNotification(SMSVerificationCodeErr result)
	{
		if (owner_)
		{
			owner_->onRetrieveSMSVerificationCodeResultNotification(Map2WrapDefine(result));
		}
	}
private:
	ZSDKSMSHelperWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZAudioSettingContextWrapEvent : public ZOOM_SDK_NAMESPACE::IAudioSettingContextEvent
{
public:
	void SetOwner(ZSettingAudioWrap* obj) { owner_ = obj; }
	virtual void onComputerMicDeviceChanged(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IMicInfo*>* pMicLst)
	{
		if (owner_)
		{
			ZNList<ZNMicInfo> zn_mic_list;
			if (pMicLst && pMicLst->GetCount() > 0)
			{
				int count = pMicLst->GetCount();
				for (int i = 0; i < count; i++)
				{
					ZOOM_SDK_NAMESPACE::IMicInfo* pMicInfo = pMicLst->GetItem(i);
					ZNMicInfo zn_mic_info;
					if (NULL == pMicInfo)
						continue;

					if (pMicInfo->GetDeviceName())
					{
						zn_mic_info.deviceName = pMicInfo->GetDeviceName();
					}
					if (pMicInfo->GetDeviceId())
					{
						zn_mic_info.deviceId = pMicInfo->GetDeviceId();
					}
					zn_mic_info.isSelectedDevice = pMicInfo->IsSelectedDevice();
					zn_mic_list.push_back(zn_mic_info);
				}
			}
			owner_->onComputerMicDeviceChanged(zn_mic_list);
		}
	}
	virtual void onComputerSpeakerDeviceChanged(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ISpeakerInfo*>* pSpeakerLst)
	{
		if (owner_)
		{
			ZNList<ZNSpeakerInfo> zn_speaker_list;
			if (pSpeakerLst && pSpeakerLst->GetCount() > 0)
			{
				int count = pSpeakerLst->GetCount();
				for (int i = 0; i < count; i++)
				{
					ZOOM_SDK_NAMESPACE::ISpeakerInfo* pSpeakerInfo = pSpeakerLst->GetItem(i);
					ZNSpeakerInfo zn_speaker_info;
					if (NULL == pSpeakerInfo)
						continue;

					if (pSpeakerInfo->GetDeviceName())
					{
						zn_speaker_info.deviceName = pSpeakerInfo->GetDeviceName();
					}
					if (pSpeakerInfo->GetDeviceId())
					{
						zn_speaker_info.deviceId = pSpeakerInfo->GetDeviceId();
					}
					zn_speaker_info.isSelectedDevice = pSpeakerInfo->IsSelectedDevice();
					zn_speaker_list.push_back(zn_speaker_info);
				}
			}
			owner_->onComputerSpeakerDeviceChanged(zn_speaker_list);
		}
	}
	virtual void onDefaultMicDeviceChanged(const wchar_t* deviceId, const wchar_t* deviceName)
	{
		if (owner_)
		{
			ZoomSTRING zn_deviceId;
			ZoomSTRING zn_deviceName;
			if (deviceId)
			{
				zn_deviceId = deviceId;
			}
			if (deviceName)
			{
				zn_deviceName = deviceName;
			}
			owner_->onDefaultMicDeviceChanged(zn_deviceId, zn_deviceName);
		}
	}
	virtual void onDefaultSpeakerDeviceChanged(const wchar_t* deviceId, const wchar_t* deviceName)
	{
		if (owner_)
		{
			ZoomSTRING zn_deviceId;
			ZoomSTRING zn_deviceName;
			if (deviceId)
			{
				zn_deviceId = deviceId;
			}
			if (deviceName)
			{
				zn_deviceName = deviceName;
			}
			owner_->onDefaultSpeakerDeviceChanged(zn_deviceId, zn_deviceName);
		}
	}
private:
	ZSettingAudioWrap* owner_;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZVideoSettingContextWrapEvent : public ZOOM_SDK_NAMESPACE::IVideoSettingContextEvent
{
public:
	void SetOwner(ZSettingVideoWrap* obj) { owner_ = obj; }
	virtual void onComputerCamDeviceChanged(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ICameraInfo*>* pCameraList)
	{
		if (owner_)
		{
			ZNList<ZNCameraInfo> zn_camera_list;
			if (pCameraList && pCameraList->GetCount() > 0)
			{
				int count = pCameraList->GetCount();
				for (int i = 0; i < count; i++)
				{
					ZOOM_SDK_NAMESPACE::ICameraInfo* pCameraInfo = pCameraList->GetItem(i);
					ZNCameraInfo zn_camera_info;
					if (NULL == pCameraInfo)
						continue;

					if (pCameraInfo->GetDeviceName())
					{
						zn_camera_info.deviceName = pCameraInfo->GetDeviceName();
					}
					if (pCameraInfo->GetDeviceId())
					{
						zn_camera_info.deviceId = pCameraInfo->GetDeviceId();
					}
					zn_camera_info.isSelectedDevice = pCameraInfo->IsSelectedDevice();
					zn_camera_list.push_back(zn_camera_info);
				}
			}
			owner_->onComputerCamDeviceChanged(zn_camera_list);

		}
	}
	virtual void onDefaultCamDeviceChanged(const wchar_t* deviceId, const wchar_t* deviceName)
	{
		if (owner_)
		{
			ZoomSTRING zn_deviceId;
			ZoomSTRING zn_deviceName;
			if (deviceId)
			{
				zn_deviceId = deviceId;
			}
			if (deviceName)
			{
				zn_deviceName = deviceName;
			}
			owner_->onDefaultCamDeviceChanged(zn_deviceId, zn_deviceName);
		}
	}

private:
	ZSettingVideoWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZRecordingSettingContextWrapEvent : public ZOOM_SDK_NAMESPACE::IRecordingSettingContextEvent
{
public:
	void SetOwner(ZSettingRecordingWrap* obj) { owner_ = obj; }
	virtual void onCloudRecordingStorageInfo(INT64 storage_total_size, INT64 storage_used_size, bool allow_exceed_storage)
	{
		if (owner_)
		{

			owner_->onCloudRecordingStorageInfo(storage_total_size, storage_used_size, allow_exceed_storage);
		}
	}
private:
	ZSettingRecordingWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZNRequestRawLiveStreamPrivilegeHandler
{
public:
	static ZNRequestRawLiveStreamPrivilegeHandler& GetInst()
	{
		static ZNRequestRawLiveStreamPrivilegeHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IRequestRawLiveStreamPrivilegeHandler* handler)
	{
		m_pHandler = handler;
	}
	ZoomSTRING GetRequestId()
	{
		ZoomSTRING reqId;
		if (m_pHandler && m_pHandler->GetRequestId())
		{
			reqId = m_pHandler->GetRequestId();
		}
		return reqId;
	}
	unsigned int GetRequesterId()
	{
		unsigned int id = 0xffff;
		if (m_pHandler)
		{
			id = m_pHandler->GetRequesterId();
		}
		return id;
	}
	ZoomSTRING GetRequesterName()
	{
		ZoomSTRING userName;
		if (m_pHandler && m_pHandler->GetRequesterName())
		{
			userName = m_pHandler->GetRequesterName();
		}
		return userName;
	}
	ZoomSTRING GetBroadcastUrl()
	{
		ZoomSTRING userName;
		if (m_pHandler && m_pHandler->GetBroadcastUrl())
		{
			userName = m_pHandler->GetBroadcastUrl();
		}
		return userName;
	}
	ZNSDKError GrantRawLiveStreamPrivilege()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
			err = m_pHandler->GrantRawLiveStreamPrivilege();
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}
	ZNSDKError DenyRawLiveStreamPrivilege()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USAGE;
		if (m_pHandler)
			err = m_pHandler->DenyRawLiveStreamPrivilege();
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}
private:
	ZNRequestRawLiveStreamPrivilegeHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IRequestRawLiveStreamPrivilegeHandler* m_pHandler;
};


class ZMeetingLiveStreamWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingLiveStreamCtrlEvent
{
public:
	void SetOwner(ZMeetingLiveStreamWrap* obj) { owner_ = obj; }
	virtual void onLiveStreamStatusChange(ZOOM_SDK_NAMESPACE::LiveStreamStatus status)
	{
		if (owner_)
		{

			owner_->onLiveStreamStatusChange(Map2WrapDefine(status));
		}
	}
	virtual void onRawLiveStreamPrivilegeChanged(bool bHasPrivilege)
	{
		if (owner_)
		{
			owner_->onRawLiveStreamPrivilegeChanged(bHasPrivilege);
		}
	}
	virtual void onUserRawLiveStreamPrivilegeChanged(unsigned int userid, bool bHasPrivilege)
	{
		if (owner_)
		{
			owner_->onUserRawLiveStreamPrivilegeChanged(userid, bHasPrivilege);
		}
	}
	virtual void onRawLiveStreamPrivilegeRequested(ZOOM_SDK_NAMESPACE::IRequestRawLiveStreamPrivilegeHandler* handler)
	{
		if (owner_ && handler) {
			ZNRequestRawLiveStreamPrivilegeHandler::GetInst().SetHandler(handler);
			owner_->onRawLiveStreamPrivilegeRequested();
		}
	}
	virtual void onUserRawLiveStreamingStatusChanged(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::RawLiveStreamInfo>* pLivingList)
	{
		if (owner_)
		{
			ZNList<ZNRawLiveStreamInfo> zn_rawLiveStreamInfolist;
			if (pLivingList && pLivingList->GetCount() > 0)
			{
				int count = pLivingList->GetCount();
				for (int i = 0; i < count; i++)
				{
					ZOOM_SDK_NAMESPACE::RawLiveStreamInfo RawLiveStreamInfo = pLivingList->GetItem(i);
					ZNRawLiveStreamInfo zn_live_stream_info;

					if (RawLiveStreamInfo.broadcastUrl)
					{
						zn_live_stream_info.broadcastUrl = RawLiveStreamInfo.broadcastUrl;
					}
					zn_live_stream_info.userId = RawLiveStreamInfo.userId;
					zn_rawLiveStreamInfolist.push_back(zn_live_stream_info);
				}
			}
			owner_->onUserRawLiveStreamingStatusChanged(zn_rawLiveStreamInfolist);

		}
	}
	virtual void onRawLiveStreamPrivilegeRequestTimeout()
	{
		if (owner_)
		{
			owner_->onRawLiveStreamPrivilegeRequestTimeout();
		}
	}
private:
	ZMeetingLiveStreamWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class SDKEventWrapMgr
{
public:
	//auth_service_cb
	ZAuthServiceWrapEvent m_authServiceWrapEvent;

	//meeting_service_cb
	ZMeetingServiceWrapEvent m_meetingServiceWrapEvent;

	//meeting_ui_ctrl_cb
	ZMeetingUIControllerWrapEvent m_meetingUICtrlWrapEvent;

	//meeting_audio_ctrl_cb
	ZMeetingAudioCtrlWrapEvent m_meetingAudioCtrlWrapEvent;
	
	//meeting_video_ctrl_cb
	ZMeetingVideoCtrlWrapEvent m_meetingVideoCtrlWrapEvent;

	//meeting_share_ctrl_cb
	ZMeetingShareCtrlWrapEvent m_meetingShareCtrlWrapEvent;

	//meeting_recording_ctrl_cb
	ZMeetingRecordingCtrlWrapEvent m_meetingRecordingCtrlWrapEvent;

	//meeting_participants_ctrl_cb
	ZMeetingParticipantsCtrlEvent m_meetingParticipantsCtrlEvent;

	//meeting_h323_ctrl_cb
	ZMeetingH323CtrlWrapEvent m_meetingH323CtrlWrapEvent;

	//meeting_config_ctrl_cb
	ZMeetingConfigCtrlWrapFreeMeetingEvent m_meetingConfigCtrlWrapEvent;

	//meeting_reminder_ctrl_cb
	ZMeetingReminderCtrlEvent m_meetingReminderCtrlEvent;

	//meeting_chat_ctrl_cb
	ZMeetingChatCtrlEvent m_meetingChatCtrlEvent;

	//meeting_waiting_room_ctrl_cb
	ZMeetingWaitingRoomCtrlEvent m_meetingWaitingRoomCtrlEvent;

	//meeting_smart_summary_ctrl_cb
	ZMeetingSmartSummaryCtrlEvent m_meetingSmartSummaryCtrlEvent;

	//direct_share_helper_cb
	ZDirectShareHelperWrapEvent m_directShareHelperWrapEvent;

	//sms_helper_cb
	ZZoomRealNameAuthMeetingWrapEvent m_zoomRealNameAuthMeetingWrapEvent;

	//audio_setting_context_cb
	ZAudioSettingContextWrapEvent m_audioSettingContextWrapEvent;

	//video_setting_context_cb
	ZVideoSettingContextWrapEvent m_videoSettingContextWrapEvent;

	//recording_setting_context_cb
	ZRecordingSettingContextWrapEvent m_recordingSettingContextWrapEvent;

	//meeting_live_stream_ctrl_cb
	ZMeetingLiveStreamWrapEvent m_meetingLiveStreamWrapEvent;


	static SDKEventWrapMgr& GetInst()
	{
		static SDKEventWrapMgr inst;
		return inst;
	}
	~SDKEventWrapMgr() {}
private:
	SDKEventWrapMgr() {}
};
#endif // !_sdk_sinks_wrap_class_h_
