//
//  ZMPSAsyncRecording.h
//  ZoomClips
//
//  Created by Michael Lin on 2023/1/5.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMPSDefine.h>
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMPSRootCanvas, ZMPSCanvas, ZMPSRender, ZMClipsSharingSendingParam;
@interface ZMPSAsyncRecording : ZMPSObject

@property (nonatomic, assign, readonly) NSUInteger recordingID;

- (void)configWithSize:(NSSize)size title:(nullable NSString *)title layoutInfoStr:(nullable NSString *)layoutInfoStr;
- (nullable ZMPSRootCanvas *)rootCanvas;
- (void)startNote;
- (void)stopNote;
- (void)cancelNote;
- (void)pauseNote;
- (void)resumeNote;
- (void)startPreviewWithRender:(ZMPSRender *)render;
- (void)startPreviewBeforeStopWithRender:(ZMPSRender *)render;
- (void)stopPreviewWithRender:(ZMPSRender *)render;
- (void)stopPreview;
- (BOOL)isPreviewingWithRender:(ZMPSRender *)render;
- (BOOL)isPreviewing;

- (nullable NSString *)webRecordingID;

- (void)bindSoundWithDefaultMic;
- (void)unbindSoundWithMic;
- (BOOL)isSoundWithMicBound;
- (void)muteSoundWithMic;
- (void)unmuteSoundWithMic;
- (BOOL)isSoundWithMicMuted;

- (void)bindVideoWithDefaultDeviceWithCanvas:(ZMPSCanvas *)canvas immersive:(BOOL)immersive expectedFrameSize:(ps::PSFrameSize)frameSize;
- (void)unbindVideoWithDefaultDeviceWithCanvas:(ZMPSCanvas *)canvas;
- (BOOL)isVideoWithDeviceBound:(ZMPSCanvas *)canvas;

- (void)bindShareWithDefaultCaptureWithCanvas:(ZMPSCanvas *)canvas captureParam:(const ps::PSCaptureParam&)captureParam;
- (void)unbindShareWithDefaultCaptureWithCanvas:(ZMPSCanvas *)canvas;

- (void)retryUpload;
- (void)cancelUpload;

- (void)setLayoutInfo:(NSString *)info;

@end

NS_ASSUME_NONNULL_END
