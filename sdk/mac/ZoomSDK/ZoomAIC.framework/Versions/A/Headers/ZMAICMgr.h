//
//  ZMAICMgr.h
//  ZoomAIC
//
//  Created by Howie Xu on 1/14/24.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMAICMgr : NSObject

- (void)addViewToParentView:(NSView *)parentView;

- (void)loadApp:(NSString *)appId;

- (void)cleanUp;

@end

NS_ASSUME_NONNULL_END
