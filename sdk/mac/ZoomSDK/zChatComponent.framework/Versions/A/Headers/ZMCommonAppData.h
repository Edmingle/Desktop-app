//
//  ZMCommonAppData.h
//  zChatUI
//
//  Created by ryan on 2018/5/7.
//  Copyright © 2018年 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMCAppMessageDefines.h>
//#import "SBPTUI.h"

typedef NS_OPTIONS(NSUInteger, ZMCommonAppSelectSourceType)
{
    ZMCommonAppSelectSourceType_members,
    ZMCommonAppSelectSourceType_channels,
    ZMCommonAppSelectSourceType_others,
};

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *ZMCommonAppExpandButtonAttribute;
FOUNDATION_EXPORT NSString *ZMCommonAppCollapseButtonAttribute;
FOUNDATION_EXPORT NSString *ZMCommonAppChannelSessionIDAttribute;

FOUNDATION_EXPORT NSFont *ZMCommonAppDefaultFontWithSize(NSInteger fontSize);

@class ZMChatFileItem;
@class ZMChatMsgItemInfo;

@interface ZMAppMarkdownFile : NSObject

// png | jpg | gif | jpeg
@property (nonatomic,copy) NSString *type;
@property (nonatomic,copy) NSString *fileId;
@property (nonatomic,copy) NSString *alt;

@property (assign) long index;
@property (assign) long fileSize;
@property (assign) long width;
@property (assign) long height;
@end

@interface ZMAppMarkdownText : NSObject

@property (copy) NSString* text;
@property (copy) NSString* hyperlink;
@property (copy) NSString* sip;
@property (copy) NSString* mailto;
@property (copy) NSString* mentionJID;
@property (copy) NSString* profile;
@property (copy) NSString* linkToJid;
@property (copy) NSString* imageLink;
@property (copy) NSString* imageAlter;
@property (copy) NSColor * color;

@property (assign) BOOL isItalic;
@property (assign) BOOL isBold;
@property (assign) BOOL isStrikethrough;
@property (assign) BOOL isMonospace;
@property (assign) BOOL isMentionAll;
@property (assign) BOOL isConcat;

@property (assign) NSUInteger quotes;

@property (nonatomic,retain) ZMAppMarkdownFile *file;

@end

@interface ZMCommonAppSelectItemData : NSObject

@property (copy) NSString* text;
@property (copy) NSString* value;

- (id)initWithDataPointer:(void *)pItemData;
- (BOOL)isEqualWithData:(ZMCommonAppSelectItemData*)inData;

@end

@interface ZMCommonAppSelectGroupData : NSObject

@property (copy) NSString* group;
@property (retain) NSArray<ZMCommonAppSelectItemData*>* selectItems;

//- (id)initWithData:(NS_ZOOM_MESSAGER::SelectGroup)itemData;

@end

@interface ZMCommonAppSelectAllGroupsData : NSObject

@property (retain) NSArray<ZMCommonAppSelectGroupData*>* groups;
@property (assign) ZMCommonAppSelectSourceType type;

//- (id)initWithData:(NS_ZOOM_MESSAGER::MessageTemplateSelectItems)itemData;

@end

@interface ZMCommonAppDialogData : NSObject

@property (copy) NSString* appID;
@property (copy) NSString* link;
@property (copy) NSString* title;
@property (copy) NSString* actionID;
@property (assign) BOOL isHideTitle;
@property (assign) BOOL isHideApp;
@property (assign) int width;
@property (assign) int height;

@end

@interface ZMCommonAppBaseItem : NSObject

@property (copy, nullable) NSString* text;
@property (copy, nullable) NSColor* color;
@property (copy, nullable) NSString* fallBack;
@property (assign) BOOL isBold;
@property (assign) BOOL isItalic;
@property (assign) BOOL isUnsupport;
@property (assign) ZMCommonAppBodyType type;
@property (assign) ZMCommonAppControlAlignment alignment;

@end

@interface ZMCommonAppHeadItem : ZMCommonAppBaseItem

@property (retain) NSArray<ZMAppMarkdownText*>* markedTextArray;

@end

@interface ZMCommonAppActionItem : ZMCommonAppBaseItem

@property (assign) ZMCommonAppActionButtonStyle style;
@property (copy) NSString* value;
@property (copy) NSString *action;
@property (retain) ZMCommonAppDialogData *dialogData;
@property (copy) NSString *toolTip;
@property (nonatomic, assign) BOOL enabled;
@property (nonatomic, assign) BOOL submitButton;
@property (nonatomic, copy) NSString *tab;
@property (nonatomic, copy) NSString *url;

@end

@interface ZMCommonAppActionItems : ZMCommonAppBaseItem

@property (retain) NSArray<ZMCommonAppActionItem*>* actions;
@property (copy) NSString* eventID;
@property (assign) NSInteger limited;

@end

@interface ZMCommonAppSelectItem : ZMCommonAppBaseItem

@property (copy) NSString* eventID;
@property (retain) ZMCommonAppSelectAllGroupsData* data;
@property (retain) NSArray<ZMCommonAppSelectItemData*>* selectItems;
@property (nonatomic, assign) BOOL bordered;

- (BOOL)isEqualToData:(NSArray<ZMCommonAppSelectItemData*>*)dataArray;

@end

@interface ZMCommonAppDateTimePickerItem : ZMCommonAppBaseItem

@property (copy) NSString *eventID;
@property (copy) NSString *actionID;
@property (retain) NSDateComponents *dateComponents;

@end

@interface ZMCommonAppRadioButtonItem : ZMCommonAppBaseItem

@property (copy) NSString *eventID;
@property (copy) NSString *actionID;
@property (copy, nonatomic) NSString *selectedValue;
@property (assign, nonatomic) NSUInteger numberOfChoices;

- (void)addChoiceWithTitle:(NSString *)title value:(NSString *)value;

- (NSString *)titleOfChoiceAtIndex:(NSUInteger)index;
- (NSString *)valueOfChoiceAtIndex:(NSUInteger)index;

@end

@interface ZMCommonAppProgressBarItem : ZMCommonAppBaseItem

@property (assign, nonatomic) NSInteger value;

@end

@interface ZMCommonAppDividerItem : ZMCommonAppBaseItem

@property (nonatomic, copy) NSColor *lineColor;
@property (nonatomic, assign) BOOL bold;
@property (nonatomic, assign) BOOL dotted;

@end

@interface ZMCommonAppMessageItem : ZMCommonAppActionItem

@property (copy) NSString* link;
@property (copy) NSString* eventID;
@property (retain) NSArray<ZMAppMarkdownText*>* markedTextArray;
@property (assign) BOOL isEditalbe;

@end

// Template File is very similar with Normal file in appearance.
@interface ZMCommonAppTemplateFileItem : ZMCommonAppBaseItem
@property (copy) NSString *iconURL;
@property (copy) NSString *title;
@property (copy) NSString *fileURL;
@property (copy) NSString *desc;
@end

@interface ZMCommonAppFieldItem : ZMCommonAppMessageItem

@property (copy) NSString* key;
@property (assign) BOOL isName;
@property (assign) BOOL isShort;

@end

@interface ZMCommonAppFieldItems : ZMCommonAppBaseItem

@property (retain) NSArray<ZMCommonAppFieldItem*>* fieldItems;
@property (copy) NSString* eventID;

@end

@interface ZMCommonAppAttachItem : ZMCommonAppBaseItem

@property (retain) NSString* resourceUrl;
@property (retain) NSString* imageUrl;
@property (retain) NSString* extention;
@property (assign) long long size;
@property (assign) NSInteger index;
@property (retain) ZMCommonAppBaseItem* descriptionItem;

@property (nonatomic, copy) NSString *fileId;
@property (nonatomic, assign) NSInteger fileIndex;

@end

@interface ZMCommonAppSubBuddyItem : ZMCommonAppBaseItem

@property (copy) NSColor* barColor;
@property (retain) NSString* footer;
@property (retain) NSString* iconURL;
@property (retain) NSString* footerFallBack;
@property (retain) NSMutableArray* bodyItems;
@property (retain) NSDate* time;
@property (retain) NSMutableArray<ZMAppMarkdownText*>* markedTextArray;
@property (assign) BOOL isAddDateToMarkedTextArray;
@property (assign) BOOL isFooterUnsupport;
@property (assign) BOOL prefersSingleLine;

@end

@interface ZMCommonAppMetaData : NSObject

@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *displayProfileId;
@property (nonatomic, copy) NSString *displayName;
@property (nonatomic, copy) NSString *displayIcon;
@property (nonatomic, copy) NSString *displayLabel;

@end

@class ZMPTCommonAppExpandCell, ZMPTCommonAppFileCell;

@interface ZMCommonAppData : NSObject

@property (retain) ZMCommonAppHeadItem* head;
@property (retain) ZMCommonAppHeadItem* subHead;
@property (retain) NSMutableArray* bodyItems;
@property (assign) BOOL isUnsupportMessage;
@property (nonatomic, assign) BOOL hasUnsupportedComponents;
@property (assign) BOOL hasSplitSideBar;
@property (assign) BOOL sideBarDisabled;
@property (assign) BOOL hasSubBody;
@property (assign) BOOL hasMonospace;
@property (assign) BOOL hasHighlight;
@property (assign) BOOL hasProfile;

// ZOOM-520700: new protocol for embedding profile links without mentions.
// "@all" cell will not be highlighted when this flag is set to `YES`.
@property (assign) BOOL hasProfileV2;

@property (assign) BOOL hasSip;
@property (assign) BOOL hasShortField;
@property (assign) BOOL isOnlyVisibleToMe;
@property (assign) NSInteger expandInfo;
@property (copy) NSColor* defaultBarColor;
@property (nonatomic, copy) NSString *botJID;

@property (assign) NSInteger headLoaction;
@property (assign) BOOL hasContent;
@property (assign, readonly) int index;

@property (nonatomic, retain) ZMCommonAppMetaData *appMetaData;

@property (nonatomic, weak) ZMChatMsgItemInfo *messageInfo;

+ (NSString*)stringByReplaceLineBreak:(NSString*)srcString;

- (id)initWithSessionID:(NSString*)sessionID messageID:(NSString*)messageID index:(int)index;
- (void)constructData;
- (NSMutableAttributedString*)contentString;
- (void)setAttachmentsHideByCell:(ZMPTCommonAppExpandCell*)cell atIndex:(NSInteger)index inAttributeString:(NSMutableAttributedString*)attString;
- (ZMCommonAppSelectItem*)getSelectItemByEventID:(NSString*)eventID;

- (void)expandTextByItem:(ZMCommonAppBaseItem *)item;
- (void)collapseTextByItem:(ZMCommonAppBaseItem *)item;

- (ZMPTCommonAppFileCell *)getFileCellWithFileId:(NSString *)fileId;

@end

@interface ZMPTCommonSpacerCell : NSTextAttachmentCell

@property (nonatomic, assign) CGFloat length;

@end

@interface ZMPTCommonBaseCell : NSTextAttachmentCell

@property (nonatomic, readonly) BOOL needFocusRing;
@property (nonatomic, assign) BOOL hoverred;

@end

@interface ZMPTCommonAppSelectCell : ZMPTCommonBaseCell

@property (copy) NSString* eventID;
@property (copy) NSString* text;
@property (retain) ZMCommonAppSelectItem* itemData;
@property (assign) BOOL isHover;
@property (nonatomic, assign) int messageTemplateIndex;

@end

@interface ZMPTCommonAppNameCell : ZMPTCommonBaseCell

@property (copy) NSAttributedString* name;

@end

@interface ZMPTCommonAppFileCell : ZMPTCommonBaseCell

@property (retain) NSAttributedString* fileName;
@property (retain) NSAttributedString* fileDescription;
@property (retain) NSString* resourceURL;
@property (retain) NSImage* iconImage;
@property (nonatomic, retain) ZMChatFileItem *fileItem;
@property (assign) BOOL isHover;
@property (assign) BOOL shouldShowToolTip;
@property (nonatomic, assign) long long size;

@property (nonatomic,assign) NSInteger downloadRatio;
@property (nonatomic,assign) NSInteger downloadSize;

- (ZMChatFileItem *)latestFileModel;

@end

typedef NS_OPTIONS(NSUInteger, ZMPTCommonAppImageCellType)
{
    ZMPTCommonAppImageCell_Footer,
    ZMPTCommonAppImageCell_InlineImage,
    ZMPTCommonAppImageCell_NormalImage,
    ZMPTCommonAppImageCell_DefaultInlineImage,
};

@interface ZMPTCommonAppImageCell : ZMPTCommonBaseCell

@property (nonatomic, assign) ZMPTCommonAppImageCellType cellType;
@property (nonatomic, retain) NSString* imageAlter;

@end

@interface ZMPTCommonAppActionCell : ZMPTCommonBaseCell

@property (retain) ZMCommonAppMessageItem* item;
@property (assign) float fontSize;
@property (assign) NSInteger length;
@property (nonatomic, assign) int messageTemplateIndex;
@end

@interface ZMPTCommonAppExpandCell : ZMPTCommonBaseCell

@property (nonatomic, assign) BOOL isExpanded;
@property (nonatomic, assign) NSUInteger index;
@property (retain) id cellData;

@end

@interface ZMPTCommonAppDateTimePickerCell : ZMPTCommonBaseCell

@property (nonatomic, assign) int messageTemplateIndex;
@property (nonatomic, copy) NSString *eventID;
@property (nonatomic, copy) NSString *actionID;

+ (NSImage *)prefixIconImage;

@end

@interface ZMPTCommonAppDatePickerCell : ZMPTCommonAppDateTimePickerCell

@property (nonatomic, copy) NSDate *date;

- (void)showPickerWindowAtPoint:(CGPoint)point withCompletionHandler:(void (^)(NSDate *selectedDate))completionHandler;

@end

@interface ZMPTCommonAppTimePickerCell : ZMPTCommonAppDateTimePickerCell

@property (nonatomic, copy) NSDateComponents *timeComponents;

- (void)showPickerMenuAtPoint:(CGPoint)point
        withCompletionHandler:(void (^)(NSDateComponents *selectedTimeComponents))completionHandler;

@end

@interface ZMPTCommonAppRadioButtonCell : ZMPTCommonBaseCell

@property (nonatomic, assign) int messageTemplateIndex;
@property (nonatomic, copy) NSString *eventID;
@property (nonatomic, copy) NSString *actionID;
@property (nonatomic, copy) NSString *groupID;
@property (nonatomic, copy) NSString *value;

@end

@interface ZMPTCommonAppProgressBarCell : ZMPTCommonBaseCell

@end

@interface ZMPTCommonAppDividerCell : ZMPTCommonBaseCell

@property (nonatomic, copy) NSColor *lineColor;
@property (nonatomic, assign) BOOL bold;
@property (nonatomic, assign) BOOL dotted;

@end

NS_ASSUME_NONNULL_END
