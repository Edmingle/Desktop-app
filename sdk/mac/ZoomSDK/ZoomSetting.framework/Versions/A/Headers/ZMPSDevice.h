//
//  ZMPSDevice.h
//  ZoomClips
//
//  Created by Michael Lin on 2023/1/6.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPSDevice : ZMPSObject

@property (nonatomic, strong) NSString *deviceID;
@property (nonatomic, assign) BOOL isVideo;
@property (nonatomic, assign) BOOL isSameAsSystem;
@property (nonatomic, assign) BOOL isNone;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *alias;
- (BOOL)isNotNone;
- (BOOL)isNotSameAsSystem;

@end

NS_ASSUME_NONNULL_END
