//
//  ZMToastPanel.h
//  zChatUI
//
//  Created by Huxley on 2019/2/22.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <ZoomKit/ZMPlainWindow.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMToast, ZMToastCoordinator;
@interface ZMToastPanel : ZMPlainPanel

+ (instancetype)toastPanelWithToast:(ZMToast *)toast coordinator:(ZMToastCoordinator *)coordinator;

@property (retain, readonly) ZMToast *toast;
@property (weak, readonly) ZMToastCoordinator *coordinator;

- (void)updateToast;

- (void)appear;
- (void)disappear;

@end

NS_ASSUME_NONNULL_END
