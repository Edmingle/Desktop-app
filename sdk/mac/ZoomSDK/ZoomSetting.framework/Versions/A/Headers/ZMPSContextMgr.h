//
//  ZMPSContextMgr.h
//  ZoomClips
//
//  Created by Michael Lin on 2023/1/11.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPSContextMgr : ZMPSObject

@property (nonatomic, assign) BOOL notRemindRecordWithoutMic;

@property (nonatomic, assign, getter = isEnableRecordImmersive) BOOL enableRecordImmersive;

- (nullable NSString *)userName;
- (nullable NSString *)accountID;
- (nullable NSString *)userID;
- (void)unregisterSink;
- (void)registerSink;
- (BOOL)is3DAvatarEnabled;

@end

NS_ASSUME_NONNULL_END
