//
//  IZMMEventTrackerProtocol.h
//  VideoUIBridge
//
//  Created by Lenard Zhou on 2022/12/26.
//

#import <Foundation/Foundation.h>
#import <ZoomPaapDef.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMEventTrackerProtocol <ZMRoutableObject>

- (ZoomPAAP::PAAPMeetingSettingInteract)getMeetingSettings;
- (ZoomPAAP::MeetingPreferences)getMeetingPreferences;
- (ZoomPAAP::PAAPChat)getChatEntity;

@end

NS_ASSUME_NONNULL_END
