//
//  ZMMTStudioSceneResourceModel.h
//  VideoUIBridge
//
//  Created by Brace Liu on 2023/11/15.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMMTStudioConstants.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTStudioSceneResourceModel : NSObject
@property(nonatomic, assign) ZMMTStudioSceneContentType type;
@property (nonatomic, copy) NSString *path;

@end

NS_ASSUME_NONNULL_END
