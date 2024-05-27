//
//  ZMJumpToBtn.h
//  zChatComponent
//
//  Created by Groot Ding on 2022/7/16.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger{
    ZMJumpType_LastestMsg,
    ZMJumpType_FirstUnreadMsg,
}ZMJumpType;

@interface ZMJumpToBtn : ZMButton

@property (assign) ZMJumpType jumpType;

+ (ZMJumpToBtn*)newJumpToBtn;

- (void)updateToType:(ZMJumpType)type;

- (void)updateArrowToUp:(BOOL)isUp;

@end

NS_ASSUME_NONNULL_END
