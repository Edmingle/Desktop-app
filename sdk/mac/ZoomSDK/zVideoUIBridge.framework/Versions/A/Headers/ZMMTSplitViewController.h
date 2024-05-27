//
//  ZMMTSplitViewController.h
//  SaasBeeConfUIModule
//
//  Created by Francis Zhuo on 8/15/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMMTBaseViewController.h>
#import <zVideoUIBridge/ZMMTSplitView.h>
#import <zVideoUIBridge/ZMMTSizeScaleFactor.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTSplitViewItem;
@protocol ZMMTSplitViewDelegate <NSObject>
@optional
- (void)splitView:(ZMMTSplitView*)splitView splitItemWillCollapse:(ZMMTSplitViewItem*)splitItem;
- (void)splitView:(ZMMTSplitView*)splitView splitItemDidCollapsed:(ZMMTSplitViewItem*)splitItem;
- (void)splitView:(ZMMTSplitView*)splitView splitItemWillExpand:(ZMMTSplitViewItem*)splitItem;
- (void)splitView:(ZMMTSplitView*)splitView splitItemDidExpanded:(ZMMTSplitViewItem*)splitItem;

@end

@interface ZMMTSplitViewItem : NSObject
@property (readonly) NSView* view;
@property (assign) Class backgroundViewClass;
@property (assign) BOOL canCollapse;
@property (nonatomic, getter=isCollapsed) BOOL collapsed;

@property (nonatomic, assign) Class dividerClass;
@property (nonatomic, assign) CGFloat dividerWidth;

@property (nullable, nonatomic, retain) ZMBaseViewController* viewController;
@property (nullable, nonatomic, retain) NSView* documentView;//recommend use viewController

@property (nonatomic, assign) NSEdgeInsets paddingRatio;//0~1
@property (nonatomic, assign) NSEdgeInsets padding;
@property (nonatomic, assign) NSSize       aspectRatio;//default NSZeroSize, will not take effect

@property (nonatomic, assign) NSSize intrinsicContentSize;
@property (assign) NSSize minimumSize;
@property (assign) NSSize maximumSize;

@property (assign) NSInteger sizePriority;//1~499, default 300
@property (assign) NSInteger resizePriority;//1~499, default 300

- (void)commonInit NS_REQUIRES_SUPER;

@property (assign) BOOL autoSaveViewSizeScale;//default is YES
@property (nonatomic, null_resettable, retain) ZMMTSizeScaleFactor* scaleFactor;
- (void)saveViewSizeScale;
- (void)restoreViewSizeByScale;

- (void)loadDocumentViewIfNeed NS_REQUIRES_SUPER;//for override
@end


@interface ZMMTSplitViewController : ZMMTBaseViewController
@property(retain) ZMMTSplitView* view;
/**
 *dividerClass need based ZMSplitDivider
 *default is ZMSplitDivider
 */

/**
 *Adds a split view item to the end of the splitViewItems array of the split view controller.
 */
- (void)addSplitViewItem:(ZMMTSplitViewItem*)viewItem;

/**
 *Adds a split view item to the splitViewItems array of the split view controller, at a specified index position.
 */
- (void)insertSplitViewItem:(ZMMTSplitViewItem *)splitViewItem atIndex:(NSInteger)index;

/**
 * Removes a specified split view item from the split view controller.
 */
- (void)removeSplitViewItem:(ZMMTSplitViewItem *)splitViewItem;

/**
 Begins a group of updates for the SplitView
 */
- (void)beginUpdates;
/**
 Ends the group of updates for the SplitView
 */
- (void)endUpdates;
@end

NS_ASSUME_NONNULL_END
