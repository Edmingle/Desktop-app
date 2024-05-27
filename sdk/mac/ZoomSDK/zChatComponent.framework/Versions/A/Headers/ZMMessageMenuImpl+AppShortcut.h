//
//  ZMMessageMenuImpl+AppShortcut.h
//  zChatComponent
//
//  Created by Cyan Yang on 2022/10/10.
//

#import <zChatComponent/ZMMessageMenuImpl.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMHMenuItem;
@class ZMChatMsgItemInfo;

@interface ZMMessageMenuImpl (AppShortcut)

/// Returns an array of menu items that represent the app shortcut section in
/// the message menu.
///
/// - Parameter msgItem: The message item.
/// - Returns: An array of `ZMHMenuItem` that can be appended to a menu directly
///            or `nil` if app shortcut is unavailable for the given message.
- (nullable NSArray<ZMHMenuItem *> *)appShortcutMenuItemsForMessageItem:(ZMChatMsgItemInfo *)msgItem;

@end

NS_ASSUME_NONNULL_END
