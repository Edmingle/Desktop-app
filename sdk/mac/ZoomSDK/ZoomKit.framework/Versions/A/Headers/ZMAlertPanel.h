//
//  ZMAlertPanel.h
//  ZCommonUI
//
//  Created by francis zhuo on 2019/9/12.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomKit/ZMAlertViewController.h>
#import <ZoomKit/ZMPlainWindow.h>

@interface ZMAlertPanel : ZMPlainPanel<ZMAlertProtocol>
@property(nonatomic,assign) BOOL constraintWithScreenFrame;//default is YES
- (void)cleanUp;

@property(retain)NSImage* imageIcon;

@property(retain)NSString* messageText;
@property(retain)NSAttributedString* attributedMessageText;

@property(retain)NSString* infomationText;
@property(retain)NSAttributedString* attributedInfomationText;
@property(assign)BOOL supportHypperLinks;

@property(readonly,retain)NSButton* checkButton;

@property(copy) ZMAlertAction escBlock;
@property(copy) ZMAlertAction clickCloseButtonBlock;
/// closeBlock used for all close window action. The default closeWindow in ZMAlertAction is YES;
@property(copy) ZMAlertAction closeBlock;

@property(retain)id representedObject;
- (void)resetAlert;
- (void)setMessageFont:(NSFont *)font;
//add button/custom view into button bar
- (NSButton*)addCheckButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction;

- (ZMButton*)addButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction isDefault:(BOOL)isDefaultButton layoutDirection:(ZMLayoutDirection)layoutDirection;
- (ZMButton*)addButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction;
- (ZMButton*)addButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction type:(ZMButtonColorStyle)type needKeyEquivalent:(BOOL)needKeyEquivalent layoutDirection:(ZMLayoutDirection)layoutDirection;

- (ZMButton*)addButtonWithTitle:(NSString*)title target:(id)target action:(SEL)action isDefault:(BOOL)isDefaultButton layoutDirection:(ZMLayoutDirection)layoutDirection;

- (NSButton*)addCustomButton:(NSButton*)button actionBlock:(ZMAlertAction)blockAction layoutDirection:(ZMLayoutDirection)layoutDirection;

- (NSView*)addCustomView:(NSView*)view layoutDirection:(ZMLayoutDirection)layoutDirection;

//add custom view into content view(under infomation text field)
- (void)setAccessoryAlignment:(NSLayoutAttribute)alignment;
- (ZMCheckButton*)addCheckButtonInAccessoryViewWithTitle:(NSString*)title identifier:(NSString*)identifier;
- (ZMCheckButton*)addCheckButtonInAccessoryViewWithTitle:(NSString*)title
                                              identifier:(NSString*)identifier
                                                  target:(id)target
                                                  action:(SEL)action;
- (void)addAccessoryView:(NSView*)view;
- (void)removeAccessoryView:(NSView*)view;

- (__kindof NSView*)viewWithIdentifier:(NSString*)identifier;

@end
