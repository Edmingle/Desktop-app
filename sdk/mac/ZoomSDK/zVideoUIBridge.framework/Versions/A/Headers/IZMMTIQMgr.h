//
//  IZMMTIQMgr.h
//  VideoUIBridge
//
//  Created by Jun Pang on 7/14/23.
//

#ifndef IZMMTIQMgr_h
#define IZMMTIQMgr_h

@class ZMQueryResponse;
@protocol IZMMTIQMgr <ZMRoutableObject>

@optional
- (void)updateDisableButton;
- (BOOL)isQueriesViewShowing;
- (void)openQueriesPanel;
- (void)closeQueriesPanel;
- (void)onStopQueriesButtonClicked;
- (void)showPopup;
- (void)onToggleMiniMode;
- (void)onWindowDidEnterFullScreen;
- (void)onWindowDidExitFullScreen;
- (void)showRequestEnableQueriesPanelIfNeed;
- (void)showAttendeeRequestStartPanelIfNeed;
- (void)showAdminReceiveRequestPanelIfNeed:(ZMUserID)senderId enableBySelf:(BOOL)isBySelf;
- (void)setIsPopout:(BOOL)isPopout;
- (void)showTurnOffPanelIfNeed:(NSString *)reqId
                      senderId:(ZMUserID)senderId
                     aicOption:(long long)aicOption
                  actionBySelf:(BOOL)isBySelf
                 includeRecord:(BOOL)includeRecord;

- (void)refreshTurnOffPanel;
- (void)refreshTurnOnPanel;
- (void)refreshTurnOnAgainPanel;
- (void)onTurnOffButtonClicked;
- (void)showTurnOnPanelIfNeed:(ZMUserID)senderId enableBySelf:(BOOL)isBySelf;
- (void)onTurnOnAllButtonClicked;
- (void)showAICStartTipIfNeeded:(BOOL)ignoreConfReady;
- (void)hideAICStartTip;
- (void)showAICStopTipIfNeeded;
- (void)hideAICStopTip;

@end

@protocol IZMMTIQEvent <NSObject>

@optional
- (void)onQueryRequestResponseReceived:(BOOL)isTimeOut response:(ZMQueryResponse*)response;
- (void)onReceiveRequestToEnableQueryMsg:(ZMUserID)senderId;
- (void)onReceiveRequestToStartQueriesMsg:(NSString *)reqId senderId:(ZMUserID)senderId;
- (void)onQuerySwitchStatusChanged:(BOOL)enable;
- (void)onReceiveStartQueryResponseMsg:(BOOL)agree timeout:(BOOL)timeout;
- (void)onReceiveSwitchAICResponseMsg:(BOOL)timeout agree:(BOOL)agree switchAction:(NSInteger)switchAction;
- (void)onReceiveSwitchAICRequestMsg:(NSString *)reqId
                            senderId:(ZMUserID)senderId
                           aicOption:(long long)aicOption
                        switchAction:(NSInteger)switchAction;
@end

#endif /* IZMMTIQMgr_h */
