//
//  IZMMTWallpaperViewController.h
//  VideoUI
//
//  Created by Brace Liu on 2024/1/15.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#ifndef IZMMTWallpaperViewController_h
#define IZMMTWallpaperViewController_h

@protocol IZMMTWallpaperViewController <NSObject>

@property (nonatomic, weak) ZMConfSession *confSession;

- (void)startVideo;
- (void)stopVideo;

@end

#endif /* IZMMTWallpaperViewController */
