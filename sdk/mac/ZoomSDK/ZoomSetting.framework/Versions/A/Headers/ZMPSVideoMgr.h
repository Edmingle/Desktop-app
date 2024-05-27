//
//  ZMPSVideoMgr.h
//  ZoomClips
//
//  Created by Michael Lin on 2022/12/30.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMPSDevice;

@interface ZMPSVideoMgr : ZMPSObject

@property (nonatomic, weak) ZMPSDevice *defaultDevice;
- (NSArray<ZMPSDevice *> *)devices;
- (BOOL)isDefaultDeviceNotExisted;
- (void)deviceAddedWithDeviceID:(nullable NSString *)deviceID;
- (void)deviceRemovedWithDeviceID:(nullable NSString *)deviceID;
- (void)unregisterSink;
- (void)registerSink;
- (BOOL)isConfigReady;
- (void)enableMirrorMyVideo:(BOOL)enable;
- (BOOL)isMirrorMyVideoEnabled;
- (void)enableFaceBeauty:(BOOL)enable;
- (BOOL)isFaceBeautyEnabled;
- (void)setFaceBeautyStrengthValue:(NSInteger)value;
- (NSInteger)getFaceBeautyStrengthValue;
- (void)enableLightAdaption:(BOOL)enable;
- (BOOL)isLightAdaptionEnabled;
- (void)enableAutoLightAdaption:(BOOL)enable;
- (BOOL)isAutoLightAdaptionEnabled;
- (void)setLightAdaptionManualValue:(NSInteger)value;
- (NSInteger)getLightAdaptionManualValue;

@end

NS_ASSUME_NONNULL_END
