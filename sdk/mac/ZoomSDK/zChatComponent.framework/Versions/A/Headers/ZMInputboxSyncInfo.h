//
//  ZMInputboxSyncInfo.h
//  zChatComponent
//
//  Created by Yong Zhou on 2/20/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMInputBoxLinkInfoSyncedResult : NSObject

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *link;
@property (nonatomic, copy) NSString *sessionID;
@property (nonatomic, copy) NSString *requireID;

@end

NS_ASSUME_NONNULL_END
