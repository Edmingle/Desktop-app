

#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"


/**
 * @brief Status of polling.
 */
typedef enum
{
    ZoomSDKPollingStatus_Initial, //The initial status.
    ZoomSDKPollingStatus_Started, //User started polling.
    ZoomSDKPollingStatus_ShareResult, //User shared polling result.
    ZoomSDKPollingStatus_Stopped, //User stopped polling.
}ZoomSDKPollingStatus;


/**
 * @brief Type of polling.
 */
typedef enum
{
    ZoomSDKPollingType_Unknown = 0,
    ZoomSDKPollingType_Poll,
    ZoomSDKPollingType_Quiz
}ZoomSDKPollingType;


typedef enum
{
    ZoomSDKPollingQuestionType_Unknown = 0,
    ZoomSDKPollingQuestionType_Single,
    ZoomSDKPollingQuestionType_Multi,
    ZoomSDKPollingQuestionType_Matching,
    ZoomSDKPollingQuestionType_RankOrder,
    ZoomSDKPollingQuestionType_ShortAnswer,
    ZoomSDKPollingQuestionType_LongAnswer,
    ZoomSDKPollingQuestionType_FillBlank,
    ZoomSDKPollingQuestionType_NPS,
    ZoomSDKPollingQuestionType_Dropdown,
}ZoomSDKPollingQuestionType;


typedef enum
{
    ZoomSDKPollingActionType_Unknown = 0,
    ZoomSDKPollingActionType_Start,
    ZoomSDKPollingActionType_Stop,
    ZoomSDKPollingActionType_ShareResult,
    ZoomSDKPollingActionType_StopShareResult,
    ZoomSDKPollingActionType_Duplicate,
    ZoomSDKPollingActionType_Delete,
    ZoomSDKPollingActionType_Submit,
    ZoomSDKPollingActionType_Error
}ZoomSDKPollingActionType;


/**
 * @brief Polling item interface.
 */
@interface ZoomSDKPollingItem : NSObject
/**
 *@brief Polling ID.
 */
@property(nonatomic, copy, readonly) NSString* pollingID;
/**
 *@brief Polling name.
 */
@property(nonatomic, copy, readonly) NSString* pollingName;
/**
 *@brief Polling type.
 */
@property(nonatomic, assign, readonly) ZoomSDKPollingType pollingType;
/**
 *@brief Polling status.
 */
@property(nonatomic, assign, readonly) ZoomSDKPollingStatus pollingStatus;
/**
 *@brief Polling question count.
 */
@property(nonatomic, assign, readonly) unsigned int pollingQuestionCount;
/**
 *@brief Count of total voted users.
 */
@property(nonatomic, assign, readonly) unsigned int totalVotedUserCount;
/**
 *@brief Determine if is library polling.
 */
@property(nonatomic, assign, readonly) BOOL isLibraryPolling;
@end



/**
 * @brief Polling answer item interface.
 */
@interface ZoomSDKPollingAnswerItem : NSObject
/**
 *@brief Polling ID of answer item.
 */
@property(nonatomic, copy, readonly) NSString* pollingID;
/**
 *@brief Polling question ID.
 */
@property(nonatomic, copy, readonly) NSString* pollingQuestionID;
/**
 *@brief Polling sub-question ID.
 */
@property(nonatomic, copy, readonly) NSString* pollingSubQuestionID;
/**
 *@brief Polling answer ID.
 */
@property(nonatomic, copy, readonly) NSString* pollingAnswerID;
/**
 *@brief Polling answer name.
 */
@property(nonatomic, copy, readonly) NSString* pollingAnswerName;
/**
 *@brief Polling answered content.
 */
@property(nonatomic, copy, readonly) NSString* pollingAnsweredContent;
/**
 *@brief Determine if is checked.
 *@note This property has no meaning for the corrent answer.
 */
@property(nonatomic, assign, readonly) BOOL isChecked;
@end


/**
 * @brief Polling answer result item interface.
 */
@interface ZoomSDKPollingAnswerResultItem : NSObject
/**
 *@brief Polling ID of answer result item.
 */
@property(nonatomic, copy, readonly) NSString* pollingID;
/**
 *@brief Polling queston ID.
 */
@property(nonatomic, copy, readonly) NSString* pollingQuestionID;
/**
 *@brief Polling sub-queston ID.
 */
@property(nonatomic, copy, readonly) NSString* pollingSubQuestionID;
/**
 *@brief Polling answer ID.
 */
@property(nonatomic, copy, readonly) NSString* pollingAnswerID;
/**
 *@brief Polling answer name.
 */
@property(nonatomic, copy, readonly) NSString* pollingAnswerName;
/**
 *@brief Query how many participants selected this answer.
 */
@property(nonatomic, assign, readonly) unsigned int selectedCount;
@end


/**
 * @brief Polling question item interface.
 */
@interface ZoomSDKPollingQuestionItem : NSObject
/**
 *@brief Polling ID of question item.
 */
@property(nonatomic, copy, readonly) NSString* pollingID;
/**
 *@brief Polling question ID.
 */
@property(nonatomic, copy, readonly) NSString* pollingQuestionID;
/**
 *@brief Polling question name.
 */
@property(nonatomic, copy, readonly) NSString* pollingQuestionName;
/**
 *@brief Polling question type.
 */
@property(nonatomic, assign, readonly) ZoomSDKPollingQuestionType pollingQuestionType;
/**
 *@brief The count of answered questions.
 */
@property(nonatomic, assign, readonly) unsigned int answeredCount;
/**
 *@brief Determine if is required.
 */
@property(nonatomic, assign, readonly) BOOL isRequired;
/**
 * @brief Get the list of polling question's subquestion.
 */
@property(nonatomic, retain, readonly) NSArray<ZoomSDKPollingQuestionItem*>* pollingSubQuestionItemList;
/**
 * @brief Get the list of polling question or subquestion's answer.
 */
@property(nonatomic, retain, readonly) NSArray<ZoomSDKPollingAnswerItem*>* pollingAnswerItemList;
@end



/**
 * @brief Polling controller callback event.
 */
@protocol ZoomSDKPollingControllerDelegate <NSObject>
@optional
/**
 * @brief Polling status changed callback. Use this function to inform the user that the polling has been started, share result or stopped.
 * @param pollingID Specify the status changed poll's ID.
 * @param status Specify current polling status. For more details. see {@link ZoomSDKPollingStatus}.
 */
- (void)onPollingStatusChanged:(NSString*)pollingID status:(ZoomSDKPollingStatus)status;

/**
 * @brief Polling result updated callback. When a participant submit polling.
 * @param pollingID Specify the result updated poll's ID.
 */
- (void)onPollingResultUpdated:(NSString*)pollingID;

/**
 * @brief Polling list updated callback. This is triggered when a host adds, edits, duplicates, or deletes a poll.
 */
- (void)onPollingListUpdated;

/**
 * @brief Polling action result callback. This is triggered when a user perform an action for a poll.
 * @param actionType Specify the action type. For more details. see {@link ZoomSDKPollingActionType}.
 * @param pollingID Specify the action poll's ID.
 * @param bSuccess Specify whether the action succeeds.
 * @param errorMsg Specify the error message when the action fails. It is only for  ZoomSDKPollingActionType_Error.
 * @note If actionType is ZoomSDKPollingActionType_Error, use errorMsg. This errorMsg may be triggered by any action.
 */
- (void)onPollingActionResult:(ZoomSDKPollingActionType)actionType pollingID:(NSString*)pollingID bSuccess:(BOOL)bSuccess errorMsg:(NSString*)errorMsg;

/**
 * @brief Polling question item image downloaded callback. This is triggered when a user starts or joins a meeting, if any polling question has an image, or the host uploads an image to a polling question in the meeting.
 * @param questionID Specify the polling question's ID.
 * @param path Specify the image downloaded path.
 */
- (void)onPollingQuestionImageDownloaded:(NSString*)questionID path:(NSString*)path;

/**
 * @brief Polling elapsed time callback. This is triggered when a host starts a poll or user changes to host from non host.
 * @param pollingID Specify the polling ID.
 * @param elapsedTime Specify the polling elapsed time in milliseconds.
 */
- (void)onGetPollingElapsedTime:(NSString*)pollingID elapsedTime:(unsigned int)elapsedTime;

/**
 * @brief Callback event for the user get right answer list privilege changed. This is triggered when the host calls EnableGetRightAnswerList in a quiz.
 * @param bCan Specify whether the user has get right answer list privilege or not.
 */
- (void)onGetRightAnswerListPrivilege:(BOOL)bCan;

/**
 * @brief Polling inactive callback. When the user starts a meeting in another device by same account, this callback is triggered. Then call CanDoPolling return false.
 */
- (void)onPollingInactive;
@end


/**
 * @brief Polling controller interface.
 */
@interface ZoomSDKPollingController : NSObject
{
    id<ZoomSDKPollingControllerDelegate> _delegate;
}
@property(nonatomic, assign)id<ZoomSDKPollingControllerDelegate> delegate;

//Common (for all)
/**
 * @brief Determine whether the current meeting can do the polling.
 * @return YES indicates you can do polling.
 */
- (BOOL)canDoPolling;

/**
 * @brief Determine if the answer result list can be show.
 * @param pollingID Specify the answer result's polling ID.
 * @return YES means can. Otherwise, the return value is NO.
 */
- (BOOL)canShowAnswerResultList:(NSString*)pollingID;

/**
 * @brief Get the list of poll's question.
 * @param pollingID Specify the question's polling ID.
 * @return If the function succeeds, the return value is a pointer to the NSArray<ZoomSDKPollingQuestionItem*>, Otherwise, the return value is nil.
 */
- (NSArray<ZoomSDKPollingQuestionItem*>*)getPollingQuestionItemList:(NSString*)pollingID;

/**
 * @brief Get the list of polling question or subquestion's right answer.
 * @param pollingID Specify the right answer's polling ID.
 * @return If the function succeeds, the return value is a pointer to the NSArray<ZoomSDKPollingAnswerItem*>, Otherwise, the return value is nil.
 */
- (NSArray<ZoomSDKPollingAnswerItem*>*)getPollingRightAnswerItemList:(NSString*)pollingID;

/**
 * @brief Get the list of polling answer result item.
 * @param pollingID Specify the answer result's polling ID.
 * @return If the function succeeds, the return value is a pointer to the NSArray<ZoomSDKPollingAnswerResultItem*>, Otherwise, the return value is nil.
 */
- (NSArray<ZoomSDKPollingAnswerResultItem*>*)getPollingAnswerResultItemList:(NSString*)pollingID;

/**
 * @brief Get the polling item object of specified polling ID.
 * @param pollingID Specify the polling ID for which you want to get the information.
 * @return If the function succeeds, the return value is a pointer to the ZoomSDKPollingItem, Otherwise, the return value is nil.
 */
- (ZoomSDKPollingItem*)getPollingItemByID:(NSString*)pollingID;

/**
 * @brief Determine if the right answer item list can be allowed to get.
 * @param pollingID Specify the right answer's polling ID.
 * @return YES means can. Otherwise, the return value is NO.
 */
- (BOOL)canGetRightAnswerItemList:(NSString*)pollingID;

/**
 * @brief Get the polling question's image path.
 * @param pollingID Specify the answer's polling ID.
 * @param questionID Specify the answer's question ID.
 * @return If the function succeeds, the return value is the question's image path, Otherwise the function fails, and the return value is nil.
 */
- (NSString*)getPollingQuestionImagePath:(NSString*)pollingID questionID:(NSString*)questionID;

/**
 * @brief Get the polling question's minimum character and maximum character count.
 * @param pollingID Specify the question's polling ID.
 * @param questionID Specify the question's question ID.
 * @param minLen Specify the minimum number of words to submit.
 * @param maxLen Specify the maximum number of words to submit.
 * @note This function can only be used by short answer question and long answer question.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise failed.
 */
- (ZoomSDKError)getQuestionCharactersLengthRange:(NSString*)pollingID questionID:(NSString*)questionID minLen:(unsigned int*)minLen maxLen:(unsigned int*)maxLen;

/**
 * @brief Determine if the question is case sensitive.
 * @param pollingID Specify the question's polling ID.
 * @param questionID Specify the question's question ID.
 * @note This function can only be used by fill blank questions.
 * @return YES means is case sensitive. Otherwise, the return value is NO.
 */
- (BOOL)isQuestionCaseSensitive:(NSString*)pollingID questionID:(NSString*)questionID;

/**
 * @brief Get the active poll's ID.
 * @return The shared result or started poll's ID.
 */
- (NSString*)getActivePollingID;


//Host
/**
 * @brief Determine if the host can add polling.
 * @note Only the origin host can add polling.
 * @return YES means can. Otherwise, the return value is NO.
 */
- (BOOL)canAddPolling;

/**
 * @brief Open create polling in a web browser.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise the function fails.
 */
- (ZoomSDKError)addPolling;

/**
 * @brief Determine if the host can edit polling.
 * @param pollingID Specify the edit poll's polling ID.
 * @note Only the origin host can edit polling.
 * @return YES means can. Otherwise, the return value is NO.
 */
- (BOOL)canEditPolling:(NSString*)pollingID;

/**
 * @brief Open edit polling in a web browser.
 * @param pollingID Specify the edit poll's polling ID.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise the function fails.
 */
- (ZoomSDKError)editPolling:(NSString*)pollingID;

/**
 * @brief Determine if the host can delete polling.
 * @param pollingID Specify the delete poll's polling ID.
 * @note Only the origin host can delete polling.
 * @return YES means can. Otherwise, the return value is NO.
 */
- (BOOL)canDeletePolling:(NSString*)pollingID;

/**
 * @brief Delete the polling.
 * @param pollingID Specify the delete poll's polling ID.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise the function fails.
 */
- (ZoomSDKError)deletePolling:(NSString*)pollingID;

/**
 * @brief Determine if the host can duplicate polling.
 * @param pollingID Specify the duplicate poll's polling ID.
 * @note Only the origin host can duplicate polling.
 * @return YES means can. Otherwise, the return value is NO.
 */
- (BOOL)canDuplicatePolling:(NSString*)pollingID;

/**
 * @brief Duplicate the polling.
 * @param pollingID Specify the duplicate poll's polling ID.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise the function fails.
 */
- (ZoomSDKError)duplicatePolling:(NSString*)pollingID;

/**
 * @brief Determine if the user can view polling result in the browser.
 * @param pollingID Specify the poll's polling ID.
 * @note Only the origin host can view.
 * @return YES means can. Otherwise, the return value is NO.
 */
- (BOOL)canViewPollingResultFromBrowser:(NSString*)pollingID;

/**
 * @brief Open a polling result in the web browser.
 * @param pollingID Specify the poll's polling ID.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise the function fails.
 */
- (ZoomSDKError)viewPollingResultFromBrowser:(NSString*)pollingID;

/**
 * @brief Get the list of poll item.
 * @return If the function succeeds, the return value is a pointer to the NSArray<ZoomSDKPollingItem*>. Otherwise, the return value is nil.
 */
- (NSArray<ZoomSDKPollingItem*>*)getPollingItemList;

/**
 * @brief Determine if the host or co-host can start the polling.
 * @param pollingID Specify the poll's polling ID.
 * @return YES means can. Otherwise, the return value is NO.
 */
- (BOOL)canStartPolling:(NSString*)pollingID;

/**
 * @brief Start the polling.
 * @param pollingID Specify the poll's polling ID.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZoomSDKError)startPolling:(NSString*)pollingID;

/**
 * @brief Stop the polling.
 * @param pollingID Specify the poll's polling ID.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZoomSDKError)stopPolling:(NSString*)pollingID;

/**
 * @brief Determine if the host or co-host can restart the polling.
 * @param pollingID Specify the poll's polling ID.
 * @return YES means can. Otherwise, the return value is NO.
 */
- (BOOL)canRestartPolling:(NSString*)pollingID;

/**
 * @brief Restart the polling.
 * @param pollingID Specify the poll's polling ID.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZoomSDKError)restartPolling:(NSString*)pollingID;

/**
 * @brief Determine if the host or co-host can share the poll's result.
 * @param pollingID Specify the poll's polling ID.
 * @return YES means can. Otherwise, the return value is NO.
 */
- (BOOL)canSharePollingResult:(NSString*)pollingID;

/**
 * @brief Share the poll's result.
 * @param pollingID Specify the poll's polling ID.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZoomSDKError)startSharePollingResult:(NSString*)pollingID;

/**
 * @brief Stop to share the poll's result.
 * @param pollingID Specify the poll's polling ID.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZoomSDKError)stopSharePollingResult:(NSString*)pollingID;

/**
 * @brief Set to enable show right answer to participants when share quiz's result.
 * @param bEnable YES indicates to enable. NO means not.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZoomSDKError)enableGetRightAnswerList:(BOOL)bEnable;

/**
 * @brief Determine if the host can download poll's result from browser.
 * @note Only the origin host can download.
 * @return YES means can. Otherwise, the return value is NO.
 */
- (BOOL)canDownloadResult;

/**
 * @brief Download all stopped poll's result from browser.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZoomSDKError)downLoadResult;


/**
 * @brief Attendee set answer's check.
 * @param answerItem Specify the object of ZoomSDKPollingAnswerItem.
 * @param bCheck Specify whether you want to select the answer or not.
 * @remarks This function should only be used by single, matching, rank order, multi, rating scale, or drop down questions.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZoomSDKError)setAnswerCheck:(ZoomSDKPollingAnswerItem*)answerItem bCheck:(BOOL)bCheck;

/**
 * @brief Attendee set answer's content.
 * @param answerItem Specify the object of ZoomSDKPollingAnswerItem.
 * @param answerText Specify you want to reply answer's content.
 * @note This function should only be used by fill blank, short answer and long answer questions.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZoomSDKError)setAnswerContent:(ZoomSDKPollingAnswerItem*)answerItem answerText:(NSString*)answerText;

/**
 * @brief Determine if the attendee can submit the polling.
 * @param pollingID Specify the submit poll's polling ID.
 * @return YES means can. Otherwise, the return value is NO.
 */
- (BOOL)canSubmitPolling:(NSString*)pollingID;

/**
 * @brief Submit the polling.
 * @param pollingID Specify the submit poll's polling ID.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZoomSDKError)submitPolling:(NSString*)pollingID;
@end
