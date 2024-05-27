//
//  ZMUnifyWebURLSchemeHelper.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/12/1.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "ZMUnifyWebViewDefine.h"
#import <ZoomUnit/ZPZAppAdapter.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^ZMUnifyWebSchemeBlockTask)(NSURLRequest *request);
typedef NSString * _Nullable (^ZMUnifyWebSchemeTaskIdentityID)(NSURLRequest *request);
typedef NSData * _Nullable (^ZMUnifyWebSchemeTaskData)(NSURLRequest *request);

API_AVAILABLE(macos(10.13))
@protocol ZMUnifyWebURLSchemeHandler <NSObject, WKURLSchemeHandler, ZMUnifyWebViewURLSchemeHandlerProtocol>

@property (nonatomic, copy) NSString *urlScheme;
@property (nonatomic, assign) NSInteger appType;

@property (nonatomic, copy) ZMUnifyWebSchemeBlockTask task;
@property (nonatomic, copy) ZMUnifyWebSchemeTaskIdentityID getIdentityID;
@property (nonatomic, copy) ZMUnifyWebSchemeTaskData getData;

- (void)finishSchemeTask:(BOOL)success identityID:(NSString *)identityID data:(NSData *)data response:(NSURLResponse *)response;
- (void)finishSchemeTask:(BOOL)success identityID:(NSString *)identityID fullPath:(NSString *)fullPath response:(NSURLResponse *)response;

@end

@interface ZMUnifyWebURLSchemeHelper : NSObject

+ (ZMUnifyWebURLSchemeHelper *)shareInstance;

- (id<ZMUnifyWebURLSchemeHandler>)generateUnifyURLSchemeHandler;
- (void)deleteUnifyURLSchemeHandler:(id<ZMUnifyWebURLSchemeHandler>)handler;

@end

NS_ASSUME_NONNULL_END
