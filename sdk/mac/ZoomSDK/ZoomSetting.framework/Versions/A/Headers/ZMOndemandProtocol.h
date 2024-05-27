//
//  ZMOndemandProtocol.h
//  SaasBeePTUIModule
//
//  Created by Francis Zhuo on 7/7/21.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomKit/ZMRoutableObject.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMDownloadObject;

typedef enum {
    ZMDownloadStageIdle = 0,
    ZMDownloadStageInitial,
    ZMDownloadStageRequestUrl,
    ZMDownloadStageDownloading,
    ZMDownloadStageUnzipping,
    ZMDownloadStageCopying,
    ZMDownloadStageFailed,
    ZMDownloadStageSuccess,
    ZMDownloadStageCancel,
} ZMDownloadStage;

typedef NS_ENUM(NSUInteger, ZMDownloadType) {
    ZMDownloadTypeDefault,
    ZMDownloadTypeCodeSnippet,
    ZMDownloadTypeSipCall,
    ZMDownloadTypeRetinaImages,
    ZMDownloadTypeComponents,
    ZMDownloadTypeAomhost,
    ZMDownloadTypeAirhost,
    ZMDownloadTypeViperEX,
    ZMDownloadTypeMail,
    ZMDownloadTypeCalendar,
    ZMDownloadTypeCodec,
    ZMDownloadTypeCefAgent,
};

typedef NS_ENUM(NSUInteger, ZMDownloadResult) {
    ZMDownloadResultFailed,
    ZMDownloadResultSuccess,
    ZMDownloadResultCancel,
};

typedef void (^ZMDownloadProgressBlock)(ZMDownloadStage stage, CGFloat process);
typedef void (^ZMDownloadCompletionBlock)(ZMDownloadResult result, NSError *_Nullable error);

@protocol ZMOndemandProtocol <ZMRoutableObject>
@optional
- (void)downloadForType:(ZMDownloadType)type;

- (BOOL)isInProgress;

///return token
- (nullable id)downloadForType:(ZMDownloadType)type
                      progress:(nullable ZMDownloadProgressBlock)progress
                    completion:(nullable ZMDownloadCompletionBlock)completion;

///return token
- (nullable id)registerForType:(ZMDownloadType)type
                      progress:(nullable ZMDownloadProgressBlock)progress
                    completion:(nullable ZMDownloadCompletionBlock)completion;

- (void)updateProgress:(nullable ZMDownloadProgressBlock)progress
            completion:(nullable ZMDownloadCompletionBlock)completion
              withType:(ZMDownloadType)type
                 token:(id)token;

- (nullable NSString *)downloadUrlForType:(ZMDownloadType)type;

- (BOOL)cancelDownloadForType:(ZMDownloadType)type withToken:(id)token;
- (BOOL)cancelDownloadForType:(ZMDownloadType)type;

- (void)checkUpdateReturn:(NSString *)inLatestVersion
              downloadURL:(NSString *)inURLString
              releaseNote:(NSString *)inReleaseNote
                requestId:(NSString *)inRequestId
                   result:(NSInteger)inResult;
- (BOOL)isInstalledForType:(ZMDownloadType)type;
- (nullable NSString *)bundlePathForType:(ZMDownloadType)type;
- (void)isCodeSignValidForType:(ZMDownloadType)type completion:(void (^)(NSString *_Nullable path))completion;
- (void)isCodeSignValidForType:(ZMDownloadType)type files:(NSArray<NSString *> *)files completion:(void (^)(NSString *_Nullable path))completion;
- (nullable ZMDownloadObject *)downloadObjectForType:(ZMDownloadType)type;

/// Download a type of resource if needed.
/// it is a combination of "isInstalledForType:" and "downloadForType:"
/// @param type download type
/// @return need download or not, as opposite as - (BOOL)isInstalledForType:(ZMDownloadType)type
- (BOOL)downloadIfNeededForType:(ZMDownloadType)type;

/// Download a type of resource if needed.
/// it is a combination of "isInstalledForType:" and "downloadForType:progress:completion:"
/// @param type download type
/// @param token return download token
/// @param progress progress block
/// @param completion completion block
/// @return need download or not, as opposite as - (BOOL)isInstalledForType:(ZMDownloadType)type
- (BOOL)downloadIfNeededForType:(ZMDownloadType)type
                          token:(NSString * _Nullable * _Nullable)token
                       progress:(nullable ZMDownloadProgressBlock)progress
                     completion:(nullable ZMDownloadCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
