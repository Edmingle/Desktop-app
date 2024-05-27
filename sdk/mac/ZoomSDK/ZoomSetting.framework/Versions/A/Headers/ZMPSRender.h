//
//  ZMPSRender.h
//  ZoomClips
//
//  Created by Michael Lin on 2022/12/30.
//

#import <Foundation/Foundation.h>
#import <zPSApp/media/IPSRender.h>
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPSRender : ZMPSObject

@property (nonatomic, readonly, nullable) ps::IPSRender *ipsRender;
- (nullable instancetype)initWithView:(NSView *)view scene:(ZMPSScene)scene;
- (void)generateRenderIfNeeded;
- (void)setMirrorStrategy:(ps::PSMirrorStrategy)strategy;
- (void)startPreviewVideoWithExpectedFrameSize:(ps::PSFrameSize)frameSize immersive:(BOOL)immersive;
- (void)stopPreviewVideo;
- (void)setAspectMode:(SSB_MC_VIDEO_ASPECT_MODE)aspect;

@end

NS_ASSUME_NONNULL_END
