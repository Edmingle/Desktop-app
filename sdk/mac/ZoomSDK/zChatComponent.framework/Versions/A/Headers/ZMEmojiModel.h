//
//  ZMEmojiModel.h
//  zChatComponent
//
//  Created by Mario Rao on 4/24/23.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMEmojiModelProtocal.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, CustomEmojiDownloadErrorCode) {
    CustomEmojiDownloadErrorCodeNone = 0,
    CustomEmojiDownloadErrorCodeUnknown,
    CustomEmojiDownloadErrorCodeNoFileID,
    CustomEmojiDownloadErrorCodeDuplicate,
    CustomEmojiDownloadErrorCodeNoExist,
    CustomEmojiDownloadErrorCodeDuplicateRequest,
    CustomEmojiDownloadErrorCodeImageSizeExcceed
};

@class ZMChatFileItem, ZMSelectedEmojiModel;

@interface ZMUnicodeEmojiModel : NSObject

@property (nonatomic, strong) NSString *emojiName;
@property (nonatomic, strong) NSString *emojiString;
@property (nonatomic, strong) NSMutableArray<NSString *> *toneArray;
///a dictionary using emoji name to find emoji unicode
@property (nonatomic, strong) NSMutableDictionary<NSString *, NSString *> *emojiName2UnicodeMap;
///a dictionary using emoji unicode to find emoji name
@property (nonatomic, strong) NSMutableDictionary<NSString *, NSString *> *unicode2EmojiNameMap;

- (instancetype)initWithEmojiString:(NSString *)emojiString;
- (NSString *)emojiAtToneIndex:(NSInteger)index;

@end


@interface ZMCustomEmojiModel : NSObject

@property (nonatomic, strong) NSString *emojiName;
@property (nonatomic, strong) NSString *fileID;
@property (nonatomic, strong, readonly) ZMChatFileItem *fileItem;

//for message custom emoji downloading
@property (nonatomic, strong) NSString *sessionID;
@property (nonatomic, strong) NSString *messageID;
@property (nonatomic, assign) NSInteger fileIndex;

///If it's been removed
@property (nonatomic, assign) BOOL isInvalid;

- (instancetype)initWithEmojiName:(NSString *)emojiName fileID:(NSString *)fileID;
- (instancetype)initWithCustomEmojiString:(NSString *)emojiString;
- (NSString *)downloadIfNeededWithError:(NSError **)error;
- (NSString *)filePath;
- (NSString *)stringValue;
- (NSString *)emojiNameWithoutColon;
- (BOOL)isDownloading;
- (BOOL)isDownloaded;

@end

@interface ZMEmojiModel : NSObject<ZMEmojiModelProtocal>

@property (nonatomic, strong, readonly) ZMUnicodeEmojiModel *unicodeEmoji;
@property (nonatomic, strong, readonly) ZMCustomEmojiModel *customEmoji;

- (instancetype)initWithEmojiString:(NSString *)emojiString;
- (instancetype)initWithEmojiName:(NSString *)emojiName fileID:(NSString *)fileID;
- (nullable NSString *)unicodeEmojiAtToneIndex:(NSInteger)index;
- (BOOL)isCustomEmoji;
- (NSString *)emojiName;
- (NSString *)emojiNameWithoutColon;
- (NSString *)downloadIfNeeded;
- (NSString *)identifierWithToneIndex:(NSInteger)idx;
- (BOOL)isEqualToModel:(ZMEmojiModel *)model;

@end

NS_ASSUME_NONNULL_END
