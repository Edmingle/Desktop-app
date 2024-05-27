//
//  ZMMenuConfig.h
//  ZoomKit
//
//  Created by Ado Du on 2021/12/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ZMHMenuAppearanceSystem,
    ZMHMenuAppearanceLight,
    ZMHMenuAppearanceDark,
} ZMHMenuAppearance;

@interface ZMMenuConfig : NSObject

+ (ZMMenuConfig *)defaultConfig; /**< init config */

#pragma mark ====== menu ======
@property (nonatomic, assign) ZMHMenuAppearance appearance; /**< default is ZMHMenuAppearanceSystem */
@property (nonatomic, retain, nullable) NSColor *menuBackgroundColor; /**< menu backgroundColor, default is zmBackgroundColor */

@property (nonatomic, assign) NSSize menuMaxSize;
@property (nonatomic, assign) NSSize subMenuMaxSize;
@property (nonatomic, assign) NSEdgeInsets menuEdgePaddings; /**< default is {7, 0, 7, 0} */

#pragma mark ====== item ======
@property (nonatomic, retain,nullable) NSFont *itemTitleFont; /**< default is [NSFont systemFontOfSize:13] */
@property (nonatomic, retain,nullable) NSColor *itemTitleColor; /**< default is zmPriTextColor */
@property (nonatomic, retain,nullable) NSColor *itemTitleHighlightColor; /**< default is zmWhiteColor */
@property (nonatomic, retain,nullable) NSColor *itemSubtitleColor; /**< default is zmGreyColor */
@property (nonatomic, retain,nullable) NSColor *itemSubtitleHighlightColor; /**< default is zmWhiteColor */
@property (nonatomic, retain,nullable) NSColor *itemSelectBackgroundColor; /**< default check color */
@property (nonatomic, retain,nullable) NSColor *itemHighlightBackgroundColor; /**< hover color */

@property (nonatomic, assign) NSEdgeInsets itemMargin; /**< default is {6, 16, 6, 16} */
@property (nonatomic, assign) CGFloat itemMinWidth;

@end

NS_ASSUME_NONNULL_END
