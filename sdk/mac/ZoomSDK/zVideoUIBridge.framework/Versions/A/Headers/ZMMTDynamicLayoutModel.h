//
//  ZMMTDynamicLayoutModel.h
//  VideoUIBridge
//
//  Created by Jun Pang on 1/18/24.
//

#import <Foundation/Foundation.h>

#define MakeMTDLRect(rect, cornerMask) [ZMMTDLRect buildMTDLRect:rect cornerType:cornerMask]

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTDLRect : NSObject

@property (nonatomic) NSRect rect;
@property (nonatomic) NSRectCorner cornerMask;

+(instancetype)buildMTDLRect:(NSRect)rect cornerType:(NSRectCorner)cornerMask;

@end

NS_ASSUME_NONNULL_END
