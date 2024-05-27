
#import "authServiceDelegate.h"
#include "zoom_node_addon.h"
#include "auth_service_wrap_core.h"
extern  ZNativeSDKWrap _g_native_wrap;
@implementation authServiceDelegate

+(authServiceDelegate *)share
{
    static authServiceDelegate *delegate = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        delegate = [[authServiceDelegate alloc] init];
    });
    return delegate;
}

-(instancetype)init
{
    self = [super init];
    if (self) {
        _authResult = ZNAUTHRET_NONE;
        _loginStatus = ZNLOGIN_IDLE;
        _directStatus = DirectShareStatus_None;
        return self;
    }
    return nil;
}

-(void)dealloc
{
    _authResult = ZNAUTHRET_NONE;
    _loginStatus = ZNLOGIN_IDLE;
    _directStatus = DirectShareStatus_None;
    [super dealloc];
}
- (void)onZoomSDKAuthReturn:(ZoomSDKAuthError)returnValue
{
    nativeErrorTypeHelp native_help;
    ZNAuthResult result = native_help.ZoomSDKAuthErrorTpye(returnValue);
    self.authResult = result;
    _g_native_wrap.GetAuthServiceWrap().onAuthenticationReturn(result);
}

- (void)onZoomSDKLoginResult:(ZoomSDKLoginStatus)loginStatus failReason:(ZoomSDKLoginFailReason)reason
{
    nativeErrorTypeHelp native_login_help;
    ZNLOGINSTATUS result = native_login_help.ZoomSDKLoginStatusType(loginStatus);
    nativeErrorTypeHelp help;
    ZNLoginFailReason failReason = help.ZNLoginFailReasonMap(reason);
    _g_native_wrap.GetAuthServiceWrap().onLoginReturnWithReason(result,failReason);
}

-(void)onZoomSDKLogout
{
    _g_native_wrap.GetAuthServiceWrap().onLogout();
}

-(void)onZoomIdentityExpired
{
    _g_native_wrap.GetAuthServiceWrap().onZoomIdentityExpired();
}

-(ZNAuthResult)getAuthResult
{
    return self.authResult;
}

-(ZNLOGINSTATUS)getLoginStatus
{
    return self.loginStatus;
}

-(void)onZoomAuthIdentityExpired
{
    _g_native_wrap.GetAuthServiceWrap().onZoomAuthIdentityExpired();
}

#pragma direct share
-(void)onDirectShareStatusReceived:(DirectShareStatus)status DirectShareReceived:(ZoomSDKDirectShareHandler *)handler
{
    nativeErrorTypeHelp help;
    ZNDirectShareStatus  ZNStatus = help.ZNSDKDirectShareStatus(status);
    self.directStatus = status;
    self.DirectShareHandler = handler;
    _g_native_wrap.GetAuthServiceWrap().GetDirectShareHelper().OnDirectShareStatusUpdate(ZNStatus);
}


-(DirectShareStatus)getDirectShare
{
    return self.directStatus;
}

-(ZoomSDKDirectShareHandler *)getDirectShareHandler
{
    return self.DirectShareHandler;
}

@end

@implementation ZoomSDKRemindDelegate

+(ZoomSDKRemindDelegate *)share
{
    static ZoomSDKRemindDelegate *delegate = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        delegate = [[ZoomSDKRemindDelegate alloc] init];
    });
    return delegate;
}

-(instancetype)init
{
    self = [super init];
    if (self) {
        _reminderHandler = nil;
        _enableReminderHandler = nil;
        return self;
    }
    return nil;
}

-(void)dealloc
{
    if(_reminderHandler)
    {
        [_reminderHandler release];
        _reminderHandler = nil;
    }
    if(_enableReminderHandler)
    {
        [_enableReminderHandler release];
        _enableReminderHandler = nil;
    }
    [super dealloc];
}
#pragma reminder delegate
-(void)onReminderNotify:(ZoomSDKReminderHandler*)handle reminderContent:(ZoomSDKReminderContent*)content
{
    self.reminderHandler = handle;
    ZNMeetingReminderContent remindContent;
    if (content) {
        nativeErrorTypeHelp help;
        ZoomSDKReminderType sdkRemindType = content.type;
        remindContent.type = help.ZNReminderTypeMap(sdkRemindType);
        remindContent.title = (content.title ? [content.title UTF8String]: "");
        remindContent.content = (content.title ? [content.content UTF8String]: "");
        remindContent.is_blocking = content.isBlocking;
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingReminderCtrl().onReminderNotify(remindContent);
}

-(void)onEnableReminderNotify:(ZoomSDKMeetingEnableReminderHandler*)handle reminderContent:(ZoomSDKReminderContent*)content
{
    self.enableReminderHandler = handle;
    ZNMeetingReminderContent remindContent;
    if (content) {
        nativeErrorTypeHelp help;
        ZoomSDKReminderType sdkRemindType = content.type;
        remindContent.type = help.ZNReminderTypeMap(sdkRemindType);
        remindContent.title = (content.title ? [content.title UTF8String]: "");
        remindContent.content = (content.title ? [content.content UTF8String]: "");
        remindContent.is_blocking = content.isBlocking;
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingReminderCtrl().onEnableReminderNotify(remindContent);
}

@end

