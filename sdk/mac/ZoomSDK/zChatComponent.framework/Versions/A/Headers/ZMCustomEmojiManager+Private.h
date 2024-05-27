//
//  ZMCustomEmojiManager+Private.h
//  zChatComponent
//
//  Created by Mario Rao on 2023/8/18.
//

#ifndef ZMCustomEmojiManager_Private_h
#define ZMCustomEmojiManager_Private_h

#import "ZMCustomEmojiManager.h"
#import "zChatApp/StickerInterface.h"
#import "cmmlib/CmmDef.h"
#import "zPTApp/SaasBeePTAppInterface.h"

@interface ZMCustomEmojiManager (Private)

//callback
- (void)OnCustomEmojisUpdated:(NSString *)req_id result:(CmmInt32)result searchAfter:(NSString *)searchAfter;
- (void)OnNewCustomEmojiUploaded:(NSString *)req_id result:(CmmInt32)result emoji:(const NS_ZOOM_MESSAGER::zStickerInfo&)emoji;
- (void)OnMyCustomEmojiDeleted:(NSString *)req_id result:(CmmInt32)result emoji:(const NS_ZOOM_MESSAGER::zStickerInfo&)emoji;
- (void)OnCustomEmojiDeleted:(const NS_ZOOM_MESSAGER::zStickerInfo&)emoji;
- (void)OnCustomEmojiDownloaded:(NSString *)req_id result:(CmmInt32)result emoji:(const NS_ZOOM_MESSAGER::zStickerInfo&)emoji;
- (void)OnSearchCustomEmojis:(NSString *)req_id result:(CmmInt32)result emoji:(const NS_ZOOM_MESSAGER::zStickerInfoList&)emojis searchAfter:(NSString *)searchAfter;

@end

#endif /* ZMCustomEmojiManager_Private_h */
