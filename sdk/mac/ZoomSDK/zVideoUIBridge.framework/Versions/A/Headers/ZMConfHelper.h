//
//  ZMConfHelper.h
//  SaasBeeConfUIModule
//
//  Created by John on 15/2/14.
//  Copyright (c) 2015年 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMUIConstants.h>
#import <zVideoUIBridge/ZMBaseHelper.h>

@interface ZMConfHelper : ZMBaseHelper

+ (ICmmConfMgrAPI*)getConfApi;
+ (ICmmConfContext*)getConfContext;
+ (ICmmConfStatus*)getConfStatusObject;
+ (ICmmVideoAPI*)getVideoApi;
+ (ICmmVideoBkgndImageMgr*)getVBApi;
+ (ICmmAudioAPI*)getAudioApi;
+ (ICmmShareAPI*)getShareApi;
+ (IZoomRaiseHandInWebinar*)getWebinarHandApi;
+ (IZoomQAComponent*)getQAComponent;
+ (ICmmBOMgrAPI*)getBOMgrApi;
+ (IZoomChatInWebinar*)getWebinarChatComponent;
+ (ICmmShareSource*)getShareSourceById:(ZMUserID)inUserId;
+ (ICmmPollAPI*)getPollApi;
+ (ICmmAttentionTrackMgrAPI*)getAttentionTrackApi;//ZOOM-4026
+ (ICmmFeedbackMgrAPI*)getFeedbackApi;
+ (ISBMeetingItem*)getMeetingItem;
+ (ICmmChatComponent*)getChatAPIObj;//ZOOM-14788
+ (ICmmRecordAPI*)getRecordApi;//[Zoom-16564]
+ (CMM_SHARESTATUS)getShareStatus;//[Zoom-16564]
+ (ICmmAnnotationAPI*)getAnnotationAPI:(void *)viewHandle;//ZOOM-66434
+ (ICmmInterpretationMgr *)getInterpretationObj;//ZOOM-73504
+ (ICmmSceneBkgndMgr *)getSceneBkgndApi;//ZOOM-261363
+ (ICmmCloudDocumentAPI *)getCloudDocumentApi;
+ (ICmmNatvieWhiteboardAPI *)getNativeWhiteboardApi;
+ (ICmmWhiteboardContainerAPI *)getWhiteboardContainerApi;
#ifdef ENABLE_ZAPP
+ (IZappService*)getZappAPI;
+ (IZappJSRegister *)getZappJsRegisterInterface;
#endif
+ (ICmmConfAppAPI*)getConfAppApi;//ZOOM-266431
+ (ICmmGRMgrAPI *)getGRMgrApi;
+ (zm::multi_conf_ins::IFeature *)getGRFeatureApi;
+ (ICmmConfInst *)getBackstageInst;
+ (ICmmWebAgentAPI*)getWebAgentAPI;
+ (ICmmConfEventTrackingAPI *)getEventTrackingAPI;
+ (ISBPTAppAPI*)getPtAppAPI;//ZOOM-381157
+ (ICmmConfJoiner*)getConfJoinerAPI;
+ (ICmmQAApi*)getQAApi;//jeffery add
#pragma mark - WebinarBO
+ (zm::new_bo::INewBOManager *)getNewBOMgrApi;
+ (zm::multi_conf_ins::IFeature *)getNewBOFeatureApi;
+ (zm::new_bo::IBOControl *)getNewBOControlApi;
+ (zm::new_bo::IBOMainConf *)getNewBOMainConfApi;
#pragma mark - PBO
+ (zm::pbo::IPBOManager *)getPBOMgrApi;
+ (zm::multi_conf_ins::IFeature *)getPBOFeatureApi;
+ (zm::pbo::IPBOControl *)getPBOControlApi;
+ (zm::pbo::IPBOMainConf *)getPBOMainConfApi;

- (ICmmConfInst *)getConfInst;
- (ICmmConfContext*)getConfInstContext;
- (ICmmConfStatus*)getConfInstStatusObject;
- (CmmUInt32)getConfInstId;
- (ICmmVideoAPI*)getConfInstVideoApi;
- (ICmmAudioAPI*)getConfInstAudioApi;
- (ICmmShareAPI*)getConfInstShareApi;
- (IZoomRaiseHandInWebinar*)getConfInstWebinarHandApi;
- (IZoomQAComponent*)getConfInstQAComponent;
- (ICmmQAApi *)getConfInstQAApi;
- (IZoomChatInWebinar*)getConfInstWebinarChatComponent;
- (ICmmShareSource*)getConfInstShareSourceById:(ZMUserID)inUserId;
- (ICmmPollAPI*)getConfInstPollApi;
- (ICmmAttentionTrackMgrAPI*)getConfInstAttentionTrackApi;
- (ICmmFeedbackMgrAPI*)getConfInstFeedbackApi;
- (ISBMeetingItem*)getConfInstMeetingItem;
- (ICmmChatComponent*)getConfInstChatAPIObj;
- (ICmmRecordAPI*)getConfInstRecordApi;
- (CMM_SHARESTATUS)getConfInstShareStatus;//[Zoom-16564]
- (ICmmAnnotationAPI*)getConfInstAnnotationAPI:(void *)viewHandle;
- (ICmmInterpretationMgr *)getConfInstInterpretationObj;//ZOOM-73504
- (ICmmSignInterpretationMgr *)getConfInstSignInterpretationObj;//ZOOM-330475
- (ICmmCloudDocumentAPI*)getConfInstCloudDocumentAPI;
- (ICmmNatvieWhiteboardAPI*)getConfInstNativeWhiteboardApi;
- (ICmmWhiteboardContainerAPI*)getConfInstWhiteboardContainerApi;
- (ICmmZoomNotesApi*)getConfInstNotesApi;
- (ICmmLTTAPI *)getLTTApi;//ZOOM-283768
- (ICmmStudioAPI *)getStudioApp;
- (IZoomLaunchConfParameter *)getLanuchConfParamenter;
#pragma mark - newBO
- (zm::new_bo::IBOControl *)getNewBOControlApi;
- (std::shared_ptr<zm::new_bo::IBOList>)getNewBOListApi;
- (std::shared_ptr<zm::new_bo::IBORoom>)getNewBORoomApi;

- (zm::multi_conf_ins::IFeature *)getPBOFeatureApi;
- (zm::pbo::IPBOControl *)getPBOControlApi;
- (std::shared_ptr<zm::pbo::IPBORoom>)getPBORoomApi;

#pragma mark - SpotsBO
#ifdef ENABLE_ZAPP
- (zm::spots::ISpotsControl *)getSpotsBOControlApi;
+ (zm::spots::ISpotsManager *)getSpotsBOMgrApi;
+ (zm::multi_conf_ins::IFeature *)getSpotsBOFeatureApi;
- (std::shared_ptr<zm::spots::ISpotsData>)getSpotsBOList;
+ (ICmmConfInst *)getSpotsBOMainConfInst;
- (std::shared_ptr<zm::spots::IBubble>)getSpotsBORoomApi;
#endif

#pragma mark - Docs
- (zm::docs::ICmmZoomDocsAPI *)getConfDocsAPI;
@end
