//
//  ZMBuddyGroupAdapter.h
//  Zoom
//
//  Created by Justin Fang on 4/13/14.
//  Copyright (c) 2013 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "zPTApp/SaasBeePTAppInterface.h"
#import "dataModule/zDataConstants.h"

@class ZMBuddyAdapter;
@interface ZMBuddyGroupAdapter : NSObject
{
    NSString*               m_gID;
    NSString*               m_gName;
    NSString*               m_xmppID;
    NSMutableArray*         m_buddies;
    BOOL                    m_canEdit;
    BOOL                    _isDirectoryGroup;
    BuddyGroupType          m_type;
}

@property (nonatomic, retain) NSString* m_gID;
@property (nonatomic, retain) NSString* m_gName;
@property (nonatomic, copy) NSString* assistantId; // actually it's  boss's Id
@property (nonatomic, copy) NSString* xmppID;
@property (nonatomic, retain) NSMutableArray*  m_buddies;
@property (nonatomic, retain) NSArray*  buddyJids;
@property (nonatomic, assign) BOOL m_canEdit;
@property (nonatomic, assign) BuddyGroupType m_type;
@property (nonatomic, assign) BuddyGroupMemberCountMode memberCountMode;
@property (nonatomic, assign) BOOL isDirectoryGroup;
@property (nonatomic, assign) NSInteger totalMembersCount;
@property (nonatomic, assign) NSInteger fuzzyMembersCount;
@property (readonly) BOOL isCustomGroup;

- (id)initWithBuddyGroup:(NS_ZOOM_MESSAGER::IZoomBuddyGroup*)buddyGroup;

- (NSString*)getGroupID;
- (NSString*)getGroupName;
- (NSUInteger)getBuddyCount;
- (ZMBuddyAdapter*)getBuddyAt:(NSUInteger)index;
- (NSArray*)getBuddies;
- (NSUInteger)getBuddyCountWithoutMyself;
- (NSArray*)getBuddiesWithoutMyself;
- (BOOL)isContainBuddy:(NSString *)jid;
@end
