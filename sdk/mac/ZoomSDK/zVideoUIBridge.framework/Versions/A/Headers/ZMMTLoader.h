//
//  ZMMTLoader.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/7/4.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMMTSessionObject.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZMMTLoader : NSObject
@property(readonly, retain) ZMMTSessionObject* sessionObject;
+ (instancetype)shared;

- (void)initLoaderWithSessionObjct:(ZMMTSessionObject*)sessionObject;

- (void)onConfMgrReady;

- (void)uninitLoader;
@end

NS_ASSUME_NONNULL_END
