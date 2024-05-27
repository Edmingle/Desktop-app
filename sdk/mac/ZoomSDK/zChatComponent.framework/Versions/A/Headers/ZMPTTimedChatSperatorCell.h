//
//  ZMPTTimedChatSperatorCell.h
//  zChatComponent
//
//  Created by groot.ding on 2/28/24.
//

#import <ZoomKit/ZoomKit.h>
#import <zChatComponent/ZMViewAttachmentCellProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPTTimedChatSperatorCell : ZMPTBaseTextAttachmentCell <ZMViewAttachmentCellProtocol> {
    NSRect                      _iconRect;
    NSTextStorage*              _textStorage;
    NSRange                     _textRange;
    NSInteger                   _textHOffset;
    NSInteger                   _textVOffset;
}
- (void)updateIconTitle:(NSString*)msg;
- (void)setCustomAttributedString:(NSAttributedString*)attributedString;
+ (nullable NSAttributedString*)attrStringWithString:(NSString*)string;
@end

NS_ASSUME_NONNULL_END
