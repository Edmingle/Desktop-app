//
//  ZMMessageSessionAdapter.h
//  Zoom
//
//  Created by Deal Shao on 9/25/13.
//  Copyright (c) 2013 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "zPTApp/SaasBeePTAppInterface.h"
#import "dataModule/zDataConstants.h"
#import "zoom_client_conf.h"

@class ZMBuddyAdapter;
@class ZMSessionGroupAdapter;
@class ZMMessageAdapter;
@class ZMIMMessageDraft;

@interface ZMMessageSessionAdapter : NSObject {
    NSString*                     m_sID;
    MsgSessionType                m_sType;
}

@property (nonatomic, retain) NSString*                     m_sID;
@property (nonatomic, assign) MsgSessionType                m_sType;

- (id)initWithMessageSession:(NS_ZOOM_MESSAGER::IZoomChatSession*)msgSession;

- (NSString*)getSessionID;
- (BOOL)isGroup;
- (BOOL)isForceE2EGroup;
- (BOOL)isRoom;
- (ZMBuddyAdapter*)getSessionBuddy;
- (ZMSessionGroupAdapter*)getSessionGroup;
- (ZMMessageAdapter*)getLastMessage;
- (NSUInteger)getUnreadMessageCount;
- (NSUInteger)getUnreadMessageCountBySetting;
- (NSUInteger)getUnreadAtMeMessageCount;
- (NSUInteger)membersCount;
- (BOOL)deleteMessage:(NSString*)messageID; //if messageID is nil, delete all message in this session

- (BOOL)hasUnreadMessageAtMe;
- (BOOL)hasUnreadMessageAtAll;
- (BOOL)hasUnreadMentionGroupMessageAtMe;
- (NSString*)getSessionTitle;
/*
 If cleanTotal is NO, The unread count of the Main session and all sub sessions is cleared
 If cleanTotal is YES, the total unread counts of the main session will be cleared and the user will not see the unread counts of the left sidebar. However, the sub-session unread count is not cleared
 **/
- (void)cleanUnreadMessageCount:(BOOL)cleanTotal;

//mark unread ZOOM-14489
- (NSUInteger)getMarkedUnreadMsgCount;
- (BOOL)clearAllMarkedUnreadMessage;

- (NSInteger)allUnreadCount;

//ZOOM-95511
- (ZMMessageAdapter*)getLastMessageForMarkAsUnread;

//ZOOM-130676
- (NSDate *)getSessionLastSearchOpenTime;
- (void)storeSessionLastSearchOpenTime:(NSTimeInterval)time;

- (BOOL)isMuted;
- (NSInteger)getAtMeMessageCount;

- (NSTimeInterval)getSessionLastMessageTime;

@end
