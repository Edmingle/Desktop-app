//
//  ZMRouterCenter.h
//  ZCommonUI
//
//  Created by Francis Zhuo on 4/3/21.
//  Copyright © 2021 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomKit/ZMRouterCenterProtocols.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMRouterCenter : NSObject <ZMRouterCenter>
+ (instancetype)shared;
@end

NS_ASSUME_NONNULL_END

