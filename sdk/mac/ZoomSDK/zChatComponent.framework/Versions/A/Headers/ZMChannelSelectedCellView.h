//
//  ZMChannelSelectedCellView.h
//  zChatUI
//
//  Created by groot.ding on 2018/5/16.
//  Copyright © 2018年 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class ZMPublicRoomInfo;

@interface ZMChannelSelectedCellView : ZMBaseTableCellView

@property (nonatomic,copy) void (^joinAction)(ZMPublicRoomInfo *info);

@property (nonatomic,copy) void (^previewAction)(ZMPublicRoomInfo *info);

@property (nonatomic,retain) NSLayoutConstraint *nameLeadingConstraint;

@property (nonatomic, copy) NSString *searchKey;

@end
