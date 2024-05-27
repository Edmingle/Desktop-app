//
//  ZMLine.h
//  ZCommonUI
//
//  Created by zoom on 13-7-29.
//  Copyright (c) 2013年 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Zoomkit/NSView+ZoomKit.h>

@interface ZMLine : ZMTagView
{
    NSColor* _color;
}
@property(nonatomic, retain) NSColor* color;
@end
