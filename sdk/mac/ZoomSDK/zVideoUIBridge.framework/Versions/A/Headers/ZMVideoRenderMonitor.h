//
//  ZMVideoRenderMonitor.h
//  zVideoUI
//
//  Created by Francis Zhuo on 10/10/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMVideoRenderMonitor : NSObject
+ (instancetype)shared;
+ (void)initVideoRenderMonitor;
+ (void)uninitVideoRenderMonitor;

- (void)cleanUp;
- (void)onConfReady;

- (void)failSubscribeForUser:(ZMUserID)userID;
@end

NS_ASSUME_NONNULL_END
