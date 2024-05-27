//
//  ZMChatMsgItemTextView.h
//  zChatUI
//
//  Created by likevin on 2018/6/12.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomKit/ZMMutableSelectProtocal.h>
#import <ZoomKit/ZMTextView.h>

@class ZMChatMsgItemInfo;

@protocol ZMChatMessageTextView <ZMTextViewDelegate>

- (void)textView:(ZMTextView *)textView hoverAttributes:(NSDictionary *)attributes charIndex:(NSInteger)charIndex;
- (void)textView:(ZMTextView *)textView hoverAttachmentCell:(id<NSTextAttachmentCell>)cell charIndex:(NSInteger)charIndex;
- (void)textView:(ZMTextView *)textView hoverMentionsName:(NSString *)jid messageItem:(ZMChatMsgItemInfo *)messageInfo relativeRect:(NSRect)rect;

- (void)textView:(ZMTextView *)textView sendAddonActionWithInfo:(NSDictionary*)dict;
- (BOOL)textView:(ZMTextView *)textView canRespondToItem:(ZMChatMsgItemInfo *)messageInfo;
@end


@interface ZMChatNoMouseDownTextView : ZMTextView <NSTextViewDelegate,ZMMutableSelectProtocal>{
    
    ZMChatMsgItemInfo* _messageInfo;
}
@property (retain) ZMChatMsgItemInfo* messageInfo;

- (void)selectFromPoint:(NSPoint)fromPoint toPoint:(NSPoint)toPoint;
- (NSInteger)indexInTextTableAtPoint:(NSPoint)point;

@end

@class ZMHMenu, ZMChatMsgItemTextView, ZMChatAppContext, ZMCommonAppDialogData;

@protocol ZMChatMsgItemTextViewDelegate <ZMTextViewDelegate>

- (void)textView:(ZMChatMsgItemTextView *)textView openChatApp:(ZMChatAppContext *)context;

@end

@interface ZMChatMsgItemTextView : ZMChatNoMouseDownTextView 

@property (assign) BOOL isUndecoded;
@property (assign) BOOL isMe;
@property (assign) BOOL isDisableShare;
@property (assign) BOOL isDoAnimation;
@property (assign) NSInteger lastHoverIndex;
@property (retain) ZMHMenu* buttonMenu;
@property (retain) ZMHMenu* dropdownMenu;

- (void)cleanUp;
- (id<NSTextAttachmentCell>)currentTextAttachmentCell;
@end


@interface ZMChatMsgItemTextView (MouseEvent)

- (void)onMouseUpAtPoint:(NSPoint)point;

@end


@interface ZMChatMsgItemTextView (Addon)

- (void)updateCommonAppMouseUp;
- (void)mouseMoveAtIndex:(NSInteger)index;
- (void)mouseExistedInRobotMessage;
- (void)showAddonMenuInCell:(NSTextAttachmentCell*)inCell;
- (void)sendAddonActionWithInfo:(NSDictionary*)dict;
- (void)commonAppSelectionChangeBackWithInfo:(NSDictionary*)dict;
- (void)showCommonAppMenuInCell:(NSTextAttachmentCell*)inCell atIndex:(NSInteger)index;
- (void)showCommonAppDatePickerInCell:(NSTextAttachmentCell *)cell atIndex:(NSInteger)index;
- (void)showCommonAppTimePickerInCell:(NSTextAttachmentCell *)cell atIndex:(NSInteger)index;
- (void)handleCommonAppRadioButtonClicked:(NSTextAttachmentCell *)cell atIndex:(NSInteger)index;
- (void)handleCommonAppCheckboxClicked:(NSTextAttachmentCell *)cell atIndex:(NSInteger)index;
- (void)handleCommonAppChannelClicked:(NSTextAttachmentCell *)cell atIndex:(NSInteger)index;
- (void)handleCommonAppDialogAction:(ZMCommonAppDialogData *)dialogData messageTemplateIndex:(NSInteger)index;

@end

