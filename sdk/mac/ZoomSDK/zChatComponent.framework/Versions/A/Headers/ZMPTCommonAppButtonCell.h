//
//  ZMPTCommonAppButtonCell.h
//  zChatComponent
//
//  Created by Cyan.Yang on 2023/7/6.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMCommonAppData.h>
#import <zChatComponent/ZMCAppMessageDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMCommonAppDialogData;
@class ZMCommonAppActionItem;

@interface ZMPTCommonAppButtonCell : ZMPTCommonBaseCell

@property (copy) NSString* name;
@property (copy) NSString* eventID;
@property (copy) NSString* value;
@property (copy) NSString* toolTip;
@property (copy) NSString* actionValue;
@property (nonatomic, copy) NSString *tab;
@property (nonatomic, copy) NSString *url;
@property (retain) ZMCommonAppDialogData *dialogData;
@property (assign) BOOL isMoreButton;
@property (assign) BOOL isHover;
@property (assign) BOOL submitButton;
@property (nonatomic, assign) ZMPTCommonAppButtonCellStatus buttonStatus;
@property (retain) NSArray<ZMCommonAppActionItem*>* actions;
@property (assign) ZMCommonAppActionButtonStyle style;
@property (nonatomic, assign) int messageTemplateIndex;

@end

NS_ASSUME_NONNULL_END
