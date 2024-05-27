//
//  ZPKeyupTextField.h
//  SaasBeeConfUIModule
//
//  Created by sanshi on 6/27/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZPKeyupSecureTextField : NSSecureTextField
{
    id _keyupTarget;
    SEL _keyupAction;
    
    id _textChangeTarget;
    SEL _textChangeAction;
}

@property (nonatomic, assign, readwrite) id keyupTarget;
@property (nonatomic, assign, readwrite) SEL keyupAction;

@property (nonatomic, assign, readwrite) id textChangeTarget;
@property (nonatomic, assign, readwrite) SEL textChangeAction;


- (void)cleanUp;



@end
