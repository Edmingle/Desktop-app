//
//  ZMPSMediaClient+CPP.h
//  ZoomSetting
//
//  Created by Michael Lin on 2024/1/11.
//

#import <Foundation/Foundation.h>
#import <zPSApp/define/PSDefine.h>
#import <ZoomSetting/ZMPSMediaClient.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPSMediaClient (CPP)

- (CmmUInt32)supportResolutions;
- (ps::PSFrameResolution)getRecommendedRecordResolution;

@end

NS_ASSUME_NONNULL_END
