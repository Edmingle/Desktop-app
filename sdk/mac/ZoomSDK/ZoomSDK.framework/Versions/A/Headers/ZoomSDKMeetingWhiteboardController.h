#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZoomSDKMeetingWhiteboardControllerDelegate <NSObject>

/**
 * @brief Whiteboard status changed callback. Use this function to inform the user that the whiteboard has been started or stopped, and all users in the meeting can get the event.
 * @param status Specify current whiteboard status. For more details, see {@link ZoomSDKWhiteboardStatus}.
 */
-(void)onWhiteboardStatusChanged:(ZoomSDKWhiteboardStatus)status;

/**
 * @brief Callback event of whiteboard setting type changed.
 * @param shareOption Who can share their whiteboard. For more details, see {@link ZoomSDKWhiteboardShareOption}.
 * @param createOption Who can create a new whiteboard. For more details, see {@link ZoomSDKWhiteboardCreateOption}.
 * @param bEnable Whether to enable the participants' ability to create a whiteboard without a host in the meeting.
 */
-(void)onWhiteboardSettingsChanged:(ZoomSDKWhiteboardShareOption)shareOption createOption:(ZoomSDKWhiteboardCreateOption)createOption enable:(BOOL)bEnable;

@end
@interface ZoomSDKMeetingWhiteboardController : NSObject
@property(nonatomic,assign) id<ZoomSDKMeetingWhiteboardControllerDelegate> delegate;

/**
 * @brief Set the whiteboard web view and dashboard web view owner window.
 * @param window Specify the owner window. If the window is NULL, the desktop window will be the owner window.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 * @note This function should be called before call ShowDashboardView. Call this function before calling showDashboardView. Call this function when receiving the meeting status ZoomSDKMeetingStatus_InMeeting. Valid only for user custom interface mode.
 */
-(ZoomSDKError)setParentWindow:(NSWindow *)window;

/**
 * @brief Determine whether the current meeting supports the whiteboard or not.
 * @return YES indicates to support.
 */
-(BOOL)isSupportWhiteBoard;

/**
 * @brief Determine whether the current meeting can start sharing the whiteboard.
 * @param reason The reason no one can start sharing the whiteboard, see {@link ZoomSDKCannotShareReasonType}.
 * @return YES indicates you can start sharing the whiteboard.
 */
-(BOOL)canStartShareWhiteboard:(ZoomSDKCannotShareReasonType*)reason;

/**
 * @brief Show the dashboard web view window.
 * @param point The original point to display dashboard web view window. If the point is (-1,-1) the window positon will be in the center of the screen where the owner window is located.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise the function fails.
 */
-(ZoomSDKError)showDashboardView:(NSPoint)point;

/**
 * @brief Set the dashboard web view window size.
 * @param size The size of display dashboard web view window. If the size is (0,0) the window size will be default size.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise the function fails.
 */
-(ZoomSDKError)setDashboardViewSize:(NSSize)size;

/**
 * @brief Set the whiteboard web view window position.
 * @param point The original point to display dashboard web view window. If the point is (-1,-1) the window positon will be in the center of the screen where the owner window is located.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise the function fails.
 */
-(ZoomSDKError)setWhiteboardViewPos:(NSPoint)point;

/**
 * @brief Set the whiteboard web view window size.
 * @param size The size of display whiteboard web view window. If the size is (0,0) the window size will be default size.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise the function fails.
 */
-(ZoomSDKError)setWhiteboardViewSize:(NSSize)size;
/**
 * @brief Set the option for who can share a whiteboard.
 * @param option New setting for who can share a whiteboard. For more details, see {@link ZoomSDKWhiteboardShareOption}.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)setWhiteboardShareOption:(ZoomSDKWhiteboardShareOption)option;

/**
 * @brief Get the option for who can share whiteboards.
 * @return The return value is the setting option for who can share a whiteboard.
 */
-(ZoomSDKWhiteboardShareOption)getWhiteboardShareOption;

/**
 * @brief Set the option for whiteboard who can initiate a new whiteboard.
 * @param option Setting option for who can initiate a new whiteboard. For more details, see {@link ZoomSDKWhiteboardCreateOption}.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)setWhiteboardCreateOption:(ZoomSDKWhiteboardCreateOption)option;

/**
 * @brief Get the option for whiteboard who can initiate a new whiteboard.
 * @return The return value is the setting option for whiteboard who can initiate a new whiteboard.
 */
-(ZoomSDKWhiteboardCreateOption)getWhiteboardCreateOption;

/**
 * @brief Enable the participants create a new whiteboard without the host in the meeting.
 * @param bEnable YES indicates to enable. NO is not.
 * @return If the function succeeds, it will return ZoomSDKError_Success.
 */
-(ZoomSDKError)enableParticipantsCreateWithoutHost:(BOOL)bEnable;

/**
 * @brief Determine whether to enable the participants create a new whiteboard without the host in the meeting.
 * @return YES indicates that they have these permissions.
 */
-(BOOL)isParticipantsCreateWithoutHostEnabled;
@end

NS_ASSUME_NONNULL_END
