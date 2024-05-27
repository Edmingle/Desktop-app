//
//  ZoomSDKMeetingSmartSummaryController.h
//  ZoomSDK
//
//  Created by Bella Tu on 2023/10/9.
//

#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"

NS_ASSUME_NONNULL_BEGIN
@interface ZoomSDKMeetingSmartSummaryPrivilegeHandler : NSObject
/**
 * @brief Agree to the start smart summary request.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)accept;
/**
 * @brief Decline the start smart summary request.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)decline;
/**
 * @brief Ignore the start smart summary request.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)ignore;
@end

@protocol ZoomSDKMeetingSmartSummaryControllerDelegate <NSObject>
/**
 * @brief Callback event when smart summary status changes.
 * @param isStart YES means that the smart summary is started. NO means it has not.
 */
-(void)onSmartSummaryStatusChanged:(BOOL)isStart;
/**
 * @brief Callback event when a user requests the host to start smart summary.
 * @param senderID The user who requests the host to start smart summary.
 * @param handler The handler to handle the smart summary start request.
 */
-(void)onSmartSummaryPrivilegeRequested:(unsigned int)senderID requestHandler:(ZoomSDKMeetingSmartSummaryPrivilegeHandler*)handler;
/**
 * @brief Callback event when the host handle the smart summary request.
 * @param timeout YES means the host doesn't handle the request until timeout.
 * @param decline YES means the host declines the request, NO means the host agrees to the request.
 */
-(void)onSmartSummaryStartReqResponse:(BOOL)timeout isDecline:(BOOL)decline;
/**
 * @brief Callback event when the user needs to go to the web to enable the smart summary feature. The interface will only be triggered for Businessbiz accounts. And the smart summary feature will be enabled for the future meeting, but not enable the current meeting. If the user enables the setting in web.
 */
-(void)onEnableSmartSummary;

@end

@interface ZoomSDKMeetingSmartSummaryController : NSObject
@property(nonatomic,assign) id<ZoomSDKMeetingSmartSummaryControllerDelegate> delegate;
/**
 * @brief Determine if current meeting support smart summary feature.
 * @return YES means the current meeting supports the smart summary feature. NO means the feature is not supported.
 */
-(BOOL)isSmartSummarySupported;
/**
 * @brief Determine if the smart summary feature is enabled in the meeting.
 * @return YES means that the smart summary feature is enabled.
 */
-(BOOL)isSmartSummaryEnabled;
/**
 * @brief Whether the current user can enable the smart summary feature for the account.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)canEnableSmartSummaryFeature;
/**
 * @brief Enable the smart summary feature for the account.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)enableSmartSummaryFeature;
/**
 * @brief Whether the current user is able to start smart summary.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)canStartSmartSummary;
/**
 * @brief Start smart summary.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)startSmartSummary;
/**
 * @brief Stop smart summary.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)stopSmartSummary;
/**
 * @brief Query whether smart summary is started.
 * @return YES means smart summary is started, NO means it has not.
 */
-(BOOL)isSmartSummaryStarted;
/**
 * @brief Whether the current user can request the admin to enable the smart summary feature for the account.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)canRequestEnableSmartSummaryFeature;
/**
 * @brief Request the admin to enable the smart summary feature for the account.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)requestEnableSmartSummaryFeature;
/**
 * @brief Whether the current user can request the host to start the smart summary for the current meeting.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)canRequestStartSmartSummary;
/**
 * @brief Request the host to start the smart summary for the current meeting.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)requestStartSmartSummary;
@end

NS_ASSUME_NONNULL_END
