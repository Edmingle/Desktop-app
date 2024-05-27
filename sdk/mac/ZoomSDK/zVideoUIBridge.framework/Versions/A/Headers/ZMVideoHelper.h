//
//  ZMVideoHelper.h
//  VideoUI
//
//  Created by javenlee.li on 2021/11/13.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUser;
@interface ZMVideoHelper : ZMBaseHelper

- (BOOL)isStartVideoDisabled;
- (void)setIsStartVideoDisable:(BOOL)disable;

- (BOOL)canIViewVideoForUserID:(ZMUserID)userID;
- (BOOL)canIViewVideoForUser:(ICmmUser*)cmmUser;

- (void)toggleVideoBlurMode;
- (BOOL)isCanBlur;
- (BOOL)isBlurVBMode;
- (BOOL)isForceVB;
- (void)turnOffAvatar;

- (BOOL)isSupportSmartVirtualBackground;
- (BOOL)vbSettingIsUseSmartVB;

- (BOOL)isVideoFeatureDisabled;
- (BOOL)isNoVideoToDisplay;

- (BOOL)isStoppedIncomingVideo;

- (BOOL)isProjectMode;

// If sign language interpreter is not allowed to talk,
// we can not see their video in the speaker && gallery && immersive && floating mode.
- (BOOL)canViewVideoOfSignLanguageInterpreter:(ICmmUser*)inCmmUser; //ZOOM-330475

// lipsync
- (BOOL)isLipsyncEnabled;//web & device support
- (void)startSendLipsync;
- (void)stopSendLipsync;
//- (void)refreshLipsync;
- (BOOL)isSupport3DAvatar;
- (BOOL)isLipsyncVirtualBackgroundOpened;
- (BOOL)isForceEnableVideoVirtualBkgnd;

- (nullable ZMUser*)getPinnedUser;

- (BOOL)mySelfIsVideoOn;
- (BOOL)isVideoOnWithUser:(ICmmUser*)inCmmUser;

- (BOOL)availableVideoCountWithFilter:(ZMMTVideoFilter)filter relationTo:(ZMMTRelation)relation count:(NSInteger)thanCount;
- (std::vector<ICmmUser*>)getAvailableVideoArrayWithFilter:(ZMMTVideoFilter)filter sortBy:(ZMMTVideoSortType)sortType;

- (BOOL)isAvailableVideo:(ICmmUser*)cmmUser mySelf:(ICmmUser*)mySelf withFilter:(ZMMTVideoFilter)filter;
- (BOOL)isAllAvailableVideoCountRelationTo:(ZMMTRelation)relation count:(NSInteger)thanCount;
- (BOOL)isAllAvailableVideoCountRelationTo:(ZMMTRelation)relation count:(NSInteger)thanCount filter:(ZMMTVideoFilter)filter;

- (BOOL)startPumpPureVideo:(ZMUserID)userID size:(NSInteger)size;
- (BOOL)stopPumpPureVideo:(ZMUserID)userID;

#pragma mark - sort video by
- (BOOL)isSortGalleryVideoEnable;
- (ZMMTVideoSortType)videoOrderSortType;
@end

ZMMTVideoSortType zmVideoSortType(USERLIST_SORT_TYPE type);
USERLIST_SORT_TYPE cmmVideoSortType(ZMMTVideoSortType type);

@interface ZMVideoHelper(WallView)
- (nullable NSArray<ZMUser*>*)getWallViewUserWithFilter:(ZMMTVideoFilter)filter sortBy:(ZMMTVideoSortType)sortType;
@end

NS_ASSUME_NONNULL_END
