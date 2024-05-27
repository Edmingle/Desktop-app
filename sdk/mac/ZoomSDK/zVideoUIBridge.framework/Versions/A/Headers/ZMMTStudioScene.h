//
//  ZMMTStudioScene.h
//  VideoUI
//
//  Created by geno.chen on 2022/8/9.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMMTStudioConstants.h>
#import <zVideoUIBridge/ZMMTStudioSceneResourceModel.h>
@class ZMUser;

NS_ASSUME_NONNULL_BEGIN


#define kStudioActiveSpeakerIdentifier @"active_speaker"
#define kStudioNotAssignedIdentifier @"not_assigned"

@interface ZMMTStudioSceneContent : NSObject

@property(nonatomic, assign) NSRect frame;
@property(nonatomic, strong, nullable, readonly) ZMUser *user;
@property(nonatomic, assign) NSInteger borderWidth;
@property(nonatomic, strong) NSColor *borderColor;
@property(nonatomic, assign) ZMMTStudioSceneContentType type;
@property(nonatomic, copy) NSString *userEmail;
@property(nonatomic, assign) NSSize videoRatio;
@property(nonatomic, assign) BOOL isBigVideo;
@property(nonatomic, copy) NSString *resourcePath;

@end


@interface ZMMTStudioScene : NSObject

@property (nonatomic, copy) NSString *sceneID;
@property (nonatomic, copy) NSString *name;

@property (nonatomic, assign) NSInteger layoutType;
@property (nonatomic, copy) NSString *wallpaperPath;

@property (nonatomic, assign) NSInteger safeArea;

@property (nonatomic, assign) NSInteger borderWidth;
@property (nonatomic, strong) NSColor *borderColor;

@property (nonatomic, assign) NSInteger videoSpacing;
@property (nonatomic, assign) NSSize videoRatio;

@property (nonatomic, strong) NSArray *videoUserEmails;
@property (nonatomic, strong) NSArray *shareUserEmails;
@property (nonatomic, strong) NSArray *resources;


@property (nonatomic, strong, readonly) NSImage *wallpaper;
@property (nonatomic, strong, readonly) NSArray <ZMMTStudioSceneContent *> *contents;
@property (nonatomic, assign, readonly) NSSize size;

@property(nonatomic, assign, getter=isLiving) BOOL living;
@property(nonatomic, assign, getter=isEnable) BOOL enable;
@property(nonatomic, assign, getter=isChanged) BOOL changed;

#ifdef __cplusplus
class CmmPSLScene;
//@property (nonatomic, assign) CmmPSScene psScene;
- (instancetype)initWithPSScene:(CmmPSLScene)scene;

+ (ZMUser *_Nullable)getStudioUserFromEmail:(NSString *)email;
+ (ZMUser *_Nullable)getStudioUserFromEmail:(NSString *)email containInSub:(BOOL)isContainInSub;

- (ZMMTStudioSceneContent *_Nullable)getContentByEmail:(NSString *)email contentType:(ZMMTStudioSceneContentType)type;


#endif

@end


@interface ZMMTStudioScene (Helper)

- (BOOL)hasSpeaker;

- (NSUInteger)availableSpeakers;

- (NSUInteger)totalSpeakers;

- (BOOL)isContainShare;
- (BOOL)isSharingContent;
- (BOOL)isContainImage;
- (nullable ZMUser*)sharingContentUser;
- (BOOL)isContainUser:(ZMUserID)userID;
- (BOOL)isContainActiveSpeaker;
- (BOOL)isBigVideoForUserIndex:(NSInteger)userIndex layoutID:(NSInteger)layoutID;
- (BOOL)containsUserWithEmail:(NSString *)email;
- (NSUInteger)bigVideoCount;

- (NSInteger)commonSizeForVideoCount:(NSInteger)videoCount
                        containShare:(BOOL)isContainShare
                       bigVideoCount:(NSInteger)bigVideoCount;
@end

NS_ASSUME_NONNULL_END
