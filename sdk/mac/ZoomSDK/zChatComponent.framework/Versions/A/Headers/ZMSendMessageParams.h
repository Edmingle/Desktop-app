//
//  ZMSendMessageParams.h
//  zChatComponent
//
//  Created by Yong Zhou on 1/6/24.
//

#import <Foundation/Foundation.h>

@class ZMFileEntity;

/*
 Send Message Params
 Design pattern: adapter for avoid too many input params and version incompatibility for `sendText` method
 */

@protocol ZMSendMessageUIProtocol <NSObject>

- (void)checkShowUserGuideInE2EChannelAfterSendHybridMsg;

@end

@interface ZMSendMessageParams : NSObject

// General chat
@property (nonatomic, assign) NSInteger messageType;
@property (nonatomic, assign) BOOL isScreenShot;
@property (nonatomic, retain) ZMFileEntity *fileEntity;
@property (nonatomic, retain) NSString *body; // will be deprecated later
@property (nonatomic, retain) NSAttributedString *attrString;
@property (nonatomic, retain) NSArray *fileList;
@property (nonatomic, retain) NSArray *urlArray;
@property (nonatomic, retain) NSArray *appPreviewsInfoArray;
@property (nonatomic, assign) BOOL isRecordVideoMessage;

// meeting chat
@property (nonatomic, assign) BOOL isMeetMessage;
@property (nonatomic, assign) NSInteger meetMsgType;
@property (nonatomic, copy) NSString *meetDMReceiverId;
@property (nonatomic, assign) NSInteger meetDMReceiverNodeId;

@property (nonatomic, retain, nullable) NSString *draftID;
@property (nonatomic, assign) BOOL isThreadedDraft;

@property (nonatomic, weak) id <ZMSendMessageUIProtocol> UIDelegate;

@end
