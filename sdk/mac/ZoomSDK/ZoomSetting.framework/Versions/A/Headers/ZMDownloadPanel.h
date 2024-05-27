//
//  ZMDownloadPanel.h
//  ChatUI
//
//  Created by Michael Lin on 2021/12/21.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZMDownloadViewMgrProtocol.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZMDownloadPanel : ZMAlertPanel <ZMDownloadPanelProtocol>

@property (nonatomic, assign) ZMDownloadType downloadType;
@property (nonatomic, strong, readonly) NSArray<NSNumber *> *downloadTypes;
- (void)setDownloadTypes:(NSArray<NSNumber *> *)downloadTypes;
- (void)setWindowTitle:(NSString *)windowTitle;
- (void)setErrorText:(NSString *)messageText;
- (void)updateDownloadStage:(ZMDownloadStage)stage process:(CGFloat)process;

@end

NS_ASSUME_NONNULL_END
