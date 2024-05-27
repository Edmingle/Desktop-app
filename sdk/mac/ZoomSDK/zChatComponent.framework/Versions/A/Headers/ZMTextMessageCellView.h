//
//  ZMTextMessageCellView.h
//  zChatUI
//
//  Created by groot.ding on 2019/5/17.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zChatComponent/ZMNTextMessageCellView.h>
#import <zChatComponent/ZMDeepLinkPreviewView.h>
#import <zChatComponent/ZMNTextMessageCellView.h>

@class ZMChatMsgItemTextView;

@interface ZMTextMessageCellView : ZMNTextMessageCellView <ZMDeepLinkPreviewViewDelegate>

@property (nonatomic,retain) ZMChatMsgItemTextView *linkPreviewTextView;

- (void)shouldUpdateLinkPreview;    // ZOOM-310221
- (BOOL)unreadDotIsHidden;
@end
