//
//  ZMPSCanvas.h
//  ZoomClips
//
//  Created by Michael Lin on 2023/1/4.
//

#import <Foundation/Foundation.h>
#import "zPSApp/media/IPSCanvas.h"
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMPSCanvas, ZMPSRender;
@interface ZMPSCanvas : ZMPSObject

@property (nonatomic, readonly, weak) ZMPSCanvas *parentCanvas;
@property (nonatomic, readonly, nullable) ps::IPSCanvas *ipsCanvas;
@property (nonatomic, assign) NSRect frame;
- (nullable instancetype)initWithCanvas:(ps::IPSCanvas *)canvas parentCanvas:(nullable ZMPSCanvas *)parentCanvas scene:(ZMPSScene)scene;
- (nullable ps::IPSCanvas *)fetchSubCanvasWithHandle:(SSB_MC_CANVAS_HANDLE)handle;
- (nullable ZMPSCanvas *)generateShareSubCanvasWithFrame:(NSRect)frame;
- (nullable ZMPSCanvas *)generateVideoSubCanvasWithFrame:(NSRect)frame;
- (void)setAspectMode:(SSB_MC_VIDEO_ASPECT_MODE)mode;
- (SSB_MC_VIDEO_ASPECT_MODE)aspectMode;
- (void)addPic:(nullable NSImage *)pic;
- (void)removePic;
- (void)bringToTop;
- (void)bringToBottom;
- (void)bringToUpper;
- (void)bringToLower;

@end

@interface ZMPSRootCanvas : ZMPSCanvas

- (nullable instancetype)initWithCanvas:(ps::IPSCanvas *)canvas scene:(ZMPSScene)scene;
- (void)run;
- (void)stop;
- (void)redraw;
- (void)publish;
- (void)stopPublish;

@end

NS_ASSUME_NONNULL_END
