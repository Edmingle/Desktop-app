//
//  ZMHMenuItem.h
//  zChatUI
//
//  Created by Huxley Yang on 2018/1/24.
//  Copyright © 2018年 Zipow. All rights reserved.
//

#import <ZoomKit/ZMBaseMenuItem.h>

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const ZMTutorial_MenuItemDidAppear;

@interface ZMHMenuItem : ZMBaseMenuItem
/// For tutorials. If YES, sends the 'ZMTutorial_JoinChannel_SidebarDropdownMenuDidAppear' notification
/// when this menuitem's view appears in the view hierarchy.
@property (nonatomic, assign) BOOL notifyOnAppear;

- (void)updateImage:(NSImage *)image;

@end

NS_ASSUME_NONNULL_END

