//
//  ZMZAppToastView.h
//  ZCommonUI
//
//  Created by Peter Xu on 2021/7/4.
//  Copyright © 2021 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZPZAppAdapter.h>
#import <ZoomKit/ZMBaseView.h>
#import <ZoomKit/ZMButton.h>
#import <ZoomKit/ZMTextView.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMZAppToastInfo;
typedef NS_ENUM(NSUInteger, ZMZAppToastViewType) {
    ZMZAppToastViewTypeInformation,
    ZMZAppToastViewTypeConfirmation,
    ZMZAppToastViewTypeSelection,
    ZMZAppToastViewTypeNotAuthentication,
    ZMZAppToastViewTypeClose,
    ZMZAppToastViewTypeMeetingChat,
    ZMZAppToastViewTypeMeetingChatNotAuthentication,
    ZMZAppToastViewTypeAppsDisableInvalidGuest,
    ZMZAppToastViewTypeFilePickerRequestEamil,
    ZMZAppToastViewTypeFilePicker,
    ZMZAppToastViewTypeFilePickerFailed,
};

@interface ZMZAppToastView : ZMNonLayerBaseView
@property (nonatomic, copy, nullable) void (^onConfirmAction)(id);
@property (nonatomic, copy, nullable) void (^onCancelAction)(id);
@property (nonatomic, retain, nullable) ZMButton *confirmButton;
@property (nonatomic, assign) ZMZAppToastViewType viewType;
@property (nonatomic, copy, nullable) NSString* (^onGetLinkAction)(NSUInteger linkType);
@property (nonatomic, retain, nullable) ZMZAppToastInfo *representObject;
@property (nonatomic, weak) id <ZMZappNotificationDelegate> notiDelegate;
+ (instancetype)toastViewWithString:(NSString *)string type:(ZMZAppToastViewType)type;
+ (instancetype)toastWithRepresentObject:(id)representObject type:(ZMZAppToastViewType)type;
- (NSAttributedString *)policyAttributedString:(nullable NSString *)clickButtonTitle;

- (void)updatePanelView:(NSString *)appId withInfo:(NSDictionary *)infoDict;
- (void)updatePanelInfo:(NSDictionary *)infoDict;
- (void)updateToastView:(NSString *)msgId thumbnailPath:(NSString *)thumbnailPath;

- (void)updateToastPolicyTitleAndLinkUrl:(nullable NSString *)clickButtonTitle;
- (ZMZAppToastViewType)getViewType;
- (void)updateToastViewByInfo:(ZMZAppToastInfo *)appInfo viewType:(ZMZAppToastViewType)viewType;
- (void)updateToastViewToGuestType;
- (void)updateDisableInvalidGuestAttributedString;
@end

@interface ZMZappToastTextView : ZMTextView

@property (nonatomic,copy,nullable) NSString *accessibilityString;

@end

@interface ZMZappToastLinkTextField : ZMTextView

@end

@interface ZMZappToastCell : NSTextAttachmentCell
@property(copy,nullable) NSString* appName;
@property(copy,nullable) NSString* appCompanyName;
@property(copy,nullable) NSString* appId;
@property (retain,nullable) NSImage *appIcon;
@property(assign) NSRect appNameRect;
@property(assign) NSRect appCompanyNameRect;
@property (retain,nullable) NSImage *betaIcon;
@property (retain,nullable) NSColor *bgColor;
@property(weak) ZMZAppToastView* parentView;
@property (assign) BOOL isCustomCompany;

@end

@interface ZMZAppToastView (newChat)

- (void)updateToastViewByInfoAuto:(ZMZAppToastInfo *)appInfo viewType:(ZMZAppToastViewType)viewType; //using autoLayout
- (void)addPolicyTitleHeight:(CGFloat)height;
@end

@interface ZMZAppImageTextView : ZMBaseView

@property(nonatomic, assign)CGFloat topMargin;
@property(nonatomic, assign)CGFloat leftMargin;
@property(nonatomic, assign)CGFloat bottomMargin;
@property(nonatomic, assign)CGFloat rightMargin;
@property(nonatomic, assign)CGFloat imgTextMargin;
@property(nonatomic, assign)CGFloat minWidth;

@property(nonatomic, copy, nullable)NSString *appId;
@property(nonatomic, retain, nullable)NSImage *appImage;
@property(nonatomic, copy, nullable)NSString *title;
@property(nonatomic, retain, nullable) NSFont *titleFont;
@property(nonatomic, retain, nullable) NSColor *textColor;

- (void)updateUI;

@end

NS_ASSUME_NONNULL_END
