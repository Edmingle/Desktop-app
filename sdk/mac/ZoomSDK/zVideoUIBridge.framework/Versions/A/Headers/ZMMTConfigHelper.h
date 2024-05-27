//
//  ZMMTConfigHelper.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 2/16/23.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTConfigHelper : ZMBaseHelper

@property (nonatomic, assign) BOOL hideChatPreview;
@property (nonatomic, assign) ZMMTVideoSortType videoOrderSortType;

@property (nonatomic, assign) BOOL showMainWindowWhenSharing;
@end

NS_ASSUME_NONNULL_END
