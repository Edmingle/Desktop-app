//
//  ZMCustomEmojiAttachmentCell.h
//  zChatComponent
//
//  Created by Mario Rao on 2023/6/28.
//

#import <zChatComponent/ZMEmojiModel.h>
#import <zChatComponent/ZMCustomEmojiView.h>
#import <zChatComponent/ZMViewAttachmentCellProtocol.h>
#import <ZoomKit/ZoomKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMCustomEmojiAttachmentCell : ZMBaseTextAttachmentCell

@property (nonatomic, strong) ZMCustomEmojiModel *emojiModel;
@property (nonatomic, assign) CGFloat maxWidth;

- (void)setMaxWidthByAttributes:(NSDictionary<NSAttributedStringKey, id> *)attributes;
- (void)setMaxWidthByFontPointSize:(CGFloat)pointSize;
- (void)setMaxWidthByFont:(NSFont *)font;

@end

NS_ASSUME_NONNULL_END
