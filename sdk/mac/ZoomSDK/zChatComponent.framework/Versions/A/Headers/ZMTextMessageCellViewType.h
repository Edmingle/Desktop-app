//
//  ZMTextMessageCellViewType.h
//  zChatComponent
//
//  Created by Zoro.Fu on 2023/12/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMTextMessageCellViewType <NSObject>

@property (nonatomic, readonly) NSTextView *messageTextView;

@end

NS_ASSUME_NONNULL_END
