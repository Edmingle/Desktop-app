//
//  ZMChatsAtListEntity.h
//  ZoomMsgUI
//
//  Created by Yong Zhou on 4/29/22.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMTableViewUtilCellView.h>
#import <zChatComponent/ZMEmojiModel.h>

@class ZMBuddyAdapter;
@class ZMSessionGroupAdapter;
@class ZMMentionGroup;
@class ZMMTBuddyModel;

typedef NS_ENUM(NSUInteger, ZMChatsAtListType)
{
    ZMChatsAtListType_at,
    ZMChatsAtListType_search,
    ZMChatsAtListType_channel,
    ZMChatsAtListType_commandCall,
    ZMChatsAtListType_commandMeet,
    ZMChatsAtListType_emoji,
    ZMChatsAtListType_muc,
    ZMChatsAtListType_mentionGroup,
};

typedef NS_ENUM(NSUInteger, ZMSearchMoreType)
{
    ZMSearchMoreType_None = 0,
    ZMSearchMoreType_Search,
    ZMSearchMoreType_Refine,
};


typedef void (^IsSelectedChanged)(BOOL visible);

@interface ZMChatsAtListBaseData : NSObject <ZMTableViewUtilProtocal>
@property (nonatomic, copy) IsSelectedChanged isSelectedChanged;
@property (nonatomic, assign) BOOL isSelected;
@property (nonatomic, assign) BOOL isDisabled;
@property (nonatomic, assign) BOOL isUtil;
@property (nonatomic, assign) ZMSearchMoreType searchMoreType;
@end

@interface ZMChatsAtListContactData : ZMChatsAtListBaseData
@property (retain) ZMBuddyAdapter* buddy;
@property (nonatomic, retain) ZMMentionGroup* mentionGroup;
@property (nonatomic,retain) ZMMTBuddyModel* meetBuddy;
@property (assign) BOOL isAtAll;
@property (assign) BOOL isDisableBlocker;
@end

@interface ZMChatsAtListChannelData : ZMChatsAtListBaseData
@property (nonatomic, copy) NSString *searchKey;
@property (retain) ZMSessionGroupAdapter* channel;
@end

@interface ZMChatsAtListEmojiData : ZMChatsAtListBaseData
@property (nonatomic, strong) ZMEmojiModel *emojiModel;
@property (nonatomic, copy) NSString *searchKey;
- (instancetype)initWithEmojiModel:(ZMEmojiModel *)emojiModel searchKey:(NSString *)searchKey;
@end

@interface ZMChatsAtListMUCData : ZMChatsAtListBaseData
@property (nonatomic, copy) NSString *searchKey;
@property (nonatomic, copy) NSString *jid;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *tooltip;
@property (nonatomic, copy) NSArray<ZMBuddyAdapter*> *members;
@property (assign) BOOL isCreateMUC;
@end



