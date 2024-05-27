//
//  ZMInputTextView.h
//  ChatUI
//
//  Created by Yong Zhou on 4/20/22.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <zChatComponent/ZMRichFormatTextView.h>
#import <zChatComponent/ZMChatsAtListEntity.h>
#import <zChatComponent/ZMCompletionStorage.h>

@class ZMIMMessageDraft, ZMInputTextView;
@class ZMInputBoxLinkInfoSyncedResult;

@protocol ZMInputTextViewDelegate <NSObject>
@required
- (BOOL)isFileAccepted;
- (void)textViewDidImportFiles:(NSArray<NSString*>*)files;
- (NSString *)zmInputTextView_currentSessionId;
- (BOOL)zmInputTextView_enableParseDeeplink;

@optional
- (void)zmInputTextView_showDisableDeeplink;
- (void)textViewDidChangeResponder:(BOOL)firstResponder;
- (BOOL)zmInputTextView_shouldPasteCustomEmoji:(ZMInputTextView *)inputTextView;
/*!
 @discussion Called when pasting at mentions (ZMPTAtUserCell).
 @return true if the jid should be pasted as an attachment cell, false if a fallback string should be pasted as plaintext
 */
- (BOOL)canPasteAtMentionForJID:(NSString*)jid;
- (BOOL)zmInputTextViewShouldPasteExternalLinks:(ZMInputTextView *)textView;
- (BOOL)zmInputTextViewShouldOpenExternalLinks:(ZMInputTextView *)textView;

// if return YES, textView will not handle the event.
- (BOOL)zmInputTextView:(ZMInputTextView *)textView keyDown:(NSEvent *)theEvent;

@end

@interface ZMInputTextView : ZMRichFormatTextView

@property (nonatomic, weak) id<ZMInputTextViewDelegate> zmDelegate;
@property (nonatomic, assign) BOOL needsDrawPlaceholder;
@property (nonatomic, assign) BOOL needsParseSystemEmoji;
@property (nonatomic, assign) BOOL isFromPaste;
@property (nonatomic, assign) BOOL shouldParseCommand;
@property (nonatomic, assign) NSRange keyRange; //for showing @list at right position
@property (nonatomic, assign) BOOL shouldShowList;
@property (nonatomic, assign) BOOL needsCallCompletion; // @Ryan.Shen
@property (nonatomic, assign) ZMChatsAtListType nameKeyType;
@property (nonatomic, readonly, retain) NSDictionary *key2EmojiDict;

@property (nonatomic, readonly) ZMCompletionStorage *completionStorage;

- (void)clearContent;

/// Will draw custom placeholder. Enable needsDrawPlaceholder if your want to use it.
//- (void)setPlaceholder:(NSString *)placeholder;
//- (void)setAttributedPlaceholder:(NSAttributedString *)zmAttributedPlaceholder;
//- (NSDictionary *)placeholderAttributes;
- (NSDictionary *)getDefaultPlaceholderAttributes;

- (NSString *)contentString;
- (NSString *)contentStringWithEmojiCount:(NSInteger *)count;

- (void)resetToValidTypingAttributeAndRemoveBackgroundColor:(BOOL)bRemove;

- (BOOL)isMentionCellAtIndex:(NSInteger)index;

- (BOOL)isNumberAndCharAtIndex:(NSInteger)index;

- (void)parseSystemEmoji;

- (void)parseSticker;

- (void)parseMatchedLinks:(ZMInputBoxLinkInfoSyncedResult*)linkInfo;

- (void)replaceInputWithEmoji:(NSDictionary *)dict withRange:(NSRange)inRange;

- (BOOL)makeShorterForATAttachment:(NSTextAttachment*)attachment inRange:(NSRange)range;

// draft
- (NSString*)getDraftString;

- (void)setDraft:(ZMIMMessageDraft*)draftItem;

- (NSString*)getUserNameWhenSelectionChange;

- (NSString*)getCommandKeyWhenSelectionChange;

- (BOOL)shouldShowZoomCommandList;

- (BOOL)isEditingTail;
- (BOOL)insertCompletionIfNeeds:(NSInteger)key;

@end
