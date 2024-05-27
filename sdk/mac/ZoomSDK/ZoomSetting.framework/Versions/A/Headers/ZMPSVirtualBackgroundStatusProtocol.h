//
//  ZMPSVirtualBackgroundStatusProtocol.h
//  ZoomSetting
//
//  Created by Michael Lin on 2024/1/15.
//

#ifndef ZMPSVirtualBackgroundStatusProtocol_h
#define ZMPSVirtualBackgroundStatusProtocol_h

@protocol ZMPSVirtualBackgroundStatusProtocol <NSObject>

- (void)psOnVBConfigChanged;
- (void)psOnVBItemsChanged;

@end

#endif /* ZMPSVirtualBackgroundStatusProtocol_h */
