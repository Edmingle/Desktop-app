//
//  ZMTableViewMenu.h
//  ZCommonUI
//
//  Created by likevin on 12/12/17.
//  Copyright © 2017 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class ZMNoFocusRingScrollView;
@class ZMTableViewMenuView;

@protocol ZMTableViewMenuViewDelegate <NSObject>
@optional
- (void)tableViewMenuView:(ZMTableViewMenuView *)menuView selectItemTitle:(NSString *)title;

@end
@interface ZMTableViewMenuView : NSView<NSTableViewDelegate, NSTableViewDataSource>{
    NSUInteger                      _radius;
    ZMNoFocusRingScrollView*        _scrollView;
    NSTableView*                    _tableView;
    NSMutableArray*                 _dataArray;
    NSTrackingArea*                 _area;
}
- (void)cleanUp;
- (void)updateDataArray:(NSArray*)array;
- (void)updateUI;
- (void)tryToScroll:(NSString*)tmpString;
- (NSString*)selectedItemString;
- (void)selectDownOne;
- (void)selectUpOne;
@property (nonatomic, weak) id<ZMTableViewMenuViewDelegate> delegate;
@property (nonatomic, assign) CGFloat leftPadding;
@property (nonatomic, assign) CGFloat borderWidth;
@property (nonatomic, assign) CGFloat rowHeight;
@property (nonatomic, retain) NSColor *borderColor;
@property (nonatomic, retain) NSColor *bgColor;
@property (nonatomic, retain) NSColor *selectionColor;
@property (nonatomic, assign) BOOL showDark;
@end

@interface ZMTableViewMenu : NSWindow{
    ZMTableViewMenuView*    _menuView;
}
- (void)cleanUp;
- (ZMTableViewMenuView*)menuView;
@end
