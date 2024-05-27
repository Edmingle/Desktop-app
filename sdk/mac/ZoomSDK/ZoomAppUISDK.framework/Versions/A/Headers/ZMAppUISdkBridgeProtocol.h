//
//  ZMAppSdkBridgeProtocol.h
//  ChatUI
//
//  Created by Peter Xu on 2021/9/17.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomKit/ZMRouterKit.h>
#import <Cocoa/Cocoa.h>

@protocol ZMAppSdkBridgeProtocol <ZMRoutableObject>
- (void *)getZappCommonApi;
- (void *)getPTApi;
- (BOOL)isSupportZmdf:(NSString *)appId;

@end

@protocol ZMAppSdkConfBridgeProtocol <ZMRoutableObject>
- (void *)getZappCommonApi;
- (void *)getConfApi;
@end
