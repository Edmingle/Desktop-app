//
//  IZPAlertManager.h
//  VideoUI
//
//  Created by martin.yu on 9/14/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZPAlertManager_h
#define IZPAlertManager_h

@class ZMAlertPanel;

NS_ASSUME_NONNULL_BEGIN

@protocol IZPAlertManager <ZMRoutableObject>
- (void)showAllowSignLanguageInterpreterToTalkAlert;
- (void)closeAllowSignLanguageInterpreterToTalkAlert;
- (void)closeGiftAlert;

- (void)showZECompanionInterpretationEnableStreamAlertConfirmBlock:(void (^)())confirmAction;

- (void)showArchiveAlert;
- (void)closeArchiveAlert;
- (void)showArchiveFailedAlert;
- (void)closeArchiveFailedAlert;

- (void)showPSProducerNoInterChannelAlert;


- (ZMAlertPanel *_Nullable)alertPanelWithIdentifier:(nullable NSString *)identifier makeIfNecessary:(BOOL)makeIfNecessary;
- (void)closeAlertPanelWithIdentifier:(nullable NSString *)identifier;
- (void)showQADlpCheckAlertWithConfirm:(void(^)())actionConfirm;
- (void)showQADlpBlockAlert;
- (void)closeDLPQACheckAlert;
- (void)closeDLPQABlockAlert;

- (void)showQAConflictAlert;
- (void)showDlpCheckAlertWithConfirm:(void(^)())actionConfirm;
- (void)showDlpBlockAlert:(NSString *)policyName;//policyName is useless

- (void)showWhiteboardBlockShareAlert;

@end

NS_ASSUME_NONNULL_END

#endif /* IZPAlertManager_h */
