//
//  ZMToastCoordinator.h
//  zChatUI
//
//  Created by Huxley on 2019/2/22.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMToastModule) {
    ZMToastModuleUnknown,
    ZMToastModuleZapp,
    ZMToastModuleNotes,
    ZMToastModulePicker,
};

typedef NS_ENUM(NSUInteger, ZMToastType) {
    ZMToastTypeInformation,
    ZMToastTypeConfirmation,
    ZMToastTypeAdvisory,
    ZMToastTypeWarning,
    ZMToastTypeError,
    ZMToastTypeImage,
    ZMToastTypeCustom
};

typedef NS_ENUM(NSUInteger, ZMLoadingOriginType) {
    ZMLoadingOriginTypeDefault,
    ZMLoadingOriginTypeEnd
};

@class ZMToast;
@class ZMZAppInstallInfo;
typedef NSString *_Nonnull(^ZMToastInformationTiming)(ZMToast *sender, NSTimeInterval duration, BOOL *resetDate);

@interface ZMToast : NSObject

- (instancetype)initWithType:(ZMToastType)type;

+ (instancetype)toastWithType:(ZMToastType)type information:(NSString *)information;

+ (instancetype)temporaryToastWithType:(ZMToastType)type information:(NSString *)information;

+ (instancetype)timingToastWithType:(ZMToastType)type informationTiming:(ZMToastInformationTiming)informationTiming;

@property (assign, readonly) ZMToastType type;
@property (assign, nonatomic) ZMToastModule sourceModule;//This is just a marker to distinguish the source of the toast


@property (copy, nullable) NSString *information;//has lower priority than attributedInformation
@property (copy, nullable) NSAttributedString *attributedInformation;//has higher priority than information
@property (copy, nullable) ZMToastInformationTiming informationTiming;
@property (copy, nullable) NSString *actionName;

// will be shown in bold above the description, if any. Not required.
// note that setting a header will increase the width of the toast by 100px, because of the
//  extra line added. This is to avoid overly tall toasts.
@property (copy, nullable) NSString *header;

// used to display a custom image. Must be set if the type is ZMToastTypeImage.
@property (copy, nullable) NSImage *image;

//accessibilityLabel for toast panel
@property (copy, nullable) NSString *panelAccessibilityLabel;

@property (nullable, weak) id target;
@property (nullable, retain) NSObject* context;//!< optional

@property (nullable) SEL action;//!< optional
@property (nullable) SEL closeAction;//!< optional
@property (nullable) SEL clickAction;//!< optional

@property (assign) BOOL alwaysShowCloseButton;
@property (assign) BOOL autoDisappear;//!< will hide close button if autoDisappear is YES & alwaysShowCloseButton is NO
@property (assign, nonatomic) NSTimeInterval remainDuration;//!< default is 3 seconds

@property (retain, nullable) NSString *identifier;

@property (assign) BOOL state;
@property (assign) BOOL showLoading;//!< will hide actionName and show a loading view.
@property (assign) BOOL actionShowPanel;//!< when have "action" and clicked, still show panel when set YES.
@property (assign) BOOL hideCloseButton; //!< just hide close button on all situation.
@property (assign) ZMLoadingOriginType loadingOriginType;
@property (retain, nullable) NSAppearance *appearance;

//Custom
- (instancetype)initWithCustomView:(NSView *)view;
@property (retain, readonly) NSView *view;
//Disappear handlder
@property (copy, nullable) void (^onDisappear)(void);
@end



@protocol ZMToastCoordinatorProtocol <NSObject>

@property (readonly) NSUInteger toastCount;

- (nullable ZMToast *)fetchToastWithIdentifier:(NSString *)identifier;

- (void)addToast:(ZMToast *)toast;
- (void)addToast:(ZMToast *)toast animation:(BOOL)isAnimate;
- (void)removeToast:(ZMToast *)toast;

- (void)removeToastFromSender:(__kindof NSView *)sender;

- (void)updateExistToast:(ZMToast *)toast;

- (void)removeAllToasts;

@end



@interface ZMToastCoordinator : NSObject <ZMToastCoordinatorProtocol>

- (instancetype)initWithWindow:(NSWindow *)window;

- (instancetype)initWithWindow:(NSWindow *)window
                   rightMargin:(CGFloat)rightMargin
                     topMargin:(CGFloat)topMargin
                       spacing:(CGFloat)spacing;

@property (assign) CGFloat rightMargin;
@property (assign) CGFloat topMargin;
@property (assign) CGFloat spacing;
@property (assign) CGFloat originTopMargin;

@property (weak, readonly) NSWindow *window;
@property (assign, getter=isDropdown) BOOL dropdown;
@property (assign) NSPoint preferredOrigin;

@property (copy,nullable) NSColor   * backgroundColor;

@property (copy,nullable) NSColor   *titleColor;

@property (assign) NSUInteger maxCount;//default is 6

@property (readonly) NSUInteger toastCount;

- (nullable ZMToast *)fetchToastWithIdentifier:(NSString *)identifier;

- (void)addToast:(ZMToast *)toast;
- (void)addToast:(ZMToast *)toast animation:(BOOL)isAnimate;
- (void)removeToast:(ZMToast *)toast;

- (void)removeToastFromSender:(__kindof NSView *)sender;

- (void)updateExistToast:(ZMToast *)toast;

- (void)removeAllToasts;

- (void)relayout;
- (void)relayoutAfterAddAnimation;
- (void)relayoutIfNeededWhenWindowBecomeShowing;

- (BOOL)isShowToastWithIdentifier:(NSString *)identifier;
@end

@protocol ZMToastCoordinatorProvider <NSObject>

- (id<ZMToastCoordinatorProtocol>)toastCoordinator;

@end

@interface ZMToastCoordinator (ZApp)
- (void)replaceToast:(ZMToast *)oldToast withToast:(ZMToast *)newToast;
- (NSArray <ZMToast *> *)fetchToastsContainsIdentifier:(NSString *)identifier;
- (void)updatePanelView:(NSString *)appId withInfo:(NSDictionary *)infoDict;
- (void)reloadToasts;
- (void)updateToastView:(NSString *)appId installState:(ZMZAppInstallInfo *)state;
- (void)updateToastView:(NSString *)msgId thumbnailPath:(NSString *)thumbnailPath;
- (void)updateToastViewToGuestType;
- (NSArray *)getToastList;
- (void)removeAllToastsFromModule:(ZMToastModule)sourceModule;
@end

NS_ASSUME_NONNULL_END
