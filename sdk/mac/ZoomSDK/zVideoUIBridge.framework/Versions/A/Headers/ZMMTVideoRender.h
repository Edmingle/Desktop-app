//
//  ZMMTVideoRender.h
//  zVideoUI
//
//  Created by Francis Zhuo on 1/5/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zVideoUIBridge/ZPConfUIConstants.h>
#import <zVideoApp/Confdef.h>
#import <cmmlib/CmmDef.h>
#import <zVideoUIBridge/zVideoUIBridge-Swift.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUser;
@class ZMMTVideoRender;
@class ZMMTRender;
@protocol ZMMTVideoRenderDelegate <NSObject>
@optional
- (void)videoRender:(ZMMTVideoRender*)render willSubscribe:(ZMUser *)theUser;
- (void)videoRender:(ZMMTVideoRender*)render didSubscribe:(ZMUser *)theUser;

- (BOOL)videoRender:(ZMMTVideoRender*)render enableCustomSizeWithHeight:(CGFloat)height;
- (uint8_t)videoRender:(ZMMTVideoRender*)render renderSizeWithHeight:(CGFloat)height;
@end

@interface ZMMTVideoRender : NSView
@property (readonly, strong) ZMUser* zmUser;
@property (nonatomic, assign) RENDER_CONTAINER_TYPE renderType;
@property (nonatomic, assign) BOOL videoIsShowing;
@property (nonatomic, assign) BOOL isUserMuted;
@property (nonatomic, assign) BOOL isPreviewing;
@property (nonatomic, assign) CMM_VIEWPORT_TYPE viewPortType;
@property (nonatomic, assign) SSB_MC_VIDEO_ASPECT_MODE aspectMode;//default is SSB_MC_VIDEO_ASPECT_LETTER_BOX
@property (nonatomic, assign) SSB_MC_VIDEO_SMART_PORTRAIT_MODE portraitMode;
@property (nonatomic, assign) ZMMTRenderBKType renderBKType;
@property (nullable, nonatomic, strong) ZMMTVideoMask* videoMask;

@property (nonatomic, retain) NSView* renderContainerView;

@property (nonatomic, assign) NSRectCorner cornerMask;
@property (nonatomic, assign) CGFloat cornerRadius;

@property (nonatomic, assign) BOOL isHovered;

//for metal
@property (nullable, nonatomic, retain) ZMMTRender *render;

@property (nonatomic, assign) id<ZMMTVideoRenderDelegate> delegate;

- (id)initWithFrame:(NSRect)frameRect renderType:(RENDER_CONTAINER_TYPE)type;
- (void)showPreview:(BOOL)bShow;
- (void)startVideoWithUser:(ZMUser*)user;
- (void)stopVideo;

- (void)lockVideo;
- (void)unlockVideo;

- (void)removeUser;
- (void)removeAndCleanUser;
- (void)destroyRender;
//- (void)onVideoSizeChanged:(NSRect)newRect;
- (void)forceUpdateRender:(ZMVideoUpdateStrategy)strategy NS_REQUIRES_SUPER;//ZOOM-82229

//- (void)updateRenderContainer:(BOOL)isForceUpdate;

- (void)resetForRecycleUse;//ZOOM-27757

- (NSRect)getRenderRect;

#pragma mark - override
- (void)updateAvatarView;
- (void)updateAvatarBKTransparent;
- (void)updateInfoView;
- (void)updatePoweredWaterMark;
- (void)updatePersonalWaterMark;
- (void)updatePersonalWaterMarkContentInsets;

@end

NS_ASSUME_NONNULL_END
