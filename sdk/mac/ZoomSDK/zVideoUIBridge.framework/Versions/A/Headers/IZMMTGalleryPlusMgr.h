//
//  IZMMTGalleryPlusMgr.h
//  VideoUI
//
//  Created by Brace Liu on 2024/1/9.
//  Copyright © 2024 zoom.us. All rights reserved.
//



#ifndef IZMMTGalleryPlusMgr_h
#define IZMMTGalleryPlusMgr_h

#import <zVideoUIBridge/IZMMTWallpaperViewController.h>
#import <zVideoUIBridge/ZMMTBaseViewController.h>

APPKIT_EXTERN const NSInteger cGalleryPlusTransparencyNone;
APPKIT_EXTERN const NSInteger cGalleryPlusTransparencyMid;
APPKIT_EXTERN const NSInteger cGalleryPlusTransparencyMax;

@protocol IZMMTGalleryPlusMgr <ZMRoutableObject>
@property(nonatomic, readonly, retain) NSImage * _Nullable wallpaperImage;
@property(nonatomic, readonly, assign) NSInteger transparency;

- (nullable ZMMTBaseViewController<IZMMTWallpaperViewController> *)newViewControllerWithType:(ZMMTType)type;

- (BOOL)isGalleryPlusWallpaperEnabled;
- (BOOL)isGalleryPlusTransparencyEnabled;
- (BOOL)canShowGalleryPlusWallpaper;

- (void)showSettingWindow;
- (void)closeSettingWindow;
- (BOOL)isSettingWindowShowing;
- (void)updateWallpaperDisplayStatus;

//sync wallpaper and video transparency
- (void)onGalleryPlusWallpaperChanged:(ZMUser *_Nullable)user wallpaperID:(NSString *_Nullable)wallpaperID;
- (void)onGalleryPlusTransparencyChanged:(ZMUser *_Nullable)user transparency:(NSInteger)transparency;

@end

#endif /* IZMMTGalleryPlusMgr_h */
