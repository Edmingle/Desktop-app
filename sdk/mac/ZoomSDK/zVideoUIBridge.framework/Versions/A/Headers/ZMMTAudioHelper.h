//
//  ZMMTAudioHelper.h
//  VideoUI
//
//  Created by javenlee.li on 2021/11/13.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTAudioHelper : ZMBaseHelper

- (BOOL)isMuteOnEntry;
- (void)setMuteOnEntry:(BOOL)isOn;

- (BOOL)isPlayChimeOn;
- (void)setPlayChime:(BOOL)isOn;

- (BOOL)isAllowParticipantUnmuteSelf;
- (void)setAllowParticipantUnmuteSelf:(BOOL)isOn;

- (int)getAudioType;
- (BOOL)isJoinAudioByVoip;

@end

NS_ASSUME_NONNULL_END
