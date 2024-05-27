//
//  ZMChatsNewMessageReminderButton.h
//  zChatComponent
//
//  Created by Groot Ding on 2022/7/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMChatsNewMessageBubbleButtonStyle)
{
    ZMChatsNewMessageBubbleButtonStyle_Ellipse,
    ZMChatsNewMessageBubbleButtonStyle_SemiellipseUp,
    ZMChatsNewMessageBubbleButtonStyle_SemiellipseDown,
};

typedef NS_ENUM(NSUInteger, ZMChatsNewMessageBubbleAtType)
{
    ZMChatsNewMessageBubbleAtType_None,
    ZMChatsNewMessageBubbleAtType_AtMe,
    ZMChatsNewMessageBubbleAtType_AtMentionGroup,
    ZMChatsNewMessageBubbleAtType_AtAll,
    ZMChatsNewMessageBubbleAtType_MarkUnread,
};

@interface ZMChatsNewMessageBubbleButton : ZMIMBaseButton

@property (nonatomic, assign) BOOL isUpArrow;
@property (nonatomic, assign) NSInteger unreadCount;
@property (nonatomic, assign) NSInteger atCount;
@property (assign) ZMChatsNewMessageBubbleButtonStyle style;
@property (nonatomic, assign) ZMChatsNewMessageBubbleAtType atType;

- (float)fitWidth;

@end

NS_ASSUME_NONNULL_END
