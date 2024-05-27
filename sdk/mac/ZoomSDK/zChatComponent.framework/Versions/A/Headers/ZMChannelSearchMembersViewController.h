//
//  ZMChannelSearchMembersViewController.h
//  zChatUI
//
//  Created by groot.ding on 2018/5/17.
//  Copyright © 2018年 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomKit/ZMBaseViewController.h>
#import <zChatComponent/ZMMemberInformationProtocol.h>

@class ZMSessionGroupAdapter;
@class ZMBuddyAdapter;
@class ZMNOutlineView;
@class ZMSearchResultItem;

typedef enum : NSUInteger {
    ZMHoverShowTableSelected = 1<<0,
    ZMHoverShowTableHover = 1 <<1,
    ZMHoverShowTableHoverAndSelected =ZMHoverShowTableSelected | ZMHoverShowTableHover,
} ZMHoverShowState;

typedef NS_ENUM(NSUInteger, ZMContactsAvailableType)
{
    ZMAllContactsAvailable,
    ZMInternalContactsAvailable,
    ZMSameOrgWithChannelAdminContactsAvailable,
	ZMBotsAvailable,
};

typedef NS_ENUM(NSUInteger, ZMDeactivatedBuddyRule) {
    ZMDeactivatedBuddyRuleNo,
    ZMDeactivatedBuddyRuleHidde,
    ZMDeactivatedBuddyRuleMoveToEnd
};

typedef NS_ENUM(NSUInteger, ZMChannelMembersFilter) {
    ZMChannelMembersFilterAll,
    ZMChannelMembersFilterExternal,
    ZMChannelMembersFilterCount
};

@interface ZMSearchMembersItemInfo : ZMTableViewUtilInfo

@property (nonatomic,assign) BOOL isUtil;

@property (nonatomic,assign) BOOL needShowDesc;

@property (nonatomic,retain) id item;

@property (nonatomic,copy) NSString *identifier;

@property (nonatomic,copy) NSString *desc;

@property (nonatomic,assign) BOOL ignoreFilterWhenSelected;

@property (nonatomic,assign) BOOL isPendingJoinChannel;

@property (nonatomic,assign) BOOL isItemCanbeSelected;

- (id)initWithItem:(id)item;

- (NSString *)itemIdentifier;

@end

@interface ZMChannelSearchMembersViewController : ZMBaseViewController

@property (nonatomic,retain) ZMNOutlineView *outlineView;

@property (nonatomic,retain) ZMSessionGroupAdapter *groupAdapter;
@property (nullable, nonatomic, strong) id<ZMMemberInformationProtocol> memberInformation;
@property (nonatomic,readonly) NSTreeNode *rootNode;

@property (nonatomic,readonly) NSTreeNode *searchDataNode;

@property (nonatomic,retain) NSArray <ZMSearchResultItem *> *searchResults;

@property (nonatomic,retain) NSArray <ZMSearchResultItem *> *defaultResults;

/**
 only show channel members
 */
@property (nonatomic,assign) BOOL onlyShowChannelMembers;
@property (nonatomic,assign) BOOL onlyShowBots;	// default NO

/**
 hover selected state,default is ZMHoverShowTableSelected
 */
@property (nonatomic,assign) ZMHoverShowState hoverShowState;

@property (nonatomic,assign) BOOL defaultSelectFirst;

@property (nonatomic,assign) BOOL showMarkedWhenSelected;

@property (nonatomic,assign) BOOL needShowToolButtons;

@property (nonatomic,assign) BOOL needSearchChannel;

@property (nonatomic,assign) BOOL needShowStarredSessions;

@property (nonatomic,assign) BOOL needShowMyNotes;

@property (nonatomic,assign) BOOL showBuddySign;

@property (nonatomic,assign) BOOL needShowMembersCountWithBracketsStyle;

@property (nonatomic,assign) BOOL needShowPublicIcon;

@property (nonatomic,assign) BOOL filterE2E;

@property (nonatomic,assign) BOOL filterSelf;

@property (nonatomic,assign) BOOL filterChannelSelf;

@property (nonatomic,assign) BOOL filterPending;

//default is YES
@property (nonatomic,assign) BOOL filterApp;

@property (nonatomic,assign) BOOL filterAuditRobotApp; // default YES.

@property (nonatomic,assign) BOOL filterZoomRoom;

@property (nonatomic,assign) BOOL filterRoomDevice;

@property (nonatomic,assign) BOOL filterBlock;

@property (nonatomic,assign) BOOL filterContactCanNotChat;// default YES.

@property (nonatomic,assign) BOOL filterChannelCanNotAnnounce;// if YES, then filter channel which I can not announce.

@property (nonatomic,assign) BOOL filterBroadcastAnnouncement;

@property (nonatomic,assign) BOOL filterDisabledChatCMC;

@property (nonatomic,assign) BOOL filter3rdStorageChannel;

@property (nonatomic,assign) ZMContactsAvailableType contactsAvailableType;

@property (nonatomic,assign) BOOL filterUniversalChannelByMioWhenLicense;

@property (nonatomic,assign) BOOL disableBlockedUser;

@property (nonatomic,assign) BOOL sortExternalUsersToEnd;

/**
 contacin information barrier buddy
 */
@property (nonatomic,readonly) BOOL containIBBuddy;

@property (nonatomic,copy) void(^selectBuddy)(id buddy);

@property (nonatomic,copy) void(^chatToBuddy)(id buddy);

@property (nonatomic,copy) void(^searchResultCallback)();

@property (nonatomic,copy) void(^countChange)(NSInteger count);

@property (nonatomic,copy) void(^moreButtonAction)(NSTableCellView *cellView,NSButton *button);

@property (nonatomic,assign) BOOL needShowFocusRing;

@property (nonatomic,copy) NSString *existTitle;

@property(nonatomic, assign) ZMDeactivatedBuddyRule deactivatedRule;

@property(nonatomic, assign) BOOL isPersonalFolderStyle;

@property(nonatomic, assign) BOOL isSharedSpaceStyle;

@property (nonatomic, assign) ZMChannelMembersFilter currentFilter;

@property (nonatomic, copy) NSString *currentFolderId;
@property (nonatomic, retain) NSMutableArray *folderRemoveList;
@property (nonatomic,copy) void(^removeFolderFromList)();

@property (nonatomic, assign) BOOL needSpeakResults;
@property (nonatomic, assign) BOOL needSpeakSelected;

@property (nonatomic,assign) BOOL needSearchMemberInLargeChannel;

@property (nonatomic,assign) BOOL searchFromMemberProtocol;

@property (nonatomic,assign) BOOL needShowHuddleBorder;    // default NO
/// Can be used to implement more advanced filtering logic.
@property (nullable, nonatomic, copy) BOOL (^shouldIncludeItem)(ZMSearchResultItem*);

- (void)setBorderHidden:(BOOL)hidden;

- (void)showSearchByKey:(NSString *)key;

- (void)showLocalBuddies;

- (NSString *)currentSearchKey;

- (NSArray <NSString *> * )filterJids;
- (void)setFilterJids:(NSArray <NSString *> *)jids;

- (void)setExistJids:(NSArray <NSString *> *)jids;

- (void)addFilterBuddyByJid:(NSString *)jid;

- (void)removeFilterBuddyByJid:(NSString *)jid;
- (void)removeFilterBuddies:(NSArray *)buddies;

- (void)removeAllFilter;

- (id)getCurrentSelectedBuddy;

- (NSInteger)currentShowMemberCount;

- (void)selectPreviousUser;

- (void)selectNextUser;

- (void)makeFirstResponder;

- (void)cleanData;

- (void)scrollToTop;

- (void)showSearchResult:(NSArray <ZMSearchResultItem *> *)items remote:(BOOL)remote limit:(NSInteger)limit;

- (void)showResult:(NSArray <ZMSearchResultItem *> *)items remote:(BOOL)remote limit:(NSInteger)limit;

- (void)fetchExternalUsers;

@end
