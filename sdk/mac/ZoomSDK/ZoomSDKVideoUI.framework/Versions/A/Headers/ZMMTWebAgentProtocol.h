//
//  ZMMTWebAgentProtocol.h
//  VideoUI
//
//  Created by walt.li on 7/18/23.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#ifndef _ZMMTWebAgentProtocol_H_
#define _ZMMTWebAgentProtocol_H_

@protocol ZMMTWebAgentProtocol <NSObject>

@optional
- (void)onWallpaperDownloaded:(NSString *)wallpaperId success:(BOOL)success;
- (void)onWallpaperThumbnailDownloaded:(NSString *)wallpaperId success:(BOOL)success;

- (void)onGalleryPlusWallpaperDownloaded:(NSString *)wallpaperId success:(BOOL)success;
- (void)onGalleryPlusThumbnailDownloaded:(NSString *)wallpaperId success:(BOOL)success;

@end

#endif /* ZMMTWebAgentProtocol */
