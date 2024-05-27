//
//  ZMChatFileShareAction.h
//  ZoomMsgUI
//
//  Created by Groot Ding on 2022/4/29.
//

#import <Foundation/Foundation.h>
#import <zPTApp/SaasBeePTAppInterface.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMChatFileShareAction : NSObject

@property (nonatomic, copy) NSString* webFileID;
@property (nonatomic, copy) NSString* sharee;
@property (nonatomic, copy) NSDate* date;
@property (nonatomic, assign) NSInteger index;
@property (nonatomic, copy) NSString *msgId;
@property (nonatomic, copy) NSString *threadId;
@property (nonatomic, assign) BOOL isComment;
@property (nonatomic, assign) unsigned long long msgServerTime;
@property (nonatomic, assign) unsigned long long threadServerTime;

- (id)initWithShareAction:(NS_ZOOM_MESSAGER::IZoomShareAction*)zoomShareAction;

@end

NS_ASSUME_NONNULL_END
