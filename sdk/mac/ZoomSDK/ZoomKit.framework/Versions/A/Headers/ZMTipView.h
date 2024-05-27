//
//  ZMMTTipView.h
//  VideoUIBridge
//
//  Created by martin yu on 2023/12/16.
//

#import <Cocoa/Cocoa.h>
#import <ZoomKit/ZMBaseView.h>
#import <ZoomKit/ZMButton.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMTipView;
typedef void(^ZMTipActionBlock)(ZMTipView *aTipView, ZMButton *sender);

@interface ZMTipView : ZMBaseView
@property (nonatomic, assign) NSEdgeInsets edgeInsets;

@property (nonatomic, strong, nullable) NSView *headIconView;
@property (nonatomic, strong, nullable) NSString *title;
@property (nonatomic, strong) NSFont *titleFont;
@property (nonatomic, strong) NSColor *titleColor;
@property (nonatomic, strong, nullable) NSAttributedString *attributedTitle;
@property (nonatomic, assign) BOOL needCloseButton;
@property (nonatomic, copy, nullable) ZMTipActionBlock closeActionBlock;

@property (nonatomic, strong, nullable) NSString *desc;
@property (nonatomic, strong) NSColor *descColor;
@property (nonatomic, strong) NSFont *descFont;
@property (nonatomic, strong, nullable) NSAttributedString *attributedDesc;
- (void)addAccessoryView:(NSView *)view;

- (ZMButton *)addLeftButtonWithTitle:(NSString *)title actionBlock:(ZMTipActionBlock)actionBlock;
- (ZMButton *)addRightButtonWithTitle:(NSString *)title isDefault:(BOOL)isDefault actionBlock:(ZMTipActionBlock)actionBlock;

#pragma mark - Spacing
@property (nonatomic, assign) CGFloat spacingAfterDesc; // Default is 10
@property (nonatomic, assign) CGFloat buttonSpacing; // Default is 10
@end

@compatibility_alias ZMMTTipView ZMTipView;

NS_ASSUME_NONNULL_END
