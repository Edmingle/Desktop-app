//
//  IZMMTPlistMgr.h
//  VideoUI
//
//  Created by Francis Zhuo on 10/18/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTRosterList;
@protocol IZMMTPlistMgr <ZMRoutableObject>
- (void)onAllowPlistRenameStatusChanged;

- (void)userInterpretStatusChangedWithUser:(ZMUser *)theUser;

//need update Item UI
- (void)userVideoStatusChangedWithUser:(ZMUser*)zmUser;

//roster changed
- (void)onUserRosterChanged:(ZMMTRosterList*)roster session:(ZMConfSession*)session;

- (void)userLivePrivilegeStatusChangedWithUser:(ZMUser *)theUser;//ZOOM-426827
- (void)userInvitedToPBOStatuesChangedWithUser:(ZMUser *)zmUser;//ZOOM-484917
- (void)onAttendeeRosterChanged;

//Invite
- (BOOL)isSupportInvite;

- (void)attendeeGuestStatusChangedWithUser:(ZMUser *)theUser;
@end

NS_ASSUME_NONNULL_END
