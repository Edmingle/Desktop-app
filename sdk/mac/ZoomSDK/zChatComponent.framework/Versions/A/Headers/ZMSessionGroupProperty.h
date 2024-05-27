//
//  ZMSessionGroupProperty.h
//  ZoomMsgUI
//
//  Created by Groot Ding on 2022/5/18.
//

#import <Foundation/Foundation.h>
#import <zPTApp/SaasBeePTAppInterface.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSessionGroupProperty : NSObject

@property (nonatomic,assign) BOOL isPublic;
@property (nonatomic,assign) BOOL isRestrictSameOrg;
@property (nonatomic,assign) BOOL isSpotChannel;
@property (nonatomic,assign) BOOL isNewMemberCanSeeMessageHistory;
@property (nonatomic,assign) BOOL isMuc;
@property (nonatomic,assign) BOOL isExternalUsersCanAddExternalUsers;

// ZOOM-387575
@property (nonatomic,assign) BOOL isOnlyAdminCanAddMembers;
@property (nonatomic,assign) BOOL isOnlyAdminCanAddExternalUsers;
@property (nonatomic,assign) ns_zoom_messager::GroupAnnouncerType announcerType;

@property (nonatomic,assign) ns_zoom_messager::AtAllOption atAllOptionType;

// ZOOM-466312
@property (nonatomic, assign) BOOL isInternalMemberCanAddApps;

@property (nonatomic,copy) NSString *name;
@property (nonatomic,copy) NSString *desc;
@property (nonatomic,retain) NSArray *announcers;

@property (nonatomic,copy) NSString *classificationID;

@property (nonatomic,copy) NSString *backgroundInfo;

@property (nonatomic,assign) BOOL isEveryOneCanReply;

@property (nonatomic,assign) BOOL isChannelHuddleDisabled;

- (void)updateWithGroup:(NS_ZOOM_MESSAGER::IZoomGroup*)buddyGroup;
- (void)updateAnnouncerWithGroup:(NS_ZOOM_MESSAGER::IZoomGroup*)buddyGroup;
- (void)updateAtAllOptionWithGroup:(NS_ZOOM_MESSAGER::IZoomGroup*)buddyGroup;
@end

NS_ASSUME_NONNULL_END
