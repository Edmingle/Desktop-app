//
//  ZMConfSession.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/6/17.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMUIConstants.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMConfHelper;
@class ZMRecordHelper;
@class ZMMTAudioHelper;
@class ZMUserHelper;
@class ZMVideoHelper;
@class ZMBOHelper;
@class ZMMTSummaryHelper;
@class ZMMTAICPlusHelper;
@class ZMMTCoachMarkHelper;
@class ZMMTQueriesHelper;
@class ZMMTInterpretHelper;
@class ZMMTCCHelper;
@class ZMMTChatHelper;
@protocol IZMMTPinVideoMgr;
@class ZMMTStudioHelper;
@class ZMMTCallCenter;
@class ZMMTConfigHelper;
@class ZPConfHelper;
@class ZMPBOHelper;
@class ZMMTReactionHelper;
@class ZMMTArchiveHelper;

@interface ZMConfSession : NSObject <NSCopying>

@property(assign) ZMConfInstType sessionType;
@property(copy) NSString* identifier;
@property(assign) NSInteger roomID;//eg:new BO roomID

- (instancetype)initWithID:(NSString*)identifier;
+ (instancetype)sessionWithID:(NSString*)identifier;

@property(nonatomic,readonly, weak) ZMConfHelper* zmConfHelper;
@property(nonatomic,readonly, weak) ZMRecordHelper* recordHelper;
@property(nonatomic,readonly, weak) ZMMTAudioHelper* zmAudioHelper;
@property(nonatomic,readonly, weak) ZPConfHelper* zpConfHelper;
@property(nonatomic,readonly, weak) ZMUserHelper* zmUserHelper;
@property(nonatomic,readonly, weak) ZMVideoHelper* zmVideoHelper;
@property(nonatomic,readonly, weak) ZMMTInterpretHelper* zmInterpretHelper;
@property(nonatomic,readonly, weak) ZMMTCCHelper* ccHelper;
@property(nonatomic,readonly, weak) ZMBOHelper* zmBOHelper;
@property(nonatomic,readonly, weak) ZMMTQueriesHelper* zmQueriesHelper;
@property(nonatomic,readonly, weak) ZMMTSummaryHelper* zmSummaryHelper;
@property(nonatomic,readonly, weak) ZMMTAICPlusHelper* zmAICPlusHelper;
@property(nonatomic,readonly, weak) ZMMTCoachMarkHelper* zmCoachMarkHelper;
@property(nonatomic,readonly, weak) ZMMTStudioHelper* studioHelper;
@property(nonatomic,readonly, weak) id<IZMMTPinVideoMgr> pinVideoMgr;
@property(nonatomic,readonly, weak) ZMMTChatHelper *zmChatHelper;
@property(nonatomic,readonly, weak) ZMMTCallCenter *callCenter;
@property(nonatomic,readonly, weak) ZMMTConfigHelper* configHelper;//local config
@property(nonatomic,readonly, weak) ZMPBOHelper* zmPBOHelper;
@property(nonatomic,readonly, weak) ZMMTReactionHelper* reactionHelper;
@property(nonatomic,readonly, weak) ZMMTArchiveHelper* archiveHelper;

- (void)startSession;
- (void)stopSession;

@property(assign) BOOL isReady;
@property(assign) BOOL isLeave;
@property(nonatomic,readonly, copy) NSString* sessionName;
/**
 * If you are in the backstage, defaultSession means mainstage session
 * If you are in the breakout room, defaultSession means breakout room and boMasterSession means the mainstage session
 */
+ (instancetype)defaultSession;
+ (instancetype)backstageSession;
+ (instancetype)boMasterSession;
+ (instancetype)currentSession;

+ (instancetype)commonSession;//just use in forceUpdate
+ (instancetype)transitionSession;//just use in transition, not a real confInst

- (BOOL)isDefaultSession;
- (BOOL)isBackstageSession;//GR
- (BOOL)isBOMasterSession;
- (BOOL)isCurrentSession;
- (BOOL)isNewBOSession;//newBO
- (BOOL)isPBOSession;

- (BOOL)isTransitionSession;
//spots BO
- (BOOL)isSpotsBOSession;

@end

NS_ASSUME_NONNULL_END
