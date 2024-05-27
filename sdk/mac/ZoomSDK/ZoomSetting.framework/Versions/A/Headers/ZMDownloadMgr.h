//
//  ZMDownloadMgr.h
//  SaasBeePTUIModule
//
//  Created by Francis Zhuo on 4/15/21.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMOndemandProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMDownloadMgr : NSObject<ZMOndemandProtocol>

@property (nonatomic, strong, nullable) NSString *privateFrameworksPath;

@end

NS_ASSUME_NONNULL_END
