//
//  ZMCEventTrackerProtocol.h
//  zChatComponent
//
//  Created by Mario Rao on 3/17/23.
//

@class ZMChatMsgItemInfo;

#import <events/chat_ChatInteract_enum.h>

#ifdef __cplusplus
#import <zEventTracker/PTEventTrackingHelper.h>
#endif

@protocol ZMCEventTrackerProtocol <ZMRoutableObject>

+ (void)trackChatEventWithName:(e_chat_ChatInteract_event_name)name
                   featureName:(e_chat_ChatInteract_feature_name)featureName
                        source:(e_chat_ChatInteract_event_source)source
                      location:(e_chat_ChatInteract_event_location)location
                     eventType:(e_chat_ChatInteract_event_type)eventType
                           jid:(NSString *)jid
                       context:(NSString *)context;

+ (void)trackChatEventWithName:(e_chat_ChatInteract_event_name)name
                   featureName:(e_chat_ChatInteract_feature_name)featureName
                        source:(e_chat_ChatInteract_event_source)source
                      location:(e_chat_ChatInteract_event_location)location
                     eventType:(e_chat_ChatInteract_event_type)eventType
                           jid:(NSString *)jid
                         msgID:(NSString *)msgID
                       context:(NSString *)context;

#ifdef __cplusplus
+ (void)trackChatEventWithName:(e_chat_ChatInteract_event_name)name
                   featureName:(e_chat_ChatInteract_feature_name)featureName
                        source:(e_chat_ChatInteract_event_source)source
                      location:(e_chat_ChatInteract_event_location)location
                     eventType:(e_chat_ChatInteract_event_type)eventType
                           jid:(NSString *)jid
                     msgStruct:(ZoomPTPAAP::ChatMessageEntityInfo)msg
                       context:(NSString *)context;
#endif

@end
