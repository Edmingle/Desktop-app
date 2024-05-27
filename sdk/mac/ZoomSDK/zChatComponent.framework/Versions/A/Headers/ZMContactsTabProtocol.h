//
//  ZMContactsProtocol.h
//  zChatComponent
//

#import <Foundation/Foundation.h>

#ifndef ZMContactsProtocol_h
#define ZMContactsProtocol_h

NS_ASSUME_NONNULL_BEGIN

@protocol ZMContactsTabProtocol <NSObject>
/// YES if the contacts tab sidebar should be a native UI element, NO if the sidebar will be part of the webview.
/// Setting this property to NO when the webview is not used is undefined.
@property (nonatomic, assign, getter=isUsingNativeUIForSidebar) BOOL useNativeUIForSidebar;
@end

NS_ASSUME_NONNULL_END

#ifndef ZMContactsTabProtocol
#define ZMShareContactsTabProtocol ((id <ZMContactsTabProtocol>)ZMSharedFor(ZMContactsTabProtocol))
#endif

#endif /* ZMContactsProtocol_h */
