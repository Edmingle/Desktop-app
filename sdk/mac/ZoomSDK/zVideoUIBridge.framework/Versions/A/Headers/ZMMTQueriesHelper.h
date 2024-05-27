//
//  ZMMTQueriesHelper.h
//  VideoUIBridge
//
//  Created by Amanda Souriyamath on 6/29/23.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/ZMIQConstant.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMQuerySettingOptions;
@class ZMAIDynamicNotifier;
@class ZMIQMeetingPrompt;
@interface ZMMTQueriesHelper : ZMBaseHelper

//ICmmConfContext:
-(BOOL)isQueryEntranceEnabled;
-(BOOL)needShowQueriesEntrance;
-(BOOL)isMeetingQueryFeatureOn;
//-(BOOL)isZoomAIFeatureOn;
-(NSString*)getZoomAILearnMoreLink;
-(BOOL)needPromptQueryDisclaimer;

//ICmmConstaus:
-(BOOL)changeMeetingQueryStatus:(ZMQueriesStatus)newStatus;
-(ZMQueriesStatus)getMeetingQueryStatus;
-(BOOL)isMeetingQueriesStarted;

//ICmmWebAgentAPI:
-(BOOL)sendFeedbackOfQueryAnswer:(ZMQueriesFeedback)feedback withRequestId:(NSString*)requestId;

//ICmmConfInst(cmmconfmgr):
-(NSString*)sendQueryQuestionRequest:(NSString*)question;

//-(BOOL)needShowFirstTimeInDisclaimer;

-(BOOL)needShowTip;
-(void)setShownTip;

-(BOOL)isQueryFreeTrial;
-(BOOL)isQueryAutoStartEnabled;
-(void)agreeQueryDisclaimer:(BOOL)didAgree;

-(BOOL)requestToEnableQueries;
-(BOOL)requestToStartQueries;
-(BOOL)rspStartQueryReq:(NSString *)reqId senderId:(ZMUserID)senderId decline:(BOOL)decline;
-(BOOL)recordReqChangeQuerySettingUser:(ZMUserID)reqUserId;
-(BOOL)turnMeetingQueriesFeatureOn;
-(BOOL)turnMeetingQueriesFeatureOff;
-(BOOL)disclaimerDoNotShow:(BOOL)notShow;
- (NSString *)getQuerySettingUrl;
- (BOOL)isQueryEnableStrategyInMeeting;
- (BOOL)isQueryEnableStrategyInWeb;


//2023.9.23 patch//
-(NSArray<ZMQuerySettingOptions*>*)getQuerySettingOptions;
-(ZMIQMeetingPrompt*)getAICompanionMultiLanguagesPrompt;
-(BOOL)canSendQuery;
-(BOOL)canSeeQuerySetting;
-(BOOL)canChangeQuerySetting;
-(BOOL)canShowCaretMenu;
-(BOOL)changeQuerySettingsTo:(NSUInteger)settingOptionId;
-(NSUInteger)getCurrentQuerySetting;
-(nullable ZMQuerySettingOptions*)getCurrentQuerySettingOption;
-(NSString*)getSettingChangedInfo;
-(ZMAIDynamicNotifier*)getAINotifier;
-(BOOL)isAICompanionNoticeActive;
-(BOOL)needShowAICPreviewTip;
-(void)setClientLangId;

- (BOOL)isAICFeaturesOn;
- (BOOL)isAICFeaturesOff;
- (BOOL)isAICFeaturesOffExceptSmartRecord;
- (BOOL)isAICFeaturesOnExceptSmartRecord;
- (BOOL)isSummaryOn;
- (BOOL)isQueryOn;
- (BOOL)isSmartRecordingOn;
- (BOOL)onlySmartRecordingOnAndForbidStop;
- (BOOL)turnOffAICompanionByHostCohost:(long long)aicOption deleteAssets:(BOOL)deleteAssets;
- (BOOL)turnOffAICompanionByAttendee:(long long)aicOption deleteAssets:(BOOL)deleteAssets;
- (BOOL)requestToSwitchAICompanion:(long long)aicOption switchAction:(NSInteger)switchAction;
- (BOOL)isAICompanionTurnOffFlowEnabled;
- (BOOL)isAICompanionTurnOnFlowEnabled;
- (void)agreeTurnOffAICompanionBeforeHostJoin:(long long)aicOption;
- (BOOL)isAICompanionAssetsDeleted:(NSInteger)gatewayType;
- (BOOL)turnOnAllAICompanion;
- (BOOL)AICFeaturesCanTurnOff;

- (BOOL)respondToSwitchAICompanion:(NSString *)reqId senderId:(ZMUserID)senderId switchAction:(NSInteger)switchAction agree:(BOOL)agree;
@end

NS_ASSUME_NONNULL_END
