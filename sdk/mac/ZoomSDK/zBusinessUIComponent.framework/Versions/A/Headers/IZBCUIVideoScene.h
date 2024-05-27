//
//  IZBCUIVideoScene.h
//  zBusinessUIComponent
//
//  Created by Giannis Ge on 2023/10/11.
//

#import <Foundation/Foundation.h>
#import "IZBCUIScene.h"
#import "zBusinessComponent/zbc_video_scene_interface.h"

NS_ASSUME_NONNULL_BEGIN
USING_ZBC_NAMESPACE

@protocol IZBCUIVideoSceneDelegate <IZBCUISceneDelegate>
@optional
- (IZBCVideoSceneHandler *)getVideoSceneHandler:(id<IZBCUIScene>)scene;
- (BOOL)canShowVideoSettingItem:(id<IZBCUIScene>)scene;
@end

@protocol IZBCUIVideoScene <IZBCUIScene>
@property (nonatomic, weak) id<IZBCUIVideoSceneDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
