//
//  ZMSettingConstants.h
//  ZoomSetting
//
//  Created by Francis Zhuo on 2024/3/25.
//

#import <Foundation/Foundation.h>

#ifndef ZMSettingConstants_h
#define ZMSettingConstants_h

//setting identifier
extern NSString * const kZMSettingItemIdentifierGeneral;
extern NSString * const kZMSettingItemIdentifierAudio;
extern NSString * const kZMSettingItemIdentifierVideo;
extern NSString * const kZMSettingItemIdentifierVirtual;
extern NSString * const kZMSettingItemIdentifierRecord;
extern NSString * const kZMSettingItemIdentifierAccount;
extern NSString * const kZMSettingItemIdentifierStatics;
extern NSString * const kZMSettingItemIdentifierFeedback;
extern NSString * const kZMSettingItemIdentifierPhone;
extern NSString * const kZMSettingItemIdentifierAccessibility;
extern NSString * const kZMSettingItemIdentifierNotification;
extern NSString * const kZMSettingItemIdentifierShortcuts;
extern NSString * const kZMSettingItemIdentifierShare;
extern NSString * const kZMSettingItemIdentifierAutoDnd; // ZOOM-285618
extern NSString * const kZMSettingItemIdentifierPrivacy; // ZOOM-257741
extern NSString * const kZMSettingItemIdentifierHuddles; // ZOOM-571440

//setting anchor key
extern NSString *const kZMSettingAnchorKey;
typedef NSString* ZMAnchorKey;
extern ZMAnchorKey const kZMSettingAnchorGeneralAppearance;
#endif
