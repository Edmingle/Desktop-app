//
//  ZMMessageReactionTooltipMgr.h
//  zChatUI
//
//  Created by likevin on 2019/7/15.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMReactionItemView;


@interface ZMMessageReactionTooltipMgr : NSObject
+ (ZMMessageReactionTooltipMgr*)sharedInstance;
+ (void)releaseInstance;

- (void)showToolTipWithSessionID:(NSString*)inSID messageID:(NSString*)inMsgID reactionView:(ZMReactionItemView*)inReactionView;
- (void)hideTooltipWithReactionView:(ZMReactionItemView*)inReactionView;

- (void)onTooltipWindowDidClosed:(id)sender;
- (void)updateReactionListWithSessionId:(NSString *)sessionId;
@end



@interface ZMReactionTooltipView : NSView
- (void)updateUIWithTooltipArray:(NSArray<NSString*>*) tooltipArray count:(NSInteger)count;
- (void)onWindowDidClosed:(id)sender;
@end
