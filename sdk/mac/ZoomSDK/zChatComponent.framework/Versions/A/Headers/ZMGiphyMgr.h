//
//  ZMGiphyMgr.h
//  SaasBeePTUIModule
//
//  Created by likevin on 7/20/17.
//  Copyright © 2017 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMPTGiphyData, ZMMessageAdapter;

@interface ZMGiphyMgr : NSObject

@property(nonatomic,copy) NSString *currentSessionId;

- (void)cleanUp;
- (void)initDefaultHotEmojis;
- (BOOL)downloadGiphy:(NSString*)giphyID andGiphyMsgGuid:(NSString*)giphyMsgGuid andSessionID:(NSString*)inSessionId;
- (void)attach2GridView:(id)inGridView;
- (BOOL)loadGiphyDataByString:(NSString*)string andGiphyNum:(NSUInteger)giphyNum;

- (void)updateGiphyDataWithMessageInfo:(ZMMessageAdapter*)msgInfo outGiphyData:(ZMPTGiphyData*)giphyData;
- (BOOL)downloadWithGiphyData:(ZMPTGiphyData*)giphyData;
@end
