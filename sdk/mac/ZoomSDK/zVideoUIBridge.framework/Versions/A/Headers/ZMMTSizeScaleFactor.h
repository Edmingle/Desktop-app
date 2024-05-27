//
//  ZMMTSizeScaleFactor.h
//  VideoUI
//
//  Created by Francis Zhuo on 5/23/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, ZMMTSizeScaleFactorType){
    ZMMTSizeScaleFactorType_Percent,
    ZMMTSizeScaleFactorType_Absolute,
};

@interface ZMMTSizeScaleFactor : NSObject
@property(assign) ZMMTSizeScaleFactorType type;
@property(assign) CGFloat scaleValue;
@property(assign) CGFloat absoluteValue;
@end

NS_ASSUME_NONNULL_END
