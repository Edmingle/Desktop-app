//
//  ZMAlertViewController.h
//  ZCommonUI
//
//  Created by francis zhuo on 2019/9/12.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomKit/ZMBaseView.h>
#import <ZoomKit/ZMButton.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMAlertProtocol;
typedef void (^ZMAlertAction)(id<ZMAlertProtocol> alert, BOOL* closeWindow);

@class ZMCheckButton;
@class ZMButton;
@protocol ZMAlertProtocol<NSObject>

@property(retain)NSImage* imageIcon;

@property(nonatomic, retain, readonly)NSView* titleBar;
@property(nonatomic, retain, readonly)NSTextField* titleField;
@property(retain)NSString* titleText;
@property(retain)NSAttributedString* attributedTitleText;
@property(assign)BOOL showTitleBarLine;

@property(assign)BOOL supportWrapsMessage;
@property(retain)NSString* messageText;
@property(retain)NSAttributedString* attributedMessageText;

@property(retain)NSString* infomationText;
@property(retain)NSAttributedString* attributedInfomationText;
@property(assign)BOOL supportHyperlinks;

@property(readonly,retain)NSButton* checkButton;

@property(retain, nullable)id representedObject;

@property (nonatomic, copy, nullable) NSEvent *_Nullable(^keyPressHandler)(NSEvent *_Nonnull);

- (void)setMinSize:(NSSize)minSize;
- (void)setMaxSize:(NSSize)maxSize;
- (void)setContentMargin:(NSEdgeInsets)margin;

- (void)resetAlert;
- (void)resetAlertWithAccessoryView; //!remove AccessoryView

//contentView
- (void)setContentStackViewMargin:(NSEdgeInsets)margin;

//add button/custom view into button bar
- (NSButton*)addCheckButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction;

- (ZMButton*)addButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction isDefault:(BOOL)isDefaultButton layoutDirection:(ZMLayoutDirection)layoutDirection;
- (ZMButton*)addButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction;
- (ZMButton*)addButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction style:(ZMButtonColorStyle)style needKeyEquivalent:(BOOL)needKeyEquivalent layoutDirection:(ZMLayoutDirection)layoutDirection;

- (ZMButton*)addButtonWithTitle:(NSString*)title target:(id)target action:(SEL)action isDefault:(BOOL)isDefaultButton layoutDirection:(ZMLayoutDirection)layoutDirection;

- (NSButton*)addCustomButton:(NSButton*)button actionBlock:(nullable ZMAlertAction)blockAction layoutDirection:(ZMLayoutDirection)layoutDirection;

- (NSView*)addCustomView:(NSView*)view layoutDirection:(ZMLayoutDirection)layoutDirection;

- (void)setButtonBarSpacing:(CGFloat)spacing layoutDirection:(ZMLayoutDirection)layoutDirection;

//add custom view into content view(under infomation text field)
- (void)setAccessoryMargin:(NSEdgeInsets)margin;
- (void)setAccessorySpacing:(CGFloat)spacing;
- (void)setAccessoryAlignment:(NSLayoutAttribute)alignment;
- (ZMCheckButton*)addCheckButtonInAccessoryViewWithTitle:(NSString*)title identifier:(NSString*)identifier target:(id)target action:(SEL)action;
- (void)addAccessoryView:(NSView*)view;
- (void)removeAccessoryView:(NSView*)view;
- (void)setMessageFont:(NSFont *)font;
- (__kindof NSView*)viewWithIdentifier:(NSString*)identifier;

//accessibility
- (NSString*)accessibilityLabel;
@end

@interface ZMAlertViewController : NSViewController<ZMAlertProtocol>
- (void)cleanUp;
@end

@interface NSImage(ZMAlert)
+ (NSImage*)zoomIcon;
+ (NSImage*)zoomWarningIcon;
+ (NSImage*)zoomErrorIcon;
@end

NS_ASSUME_NONNULL_END
