//
//  ZMMTGridCellView.h
//  zVideoUI
//
//  Created by Francis Zhuo on 9/24/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN
@class ZMMTGridView;
@interface ZMMTGridCellView : ZMTrackingView
@property(weak) ZMMTGridView* gridView;
@property(readonly, assign) BOOL selected;

- (void)updateUI;
- (void)selectedStatusChanged:(BOOL)isSelected;//for override
@end

NS_ASSUME_NONNULL_END
