//
//  ZMBOHelper.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 10/9/22.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMBOHelper : ZMBaseHelper
- (BOOL)isBOEnable;//old BO feature
- (BOOL)isInBOSession;//old BO session

- (BOOL)isBOHost;
- (BOOL)isBOModerator;
- (BOOL)isNewBOEnabled;
- (BOOL)isInNewBOSession;
- (BOOL)needToBeBuilt;
- (BOOL)canEditWhileStart;
- (BOOL)canControlBO;
- (BOOL)isInBOStatus:(zm::new_bo::bo_user_status)status;
- (BOOL)isBOListReady;
- (zm::new_bo::bo_status)getBOStatus;
- (BOOL)getUserWhoStartBO:(CmmUInt32&)unique_join_index isMySelf:(CmmBool&)isMySelf;
- (BOOL)getUserWhoStopBO:(CmmUInt32&)unique_join_index isMySelf:(CmmBool&)isMySelf ;
- (std::vector<std::shared_ptr<zm::new_bo::IBORoom>>)getBORooms;
- (std::shared_ptr<zm::new_bo::IBORoom>)getBORoomWithID:(NSInteger)roomID;
- (NSInteger)getMaxRoomLimits;
- (NSInteger)getMaxRoomUserLimits;
- (BOOL)getBORemainTimerTime:(NSInteger&)seconds;
- (BOOL)getBORemainStopTime:(NSInteger &)seconds;
- (std::shared_ptr<zm::new_bo::IBuild>)getBuilder;
- (zm::new_bo::Configs)getConfig;
- (std::shared_ptr<zm::new_bo::IDraftConfig>)getDraftConfig;
- (NSString*)getRoomName;
- (NSString*)getRoomName:(std::shared_ptr<zm::new_bo::IBORoom>)room;
- (NSString*)getRoomNameWithID:(NSInteger)roomID;
- (nullable ICmmUser *)getUserByUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;
- (nullable IZoomQABuddy *)getBuddyByUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;
- (std::shared_ptr<zm::new_bo::IParticipant>)getParticipantByUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;
- (NSInteger)getRoomCount;

- (BOOL)canLeaveBOFreely;

- (BOOL)isEnableTimer;

- (BOOL)isInNewBOWithUser:(ZMUser*)zmUser;
- (BOOL)isInNewBOWithBuddy:(IZoomQABuddy *)buddy;
- (BOOL)isInNewBO:(ICmmUser*)cmmUser;

- (BOOL)isCmmUserInMainSession:(ICmmUser*)cmmUser;
- (nullable ZMUser*)getDefaultUserForUser:(ZMUser*)zmUser;

- (BOOL)isUserInMainSession:(ZMUserID)uniqueJoinIndex;
- (BOOL)isUserBelongToRoom:(ZMUserID)uniqueJoinIndex;
- (BOOL)isUserUnassigned:(ZMUserID)uniqueJoinIndex;
- (BOOL)isUserExist:(ZMUserID)uniqueJoinIndex;
- (BOOL)canBroadcastMessage;

- (BOOL)needAttendeeConfirmJoinWebinarBO;
- (void)agreeWebinarBODisclaimer:(BOOL)agree;

- (void)markUITip:(int)uiTip;
- (BOOL)isUITipMarked:(int)uiTip;

// capacity
- (NSInteger)getMaxParticipantLimits;
- (BOOL)isReachParticipantLimits;

#pragma mark - SpotsBO
#ifdef ENABLE_ZAPP
- (NSString*)getSpotsBORoomName:(std::shared_ptr<zm::spots::IBubble>)room;
- (nullable ICmmUser *)getSpotsUserByUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;
- (BOOL)isSpotsEnabled;
- (BOOL)isInSpotsBOSession;
- (NSString*)getSpotsBORoomName;
- (BOOL)isInSpotsBOWithUser:(ZMUser*)zmUser;
#endif
@end

NS_ASSUME_NONNULL_END
