//
//  ZMIMInputCustomButtonCellView.h
//  zChatComponent
//
//  Created by Yong Zhou on 10/25/22.
//

#import <ZoomUnit/ZoomUnit.h>

@class ZMIMInputCustomButtonItem;

NS_ASSUME_NONNULL_BEGIN

@interface ZMIMInputCustomButtonCellView : ZMBaseTableCellView

@property (nonatomic, retain) ZMIMInputCustomButtonItem *item;

@end

@interface ZMIMInputCustomButtonSystemSeparateLineCell : NSTableCellView

@property (nonatomic, retain, nullable) ZMIMInputCustomButtonItem *item;

@end

@interface ZMIMInputCustomButtonSystemDescCell : NSTableCellView

@property (nonatomic, retain, nullable) ZMIMInputCustomButtonItem *item;

@end

NS_ASSUME_NONNULL_END
