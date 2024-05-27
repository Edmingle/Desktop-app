//
//  ZMPSMediaClient.h
//  ZoomClips
//
//  Created by Michael Lin on 2023/1/11.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPSMediaClient : ZMPSObject

- (void)setupProxy;
- (BOOL)supportSmartVirtualBackground;
- (BOOL)supportSmartVideoVirtualBackground;
- (BOOL)support3DAvatarEffect;
- (void)notifyAomhostReady;
- (void)notifyViperExReady;

@end

NS_ASSUME_NONNULL_END
