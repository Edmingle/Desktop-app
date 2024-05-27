//
//  ZMMessageBubbleView.h
//  ZCommonUI
//
//  Created by groot.ding on 21/07/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <ZoomKit/ZMBaseView.h>


NS_ASSUME_NONNULL_BEGIN

@interface ZMMessageBubbleView : ZMBaseView

@property (nonatomic,weak) id target;

@property (nonatomic,assign) SEL mouseDownAction;

@property (nonatomic,assign) NSInteger headLocation;
@property (nonatomic,assign) BOOL hasContent;

@property (nonatomic,assign) float offset;

@end

NS_ASSUME_NONNULL_END
