//
//  NSApplication+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
APPKIT_EXTERN NSString *const NSAccessibilityVoiceOverStatusChanged;//!< Notification
APPKIT_EXTERN NSString *const kZMUserAppearanceKey;
APPKIT_EXTERN NSString *const kZMFontSizeChangedKey;
APPKIT_EXTERN NSString *const KZMAccessibilityVoiceOverStatusObserverKey;

typedef NS_ENUM(NSInteger, ZMUserAppearance){
    ZMUserAppearanceSystem,
    ZMUserAppearanceLight,
    ZMUserAppearanceDark,
};

struct ZMVoiceOverInfo {
    BOOL isVoiceOverInitialized;
    BOOL isVoiceOverEnabledInCache;
};
APPKIT_EXTERN struct ZMVoiceOverInfo globalZMVoiceOverInfo;

@interface NSApplication (ZoomKit)
@property (nonatomic, readonly, assign) BOOL isDebuggerAttached;

@property (assign) BOOL canTerminateNow;
@property (assign) BOOL isSupportDarkMode;

@property (readonly, assign) BOOL isSupportUserAppearance;
@property (assign) ZMUserAppearance userAppearance;

@property (readonly, getter=isVoiceOverRunning) BOOL voiceOverRunning;//!< for tab control, use 'fullKeyboardAccessEnabled'

@property (nonatomic, assign) BOOL retinaBundleNotReady;
@property (readonly) BOOL isDarkMode;
@property (assign) NSInteger fontSizeRate;
@property (assign) NSInteger lastFontSizeRate;

/**
 * check if screen recording in Security&Privacy is turn on
 **/
+ (BOOL)isScreenRecordingOn;

- (BOOL)inTyping;
/**
 mac os 13 & stage Manager mode
 */
+ (BOOL)isStageManagerMode;

- (BOOL)isRunAsHuddle;
@end
NS_ASSUME_NONNULL_END
