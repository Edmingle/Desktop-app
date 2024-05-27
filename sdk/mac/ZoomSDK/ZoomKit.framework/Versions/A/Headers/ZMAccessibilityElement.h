//
//  ZMAccessibilityElement.h
//  MessageListDemo
//
//  Created by groot.ding on 13/05/2020.
//  Copyright © 2020 groot.ding. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(10.10))
@interface ZMAccessibilityElement : NSAccessibilityElement

@property (nonatomic,nullable, copy) NSString *label;

@property (nonatomic,nullable, copy) NSString *role;
@property (nonatomic,nullable, retain) id value;

@property (nonatomic,nullable, copy) NSString *roleDescription;

@property (nonatomic,nullable, retain) NSArray <NSValue *> *frames;

// Union frames
@property (nonatomic, readonly) NSRect frameInParentView;

@property (nonatomic, assign) NSRange textRange;

@property (nonatomic, retain,nullable) id responseElement;

@property (nonatomic, weak) id target;
@property (nonatomic, assign,nullable) SEL action;

- (void)removeFrame:(NSRect)frame;

@end

NS_ASSUME_NONNULL_END
