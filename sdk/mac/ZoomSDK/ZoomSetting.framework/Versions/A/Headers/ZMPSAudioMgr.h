//
//  ZMPSAudioMgr.h
//  ZoomClips
//
//  Created by Michael Lin on 2022/12/30.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMPSDevice;
@interface ZMPSAudioMgr : ZMPSObject

@property (nonatomic, weak) ZMPSDevice *microphoneDevice;
- (NSArray<ZMPSDevice *> *)microphoneDevices;
- (BOOL)isDefaultMicDeviceNotExisted;
- (void)micDeviceAddedWithDeviceID:(nullable NSString *)deviceID;
- (void)micDeviceRemovedWithDeviceID:(nullable NSString *)deviceID;
- (void)unregisterSink;
- (void)registerSink;
- (BOOL)isConfigReady;
- (void)initNoiseSuppress;
- (BOOL)isNoiseSuppressEnabled;
- (void)enableNoiseSuppress:(BOOL)enable;
- (BOOL)isStereoMicRecordingEnabled;
- (void)setStereoMicRecording:(BOOL)enable;
- (void)startMicForIdle;
- (void)stopMicForIdle;

@end

NS_ASSUME_NONNULL_END
