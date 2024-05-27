//
//  ZMPSAppMgr.h
//  ZoomClips
//
//  Created by Michael Lin on 2022/12/30.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMPSCanvasMgr, ZMPSContextMgr, ZMPSMediaClient, ZMPSAvatarMgr;
@class ZMPSVirtualBackgroundMgr, ZMPSVideoMgr, ZMPSAudioMgr;
@class ZMPSWallpaperMgr, ZMPSShareMgr, ZMPSRenderMgr;
@class ZMPSWebAgentAPIMgr, ZMPSAsyncRecordingMgr, ZMPSAnnotationMgr;
@interface ZMPSAppMgr : ZMPSObject

- (void)setupPSApp;
- (void)uninitPSApp;

@property (nonatomic, strong) ZMPSCanvasMgr *canvasMgr;
@property (nonatomic, strong) ZMPSRenderMgr *renderMgr;
@property (nonatomic, strong) ZMPSContextMgr *contextMgr;
@property (nonatomic, strong) ZMPSMediaClient *mediaClient;
@property (nonatomic, strong) ZMPSAvatarMgr *avatarMgr;
@property (nonatomic, strong) ZMPSVirtualBackgroundMgr *virtualBackgroundMgr;
@property (nonatomic, strong) ZMPSVideoMgr *videoMgr;
@property (nonatomic, strong) ZMPSAudioMgr *audioMgr;
@property (nonatomic, strong) ZMPSShareMgr *shareMgr;
@property (nonatomic, strong) ZMPSWebAgentAPIMgr *webAgentAPIMgr;
@property (nonatomic, strong) ZMPSWallpaperMgr *wallpaperMgr;
@property (nonatomic, strong) ZMPSAsyncRecordingMgr *asyncRecordingMgr;
@property (nonatomic, strong) ZMPSAnnotationMgr *annotationMgr;

@end

NS_ASSUME_NONNULL_END
