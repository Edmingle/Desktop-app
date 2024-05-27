//
//  ZMChatsInputFileView.h
//  zChatUI
//
//  Created by Yong Zhou on 3/2/20.
//  Copyright © 2020 Zoom. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@class ZMFileEntity;
@class ZMChatAppMessagePreviewInfo;
@class ZMChatsInputFileView;

typedef NS_ENUM(NSUInteger, ZMChatsInputFileTip) {
    ZMChatsInputFileTip_None = 0,
    ZMChatsInputFileTip_ReachToMaxFileCountInProcessOfSending = 1,
    ZMChatsInputFileTip_FileExistAlready = 2,
    ZMChatsInputFileTip_ReachToMaxAppShortcutInProcessOfSending = 3
};

@protocol ZMChatsInputFileViewDelegate <NSObject>

- (void)inputFileViewHeightChange:(CGFloat)height;
- (void)inputFileViewFileCountChange:(NSUInteger)fileCount needsUpdate:(BOOL)needsUpdate canSendFile:(BOOL)canSendFile;
- (void)tipForInputFileView:(ZMChatsInputFileTip)type;
- (void)removeFileView:(NSView *)fileView fileName:(NSString*)fileName fileID:(NSString*)fileID;
@optional
- (void)didInputFilesListChanged:(ZMChatsInputFileView *)inputFileView;
- (void)inputFileViewDidRemoveFileAtPath:(nullable NSString *)path;

@end


@interface ZMChatsInputFileView : ZMBaseView

@property (nonatomic, assign) id<ZMChatsInputFileViewDelegate> delegate;

@property (nonatomic, assign) BOOL isFTDisabled;
/**
 All giphy count
 */
@property (nonatomic, assign, readonly) NSUInteger giphyCount;
/**
 Used for checking if any file exists, lightweight compare to fileListInfoArr. (Contains normal file, image, giphy, appCard )
 */
@property (nonatomic, retain, readonly) NSArray<NSString *> *fileListArr;
/**
 Used only when sending message! (Contains normal file, image, giphy, appCard )
 */
@property (nonatomic, retain, readonly) NSArray<ZMFileEntity *> *fileListInfoArr;
/**
 All app card list info!
 */
@property (nonatomic, retain, readonly) NSArray<ZMChatAppMessagePreviewInfo *> *appCardListInfoArr;
/**
 Rank for draft in mainChatList.
*/
@property (nonatomic, assign) BOOL isDraftEdited;

/**
 Layout and validate files、post notifications for height change
 */
- (void)handleFiles:(NSArray<ZMFileEntity*>*)fileLists;

- (void)updateFileWebIDs:(NSArray<ZMFileEntity *> *)fileList;
/**
 Just layout, such as cell from reuse, editing message.
 */
- (void)layoutFilesFromMemory:(NSArray<ZMFileEntity*> *)fileLists;

- (BOOL)deleteSelectedFile;

- (void)cleanContent;

- (void)removeView:(NSView*)view;

@end


@interface ZMChatsInputFileView (Size)

- (NSSize)sizeWithFileLists:(NSArray<ZMFileEntity *> *)fileLists width:(CGFloat)maxWidth;

- (NSSize)sizeWithFileItem:(ZMFileEntity *)fileItem width:(CGFloat)maxWidth;

@end

NS_ASSUME_NONNULL_END
