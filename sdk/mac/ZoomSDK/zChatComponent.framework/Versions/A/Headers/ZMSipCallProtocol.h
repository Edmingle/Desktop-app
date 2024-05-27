//
//  ZMSipCallProtocol.h
//  zChatComponent
//
//  Created by groot.ding on 6/29/23.
//

#ifndef ZMSipCallProtocol_h
#define ZMSipCallProtocol_h

#import <zChatComponent/ZMSipContactItemProtocol.h>

@class ZMBuddyAdapter;
@class ZMSipCloudPBX;

@protocol ZMSipCallWarningProtocol <ZMRoutableObject>

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)pDelegate andCallBack:(NSString*)strCallBack andParam:(id)idParam andIsJoinMeeting:(BOOL)isJoinMeeting;

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)pDelegate andCallBack:(NSString*)strCallBack andParam:(id)idParam;

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)deleagte userJID:(NSString*)jid openVideo:(BOOL)open;

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)pDelegate andCallBack:(NSString*)strCallBack andCancelCallBack:(NSString*)strCancelCallBack andParam:(id)idParam andIsJoinMeeting:(BOOL)isJoinMeeting;

- (void)closeWhenDelegateRelease:(id)privateDelegate;

- (void)closeWhenMeetingDeleted:(id)privateDelegate andMeetingNum:(long long)meetingNum;

@end


@protocol ZMSipCallProtocol <ZMRoutableObject>

@required

- (BOOL)isSIPFeatureEnabled;

- (BOOL)checkPhoneTabIsVisible;

- (BOOL)isInCallWithAdapter:(ZMBuddyAdapter *)buddy;

- (BOOL)isInCallWithNumber:(NSString *)number;

- (BOOL)isCloudPBXEnable;

- (BOOL)isCallPSTNEnable;

- (ZMSipCloudPBX*)getMyPBXConfig;

- (BOOL)try2callPeer:(NSString*)number peerName:(NSString*)peerName numberType:(int)numberType;

- (void)navigate2SipTab;

- (BOOL)isInSIPCall;

- (BOOL)hasCallingoutCall;

- (BOOL)hasIncomingCall;

- (BOOL)isEnableSMS;

- (BOOL)isVipSLAEnable;

- (BOOL)enableCallUser;

- (BOOL)isTransfering;

- (BOOL)isWarmTransfering;

- (BOOL)isEnableCallTransfer;

- (NSInteger)getSipCallCount;

- (NSString*)getTransferCallID;

- (BOOL)isHideCallButtonInIM:(ZMBuddyAdapter *)useradapter;

- (BOOL)isCallButtonEnable:(ZMBuddyAdapter *)useradapter;

- (id <ZMSipContactItem>)getSipContactByID:(NSString *)cloudID;

- (void)selectedSessionWithToNumber:(NSString *)toNumber toName:(NSString *)toName;

- (void)transferCall:(NSString*)callID peerUri:(NSString*)peerUri warmTransfer:(int)transferType andNumberType:(int)type name:(NSString*)name jID:(NSString*)jID;

@end


#endif /* ZMSipCallProtocol_h */
