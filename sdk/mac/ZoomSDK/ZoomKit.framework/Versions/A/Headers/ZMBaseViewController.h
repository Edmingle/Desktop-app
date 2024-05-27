//
//  ZMBaseViewController.h
//  zChatUI
//
//  Created by Huxley Yang on 2018/2/8.
//  Copyright © 2018年 Zipow. All rights reserved.
//

#import <ZoomKit/ZMBaseKit.h>

@interface ZMBaseViewController : NSViewController <ZMViewProviding>

@property (readonly, class, nonatomic) Class viewClass;

- (void)viewDidLoad;
@property (readonly, getter=isViewLoaded) BOOL viewLoaded;

@property BOOL manuallyMaintainViewLifeCircle; //return YES if OS Version < 10.10

- (void)effectiveAppearanceDidChange:(NSAppearance *)appearance;

@end
