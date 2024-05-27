//
//  NSMutableAttributedString+RichFormat.h
//  ChatUI
//
//  Created by Yong Zhou on 8/20/21.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMRichFormatConstants.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableAttributedString (RichFormat)

- (void)setIsBold:(BOOL)isBold forRange:(NSRange)range;
- (void)setIsItalic:(BOOL)isItalic forRange:(NSRange)range;
- (void)setIsUnderline:(BOOL)isUnderline forRange:(NSRange)range;
- (void)setIsStrikethrough:(BOOL)isStrikethrough forRange:(NSRange)range;
- (void)setParagraphIndent:(CGFloat)indent needsCalculateIndent:(BOOL)needsCalculateIndent isIncrease:(BOOL)isIncrease forRange:(NSRange)range;
- (void)setParagraphListType:(ZMTextFormatListType)listType enabled:(BOOL)enabled forRange:(NSRange)range follow1stParagraph:(BOOL)follow1stParagraph shouldSeperateParagraph:(BOOL)shouldSeperateParagraph;
- (void)setParagraphHeadingType:(ZMTextFormatParagraphType)type needsCalculateFontSize:(BOOL)needsCalculateFontSize forRange:(NSRange)range shouldSeperateParagraph:(BOOL)shouldSeperateParagraph;
- (NSRange)safeLineRangeFromEffectiveRange:(NSRange)effectiveRange startIndex:(NSUInteger)startIndex endIndex:(NSUInteger)endIndex;
- (NSRange)longestEffectiveParagraphRangeForRange:(NSRange)range;
- (void)adjustParagraphStyle;

@end

NS_ASSUME_NONNULL_END
