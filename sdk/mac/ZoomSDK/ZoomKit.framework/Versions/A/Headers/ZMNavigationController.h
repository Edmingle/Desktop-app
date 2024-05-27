//
//  ZMNavigationController.h
//  ZoomUnit
//
//  Created by Michael Lin on 2023/5/15.
//

#import <Cocoa/Cocoa.h>
#import <ZoomKit/ZMBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMNavigationController : ZMBaseViewController

@property (nonatomic, strong) NSViewController *rootViewController;

@property (nonatomic, readonly) NSViewController *topViewController;

- (id)initWithRootViewController:(NSViewController *)rootViewController;
- (void)pushViewController:(NSViewController *)viewController;

- (nullable NSViewController *)popViewController;

- (void)removeViewController:(NSViewController *)viewController;

- (nullable NSArray <NSViewController *> *)popToRootViewController;

- (nullable NSArray <NSViewController *> *)popToViewController:(NSViewController *)viewController;

- (nullable NSArray <NSViewController *>*)viewControllers;

@end

NS_ASSUME_NONNULL_END
