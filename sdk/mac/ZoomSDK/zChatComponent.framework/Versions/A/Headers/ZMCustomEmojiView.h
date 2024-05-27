//
//  ZMCustomEmojiView.h
//  zChatComponent
//
//  Created by Mario Rao on 2023/6/30.
//

#import <ZoomKit/ZoomKit.h>
#import <zChatComponent/ZMEmojiModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMCustomEmojiShowMode) {
    ZMCustomEmojiShowModeDownloadAndShow,
    ZMCustomEmojiShowModeOnlyLoading,
    ZMCustomEmojiShowModeShowWithoutDownload,
};

@interface ZMCustomEmojiView : ZMBaseView <ZMTextAttachmentContentViewProtocol>

@property (nonatomic, strong, nullable) ZMCustomEmojiModel *emojiModel;
@property (nonatomic, assign) NSEdgeInsets emojiInsets;
@property (nonatomic, assign) BOOL disableUserInteraction;

- (instancetype)initWithEmojiInsets:(NSEdgeInsets)insets;

- (void)setCustomEmojiWidth:(CGFloat)width;

- (void)setErrorContentWidth:(CGFloat)width;

- (void)setErrorImage:(NSImage *)errorImage;

- (void)updateEmojiModel:(ZMCustomEmojiModel *)emojiModel showMode:(ZMCustomEmojiShowMode)showMode;

- (void)downloadAndShowEmojiIfNeeded;

@end

NS_ASSUME_NONNULL_END
