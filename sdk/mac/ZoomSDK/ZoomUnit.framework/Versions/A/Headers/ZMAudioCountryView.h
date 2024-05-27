//
//  ZMAudioCountryView.h
//  SaasBeeConfUIModule
//
//  Created by John on 6/17/14.
//  Copyright (c) 2014 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMAudioCountryView : NSView
{
    NSColor* _backgroundColor;
}
@property(nonatomic, retain) NSColor* backgroundColor;
@end

@interface ZMAudioCountryInfo : NSObject
{
    NSString* _countryId;
    int _countryCode;
    NSString* _countryName;
    NSString* _countryNumber;
    NSString* _countryDisplayNumber;
    NSMutableArray* _numberArray;
    NSMutableArray* _tollFreeNumberArray;
    int _callType;
}
@property(nonatomic, retain)NSString* countryId;
@property(nonatomic, assign)int countryCode;
@property(nonatomic, retain)NSString* countryName;
@property(nonatomic, retain)NSString* countryNumber;
@property(nonatomic, retain)NSString* countryDisplayNumber;
@property(nonatomic, retain)NSString* phoneType;
@property(nonatomic, retain)NSMutableArray* numberArray;
@property(nonatomic, retain)NSMutableArray* tollFreeNumberArray;
@property(nonatomic, assign)int callType;
- (id)initWithCode:(int)inCode name:(NSString*)inName;
- (void)addCountryNumber:(NSString*)inNumber isFree:(BOOL)isFree;
@end

@interface ZMAudioCountryButton : ZMButton
{
    NSString* _countryId;
}
@property(nonatomic, retain) NSString* countryId;
@property(nonatomic, retain) ZMAudioCountryInfo *info;
@end
