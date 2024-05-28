#if 0
#elif defined(__x86_64__) && __x86_64__
// Generated by Apple Swift version 5.9.2 (swiftlang-5.9.2.2.56 clang-1500.1.0.2.5)
#ifndef ZCHATCOMPONENT_SWIFT_H
#define ZCHATCOMPONENT_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#if defined(__OBJC__)
#include <Foundation/Foundation.h>
#endif
#if defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <cstdbool>
#include <cstring>
#include <stdlib.h>
#include <new>
#include <type_traits>
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#endif
#if defined(__cplusplus)
#if defined(__arm64e__) && __has_include(<ptrauth.h>)
# include <ptrauth.h>
#else
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-macro-identifier"
# ifndef __ptrauth_swift_value_witness_function_pointer
#  define __ptrauth_swift_value_witness_function_pointer(x)
# endif
# ifndef __ptrauth_swift_class_method_pointer
#  define __ptrauth_swift_class_method_pointer(x)
# endif
#pragma clang diagnostic pop
#endif
#endif

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...) 
# endif
#endif
#if !defined(SWIFT_RUNTIME_NAME)
# if __has_attribute(objc_runtime_name)
#  define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
# else
#  define SWIFT_RUNTIME_NAME(X) 
# endif
#endif
#if !defined(SWIFT_COMPILE_NAME)
# if __has_attribute(swift_name)
#  define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
# else
#  define SWIFT_COMPILE_NAME(X) 
# endif
#endif
#if !defined(SWIFT_METHOD_FAMILY)
# if __has_attribute(objc_method_family)
#  define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
# else
#  define SWIFT_METHOD_FAMILY(X) 
# endif
#endif
#if !defined(SWIFT_NOESCAPE)
# if __has_attribute(noescape)
#  define SWIFT_NOESCAPE __attribute__((noescape))
# else
#  define SWIFT_NOESCAPE 
# endif
#endif
#if !defined(SWIFT_RELEASES_ARGUMENT)
# if __has_attribute(ns_consumed)
#  define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
# else
#  define SWIFT_RELEASES_ARGUMENT 
# endif
#endif
#if !defined(SWIFT_WARN_UNUSED_RESULT)
# if __has_attribute(warn_unused_result)
#  define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
# else
#  define SWIFT_WARN_UNUSED_RESULT 
# endif
#endif
#if !defined(SWIFT_NORETURN)
# if __has_attribute(noreturn)
#  define SWIFT_NORETURN __attribute__((noreturn))
# else
#  define SWIFT_NORETURN 
# endif
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA 
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA 
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA 
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif
#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif
#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER 
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility) 
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED_OBJC)
# if __has_feature(attribute_diagnose_if_objc)
#  define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
# else
#  define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
# endif
#endif
#if defined(__OBJC__)
#if !defined(IBSegueAction)
# define IBSegueAction 
#endif
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if !defined(SWIFT_CALL)
# define SWIFT_CALL __attribute__((swiftcall))
#endif
#if !defined(SWIFT_INDIRECT_RESULT)
# define SWIFT_INDIRECT_RESULT __attribute__((swift_indirect_result))
#endif
#if !defined(SWIFT_CONTEXT)
# define SWIFT_CONTEXT __attribute__((swift_context))
#endif
#if !defined(SWIFT_ERROR_RESULT)
# define SWIFT_ERROR_RESULT __attribute__((swift_error_result))
#endif
#if defined(__cplusplus)
# define SWIFT_NOEXCEPT noexcept
#else
# define SWIFT_NOEXCEPT 
#endif
#if !defined(SWIFT_C_INLINE_THUNK)
# if __has_attribute(always_inline)
# if __has_attribute(nodebug)
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline)) __attribute__((nodebug))
# else
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline))
# endif
# else
#  define SWIFT_C_INLINE_THUNK inline
# endif
#endif
#if defined(_WIN32)
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL __declspec(dllimport)
#endif
#else
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL 
#endif
#endif
#if defined(__OBJC__)
#if __has_feature(objc_modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import AppKit;
@import CoreFoundation;
@import Foundation;
@import ObjectiveC;
@import ZoomKit;
#endif

#import <zChatComponent/zChatComponent.h>

#endif
#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="zChatComponent",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

#if defined(__OBJC__)
@class NSCoder;

SWIFT_CLASS_NAMED("AddStickerView")
@interface ZMAddStickerView : ZMBaseView
- (nonnull instancetype)initWithFrame:(NSRect)frameRect OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS_NAMED("AttachmentLabel")
@interface ZMAttachmentLabel : ZMLabel
@property (nonatomic) NSRect frame;
@property (nonatomic) NSRect bounds;
- (void)setNeedsDisplayInRect:(NSRect)invalidRect;
- (void)drawRect:(NSRect)dirtyRect;
- (nonnull instancetype)initWithFrame:(NSRect)frameRect OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end

@class ZMBaseTextAttachmentCell;

@interface ZMAttachmentLabel (SWIFT_EXTENSION(zChatComponent)) <ZMBaseTextProtocol>
- (void)addAttachmentCell:(ZMBaseTextAttachmentCell * _Nonnull)attachmentCell withFrame:(CGRect)frame;
@end

typedef SWIFT_ENUM(NSInteger, CenterVerticalAlignment, open) {
  CenterVerticalAlignmentLeft = 0,
  CenterVerticalAlignmentRight = 1,
  CenterVerticalAlignmentCenter = 2,
};

@class NSString;
@class NSColor;

SWIFT_CLASS_NAMED("CenterVerticalLabel")
@interface ZMCenterVerticalLabel : NSView
@property (nonatomic, readonly, copy) NSString * _Nonnull stringValue;
@property (nonatomic, readonly) CGFloat fontSize;
@property (nonatomic, strong) NSColor * _Nonnull color;
@property (nonatomic) enum CenterVerticalAlignment alignment;
@property (nonatomic, copy) NSString * _Nullable fontName;
- (NSString * _Nullable)accessibilityLabel SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, readonly) NSSize intrinsicContentSize;
- (void)updateStringValue:(NSString * _Nullable)stringValue;
- (void)updateFontSize:(CGFloat)fontSize;
- (void)updateStringValue:(NSString * _Nullable)stringValue fontSize:(CGFloat)fontSize;
- (void)drawRect:(NSRect)dirtyRect;
- (NSView * _Nullable)hitTest:(NSPoint)point SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)initWithFrame:(NSRect)frameRect OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end

enum ZMCommonAppAlertLevel : NSInteger;
@class NSTextContainer;
@class NSImage;

SWIFT_CLASS_NAMED("CommonAppAlertCell")
@interface ZMPTCommonAppAlertCell : ZMPTCommonBaseCell
@property (nonatomic, copy) NSString * _Nonnull title;
/// Level of the alert.
@property (nonatomic) enum ZMCommonAppAlertLevel level;
/// A Boolean value that indicates whether a close button is shown.
@property (nonatomic) BOOL closable;
@property (nonatomic, copy) void (^ _Nullable closeHandler)(void);
@property (nonatomic) NSInteger messageTemplateIndex;
@property (nonatomic, copy) NSString * _Nullable eventID;
- (NSString * _Nullable)copyString SWIFT_WARN_UNUSED_RESULT;
- (NSRect)cellFrameForTextContainer:(NSTextContainer * _Nonnull)textContainer proposedLineFragment:(NSRect)lineFrag glyphPosition:(NSPoint)position characterIndex:(NSUInteger)charIndex SWIFT_WARN_UNUSED_RESULT;
- (void)drawWithFrame:(NSRect)cellFrame inView:(NSView * _Nullable)controlView;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initTextCell:(NSString * _Nonnull)string OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initImageCell:(NSImage * _Nullable)image OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


@interface ZMPTCommonAppAlertCell (SWIFT_EXTENSION(zChatComponent)) <ZMViewAttachmentCellProtocol>
@property (nonatomic, readonly, strong) NSView * _Nonnull imageView;
- (void)cleanUp;
@end


SWIFT_CLASS_NAMED("CommonAppAlertItem")
@interface ZMCommonAppAlertItem : ZMCommonAppBaseItem
@property (nonatomic) enum ZMCommonAppAlertLevel level;
@property (nonatomic) BOOL closable;
@property (nonatomic, copy) NSString * _Nullable eventID;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM_NAMED(NSInteger, ZMCommonAppAlertLevel, "CommonAppAlertLevel", open) {
  ZMCommonAppAlertLevelError = 0,
};


SWIFT_CLASS_NAMED("CommonAppChannelCell")
@interface ZMPTCommonAppChannelCell : ZMPTCommonBaseCell
@property (nonatomic, copy) NSString * _Nonnull title;
/// The number that displays after the title.
/// When the number in this property is <code>0</code>, the cell doesn’t display a
/// badge. When the number is greater than <code>0</code>, a red badge with this
/// number is displayed after the title label.
@property (nonatomic) NSUInteger badgeCount;
/// A short text displayed before the badge.
/// When <code>badgeCount</code> is greater than <code>0</code>, you can set this property to
/// show a short text before the badge. This property does nothing when
/// <code>badgeCount</code> is <code>0</code>.
@property (nonatomic, copy) NSString * _Nullable badgeInformativeText;
/// The icon that displays before the title.
@property (nonatomic, strong) NSImage * _Nullable iconImage;
- (NSRect)cellFrameForTextContainer:(NSTextContainer * _Nonnull)textContainer proposedLineFragment:(NSRect)lineFrag glyphPosition:(NSPoint)position characterIndex:(NSUInteger)charIndex SWIFT_WARN_UNUSED_RESULT;
- (void)drawWithFrame:(NSRect)cellFrame inView:(NSView * _Nullable)controlView;
- (NSAccessibilityRole _Nullable)accessibilityRole SWIFT_WARN_UNUSED_RESULT;
- (NSString * _Nullable)accessibilityTitle SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initTextCell:(NSString * _Nonnull)string OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initImageCell:(NSImage * _Nullable)image OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


enum ZMCommonAppChannelMentionType : NSInteger;

SWIFT_CLASS_NAMED("CommonAppChannelItem")
@interface ZMCommonAppChannelItem : ZMCommonAppBaseItem
@property (nonatomic) enum ZMCommonAppChannelMentionType mentionType;
@property (nonatomic, copy) NSString * _Nullable iconType;
@property (nonatomic, copy) NSString * _Nullable sessionID;
@property (nonatomic) NSUInteger unreadCount;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM_NAMED(NSInteger, ZMCommonAppChannelMentionType, "CommonAppChannelMentionType", open) {
  ZMCommonAppChannelMentionTypeNone = 0,
  ZMCommonAppChannelMentionTypeAtMe = 1,
  ZMCommonAppChannelMentionTypeAtMePlus = 2,
  ZMCommonAppChannelMentionTypeAtAll = 3,
};

enum ZMPTCommonAppCheckboxStyle : NSInteger;

SWIFT_CLASS_NAMED("CommonAppCheckboxCell")
@interface ZMPTCommonAppCheckboxCell : ZMPTCommonBaseCell
@property (nonatomic) NSInteger messageTemplateIndex;
@property (nonatomic, copy) NSString * _Nonnull eventID;
@property (nonatomic, copy) NSString * _Nonnull actionID;
@property (nonatomic, copy) NSString * _Nonnull groupID;
@property (nonatomic, copy) NSString * _Nonnull value;
@property (nonatomic) enum ZMPTCommonAppCheckboxStyle style;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithCoder:(NSCoder * _Nonnull)coder SWIFT_UNAVAILABLE;
- (NSRect)cellFrameForTextContainer:(NSTextContainer * _Nonnull)textContainer proposedLineFragment:(NSRect)lineFrag glyphPosition:(NSPoint)position characterIndex:(NSUInteger)charIndex SWIFT_WARN_UNUSED_RESULT;
- (void)drawWithFrame:(NSRect)cellFrame inView:(NSView * _Nullable)controlView;
- (NSString * _Nullable)accessibilityLabel SWIFT_WARN_UNUSED_RESULT;
- (NSString * _Nullable)accessibilityTitle SWIFT_WARN_UNUSED_RESULT;
- (id _Nullable)accessibilityValue SWIFT_WARN_UNUSED_RESULT;
- (NSAccessibilityRole _Nullable)accessibilityRole SWIFT_WARN_UNUSED_RESULT;
- (NSAccessibilitySubrole _Nullable)accessibilitySubrole SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)initTextCell:(NSString * _Nonnull)string SWIFT_UNAVAILABLE;
- (nonnull instancetype)initImageCell:(NSImage * _Nullable)image SWIFT_UNAVAILABLE;
@end



SWIFT_CLASS_NAMED("CommonAppCheckboxItem")
@interface ZMCommonAppCheckboxItem : ZMCommonAppBaseItem
@property (nonatomic, copy) NSString * _Nonnull eventID;
@property (nonatomic, copy) NSString * _Nonnull actionID;
@property (nonatomic) enum ZMPTCommonAppCheckboxStyle style;
@property (nonatomic, readonly) NSInteger numberOfItems;
- (void)addItemWithValue:(NSString * _Nonnull)value text:(NSString * _Nonnull)text;
- (void)selectItemWithValue:(NSString * _Nonnull)value;
/// Enumerates all the items in this checkbox group.
/// \param block A block to be called for each item. The block takes the following parameters:
///
/// \param text A string represented the text of the item
///
/// \param value A string represented the value of the item
///
/// \param isSelected A Boolean value that indicates whether the item is selected.
///
- (void)enumerateItemsUsingBlock:(SWIFT_NOESCAPE void (^ _Nonnull)(NSString * _Nonnull, NSString * _Nonnull, BOOL))block;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM_NAMED(NSInteger, ZMPTCommonAppCheckboxStyle, "CommonAppCheckboxStyle", open) {
  ZMPTCommonAppCheckboxStyleRegular = 0,
  ZMPTCommonAppCheckboxStyleSwitch = 1,
};


SWIFT_CLASS_NAMED("CommonAppMeetingCardCell")
@interface ZMPTCommonAppMeetingCardCell : ZMPTCommonBaseCell
- (nullable instancetype)initWithMessageID:(NSString * _Nonnull)messageID sessionID:(NSString * _Nonnull)sessionID OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithCoder:(NSCoder * _Nonnull)coder SWIFT_UNAVAILABLE;
- (NSRect)cellFrameForTextContainer:(NSTextContainer * _Nonnull)textContainer proposedLineFragment:(NSRect)lineFrag glyphPosition:(NSPoint)position characterIndex:(NSUInteger)charIndex SWIFT_WARN_UNUSED_RESULT;
- (void)drawWithFrame:(NSRect)cellFrame inView:(NSView * _Nullable)controlView;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (nonnull instancetype)initTextCell:(NSString * _Nonnull)string SWIFT_UNAVAILABLE;
- (nonnull instancetype)initImageCell:(NSImage * _Nullable)image SWIFT_UNAVAILABLE;
@end

@protocol ZMMessageCellViewDelegate;
@class ZMBaseMessageCellView;

@interface ZMPTCommonAppMeetingCardCell (SWIFT_EXTENSION(zChatComponent)) <ZMViewAttachmentCellProtocol>
@property (nonatomic, readonly, strong) NSView * _Nonnull imageView;
- (void)cleanUp;
- (void)attachDelegate:(id <ZMMessageCellViewDelegate> _Nullable)delegate ofMessageCellView:(ZMBaseMessageCellView * _Null_unspecified)cellView;
@end

@class ZMScheduleMeetingCardView;
@class ZMScheduleMeetingInfo;

@interface ZMPTCommonAppMeetingCardCell (SWIFT_EXTENSION(zChatComponent)) <ZMScheduleMeetingCardViewDelegate>
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView * _Nonnull)scheduleMeetingCardView joinMeeting:(NSString * _Nonnull)sessionId meetingNumber:(NSInteger)meetingNumber password:(NSString * _Nonnull)password;
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView * _Nonnull)scheduleMeetingCardView fromSession:(NSString * _Nonnull)sessionId openCMCchat:(NSString * _Nonnull)subCMCSessionId;
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView * _Nonnull)scheduleMeetingCardView viewInCalendar:(NSString * _Nonnull)calendarLink;
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView * _Nonnull)scheduleMeetingCardView copyInvitation:(NSString * _Nonnull)joinURL;
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView * _Nonnull)scheduleMeetingCardView editMeeting:(NSString * _Nonnull)sessionId meetingNumber:(NSInteger)meetingNumber occurrenceTime:(NSInteger)occurrenceTime meetingMasterEventId:(NSString * _Nonnull)meetingMasterEventId;
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView * _Nonnull)scheduleMeetingCardView deleteMeeting:(NSString * _Nonnull)sessionId meetingNumber:(NSInteger)meetingNumber occurrenceTime:(NSInteger)occurrenceTime meetingMasterEventId:(NSString * _Nonnull)meetingMasterEventId;
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView * _Nonnull)scheduleMeetingCardView joinFromARoom:(NSString * _Nonnull)sessionId meetingNumber:(NSInteger)meetingNumber;
- (void)scheduleMeetingCardView:(ZMScheduleMeetingCardView * _Nonnull)scheduleMeetingCardView moreParticipantsClicked:(ZMScheduleMeetingInfo * _Nonnull)meetingInfo;
- (BOOL)scheduleMeetingCardView:(ZMScheduleMeetingCardView * _Nonnull)scheduleMeetingCardView isInMeeting:(NSInteger)meetingNumber SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS_NAMED("CommonAppMeetingCardItem")
@interface ZMCommonAppMeetingCardItem : ZMCommonAppBaseItem
@property (nonatomic, copy) NSString * _Nullable messageID;
@property (nonatomic, copy) NSString * _Nullable sessionID;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class ZMCommonAppTextAreaItem;

SWIFT_CLASS_NAMED("CommonAppTextAreaCell")
@interface ZMPTCommonAppTextAreaCell : ZMPTCommonBaseCell
@property (nonatomic, copy) NSString * _Nonnull title;
@property (nonatomic, copy) NSString * _Nonnull stringValue;
@property (nonatomic, strong) ZMCommonAppTextAreaItem * _Nullable textAreaItem;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithCoder:(NSCoder * _Nonnull)coder SWIFT_UNAVAILABLE;
- (NSRect)cellFrameForTextContainer:(NSTextContainer * _Nonnull)textContainer proposedLineFragment:(NSRect)lineFrag glyphPosition:(NSPoint)position characterIndex:(NSUInteger)charIndex SWIFT_WARN_UNUSED_RESULT;
- (void)drawWithFrame:(NSRect)cellFrame inView:(NSView * _Nullable)controlView;
- (nonnull instancetype)initTextCell:(NSString * _Nonnull)string SWIFT_UNAVAILABLE;
- (nonnull instancetype)initImageCell:(NSImage * _Nullable)image SWIFT_UNAVAILABLE;
@end


@interface ZMPTCommonAppTextAreaCell (SWIFT_EXTENSION(zChatComponent)) <ZMViewAttachmentCellProtocol>
@property (nonatomic, readonly, strong) NSView * _Nonnull imageView;
- (void)cleanUp;
@end

@class ZMPTCommonAppTextAreaCxxItemWrapper;

SWIFT_CLASS_NAMED("CommonAppTextAreaItem")
@interface ZMCommonAppTextAreaItem : ZMCommonAppBaseItem
@property (nonatomic, readonly, strong) ZMPTCommonAppTextAreaCxxItemWrapper * _Nonnull cxxItemWrapper;
@property (nonatomic, copy) NSString * _Nullable sessionID;
@property (nonatomic, copy) NSString * _Nullable messageID;
@property (nonatomic, copy) NSString * _Nullable eventID;
@property (nonatomic, copy) NSString * _Nullable actionID;
@property (nonatomic) NSInteger index;
@property (nonatomic, copy) NSString * _Nullable text;
@property (nonatomic, copy) NSString * _Nonnull value;
@property (nonatomic, readonly, copy) NSString * _Nonnull placeholder;
@property (nonatomic, readonly) BOOL multiline;
@property (nonatomic, readonly) NSInteger maximumLength;
@property (nonatomic, copy) BOOL (^ _Nullable commitHandler)(NSString * _Nonnull);
- (nonnull instancetype)initWithCxxItemWrapper:(ZMPTCommonAppTextAreaCxxItemWrapper * _Nonnull)cxxItemWrapper OBJC_DESIGNATED_INITIALIZER;
- (void)markChanged;
- (BOOL)commitChanges;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class NSAttributedString;
@class ZMPTCommonAppTextLayoutInfo;

SWIFT_CLASS_NAMED("CommonAppTextLayoutHelperReference")
@interface ZMPTCommonAppTextLayoutHelper : NSObject
+ (ZMPTCommonAppTextLayoutInfo * _Nonnull)layoutInfoOfAttributedString:(NSAttributedString * _Nonnull)attributedString containerSize:(CGSize)containerSize SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS_NAMED("LayoutInfo")
@interface ZMPTCommonAppTextLayoutInfo : NSObject
@property (nonatomic, readonly) NSInteger numberOfLines;
@property (nonatomic, readonly) CGRect boundingRect;
- (CGRect)usedRectForLineAtIndex:(NSInteger)index SWIFT_WARN_UNUSED_RESULT;
- (NSRange)characterRangeForLineAtIndex:(NSInteger)index SWIFT_WARN_UNUSED_RESULT;
- (void)drawAtPoint:(NSPoint)point;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class ZMCustomEmojiModel;

SWIFT_CLASS_NAMED("EmojiLabel")
@interface ZMEmojiLabel : NSView
@property (nonatomic) CGFloat fontSize;
@property (nonatomic) CGFloat imageSize;
@property (nonatomic, readonly, strong) ZMCustomEmojiModel * _Nullable customEmoji;
@property (nonatomic, readonly, copy) NSString * _Nullable unicodeEmoji;
- (nonnull instancetype)initWithFrame:(NSRect)frameRect OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder SWIFT_UNAVAILABLE;
- (void)updateWithCustomEmoji:(ZMCustomEmojiModel * _Nullable)customEmoji;
- (void)updateWithUnicodeEmoji:(NSString * _Nullable)unicodeEmoji;
@end

@class NSSearchField;
@class ZMChatAlwaysOverlayScrollView;
@class ZMCollectionView;
@class NSTextField;

SWIFT_CLASS_NAMED("GiphyView")
@interface ZMGiphyView : ZMBaseView
@property (nonatomic, strong) NSSearchField * _Nonnull searchField;
@property (nonatomic, strong) ZMChatAlwaysOverlayScrollView * _Nonnull scrollView;
@property (nonatomic, readonly, strong) ZMCollectionView * _Nonnull collectionView;
@property (nonatomic, readonly, strong) NSTextField * _Nonnull errorTextField;
- (nonnull instancetype)initWithFrame:(NSRect)frameRect OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end



@interface NSString (SWIFT_EXTENSION(zChatComponent))
- (BOOL)hasEmojis SWIFT_WARN_UNUSED_RESULT;
- (BOOL)isEmojiOnly SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC14zChatComponent12PureTextView")
@interface PureTextView : NSTableCellView
- (nonnull instancetype)initWithFrame:(NSRect)frameRect OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS_NAMED("StickerView")
@interface ZMStickerView : ZMBaseView
@property (nonatomic, strong) ZMChatAlwaysOverlayScrollView * _Nonnull scrollView;
@property (nonatomic, readonly, strong) ZMCollectionView * _Nonnull collectionView;
- (nonnull instancetype)initWithFrame:(NSRect)frameRect OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end

@class NSCollectionViewLayoutAttributes;
@class NSIndexPath;

SWIFT_CLASS_NAMED("StickyHeadersCollectionViewFlowLayout")
@interface ZMStickyHeadersCollectionViewFlowLayout : NSCollectionViewFlowLayout
- (BOOL)shouldInvalidateLayoutForBoundsChange:(CGRect)newBounds SWIFT_WARN_UNUSED_RESULT;
- (NSArray<NSCollectionViewLayoutAttributes *> * _Nonnull)layoutAttributesForElementsInRect:(CGRect)rect SWIFT_WARN_UNUSED_RESULT;
- (NSCollectionViewLayoutAttributes * _Nullable)layoutAttributesForSupplementaryViewOfKind:(NSString * _Nonnull)elementKind atIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end

@class NSProgressIndicator;

SWIFT_CLASS_NAMED("SyncStickerView")
@interface ZMSyncStickerView : ZMBaseView
@property (nonatomic, readonly, strong) NSProgressIndicator * _Nonnull progressIndicator;
@property (nonatomic, readonly, strong) NSTextField * _Nonnull syncTip;
- (nonnull instancetype)initWithFrame:(NSRect)frameRect OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS_NAMED("TextListView")
@interface ZMTextListView : ZMBaseView
@property (nonatomic, strong) NSColor * _Nullable itemTextColor;
@property (nonatomic, copy) NSArray<NSString *> * _Nonnull allText;
- (nonnull instancetype)initWithFrame:(NSRect)frameRect OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder SWIFT_UNAVAILABLE;
@end

@class NSTableView;
@class NSTableColumn;

@interface ZMTextListView (SWIFT_EXTENSION(zChatComponent)) <NSTableViewDataSource, NSTableViewDelegate>
- (NSInteger)numberOfRowsInTableView:(NSTableView * _Nonnull)tableView SWIFT_WARN_UNUSED_RESULT;
- (NSView * _Nullable)tableView:(NSTableView * _Nonnull)tableView viewForTableColumn:(NSTableColumn * _Nullable)tableColumn row:(NSInteger)row SWIFT_WARN_UNUSED_RESULT;
- (CGFloat)tableView:(NSTableView * _Nonnull)tableView heightOfRow:(NSInteger)row SWIFT_WARN_UNUSED_RESULT;
- (BOOL)tableView:(NSTableView * _Nonnull)tableView shouldEditTableColumn:(NSTableColumn * _Nullable)tableColumn row:(NSInteger)row SWIFT_WARN_UNUSED_RESULT;
@end

enum ZMUserSignatureDataDurationType : NSInteger;
@class NSDate;

/// Model object for the user signature, also known as the “personal note”.
SWIFT_CLASS_NAMED("UserSignatureData")
@interface ZMUserSignatureData : NSObject
/// The type of duration setting.
@property (nonatomic) enum ZMUserSignatureDataDurationType durationType;
/// The raw signature content.
/// This contains the plaintext, written by the user.
@property (nonatomic, copy) NSString * _Nullable content;
/// The formatted content, with prepended or appended decorations included.
/// An example of added content is a short string with a link to a contact’s active huddle.
@property (nonatomic, readonly, strong) NSAttributedString * _Nullable calculatedContent;
/// The name of the huddle the user is in, if any.
@property (nonatomic, copy) NSString * _Nullable huddleName;
/// The deep link of the huddle the user is in, if any.
@property (nonatomic, copy) NSString * _Nullable huddleDeepLink;
/// Whether this signature item is a reminder or not.
@property (nonatomic) BOOL isReminder;
/// The starting date of the item.
@property (nonatomic, copy) NSDate * _Nullable start;
/// The end date of the item.
@property (nonatomic, copy) NSDate * _Nullable end;
/// The duration of the item.
/// This is only used for <code>DurationType/hours</code>.
@property (nonatomic) NSTimeInterval duration;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

/// The available user-configurable duration settings.
typedef SWIFT_ENUM_NAMED(NSInteger, ZMUserSignatureDataDurationType, "DurationType", open) {
  ZMUserSignatureDataDurationTypeAlways = 0,
  ZMUserSignatureDataDurationTypeCustom = 1,
  ZMUserSignatureDataDurationTypeHours = 2,
};

typedef SWIFT_ENUM(NSInteger, ZMFooterStatus, open) {
  ZMFooterStatusNormal = 0,
  ZMFooterStatusLoading = 1,
  ZMFooterStatusError = 2,
};


SWIFT_CLASS("_TtC14zChatComponent31ZMGroupInviteConsentRequestInfo")
@interface ZMGroupInviteConsentRequestInfo : NSObject
@property (nonatomic, copy) NSString * _Nonnull sessionID;
@property (nonatomic, copy) NSString * _Nonnull sessionName;
@property (nonatomic, copy) NSString * _Nonnull orgName;
@property (nonatomic, copy) NSString * _Nonnull actionOwnerName;
@property (nonatomic) BOOL autoTrustOrg;
- (nonnull instancetype)initWithSessionID:(NSString * _Nonnull)sessionID sessionName:(NSString * _Nonnull)sessionName orgName:(NSString * _Nonnull)orgName actionOwnerName:(NSString * _Nonnull)actionOwnerName autoTrustOrg:(BOOL)autoTrustOrg OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithSessionID:(NSString * _Nonnull)sessionID sessionName:(NSString * _Nonnull)sessionName orgName:(NSString * _Nonnull)orgName actionOwnerName:(NSString * _Nonnull)actionOwnerName;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@protocol ZMInviteConsentRequestViewControllerDelegate;
@class NSBundle;

SWIFT_CLASS("_TtC14zChatComponent36ZMInviteConsentRequestViewController")
@interface ZMInviteConsentRequestViewController : NSViewController
@property (nonatomic, strong) ZMGroupInviteConsentRequestInfo * _Nullable request;
@property (nonatomic, weak) id <ZMInviteConsentRequestViewControllerDelegate> _Nullable delegate;
@property (nonatomic, readonly, copy) NSNibName _Nullable nibName;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithRequest:(ZMGroupInviteConsentRequestInfo * _Nonnull)request OBJC_DESIGNATED_INITIALIZER;
- (void)viewDidLoad;
- (void)loadView;
- (nonnull instancetype)initWithNibName:(NSNibName _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil SWIFT_UNAVAILABLE;
@end


SWIFT_PROTOCOL("_TtP14zChatComponent44ZMInviteConsentRequestViewControllerDelegate_")
@protocol ZMInviteConsentRequestViewControllerDelegate
- (void)onSuccessfulConsentResponse:(ZMInviteConsentRequestViewController * _Nonnull)sender didConsent:(BOOL)didConsent;
- (void)onConsentRequestRemoval:(ZMInviteConsentRequestViewController * _Nonnull)sender sessionID:(NSString * _Nonnull)sessionID;
@end


SWIFT_PROTOCOL("_TtP14zChatComponent16ZMLoadableFooter_")
@protocol ZMLoadableFooter
- (void)updateFooterWithStatus:(enum ZMFooterStatus)status;
@end


SWIFT_CLASS("_TtC14zChatComponent21ZMNoCustomEmojiFooter")
@interface ZMNoCustomEmojiFooter : ZMBaseView <NSCollectionViewElement>
@property (nonatomic) BOOL forceDarkMode;
@property (nonatomic, copy) void (^ _Nullable addEmojiWindowDidOpen)(void);
- (nonnull instancetype)initWithFrame:(NSRect)frameRect OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder SWIFT_UNAVAILABLE;
@end


SWIFT_CLASS("_TtC14zChatComponent16ZMViewMoreFooter")
@interface ZMViewMoreFooter : ZMBaseView <NSCollectionViewElement>
@property (nonatomic) BOOL forceDarkMode;
@property (nonatomic, copy) void (^ _Nullable viewMoreHandler)(void);
@property (nonatomic) enum ZMFooterStatus status;
- (nonnull instancetype)initWithFrame:(NSRect)frameRect OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder SWIFT_UNAVAILABLE;
@end


@interface ZMViewMoreFooter (SWIFT_EXTENSION(zChatComponent)) <ZMLoadableFooter>
- (void)updateFooterWithStatus:(enum ZMFooterStatus)status;
@end

#endif
#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#if defined(__cplusplus)
#endif
#pragma clang diagnostic pop
#endif

#else
#error unsupported Swift architecture
#endif