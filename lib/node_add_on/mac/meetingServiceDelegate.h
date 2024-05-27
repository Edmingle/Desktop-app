

#import <Foundation/Foundation.h>
#import "Header_include.h"
NS_ASSUME_NONNULL_BEGIN
@interface meetingServiceDelegate : NSObject<ZoomSDKMeetingServiceDelegate,ZoomSDKMeetingUIControllerDelegate,ZoomSDKMeetingActionControllerDelegate,ZoomSDKH323HelperDelegate,ZoomSDKASControllerDelegate,ZoomSDKRealNameAuthenticationDelegate,ZoomSDKWebinarControllerDelegate,ZoomSDKMeetingRecordDelegate>


+(meetingServiceDelegate *)share;
-(ZoomSDKRetrieveSMSVerificationCodeController *)getRetriveController;
-(ZoomSDKVerifySMSVerificationCodeController *)getVerifyCintroller;
-(BOOL)getResendRetriveController;
-(BOOL)getReVerifyCintroller;
-(ZoomSDKWebinarRegisterHelper *)getWebinarRegisterHelper;
-(ZoomSDKJoinMeetingHelper *)getJoinMeetingHelper;
-(ZoomSDKWebinarInputScreenNameHandler *)getWebinarInputScreenNameHandler;

@end

@interface meetingServiceChatDelegate : NSObject<ZoomSDKMeetingChatControllerDelegate>

@end

@interface meetingServiceRecordDelegate : NSObject<ZoomSDKMeetingRecordDelegate>
+(meetingServiceRecordDelegate *)share;
@property(nonatomic,strong)ZoomSDKRequestStartCloudRecordingHandler *cloudRecordingHandler;
@end

@interface meetingServiceWaitingRoomDelegate : NSObject<ZoomSDKWaitingRoomDelegate>
+(meetingServiceWaitingRoomDelegate *)share;
@property(nonatomic,strong)ZoomSDKWaitingRoomDataDownloadHandler *waitingRoomHandler;
@end

@interface meetingServiceSmartSummaryDelegate : NSObject<ZoomSDKMeetingSmartSummaryControllerDelegate>
+(meetingServiceSmartSummaryDelegate *)share;
@property(nonatomic,strong)ZoomSDKMeetingSmartSummaryPrivilegeHandler *smartSummaryHandler;
@end

NS_ASSUME_NONNULL_END
