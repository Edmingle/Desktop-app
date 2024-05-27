//

#import <Foundation/Foundation.h>

@interface ZoomSDKReminderContent : NSObject
/**
 * Get the reminder’s type.
 */
@property(nonatomic,assign,readonly)ZoomSDKReminderType type;
/**
 * Get the reminder dialog content’s title.
 */
@property(nonatomic,copy,readonly)NSString *title;
/**
 * Get the detail content of the reminder dialog content.
 */
@property(nonatomic,copy,readonly)NSString *content;
/**
 * Whether to block the user from joining or staying in the meeting.
 */
@property(nonatomic,assign,readonly)BOOL isBlocking;
/**
 * Get the type of the action which user should take after receiving this reminder content.
 */
@property(nonatomic,assign,readonly)ZoomSDKReminderActionType actionType;
/**
 * Get a list of reminder’s type.
 */
@property(nonatomic,copy,readonly)NSArray *multiReminderTypes;
@end

@interface ZoomSDKReminderHandler : NSObject
/**
 * accept the reminder.
 */
-(void)accept;
/**
* declined the reminder.
*/
-(void)decline;
/**
* ignore the reminder.
*/
-(void)ignore;

@end

@interface ZoomSDKMeetingEnableReminderHandler : NSObject

/**
 * @brief Set the option indicating which meetings smart recording will be enabled for.
 * @param option Specify the option.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
-(ZoomSDKError)setEnableOption:(ZoomSDKMeetingFeatureEnableOption)option;

/**
 * @brief Start the smart recording.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
-(ZoomSDKError)start;

/**
 * @brief Decline the reminder.
 * @param declineAll YES means decline all reminders,and participants cannot send requests again until the host change the setting. NO means that the host declines only this specific request , not all requests.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
-(ZoomSDKError)decline:(BOOL)declineAll;

/**
 * @brief Ignore the reminder.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
-(ZoomSDKError)ignore;
@end

@protocol ZoomSDKReminderControllerDelegate <NSObject>
/**
 * @brief Callback event when the reminder dialog displays.
 * @param handle The helper to handle the reminder dialog.
 * @param content The detail content in the reminder dialog.
 */
-(void)onReminderNotify:(ZoomSDKReminderHandler*)handle reminderContent:(ZoomSDKReminderContent*)content;

/**
 * @brief Callback event to enable showing the reminder dialog.
 * @param handle A pointer to the ZoomSDKMeetingEnableReminderHandler.
 * @param content The detail content in the reminder dialog.
 */
-(void)onEnableReminderNotify:(ZoomSDKMeetingEnableReminderHandler*)handle reminderContent:(ZoomSDKReminderContent*)content;

@end

@interface ZoomSDKReminderController : NSObject
/**
 *@brief Reminder callback event handler.
 */
@property(nonatomic,assign) id<ZoomSDKReminderControllerDelegate> delegate;
@end
