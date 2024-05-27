//
//  IZMShareMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/13/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMShareMgr_h
#define IZMShareMgr_h

NS_ASSUME_NONNULL_BEGIN

enum Support_Center_Share_Type
{
    Support_Center_Share_Type_None,
    Support_Center_Share_Type_Monitor,
    Support_Center_Share_Type_Window,
};

typedef NS_ENUM(NSInteger, ZMSendingShareType){
    ZMSendingShareType_Normal,
    ZMSendingShareType_Slides,
    ZMSendingShareType_WhiteBoard,
    ZMSendingShareType_ZDoc,
};

@protocol IZMSendShareCompatibleStreamMgr <NSObject>
@property (readonly, assign) NSInteger  shareSessionType;

@end

@protocol IZMShareMgr <ZMRoutableObject>
- (BOOL)isMainConfWindowNotVisibleWhileSharing;
- (void)onRemoteForbidded;
- (void)closeSelectShareWindow;
- (void)stopShare;
- (void)stopAllViewableShares;
- (void)force2ShowSelections:(int)inType bForced:(BOOL)bForced;
- (NSScreen*)getFITScreen;
- (void)cleanZappShareInfo;
- (BOOL)isInComputerAudioSharingMode;
- (BOOL)isSendingSharing;
- (void)showFitBarForNotifyWithDelay;
@end

NS_ASSUME_NONNULL_END

#endif /* IZMShareMgr_h */
