//
//  ZMMessagePreviewContext.h
//  zChatComponent
//
//  Created by Cyan.Yang on 2022/10/24.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ZMMessagePreviewContextPreset) {
    ZMMessagePreviewContextPresetSidebar = 0,
    ZMMessagePreviewContextPresetPushNotification,
    ZMMessagePreviewContextPresetPin,
    ZMMessagePreviewContextPresetSharing,
};

NS_ASSUME_NONNULL_BEGIN

@interface ZMMessagePreviewContext : NSObject

/// A Boolean that controls whether message body and file description should
/// stay in a signle line.
@property (nonatomic, assign) BOOL prefersSingleLine;

@property (nonatomic, assign) BOOL removesNewlines;
@property (nonatomic, assign) BOOL wantsFileDescription;
@property (nonatomic, assign) BOOL wantsCodeSnippetContents;
@property (nonatomic, assign) BOOL wantsImageFileName;

+ (instancetype)contextWithPreset:(ZMMessagePreviewContextPreset)preset;

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithPreset:(ZMMessagePreviewContextPreset)preset;

@end

NS_ASSUME_NONNULL_END
