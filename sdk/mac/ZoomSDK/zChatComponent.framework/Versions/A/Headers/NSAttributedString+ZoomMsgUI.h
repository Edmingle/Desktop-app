//
//  NSAttributedString+Message.h
//  zChatUI
//
//  Created by groot.ding on 2019/5/30.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zEventTracker/PTEventTrackingHelper.h>

@class ZMMessageFontInfo;
@class ZMCustomEmojiModel;

@interface NSAttributedString (ZoomMsgUI)

- (NSString *)getMessageStringAndAtList:(NSArray **)atlist atListText:(NSArray **)atListText emojiExtension:(void **)emojiExtension sessionID:(NSString*)sessionID;
- (NSString *)getMessageStringAndAtList:(NSArray **)atlist emojiExtension:(void **)emojiExtension sessionID:(NSString*)sessionID;

- (NSAttributedString *)stringByExtractingAtMentionsToPasteboardItem:(nonnull NSPasteboardItem *)item;

- (NSArray *)splitInputMessage;

- (NSArray*)fontStyleInfo;

/* attachment like "@name, #channel-name" should not parsed to plain-text to calculate the range of font-style when save to draft */
- (NSArray*)fontStyleInfoWithAttachmentParsed:(BOOL)needsParseAttachment;

/// for telemetry
+ (ZoomPTPAAP::ChatMessageEntityInfo)messageEntityWithEntity:(ZoomPTPAAP::ChatMessageEntityInfo)entity fontStyleInfo:(NSArray<ZMMessageFontInfo*> *)fontStyleInfoList;
- (NSArray *)fontStyleInfoWithAttachmentParsed:(BOOL)needsParseAttachment
                                  resultString:(NSAttributedString **)resultString;
- (NSArray *)fontStyleInfoWithAttachmentParsed:(BOOL)needsParseAttachment
                                  resultString:(NSAttributedString **)resultString
      ignoreFontSize:(BOOL)ignoreFontSize;
//custom emoji
+ (NSAttributedString *)customEmojiAttributedStringWithModel:(ZMCustomEmojiModel *)emojiModel attributes:(NSDictionary *)attributes;
+ (NSAttributedString *)customEmojiAttributedStringWithName:(NSString *)name fileID:(NSString *)fileID attributes:(NSDictionary *)attributes;
+ (NSAttributedString *)customEmojiAttributedStringWithName:(NSString *)name fileID:(NSString *)fileID sessionID:(NSString *)sessionID messageID:(NSString *)messageID fileIndex:(NSInteger)fileIndex attributes:(NSDictionary *)attributes;
+ (NSMutableAttributedString *)plainStringWithCustomEmojiFromString:(NSString *)string fontStyleInfo:(NSArray<ZMMessageFontInfo*> *)fontStyleInfo;

- (NSDictionary *)customEmojiAttributesAtIndex:(NSInteger)index;
- (NSMutableAttributedString *)attributedStringWithPlainCustomEmoji;
- (NSMutableAttributedString *)plainStringWithCustomEmoji;
- (NSMutableAttributedString *)attributedStringWithFixedCustomEmojiSize;
- (NSString *)stringWithPlainCustomEmoji;
- (NSInteger)customEmojiCount;
- (NSMutableAttributedString*)parsedAttributedStringToZMSupportedRTFWithFontSize:(CGFloat)fontSize;

- (NSMutableAttributedString *)attributedStringWithFontStyleInfo:(NSArray<ZMMessageFontInfo*> *)fontStyleInfo curAppFontSize:(CGFloat)appFontSize;
// provide public accessible RTF for 3rd apps
- (NSMutableAttributedString *)publicRTFFromZMStyleInfo:(NSArray<ZMMessageFontInfo*> *)fontStyleInfo;

- (NSArray <NSTextAttachmentCell *> *_Nullable)getViewAttachmentCells;
- (void)layoutAttchmentCellsWithMaxTextWidth:(CGFloat)maxWidth;
- (void)cleanUpViewAttachmentCells;

- (BOOL)checkMessageContainMentionAll;

- (nonnull NSString *)stringWithPlaintextAtMentions;

- (NSAttributedString *)attributedStringByTrimmingCharactersInSet:(NSCharacterSet *)characterSet;


@end


@interface NSMutableAttributedString (ZMLink)

- (void)addZMLinkToolTip;
- (void)removeZMLinkToolTip;
- (void)removeLink;
- (void)removeCursor;

@end

@interface NSMutableAttributedString (Emoji)

- (void)changeEmojiStringFont;
- (void)changeEmojiStringFontForIMInputTextViewWithFontSize:(CGFloat)fontSize;
@end
