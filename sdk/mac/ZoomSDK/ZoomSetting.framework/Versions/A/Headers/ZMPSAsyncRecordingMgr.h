//
//  ZMPSAsyncRecordingMgr.h
//  ZoomClips
//
//  Created by Michael Lin on 2023/5/6.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPSAsyncRecordingMgr : ZMPSObject

- (NSUInteger)generateAsyncRecording;
- (void)destoryAsyncRecordingWithID:(NSUInteger)recordingID;
- (void)registerSink;
- (void)unregisterSink;
- (void)retryUploadAsyncRecordingWithID:(NSUInteger)recordingID;
- (void)cancelUploadAsyncRecordingWithID:(NSUInteger)recordingID;
- (void)openDefaultVBSetting;
- (void)openPTLibrary;
- (void)setClipsIsRunning:(BOOL)isRunning;
- (BOOL)needCheckAsyncRecordingLimitation;
- (void)queryAsyncRecordingLimitation;

- (void)sendCustomMessageToPT:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
