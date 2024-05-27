//
//  ZMUser.h
//  ZCommonUI
//
//  Created by francis on 3/28/17.
//  Copyright © 2017 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMUserType){
    ZMUserType_CmmUser      = 1<<0,
    ZMUserType_LeftUser     = 1<<1,
    ZMUserType_MasterUser   = 1<<2,
    ZMUserType_ViewOnly     = 1<<3,
    ZMUserType_Specific     = 1<<4,
    ZMUserType_Invitee      = 1<<5,
};

class ICmmUser;
class IZoomQABuddy;

@interface ZMMTNameTag : NSObject <NSCopying>
@property (nonatomic, assign) BOOL isValid;
@property (nonatomic, copy) NSString *templateid;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *desc;
@property (nonatomic, copy) NSString *pronouns;
@property (nonatomic, copy) NSColor *textColor;
@property (nonatomic, copy) NSColor *backgroundColor;
@property (nonatomic, copy) NSColor *accentColor;
+ (instancetype)nameTag:(CmmUserNameTag)cmmNameTag;
- (BOOL)isNotNone;
@end

@class ZMConfSession;

@interface ZMUser : NSObject<NSCopying>
@property(nullable,nonatomic,retain) ZMConfSession* confSession;

@property(assign) ZMUserType userType;
@property(readonly,assign) ZMUserID userId;//MMR protection
@property(readonly,assign) ZMUserID defaultUserId;
@property(readonly,assign) ZMUUID   userUUID;
@property(readonly,assign) ZMUJID   userUJID;
@property(nullable,readonly,copy) NSString*      GUID; /// PII
@property(nullable,readonly,copy) NSString*      userJid; /// PII
@property(nullable,readonly,copy) NSString*      CUID;/// PII - conf user id
@property(nullable,readonly,copy) NSString*      deviceID; /// PII
@property(nullable,readonly,copy) NSString*      email;/// PII - ZOOM-276920 /// If an invitee don't have CUID, we have to use email to identify.
@property(nullable,readonly,copy) NSString*  specificID;
@property(nullable, readonly) ZMMTNameTag*     nameTag;
@property(nonatomic, readonly) NSString *identifier;
@property(nullable,copy) NSString* specificUserName;

///may be return nil, eg: attendee in webinar bo
@property(readonly,assign) ZMUser* defaultUser;
@property(readonly,assign,nullable) ZMUser* masterUser;
@property(readonly,assign,nullable) ZMUser* viewOnlyUser;//cmmuser transfer to QAbuddy

@property(readonly,assign)BOOL         isLeftUser;
@property(readonly,assign)BOOL         isMasterUser;
@property(readonly,assign)BOOL         isViewOnly;
@property(readonly,assign)BOOL         isValid;
@property(readonly,assign)BOOL         isFreeWayIndexUser;
@property(readonly,assign)BOOL         isMultistreamUser;
@property(readonly,assign)BOOL         isPairedZRUser;
@property(readonly,assign)BOOL         isSmartGalleryVideoUser;
@property(readonly,assign)BOOL         isMyself;
@property(readonly,assign)BOOL         isSupportSilentMode;
@property(readonly,assign)BOOL         isInSilentMode;
@property(readonly,assign)BOOL         isHostCohost;
@property(readonly,assign)BOOL         isHost;
@property(readonly,assign)BOOL         isCoHost;
@property(readonly,assign)BOOL         isVirtualAssistantUser;

@property(readonly,assign)BOOL         isViewOnlyInDefaultSession;
@property(readonly,assign)BOOL         isSupportProctoringMode;
@property(readonly,assign)BOOL         isInCompanionMode;
@property(readonly,assign)BOOL         isSupportZESwitchCompanionMode;
@property(readonly,assign)BOOL         isZECompanionUser;
@property(readonly,assign)BOOL         isRaiseHand;
@property(readonly,assign)BOOL         isSupportSubChat;

+ (instancetype)userWithCmmUser:(ICmmUser*)user;
+ (instancetype)userWithCmmUser:(ICmmUser*)user confSession:(nullable ZMConfSession*)confSession;
+ (instancetype)leftUserWithCmmUser:(ICmmUser*)user;
+ (instancetype)masterUserWithCmmUser:(ICmmUser*)user;
+ (instancetype)masterLeftUserWithCmmUser:(ICmmUser*)user;
+ (instancetype)userWithBuddy:(IZoomQABuddy*)buddy;
+ (nullable instancetype)userWithInviteeItem:(NS_ZOOM_DATA::ConfInviteeItem*)item;
+ (nullable instancetype)userWithInviteeCUID:(nullable NSString*)CUID email:(nullable NSString*)email;
+ (instancetype)userWithZmUser:(ZMUser*)zmUser;

+ (nullable id)userWithID:(ZMUserID)ID confSession:(ZMConfSession*)confSession;
+ (id)userWithSpecificID:(NSString*)specificID;
+ (nullable id)userWithUJID:(ZMUJID)uniqueJoinIndex confSession:(ZMConfSession*)confSession;

- (nullable ICmmUser *)getCmmUser;
- (nullable ICmmUser *)masterCmmUser;//BO get master user
- (nullable ICmmUser *)getLeftCmmUser;
- (nullable NS_ZOOM_DATA::ConfInviteeItem *)getInviteeItem;
- (nullable IZoomQABuddy*)getBuddyUser;

- (nullable NSImage *)avatarWithSize:(NSSize)size;

- (nullable NSString *)originalName;//without change TWFlag
- (nullable NSString *)masterUserName;
- (nullable NSString *)userName;
/// This leftUserName is used only by invitee who joined once and left participant list.
- (nullable NSString *)leftUserName;
- (nullable NSString *)effectiveVBFileID;

@end
NS_ASSUME_NONNULL_END
