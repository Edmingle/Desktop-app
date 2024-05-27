//
//  ZMMTBaseVeiw.h
//  ZMMTNewUIDemo
//
//  Created by francis zhuo on 5/10/20.
//  Copyright © 2020 zoom. All rights reserved.
//

typedef NSUInteger ZMMTType;

@interface ZMMTViewType : NSObject

@property(class, readonly) ZMMTType invalid;
//level 1 type
@property(class, readonly) ZMMTType main;
@property(class, readonly) ZMMTType aux;
@property(class, readonly) ZMMTType mini;
@property(class, readonly) ZMMTType floatPanel;
@property(class, readonly) ZMMTType countDown;
@property(class, readonly) ZMMTType interpreter;

@property(class, readonly) ZMMTType spotLayer;

//level 2 type
@property(class, readonly) ZMMTType dummyScene;
@property(class, readonly) ZMMTType backstage;
@property(class, readonly) ZMMTType immersive;
@property(class, readonly) ZMMTType proctoring;

//level 3 type
@property(class, readonly) ZMMTType share_screen;
@property(class, readonly) ZMMTType viewer_screen;

// level 4 type
// FIXME: - yutong reserve 3 slots for it
@property(class, readonly) ZMMTType tab_popout_screen;
@property(class, readonly) ZMMTType popout_slot0;
@property(class, readonly) ZMMTType popout_slot1;
@property(class, readonly) ZMMTType popout_slot2;

@end

#import <ZoomKit/ZoomKit.h>
@interface ZMMTBaseView : ZMBaseView
@end
