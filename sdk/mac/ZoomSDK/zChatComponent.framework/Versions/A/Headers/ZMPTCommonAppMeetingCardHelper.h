//
//  ZMPTCommonAppMeetingCardHelper.h
//  zChatComponent
//
//  Created by Cyan.Yang on 2024/1/23.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMScheduleMeetingInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPTCommonAppMeetingCardHelper : NSObject

@property (nonatomic, readonly, nullable) ZMScheduleMeetingInfo *scheduleMeetingInfo;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (nullable instancetype)initWithMessageID:(NSString *)messageID sessionID:(NSString *)sessionID NS_DESIGNATED_INITIALIZER;

- (void)viewInCalendar:(NSString *)calendarLink;
- (void)openCMCChat:(NSString *)subCMCSessionId fromSession:(NSString *)sessionId;
- (void)copyInvitation:(NSString *)joinURL;

@end

NS_ASSUME_NONNULL_END
