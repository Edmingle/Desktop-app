//
//  ZMDeepLinkEntity.h
//  zChatComponent
//
//  Created by Felipe Bastos on 6/8/22.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMFileEntity.h>

typedef NS_ENUM(NSUInteger, ZMDeepLinkEntitySessionType) {
    ZMDeepLinkEntitySessionType_Indeterminate = 0,
    ZMDeepLinkEntitySessionType_PublicChannel,
    ZMDeepLinkEntitySessionType_PrivateChannel,
    ZMDeepLinkEntitySessionType_Chat,
    ZMDeepLinkEntitySessionType_PMC,
    ZMDeepLinkEntitySessionType_RecurringPMC,
    ZMDeepLinkEntitySessionType_PrivateSpots,
    ZMDeepLinkEntitySessionType_PublicSpots
};

typedef NS_ENUM(NSUInteger, ZMDeepLinkEntityMessageType) {
    ZMDeepLinkEntityMessageType_Indeterminate = 0,
    ZMDeepLinkEntityMessageType_Text,
    ZMDeepLinkEntityMessageType_Image,
    ZMDeepLinkEntityMessageType_File,
    ZMDeepLinkEntityMessageType_Mixed, // file and/or image + text
    ZMDeepLinkEntityMessageType_NotAMessage,
};

typedef NS_ENUM(NSUInteger, ZMDeepLinkEntityStatus) {
    ZMDeepLinkEntityStatus_OK = 0,
    ZMDeepLinkEntityStatus_Error,
    ZMDeepLinkEntityStatus_Loading,
    ZMDeepLinkEntityStatus_NoContent,
    ZMDeepLinkEntityStatus_DeferredLoading,
};

@interface ZMDeepLinkEntity : ZMFileEntity
NS_ASSUME_NONNULL_BEGIN
@property (assign) ZMDeepLinkEntityStatus status;
@property (assign) BOOL needsDeferredLoading;
@property (assign) ZMDeepLinkEntitySessionType sessionType;
@property (assign) ZMDeepLinkEntityMessageType messageType;
@property (copy) NSString *messageSender;
@property (copy) NSDate *messageTime;
@property (copy) NSString *sessionName;
@property (copy) NSString *sessionDescription;
@property (copy) NSString *messageBody;
@property (copy, nullable) NSString *optionalDetailString;
@property (retain, nullable) NSImage *image;
@property (assign) unsigned long long targetServerTime;
@property (copy) NSDate *lastUpdateTime;
@property (nonatomic, assign) NSSize previewSize;
@property (nonatomic, assign) NSSize replyPreviewSize;
@property (assign) BOOL isAwaitingServerResponse;
NS_ASSUME_NONNULL_END

- (NSSize)titleContentSizeForWidth:(NSUInteger)maximumAllowableWidth;
- (NSSize)descriptionContentSizeForWidth:(NSUInteger)maximumAllowableWidth;
- (NSSize)optionalDetailContentSizeForWidth:(NSUInteger)maximumAllowableWidth;

- (NSSize)updateContentSize;
- (NSSize)updateReplyContentSize;
- (NSSize)updateContentSizeWithMaxWidth:(NSUInteger)maximumAllowableWidth;
- (NSSize)updateContentSizeWithMaxWidth:(NSUInteger)maximumAllowableWidth isReply:(BOOL)isReply;

- (NSString *_Nonnull)titleString;
- (NSDictionary *_Nonnull)titleAttributes;

- (NSString *_Nullable)timestampString;
- (NSDictionary *_Nullable)timestampAttributes;

- (NSString *_Nonnull)descriptionString;
- (NSDictionary *_Nonnull)descriptionAttributes;

- (void)loadImage:(NSString * _Nonnull)path;

@end
