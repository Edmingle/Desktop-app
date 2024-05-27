//
//  ZMFileModule.h
//  zChatUI
//
//  Created by groot.ding on 14/08/2020.
//  Copyright © 2020 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMFileOperateProtocal.h>
#import <zChatComponent/ZMFileEntity.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMFileIntegrationShareInfo;

@interface ZMFileCallbackParam : NSObject

@property (nonatomic,assign) unsigned int result;

@property (nonatomic,copy) NSString *actionOnwer;

@property (nonatomic,copy) NSString *fileId;
@property (nonatomic,copy) NSString *fileName;

@property (nonatomic,copy) NSString *sessionId;
@property (nonatomic,copy) NSString *messageId;
@property (nonatomic,copy) NSString *threadId;

@property (nonatomic,assign) NSUInteger fileIndex;
@property (nonatomic,assign) NSUInteger fileSourceType;

@property (nonatomic,copy) NSString *requestId;

@property (nonatomic,copy) NSString *url;

@property (nonatomic,assign) BOOL isPreview;

@property (nonatomic,assign) NSInteger ratio;
@property (nonatomic,assign) NSInteger completeSize;
@property (nonatomic,assign) NSInteger bitPerSecond;

@property (nonatomic,copy) NSArray <NSString *> * relatedSessionIds;

@property (nonatomic,assign) ZMFileShareType shareType;

@property (nonatomic,copy) NSString *whiteboardLink;

@property (nonatomic,retain) ZMFileIntegrationShareInfo *fileIntergrationShareInfo;

@end

@interface ZMFileModule : NSObject <ZMFileOperateProtocal,ZMFileOPFlagProtocol,ZMFileOperateCallback,ZMFileDownladCallback,ZMFileOperateListen,ZMFileErrorProtocal,ZMImageCompressProtolcal, ZMFileShareProtocal>


+ (ZMFileModule *)sharedInstance;
+ (void)releaseInstance;

- (void)registerFileOperateImpl:(id <ZMFileOperateProtocal>)fileOperateImpl sourceType:(NSInteger)sourceType;

- (void)removeFileOperateBySourceType:(NSInteger)sourceType;

@end

NS_ASSUME_NONNULL_END
