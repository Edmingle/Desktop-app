//
//  ZMMTStudioConstants.h
//  VideoUIBridge
//
//  Created by Brace Liu on 2023/11/10.
//

#ifndef ZMMTStudioConstants_h
#define ZMMTStudioConstants_h

typedef NS_ENUM(NSUInteger, ZMMTStudioResourceTag) {
    ZMMTStudioResourceTag_Wallpaper = 99,
    ZMMTStudioResourceTag_Video,
    ZMMTStudioResourceTag_Avatar,
    ZMMTStudioResourceTag_Border_Left,
    ZMMTStudioResourceTag_Border_Right,
    ZMMTStudioResourceTag_Border_Top,
    ZMMTStudioResourceTag_Border_Bottom,
    ZMMTStudioResourceTag_NameBox,
    ZMMTStudioResourceTag_NameTag,
};

typedef NS_ENUM(NSUInteger, ZMMTStudioResourceRelativePosition) {
    ZMMTStudioResourceRelativePosition_BG = 0,
    ZMMTStudioResourceRelativePosition_FG,
    ZMMTStudioResourceRelativePosition_TOP
};

typedef NS_ENUM(NSUInteger, ZMMTStudioSceneContentType) {
    ZMMTStudioSceneContentType_None = 0,
    ZMMTStudioSceneContentType_Video,
    ZMMTStudioSceneContentType_Share,
    ZMMTStudioSceneContentType_Image,
};

#endif /* ZMMTStudioConstants_h */
