//
//  ZMTutorialProtocol.h
//  zChatComponent
//

#ifndef ZMTutorialProtocol_h
#define ZMTutorialProtocol_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString* ZMTutorialName NS_TYPED_ENUM;

/// Unique notifications/names that identify every UI element tutorials dynamically request.
///
/// Normally these are defined in the header for a specific tutorial, but tutorials which need
/// to get elements from zChatComponent may define values here.
typedef NSNotificationName ZMTutorialElementName NS_TYPED_EXTENSIBLE_ENUM;

/// The entire compose box, i.e. the text field, formatting buttons, and send button
extern ZMTutorialElementName const ZMTutorialElementName_NewChatSession_MessageComposeBox;
/// The text field of the compose box
extern ZMTutorialElementName const ZMTutorialElementName_NewChatSession_MessageComposeField;
/// The 'send message' button inside the compose box
extern ZMTutorialElementName const ZMTutorialElementName_NewChatSession_SendMessageButton;

/// Implemented by classes that provide a UI element to a tutorial
@protocol ZMTutorialElementProvider <NSObject>
@required
- (NSObject* _Nullable)tutorialElementNamed:(ZMTutorialElementName)name;
@end

@protocol ZMTutorialManagerProtocol <NSObject>
@required
- (void)registerProvider:(id<ZMTutorialElementProvider>)provider forTypes:(NSArray<ZMTutorialElementName>*)types;
- (void)removeProviderRegistration:(id<ZMTutorialElementProvider>)provider;
- (ZMTutorialName)currentTutorialName;
@end

#ifndef ZMShareTutorialManagerProtocol
#define ZMShareTutorialManagerProtocol (id<ZMTutorialManagerProtocol>)ZMSharedFor(ZMTutorialManagerProtocol)
#endif

NS_ASSUME_NONNULL_END

#endif /* ZMTutorialProtocol_h */
