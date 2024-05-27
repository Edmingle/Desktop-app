//
//  ZMMTArchiveHelper.h
//  VideoUIBridge
//
//  Created by davies zhao on 2023/8/24.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTArchiveHelper : ZMBaseHelper
#pragma mark - single cma
- (BOOL)isMeetingArchiveInProgress;
- (NSInteger)getMeetingArchiveOptions;
- (BOOL)isMeetingArchiveFailed;
- (BOOL)needPromptArchiveDisclaimer;

#pragma mark - mutiple cma
- (BOOL)isMultipleCMAEnabled;
- (NSUInteger)getCMAOptions;
- (BOOL)hasCMAInProgress;
#ifdef __cplusplus
- (archive_gw_status)getCMAStatusByRegion:(CString&)region;
#endif

- (BOOL)hasArchiveInProgress;
- (NSInteger)getArchiveOptions;
- (BOOL)enableShowArchiveIcon:(ZMUser *)user;

- (BOOL)isArchiveNoticeAvailable;
@end

NS_ASSUME_NONNULL_END
