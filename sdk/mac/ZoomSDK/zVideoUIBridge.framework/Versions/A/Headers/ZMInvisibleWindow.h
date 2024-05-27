//
//  ZMInvisibleWindow.h
//  SaasBeeConfUIModule
//
//  Created by John on 1/27/15.
//  Copyright (c) 2015 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMInvisibleWindow : NSPanel
- (void)invisibleInSharing;
@end

@interface ZMIgnordAccessibilityInvisibleWindow : ZMInvisibleWindow
@end

@interface ZMInvisibleWindowNoPanel : NSWindow
- (void)invisibleInSharing;
@end

