//
//  ZMUserModule.h
//  zChatUI
//
//  Created by groot.ding on 2018/4/25.
//  Copyright © 2018年 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "zPTApp/SaasBeePTAppInterface.h"
#import <zChatComponent/ZMBuddyProtocal.h>
#import <ZoomUnit/ZMLoginProtocol.h>

@interface ZMUserModule : NSObject <ZMBuddyProtocol,ZMLoginProtocol>

+ (instancetype)shareInstance;

@end
