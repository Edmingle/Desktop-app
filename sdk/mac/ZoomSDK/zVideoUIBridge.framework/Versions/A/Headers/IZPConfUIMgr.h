//
//  IZPConfUIMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/15/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZPConfUIMgr_h
#define IZPConfUIMgr_h

#import <zVideoUIBridge/IZMShareMgr.h>
@protocol IZPConfUIMgr <ZMRoutableObject>
@property (nonatomic, assign) BOOL isConfReady;

- (void)startSendingShareForType:(ZMSendingShareType)type;

@end

#endif /* IZPConfUIMgr_h */
