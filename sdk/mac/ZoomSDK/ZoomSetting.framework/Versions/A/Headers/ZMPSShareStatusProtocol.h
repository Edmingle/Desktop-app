//
//  ZMPSShareStatusProtocol.h
//  ZoomSetting
//
//  Created by Michael Lin on 2024/1/11.
//

#ifndef ZMPSShareStatusProtocol_h
#define ZMPSShareStatusProtocol_h

#import <zPSApp/media/IPSShare.h>

@protocol ZMPSShareStatusProtocol <NSObject>

@optional
- (void)psOnShareCapturerStatusChanged:(SSB_MC_AS_SPECIAL_MSG)msg;
- (void)psOnMacOverlayEnabled:(BOOL)enable;

@end

#endif /* ZMPSShareStatusProtocol_h */
