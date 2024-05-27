//
//  ZMMTFeatureMgrSink.h
//  VideoUI
//
//  Created by Francis Zhuo on 10/17/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTFeatureMgrSinkAdapter;
class ZMMTFeatureMgrSink : public zm::multi_conf_ins::IFeatureManagerSink
{
public:
    ZMMTFeatureMgrSink(ZMMTFeatureMgrSinkAdapter *adapter);
    virtual ~ZMMTFeatureMgrSink(void);

public:
    virtual void OnPrepareFeatureMaterial(zm::multi_conf_ins::FeatureType nFeature, zm::multi_conf_ins::FeatureMaterial& fm) override;
    virtual void OnFeatureCreated(CmmBool bOk, zm::multi_conf_ins::FeatureType nFeature) override;
    virtual void OnFeatureDestroying(zm::multi_conf_ins::FeatureType nFeature) override;
        
    virtual void OnBeginSwitchFeature(const zm::multi_conf_ins::FeatureDetails& newRoom, const std::vector<zm::multi_conf_ins::FeatureDetails>& oldRoom, const zm::multi_conf_ins::FeatureSwitchDetails& fsd) override;
    virtual void OnSwitchFeature(const zm::multi_conf_ins::FeatureDetails& finalRoom, const zm::multi_conf_ins::FeatureSwitchResult& result) override;
    
protected:
    ZMMTFeatureMgrSinkAdapter  *_Nullable m_sinkAdapter;
};

@interface ZMMTFeatureMgrSinkAdapter : NSObject
- (void)onPrepareFeatureMaterial:(zm::multi_conf_ins::FeatureType)featureType material:(zm::multi_conf_ins::FeatureMaterial&)material;
- (void)onFeatureCreated:(CmmBool)success forFeature:(zm::multi_conf_ins::FeatureType)featureType;
- (void)onFeatureDestroying:(zm::multi_conf_ins::FeatureType)nFeature;
- (void)onBeginSwitchFeature:(const zm::multi_conf_ins::FeatureDetails&)newRoom oldRooms:(const std::vector<zm::multi_conf_ins::FeatureDetails>&)oldRooms;
- (void)onEndedSwitchFeature:(const zm::multi_conf_ins::FeatureDetails&)finalRoom success:(BOOL)success;
@end

NS_ASSUME_NONNULL_END
