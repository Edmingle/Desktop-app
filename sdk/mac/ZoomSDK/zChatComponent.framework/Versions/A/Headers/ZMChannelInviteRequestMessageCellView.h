//
//  ZMChannelInviteRequestMessageCellView.h
//  zChatComponent
//
//  Created by Felipe Bastos on 6/22/22.
//

#import <Foundation/Foundation.h>

#import <zChatComponent/ZMIMAvatarView.h>
#import <zChatComponent/ZMBaseMessageCellView.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMChannelInviteRequestBubbleView : ZMBaseView

@property (nonatomic, strong) NSTextField *descriptionField;
@property (nonatomic, strong) NSButton *acceptButton;
@property (nonatomic, strong) NSButton *declineButton;

@end

@interface ZMChannelInviteRequestMessageCellView : ZMBaseMessageCellView

@property (nonatomic, strong) ZMIMAvatarView *avatarView;
@property (nonatomic, strong) NSView *headerView;
@property (nonatomic, strong) ZMChannelInviteRequestBubbleView *bubbleView;
@property (nonatomic, strong) NSLayoutConstraint *bubbleViewWidthConstraint;
@property (nonatomic, strong, nullable) ZMButton *acceptButton;
@property (nonatomic, strong, nullable) ZMButton *cancelButton;
@property (nonatomic, strong, nullable) NSProgressIndicator *progressIndicator;
@property (assign) BOOL isActionPending;

@end

NS_ASSUME_NONNULL_END
