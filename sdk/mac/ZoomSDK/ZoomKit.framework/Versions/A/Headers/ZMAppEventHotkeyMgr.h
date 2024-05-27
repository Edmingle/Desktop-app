//
//  ZMHotkeyEventMonitor.h
//  ZCommonUI
//
//  Created by francis zhuo on 2019/3/11.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
extern const NSEventModifierFlags effectiveModifierFlags;

@protocol ZMAppEventHandlerDelegate;
@interface ZMAppEventHotkeyMgr : NSObject
+ (id)sharedMgr;
- (void)addAppEventHandler:(id<ZMAppEventHandlerDelegate>)handler;
- (void)removeEventHandler:(id<ZMAppEventHandlerDelegate>)handler;
- (OSStatus)registerAppEventHotkey:(UInt32)hotkeyCode
                         mofifiers:(NSEventModifierFlags)hotkeyModifiers
                         hotkeyRef:(id*)outRef;
- (void)unregisterAppEventHotKey:(id)hotkeyRef;
@end

@protocol ZMAppEventHandlerDelegate<NSObject>
@required
- (OSStatus)appEventActionWithHotkeyMgr:(ZMAppEventHotkeyMgr*)manager event:(NSEvent*)event hotkeyRef:(id)hotkeyRef;
@end
