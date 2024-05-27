//
//  ZMTextBubbleObject.h
//  ZCommonUI
//
//  Created by Francis Zhuo on 2/25/21.
//  Copyright © 2021 zoom. All rights reserved.
//

#import <ZoomKit/ZMBubbleObject.h>

NS_ASSUME_NONNULL_BEGIN
@interface ZMTextBubbleConfig : ZMBubbleConfig
@property(retain, nullable) NSColor* textColor;
@property(retain, nullable) NSFont* textFont;//defalut systemFontOfSize:12
@property(assign) NSTextAlignment textAlignment;//default NSTextAlignmentCenter
@end

@interface ZMTextBubbleObject : ZMBubbleObject
@property(retain) ZMTextBubbleConfig* config;
@property(nullable, nonatomic, retain) NSString* bubbleText;
@property(nullable, nonatomic, retain) NSAttributedString* attributedBubbleText;
@property(nonatomic, assign) BOOL supportHyperlinks;
@end

NS_ASSUME_NONNULL_END
