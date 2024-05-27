//
//  ZMRTFCopyManager.h
//  ChatUI
//
//  Created by Yong Zhou on 1/17/22.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMMessageFontInfo;

@interface ZMRTFCopyManager : NSObject

@property (nonatomic, readonly, assign) NSInteger changeCount;
@property (nonatomic, readonly, assign) BOOL hasPasteItem;
@property (nonatomic, readonly, retain) NSArray<NSDictionary<NSArray<ZMMessageFontInfo *>*, NSString*> *> *pasteItems;

+ (ZMRTFCopyManager*)sharedInstance;

+ (void)releaseInstance;

- (void)cleanCopyManager;

- (void)addFontInfoList:(NSArray<ZMMessageFontInfo*>*)infoList forContent:(NSString*)content;

@end

