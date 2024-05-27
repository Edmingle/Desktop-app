//
//  ZMTokenTextAttachmentCell.h
//  zChatUI
//
//  Created by groot.ding on 2018/5/22.
//  Copyright © 2018年 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMTokenTextAttachmentCell : NSTextAttachmentCell

@property(nonatomic, copy) NSString *name;

@property(nonatomic, retain) NSDictionary *userInfo;

@property (nonatomic,copy) void (^remove)(ZMTokenTextAttachmentCell *cell);

@property (nonatomic, assign) BOOL isShowExternal;

@property (nonatomic, assign) BOOL isShowAdded;

@property (readonly) NSRect closeIconRect;

@property (nonatomic, retain) NSColor *borderColor;

@property (nonatomic, retain) NSColor *backgroundColor;

@property (nonatomic, retain) NSColor *highlightBackgroundColor;

@property (nonatomic, retain) NSString *accessibilityDescription;

- (NSAttributedString *)attributedString;

@end

@interface ZMTokenTexteExpandAttachmentCell : NSTextAttachmentCell

@property(nonatomic, copy) NSString *name;

@property(nonatomic, retain) NSDictionary *userInfo;

@property (nonatomic,copy) void (^remove)(ZMTokenTexteExpandAttachmentCell *cell);

@property (nonatomic, copy) void (^expand)(ZMTokenTexteExpandAttachmentCell *cell, NSUInteger atCharacterIndex);

@property (readonly) NSRect closeIconRect;

@property (readonly) NSRect expandIconRect;

@property (nonatomic, assign) BOOL expandEnable;

@end
