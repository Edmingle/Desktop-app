//
//  ZMTextFormatAddLinkView.h
//  zChatComponent
//
//  Created by Yong Zhou on 6/22/21.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import "ZMTextFormatEntity.h"

@interface ZMTextFormatAddLinkView : NSView

@property (nonatomic, copy) void (^onConfirmBtnClicked)(NSString *linkUrlString);
@property (nonatomic, copy) void (^onEditBtnClicked)(NSString *linkUrlString, NSRange linkRange);
@property (nonatomic, copy) void (^onRemoveBtnClicked)(NSRange linkRange);
@property (nonatomic, copy) void (^checkLinkURLCompletion)(BOOL isValidUrl, BOOL needsClose);
@property (nonatomic, copy) void (^checkURL)(NSString *tmpUrlString);

@property (nonatomic, assign) BOOL openButtonDisabled;

+ (instancetype)sharedLinkView;

- (instancetype)init NS_UNAVAILABLE;  // Use the designated initializer sharedLinkView
- (instancetype)initWithFrame:(NSRect)frameRect NS_UNAVAILABLE;  // Use the designated initializer sharedLinkView

- (void)showWithType:(ZMTextFormatShowLinkViewType)type url:(NSString*)urlString linkRange:(NSRange)range
         relatedView:(NSView *)relatedView relatedRect:(NSRect)relatedRect;

- (void)close;

@end


