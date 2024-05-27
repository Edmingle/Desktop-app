//
//  ZMSysEmojiMgr.h
//  SaasBeePTUIModule
//
//  Created by likevin on 7/3/17.
//  Copyright © 2017 Zipow. All rights reserved.
//

#import <zChatComponent/ZMEmojiUnicodeData.h>
#import <zChatComponent/ZMEmojiModel.h>
#import <zChatComponent/ZMSysEmojiView.h>
#import <zChatComponent/ZMSkinToneButton.h>

@class ZMBaseView;
@class ZMCustomEmojiView;
@class ZMSysEmojiToolbarItemModel;

@protocol ZMSysEmojiMgrDelegate <ZMEmojiUnicodeDataDelegate>
- (void)sysEmojiMgrDidSelectedEmoji:(ZMEmojiModel *)emojiModel atIndex:(NSInteger)index;
- (void)sysEmojiMgrDidAddFavorite:(ZMEmojiModel *)emojiModel;
- (int)sysEmojiMgrDidGetSkinTone;
@optional
- (void)sysEmojiMgrDidEnterEditCustomEmoji;
@end

@interface ZMSysEmojiMgr : NSObject 
@property (nonatomic, weak) id<ZMSysEmojiMgrDelegate> delegate;
@property (nonatomic, assign) BOOL forceDarkMode;
@property (nonatomic, assign) BOOL canShowCustomEmoji;
@property (nonatomic, assign, readonly) ZMEmojiUnicodeData *emojiUnicodeData;

- (instancetype)initWithDelegate:(id<ZMSysEmojiMgrDelegate>)delegate;
- (void)cleanUp;
- (void)onSearch:(NSString*)searchString;
- (void)onTagSelected:(NSUInteger)tag;
- (void)addFavorite:(ZMEmojiModel *)emojiModel;
- (void)clickedItem:(ZMEmojiModel *)emojiModel;
- (void)resetEmojiView;
- (void)makeSearchFiledFirstResponder;
- (NSView*)getUnicodeEmojiView:(NSRect)inRect;
- (void)releaseEmojiView;
- (void)reloadSysEmojiData;
- (BOOL)isInEmojiFont:(NSString*)uniString;
- (Class)emojiItemViewClass;
- (NSArray<ZMSysEmojiToolbarItemModel *> *)tableBarDataSource;
- (void)updateCustomEmojis:(NSArray<ZMEmojiModel *> *)customEmojis;
- (void)createEmojiDataWhenLogin;
@end
