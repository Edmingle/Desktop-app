//
//  ZMTableViewUtilCellView.h
//  zChatUI
//
//  Created by groot.ding on 2018/11/7.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMBaseTableCellView.h>

typedef enum : NSUInteger {
    ZMUtilCellViewTextOnly = 1,
    ZMUtilCellViewLoadingAnimationOnly,
    ZMUtilCellViewLoadingTextBottom
} ZMUtilCellViewStyle;

@protocol ZMTableViewUtilProtocal <NSObject>

@optional
- (NSString *)title;

- (NSFont *)titleFont;
- (NSColor *)titleColor;
- (NSTextAlignment)titleAlignment;
- (NSMutableAttributedString *)attributedTitle;

- (BOOL)needSplitLine;

- (NSEdgeInsets)contentEdgeInsets;
- (NSEdgeInsets)splitLineEdgeInsets;

- (ZMUtilCellViewStyle)cellViewStyle;
@end

@interface ZMTableViewUtilInfo : NSObject <ZMTableViewUtilProtocal>

@property (nonatomic,retain) NSFont *titleFont;
@property (nonatomic,copy) NSString *title;
@property (nonatomic,retain) NSColor *titleColor;

@property (nonatomic,retain) NSMutableAttributedString *attributedTitle;

@property (nonatomic,assign) NSTextAlignment titleAlignment;

@property (nonatomic,assign) BOOL needSplitLine;

@property (nonatomic,assign) NSEdgeInsets contentEdgeInsets;
@property (nonatomic,assign) NSEdgeInsets splitLineEdgeInsets;

@property (nonatomic,assign) ZMUtilCellViewStyle cellViewStyle;

+ (instancetype)utilWithStyle:(ZMUtilCellViewStyle)style;

@end

@interface ZMTableViewUtilCellView : ZMBaseTableCellView

+ (CGFloat)heightOfInfo:(id <ZMTableViewUtilProtocal>)info maxWidth:(CGFloat)maxWidth;

@end
