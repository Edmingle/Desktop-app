//
//  ZMCustomEmojiManager.h
//  ChatUI
//
//  Created by Mario Rao on 2023/6/13.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMEmojiModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^CustomEmojiSearchCallback)(NSArray<ZMEmojiModel *> *searchResult, NSString *searchAfterKey);
typedef void (^CustomEmojiLoadCallback)(NSArray<ZMEmojiModel *> *allEmojis, BOOL hasError);

@interface ZMCustomEmojiManager : NSObject

@property (nonatomic, assign) BOOL isCustomEmojiFetched;
@property (nonatomic, assign) BOOL isLoadingEmojiList;
@property (nonatomic, strong) NSArray<ZMEmojiModel *> *customEmojis;

+ (instancetype)shared;
- (void)prepare;

- (BOOL)isCustomEmojiEnabledInChannel:(NSString *)sessionID messageID:(NSString *)messageID;
- (BOOL)isCustomEmojiEnabled;
- (BOOL)isEditCustomEmojiEnabled;
- (BOOL)isValidCustomEmojiNameInput:(NSString *)name;
- (NSString *)uploadAndMakeCustomEmoji:(NSString *)path emojiName:(NSString *)emojiName;
- (NSString *)deleteCustomEmoji:(ZMCustomEmojiModel *)emoji;
- (NSString *)downloadCustomEmoji:(ZMCustomEmojiModel *)emoji error:(NSError **)error;
- (NSString *)emojiOwnerIDWithName:(NSString *)name fileID:(NSString *)fileID;
- (BOOL)canLoadMoreCustomEmoji;
- (void)loadCustomEmojiIfNeeded:(CustomEmojiLoadCallback)callback;

//panel
- (void)showEditCustomEmojiWindow;
- (void)showAddCustomEmojiWindow:(BOOL)isFromEdit;

//search
- (void)searchCustomEmojiForKeyword:(NSString *)keyword
                     searchAfterKey:(NSString *)searchAfter
             remoteSearchCompletion:(CustomEmojiSearchCallback)remoteCompletion;
- (void)searchCustomEmojiForCurrentUserWithSearchAfterKey:(NSString *)searchAfter
                                         remoteCompletion:(CustomEmojiSearchCallback)completion;

@end

NS_ASSUME_NONNULL_END
