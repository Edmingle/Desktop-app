//
//  ZMDeepLinkPreviewView.h
//  zChatComponent
//
//  Created by Felipe Bastos on 6/8/22.
//

#import <ZoomKit/ZoomKit.h>
#import <zChatComponent/ZMDeepLinkEntity.h>

@protocol ZMDeepLinkPreviewViewDelegate <NSObject>
- (void)notifyDeepLinkPreviewViewSizeUpdated:(id _Nonnull)sender;
- (void)notifyDeepLinkPreviewExpandedOrCollapsed:(id _Nonnull)sender;
- (nullable NSMutableDictionary<NSString *, NSNumber *> *)deepLinkPreviewsAreCollapsed;

@end

@interface ZMDeepLinkPreviewCollapseButton : ZMButton

@property (nonatomic, assign) BOOL isCollapsed;

@end

@interface ZMDeepLinkPreviewView : ZMBaseView

@property (nonatomic, weak) id<ZMDeepLinkPreviewViewDelegate> _Nullable delegate;

@property (nonatomic, nullable, retain) ZMDeepLinkEntity *entity;
@property (nullable, retain) NSView *linkTypeView; // icon + text, private/public/muc
@property (nullable, retain) NSView *titleView;
@property (nullable, retain) NSTextView *descriptionView;
@property (nullable, retain) NSTextView *optionalDetailView;
@property (nullable, retain) NSImageView *imageView;
@property (nullable, retain) NSProgressIndicator *progressIndicator;

@property (nullable, retain) NSLayoutConstraint *minWidthConstraint;
@property (nullable, retain) NSLayoutConstraint *maxWidthConstraint;
@property (nullable, retain) NSLayoutConstraint *preferredWidthConstraint;
@property (nullable, retain) NSLayoutConstraint *heightConstraint;
@property (nonatomic, assign) NSUInteger maximumSuperviewWidth;

@property (nonatomic, assign) BOOL isHovered;

// is the message whose link we're previewing a response in a thread? If so, we need to shrink by 20px
@property (assign) BOOL isAttachedToReplyMessage;

@property (nullable, retain) ZMDeepLinkPreviewCollapseButton *collapseButton;
@property (nonatomic, assign) BOOL isCollapsed;

@property (nonatomic, assign) BOOL hasContentAbove;
@property (nonatomic, assign) BOOL hasContentBelow;

@property (nonatomic, retain, nullable) CAShapeLayer *borderLayer;

- (instancetype _Nullable)initWithEntity:(ZMDeepLinkEntity *_Nonnull)url collapsed:(BOOL)isCollapsed attachedToReply:(BOOL)isReply;

- (NSSize)updateContentSizeWithMaxWidth:(NSUInteger)maxWidth;
- (NSSize)updateContentSize;

- (void)setEntity:(ZMDeepLinkEntity *_Nonnull)entity;

- (BOOL)isCollapsed;

@end
