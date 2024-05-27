//
//  ZMFileOperateMenuImpl.h
//  zChatUI
//
//  Created by groot.ding on 20/08/2020.
//  Copyright © 2020 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMMenuImpl.h>

@class ZMChatMsgItemInfo;

typedef NS_ENUM(NSInteger, ZMFileMenuTag) {
    
    ZMFileMenuTagOpen,
    ZMFileMenuTagCopy,
    ZMFileMenuTagDownload,
    ZMFileMenuTagCancel,
    ZMFileMenuTagViewInFinder,
    ZMFileMenuTagAddEmoji,
    ZMFileMenuTagDelete,
    ZMFileMenuTagHybridItemDelete,
    ZMFileMenuTagShare,
    ZMFileMenuTagSaveAs,
    ZMFileMenuTagExpand,
};

NS_ASSUME_NONNULL_BEGIN

@class ZMFileEntity, ZMFileOperateMenuImpl;

@protocol ZMFileOperateMenuProxy <NSObject>

- (void)fileOperateMenu:(ZMFileOperateMenuImpl *)memuImpl didSelectedItem:(ZMFileMenuTag)itemTag;

@end

@interface ZMFileOperateMenuImpl : ZMMenuImpl

@property (nonatomic,assign) BOOL filterOpen;
@property (nonatomic,assign) BOOL filterDownload;
@property (nonatomic,assign) BOOL filterViewInFinder;
@property (nonatomic,readonly) ZMFileEntity *fileItem;
@property (nonatomic,readonly) ZMChatMsgItemInfo *messageItem;

@property (nonatomic, weak) id<ZMFileOperateMenuProxy> proxy;

- (void)showMenuWithFileItem:(ZMFileEntity *)fileItem sessionId:(NSString *)sessionId inView:(NSView *)inView localPoint:(CGPoint)localPoint;

- (void)showMenuForHybridItemWithFileItem:(ZMFileEntity *)fileItem messageItem:(ZMChatMsgItemInfo*)messageItem sessionId:(NSString *)sessionId inView:(NSView *)inView localPoint:(CGPoint)localPoint;

@end

NS_ASSUME_NONNULL_END
