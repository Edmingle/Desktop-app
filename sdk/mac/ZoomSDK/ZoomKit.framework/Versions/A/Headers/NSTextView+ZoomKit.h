//
//  NSTextView+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/6/25.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <ZoomKit/NSView+ZoomKit.h>

@interface NSTextView (ZoomKit)

@property (copy) IBInspectable NSString *placeholderString;

- (NSUInteger)charIndexWithPoint:(NSPoint)point;
- (NSTextAttachment*)textAttachmentWithCharIndex:(NSInteger)charIndex;
- (NSRect)rectOfCharacterAtIndex:(NSUInteger)charIndex;
- (NSRect)rectOfCharacterWithRange:(NSRange)charRange;

+ (void)changeGifCellMethod;

- (void)selectFromPoint:(NSPoint)fromPoint toPoint:(NSPoint)toPoint;

- (NSRange)appendString:(NSString*)newString;

- (NSSize)sizeThatFitsMaxWidth:(CGFloat)maxWidth maxLine:(NSInteger)maxLine;

- (NSRange)appendAttributedString:(NSAttributedString *)attributedString;

@end
