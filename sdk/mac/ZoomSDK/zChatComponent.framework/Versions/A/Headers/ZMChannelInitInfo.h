//
//  ZMChannelInitInfo.h
//  ChatUI
//
//  Created by Zoro.Fu on 2023/3/16.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMChannelInitInfo : NSObject

@property (nonatomic, copy) NSString *channelName;
@property (nonatomic, copy) NSString *channelDes;
@property (nonatomic, copy) NSArray<NSString *> *memberJids;
@property (nonatomic, copy) NSArray<NSString *> *memberEmails;
@property (nonatomic, copy) NSArray<NSString *> *groupIds;
@property (nonatomic, copy) NSArray<NSString *> *announcers;
@property (nonatomic, assign) NSInteger channelType;
@property (nonatomic, copy) NSString *classificationId;
@property (nonatomic, assign) BOOL isInternalMemberCanAddApps;
@property (nullable, nonatomic, strong) NSString* sharedSpaceID;

- (BOOL)isAvailableName;

- (BOOL)isAvailableMembers;

@end

NS_ASSUME_NONNULL_END
