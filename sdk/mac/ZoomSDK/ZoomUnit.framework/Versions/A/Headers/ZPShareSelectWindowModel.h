//
//  ZPShareSelectWindowModel.h
//  ZCommonUI
//
//  Created by sanshi on 3/26/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMShareSelectDef.h>
#import <ZoomUnit/ZMCaptureModel.h>

@interface ZPShareSelectThirdPartyInfo: NSObject

@property (nonatomic, assign) ZMShareSelectItemType docType;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *docURL;
@property (nonatomic, copy) NSString *appName;

@end

@interface ZPShareSelectWindowModel : ZMCaptureModel

@property(assign)ZMShareSelectItemType sharingType;
@property(copy)NSString* toolTip;
@property(copy)NSString* disabledInfo;
@property(copy)NSString* documentPath;
@property(assign)NSUInteger winCount;
@property(copy)NSString* axTitle;
@property(copy)NSString* nativeToolTip;
@property(retain)NSArray<NSNumber *> *winIDsForPS;
@property(retain)NSDictionary<NSNumber *, NSString *> *moreMenus;
@property(assign)BOOL disabled;
@property(copy)NSString* appId;
@property(assign)BOOL canCollaborate;
@property(retain) ZPShareSelectThirdPartyInfo *docInfo;

+ (id)modelWithCaptureModel:(ZMCaptureModel*)model;
- (id)initWithCaptureModel:(ZMCaptureModel*)model;
- (BOOL)isValid;
- (BOOL)isEqualToModel:(ZPShareSelectWindowModel *)model;
- (BOOL)isDesktopModel;
- (BOOL)isAsOrPsModel:(BOOL)containZapp;
- (BOOL)isAsModel;
- (BOOL)isZoomAppsCollaborationModel; //add for collaborateMode
- (BOOL)isPsModel;
- (BOOL)isAudioModel;
- (BOOL)isVideoModel;
- (BOOL)isDocModel;
- (BOOL)isWebWBModel;
- (BOOL)isFrameModel;
- (BOOL)isThirdPartyDoc;
- (BOOL)isZNotesModel;
- (BOOL)canEnableShareButton;
- (BOOL)supportAudioShare;
- (BOOL)supportVideoShare;
- (BOOL)supportBoShare;
+ (NSArray<ZPShareSelectWindowModel*>*)getScreensModelList;
+ (NSArray<ZPShareSelectWindowModel*>*)getWindowsModelList;
+ (NSArray<ZPShareSelectWindowModel*>*)getProcessModeList;
+ (ZPShareSelectWindowModel*)getEmptyScreenModel;
+ (ZPShareSelectWindowModel*)getIOSDevideModel;
+ (ZPShareSelectWindowModel*)getIOSWiredDeviceModel;
+ (ZPShareSelectWindowModel*)getModelWithFileStorageModel:(NSString *)name imageName:(NSString *)imageName shareType:(ZMShareSelectItemType)shareType;
+ (ZPShareSelectWindowModel*)getClassicWhiteboardModel;
+ (ZPShareSelectWindowModel*)getWebWhiteboardModel;
+ (ZPShareSelectWindowModel*)getCameraModel;
+ (ZPShareSelectWindowModel*)getFrameModel;
+ (ZPShareSelectWindowModel*)getSoundModel;
+ (ZPShareSelectWindowModel*)getDocModel;
+ (ZPShareSelectWindowModel*)getVideoModel;
+ (ZPShareSelectWindowModel*)getZoomNotesModel;
@end

@interface ZPAppShareSelectWindowModel : ZPShareSelectWindowModel

@property(retain)NSDictionary* zappShareParam;
@property(assign)BOOL isAppOpened;
@property(assign)BOOL isSidePanel;

@end
