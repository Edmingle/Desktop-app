//
//  ZMPSVirtualBackgroundMgr.h
//  ZoomClips
//
//  Created by Michael Lin on 2023/2/13.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMPSVirtualBackgroundItem;

@interface ZMPSVirtualBackgroundMgr : ZMPSObject

- (void)unregisterSink;
- (void)registerSink;
- (ZMPSVirtualBackgroundItem *)noneItem;
- (ZMPSVirtualBackgroundItem *)blurItem;
- (NSUInteger)vbItemsCount;
- (nullable ZMPSVirtualBackgroundItem *)vbItemAtIndex:(NSUInteger)index;
- (NSArray<ZMPSVirtualBackgroundItem *> *)vbItems;
@property (nonatomic, weak) ZMPSVirtualBackgroundItem *selectedVBItem;

@end

NS_ASSUME_NONNULL_END
