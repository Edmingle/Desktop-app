//
//  NSView+Toast.h
//  zChatComponent
//
//  Created by Zoro.Fu on 2022/9/29.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSView (Toast)

- (BOOL)dispatchToast:(ZMToast *)toast fromView:(NSView *_Nullable)view;

@end

@interface NSWindow (Toast)

- (BOOL)dispatchToast:(ZMToast *)toast fromView:(NSView *_Nullable)view;

@end

NS_ASSUME_NONNULL_END
