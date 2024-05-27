//
//  ZMIMDataInfo.h
//  zChatUI
//
//  Created by likevin on 2019/5/18.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <dataModule/zDataConstants.h>
#import <zChatComponent/ZMTranslationManagerProtocol.h>

@interface ZMOnZoomOpenChatOption : NSObject
@property (assign)  NSInteger      viewMode; // 0 - docking; 1 - floating
@property (assign)  BOOL           canShowTitleBar;
@property (assign)  BOOL           canShowInfoPanel;
@property (assign)  BOOL           canShowInputToolbar;

+ (ZMOnZoomOpenChatOption*)createZMOnZoomOpenChatOption:(void*)sdkChatOption;
@end


typedef NS_ENUM(NSInteger, ZMReportTag){
	
	ZMReportTag_ReportUser = 1,
	ZMReportTag_RemoveChatMsg,
	ZMReportTagTag_ReportRemoveUserAndMsg,
};


typedef enum
{
    ZMSearchArchivedStatus_None        = 0,
    ZMSearchArchivedStatus_Archived    = 1,
    ZMSearchArchivedStatus_Unarchived  = 2,
    ZMSearchArchivedStatus_All         = 3,
}ZMSearchArchivedStatus;

@interface ZMReportInChannelCommonInfo : NSObject
@property (assign)  ZMReportTag             reportTag;
@property (assign)  BOOL                    isAdmin;
@property (assign)	ReportInChannelAction   reportAction;
@property (assign)	RemoveInChannelAction   removeAction;
@property (assign)	ReportInChannelType     reportType;
@property (copy)    NSString*      channelID;
@property (copy)    NSString*      msgID;
@property (copy)    NSString*      reportedUserName; //  only enabled in ui callback
@property (retain)  NSArray<NSImage*> * sourceImageArray; //screenshot
@property (copy)    NSArray<NSString*> * imagePathArray;
@property (assign)  BOOL                    is1v1ZoomEventChannel;
- (void)processLongUserName;
@end

@interface ZMReportInChannelRes : NSObject
@property (assign)  NSInteger      result;
@property (retain)  ZMReportInChannelCommonInfo* commonInfo;
@property (assign)  ReportInChannelErrorType  errorType;
+ (ZMReportInChannelRes*)createZMReportInChannelRes:(void*)sdkReportInChannelRes NS_RETURNS_RETAINED;
@end

@interface ZMRoomPreviewPrivilegeInfo : NSObject
@property (nonatomic, assign) NSUInteger previewPrivilegeType;
@property (nonatomic, assign) NSInteger option; // room flags
@property (nonatomic, assign, getter=isExternalUser) BOOL externalUser; // the requester is an external user as the MUC owner or not
@property (nonatomic, assign, getter=isAccountTrusted) BOOL accountTrusted; // the requester already trusts this account or not
@property (nonatomic, copy) NSString *accountName; // the account name of the MUC owner, eg. Zoom IT
@property (nonatomic, copy) NSString *sessionName; // the name of channel/muc
@end

@interface ZMPreviewGroupInfo : NSObject
@property (copy)    NSString*      reqId;
@property (assign)  NSInteger      result;
@property (copy)    NSString*      groupId;
@property (copy)    NSString*      groupName;
@property (copy)    NSString*      groupDesc;
@property (assign)  NSInteger      totalMemberCount;
@property (assign)  NSInteger      roomFlags;
@property (nonatomic, retain) ZMRoomPreviewPrivilegeInfo *previewPrivilegeInfo;

@property (retain)  NSArray* memberArray;

+ (ZMPreviewGroupInfo*)createZMPreviewGroupInfo:(void*)sdkPreviewGroupInfo NS_RETURNS_RETAINED;
@end

@interface ZMOutdatedLocalFileInfo : NSObject
@property (assign)  NSInteger      type;
@property (copy)    NSString*      fileId;
@property (copy)    NSString*      path;
@property (copy)    NSString*      originalPath;
@property (copy)    NSString*      previewPath;
@property (retain)    NSArray<NSString*>*      tmpPathArray;
+ (ZMOutdatedLocalFileInfo*)createZMOutdatedLocalFileInfo:(void*)sdkOutdatedLocalFileInfo NS_RETURNS_RETAINED;
@end


/*@interface ZMWBPreviewInfo: NSObject
@property (assign)  NSInteger      fileIndex;
@property (copy)    NSString*      fileId;
@property (copy)    NSString*      title;
@property (copy)    NSString*      link;
@property (copy)    NSString*      fileName;
@property (assign)  NSInteger      fileSize;
@property (assign)  NSSize         imageSize;
@property (assign)  BOOL           hasAccess;

+ (ZMWBPreviewInfo*)createZMWBPreviewInfo:(void*)pTmpSdkWBPreviewInfo;
@end*/


@interface ZMChannelMemberSearchFilter : NSObject

@property (copy)    NSString*      channelId;
@property (copy)    NSString*      keyWord;
@property (assign)  NSUInteger      pageNum;
@property (assign)  NSUInteger      maxSize;

@end

@interface ZMChannelSearchFilter : NSObject
@property (assign)  ZMSearchArchivedStatus archivedStatus;

@end

@class ZMIMMessageDraft,ZMFileEntity;

@interface ZMEditMessageInfo : NSObject

@property (nonatomic, copy, nullable) NSAttributedString *editString;

@property (nonatomic, copy, nullable) NSArray<ZMFileEntity *> *editFileList;

@property (nonatomic, readonly, nullable) NSString *activeDraftID;

@property (nonatomic, retain, nullable) ZMIMMessageDraft *draft;

@property (nonatomic, assign) BOOL isSavingDraft;

@property (nonatomic, assign) BOOL needUpdateFileWebIds;

- (BOOL)isEmpty;

- (void)cleanContent;

- (void)updateFileWebIDs:(nonnull NSArray <ZMFileEntity *> *)fileList;

@end

@interface ZMCopyMessageInfo : NSObject

@property (nonatomic, copy) NSString * _Nullable string;
@property (nonatomic, retain) NSArray<ZMMessageFontInfo *> * _Nullable fontStyleInfoList;
@property (nonatomic, retain) NSArray<NSURL *> * _Nullable fileURLs;
@property (nonatomic, readonly) BOOL isEmpty;
- (void)writeToPasteboard;
@end


typedef NS_ENUM(int64_t, ZMTranslationState) {
    /// no translation request has been sent
    ZMTranslationState_None = 0,
    /// waiting for server response
    ZMTranslationState_Loading,
    /// server provided a translation
    ZMTranslationState_Translated,
    /// server failed to provide a translation. Retrying may succeed.
    ZMTranslationState_FailedRecoverable,
    /// server failed to provide a translation. Retrying is unlikely to succeed.
    ZMTranslationState_FailedUnrecoverable,
};


@interface ZMMessageTranslationInfo : NSObject
@property (nonatomic, assign) ZMTranslationState state;
/// The SDK translation-request ID for this message's latest translation
@property (nonatomic, copy) NSString* _Nullable requestID;
/// The message's translated text. nil if state != ZMTranslationState_Succeeded
@property (nullable, nonatomic, copy) NSString* translation;
/// The language the message was translated from.
@property (nonatomic, copy) ZMLanguageCode _Nonnull sourceLanguage;
/// A localized string describing the reason for translation failure.
/// non-nil only when state is a failure value, e.g. ZMTranslationState_FailedRecoverable
@property (nullable, nonatomic, copy) NSString* failureMessage;
@end


