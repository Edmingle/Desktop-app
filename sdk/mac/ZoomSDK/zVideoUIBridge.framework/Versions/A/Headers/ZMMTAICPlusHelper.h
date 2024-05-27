//
//  ZMMTAICPlusHelper.h
//  VideoUIBridge
//
//  Created by Howie Xu on 1/14/24.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTAICPlusHelper : ZMBaseHelper

- (BOOL)isAICPlusStarted;

- (BOOL)needPromptDisclaimer;

- (void)agreeDisclaimer:(BOOL)didAgree;

@end

NS_ASSUME_NONNULL_END
