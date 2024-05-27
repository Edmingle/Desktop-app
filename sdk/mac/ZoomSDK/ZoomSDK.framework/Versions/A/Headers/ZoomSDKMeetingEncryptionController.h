
#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"

/**
 * @brief Type of meeting encryption.
 */
typedef enum
{
    ZoomSDKEncryptionType_None,
    ZoomSDKEncryptionType_Enhanced,
    ZoomSDKEncryptionType_E2EE
}ZoomSDKEncryptionType;


@protocol ZoomSDKMeetingEncryptionDelegate <NSObject>
/**
 * @brief This callback will be called when the security code changes.
 */
- (void)onE2EEMeetingSecurityCodeChanged;
@end


@interface ZoomSDKMeetingEncryptionController : NSObject
@property(nonatomic,assign) id<ZoomSDKMeetingEncryptionDelegate> delegate;

/**
 * @brief Get meeting encryption type.
 * @return YES means the immersive view is active. Otherwise NO.
 */
- (ZoomSDKEncryptionType)getEncryptionType;

/**
 * @brief Get E2EE meeting security code.
 * @return If the function succeeds, it will return 40-digit security code. Otherwise failed.
 */
- (NSString*)getE2EEMeetingSecurityCode;

/**
 * @brief Get security code passed seconds.
 * @return If the function succeeds, it will return the time the security code exists, in seconds. Otherwise failed.
 */
- (unsigned int)getE2EEMeetingSecurityCodePassedSeconds;

/**
 * @brief Determine whether unencrypted exception data is valid,
 * @note This method can only be called when the encryption type is ZoomSDKEncryptionType_Enhanced.
 * @return YES means unencrypted exception data is valid.
 */
- (BOOL)isUnencryptedExceptionDataValid;

/**
 * @brief Get unencrypted exception count.
 * @return If the function succeeds, it will return the unencrypted exception count. Otherwise failed.
 */
- (unsigned int)getUnencryptedExceptionCount;

/**
 * @brief Get unencrypted exception info.
 * @return If the function succeeds, it will return unencrypted exception details. Otherwise failed.
 */
- (NSString*)getUnencryptedExceptionInfo;
@end
