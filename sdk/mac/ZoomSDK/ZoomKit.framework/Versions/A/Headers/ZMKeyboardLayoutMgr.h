//
//  ZMKeyboardLayoutMgr.h
//  ZCommonUI
//
//  Created by francis zhuo on 11/11/2019.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
APPKIT_EXTERN NSString* const kZMUSKeyBoardLayoutID;

APPKIT_EXTERN NSNotificationName const ZMKeyBoardLayoutWillChanged;
APPKIT_EXTERN NSNotificationName const ZMKeyBoardLayoutDidChanged;

@interface ZMKeyboardLayoutMgr : NSObject
@property(readonly, retain) NSString* currentKeyboardLayoutID;
@property(class, readonly, retain) id sharedMgr;

+ (NSDictionary*)KeyboardLayoutWithID:(NSString*)layoutID;//return <letter:keycode> dictionary
+ (CGKeyCode)keyCodeForLetter:(NSString*)letter alternateKeyCode:(CGKeyCode)alternateKeyCode layoutID:(NSString*)layoutID;
+ (NSString*)letterForKeyCode:(CGKeyCode)keyCode layoutID:(NSString*)layoutID;
+ (NSString*)getCurrentKeyboardID;
@end

NS_ASSUME_NONNULL_END
