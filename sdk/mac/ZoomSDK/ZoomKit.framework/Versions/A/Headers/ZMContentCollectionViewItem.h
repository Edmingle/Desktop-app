//
//  ZMContentCollectionViewItem.h
//  ChatUI
//
//  Created by Michael Lin on 2023/6/25.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMBaseView, ZMTrackingView;
@interface ZMContentCollectionViewItem : NSCollectionViewItem

- (void)configUI;
- (void)refreshUI;
- (void)updateAccessibilityDescription;
@property (nonatomic, copy) NSString *zmAccessibilityPosition;
@property (nonatomic, copy) NSString *zmAccessibilityValue;
@property (nonatomic, setter=setZMSelected:, getter=isZMSelected) BOOL zmSelected;
@property (setter=setZMHovered:, getter=isZMHovered) BOOL zmHovered;
@property (nonatomic, strong) ZMTrackingView *trackingView;

@end

NS_ASSUME_NONNULL_END
